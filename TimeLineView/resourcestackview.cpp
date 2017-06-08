#include "stdafx.h"
#include <QPainter>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDragMoveEvent>
#include <QDrag>
#include <QtDebug>
#include <QVector>
#include "resourcestackview.h"
#include "dragclip.h"
#include "NLEComPtr.h"
#include "NLEWraper.h"
#include "NLETimeline.h"
#include "timeruler.h"
#include "FileOperation.h"
#include "timelinecommandbase.h "
#include <QMessageBox>


class NLETimeline;
ResourceStackView::ResourceStackView(QWidget *parent)
	: QWidget(parent)
{
	initData();
	initConnections();
	this->resize(800, m_initalHeight);
	setAcceptDrops(true);
	this->setMouseTracking(true);
}

ResourceStackView::~ResourceStackView()
{

}

//�϶���Դʱ���ڶ�Ӧ��һ�������Ӧ�û��Ƶ�ͼƬ���ο�����Ͻ�Y������
int ResourceStackView::getDrapLipeTopPos(QPoint dragPos)
{
	int dragYPos = 0;
	if (dragPos.y() <= m_firstDistance)
	{
		dragYPos = 0;
	}
	else
	{
		int iNum = (dragPos.y() - m_firstDistance) / m_Distance;
		if (iNum == 0)
		{
			dragYPos = 0;
			return dragYPos;
		}
		if ((dragPos.y() - m_firstDistance) % m_Distance != 0)
		{

			dragYPos = m_firstDistance + iNum * m_Distance;
		}
		else
		{
			dragYPos = m_firstDistance + ((iNum > 1) ? iNum - 1 : 1)* m_Distance;
		}
	}
	return dragYPos;
}

//���õ�ǰʹ�õ��¼��߿ؼ�
void  ResourceStackView::setRuler(TimeRuler* ruler)
{
	m_Ruler = ruler;

}

void ResourceStackView::getAllSelectRect()
{
	QMap<int, DragClip*>::iterator iter = m_AllClipInfo.begin();
	for (; iter != m_AllClipInfo.end(); ++iter)
	{
		if ((*iter)->getClipState())
		{
			m_AllSecletedClips.push_back(*iter);
		}
	}
}

void ResourceStackView::doSplitAction()
{
	TimelineDivideCommand* pCommand = new TimelineDivideCommand(m_SpinLinePos);
	pCommand->setTimeline(m_ComplexTimeline);
	pCommand->setRuler(m_Ruler);
	pCommand->setClipInfo(&m_AllClipInfo, &m_AllSecletedClips);
	//Ŀǰ��֧�ֵ�ѡ����
	if (m_AllSecletedClips.size() > 0 )
	{
		pCommand->setCurrentHandleClip(m_AllSecletedClips[0]);
	}
	else
	{
		pCommand->setCurrentHandleClip(nullptr);
	}
	connect(pCommand, &TimelineDivideCommand::signalUpdateView, this, [&](){
		update();
	});
	m_UndoStack.push(static_cast<TimelineCommandBase*>(pCommand));
}

void ResourceStackView::resizeEvent(QResizeEvent* event)
{

}

