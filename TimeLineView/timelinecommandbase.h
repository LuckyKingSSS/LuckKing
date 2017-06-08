#ifndef TIMELINECOMMANDBASE_H
#define TIMELINECOMMANDBASE_H

#include <QObject>
#include "timeruler.h"
class DragClip;

//Ŀǰ֧��redo undo ����������ֻ�У� ɾ�� �ü�  ���и����
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
	//�ƶ����α�ͷ��
	void signalMoveHandler(QPointF pos);
	//�ƶ� ���α��ߡ�
	void signalMoveFrameline(QPointF pos);
private:
	
};

//trim ��������
class TimelineTrimCommand : public TimelineCommandBase
{
public:
	TimelineTrimCommand(QPointF pos, DragClip* clip, bool bIsTouchLeft, bool bIsTouchRight);
	~TimelineTrimCommand();
	virtual void Undo();
	virtual void Redo();
	//�ж�trim�����Ƿ��ܹ����ƶ���Position
	bool canTrimToPos(DragClip* clip,QPointF pos);
	void trimTimeline(DragClip* clip, QPointF pos,int iType);
	void setTimeRuler(TimeRuler* ruler){ m_Ruler = ruler; };
	void setTimeline(NLETimeline* timeline){ m_ComplexTimeline = timeline; };
private:
	std::tuple<QPointF, int> m_RawData; //��һ��rect����Ϣ,��ʼֵΪ��ǰ
	std::tuple<int, int> m_RawFrameData; //(��ʼλ��֡���� �ܹ���֡��)��ʹ��֡��Ҫ���ӷ���
	std::tuple<int, int> m_CurrentFrameData; //��ǰtrim�����󣬸�timeline����Ӧ����ʼλ��֡ ��ֹλ��֡
	DragClip* m_OperateClip;  //��������clipʱ��Ƭ
	QPointF m_NewStartPos;    //��ǰ�û��ö���ʱ��Ƭ�������
	float m_iNewClipWidth;     //��ǰ�趨��clip�Ŀ��
	bool m_bIsLeftTrim;      //�Ƿ�����ߵ�trim����
	bool m_bIsRightTrim;    //�Ƿ����ұߵ�trim����
	TimeRuler* m_Ruler;     //ʱ��߿ؼ�����Ҫʹ�õ��¼���֡�������ת������
	NLETimeline* m_ComplexTimeline;
}; 

//delete ��������
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
	QVector<DragClip*>* m_AllSelectClips;   // ��ǰ���б�ѡ�е�clip�ļ���
	QVector<DragClip*> m_OldSelctClipList; //��һ�β�����clip���,�����ݣ��Ա���ԭ
	QMap<int,DragClip*>* m_AllClipInfo;      //��ǰ���е�clip��Ϣ
	QMap<int,DragClip*> m_OldAllClipInfo; //��һ�����е�clip��Ϣ �����ݣ��Ա���ԭ
	NLETimeline* m_ComposeTimeline;       //�ܵ�timeline
	TimeRuler* m_Ruler;                   //ʱ��߿ؼ�
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

//�и��������
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
	QMap<int,DragClip*>* m_AllClipInfo;      // ��ǰ���е�clip��Ϣ
	QMap<int,DragClip*> m_OldClipInfo;       // ��һ�����е�clip��Ϣ �����ݣ��Ա���ԭ
	QVector<DragClip*>* m_AllSelectClips;    // ��ǰ���б�ѡ�е�clip�ļ���
	QVector<DragClip*> m_OldSelctClipList;  //  ��һ�β�����clip���,�����ݣ��Ա���ԭ
	QVector<DragClip*>* m_SplitResult;       //  �ָ�֮���clip����
	NLETimeline* m_ComposeTimeline;        //  ��tiemline �ϳɵ�timeline
	NLETimeline* m_OldComposeTimeline;      //������ǰ��timeline����
	TimeRuler* m_Ruler;  //ʱ��߿ؼ�
	QPoint  m_DividePos; //�и�λ�õ�
	DragClip* m_CurrentHandleClip;//��ǰ׼���и��clip
};
#endif // TIMELINECOMMANDBASE_H