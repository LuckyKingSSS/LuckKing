#include "stdafx.h"
#include "../include/inc_MediaPlayerView/meidaplayerview.h"
#include "meidaplayerinnerdata.h"
#include "inc_CommonLib/externalapi.h"
#include "inc_MediaPlayerView/IMediaPlayerControl.h"

MeidaPlayerView::MeidaPlayerView(QWidget* parent) :QWidget(parent)
{
	setObjectName("MeidaPlayerView");
	m_InnerData = new MeidaPlayerInnerData(this);
	m_InnerData->setGeometry(0, 0, width(), height());
	initConnection();
}

MeidaPlayerView::~MeidaPlayerView()
{

}

IMediaPlayerControl* MeidaPlayerView::GetPlayerControler()
{
	return m_InnerData->getMediaControler();
}

void MeidaPlayerView::initConnection()
{
	connect(this, &MeidaPlayerView::signalSeekToPos, m_InnerData, &MeidaPlayerInnerData::slotSeekToFrame);
	connect(this, &MeidaPlayerView::signalPlaySliderValueChanged, m_InnerData, &MeidaPlayerInnerData::signalSliderValueChange);
	//test signal
	connect(m_InnerData, &MeidaPlayerInnerData::sigalSyncRulerHandler, this, &MeidaPlayerView::sigalSyncRulerHandler);
	connect(this, &MeidaPlayerView::sigalDurationChanged, m_InnerData, &MeidaPlayerInnerData::sigalDurationChanged);
}

void MeidaPlayerView::playMovie(QString strMoviePath)
{

}

void MeidaPlayerView::resizeEvent(QResizeEvent *event)
{
	m_InnerData->setGeometry(0, 0, width(), height());
	m_InnerData->show();
}

 QString gGetMediaPlayerStyles()
{
	 return gGetStyleSheet(QString(":/style/Resources/styles.qss"));
}

void MeidaPlayerView::refreshUI()
{

}