void ResourceStackView::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.save();
	QPen pen(Qt::SolidLine | Qt::black);
	painter.setPen(pen);
	//���ƹ��
	QVector<headType>::iterator stackIter = m_StackList.begin();
	for (stackIter; stackIter != m_StackList.end(); ++stackIter)
	{
		//�����Ŀ�Ǵ�1��ʼ������������Ҫ����1
		int iIndex = stackIter - m_StackList.begin() + 1;
		if (iIndex <= m_iMovieStackNum)
		{
			//������Ƶ���
			painter.drawLine(0, m_firstDistance * iIndex, width(), m_firstDistance * iIndex);
			createHeadPixMap(TYPE_MOVIE, iIndex, painter);
		}
		if (iIndex > m_iMovieStackNum && iIndex <= m_iMovieStackNum + m_iEffectStackNum)
		{
			//����effect���
			int iCurrentStackDistance = m_firstDistance * m_iMovieStackNum + m_iEffectStackNum * m_Distance;
			painter.drawLine(0, iCurrentStackDistance, width(), iCurrentStackDistance);
			createHeadPixMap(TYPE_EFFECT, iIndex, painter);
		}
		if (iIndex > m_iMovieStackNum + m_iEffectStackNum && iIndex <= m_iMovieStackNum + m_iEffectStackNum + m_iMusicStackNum)
		{
			//����music ���
			int iMovieStackDistance = m_firstDistance * m_iMovieStackNum + (m_iEffectStackNum + m_iMusicStackNum) * m_Distance;
			painter.drawLine(0, iMovieStackDistance, width(), iMovieStackDistance);
			createHeadPixMap(TYPE_EFFECT, iIndex, painter);
		}
	}
	//�����α�
	painter.drawLine(m_SpinLinePos.x(), 0, m_SpinLinePos.x(), m_initalHeight);
	//����clip
	QMap<int, DragClip*>::iterator iter = m_AllClipInfo.begin();
	for (; iter != m_AllClipInfo.end(); ++iter)
	{
		QPointF pos = (*iter)->getPos();
		int iMovieRecWidth = (*iter)->getClipWidth();
		QRect recArea;
		if ((*iter)->getMediaType() == TYPE_MOVIE)
		{
			int iLevelIndex = (*iter)->getCurrentStackIndex();
			recArea = QRect(pos.x(), (iLevelIndex - 1)* m_firstDistance, iMovieRecWidth, m_firstDistance);
			//������Ƶ���ļ�����Ϣ   --ʹ��drawText QRect�����汾�������������ִ�С�ھ��ο��ڲ�
			qDebug() << "current file name is : " << (*iter)->getClipResName();
			//����ֱ�ߺ�ͼƬ
			drawMediaRect(painter, recArea, iter);
			painter.drawText(QRect(pos.x(), (iLevelIndex - 1) * m_firstDistance, (*iter)->getClipWidth(), recArea.height()), Qt::AlignVCenter | Qt::AlignLeft, (*iter)->getClipResName());
		}
		else
		{
			recArea = QRect(pos.x(), 0, iMovieRecWidth, m_Distance);
			//����ֱ�ߺ�ͼƬ
			drawMediaRect(painter, recArea, iter);
		}
	}
	if (m_currentDragClip != nullptr)
	{
		//painter.drawRect(m_currentDragClip->getPixMapRec());
		//painter.fillRect(m_currentDragClip->getPixMapRec(), Qt::gray);
	}
	painter.restore();
}

void ResourceStackView::drawMediaRect(QPainter &painter, QRect &recArea, QMap<int, DragClip*>::iterator iter)
{
	painter.save();
	QPen pen;
	pen.setColor(Qt::black);
	pen.setStyle(Qt::SolidLine);
	painter.setPen(pen);
	QBrush brush;
	brush.setColor(Qt::gray);
	painter.setBrush(brush);
	painter.drawRect(recArea);
	qDebug() << "current pos is :" << "(" << (recArea.x()) << "," << recArea.y() << ")";
	painter.drawPixmap(recArea, *(*iter)->getPixMap());
	painter.restore();
}

void ResourceStackView::dropEvent(QDropEvent* event)
{
	//���϶��Ŀ�ĳ�ʼλ��Ϊdropʱ���λ��
	m_currentDragClip->SetPos(event->pos());
	m_currentDragClip->setPosF(event->pos());
	m_currentDragClip->setStackYPos(getYPosInStack(event->pos()));
	m_currentDragClip->setPixMapRect(QRect(event->pos().x(), getYPosInStack(event->pos()), m_currentDragClip->getClipWidth(), m_currentDragClip->getClipHeight()));
	int iCurrentStackIndex = getCurrentStackIndex(event->pos(), getHeadType(m_currentDragClip->getResourceName()));
	m_currentDragClip->setCurrentStackIndex(iCurrentStackIndex);
	emit signalAddClipTimeline(m_NewTimeline, event->pos());
	m_AllClipInfo.insertMulti(iCurrentStackIndex, m_currentDragClip);
	//��ȡ��ǰ��clip����ʼλ��
	m_SpinLinePos = event->pos();
	QPoint handlerPos = m_SpinLinePos;
	//����������
	handlerPos.setX(m_SpinLinePos.x() - m_OffsetLen);
	m_currentDragClip = nullptr;
	emit frameHanlerChange(handlerPos);
	update();
}

