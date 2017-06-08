#include "stdafx.h"
#include <QPainter>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDragMoveEvent>
#include <QDrag>
#include <QtDebug>
#include "resourcestackview.h"
#include "dragclip.h"
#include "timeruler.h"

class NLETimeline;
ResourceStackView::ResourceStackView(QWidget *parent)
	: QWidget(parent)
{
	initData();
	initConnections();
	this->resize(800, m_initalHeight);
	setAcceptDrops(true);
	this->setMouseTracking(false);
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

void ResourceStackView::resizeEvent(QResizeEvent* event)
{

}

void ResourceStackView::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QPen pen(Qt::SolidLine | Qt::black);
	painter.setPen(pen);
	painter.drawLine(0, m_firstDistance, width(), m_firstDistance);
	//����ʱ���ߵ�ͷ
	createHeadPixMap(TYPE_MOVIE, 0, painter);
	painter.drawLine(0, m_firstDistance + m_Distance + 1, width(), m_firstDistance + m_Distance + 1);
	createHeadPixMap(TYPE_EFFECT, 1, painter);
	painter.drawLine(0, m_firstDistance + 2 * (m_Distance + 1), width(), m_firstDistance + 2 * (m_Distance + 1));
	createHeadPixMap(TYPE_MUSIC, 2, painter);
	//����spinLine��λ��
	painter.drawLine(m_SpinLinePos.x(), 0, m_SpinLinePos.x(), m_initalHeight);
	//����clip
	QList<DragClip*>::iterator iter = m_AllClipInfo.begin();
	for (; iter != m_AllClipInfo.end();++iter)
    {
		QPoint pos =  (*iter)->getpos();
		QRect recArea = (*iter)->getPixMapRec();
		//����ֱ�ߺ�ͼƬ
		QPen pen;
		pen.setColor(Qt::black);
		pen.setStyle(Qt::SolidLine);
		painter.setPen(pen);
		QBrush brush;
		brush.setColor(Qt::gray);
		painter.setBrush(brush);
		painter.drawLine(recArea.x(), 0, recArea.x(), m_CurrentGridHeight);
		int iBoxWidth = (*iter)->getClipWidth();
		painter.drawRect(recArea);
		qDebug() << "current pos is :" << "(" << (recArea.x()) << "," << recArea.y() << ")";
		painter.drawPixmap((*iter)->getPixMapRec().x(), (*iter)->getPixMapRec().y(), (*iter)->getPixMapRec().width(), (*iter)->getPixMapRec().height(), *(*iter)->getPixMap());
		//������Ƶ���ļ�����Ϣ
		painter.drawText(pos.x() + 10, 0 + 10, (*iter)->getClipResName());
		//���Ƶ�ǰ�϶��ľ�������
    }
	if (m_currentDragClip != nullptr)
	{
		painter.drawRect(m_currentDragClip->getPixMapRec());
		painter.fillRect(m_currentDragClip->getPixMapRec(), Qt::gray);
	}	
}

void ResourceStackView::dropEvent(QDropEvent* event)
{
	m_AllClipInfo.push_back(m_currentDragClip);
	m_currentDragClip = nullptr;
	update();
}

void ResourceStackView::dragEnterEvent(QDragEnterEvent *event)
{
	if ( event->mimeData()->hasFormat("MatterView_TimelineItem") || event->mimeData()->hasFormat("TimelineView_ClipBase"))
	{
		auto mimeData = event->mimeData();
		DragClip* dragClip = new DragClip;
		if (event->mimeData()->hasFormat("MatterView_TimelineItem"))
		{
            //��ȡʱ����
			NLETimeline * timeline = reinterpret_cast<NLETimeline*>(mimeData->property("MatterView_TimelineItem").value<qptrdiff>());
			auto resourceType = mimeData->property("MatterType").toInt();
			auto duration = mimeData->property("Duration").toInt();
			m_Ruler->getPosFromFrameNum(duration);
			dragClip->setClipWidth(duration);
			dragClip->setClipWidth(50);
			int xPos = (event->pos().x() > m_OffsetLen) ? event->pos().x() : m_OffsetLen;
			QPoint pos(xPos, getDrapLipeTopPos(event->pos()));
			qDebug() << "current pos is :" << "(" << (event->pos().x()) << "," << event->pos().y()<<")";
			qDebug() << "current rec top pos is :" << "(" << (pos.x()) << "," << pos.y() << ")";
			dragClip->SetPos(pos);
			QRect recTmp(pos.x(), pos.y(),50, m_firstDistance);
			dragClip->setPixMapRect(recTmp);
			m_currentDragClip = dragClip;
			//m_AllClipInfo.push_back(dragClip);
		}
		event->acceptProposedAction();
		update();
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
	}
}

