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
	//֪ͨ���ڽ��и��½���
	emit signalUpdateView();
}

void TimelineCommandBase::redo()
{
	Redo();
	//֪ͨ���ڽ��и��½���
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
	//�����޸ġ�����
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
	//����ʱ��Ƭ����ڹ������ʼλ��
	int iRevertFrame = m_Ruler->getFrameNumFromPos(startPos.x() - 55.00);
	m_ComplexTimeline->SetClipPos(timeline, iRevertFrame);
}

void TimelineTrimCommand::Redo()
{
	//���õ�ʱ����Ҫ���Ǳ߽�
	if (canTrimToPos(m_OperateClip, m_NewStartPos))
	{
		if (m_bIsLeftTrim)
		{
			//���浱ǰ��ʱ��Ƭ������Ϣ
			m_RawData = std::make_tuple(QPointF(m_OperateClip->getPixMapRec().x(), m_OperateClip->getPixMapRec().y()), m_OperateClip->getPixMapRec().width());
			int iNewClipWidth = m_NewStartPos.x() - std::get<0>(m_RawData).x();
			iNewClipWidth = m_OperateClip->getClipWidth() - iNewClipWidth;
			//�޸�ʱ��Ƭ���εĽ���������޸ľ��εĴ�С λ�ã�
			m_OperateClip->setClipWidth(iNewClipWidth);
			int lastRectYpos = m_OperateClip->getPixMapRec().y();
			int lastRectHeight = m_OperateClip->getPixMapRec().height();
			m_OperateClip->setPixMapRect(QRect(m_NewStartPos.x(), lastRectYpos, iNewClipWidth, lastRectHeight));
			m_OperateClip->setStackYPos(lastRectYpos);//y���걣�ֲ���
			//���浱ǰ����ʼ֡λ�ú���ֹ֡��λ�÷�����洦��timeline 
			int iCurrentStartFrame = m_Ruler->getFrameNumFromPos(m_NewStartPos.x() - 55.00);
			iCurrentStartFrame = iCurrentStartFrame - m_Ruler->getFrameNumFromPos(std::get<0>(m_RawData).x() - 55.00) + 1;
			int iTotalframe = m_Ruler->getFrameNumFromPos(m_NewStartPos.x() + iNewClipWidth - 55.00);
			iTotalframe = iTotalframe - m_Ruler->getFrameNumFromPos(m_NewStartPos.x() - 55.00) + 1;
			m_CurrentFrameData = std::make_tuple(0, m_OperateClip->getTimeline()->GetRange().y() - m_OperateClip->getTimeline()->GetRange().x());
			m_RawFrameData = std::make_tuple(iCurrentStartFrame, iCurrentStartFrame + iTotalframe);	
			//�ƶ��α�ͷ���α���
			QPointF pos(m_NewStartPos.x() - 55.00, m_NewStartPos.y());
			emit signalMoveHandler(pos);
			emit signalMoveFrameline(m_NewStartPos);
			//��ʱ���߲������޸�
			trimTimeline(m_OperateClip, m_NewStartPos, 0);
		}
		else
		{
           //�ұ���trim����
			m_RawData = std::make_tuple(QPointF(m_OperateClip->getPixMapRec().x(), m_OperateClip->getPixMapRec().y()), m_OperateClip->getPixMapRec().width());
			QPointF iRawStartPosF = m_OperateClip->getPosF();
			//��Ϊ���ұ���trim����������ֱ��������ǵ�ǰ��rect�Ŀ��
			int iNewClipWidth = m_NewStartPos.x() - iRawStartPosF.x();
			m_OperateClip->setClipWidth(iNewClipWidth);
			m_OperateClip->setPixMapRect(QRect(m_OperateClip->getPixMapRec().x(), m_OperateClip->getPixMapRec().y(), iNewClipWidth, m_OperateClip->getPixMapRec().height()));
			//���浱ǰtimeline��֡����Ϣ
			int iCurrentEndFrame = m_Ruler->getFrameNumFromPos(m_NewStartPos.x() - 55.00);
			int iCurrentStartFrame = m_Ruler->getFrameNumFromPos(std::get<0>(m_RawData).x() - 55.00);
			m_RawFrameData = std::make_tuple(m_OperateClip->getTimeline()->GetRange().x(), m_OperateClip->getTimeline()->GetRange().x() + iCurrentEndFrame - iCurrentStartFrame + 1);
			m_CurrentFrameData = std::make_tuple(m_OperateClip->getTimeline()->GetRange().x(), m_OperateClip->getTimeline()->GetRange().y() -  m_OperateClip->getTimeline()->GetRange().x());
			trimTimeline(m_OperateClip, m_NewStartPos, 1);//1�����ұ���trim����
		}	
	}
}