void ResourceStackView::dragEnterEvent(QDragEnterEvent *event)
{
	const QMimeData* data = event->mimeData();
	QString strFilePath = data->property("ResourceView_FilePath").toString();
	QString strFileName = data->property("ResourceView_FileName").toString();
	if (!strFilePath.isEmpty() && !strFileName.isEmpty())
	{
		//��ӵ��ܵ�timeline
		NLEComPtr<INLETimelineBase> ptimeline;
		m_currentDragClip = new DragClip;
		ptimeline = NLEWraper::GetInstance().GetPlayerMaterProvider()->CreateMediaTimeline(strFilePath);
		m_NewTimeline = new NLETimeline(ptimeline);
		//��ȡ��Ƶ��֡��
		int iFrameNum = m_NewTimeline->GetTotalLength();
		float iRecWidth = m_Ruler->getPosFromFrameNum(iFrameNum);
		//���ǵ�ǰ�������Ƶ��fps����ʱ�����ϵ�fps��25.00����һ��һ�£�������Ҫ��ת��
		float fCurrentMovieFps = m_NewTimeline->GetSourceFramerate();
		iRecWidth = iRecWidth * DEFAULT_PLAY_FPS / fCurrentMovieFps;
		qDebug() << "***** Movie total frame number  : " << iFrameNum << "*****";
		qDebug() << "***** Movie Rect width is : " << iRecWidth << "*****";
		m_currentDragClip->setClipWidth(iRecWidth);
		m_currentDragClip->setClipResName(strFileName);
		m_currentDragClip->setFilePath(strFilePath);
		m_currentDragClip->setMediaType(getMediaType(strFileName));
		m_currentDragClip->setTimeline(m_NewTimeline);
		event->acceptProposedAction();
	}
	else
	{
		event->ignore();
	}
}

void ResourceStackView::dragMoveEvent(QDragMoveEvent * event)
{
	if (canDrag(event->pos()))
	{
		//�϶����λ���֮ǰ������⣬�ж��Ƿ�����ڵ�ǰ�������ƶ�
		QRect currentClipRec = m_currentDragClip->getPixMapRec();
		QRect newRec = QRect(event->pos().x(), currentClipRec.y(), currentClipRec.width(), currentClipRec.height());
		m_currentDragClip->setPixMapRect(newRec);
		update();
		event->setDropAction(Qt::CopyAction);
		event->accept();
	}
	else
	{
		event->ignore();
		event->accept();
	}
}

