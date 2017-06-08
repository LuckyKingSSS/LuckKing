#include "stdafx.h"
#include <QPainter>
#include <QMouseEvent>
#include "timeruler.h"
#include "QDebug"


#define FONT_WIDTH 70    //�̶ȳ��ϵ����ֿ�ȴ�С
TimeRuler::TimeRuler(QWidget *parent)
	: QWidget(parent)
{	
	initData();
	//this->setStyleSheet("background:red");
}

TimeRuler::~TimeRuler()
{

}

//�������ԣ������Ҫ����width() ��height() ��ȡ���ڵĸߺͿ���Ҫ��resizeEvent��
//����Ҫ���ǲ����ٹ��캯����ȥ��ȡ����Ϊ����ʱ���������ݸ����ڵĴ�С�����ı�
//��������������ڸ������е�����setGeometry�������µ�
void TimeRuler::resizeEvent(QResizeEvent * event)
{
	m_iTotalLen = width();
	//����ڿ̶ȳߵ���ʵλ��
	m_iCurrentPos = QPoint(0, height() - 1); 
	m_beginPos = QPoint(0, height() - 1);
	//���ڴ��ڴ�С�ڹ�������һ�α仯���̣�����������Ӧ��
	//ֻ�ڵ�һ�δ��ڸı��ʱ�����޸�y�����ֵ
	if (m_CurrentHandlerPos.x() == -3)
	{
		m_CurrentHandlerPos = QRect(-3, height() - 18, 4, 18);
	}
}

void TimeRuler::paintEvent(QPaintEvent *event)
{
	drawRuler();
}

//todo: Ŀǰת�����ں����ص����⣬���ǿ���ת�ı任�����̫����Ҫ���
float TimeRuler::getFrameNumFromPos(float iPos)
{
	return iPos / m_iStep * m_iOneStepFrames;
}

float TimeRuler::getPosFromFrameNum(float iFramNum)
{
	return iFramNum / m_iOneStepFrames * m_iStep;
}

void TimeRuler::setStartFrameHandler(QPointF newPos)
{
	//��������ͷ�ʱ����λ�ò�ȷ����
	//�ڴ˶�����x���������ƣ���ֹ ���α�ͷ�����֡�Խ�硱����Ϊ
	if (newPos.x() < -2)
	{
		newPos.setX(-2);
	}
	m_CurrentHandlerPos = QRect(newPos.x(), height() - 18, 4, 18);
}

void TimeRuler::setCurrentTimeline(NLETimeline* timeline)
{
	m_CurrentTimeline = timeline;
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
			//��ƫ��2��������Ϊ��ʹ"�α�"������handler��������
			QPoint relativeParentPos(event->pos().x() + m_iOffOriginLen + 2, event->pos().y());
			emit frameMove(relativeParentPos);
		}
	}else if (m_bIsPressLeftMouse)
	{
		signed int  moveLen = (event->pos().x()) - (m_PressPoint.x());
		m_ZoomValue -= moveLen;
		m_iZommSize = moveLen;
		if (m_iZommSize > 600 || m_iZommSize < 0)
		{
			m_iZommSize = m_iZommSize % 600;
		}
		//���ó�Ա����Ϊ�޸ĺ����ֵ
		int iLevel = getLevel(m_ZoomValue);
		setData(iLevel);
		if (iLevel != m_OldZoomLevel)
		{
			changeRulerAccuracy(iLevel);
			m_OldZoomLevel = iLevel;
		}
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
	QPointF endPos(m_beginPos.x() + m_iTotalLen, m_beginPos.y());
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
		//���صĽ����ʵ��float����������ʱ��ߵľ������⣬Ŀǰ��ֻȡ���β���
		int iFrameSize = getFrameNumFromPos(i - m_beginPos.x());
		iFrameSize *= ((m_RestoreSizeFactor == 0) ? 1 : m_RestoreSizeFactor);
		int iSecondTotal = iFrameSize / 25;
		int iSecond = iSecondTotal % 60;
		int iMinuteTotal = iSecondTotal / 60;
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
		qDebug() << "current handler pos is " << "("<<m_CurrentHandlerPos.x()<<","<<m_CurrentHandlerPos.y()<<")";
	}
	p.restore();
	update();
}

//��ʼ����Ա����
void TimeRuler::initData()
{
	// ��ʼ״̬û�����Ŵ����
	m_iZommSize = 0; 
	m_RestoreSizeFactor = 0;
	m_iBigIntervalSize = 150;
	m_iOneStepFrames = 1;
	m_iFontIntervalCount = 1;
	m_bIsPressLeftMouse = false;
	m_iOffOriginLen = 55;
	m_bIsClickHandler = false;
	m_ZoomValue = 0;
	m_OldZoomLevel = 0;
	m_iStep = 30;
	m_CurrentHandlerPos = QRect(-3, height() - 18, 4, 18);
	m_CurrentTimeline = nullptr;
}

//���ó�Ա������ֵ
void TimeRuler::setData(int iLevel)
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
	int iTmpLen = m_iStep * 5;
	m_iFontIntervalCount = 1;
	int iFactor = 0;
	while (iTmpLen > 0 && iTmpLen < FONT_WIDTH * 1.5)
	{
		iTmpLen *= 2;
		m_iFontIntervalCount++;
		iFactor++;
	}	
}

bool TimeRuler::canDrag(QPointF pos)
{
	float iRightBound = width() - m_iOffOriginLen;
	if (m_CurrentTimeline != nullptr)
	{	
		int iRightFrameBound = m_CurrentTimeline->GetRange().y() - m_CurrentTimeline->GetRange().x();
		qDebug() << "***** iRightFrameBound pos is " << "(" << m_CurrentTimeline->GetRange().x() << "," << m_CurrentTimeline->GetRange().y() << ") *****";
		qDebug() << "***** iRightFrameBound length is (total frame number: )" << iRightFrameBound;
	    iRightBound = getPosFromFrameNum(iRightFrameBound);
		qDebug() << "***** iRightBound length is (total timeline length:  )" << iRightBound;
	}
	//ע�⸡���ͱ����Ƚϵı�ʾ
	if (pos.x() >= (-2 + 0.0) && pos.x() <= iRightBound)
	{
		qDebug() << "***** current drag pos is " << "(" << m_CurrentHandlerPos.x() << "," << m_CurrentHandlerPos.y() << ") *****";
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

//��ȡ��ǰ���Ŷ�Ӧ�ĵ�λ
int TimeRuler::getLevel(int m_iZommSize)
{
	int iLevel = m_iZommSize / 120;
	return iLevel;
}

//�ı�ʱ��ߵ�ǰ�ľ���
void TimeRuler::changeRulerAccuracy(int iAccuracyLevel)
{
	switch (iAccuracyLevel)
	{
	case 0:
	{
		m_iOneStepFrames = 1;

		break;
	}
	case 1:
	{
		m_iOneStepFrames = 1 * 5;
		break;
	}
	case 2:
	{
		m_iOneStepFrames = 1 * 5 * 5;
		break;
	}
	case 3:
	{
		m_iOneStepFrames = 1 * 5 * 5 * 6;
		break;
	}
	case 4:
	{
		m_iOneStepFrames = 1 * 5 * 5 * 6 * 5;
		break;
	}
	default:
		break;
	}
	//�ı�ȼ�һ����ĳ߶ȵĳ��Ȼ�ԭ
	m_iBigIntervalSize = 150;
	m_iStep = m_iBigIntervalSize / 5;

}
