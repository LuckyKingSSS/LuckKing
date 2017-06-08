#include "stdafx.h"
#include <QPropertyAnimation>
#include <QTimer>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QDesktopWidget>
#include "inc_CommonLib/externalapi.h"
#include "inc_CommonLib/CommonWidgets.h"
#include "mediaplayertoolbar.h"
#include "commonapi.h"

FullScreenControl::FullScreenControl( QWidget *w)
:QObject(w)
{
	m_mediaPlayerViewPrivate = w;
	SetFullScreen(false);
	m_hideAnimation = new QPropertyAnimation(this);
	m_hideAnimation->setDuration(500);
	m_hideAnimTimer = new QTimer(this);
	m_hideAnimTimer->setSingleShot(true);
	m_hideAnimTimer->setInterval(500);
	connect(m_hideAnimTimer, &QTimer::timeout, this, [&](){
		QPoint start = m_toolbar->pos();
		QPoint end = start + QPoint(0, m_toolbar->height());
		m_hideAnimation->setTargetObject(m_toolbar);
		m_hideAnimation->setPropertyName(QByteArray("pos"));
		m_hideAnimation->setStartValue(start);
		m_hideAnimation->setEndValue(end);
		m_hideAnimation->start();
	});
	m_showAnimation = new QPropertyAnimation(this);
	m_showAnimation->setDuration(100);
}


void FullScreenControl::FullScreen()
{
	if (IsFullScreen())
	{
		SetFullScreen(false);
		m_mediaPlayerViewPrivate->setWindowFlags(Qt::Widget);
		m_mediaPlayerViewPrivate->showNormal();
		StopAnimation(); 
	}
	else
	{
		// 重构不要放if外面
		//必须放在最前面，m_mediaPlayerViewPrivate->setGeometry(fullscreen)会马上触发resizeEvent
		SetFullScreen(true); 

		// 使用此方法全屏会有边框
		//m_mediaPlayerViewPrivate->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
		//m_mediaPlayerViewPrivate->showFullScreen();
		// 使用此方法播放器工具栏无法及时收到paint事件，导致工具没实时响应事件
		//m_mediaPlayerViewPrivate->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
		//m_mediaPlayerViewPrivate->showFullScreen();


		// 手动设置全屏
		auto fullscreen = QApplication::desktop()->screenGeometry();
		m_mediaPlayerViewPrivate->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
		m_mediaPlayerViewPrivate->setGeometry(fullscreen);
		m_mediaPlayerViewPrivate->setVisible(true);
		m_mediaPlayerViewPrivate->activateWindow();

	}
	
}

void FullScreenControl::Restore()
{
	if (IsFullScreen())
	{
		auto mainToolbar = qobject_cast<MediaPlayerToolBar*>(m_toolbar);
		if (mainToolbar)
		{
			mainToolbar->DblMouseButtonFullScreen();
		}	
		else
		{
			m_mediaPlayerViewPrivate->setWindowFlags(Qt::SubWindow);
			m_mediaPlayerViewPrivate->showNormal();
			StopAnimation();
			SetFullScreen(false);
		}
	}
}



void FullScreenControl::ResizeEvent(QWidget *displayView, QRect rect)
{
	// 是全屏时进行隐藏动画
	if (IsFullScreen() && m_toolbar)
	{
		displayView->setGeometry(rect);
		m_hideAnimTimer->start();
	}
}

void FullScreenControl::MayShowToolbar(QRect rect, QPoint p)
{
	// 是全屏时进行显示动画
	if (IsFullScreen() && m_toolbar)
	{
		m_curPoint = p;
		m_dispplayRect = rect;
		const int hitHeith = m_toolbar->height() * 2;
		QRect hitRect(0, m_dispplayRect.height() - hitHeith, m_dispplayRect.width(), hitHeith);
		if (hitRect.contains(m_curPoint))
		{
			m_hideAnimTimer->stop();
			if (!IsAnimationRunning() && !IsToolBarShow())
			{
				QPoint start = m_toolbar->pos();
				QPoint end = start - QPoint(0, m_toolbar->height());
				m_showAnimation->setTargetObject(m_toolbar);
				m_showAnimation->setPropertyName(QByteArray("pos"));
				m_showAnimation->setStartValue(start);
				m_showAnimation->setEndValue(end);
				m_showAnimation->start();
			}
		}
		else
		{
			if (!IsAnimationRunning() && IsToolBarShow())
			{
				m_hideAnimTimer->start();
			}
			
		}
	}
}

void FullScreenControl::StopAnimation()
{
	m_hideAnimation->stop();
	m_hideAnimTimer->stop();
}

bool FullScreenControl::IsToolBarShow()
{
	if (m_toolbar)
	{
		auto r1 = m_toolbar->geometry();
		auto r2 = m_dispplayRect;
		auto ret = r2.contains(r1);
		return m_dispplayRect.contains(m_toolbar->geometry());
	}
	return false;
}

bool FullScreenControl::IsAnimationRunning()
{
	return m_hideAnimation->state() == QAbstractAnimation::Running ||
		m_showAnimation->state() == QAbstractAnimation::Running;
}

void FullScreenControl::SetFullScreen(bool fullscreen)
{
	m_mediaPlayerViewPrivate->setProperty("FullScreen", fullscreen);
}

bool FullScreenControl::IsFullScreen()
{
	return m_mediaPlayerViewPrivate->property("FullScreen").toBool();
}