//ʵ�ֶ����еľ��ο���ϷŲ���
void ResourceStackView::mouseMoveEvent(QMouseEvent * event)
{
	if (m_bIsleftMousePress && m_currentDragClip != nullptr)
	{
		//��ȡ��ǰ���Ϸŵľ��ο��left��ֵ
		int iLeftValue = m_currentDragClip->getPixMapRec().x();
		QPoint pos(iLeftValue, 0);
		if (canDrag(pos))		
		{
			if (!isRecCollision(m_currentDragClip))
			{
				//��ȡ�ƶ��ľ���
				QPoint posDistance = event->pos() - m_PressPoint;
				qDebug() << "the press point  is : " << "(" << m_PressPoint.x() << "," << m_PressPoint.y() << ")";
				qDebug() << "the move distance is : " << posDistance.x();
				int iCurrentXpos = m_PressRecLocate.x();
				qDebug() << "after move the X pos is : " << iCurrentXpos + posDistance.x();
				QRect rec;
				//������߽�
				if (iCurrentXpos + posDistance.x() >= m_OffsetLen)
				{
					rec = QRect(iCurrentXpos + posDistance.x(), m_currentDragClip->getPixMapRec().y(), m_currentDragClip->getPixMapRec().width(), m_currentDragClip->getPixMapRec().height());
				}
				else
				{
					rec = QRect(m_OffsetLen, m_currentDragClip->getPixMapRec().y(), m_currentDragClip->getPixMapRec().width(), m_currentDragClip->getPixMapRec().height());
				}
				//�����ұ߽�
				if (iCurrentXpos + posDistance.x() >= width() - 15)
				{
					rec.setX(width() - 15);
				}
				m_currentDragClip->setPixMapRect(rec);
			}
			else
			{
				//���������ײ����������ײ���ڹ��
				reSetStackList();
			}
		}
		update();
	}
	if (isMousePosNearToRect(event->pos()) || m_bIsSplitting)
	{
		setCursor(Qt::SplitHCursor);
		//�����ʱ����trim ���������ƶ��Ĺ����н���seek����
		//ע�����߽���
		if (m_bIsSplitting && canTrimToPos(m_currentDragClip,event->pos()))
		{
			QPointF point(event->pos().x() - 55.00, event->pos().y());
			emit frameLineChange(event->pos());
			emit frameHanlerChange(point);
			//seek����
			int iCurrentFrame = m_Ruler->getFrameNumFromPos(point.x());
			emit signalSeekToFrame(iCurrentFrame);
		}	
	}
	else
	{
		setCursor(Qt::ArrowCursor);
		m_bIsTouchleftline = false;
		m_bIsTouchRightline = false;
	}
	QWidget::mouseMoveEvent(event);
}

//��갴�µ���Ϣ
void ResourceStackView::mousePressEvent(QMouseEvent *event)
{
	if (event->buttons() | Qt::LeftButton)
	{
		//���浱ǰ�û�������갴��ʱ���λ��
		m_PressPoint = event->pos();
		if (m_bIsTouchleftline || m_bIsTouchRightline)
		{
			m_bIsSplitting = true;
		}
		else
		{
			QMap<int, DragClip*>::iterator iter = m_AllClipInfo.begin();
			//�û���ǰ�����λ���Ƿ����κ�һ��rect�н���
			bool bIsClickRect = false;
			for (; iter != m_AllClipInfo.end(); ++iter)
			{
				QRect recTmp = (*iter)->getPixMapRec();
				if (recTmp.contains(event->pos()))
				{
					bIsClickRect = true;
					m_currentDragClip = *iter;
					m_bIsleftMousePress = true;
					if (QApplication::keyboardModifiers() == Qt::ControlModifier)
					{
						//�ж�ctrl �Ƿ��а��£� ����������ǽ��ж�ѡ������������е�ѡ����
						(*iter)->setClipStateSelected(true);
						m_AllSecletedClips.push_back((*iter));
						m_PressRecLocate = (*iter)->getPixMapRec();
						//��ǰ�����clipΪ���һ��Move�Ĵ���
						m_currentDragClip = *iter;
						qDebug() << "the press X pos is  : " << event->pos().x();
						break;
					}
					else
					{
						unSelectAllClips();
						(*iter)->setClipStateSelected(true);
						m_AllSecletedClips.push_back((*iter));
						m_PressRecLocate = (*iter)->getPixMapRec();
						//��ǰ�����clipΪ���һ��Move�Ĵ���
						m_currentDragClip = *iter;
						qDebug() << "the press X pos is  : " << event->pos().x();
						break;
					}
				}
			}
			if (!bIsClickRect)
			{
				unSelectAllClips();
			}
		}
	}
	QWidget::mousePressEvent(event);
}

