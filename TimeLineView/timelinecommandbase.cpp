#include "stdafx.h"
#include "timelinecommandbase.h"
#include "dragclip.h"
#include "timeruler.h"


TimelineCommandBase::TimelineCommandBase(QObject *parent)
{
}

TimelineCommandBase::~TimelineCommandBase()
{

}

void TimelineCommandBase::undo()
{
	Undo();
	//通知窗口进行更新界面
	emit signalUpdateView();
}

void TimelineCommandBase::redo()
{
	Redo();
	//通知窗口进行更新界面
	emit signalUpdateView();
}

TimelineTrimCommand::TimelineTrimCommand(QPointF pos, DragClip* clip, bool bIsTouchLeft, bool bIsTouchRight)
{
	m_OperateClip = clip;
	m_NewStartPos = pos;
	m_iNewClipWidth = clip->getClipWidth();
	m_RawData = std::make_tuple(clip->getPosF(), clip->getClipWidth());
	m_RawFrameData = std::make_tuple(0, clip->getCurrentTimelineRange());
	m_CurrentFrameData = std::make_tuple(0, 0);
	m_bIsRightTrim = bIsTouchRight;
	m_bIsLeftTrim = bIsTouchLeft;
	m_Ruler = nullptr;
	m_ComplexTimeline = nullptr;
}

TimelineTrimCommand::~TimelineTrimCommand()
{

}

void TimelineTrimCommand::Undo()
{
	//参数修改。。。
	QPointF startPos;
	int DragClipWidth;
	std::tie(startPos, DragClipWidth) = m_RawData;
	QRect preRect = m_OperateClip->getPixMapRec();
	m_OperateClip->setPixMapRect(QRect(startPos.x(), preRect.y(), DragClipWidth, preRect.height()));
	m_OperateClip->setClipWidth(DragClipWidth);

	int iBeginFrame = std::get<0>(m_CurrentFrameData);
	int iEndFrame = std::get<1>(m_CurrentFrameData);
	NLETimeline *timeline = m_OperateClip->getTimeline();
	m_ComplexTimeline->SetClipRange(timeline, iBeginFrame, iEndFrame);
	//设置时间片相对于轨道的起始位置
	int iRevertFrame = m_Ruler->getFrameNumFromPos(startPos.x() - 55.00);
	m_ComplexTimeline->SetClipPos(timeline, iRevertFrame);
}