bool TimelineTrimCommand::canTrimToPos(DragClip* clip, QPointF pos)
{
	//Ŀǰ���򵥴�����ǰ�ܹ���trim������ǰ����rec�Ŀ�ȴ���30pix
	//Ŀ���Ǳ�֤���ʱ��ߵı��������ŵ���С��һ����С�̶ȣ���Ӧ1֡���ݣ��ĳ�����30pix 
	//��ҵ���ϲ���֧���ٶ�1֡������ٵĵ�λ��trim����
	bool bRec = false;
	//����ֵ�ı߽���Բ����ж�
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
		//����ʱ��Ƭ����ڹ������ʼλ��
		m_ComplexTimeline->SetClipPos(timeline, fBeginFrame);
	}
	else
	{
		//�ұߵ�trim����
		NLETimeline *timeline = m_OperateClip->getTimeline();
		int iStartFrame = std::get<0>(m_RawFrameData);
		int iEndFrame = std::get<1>(m_RawFrameData);
		m_ComplexTimeline->SetClipRange(timeline, iStartFrame, iEndFrame);
		//���������ұߵ�trim�������Բ���Ҫ��������timeline��track�ϵ����
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
	//��ԭ����
	QMap<int,DragClip*> tmpMap = *m_AllClipInfo;
	QVector<DragClip*> tmpVector = *m_AllSelectClips;
	*m_AllClipInfo =  m_OldAllClipInfo;
	*m_AllSelectClips = m_OldSelctClipList;
	m_OldAllClipInfo = tmpMap;
	m_OldSelctClipList = tmpVector;
	//��ʱ��������ԭ����
	QVector<DragClip*>::iterator allSelectIter = m_AllSelectClips->begin();
	for (; allSelectIter != m_AllSelectClips->end(); ++allSelectIter)
	{
		NLETimeline* timeline = (*allSelectIter)->getTimeline();
		int iXPos = (*allSelectIter)->getPixMapRec().x();
		//��ʱû������level
		int iLevel = (*allSelectIter)->getLevel();
		int iOffFrameNum = m_Ruler->getFrameNumFromPos(iXPos - 55.00);
		m_ComposeTimeline->AddClip(timeline, iOffFrameNum, 0);
	}
}

void TimelineDeleteCommand::Redo()
{
	//������֮ǰ�ȱ��浱�ڵ������Ա�undo���ָ�����
	//todo ����Ϊʲô��assign ��������� crash???
	//Ϊʲô��ֵ�������QMap�ĵ���������Ӱ��
	m_OldAllClipInfo = *m_AllClipInfo;
	m_OldSelctClipList = *m_AllSelectClips;
	QVector<DragClip*>::iterator  allSelectInfoIter = m_AllSelectClips->begin();
	QMap<int, DragClip*>::iterator allClipinfoIter = m_AllClipInfo->begin();
	//������ѡ�ܵ�clipɾ��
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
				//��ʱ����������
				NLETimeline* timeline = (*allSelectInfoIter)->getTimeline();
				m_ComposeTimeline->RemoveClip(timeline);
				break;
			}
			else
			{
                //û��ƥ�䵽���������ƥ��
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
	//��ԭtiemline ����
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
		//��ʱû������level
		int iLevel = (*OldIter)->getLevel();
		int iOffFrameNum = m_Ruler->getFrameNumFromPos(iXPos - 55.00);
		m_ComposeTimeline->AddClip(timeline, iOffFrameNum,iLevel);
	}
	//��ԭclip����
	*m_AllClipInfo = m_OldClipInfo;
	*m_AllSelectClips = m_OldSelctClipList;
}

