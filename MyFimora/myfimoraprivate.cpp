#include "stdafx.h"
#include <QHBoxLayout>
#include "myfimoraprivate.h"
#include "inc_MediaPlayerView/IMediaPlayerControl.h"
#include "inc_MatterView/resourceview.h"
#include "inc_TimelineView/timelineview.h"
#include "inc_MediaPlayerView/meidaplayerview.h"
#include "../MeidaPlayerView/mediaplayercontrol.h"


MyFimoraPrivate::MyFimoraPrivate(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_StyledBackground);
	initUI();
	initConnections();
}

MyFimoraPrivate::~MyFimoraPrivate()
{

}

//初始化界面
void MyFimoraPrivate::initUI()
{
	this->resView = new ResourceView();
	this->playerView = new MeidaPlayerView;
	timelineView = new TimeLineView;
	hLayout = new QHBoxLayout();
	hLayout->setContentsMargins(0,0,0,0);
	hLayout->addWidget(resView);
	hLayout->addWidget(playerView);
	vLayout = new QVBoxLayout;
	vLayout->addLayout(hLayout);
	vLayout->setStretchFactor(hLayout, 6);
	vLayout->addWidget(timelineView);
	vLayout->setStretchFactor(timelineView, 4);
	this->setLayout(vLayout);
}

//窗口大小改变产生的事件
void MyFimoraPrivate::resizeEvent(QResizeEvent *event)
{
	/*qDebug() << "******************** resView: " << resView->height() << "***************"; 
	qDebug() << "******************** playerView :" << playerView->height() << "***************"; 
	qDebug() << "******************** timelineView： " << timelineView->height() << "***************";*/
}

IMediaPlayerControl* MyFimoraPrivate::GetPlayerControler()
{
	return this->playerView->GetPlayerControler();
}

void MyFimoraPrivate::refreshUI()
{
  //重新设置界面语言
	resView->refreshUI();
	playerView->refreshUI();
	timelineView->refreshUI();
}

void MyFimoraPrivate::slotChangeLanguage()
{
	refreshUI();
}

void MyFimoraPrivate::initConnections()
{
	connect(resView, &ResourceView::signalPlayMovie, this, [&](QString strMoviePath){
		//m_eLoadedType = RenderLoadedType_MatterView;
		MeidaPlayerView* pView = qobject_cast<MeidaPlayerView*>(playerView);
		//if (pView) pView->SetLoadType(false);
		IMediaPlayerControl* playControl = GetPlayerControler();
		if (!playControl->Close()) return;
		auto *pTimeline = resView->GetSelectTimeline();
		if (!pTimeline) return;
		if (!playControl->Open(1, pTimeline)) return;
		//if (!bPlay) return;
		//if (!m_pPlayer->Seek(0, 0)) return;
		playControl->Play();
	});

	connect(resView, &ResourceView::signalUnload, this, [&](){
		LoadTimeline();	
	});

	connect(timelineView, &TimeLineView::signalSeekToFrame, playerView, &MeidaPlayerView::signalSeekToPos);
	connect(timelineView, &TimeLineView::signalPlaySliderValueChanged, playerView, &MeidaPlayerView::signalPlaySliderValueChanged);
	connect(timelineView, &TimeLineView::sigalDurationChanged, playerView, &MeidaPlayerView::sigalDurationChanged);
	//test signal
	connect(playerView, &MeidaPlayerView::sigalSyncRulerHandler, timelineView, &TimeLineView::sigalSyncRulerHandler);
	//处理换肤信号
	connect(this, &MyFimoraPrivate::signalChangeLanguge, this, [&](){
		slotChangeLanguage();
	});
}

void MyFimoraPrivate::LoadTimeline()
{
	//获取当前的时间线
	auto *pTimeline = timelineView->GetTimeline();
	if (pTimeline == nullptr)
	{
		return;
	}
	IMediaPlayerControl* playControl = GetPlayerControler();
	if (!playControl->Close())
	{
		return;
	}
	if (!playControl->Open(1, pTimeline))
	{
		return;
	}
    //获取当前视频的总帧数
	int iAllFramesCount = reinterpret_cast<MediaPlayerControl*>(playControl)->Duration();
	emit 
}
