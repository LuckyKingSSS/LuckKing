#ifndef DRAGCLIP_H
#define DRAGCLIP_H

#include "stdafx.h"
/************************************************************************/
/* ���ߣ�wangbiao
   ���ܣ���ק�Ķ�ý����Ϣ��
   ʱ�䣺2017/05/03
*/
/************************************************************************/

const int TIMELINEVIEW_TRACKITEM_HEIGHT_VIDEO = 65;
const int TIMELINEVIEW_TRACKITEM_HEIGHT_EFFECT = 42;
const int TIMELINEVIEW_TRACKITEM_HEIGHT_AUDIO = 42;
const int TIMELINEVIEW_TRACKITEM_WIDTH_HEADER = 55;

class DragClip : public QObject
{
	Q_OBJECT

public:
	DragClip(QObject *parent = nullptr);
	~DragClip();
	void initData();
	void SetPos(QPoint pos);
	void setPosF(QPointF pos){ m_StayPosF = pos; };
	void setClipWidth(float iWidth);
	void setClipResName(QString strName);
	void setDragPixmap(QPixmap* map = nullptr);
	void setPixMapRect(QRect rec);
	void setMediaType(FilmoraMediaType type);
	void setStackYPos(int pos);
	FilmoraMediaType getMediaType(){ return m_CurrentMediaType; };
	int getCurrentStackIndex(){ return m_iCurrentStackIndex; };
	void setCurrentStackIndex(int iIndex){ m_iCurrentStackIndex = iIndex; };
	QString getResourceName(){ return m_ClipResourceName; };
	//��¡��ȫ��ͬ�Ķ���
	DragClip* clone();
public:
	QPoint getPos(){ return m_StayPos; };
	QPointF getPosF(){ return m_StayPosF; };
	float getClipWidth(){ return m_ClipWidth; };
	QString getClipResName(){ return m_ClipResourceName; };
	QPixmap* getPixMap(){ return m_DragPixMap; };
	QRect getPixMapRec(){ return m_PixMapRec; };
	int getClipHeight();//��ȡ��ǰ�ľ��ο�ĸ߶�
	void setClipStateSelected(bool bIsSelected){ m_bIsSelected = bIsSelected; };
	bool getClipState(){ return m_bIsSelected; };
	QString getFilePath(){ return m_StrFilePath; };
	void setFilePath(QString strParth){ m_StrFilePath = strParth; };
	void setTimeline(NLETimeline* timeline){ m_CurrentTimeline = timeline; };
	NLETimeline* getTimeline(){ return m_CurrentTimeline; };
	void setCurrentLevel(int iLevel){ m_iLevel = iLevel; };
	int getLevel(){ return m_iLevel; };
	//��ȡ��ǰtimeline����֡��
	int getCurrentTimelineRange(){ return m_CurrentTimeline->GetRange().y() - m_CurrentTimeline->GetRange().x(); };
public:
	//��ǰ�Ĺ����ŷ����ı��ʱ�����õ�ǰ�������Ϣ
	void resetStackInfo(int iCurrentStackIndex, int iVedioStackNum);
private:
	QPoint m_StayPos;
	QPointF m_StayPosF; //����float��¼λ�ã���ȷ�ȸ�
	float m_ClipWidth;
	QString m_ClipResourceName;
	QPixmap* m_DragPixMap;//��קʱ�����ͼƬ
	QRect m_PixMapRec;   //��ʱ��Ƭ��ͼ�����Ӧ�ľ������򣬷���������ж�
	FilmoraMediaType m_CurrentMediaType; //��ǰʱ��Ƭ��Ӧ�Ķ�ý������,ע����Ŀǰֻ���Ƕ�ý���ļ����� �磺��Ƶ ��Ƶ ͼƬ������ ���֣����ˡ�ת����Ч������
	int m_StackStartYPos;        //��ǰ��Դ��Ӧ�Ĺ�������Y����
	int m_iCurrentStackIndex; //��ǰ��Դ���ڵĹ������ţ������1��ʼ����(Ĭ��û�й����ʱ������Ϊ 0)
	bool m_bIsSelected;//ʱ���߿ؼ��ϵ�ǰ��Դ�Ƿ�ѡ��
	QString m_StrFilePath;//��Դ�ļ����ڵ�·��
	NLETimeline* m_CurrentTimeline;//��ǰʱ��Ƭ��Ӧ��timeline����
	int m_iLevel; //��ǰclip  ���ڵ�level
};
#endif // DRAGCLIP_H