void TimelineTrimCommand::Redo()
{
	//设置的时候需要考虑边界
	if (canTrimToPos(m_OperateClip, m_NewStartPos))
	{
		if (m_bIsLeftTrim)
		{
			//保存当前的时间片矩形信息
			m_RawData = std::make_tuple(QPointF(m_OperateClip->getPixMapRec().x(), m_OperateClip->getPixMapRec().y()), m_OperateClip->getPixMapRec().width());
			int iNewClipWidth = m_NewStartPos.x() - std::get<0>(m_RawData).x();
			iNewClipWidth = m_OperateClip->getClipWidth() - iNewClipWidth;
			//修改时间片矩形的界面参数（修改矩形的大小 位置）
			m_OperateClip->setClipWidth(iNewClipWidth);
			int lastRectYpos = m_OperateClip->getPixMapRec().y();
			int lastRectHeight = m_OperateClip->getPixMapRec().height();
			m_OperateClip->setPixMapRect(QRect(m_NewStartPos.x(), lastRectYpos, iNewClipWidth, lastRectHeight));
			m_OperateClip->setStackYPos(lastRectYpos);//y坐标保持不变
			//保存当前的起始帧位置和终止帧的位置方便后面处理timeline 
			int iCurrentStartFrame = m_Ruler->getFrameNumFromPos(m_NewStartPos.x() - 55.00);
			iCurrentStartFrame = iCurrentStartFrame - m_Ruler->getFrameNumFromPos(std::get<0>(m_RawData).x() - 55.00) + 1;
			int iTotalframe = m_Ruler->getFrameNumFromPos(m_NewStartPos.x() + iNewClipWidth - 55.00);
			iTotalframe = iTotalframe - m_Ruler->getFrameNumFromPos(m_NewStartPos.x() - 55.00) + 1;
			m_CurrentFrameData = std::make_tuple(0, m_OperateClip->getTimeline()->GetRange().y() - m_OperateClip->getTimeline()->GetRange().x());
			m_RawFrameData = std::make_tuple(iCurrentStartFrame, iCurrentStartFrame + iTotalframe);	
			//移动游标头和游标线
			QPointF pos(m_NewStartPos.x() - 55.00, m_NewStartPos.y());
			emit signalMoveHandler(pos);
			emit signalMoveFrameline(m_NewStartPos);
			//对时间线参数做修改
			trimTimeline(m_OperateClip, m_NewStartPos, 0);
		}
		else
		{
           //右边做trim操作
			m_RawData = std::make_tuple(QPointF(m_OperateClip->getPixMapRec().x(), m_OperateClip->getPixMapRec().y()), m_OperateClip->getPixMapRec().width());
			QPointF iRawStartPosF = m_OperateClip->getPosF();
			//因为是右边做trim操作，所以直接相减就是当前的rect的宽度
			int iNewClipWidth = m_NewStartPos.x() - iRawStartPosF.x();
			m_OperateClip->setClipWidth(iNewClipWidth);
			m_OperateClip->setPixMapRect(QRect(m_OperateClip->getPixMapRec().x(), m_OperateClip->getPixMapRec().y(), iNewClipWidth, m_OperateClip->getPixMapRec().height()));
			//保存当前timeline的帧的信息
			int iCurrentEndFrame = m_Ruler->getFrameNumFromPos(m_NewStartPos.x() - 55.00);
			int iCurrentStartFrame = m_Ruler->getFrameNumFromPos(std::get<0>(m_RawData).x() - 55.00);
			m_RawFrameData = std::make_tuple(m_OperateClip->getTimeline()->GetRange().x(), m_OperateClip->getTimeline()->GetRange().x() + iCurrentEndFrame - iCurrentStartFrame + 1);
			m_CurrentFrameData = std::make_tuple(m_OperateClip->getTimeline()->GetRange().x(), m_OperateClip->getTimeline()->GetRange().y() -  m_OperateClip->getTimeline()->GetRange().x());
			trimTimeline(m_OperateClip, m_NewStartPos, 1);//1代表右边做trim操作
		}	
	}
}

bool TimelineTrimCommand::canTrimToPos(DragClip* clip, QPointF pos)
{
	//目前做简单处理，当前能够被trim操作的前提是rec的宽度大于30pix
	//目的是保证如果时间尺的比例尺缩放到最小，一个最小刻度（对应1帧数据）的长度是30pix 
	//而业务上不能支持再对1帧这个最少的单位做trim操作
	bool bRec = false;
	//浮点值的边界可以不做判断
	if (m_bIsLeftTrim && !m_bIsRightTrim)
	{
		if (pos.x() > clip->getPixMapRec().x() && pos.x() < clip->getPixMapRec().x() + clip->getPixMapRec().width())
		{
			bRec = true;
		}
	}
	if (!m_bIsLeftTrim && m_bIsRightTrim)
	{
		if (pos.x() < clip->getPixMapRec().x() + clip->getPixMapRec().width() && pos.x() > clip->getPixMapRec().x())
		{
			bRec = true;
		}
	}
	return bRec;
}

void TimelineTrimCommand::trimTimeline(DragClip* clip, QPointF pos, int iType)
{
	if (iType == 0)
	{
		NLETimeline *timeline = m_OperateClip->getTimeline();
		int iRawBeginFrame = std::get<0>(m_RawFrameData);
		int iEndFrame = std::get<1>(m_RawFrameData);
		m_ComplexTimeline->SetClipRange(timeline, iRawBeginFrame, iEndFrame);
		float fBeginFrame = m_Ruler->getFrameNumFromPos(pos.x() - 55.00);
		//设置时间片相对于轨道的起始位置
		m_ComplexTimeline->SetClipPos(timeline, fBeginFrame);
	}
	else
	{
		//右边的trim操作
		NLETimeline *timeline = m_OperateClip->getTimeline();
		int iStartFrame = std::get<0>(m_RawFrameData);
		int iEndFrame = std::get<1>(m_RawFrameData);
		m_ComplexTimeline->SetClipRange(timeline, iStartFrame, iEndFrame);
		//由于是做右边的trim操作所以不需要重新设置timeline在track上的起点
	}
}

