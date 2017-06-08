#include "stdafx.h"
#include <QPainter>
#include <QMouseEvent>
#include "timeruler.h"


#define FONT_WIDTH 70    //�̶ȳ��ϵ����ֿ�ȴ�С
TimeRuler::TimeRuler(QWidget *parent)
	: QWidget(parent)
{
	initData();
	drawRuler();
	
}

TimeRuler::~TimeRuler()
{

}

void TimeRuler::resizeEvent(QResizeEvent * event)
{
	initData();
	drawRuler();
}

void TimeRuler::paintEvent(QPaintEvent *event)
{
	drawRuler();
}

int TimeRuler::getFrameNumFromPos(int iPos)
{
	return iPos / m_iStep * m_iOneStepFrames;
}

void TimeRuler::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bIsPressLeftMouse = true;
		m_PressPoint = event->pos();
		if (m_CurrentHandlerPos.contains(event->pos()))
		{
			m_bIsClickHandler = true;
		}
	}
	QWidget::mousePressEvent(event);
}

void TimeRuler::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bIsPressLeftMouse = false;
		m_bIsClickHandler = false;
	}
	QWidget::mouseReleaseEvent(event);
}


void TimeRuler::mouseMoveEvent(QMouseEvent* event)
{
	if (m_bIsPressLeftMouse && m_bIsClickHandler)
	{
		if (canDrag(event->pos()))
		{
			m_CurrentHandlerPos = QRect(event->pos().x(), m_CurrentHandlerPos.y(), m_CurrentHandlerPos.width(), m_CurrentHandlerPos.height());
			emit frameMove(event->pos());
		}
	}else if (m_bIsPressLeftMouse)
	{
		int  moveLen = (event->pos().x()) - (m_PressPoint.x());
		m_iZommSize = moveLen;
		if (m_iZommSize > 130 || m_iZommSize < 0)
		{
			m_iZommSize = m_iZommSize % 130;
		}
		//���ó�Ա����Ϊ�޸ĺ����ֵ
		setData();
	}
	//����û��û������������handler�ڲ��Ļ���ִ��handler���ƶ�����	
	QWidget::mouseMoveEvent(event);
}

//���ƿ̶ȳ�
void TimeRuler::drawRuler()
{
	//��һ���� ����ˮƽ��
	QPainter p(this);
	p.setPen(Qt::SolidLine);
	QPainterPath path;
	QPen pen = p.pen();
	pen.setColor(QColor(61, 65, 69));
	pen.setWidth(1);
	p.setPen(pen);
	p.setBrush(QColor(61, 65, 69));
	p.save();
	
	//���ÿ̶��ߵ���ʼλ��ΪĬ�ϵ���ʼλ��
	QPoint endPos(m_beginPos.x() + m_iTotalLen, m_beginPos.y());
	p.drawLine(m_beginPos, endPos);

	//�����߿̶�
	int iMidLine = 0;
	for (int i = m_beginPos.x(); i < endPos.x(); i += m_iStep)
	{
		if (iMidLine == 5)
		{
			//��ʱӦ�û��Ƴ��Ŀ̶�
			p.drawLine(i, m_beginPos.y(), i, m_beginPos.y() - 5);
			iMidLine = 0;
		}
		else
		{
			p.drawLine(i, m_beginPos.y(), i, m_beginPos.y() - 2);
		}
		iMidLine++;
	}
	//�����α�
	//���û��ʣ���Ϊ�α������������Ŀ̶���Ҫ��һЩ
	p.restore();
	pen.setWidth(3);
	p.setPen(pen);
	p.save();
	//p.drawLine(m_iCurrentPos.x(), m_iCurrentPos.y(), m_iCurrentPos.x(), m_iCurrentPos.y() - 10);
	//���ƿ̶�����   --��ʼʱÿ5֡����һ��ʱ���־
	int iTextLen = m_iFontIntervalCount * 5 * m_iStep;
	for (int i = m_beginPos.x(); i< endPos.x(); i += iTextLen)
	{
		int iFrameSize = getFrameNumFromPos(i - m_beginPos.x());
		int iSecondTotal = iFrameSize / 25;
		int iSecond = iSecondTotal % 60;
		int iMinuteTotal = iSecond / 60;
		QString strFramSize = QString::number(iFrameSize%25, 10);
		if ((iFrameSize % 25) < 10)
		{
			strFramSize.insert(0, '0');
		}
	    QString strSecond = QString::number(iSecondTotal % 60, 10);
		if (iSecondTotal % 60 < 10)
		{
			strSecond.insert(0, '0');
		}
		QString strMinut = QString::number(iMinuteTotal % 60, 10);
		if (iMinuteTotal % 60 < 10)
		{
			strMinut.insert(0, '0');
		}
		QString strHour = QString::number(iMinuteTotal / 60, 10);
		if (iMinuteTotal / 60 < 10)
		{
			strHour.insert(0, '0');
		}
		QString strText;
		strText = QString("%1:%2:%3.%4").arg(strHour).arg(strMinut).arg(strSecond).arg(strFramSize);
		p.drawText(i, m_beginPos.y() - 10, strText);
		//����hander
		p.drawRect(m_CurrentHandlerPos);
	}
	p.restore();
	update();
}

//��ʼ����Ա����
void TimeRuler::initData()
{
	m_iStep = 30;
	m_iTotalLen = width();
	m_iCurrentPos = QPoint(0, height() - 1); //����ڿ̶ȳߵ���ʵλ��
	m_beginPos = m_iCurrentPos;
	m_iZommSize = 0; // ��ʼ״̬û�����Ŵ����

	m_iBigIntervalSize = 150;
	m_iOneStepFrames = 1;
	m_iFontIntervalCount = 1;
	m_bIsPressLeftMouse = false;
	m_iOffOriginLen = 55;
	m_CurrentHandlerPos = QRect(-3, height() - 18, 4, 18);
	m_bIsClickHandler = false;
}

//���ó�Ա������ֵ
void TimeRuler::setData()
{
	m_iTotalLen = width();
	m_iCurrentPos = QPoint(0, height()- 1); //����ڿ̶ȳߵ���ʵλ��
	m_beginPos = m_iCurrentPos;
	m_iBigIntervalSize += m_iZommSize;
	if (m_iBigIntervalSize >= 150)
	{
		m_iBigIntervalSize = 150;
	}

    if (m_iBigIntervalSize < 30)
	{
		m_iBigIntervalSize = 30;
	}
	m_iStep = m_iBigIntervalSize / 5;
	//if (m_iStep < m_RawStep / 2)
	//{
	//	m_iOneStepFrames *= 2;
	//	m_RawStep = m_iStep;
	//}
	//if (m_iStep > m_RawStep * 2)
	//{
	//	m_iOneStepFrames /= 2;
	//	m_RawStep = m_iStep;
	//}
	int iTmpLen = m_iStep * 5;
	m_iFontIntervalCount = 1;
	while (iTmpLen > 0 && iTmpLen < FONT_WIDTH * 1.5)
	{
		iTmpLen *= 2;
		m_iFontIntervalCount++;
	}
}

bool TimeRuler::canDrag(QPoint pos)
{
	if (pos.x() >=0 && pos.x()< width() - m_iOffOriginLen)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��ʼ���źźͲ�
void TimeRuler::initConnections()
{
	
}
