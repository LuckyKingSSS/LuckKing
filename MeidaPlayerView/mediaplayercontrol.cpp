#include "stdafx.h"
#include "Interface/INLEFactory.h"
#include <QtCore/QThread>
#include <QtWidgets/QApplication>
#include "inc_CommonLib/WSCreateInstance.h"
#include "inc_CommonLib/NLETimeline.h"
#include "mediaplayertoolbar.h"
#include "mediaplayercontrol.h"

MediaPlayerControl* MediaPlayerControl::g_control = nullptr;

MediaPlayerControl::MediaPlayerControl()
{
	initData();
	initConnections();
}

MediaPlayerControl::~MediaPlayerControl()
{
   
}

void MediaPlayerControl::initData()
{
	//m_eLoadedType = RenderLoadedType_None;
	m_timeline = nullptr;
	m_toolbar = nullptr;
	m_IPlayerView = nullptr;
	m_isStop = false;
    m_haveSource = false;
    m_fps = 0;
	m_ratio = 0.0;
	m_close = false;
	m_isSeeking = false;
	m_seekFrames = 0;
	m_isStop = false;
	m_curFrames = 0;
	m_playStartCallbackFun = nullptr;
}

//初始化信号和槽的连接
void MediaPlayerControl::initConnections()
{
	/*connect(this, &MediaPlayerControl::PlayFinishCallback, m_toolbar, [&](){
		m_toolbar->stopPlay();
		});*/
}

IMediaPlayerControl* IMediaPlayerControl::GetInstance()
{
	if (MediaPlayerControl::g_control == nullptr)
	{
		MediaPlayerControl::g_control = new MediaPlayerControl;
		if (!(MediaPlayerControl::g_control)->Init())
		{
			 (MediaPlayerControl::g_control)->Release();
			 MediaPlayerControl::g_control = nullptr;
		}
	}
	return MediaPlayerControl::g_control;
}

bool MediaPlayerControl::Open(int iSourceType, NLETimeline* timeline)
{
	Q_ASSERT(timeline);
	m_timeline = timeline;
	NLEComPtr<INLERender> pVideoRender;
	NLEComPtr<INLERender> pAudioRender;
	bool bRec = SUCCEEDED(m_timeline->GetSrc()->GetRender(&pAudioRender, &pVideoRender));
	if (bRec)
	{
		float rate = m_timeline->GetRenderFrameRate();
		bRec = Open(iSourceType, pVideoRender, pAudioRender, rate);
		UpdateRatio();
	}
	return bRec;
}

bool MediaPlayerControl::Open(int bSource, INLERender *pVideoRender, INLERender* pAudioRender, float fps)
{
	m_fps = fps;
	m_haveSource = true;
	bool ret = SUCCEEDED(m_IPlayerView->SetVideoInput(bSource, pVideoRender));
	m_IMediaPlayer->SetAudioInput(pAudioRender);
	m_IMediaPlayer->Load();
	while (m_IMediaPlayer->GetPlayerState() == PS_LOADING)
	{
		QThread::msleep(20);
	}
	if (m_toolbar)
	{
		m_toolbar->Open();
		m_toolbar->SetFPS(m_fps);
		m_toolbar->SetDuration(Duration());
	}
	return ret;
}

void MediaPlayerControl::SetRatio(float ratio)
{

}

void MediaPlayerControl::UpdateRatio()
{

}

bool MediaPlayerControl::Play()
{
	bool ret = true;
	if (HaveSource())
	{
		if (m_toolbar)
		{
			// Slider在seeking中时不播放
			if (!IsPlaying() && !m_toolbar->IsSeeking())
			{
				if (m_playStartCallbackFun && !m_playStartCallbackFun())
					return false;
				emit PlayStartCallback();
				ret = SUCCEEDED(m_IMediaPlayer->Play());
				if (m_toolbar)
					m_toolbar->Play();
			}
		}
		else
		{
			if (!IsPlaying())
			{
				if (m_playStartCallbackFun && !m_playStartCallbackFun())
					return false;
				emit PlayStartCallback();
				ret = SUCCEEDED(m_IMediaPlayer->Play());
			}
		}
	}
	else
	{
		if (m_toolbar)
			m_toolbar->Pause();
	}
	return ret;
}

