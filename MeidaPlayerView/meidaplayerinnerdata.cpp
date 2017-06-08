#include "stdafx.h"
#include "meidaplayerinnerdata.h"
#include "displayview.h"
#include "mediaplayercontrol.h"
#include "mediaplayertoolbar.h"
#include "commonapi.h"


MeidaPlayerInnerData::MeidaPlayerInnerData(QWidget *parent)
	: QWidget(parent)
{
	m_DisplayView = new DisplayView(this);
	m_DisplayControl = reinterpret_cast<MediaPlayerControl*>(MediaPlayerControl::GetInstance());
	m_PlayerToolBar = new MediaPlayerToolBar(this);
	m_DisplayControl->setToolBar(m_PlayerToolBar);
	////为什么传入this 播放控制工具栏不会显示？ 
    m_FullScreenContol = new FullScreenControl(reinterpret_cast<QWidget*>(parent));
	m_FullScreenContol->SetToolbar(m_PlayerToolBar);
	initConnections();
}

MeidaPlayerInnerData::~MeidaPlayerInnerData()
{
   
}

void MeidaPlayerInnerData::initConnections()
{
	connect(m_PlayerToolBar, &MediaPlayerToolBar::Clicked, this, [&](int id, QPoint p){
		switch (id)
		{
		case MediaPlayerToolBar::Type_FullScreen:	
		case MediaPlayerToolBar::Type_Restore:
			m_FullScreenContol->FullScreen();
			break;
			/*m_FullScreenContol->Restore();
			break;*/
		default:
			break;
		}
	});

	connect(this, &MeidaPlayerInnerData::signalSliderValueChange, m_PlayerToolBar, &MediaPlayerToolBar::signalSliderValueChange);
	//test sigal
	connect(m_PlayerToolBar, &MediaPlayerToolBar::sigalSyncRulerHandler, this, &MeidaPlayerInnerData::sigalSyncRulerHandler);
	connect(this, &MeidaPlayerInnerData::sigalDurationChanged, m_PlayerToolBar, &MediaPlayerToolBar::sigalDurationChanged);
}

void MeidaPlayerInnerData::slotSeekToFrame(int iFrame)
{
	m_DisplayControl->Seek(iFrame, 0);
}

void MeidaPlayerInnerData::resizeEvent(QResizeEvent *event)
{
	m_DisplayView->setGeometry(0, 0, width(), height() - 40);
	m_DisplayView->show();
	RECT r = { 0, 0, m_DisplayView->width(),m_DisplayView->height()};
	HVIEW test = (HVIEW)m_DisplayView->winId();
	m_DisplayControl->SetHwnd(test, r);
	int iButtonPos  = m_DisplayView->geometry().bottom();
	//int iTopPos = m_DisplayView->geometry().top();
	m_PlayerToolBar->setGeometry(0, iButtonPos, width(), height() - iButtonPos);
	//m_PlayerToolBar->setStyleSheet("background:green");
    m_PlayerToolBar->show();
}
