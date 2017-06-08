#include "stdafx.h"
#include "mediaplayertoolbar.h"
#include "inc_CommonLib\CommonWidgets.h"
#include "mediaplayercontrol.h"
#include "commonapi.h"
#include <QtWidgets/QApplication>

MediaPlayerToolBar::MediaPlayerToolBar(QWidget *parent)
	: QWidget(parent)
{
	initData();
	initUI();
	initConnectios();
}

MediaPlayerToolBar::~MediaPlayerToolBar()
{

}

void MediaPlayerToolBar::initUI()
{
	setAttribute(Qt::WA_StyledBackground);
	setObjectName("MediaPlayerView_ToolBarBase");
	//setStyleSheet("background-color:blue;");
	//创建播放控制按钮
	CreateToolBarMixButton(MediaPlayerToolBar::Type_Play, "Button_Play", MediaPlayerToolBar::Type_Pause, "Button_Pause");
	createToolBarButtons(MediaPlayerToolBar::Type_FrontFrame, "Button_NextFrame");
	createToolBarButtons(MediaPlayerToolBar::Type_BackFrame, "Button_BackFrame");
	createToolBarButtons(MediaPlayerToolBar::Type_Stop, "Button_StopPlay");
	CreateToolBarMixButton(MediaPlayerToolBar::Type_FullScreen,"Type_FullScreen",MediaPlayerToolBar::Type_Restore,"Type_Restore");
	m_slider = new ToolBarSlider(this);
}

void MediaPlayerToolBar::initData()
{
	m_mediaPlayerControl = IMediaPlayerControl::GetInstance();
	//初始的时候设置slider 持续时间为0
	//m_slider->setDuration(0);
	//m_slider->setValue(0);
}

void MediaPlayerToolBar::initConnectios()
{
   //初始化工具栏播放控制按钮事件
	QMap<int, BaseButton*>::iterator iter = m_toolbarButtons.begin();
	for (; iter != m_toolbarButtons.end();++iter)
	{
		connect(*iter, &BaseButton::Clicked, this, [&](int id,QPoint p){
			ButtonClicked(id,p);
			emit Clicked(id, p);
		});	
	}

	connect(m_mediaPlayerControl, &MediaPlayerControl::PlayingCallback, this, [&](int frames){
		  m_slider->setValue(frames);
		  //改变时间线的“游标头”
		  emit sigalSyncRulerHandler(frames);
	});

	//手动改变slider的位置，视频的当前播放帧跟着跳跃到对应的帧
	connect(m_slider, &ToolBarSlider::valueChanged, this, [&](double value){
		//seek 视频帧
		SeekManual(value, 0);
		//同步timeline控件
		int iCurrentVal = m_slider->value();
	});

	connect(reinterpret_cast<MediaPlayerControl*>(m_mediaPlayerControl), &MediaPlayerControl::PlayFinishCallback, this, [&](){
		stopPlay();
	});

	//修改当前slider的播放进度
	connect(this, &MediaPlayerToolBar::signalSliderValueChange, this, [&](int iValue){
		m_slider->setValue(iValue);
	});

	//重设slider的范围（视频总帧数）
	connect(this, &MediaPlayerToolBar::sigalDurationChanged, this, [&](int iValue){
		m_slider->setDuration(iValue);
	});
}

//启用&& 禁用工具栏
void MediaPlayerToolBar::EnableButton(bool isEnabel)
{
	GetButton(MediaPlayerToolBar::Type_Play)->setEnabled(isEnabel);
	GetButton(MediaPlayerToolBar::Type_Stop)->setEnabled(isEnabel);
	GetButton(MediaPlayerToolBar::Type_BackFrame)->setEnabled(isEnabel);
	GetButton(MediaPlayerToolBar::Type_FrontFrame)->setEnabled(isEnabel);
}

void MediaPlayerToolBar::Open()
{
	EnableButton(true);
}

void MediaPlayerToolBar::Close()
{
	TransferMixButton(MediaPlayerToolBar::Type_Play);
	EnableButton(false);
}

void MediaPlayerToolBar::Play()
{
	TransferMixButton(MediaPlayerToolBar::Type_Pause);
}

void MediaPlayerToolBar::Stop()
{
	TransferMixButton(MediaPlayerToolBar::Type_Play);
}

void MediaPlayerToolBar::Pause()
{
	TransferMixButton(MediaPlayerToolBar::Type_Play);
}

void MediaPlayerToolBar::Forward()
{

}

void MediaPlayerToolBar::Backward()
{

}

void MediaPlayerToolBar::createToolBarButtons(int id, const QString objectName)
{
	if (!m_toolbarButtons.contains(id))
	{
		auto btn = new BaseButton(id,objectName,this);
		//btn->show();
		m_toolbarButtons.insert(id, btn);		
	}
}

//创建混合的按钮（一个按钮通过点击实现切换）
void MediaPlayerToolBar::CreateToolBarMixButton(int firstId, QString firstObjectName, int secondId, QString secondObjectName)
{
	auto btn = new BaseStateButton(firstId, "", this);
	btn->AddButton(firstId, firstObjectName);
	btn->AddButton(secondId, secondObjectName);
	m_toolbarButtons.insert(firstId, btn);
}