//��갴ť�ͷŵĲ�����Ӧ
void ResourceStackView::mouseReleaseEvent(QMouseEvent * event)
{
	if (m_bIsSplitting)
	{
		//�����ʱ����ѡ�е�rect�������࣬���ǽ���split����
		//doClipAction(m_currentDragClip, event->pos());
		//�ı��Ӧ��ʱ����
		doClipAction(m_currentDragClip, event->pos(), m_bIsTouchleftline, m_bIsTouchRightline);
		m_bIsTouchleftline = false;
		m_bIsTouchRightline = false;
		m_bIsSplitting = false;
		return;
	}
	if (event->buttons() | Qt::LeftButton && m_bIsleftMousePress)
	{
		//���ơ�Խ�硱��ʹ���ο�һֱ����stack�����
		//��ȥ15��Ϊ�˸� ǰ���canDrag�������Ʊ߽�һ��
		QPoint newHanlerPos;
		QPoint newFirstFramePos;
		if (event->pos().x() >= m_OffsetLen && event->pos().x() <= width() - 15)
		{
			//������Χ
			//����ɿ���ʱ��handler�����ƶ�
			newHanlerPos = event->pos();
			newFirstFramePos = newHanlerPos;
			newHanlerPos.setX(newHanlerPos.x() - m_OffsetLen);
			qDebug() << "***** current drag pos is " << "(" << newHanlerPos.x() << "," << newHanlerPos.y() << ") *****";
		}
		else if (event->pos().x() < m_OffsetLen)
		{
			//��߽�Խ��
			newHanlerPos = QPoint(m_OffsetLen, 0);
			newFirstFramePos = newHanlerPos;
			newHanlerPos.setX(newHanlerPos.x() - m_OffsetLen);
		}
		else if (event->pos().x() > width() - 15)
		{
			//�ұ߽�Խ��
			newHanlerPos = QPoint(width() - 15, 0);
			newFirstFramePos = newHanlerPos;
			newHanlerPos.setX(newHanlerPos.x() - m_OffsetLen);
		}
		m_bIsleftMousePress = false;
		newHanlerPos = QPoint(m_currentDragClip->getPixMapRec().x() - 55, m_currentDragClip->getPixMapRec().y());
		newFirstFramePos = QPoint(m_currentDragClip->getPixMapRec().x(), m_currentDragClip->getPixMapRec().y());
		emit frameHanlerChange(newHanlerPos);
		emit frameLineChange(newFirstFramePos);
		//�ƶ����飬���Ĳ�������ɾ�������
		NLETimeline* timeline = m_currentDragClip->getTimeline();
		emit signalRemoveClipTimeline(timeline);
		emit signalAddClipTimeline(timeline, newFirstFramePos);
		m_currentDragClip = nullptr;
	}
	QWidget::mouseReleaseEvent(event);
}

void ResourceStackView::FramePosChange(QPointF point)
{
	m_SpinLinePos = QPoint(point.x(), 0);
	//ͬ��������slider�ؼ�
	//QPoint  ralativeToRulerPoint = QPoint(m_SpinLinePos.x() - 55,m_SpinLinePos.y());
	update();
}

void ResourceStackView::initData()
{
	m_OffsetLen = 55;
	m_firstDistance = 65;
	m_Distance = 40;
	m_initalHeight = 145;
	m_CurrentGridHeight = 145;
	m_currentDragClip = new DragClip;
	m_bIsleftMousePress = false;
	m_SpinLinePos = QPoint(m_OffsetLen, 0);
	m_Ruler = nullptr;
	m_iMovieStackNum = 1;
	m_iEffectStackNum = 1;
	m_iMusicStackNum = 1;
	m_StackList.push_back(TYPE_MOVIE);
	m_StackList.push_back(TYPE_EFFECT);
	m_StackList.push_back(TYPE_MUSIC);
	m_NewTimeline = nullptr;
	m_bIsTouchleftline = false;
	m_bIsTouchRightline = false;
	m_bIsSplitting = false;
}

