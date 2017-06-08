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

//拖动资源时，在对应的一个轨道上应该绘制的图片矩形框的左上角Y的坐标
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

//设置当前使用的事件线控件
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
	//目前仅支持单选处理
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
	//绘制轨道
	QVector<headType>::iterator stackIter = m_StackList.begin();
	for (stackIter; stackIter != m_StackList.end(); ++stackIter)
	{
		//轨道数目是从1开始计数，所以需要加上1
		int iIndex = stackIter - m_StackList.begin() + 1;
		if (iIndex <= m_iMovieStackNum)
		{
			//绘制视频轨道
			painter.drawLine(0, m_firstDistance * iIndex, width(), m_firstDistance * iIndex);
			createHeadPixMap(TYPE_MOVIE, iIndex, painter);
		}
		if (iIndex > m_iMovieStackNum && iIndex <= m_iMovieStackNum + m_iEffectStackNum)
		{
			//绘制effect轨道
			int iCurrentStackDistance = m_firstDistance * m_iMovieStackNum + m_iEffectStackNum * m_Distance;
			painter.drawLine(0, iCurrentStackDistance, width(), iCurrentStackDistance);
			createHeadPixMap(TYPE_EFFECT, iIndex, painter);
		}
		if (iIndex > m_iMovieStackNum + m_iEffectStackNum && iIndex <= m_iMovieStackNum + m_iEffectStackNum + m_iMusicStackNum)
		{
			//绘制music 轨道
			int iMovieStackDistance = m_firstDistance * m_iMovieStackNum + (m_iEffectStackNum + m_iMusicStackNum) * m_Distance;
			painter.drawLine(0, iMovieStackDistance, width(), iMovieStackDistance);
			createHeadPixMap(TYPE_EFFECT, iIndex, painter);
		}
	}
	//绘制游标
	painter.drawLine(m_SpinLinePos.x(), 0, m_SpinLinePos.x(), m_initalHeight);
	//绘制clip
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
			//绘制视频的文件名信息   --使用drawText QRect参数版本，可以限制文字大小在矩形框内部
			qDebug() << "current file name is : " << (*iter)->getClipResName();
			//绘制直线和图片
			drawMediaRect(painter, recArea, iter);
			painter.drawText(QRect(pos.x(), (iLevelIndex - 1) * m_firstDistance, (*iter)->getClipWidth(), recArea.height()), Qt::AlignVCenter | Qt::AlignLeft, (*iter)->getClipResName());
		}
		else
		{
			recArea = QRect(pos.x(), 0, iMovieRecWidth, m_Distance);
			//绘制直线和图片
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
	//可拖动的块的初始位置为drop时候的位置
	m_currentDragClip->SetPos(event->pos());
	m_currentDragClip->setPosF(event->pos());
	m_currentDragClip->setStackYPos(getYPosInStack(event->pos()));
	m_currentDragClip->setPixMapRect(QRect(event->pos().x(), getYPosInStack(event->pos()), m_currentDragClip->getClipWidth(), m_currentDragClip->getClipHeight()));
	int iCurrentStackIndex = getCurrentStackIndex(event->pos(), getHeadType(m_currentDragClip->getResourceName()));
	m_currentDragClip->setCurrentStackIndex(iCurrentStackIndex);
	emit signalAddClipTimeline(m_NewTimeline, event->pos());
	m_AllClipInfo.insertMulti(iCurrentStackIndex, m_currentDragClip);
	//获取当前的clip的起始位置
	m_SpinLinePos = event->pos();
	QPoint handlerPos = m_SpinLinePos;
	//做坐标修正
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
		//添加到总的timeline
		NLEComPtr<INLETimelineBase> ptimeline;
		m_currentDragClip = new DragClip;
		ptimeline = NLEWraper::GetInstance().GetPlayerMaterProvider()->CreateMediaTimeline(strFilePath);
		m_NewTimeline = new NLETimeline(ptimeline);
		//获取视频的帧数
		int iFrameNum = m_NewTimeline->GetTotalLength();
		float iRecWidth = m_Ruler->getPosFromFrameNum(iFrameNum);
		//考虑当前导入的视频的fps和总时间线上的fps（25.00）不一定一致，所以需要做转换
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
		//拖动矩形滑块之前先做检测，判断是否可以在当前方向做移动
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

//实现对现有的矩形框的拖放操作
void ResourceStackView::mouseMoveEvent(QMouseEvent * event)
{
	if (m_bIsleftMousePress && m_currentDragClip != nullptr)
	{
		//获取当前被拖放的矩形框的left的值
		int iLeftValue = m_currentDragClip->getPixMapRec().x();
		QPoint pos(iLeftValue, 0);
		if (canDrag(pos))		
		{
			if (!isRecCollision(m_currentDragClip))
			{
				//获取移动的距离
				QPoint posDistance = event->pos() - m_PressPoint;
				qDebug() << "the press point  is : " << "(" << m_PressPoint.x() << "," << m_PressPoint.y() << ")";
				qDebug() << "the move distance is : " << posDistance.x();
				int iCurrentXpos = m_PressRecLocate.x();
				qDebug() << "after move the X pos is : " << iCurrentXpos + posDistance.x();
				QRect rec;
				//限制左边界
				if (iCurrentXpos + posDistance.x() >= m_OffsetLen)
				{
					rec = QRect(iCurrentXpos + posDistance.x(), m_currentDragClip->getPixMapRec().y(), m_currentDragClip->getPixMapRec().width(), m_currentDragClip->getPixMapRec().height());
				}
				else
				{
					rec = QRect(m_OffsetLen, m_currentDragClip->getPixMapRec().y(), m_currentDragClip->getPixMapRec().width(), m_currentDragClip->getPixMapRec().height());
				}
				//限制右边界
				if (iCurrentXpos + posDistance.x() >= width() - 15)
				{
					rec.setX(width() - 15);
				}
				m_currentDragClip->setPixMapRect(rec);
			}
			else
			{
				//如果发生碰撞，则重置碰撞所在轨道
				reSetStackList();
			}
		}
		update();
	}
	if (isMousePosNearToRect(event->pos()) || m_bIsSplitting)
	{
		setCursor(Qt::SplitHCursor);
		//如果此时在做trim 操作，则移动的过程中进行seek操作
		//注意做边界检测
		if (m_bIsSplitting && canTrimToPos(m_currentDragClip,event->pos()))
		{
			QPointF point(event->pos().x() - 55.00, event->pos().y());
			emit frameLineChange(event->pos());
			emit frameHanlerChange(point);
			//seek操作
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

//鼠标按下的消息
void ResourceStackView::mousePressEvent(QMouseEvent *event)
{
	if (event->buttons() | Qt::LeftButton)
	{
		//保存当前用户进行鼠标按下时候的位置
		m_PressPoint = event->pos();
		if (m_bIsTouchleftline || m_bIsTouchRightline)
		{
			m_bIsSplitting = true;
		}
		else
		{
			QMap<int, DragClip*>::iterator iter = m_AllClipInfo.begin();
			//用户当前点击的位置是否与任何一个rect有交集
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
						//判断ctrl 是否有按下， 如果按下则是进行多选操作，否则进行单选操作
						(*iter)->setClipStateSelected(true);
						m_AllSecletedClips.push_back((*iter));
						m_PressRecLocate = (*iter)->getPixMapRec();
						//当前处理的clip为最后一个Move的窗口
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
						//当前处理的clip为最后一个Move的窗口
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

//鼠标按钮释放的操作响应
void ResourceStackView::mouseReleaseEvent(QMouseEvent * event)
{
	if (m_bIsSplitting)
	{
		//如果此时是在选中的rect左右两侧，则是进行split操作
		//doClipAction(m_currentDragClip, event->pos());
		//改变对应的时间线
		doClipAction(m_currentDragClip, event->pos(), m_bIsTouchleftline, m_bIsTouchRightline);
		m_bIsTouchleftline = false;
		m_bIsTouchRightline = false;
		m_bIsSplitting = false;
		return;
	}
	if (event->buttons() | Qt::LeftButton && m_bIsleftMousePress)
	{
		//限制“越界”，使矩形框一直处于stack轨道中
		//减去15是为了跟 前面的canDrag方法限制边界一致
		QPoint newHanlerPos;
		QPoint newFirstFramePos;
		if (event->pos().x() >= m_OffsetLen && event->pos().x() <= width() - 15)
		{
			//正常范围
			//鼠标松开的时候，handler跟着移动
			newHanlerPos = event->pos();
			newFirstFramePos = newHanlerPos;
			newHanlerPos.setX(newHanlerPos.x() - m_OffsetLen);
			qDebug() << "***** current drag pos is " << "(" << newHanlerPos.x() << "," << newHanlerPos.y() << ") *****";
		}
		else if (event->pos().x() < m_OffsetLen)
		{
			//左边界越界
			newHanlerPos = QPoint(m_OffsetLen, 0);
			newFirstFramePos = newHanlerPos;
			newHanlerPos.setX(newHanlerPos.x() - m_OffsetLen);
		}
		else if (event->pos().x() > width() - 15)
		{
			//右边界越界
			newHanlerPos = QPoint(width() - 15, 0);
			newFirstFramePos = newHanlerPos;
			newHanlerPos.setX(newHanlerPos.x() - m_OffsetLen);
		}
		m_bIsleftMousePress = false;
		newHanlerPos = QPoint(m_currentDragClip->getPixMapRec().x() - 55, m_currentDragClip->getPixMapRec().y());
		newFirstFramePos = QPoint(m_currentDragClip->getPixMapRec().x(), m_currentDragClip->getPixMapRec().y());
		emit frameHanlerChange(newHanlerPos);
		emit frameLineChange(newFirstFramePos);
		//移动方块，做的操作是先删除后添加
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
	//同步播放器slider控件
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
		//redo按钮
		if (iType == 0)
		{
			m_UndoStack.redo();
		}
		//Undo按钮
		if (iType == 1)
		{
			m_UndoStack.undo();
		}
		//裁剪 split操作
		if (iType == 2)
		{
			doSplitAction();
		}
		//删除操作
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
		//crop操作
		if (iType == 4)
		{
			QMessageBox* box = new QMessageBox;
			box->setText(tr("comming soon ....."));
			box->show();
		}
	});
}

//创建时间线的头部
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

	//根据序号设置位置
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

//判断当前移动是否可以被执行，做边界检测
bool ResourceStackView::canDrag(QPoint newPos)
{
	//减去15的目的是为了至少预留少量的区域给用户操作rec
	int iCurrentRectXpos = m_currentDragClip->getPixMapRec().x();
	if (iCurrentRectXpos >= m_OffsetLen &&  iCurrentRectXpos <= width() - 15)
	{
		return true;
	}
	return false;
}

//废弃方法，暂时没有使用
int ResourceStackView::getYPosInStack(QPoint pos)
{
	return 0;
}

//获取当前的多媒体资源类型
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
	//重置两个标记stack的参数
	m_AllClipInfo.clear();
	//删除当前rect
	currentValue.removeOne(m_currentDragClip);
	//碰撞会导致其后面的stack有影响，所以不需要关注前面的stack
	QMap<int, DragClip*>::iterator iter = rectMap.begin();
	int iLevel = -1;
	for (; iter != rectMap.end(); ++iter)
	{
		//当前level之前的stack直接copy
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
				//因为insert插入是从0开始计数 所以 插入位置为 iCurrentIndex
				m_StackList.insert(iCurrentIndex, getHeadTypeByMediaType((*iterTmp)->getMediaType()));
				//需要改变不同轨道类型的数目
				changeStackNum(getHeadTypeByMediaType((*iterTmp)->getMediaType()));
				(*iter)->resetStackInfo(iLevel, m_iMovieStackNum);
				for (; iterTmp != currentValue.end(); ++iterTmp)
				{
					//自立门户，在新的stack上插入clip
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
		//新增轨道需要改变时间轨道总空间的高度
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
	//规则是:  如果当前的鼠标的y坐标在选中rect区域内，并且x坐标等于 rect.left 或者rect.right
	//则此时认为当前鼠标位置是满足条件返回true 否则返回false
	bool bRect = false;
	QVector<DragClip*>::iterator iter = m_AllSecletedClips.begin();
	for (; iter != m_AllSecletedClips.end(); ++iter)
	{
		QRect rect = (*iter)->getPixMapRec();
		// 加6 减6 是为了允许有一定的像素差，在可以允许的“误差范围”符合人的操作
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
	//push 之前先连接信号，因为QundoStack 我们无法跟其进行通信
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
	//坐标转换
	int iFrame = 0;
	iFrame = m_Ruler->getFrameNumFromPos(pos.x() - 55.00);
	return iFrame;
}

bool ResourceStackView::canTrimToPos(DragClip* clip, QPoint pos)
{
	QRect rec = clip->getPixMapRec();
	return rec.contains(pos);
}
