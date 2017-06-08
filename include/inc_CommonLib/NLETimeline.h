#ifndef NLETIMELINE_H
#define NLETIMELINE_H


#include <QtCore/QObject>
//#include <QImage>
//#include "windows.h"
#include "NLEComPtr.h"
#include "NLEPropComPtr/NLEKeyShortcut.h"
#include "inc_CommonLib/commonlib_global.h"

enum ExactType
{
	ExactType_Unknown = 0,
	ExactType_Video,
	ExactType_Audio,
	ExactType_Image,
	ExactType_VideoFilter,
	ExactType_AudioFilter,
	ExactType_Montage,
	ExactType_Caption,
};


class INLETimelineBase;
class INLETimelineClipControl;
class INLERender;
class COMMONLIB_EXPORT NLETimeline : public QObject
{
	Q_OBJECT

public:
	NLETimeline(NLEComPtr<INLETimelineBase> pSrcTimeline, ExactType exacttype = ExactType_Unknown, QObject *parent = nullptr);
	~NLETimeline();
	//属性设置
	virtual NLETimeline* Clone();
	void SetName(const QString &strName);
	QString GetName() const;
	//获取视频文件的总的视频帧数目
	int GetTotalLength();
	GUID GetGuid();
	void SetLevel(int nLevel);
	void SetPosition(int nPost);
	int GetPosition();
	void SetTrimin(int nTrimin);
	int GetTrimin();
	void SetTrimout(int nTrimout);
	int GetTrimout();
	//获取播放区域（起始帧，终止帧）
	QPoint GetRange();
	void SetRange(int nTrimin, int nTrimout);
	int GetPlayLen();
	int GetSrcLen();
	bool GetRender(INLERender** ppVideoRender, INLERender** ppAudioRender);
	void SetRenderSize(int nDx, int nDy);
	QSize GetRenderSize();
	void SetCropRegion(const QRectF  &rc);
	QRectF GetCropRegion();
	void GetTimelineBase(INLETimelineBase **ppTimelineBase);
	NLEComPtr<INLETimelineBase> GetSrc();
	void SetAncestralGuid(const QString &strGuid);
	QString GetAncestralGuid() const;
	//获取当前时间线对应的原始帧率（视频原始的帧率）
	float GetSourceFramerate();
	//获取当前时间线对应的渲染帧率（视频的渲染帧率）
	float GetRenderFramerate();
	bool IsFrameIn(int nFrame);
	int GetCurrentFrame();
	QImage GetCurrentFrameImg(int nFrameW, int nFrameH);
	QPointF GetRegionCenter();
	void SetRegionCenter(QPointF center);
	int GetRegionRotateAngle();
	void SetRegionRotateAngle(int angle);
	QSizeF GetRegionScale();
	void SetRegionScale(QSizeF size);
	QPixmap GetFramePixmap(int nFrame, int nW, int nH);
	void SetRenderFrameRate(float frameRate);
	float GetRenderFrameRate();
	ExactType GetExactType() const;
	//获取时间线的总的持续帧数目
	int GetDuration(); 
	//在当前时间线上叠加一个时间线（合并视频、音乐等多媒体文件）
	void AddClip(NLETimeline* pClip,int nStartPos = 0,int nLevel = 0);
	void RemoveClip(NLETimeline* pClip);
	void SetClipLevel(NLETimeline* pClip,int nLevel);
	void SetClipPos(NLETimeline* pClip,int nStartPos);
	//设置timeline的播放范围（是相对原始的timeline而言，原始timeline 的范围是 0 - totalLength）
	void SetClipRange(NLETimeline* pClip,int nTrimin, int nTrimout);
    int GetVolume();
    void SetVolume(int volume);
	
protected:
	bool IsClipExist(NLETimeline* pClip);
protected:
	NLEComPtr<INLETimelineBase> m_pSrcTimeLine;
	NLEPropComPtr m_pProp;
	QString m_strAncestralGuid;
	ExactType m_ExactType;
};

#endif // NLETIMELINE_H
