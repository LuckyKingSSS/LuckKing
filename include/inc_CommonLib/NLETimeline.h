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
	//��������
	virtual NLETimeline* Clone();
	void SetName(const QString &strName);
	QString GetName() const;
	//��ȡ��Ƶ�ļ����ܵ���Ƶ֡��Ŀ
	int GetTotalLength();
	GUID GetGuid();
	void SetLevel(int nLevel);
	void SetPosition(int nPost);
	int GetPosition();
	void SetTrimin(int nTrimin);
	int GetTrimin();
	void SetTrimout(int nTrimout);
	int GetTrimout();
	//��ȡ����������ʼ֡����ֹ֡��
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
	//��ȡ��ǰʱ���߶�Ӧ��ԭʼ֡�ʣ���Ƶԭʼ��֡�ʣ�
	float GetSourceFramerate();
	//��ȡ��ǰʱ���߶�Ӧ����Ⱦ֡�ʣ���Ƶ����Ⱦ֡�ʣ�
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
	//��ȡʱ���ߵ��ܵĳ���֡��Ŀ
	int GetDuration(); 
	//�ڵ�ǰʱ�����ϵ���һ��ʱ���ߣ��ϲ���Ƶ�����ֵȶ�ý���ļ���
	void AddClip(NLETimeline* pClip,int nStartPos = 0,int nLevel = 0);
	void RemoveClip(NLETimeline* pClip);
	void SetClipLevel(NLETimeline* pClip,int nLevel);
	void SetClipPos(NLETimeline* pClip,int nStartPos);
	//����timeline�Ĳ��ŷ�Χ�������ԭʼ��timeline���ԣ�ԭʼtimeline �ķ�Χ�� 0 - totalLength��
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
