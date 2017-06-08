#ifndef DRAGCLIP_H
#define DRAGCLIP_H

#include "stdafx.h"
/************************************************************************/
/* 作者：wangbiao
   功能：拖拽的多媒体信息类
   时间：2017/05/03
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
	//克隆完全相同的对象
	DragClip* clone();
public:
	QPoint getPos(){ return m_StayPos; };
	QPointF getPosF(){ return m_StayPosF; };
	float getClipWidth(){ return m_ClipWidth; };
	QString getClipResName(){ return m_ClipResourceName; };
	QPixmap* getPixMap(){ return m_DragPixMap; };
	QRect getPixMapRec(){ return m_PixMapRec; };
	int getClipHeight();//获取当前的矩形框的高度
	void setClipStateSelected(bool bIsSelected){ m_bIsSelected = bIsSelected; };
	bool getClipState(){ return m_bIsSelected; };
	QString getFilePath(){ return m_StrFilePath; };
	void setFilePath(QString strParth){ m_StrFilePath = strParth; };
	void setTimeline(NLETimeline* timeline){ m_CurrentTimeline = timeline; };
	NLETimeline* getTimeline(){ return m_CurrentTimeline; };
	void setCurrentLevel(int iLevel){ m_iLevel = iLevel; };
	int getLevel(){ return m_iLevel; };
	//获取当前timeline的总帧数
	int getCurrentTimelineRange(){ return m_CurrentTimeline->GetRange().y() - m_CurrentTimeline->GetRange().x(); };
public:
	//当前的轨道序号发生改变的时候，重置当前轨道的信息
	void resetStackInfo(int iCurrentStackIndex, int iVedioStackNum);
private:
	QPoint m_StayPos;
	QPointF m_StayPosF; //采用float记录位置，精确度高
	float m_ClipWidth;
	QString m_ClipResourceName;
	QPixmap* m_DragPixMap;//拖拽时跟随的图片
	QRect m_PixMapRec;   //在时间片视图上面对应的矩形区域，方便后续做判断
	FilmoraMediaType m_CurrentMediaType; //当前时间片对应的多媒体类型,注明：目前只考虑多媒体文件类型 如：音频 视频 图片不考虑 文字，过滤、转场等效果类型
	int m_StackStartYPos;        //当前资源对应的轨道的起点Y坐标
	int m_iCurrentStackIndex; //当前资源所在的轨道的序号，序号以1开始计数(默认没有轨道的时候设置为 0)
	bool m_bIsSelected;//时间线控件上当前资源是否被选中
	QString m_StrFilePath;//资源文件所在的路径
	NLETimeline* m_CurrentTimeline;//当前时间片对应的timeline参数
	int m_iLevel; //当前clip  所在的level
};
#endif // DRAGCLIP_H