TimelineDeleteCommand::TimelineDeleteCommand(QVector<DragClip*>* clipList, QMap<int,DragClip*>* allClipInfo)
{
	m_AllClipInfo = allClipInfo;
	m_AllSelectClips = clipList;
	m_OldAllClipInfo = *allClipInfo;
	m_OldSelctClipList = *clipList;
}

TimelineDeleteCommand::~TimelineDeleteCommand()
{
 
}

void TimelineDeleteCommand::Undo()
{
	//还原数据
	QMap<int,DragClip*> tmpMap = *m_AllClipInfo;
	QVector<DragClip*> tmpVector = *m_AllSelectClips;
	*m_AllClipInfo =  m_OldAllClipInfo;
	*m_AllSelectClips = m_OldSelctClipList;
	m_OldAllClipInfo = tmpMap;
	m_OldSelctClipList = tmpVector;
	//对时间线做还原操作
	QVector<DragClip*>::iterator allSelectIter = m_AllSelectClips->begin();
	for (; allSelectIter != m_AllSelectClips->end(); ++allSelectIter)
	{
		NLETimeline* timeline = (*allSelectIter)->getTimeline();
		int iXPos = (*allSelectIter)->getPixMapRec().x();
		//暂时没有区分level
		int iLevel = (*allSelectIter)->getLevel();
		int iOffFrameNum = m_Ruler->getFrameNumFromPos(iXPos - 55.00);
		m_ComposeTimeline->AddClip(timeline, iOffFrameNum, 0);
	}
}

void TimelineDeleteCommand::Redo()
{
	//做操作之前先保存当期的数据以备undo做恢复操作
	//todo ：　为什么做assign 操作程序会 crash???
	//为什么赋值操作会对QMap的迭代器产生影响
	m_OldAllClipInfo = *m_AllClipInfo;
	m_OldSelctClipList = *m_AllSelectClips;
	QVector<DragClip*>::iterator  allSelectInfoIter = m_AllSelectClips->begin();
	QMap<int, DragClip*>::iterator allClipinfoIter = m_AllClipInfo->begin();
	//将所有选总的clip删除
	for (; allSelectInfoIter != m_AllSelectClips->end(); ++allSelectInfoIter)
	{
		for (; allClipinfoIter != m_AllClipInfo->end();)
		{
			if (*allClipinfoIter == *allSelectInfoIter)
			{
				/*QList<int> Keys = m_AllClipInfo->keys(*allClipinfoIter);
				QList<int>::iterator iter = Keys.begin();
				for (; iter != Keys.end();++iter)
				{
				m_AllClipInfo->remove(*iter);
				}*/
				m_AllClipInfo->erase(allClipinfoIter);
				//对时间线做处理
				NLETimeline* timeline = (*allSelectInfoIter)->getTimeline();
				m_ComposeTimeline->RemoveClip(timeline);
				break;
			}
			else
			{
                //没有匹配到则往后继续匹配
				allClipinfoIter++;
			}
		}
	}
	m_AllSelectClips->clear();
	emit signalUpdateView();
}

TimelineDivideCommand::TimelineDivideCommand(QPoint& pos)
{
	m_DividePos = pos;
	m_OldComposeTimeline = nullptr;
	m_SplitResult = new QVector < DragClip* > ;
}

TimelineDivideCommand::~TimelineDivideCommand()
{

}

void TimelineDivideCommand::Undo()
{
	//还原tiemline 参数
	QVector<DragClip*>::iterator iter = m_SplitResult->begin();
	for (; iter != m_SplitResult->end(); ++iter)
    {
		NLETimeline* timeline = (*iter)->getTimeline();
		m_ComposeTimeline->RemoveClip(timeline);
    }
	m_SplitResult->clear();
	QVector<DragClip*>::iterator OldIter = m_OldSelctClipList.begin();
	for (; OldIter != m_OldSelctClipList.end(); ++OldIter)
	{
		NLETimeline* timeline = (*OldIter)->getTimeline();
		int iXPos = (*OldIter)->getPixMapRec().x();
		//暂时没有区分level
		int iLevel = (*OldIter)->getLevel();
		int iOffFrameNum = m_Ruler->getFrameNumFromPos(iXPos - 55.00);
		m_ComposeTimeline->AddClip(timeline, iOffFrameNum,iLevel);
	}
	//还原clip参数
	*m_AllClipInfo = m_OldClipInfo;
	*m_AllSelectClips = m_OldSelctClipList;
}