void ResourceStackView::initConnections()
{
	connect(this, &ResourceStackView::signalButtonClicked, this, [&](int iType)
	{
		//redo��ť
		if (iType == 0)
		{
			m_UndoStack.redo();
		}
		//Undo��ť
		if (iType == 1)
		{
			m_UndoStack.undo();
		}
		//�ü� split����
		if (iType == 2)
		{
			doSplitAction();
		}
		//ɾ������
		if (iType == 3)
		{
			TimelineDeleteCommand* pCommand = new TimelineDeleteCommand(&m_AllSecletedClips, &m_AllClipInfo);
			pCommand->setTimeline(m_ComplexTimeline);
			pCommand->setTimeRuler(m_Ruler);
			connect(pCommand, &TimelineDeleteCommand::signalUpdateView, this, [&](){
				update();
			});
			m_UndoStack.push(static_cast<TimelineCommandBase*>(pCommand));
		}
		//crop����
		if (iType == 4)
		{
			QMessageBox* box = new QMessageBox;
			box->setText(tr("comming soon ....."));
			box->show();
		}
	});
}

//����ʱ���ߵ�ͷ��
void ResourceStackView::createHeadPixMap(headType type, int iIndex, QPainter& picPainter)
{
	QPixmap map;
	switch (type)
	{
	case ResourceStackView::TYPE_MOVIE:
	{
		map.load(":/images/images/normal/TimelineView_Header_Video_n.png");
		break;
	}
	case ResourceStackView::TYPE_EFFECT:
	{
		map.load(":/images/images/normal/TimelineView_Header_Effect_n.png");
		break;
	}
	case ResourceStackView::TYPE_MUSIC:
	{
		map.load(":/images/images/normal/TimelineView_Header_Audio_n.png");
		break;
	}
	default:
	{
		map.load(":/images/images/normal/TimelineView_Header_Video_n.png");
		break;
	}
	}

	//�����������λ��
	QPoint point;
	int y = 0;
	if (iIndex <= m_iMovieStackNum)
	{
		y = iIndex * m_firstDistance - m_firstDistance / 2 - map.height() / 2;
	}
	else
	{
		y = m_iMovieStackNum * m_firstDistance + (iIndex - m_iMovieStackNum)* m_Distance - m_Distance / 2 - map.height() / 2;
	}
	point.setY(y);
	point.setX(m_OffsetLen / 2 - map.width() / 2);
	picPainter.drawPixmap(point.x(), point.y(), map.width(), map.height(), map);
}

//�жϵ�ǰ�ƶ��Ƿ���Ա�ִ�У����߽���
bool ResourceStackView::canDrag(QPoint newPos)
{
	//��ȥ15��Ŀ����Ϊ������Ԥ��������������û�����rec
	int iCurrentRectXpos = m_currentDragClip->getPixMapRec().x();
	if (iCurrentRectXpos >= m_OffsetLen &&  iCurrentRectXpos <= width() - 15)
	{
		return true;
	}
	return false;
}

//������������ʱû��ʹ��
int ResourceStackView::getYPosInStack(QPoint pos)
{
	return 0;
}

//��ȡ��ǰ�Ķ�ý����Դ����
FilmoraMediaType ResourceStackView::getMediaType(QString strFileName)
{
	QString strSuffix = FileOperation::GetFileSuffixName(strFileName).toLower();
	if (TypeFilter[Type_Video][1].contains(strSuffix)) return FilmoraMediaType::Type_Video;
	if (TypeFilter[Type_Audio][1].contains(strSuffix)) return FilmoraMediaType::Type_Audio;
	if (TypeFilter[Type_Image][1].contains(strSuffix)) return FilmoraMediaType::Type_Image;
	return FilmoraMediaType::Type_Unknow;
}

ResourceStackView::headType ResourceStackView::getHeadType(QString strFileName)
{
	if (getMediaType(strFileName) == FilmoraMediaType::Type_Unknow)
	{
		return TYPE_EFFECT;
	}
	else if (getMediaType(strFileName) == FilmoraMediaType::Type_Video)
	{
		return TYPE_MOVIE;
	}
	else if (getMediaType(strFileName) == FilmoraMediaType::Type_Audio)
	{
		return TYPE_MUSIC;
	}
}