bool MediaPlayerControl::Stop()
{
	bool rec = true;
	rec = SUCCEEDED(m_IMediaPlayer->Stop());
	while (!m_isStop)
	{
		QThread::msleep(20);
		qApp->processEvents();
	}
	return rec;
}

bool MediaPlayerControl::Pause()
{
	bool ret = true;
	if (HaveSource() && IsPlaying())
	{
		ret = SUCCEEDED(m_IMediaPlayer->Pause());
		if (m_toolbar)
			m_toolbar->Pause();
		// pause底层不会发送停止信号，在此模拟停止播放信号

		while (!IsPause())
		{
			QThread::msleep(20);
			qApp->processEvents();
		}
		emit PlayPauseCallback();
	}
	return ret;
}

bool MediaPlayerControl::Close()
{
	if (HaveSource())
	{
		m_close = true;
		Stop();

		m_IPlayerView->SetVideoInput(0, nullptr);
		m_IMediaPlayer->SetAudioInput(nullptr);

		if (m_toolbar)
			m_toolbar->Close();
		m_haveSource = false;
		//m_TimelineBase = nullptr;
	}

	return true;
}

bool MediaPlayerControl::Forward()
{
	bool ret = true;
	if (HaveSource())
	{
		Pause();
		ret = SUCCEEDED(m_IMediaPlayer->Forward());
		if (m_toolbar)
			m_toolbar->Forward();
	}
	return ret;
}

bool MediaPlayerControl::Backward()
{
	bool ret = true;
	if (HaveSource())
	{
		Pause();
		ret = SUCCEEDED(m_IMediaPlayer->BackForward());
		if (m_toolbar)
			m_toolbar->Backward();
	}
	return ret;
}

bool MediaPlayerControl::Init()
{
	INLEFactory	*pFactory = NULL;
	WSCreateInstance::Instance()->wsCreateInstance(CLSID_NLEFactory, nullptr, 0, IID_INLEFactory, (void**)&pFactory);
	if (!pFactory)
		return false;
	pFactory->Init(NULL);
	m_IMediaPlayer = pFactory->CreateNLEPlayer();
	if (!m_IMediaPlayer)
		return false;

	m_IMediaPlayer->GetPlayerViewMgr(&m_IPlayerViewMgr);
	assert(m_IPlayerViewMgr);

	// 设置播放时间回调
	m_IMediaPlayer->SetCallBack([](void* pUserObj, UINT uMsg, WPARAM_PLAYER wParam, LPARAM_PLAYER lParam)->HRESULT{

		auto mediaPlayerControl = static_cast<MediaPlayerControl*>(pUserObj);
		if (uMsg == WM_USER + 2001)
		{
			// 播放中
			if (wParam == PLAYER_MSG_PROGRESS)
			{
				if (mediaPlayerControl->IsPlaying() && !mediaPlayerControl->IsSeeking())
				{
					long long frames = *(long long*)(lParam);
					QMetaObject::invokeMethod(mediaPlayerControl, "QueuePlayingCallback", Qt::QueuedConnection, Q_ARG(int, frames));
				}
			}
			// 停止播放
			else if (wParam == PLAYER_MSG_FINISH)
			{
				QMetaObject::invokeMethod(mediaPlayerControl, "QueuePlayerFinish", Qt::QueuedConnection);

			}
			else if (wParam == PLAYER_MSG_STOP)
			{
				QMetaObject::invokeMethod(mediaPlayerControl, "QueuePlayerStop", Qt::QueuedConnection);
			}
			else if (wParam == PLAYER_MSG_PAUSE)
			{
			}
			else if (wParam == PLAYER_MSG_SEEK || wParam == PLAYER_MSG_SEEK_PLAYING)
			{
				long long frames = *(long long*)(lParam);
				QMetaObject::invokeMethod(mediaPlayerControl, "QueuePlayerSeekFinish", Qt::QueuedConnection, Q_ARG(int, frames));

			}
			else if (wParam == PLAYER_MSG_LOAD)
			{
				QMetaObject::invokeMethod(mediaPlayerControl, "QueuePlayerLoad", Qt::QueuedConnection);
			}
			else if (wParam == PLAYER_MSG_PROGRESSFORMARKUP)
			{
				long long frames = *(long long*)(lParam);
				QMetaObject::invokeMethod(mediaPlayerControl, "QueuePlayingMarkdownCallback", Qt::QueuedConnection, Q_ARG(int, frames));
			}
		}
		return 0;
	}, this);


	// 获取音频数据
	m_IMediaPlayer->SetAudioVolumeCallBack([](void* pUserObj, UINT uMsg, WPARAM_PLAYER wParam, LPARAM_PLAYER lParam)->HRESULT{

		auto mediaPlayerControl = static_cast<MediaPlayerControl*>(pUserObj);
		if (uMsg == WM_AudioVolume)
		{
			DWORD l = *(DWORD*)wParam;
			DWORD r = *(DWORD*)lParam;
			QMetaObject::invokeMethod(mediaPlayerControl, "QueueAudioVolumesCallback", Qt::QueuedConnection, Q_ARG(int, l), Q_ARG(int, r));
		}
		return 0;
	}, this);
	return true;
}