//��ʱ����֧�ֵ�ѡ���������֧���û�����ѡ������ʵ��
//todo: ʱ���ߴ����������
void TimelineDivideCommand::Redo()
{
	//�޸�ǰ��������
	m_OldClipInfo = *m_AllClipInfo;
	m_OldSelctClipList = *m_AllSelectClips;
	m_OldComposeTimeline =  m_ComposeTimeline->Clone();
    //�޸�clip����
	DragClip* leftClip = new DragClip();
	DragClip* rightClip = new DragClip();
	//ͬ����Ҫ�Ĳ���
	leftClip = m_CurrentHandleClip->clone();
	rightClip = m_CurrentHandleClip->clone();
	//�޸�leftClip
	QRect rect = leftClip->getPixMapRec();
	rect.setWidth(m_DividePos.x() - rect.x());
	leftClip->setPixMapRect(rect);
	leftClip->setClipWidth(rect.width());
	//�޸�rightClip
	rect = rightClip->getPixMapRec();
	rect.setX(m_DividePos.x());
	rect.setWidth(rect.width() - m_DividePos.x() + rect.x());
	rightClip->setPixMapRect(rect);
	rightClip->setClipWidth(rect.width());
	//��stack �����е�clip��Ϣ���޸�
	QMap<int, DragClip*>::iterator iter = m_AllClipInfo->begin();
	for (; iter != m_AllClipInfo->end();++iter)
	{
		if (*iter == m_CurrentHandleClip)
		{
			//�ȴ���leftClip
			NLETimeline* curTimeline = leftClip->getTimeline()->Clone();
			QPoint range = curTimeline->GetRange();
			int iTotalFrames = m_Ruler->getFrameNumFromPos(m_DividePos.x() - 55.00) - m_Ruler->getFrameNumFromPos(m_CurrentHandleClip->getPixMapRec().x() - 55.00);
			range.setY(iTotalFrames);
			curTimeline->SetRange(range.x(), range.y());
			//��ɾ��ԭ�ȵĺ���뱻��ֵ�timeline
			m_ComposeTimeline->RemoveClip((*iter)->getTimeline());
			m_ComposeTimeline->AddClip(curTimeline, m_Ruler->getFrameNumFromPos(m_CurrentHandleClip->getPixMapRec().x() - 55.00));
			m_ComposeTimeline->SetClipPos(curTimeline, m_Ruler->getFrameNumFromPos(m_CurrentHandleClip->getPixMapRec().x() - 55.00));
			leftClip->setTimeline(curTimeline);
			//����rightClip
			NLETimeline*  curRightTimeline = rightClip->getTimeline()->Clone();
			range = curRightTimeline->GetRange();
			iTotalFrames = m_Ruler->getFrameNumFromPos(m_CurrentHandleClip->getPixMapRec().x() + m_CurrentHandleClip->getPixMapRec().width() - 55.00) - m_Ruler->getFrameNumFromPos(m_DividePos.x() - 55.00) + 1;
			QPoint leftRange = leftClip->getTimeline()->GetRange();
			range.setX(leftRange.y() + 1);
			curRightTimeline->SetRange(range.x(), range.y());
			//��ɾ��ԭ�ȵĺ���뱻��ֵ�timeline
			m_ComposeTimeline->AddClip(curRightTimeline, m_Ruler->getFrameNumFromPos(m_DividePos.x() - 55.00));
			m_ComposeTimeline->SetClipPos(curRightTimeline, m_Ruler->getFrameNumFromPos(m_DividePos.x() - 55.00));
			rightClip->setTimeline(curRightTimeline);
			m_AllClipInfo->erase(iter);
			break;
		}
	}
	//���뵱ǰ��ֵ�������clip����
	m_AllClipInfo->insertMulti(leftClip->getMediaType(),leftClip);
	m_AllClipInfo->insertMulti(rightClip->getMediaType(), rightClip);
	//��ʱ����֧�ֵ�ѡ
	m_AllSelectClips->clear();
	m_AllSelectClips->push_back(rightClip);
	m_SplitResult->push_back(leftClip);
	m_SplitResult->push_back(rightClip);

	//QVector<DragClip*>::iterator vecIter = m_AllSelectClips->begin();
	//for (; vecIter != m_AllSelectClips->end();++vecIter)
	//{
	//	m_AllSelectClips->erase(vecIter);
	//	 //���и���ұ߲�����Ϊѡ��
	//	m_AllSelectClips->push_back(rightClip);
	//	break;
	//}
}
