#include "stdafx.h"
#include <QPainter>
#include "dragclip.h"

DragClip::DragClip(QObject *parent)
	: QObject(parent)
{
	 m_ClipWidth = 0;
	 m_ClipResourceName = "";
	 m_DragPixMap = new QPixmap(TIMELINEVIEW_TRACKITEM_HEIGHT_VIDEO, TIMELINEVIEW_TRACKITEM_HEIGHT_VIDEO);
	 QPainter painter(m_DragPixMap);
	 painter.fillRect(QRect(QPoint(0, 0), m_DragPixMap->size()), QColor(196, 196, 196));
	 m_PixMapRec = QRect(-100, 0, 1, 1);
}

DragClip::~DragClip()
{

}

void DragClip::SetPos(QPoint& pos)
{
	m_StayPos = pos;
}

void DragClip::setClipWidth(int iWidth)
{
	m_ClipWidth = iWidth;
}

void DragClip::setClipResName(QString strName)
{
	m_ClipResourceName = strName;
}

void DragClip::setDragPixmap(QPixmap* map /*= nullptr*/)
{
	if (map == nullptr)
	{
		//初始化已经赋值了
	}
	else
	{
        
	}
}

void DragClip::setPixMapRect(QRect rec)
{
	m_PixMapRec = rec;
}
