#ifndef MEDIAPLAYERCONTROL_H
#define MEDIAPLAYERCONTROL_H

#include <QObject>
#include <functional>
#include "include/NLEComPtr.h"
#include "Interface/INLEPlayer.h"
#include "inc_MediaPlayerView/IMediaPlayerControl.h"
class NLETimeline;
class IPlayerView;
class INLEPlayer;
class IPlayerViewMgr;
class MediaPlayerToolBar;
class MediaPlayerControl : public IMediaPlayerControl
{
	Q_OBJECT
public:
	MediaPlayerControl();
	~MediaPlayerControl();

	void initData();
	void initConnections();
	bool Open(int iSourceType, NLETimeline* timeline)override;
	bool Play()override;
	bool Stop()override;
	bool Pause()override;
	bool Close() override;
	bool Forward()override;
	bool Backward()override;

	bool Init();
	void Release();
	bool IsPlaying();
	bool IsSeeking();
	bool IsPause();
	//获取视频的总的帧数
	int Duration();
	bool Seek(int iFrame,int accurate);
	bool Open(int bSource, INLERender *pVideoRender, INLERender*  pAudioRender, float fps);
	void SetRatio(float ratio);
	void UpdateRatio();
	NLETimeline* GetTimeline()override;
	bool HaveSource();
	void SetHwnd(HVIEW hview, const RECT &rect);
	void RegisterPlayStartCallback(std::function<bool()> playStartCallbackFun) override;
	void setToolBar(MediaPlayerToolBar* toolbar);
	Q_INVOKABLE void QueuePlayingCallback(int frames);
    Q_INVOKABLE void QueuePlayerStop();
	Q_INVOKABLE void QueuePlayerFinish();
	Q_INVOKABLE void QueuePlayerSeekFinish(int frames);

Q_SIGNALS:
	void PlayStopCallback();
	// 开始播放
	void PlayStartCallback();
	//暂停
	void PlayPauseCallback();
	//完成当前视频的播放
	void PlayFinishCallback();

private:
	NLETimeline* m_timeline;
	NLEComPtr<INLEPlayer> m_IMediaPlayer;
	NLEComPtr<IPlayerViewMgr> m_IPlayerViewMgr;
	IPlayerView* m_IPlayerView;
	float m_fps;
	bool m_haveSource;
	MediaPlayerToolBar*  m_toolbar;
	float m_ratio;
	bool m_close;
	bool m_isSeeking;
	int m_seekFrames;
	bool m_isStop;
	int m_curFrames;

	std::function<bool()> m_playStartCallbackFun;
public:
	static MediaPlayerControl *g_control;
};

#endif // MEDIAPLAYERCONTROL_H
