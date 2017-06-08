#ifndef IMEDIAPLAYERCONTROL_H
#define IMEDIAPLAYERCONTROL_H

#include <QObject>
#include <functional>
#include "meidaplayerview_global.h"
class NLETimeline;
class MEIDAPLAYERVIEW_EXPORT IMediaPlayerControl : public QObject
{
	Q_OBJECT
public:
	static IMediaPlayerControl* GetInstance();
	virtual bool Open(int iSourceType,NLETimeline* timeline) = 0;
	virtual bool Play() = 0;
	virtual bool Stop() = 0;
	virtual bool Pause() = 0;
	virtual bool Close() = 0;
	virtual bool Forward() = 0;
	virtual bool Backward() = 0;
	virtual bool Seek(int iCuurentFrame, int accurate) = 0;
	virtual int Duration() = 0;

	virtual NLETimeline* GetTimeline() = 0;
	virtual void RegisterPlayStartCallback(std::function<bool()> playStartCallbackFun) = 0;
Q_SIGNALS:
	// 播放中帧回调信号，单位帧
	void PlayingCallback(int frames);
	// 开始播放
	void PlayStartCallback();
	//void PlayFinishCallback();
};

#endif // MEDIAPLAYERCONTROL_H