//ʵ�ֶ����еľ��ο���ϷŲ���
void ResourceStackView::mouseMoveEvent(QMouseEvent * event)
{
	if (m_bIsleftMousePress && m_currentDragClip != nullptr)
	{
		if (canDrag(event->pos()))
		{
			QRect rec(event->pos().x(), m_currentDragClip->getPixMapRec().y(), m_currentDragClip->getPixMapRec().width(), m_currentDragClip->getPixMapRec().height());
			m_currentDragClip->setPixMapRect(rec);
		}
		update();
	}
}

//��갴�µ���Ϣ
void ResourceStackView::mousePressEvent(QMouseEvent *event)
{
	if (event->buttons() | Qt::LeftButton)
    {
		m_bIsleftMousePress = true;
		QList<DragClip*>::iterator iter = m_AllClipInfo.begin();
		for (; iter != m_AllClipInfo.end(); ++iter)
		{
			QRect recTmp = (*iter)->getPixMapRec();
			if (recTmp.contains(event->pos()))
			{
				m_currentDragClip = *iter;
				break;
			}
		}
    }
}

//��갴ť�ͷŵĲ�����Ӧ
void ResourceStackView::mouseReleaseEvent(QMouseEvent * event)
{
	if (event->buttons() | Qt::LeftButton)
	{
		m_bIsleftMousePress = false;
		m_currentDragClip = nullptr;
	}
}


void ResourceStackView::FramePosChange(QPoint point)
{
	m_SpinLinePos = QPoint(point.x() + m_OffsetLen + 3,0);
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
	m_SpinLinePos = QPoint(m_OffsetLen,0);
}

void ResourceStackView::initConnections()
{
	
}

//����ʱ���ߵ�ͷ��
void ResourceStackView::createHeadPixMap(headType type, int iIndex,QPainter& picPainter)
{
	QPixmap map;
	switch (type)
	{
	case ResourceStackView::TYPE_MOVIE:
	{
		map.load(":/drag/Resources/normal/TimelineView_Header_Video_n.png");
		break;
	}		
	case ResourceStackView::TYPE_EFFECT:
	{
		map.load(":/drag/Resources/normal/TimelineView_Header_Effect_n.png");
		break;
	}
	case ResourceStackView::TYPE_MUSIC:
	{
		map.load(":/drag/Resources/normal/TimelineView_Header_Audio_n.png");
		break;
	}
	default:
	{
		map.load(":/drag/Resources/normal/TimelineView_Header_Video_n.png");
		break;
	}	
	}

	//�����������λ��
	//QPainter painter;
	QPoint point;
	int y = 0;
	if (iIndex == 0)
	{
		y = m_firstDistance / 2;
	}
	else
	{
		y = m_firstDistance + m_Distance*(iIndex - 0.5) - map.height()/2;
	}
	point.setY(y);
	point.setX(m_OffsetLen / 2 - map.width()/2 );
	picPainter.drawPixmap(point.x(), point.y(), map.width(), map.height(), map);
}


//�жϵ�ǰ�ƶ��Ƿ���Ա�ִ�У����߽���
bool ResourceStackView::canDrag(QPoint newPos)
{
	if (newPos.x() >= m_OffsetLen &&  newPos.x()<= width()- m_currentDragClip->getClipWidth())
	{
		return true;
	}
	return false;
}