void MediaPlayerControl::Release()
{
	delete this;
}

bool MediaPlayerControl::IsPlaying()
{
	return m_IMediaPlayer->GetPlayerState() == PS_PLAYING;
}

bool MediaPlayerControl::IsPause()
{
	return m_IMediaPlayer->GetPlayerState() == PS_PAUSE;
}

int MediaPlayerControl::Duration()
{
	int duration = 0;
	if (HaveSource())
	{
		if (m_timeline)
		{
			QPoint range = m_timeline->GetRange();
			duration = range.y() - range.x();
		}
		else
			duration = m_IMediaPlayer->GetMovieLength();
	}
	return duration;
}

//跳跃播放帧
bool MediaPlayerControl::Seek(int iFrame,int iaccurate)
{
	bool ret = true;
	if (HaveSource())
	{
		m_isSeeking = true;
		m_seekFrames = iFrame;
		m_curFrames = iFrame;
		ret = SUCCEEDED(m_IMediaPlayer->Seek(iFrame, iaccurate));
		/*	if (m_toolbar)
				m_toolbar->SeekManual(iFrame, iaccurate);*/
	}
	return ret;
}

bool MediaPlayerControl::IsSeeking()
{
	return m_isSeeking;
}

NLETimeline* MediaPlayerControl::GetTimeline()
{
	return m_timeline;
}

bool MediaPlayerControl::HaveSource()
{
	return m_haveSource;
}

void MediaPlayerControl::SetHwnd(HVIEW hview, const RECT &rect)
{
	if (!m_IPlayerView)
	{
		m_IPlayerView = m_IPlayerViewMgr->CreatePlayView(hview, rect);
	}
	else
	{
		m_IPlayerView->SetParentWND(hview);
		auto hwnd = m_IPlayerView->GetWND();
#ifdef WIN32
		SetWindowPos(m_IPlayerView->GetWND(), 0, 0, 0, rect.right, rect.bottom, SWP_NOACTIVATE);
#endif
	}
}

//注册回调函数
void MediaPlayerControl::RegisterPlayStartCallback(std::function<bool()> playStartCallbackFun)
{
    
}

//设置工具栏
void MediaPlayerControl::setToolBar(MediaPlayerToolBar* toolbar)
{
	if (toolbar != nullptr)
	{
		m_toolbar = toolbar;
	}
}

Q_INVOKABLE void MediaPlayerControl::QueuePlayerFinish()
{
	m_curFrames = 0;
	m_IMediaPlayer->Load();
	emit PlayFinishCallback();
}

Q_INVOKABLE void MediaPlayerControl::QueuePlayerSeekFinish(int frames)
{
	if (frames == m_seekFrames)
		m_isSeeking = false;
}

Q_INVOKABLE void MediaPlayerControl::QueuePlayerStop()
{
	if (!m_close)
	{
		m_IMediaPlayer->Load();
	}
	m_close = false;
	m_isStop = true;
	m_curFrames = 0;
	emit PlayStopCallback();
}

Q_INVOKABLE void MediaPlayerControl::QueuePlayingCallback(int frames)
{
	m_curFrames = frames;
	emit PlayingCallback(frames);
}
