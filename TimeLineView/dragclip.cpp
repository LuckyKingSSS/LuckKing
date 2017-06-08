#include "stdafx.h"
#include <QPainter>
#include "dragclip.h"


DragClip::DragClip(QObject *parent)
	: QObject(parent)
{
	initData();
}

DragClip::~DragClip()
{

}

void DragClip::initData()
{
	m_ClipWidth = 0;
	m_ClipResourceName = "";
	m_DragPixMap = new QPixmap(TIMELINEVIEW_TRACKITEM_HEIGHT_VIDEO, TIMELINEVIEW_TRACKITEM_HEIGHT_VIDEO);
	QPainter painter(m_DragPixMap);
	painter.fillRect(QRect(QPoint(0, 0), m_DragPixMap->size()), QColor(196, 196, 196));
	m_PixMapRec = QRect(-100, 0, 1, 1);
	m_StackStartYPos = 0;
	m_CurrentMediaType = Type_Unknow;
	m_iCurrentStackIndex = 0;
	m_CurrentTimeline = nullptr;
}

void DragClip::SetPos(QPoint pos)
{
	m_StayPos = pos;
}

void DragClip::setClipWidth(float fWidth)
{
	m_ClipWidth = fWidth;
	m_PixMapRec.setWidth(fWidth);
}

void DragClip::setClipResName(QString strName)
{
	m_ClipResourceName = strName;
}

void DragClip::setDragPixmap(QPixmap* map /*= nullptr*/)
{
	if (map == nullptr)
	{
		//��ʼ���Ѿ���ֵ��
	}
	else
	{
        
	}
}

void DragClip::setPixMapRect(QRect rec)
{
	m_PixMapRec = rec;
	//ǰ��û����ƺã��ڴ���ͬ��������Ա����
	m_StackStartYPos = rec.y();
	m_StayPos = QPoint(rec.x(),rec.y());
}

void DragClip::setMediaType(FilmoraMediaType type)
{
	m_CurrentMediaType = type;
}

void DragClip::setStackYPos(int pos)
{
	m_StackStartYPos = pos;
}

DragClip* DragClip::clone()
{
	DragClip* newClip = new DragClip();
	//ͬ����Ҫ�Ĳ���
	newClip->SetPos(this->getPos());
	newClip->setPosF(this->getPosF());
	newClip->setClipWidth(this->getClipWidth());
	newClip->setClipResName(this->getClipResName());
	newClip->setDragPixmap(m_DragPixMap);
	newClip->setPixMapRect(this->getPixMapRec());
	newClip->setMediaType(this->getMediaType());
	newClip->setCurrentStackIndex(this->getCurrentStackIndex());
	newClip->setClipStateSelected(m_bIsSelected);
	newClip->setFilePath(m_StrFilePath);
	//ע��tineline������Ҫclone ����Ӱ�������ĸ���
	newClip->setTimeline(this->getTimeline()->Clone());
	newClip->setCurrentLevel(m_iLevel);	
	return newClip;
}

int DragClip::getClipHeight()
{
	switch (m_CurrentMediaType)
	{
	case Type_Video:
	case Type_Audio:
	case Type_Image:
	{
		return TIMELINEVIEW_TRACKITEM_HEIGHT_VIDEO;
	}
	case Type_Unknow:
	{
		return TIMELINEVIEW_TRACKITEM_HEIGHT_EFFECT;
	}
	}
}

void DragClip::resetStackInfo(int iCurrentStackIndex, int iVedioStackNum)
{
	m_iCurrentStackIndex = iCurrentStackIndex;
	if (m_CurrentMediaType == Type_Video || m_CurrentMediaType == Type_Image)
	{
		int yPos = TIMELINEVIEW_TRACKITEM_HEIGHT_VIDEO * (iCurrentStackIndex - 1);
		m_PixMapRec.setY(yPos);
		m_PixMapRec.setHeight(TIMELINEVIEW_TRACKITEM_HEIGHT_VIDEO);
		m_StackStartYPos = yPos;
	}
	else
	{
		int yPos = TIMELINEVIEW_TRACKITEM_HEIGHT_VIDEO * iVedioStackNum;
		yPos += (iCurrentStackIndex - iVedioStackNum - 1)* TIMELINEVIEW_TRACKITEM_HEIGHT_EFFECT;
		m_PixMapRec.setHeight(TIMELINEVIEW_TRACKITEM_HEIGHT_EFFECT);
		m_PixMapRec.setY(yPos);
	}
}
