#include "stdafx.h"
#include "myfimora.h"
#include "inc_CommonLib/externalapi.h"
#include "inc_MediaPlayerView/meidaplayerview.h"
#include "myfimoraprivate.h"
#include "filmoratoolbar.h"

MyFimora::MyFimora(QWidget *parent)
	: QWidget(parent)
{
	m_Toolbar = new FilmoraToolbar(this);
	m_InnerData = new MyFimoraPrivate(this);
	initUI();
	initConnections();
}

MyFimora::~MyFimora()
{

}

//初始化界面
void MyFimora::initUI()
{
	setMinimumSize(1332, 745);
	qApp->setStyleSheet(gGetCommonLibStyles() + gGetMediaPlayerStyles());
}

void MyFimora::initConnections()
{
	connect(m_Toolbar, &FilmoraToolbar::signalChangeLanguage, m_InnerData, &MyFimoraPrivate::slotChangeLanguage);
}

void MyFimora::resizeEvent(QResizeEvent *event)
{
	m_InnerData->setGeometry(0, 30, width(), height() - 30);
	m_Toolbar->setGeometry(0, 0, width(), 30);
}

void MyFimora::setTranslator(QTranslator* qTranslator)
{
	m_Translator = qTranslator;
	m_Toolbar->setTranslator(qTranslator);
}