//暂时仅仅支持单选的情况，不支持用户做多选，后期实现
//todo: 时间线处理存在问题
void TimelineDivideCommand::Redo()
{
	//修改前先做备份
	m_OldClipInfo = *m_AllClipInfo;
	m_OldSelctClipList = *m_AllSelectClips;
	m_OldComposeTimeline =  m_ComposeTimeline->Clone();
    //修改clip界面
	DragClip* leftClip = new DragClip();
	DragClip* rightClip = new DragClip();
	//同步重要的参数
	leftClip = m_CurrentHandleClip->clone();
	rightClip = m_CurrentHandleClip->clone();
	//修改leftClip
	QRect rect = leftClip->getPixMapRec();
	rect.setWidth(m_DividePos.x() - rect.x());
	leftClip->setPixMapRect(rect);
	leftClip->setClipWidth(rect.width());
	//修改rightClip
	rect = rightClip->getPixMapRec();
	rect.setX(m_DividePos.x());
	rect.setWidth(rect.width() - m_DividePos.x() + rect.x());
	rightClip->setPixMapRect(rect);
	rightClip->setClipWidth(rect.width());
	//对stack 中所有的clip信息做修改
	QMap<int, DragClip*>::iterator iter = m_AllClipInfo->begin();
	for (; iter != m_AllClipInfo->end();++iter)
	{
		if (*iter == m_CurrentHandleClip)
		{
			//先处理leftClip
			NLETimeline* curTimeline = leftClip->getTimeline()->Clone();
			QPoint range = curTimeline->GetRange();
			int iTotalFrames = m_Ruler->getFrameNumFromPos(m_DividePos.x() - 55.00) - m_Ruler->getFrameNumFromPos(m_CurrentHandleClip->getPixMapRec().x() - 55.00);
			range.setY(iTotalFrames);
			curTimeline->SetRange(range.x(), range.y());
			//先删除原先的后插入被拆分的timeline
			m_ComposeTimeline->RemoveClip((*iter)->getTimeline());
			m_ComposeTimeline->AddClip(curTimeline, m_Ruler->getFrameNumFromPos(m_CurrentHandleClip->getPixMapRec().x() - 55.00));
			m_ComposeTimeline->SetClipPos(curTimeline, m_Ruler->getFrameNumFromPos(m_CurrentHandleClip->getPixMapRec().x() - 55.00));
			leftClip->setTimeline(curTimeline);
			//后处理rightClip
			NLETimeline*  curRightTimeline = rightClip->getTimeline()->Clone();
			range = curRightTimeline->GetRange();
			iTotalFrames = m_Ruler->getFrameNumFromPos(m_CurrentHandleClip->getPixMapRec().x() + m_CurrentHandleClip->getPixMapRec().width() - 55.00) - m_Ruler->getFrameNumFromPos(m_DividePos.x() - 55.00) + 1;
			QPoint leftRange = leftClip->getTimeline()->GetRange();
			range.setX(leftRange.y() + 1);
			curRightTimeline->SetRange(range.x(), range.y());
			//先删除原先的后插入被拆分的timeline
			m_ComposeTimeline->AddClip(curRightTimeline, m_Ruler->getFrameNumFromPos(m_DividePos.x() - 55.00));
			m_ComposeTimeline->SetClipPos(curRightTimeline, m_Ruler->getFrameNumFromPos(m_DividePos.x() - 55.00));
			rightClip->setTimeline(curRightTimeline);
			m_AllClipInfo->erase(iter);
			break;
		}
	}
	//插入当前拆分的两个子clip对象
	m_AllClipInfo->insertMulti(leftClip->getMediaType(),leftClip);
	m_AllClipInfo->insertMulti(rightClip->getMediaType(), rightClip);
	//暂时仅仅支持单选
	m_AllSelectClips->clear();
	m_AllSelectClips->push_back(rightClip);
	m_SplitResult->push_back(leftClip);
	m_SplitResult->push_back(rightClip);

	//QVector<DragClip*>::iterator vecIter = m_AllSelectClips->begin();
	//for (; vecIter != m_AllSelectClips->end();++vecIter)
	//{
	//	m_AllSelectClips->erase(vecIter);
	//	 //将切割的右边部分置为选中
	//	m_AllSelectClips->push_back(rightClip);
	//	break;
	//}
}