ResourceStackView::headType ResourceStackView::getHeadTypeByMediaType(FilmoraMediaType type)
{
	switch (type)
	{
	case Type_Video:
	case Type_Image:
	{
		return TYPE_MOVIE;
	}
	case Type_Audio:
	{
		return TYPE_MUSIC;
	}
	case Type_Unknow:
	{
		return TYPE_EFFECT;
	}
	default:
		return TYPE_EFFECT;
	}
}

int ResourceStackView::getCurrentStackIndex(QPoint point, headType stacktype)
{
	int iIndex = -1;
	if (stacktype == TYPE_MOVIE)
	{
		iIndex = point.y() / m_firstDistance + 1;
	}
	if (stacktype == TYPE_EFFECT)
	{
		iIndex = m_iMovieStackNum + (point.y() - m_iMovieStackNum * m_firstDistance) / m_Distance + 1;
	}
	if (stacktype == TYPE_MUSIC)
	{
		iIndex = m_iMovieStackNum + m_iEffectStackNum + (point.y() - m_iMovieStackNum * m_firstDistance - m_iEffectStackNum * m_Distance) / m_Distance + 1;
	}
	if (stacktype == Type_Unknow)
	{
		//do nothing
	}
	return iIndex;
}

void ResourceStackView::reSetStackList()
{
	int iCurrentIndex = m_currentDragClip->getCurrentStackIndex();
	QList<DragClip*> nextValue;
	QList<DragClip*> currentValue;
	currentValue = m_AllClipInfo.values(iCurrentIndex);
	nextValue = m_AllClipInfo.values(iCurrentIndex + 1);
	QMap<int, DragClip*> rectMap = m_AllClipInfo;
	//�����������stack�Ĳ���
	m_AllClipInfo.clear();
	//ɾ����ǰrect
	currentValue.removeOne(m_currentDragClip);
	//��ײ�ᵼ��������stack��Ӱ�죬���Բ���Ҫ��עǰ���stack
	QMap<int, DragClip*>::iterator iter = rectMap.begin();
	int iLevel = -1;
	for (; iter != rectMap.end(); ++iter)
	{
		//��ǰlevel֮ǰ��stackֱ��copy
		iLevel = (*iter)->getCurrentStackIndex();
		if (iLevel < iCurrentIndex)
		{
			m_AllClipInfo.insertMulti(iLevel, *iter);
			(*iter)->setCurrentStackIndex(iLevel);
		}
		else if (iLevel == iCurrentIndex)
		{
			if (m_currentDragClip != *iter)
			{
				m_AllClipInfo.insertMulti(iLevel, m_currentDragClip);
				m_currentDragClip->setCurrentStackIndex(iLevel);
				QList<DragClip*>::iterator iterTmp = currentValue.begin();
				//��Ϊinsert�����Ǵ�0��ʼ���� ���� ����λ��Ϊ iCurrentIndex
				m_StackList.insert(iCurrentIndex, getHeadTypeByMediaType((*iterTmp)->getMediaType()));
				//��Ҫ�ı䲻ͬ������͵���Ŀ
				changeStackNum(getHeadTypeByMediaType((*iterTmp)->getMediaType()));
				(*iter)->resetStackInfo(iLevel, m_iMovieStackNum);
				for (; iterTmp != currentValue.end(); ++iterTmp)
				{
					//�����Ż������µ�stack�ϲ���clip
					m_AllClipInfo.insertMulti(iLevel + 1, *iterTmp);
					(*iterTmp)->setCurrentStackIndex(iLevel + 1);
					(*iter)->resetStackInfo(iLevel + 1, m_iMovieStackNum);
				}
			}
		}
		else
		{
			m_AllClipInfo.insertMulti(iLevel + 1, *iter);
			(*iter)->setCurrentStackIndex(iLevel + 1);
			(*iter)->resetStackInfo(iLevel + 1, m_iMovieStackNum);
		}
	}
}