void MediaPlayerToolBar::ButtonClicked(int id, QPoint p)
{
	switch (id)
	{
	case MediaPlayerToolBar::Type_Play:
	{
		if (!m_mediaPlayerControl->Play())
		{
			TransferMixButton(MediaPlayerToolBar::Type_Pause);
		}
		break;
	}
	case MediaPlayerToolBar::Type_Pause:
		m_mediaPlayerControl->Pause();
		break;
	case MediaPlayerToolBar::Type_Stop:
		m_mediaPlayerControl->Stop();
		break;
	case MediaPlayerToolBar::Type_BackFrame:

		m_mediaPlayerControl->Backward();
		break;
	case MediaPlayerToolBar::Type_FrontFrame:
		m_mediaPlayerControl->Forward();
		break;
	default:
		;//Q_ASSERT(false);
	}
}


#include <QDebug>
void MediaPlayerToolBar::resizeEvent(QResizeEvent *event)
{
	const int margins = 5;
	const int space = margins;
	int left = margins;
	int top = margins;
	const int btnw = 14;
	const int btnh = 14;
	//qDebug() << GetButton(Type_BackFrame)->geometry()<<geometry();
	GetButton(Type_BackFrame)->setGeometry(left, top, btnw, btnh);
	left = GetButton(Type_BackFrame)->geometry().right() + space;
	GetButton(Type_Play)->setGeometry(left, top, btnw, btnh);
	left = GetButton(Type_Play)->geometry().right() + space;
	GetButton(Type_FrontFrame)->setGeometry(left, top, btnw, btnh);
	left = GetButton(Type_FrontFrame)->geometry().right() + space;
	GetButton(Type_Stop)->setGeometry(left, top, btnw, btnh);
	left = GetButton(Type_Stop)->geometry().right() + space;

	const int rightbtnw = 17;
	int sliderw = width() - left - 4 * (rightbtnw + space);
	m_slider->setGeometry(left, top, sliderw, m_slider->Height());


	//left = m_slider->geometry().right() + space;

	left = this->geometry().right() - 2*space;
	//GetButton(MainToolBar_RecordVoice)->setGeometry(left, top, rightbtnw, btnh);
	//left = GetButton(MainToolBar_RecordVoice)->geometry().right() + space;
	//GetButton(MainToolBar_SnapShot)->setGeometry(left, top, rightbtnw, btnh);
	//left = GetButton(MainToolBar_SnapShot)->geometry().right() + space;
	//GetButton(MainToolBar_Volume)->setGeometry(left, top, rightbtnw, btnh);
	//left = GetButton(MainToolBar_Volume)->geometry().right() + space;

	GetButton(Type_FullScreen)->setGeometry(left, top, rightbtnw, btnh);
	left = GetButton(Type_FullScreen)->geometry().right() + space;


	//top = m_slider->geometry().bottom() + 10;
	//left = margins;
	//m_aspectRatio->setGeometry(left, top, 200, btnh);
	//m_pAudioPillar->setGeometry(width() - rightbtnw, top, rightbtnw, 30);
	//m_currentFrame->setGeometry(width() - 75 - rightbtnw, top, 90, 14);
	//top = m_currentFrame->geometry().bottom();
	//m_TotalFrame->setGeometry(width() - 75 - rightbtnw, top, 90, 14);
}

BaseButton* MediaPlayerToolBar::GetButton(int id)
{
	auto btn = m_toolbarButtons[id];
	Q_ASSERT(btn);
	btn->show();
	return btn;
}


void MediaPlayerToolBar::TransferMixButton(ButtonType newType)
{
	qobject_cast<BaseStateButton*>(GetButton(MediaPlayerToolBar::Type_Play))->SetCurrentButtonId(newType);
}

//设置当前播放视频所使用的fps
void MediaPlayerToolBar::SetFPS(float m_fps)
{
	 //
}

void MediaPlayerToolBar::SeekManual(int frames, int accurate)
{
	reinterpret_cast<MediaPlayerControl*>(m_mediaPlayerControl)->Seek(frames, accurate);
	//GetButton(ToolBar::ToolBar_Backward)->SetEnabled(frames > 0);
	//emit RulerSeekCallback(frames);
	/*if (!m_mediaPlayerControl->IsPlaying() || m_seekManual)
		m_lastSeekFrames = frames;*/
}

void MediaPlayerToolBar::stopPlay()
{
	TransferMixButton(MediaPlayerToolBar::Type_Play);
	m_slider->setValue(0);
}

void MediaPlayerToolBar::DblMouseButtonFullScreen()
{
	(qobject_cast<BaseStateButton*>(GetButton(Type_FullScreen)))->ClickCurrentButton();
}

void MediaPlayerToolBar::SetDuration(int iFrameNumber)
{
	m_slider->setDuration(iFrameNumber);
}

bool MediaPlayerToolBar::IsSeeking()
{
	return !m_slider->canSeek();
}

