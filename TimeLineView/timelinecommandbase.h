#ifndef TIMELINECOMMANDBASE_H
#define TIMELINECOMMANDBASE_H

#include <QObject>
#include "timeruler.h"
class DragClip;

//目前支持redo undo 操作的命令只有： 删除 裁剪  剪切割操作
class TimelineCommandBase : public QObject,public QUndoCommand
{
	Q_OBJECT
public:
	TimelineCommandBase(QObject *parent = nullptr);
	~TimelineCommandBase();
	void undo()override;
	void redo()override;
	virtual void Undo(){};
	virtual void Redo(){};

Q_SIGNALS:
	void signalUpdateView();
	//移动“游标头”
	void signalMoveHandler(QPointF pos);
	//移动 “游标线”
	void signalMoveFrameline(QPointF pos);
private:
	
};

//trim 操作命令
class TimelineTrimCommand : public TimelineCommandBase
{
public:
	TimelineTrimCommand(QPointF pos, DragClip* clip, bool bIsTouchLeft, bool bIsTouchRight);
	~TimelineTrimCommand();
	virtual void Undo();
	virtual void Redo();
	//判断trim操作是否能够到制定的Position
	bool canTrimToPos(DragClip* clip,QPointF pos);
	void trimTimeline(DragClip* clip, QPointF pos,int iType);
	void setTimeRuler(TimeRuler* ruler){ m_Ruler = ruler; };
	void setTimeline(NLETimeline* timeline){ m_ComplexTimeline = timeline; };
private:
	std::tuple<QPointF, int> m_RawData; //上一次rect的信息,初始值为当前
	std::tuple<int, int> m_RawFrameData; //(起始位置帧数， 总共的帧数)，使用帧数要更加方便
	std::tuple<int, int> m_CurrentFrameData; //当前trim操作后，该timeline所对应的起始位置帧 终止位置帧
	DragClip* m_OperateClip;  //被操作的clip时间片
	QPointF m_NewStartPos;    //当前用户裁定的时间片的新起点
	float m_iNewClipWidth;     //当前设定的clip的宽度
	bool m_bIsLeftTrim;      //是否是左边的trim操作
	bool m_bIsRightTrim;    //是否是右边的trim操作
	TimeRuler* m_Ruler;     //时间尺控件，需要使用到事件尺帧和坐标的转换函数
	NLETimeline* m_ComplexTimeline;
}; 

//delete 操作命令
class TimelineDeleteCommand : public TimelineCommandBase
{
public:
	TimelineDeleteCommand(QVector<DragClip*>* clipList, QMap<int,DragClip*>* allClipInfo);
	~TimelineDeleteCommand();
	virtual void Undo();
	virtual void Redo(); 
	void setTimeRuler(TimeRuler* ruler){ m_Ruler = ruler; };
	void setTimeline(NLETimeline* timeline){ m_ComposeTimeline = timeline; }
private:
	QVector<DragClip*>* m_AllSelectClips;   // 当前所有被选中的clip的集合
	QVector<DragClip*> m_OldSelctClipList; //上一次操作的clip结果,做备份，以备还原
	QMap<int,DragClip*>* m_AllClipInfo;      //当前所有的clip信息
	QMap<int,DragClip*> m_OldAllClipInfo; //上一次所有的clip信息 做备份，以备还原
	NLETimeline* m_ComposeTimeline;       //总的timeline
	TimeRuler* m_Ruler;                   //时间尺控件
};


class TimelineCopyCommand : public TimelineCommandBase
{
public:
	TimelineCopyCommand();
	~TimelineCopyCommand(){}
	virtual void Undo();
	virtual void Redo();
	void setTimeline(NLETimeline* timeline){ m_ComposeTimeline = timeline; }
private:
	QVector<DragClip*> m_AllClipInfoList;
	QVector<DragClip*> m_OldClipInfoList;
	NLETimeline* m_ComposeTimeline;
};

//切割操作命令
class TimelineDivideCommand : public TimelineCommandBase
{
public:
	TimelineDivideCommand(QPoint& pos);
	~TimelineDivideCommand();
	virtual void Undo();
	virtual void Redo();
	void setTimeline(NLETimeline* timeline){ m_ComposeTimeline = timeline; }
	void setRuler(TimeRuler* ruler){ m_Ruler = ruler; };
	void setCurrentHandleClip(DragClip* clip){ m_CurrentHandleClip = clip; };
	void setClipInfo(QMap<int, DragClip*>* allDragclip, QVector<DragClip*>* allSelectClip)
	{
		m_AllClipInfo = allDragclip; 
		m_AllSelectClips = allSelectClip;
	};
private: 
	QMap<int,DragClip*>* m_AllClipInfo;      // 当前所有的clip信息
	QMap<int,DragClip*> m_OldClipInfo;       // 上一次所有的clip信息 做备份，以备还原
	QVector<DragClip*>* m_AllSelectClips;    // 当前所有被选中的clip的集合
	QVector<DragClip*> m_OldSelctClipList;  //  上一次操作的clip结果,做备份，以备还原
	QVector<DragClip*>* m_SplitResult;       //  分割之后的clip集合
	NLETimeline* m_ComposeTimeline;        //  分tiemline 合成的timeline
	NLETimeline* m_OldComposeTimeline;      //做操作前的timeline对象
	TimeRuler* m_Ruler;  //时间尺控件
	QPoint  m_DividePos; //切割位置点
	DragClip* m_CurrentHandleClip;//当前准备切割的clip
};
#endif // TIMELINECOMMANDBASE_H