bool ResourceStackView::isRecCollision(DragClip* m_currentDragClip)
{
	int iCurrentIndex = m_currentDragClip->getCurrentStackIndex();
	QList<DragClip*> sameLevelClips = m_AllClipInfo.values(iCurrentIndex);
	QList<DragClip*>::iterator iter = sameLevelClips.begin();
	for (; iter != sameLevelClips.end(); ++iter)
	{
		if (*iter == m_currentDragClip)
		{
			continue;
		}
		if ((*iter)->getPixMapRec().intersects(m_currentDragClip->getPixMapRec()))
		{
			return true;
		}
	}
	return false;
}

void ResourceStackView::changeStackNum(headType type)
{
	switch (type)
	{
	case ResourceStackView::TYPE_MOVIE:
	{
		m_iMovieStackNum++;
		//���������Ҫ�ı�ʱ�����ܿռ�ĸ߶�
		m_initalHeight += m_firstDistance;
		break;
	}
	case ResourceStackView::TYPE_EFFECT:
	{
		m_initalHeight += m_Distance;
		m_iEffectStackNum++;
		break;
	}
	case ResourceStackView::TYPE_MUSIC:
	{
		m_initalHeight += m_Distance;
		m_iMusicStackNum++;
		break;
	}
	default:
		break;
	}
}

void ResourceStackView::unSelectAllClips()
{
	QMap<int, DragClip*>::iterator iter = m_AllClipInfo.begin();
	for (; iter != m_AllClipInfo.end(); ++iter)
	{
		(*iter)->setClipStateSelected(false);
	}
	m_AllSecletedClips.clear();
}

bool ResourceStackView::isMousePosNearToRect(QPoint pos)
{
	//������:  �����ǰ������y������ѡ��rect�����ڣ�����x������� rect.left ����rect.right
	//���ʱ��Ϊ��ǰ���λ����������������true ���򷵻�false
	bool bRect = false;
	QVector<DragClip*>::iterator iter = m_AllSecletedClips.begin();
	for (; iter != m_AllSecletedClips.end(); ++iter)
	{
		QRect rect = (*iter)->getPixMapRec();
		// ��6 ��6 ��Ϊ��������һ�������ز�ڿ�������ġ���Χ�������˵Ĳ���
		if (rect.contains(pos))
		{
			if ((pos.x() <= rect.left() + 3))
			{
				m_bIsTouchleftline = true;
				m_currentDragClip = *iter;
				return true;
			}
			if (pos.x() >= rect.right() - 3)
			{
				m_bIsTouchRightline = true;
				m_currentDragClip = *iter;
				return true;
			}
		}
	}
	return bRect;
}

void ResourceStackView::doClipAction(DragClip* clip, QPoint clipPos, bool bIsTouchLeft, bool bIsTouchRight)
{
	//push ֮ǰ�������źţ���ΪQundoStack �����޷��������ͨ��
	TimelineTrimCommand* pCommand = new TimelineTrimCommand(clipPos, clip, bIsTouchLeft, bIsTouchRight);
	pCommand->setTimeRuler(m_Ruler);
	pCommand->setTimeline(m_ComplexTimeline);
	connect(pCommand, &TimelineTrimCommand::signalUpdateView, this, [&](){
		repaint(); 
		qDebug() << "update window";
	});
	//connect(pCommand, &TimelineTrimCommand::signalUpdateView, this, [&](){ repaint(); });
	connect(pCommand, &TimelineTrimCommand::signalMoveHandler, this, &ResourceStackView::frameHanlerChange);
	connect(pCommand, &TimelineTrimCommand::signalMoveFrameline, this, &ResourceStackView::frameLineChange);
	m_UndoStack.push(pCommand);
}

int ResourceStackView::getFrameFromPos(QPointF pos)
{
	//����ת��
	int iFrame = 0;
	iFrame = m_Ruler->getFrameNumFromPos(pos.x() - 55.00);
	return iFrame;
}

bool ResourceStackView::canTrimToPos(DragClip* clip, QPoint pos)
{
	QRect rec = clip->getPixMapRec();
	return rec.contains(pos);
}
