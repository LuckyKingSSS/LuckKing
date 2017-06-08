#include "stdafx.h"
#include <QPainter>
#include <QMouseEvent>
#include "timeruler.h"
#include "QDebug"


#define FONT_WIDTH 70    //刻度尺上的文字宽度大小
TimeRuler::TimeRuler(QWidget *parent)
	: QWidget(parent)
{	
	initData();
	//this->setStyleSheet("background:red");
}

TimeRuler::~TimeRuler()
{

}

//经过测试，如果需要调用width() 和height() 获取窗口的高和宽需要在resizeEvent，
//最重要的是不能再构造函数中去获取，因为窗口时创建后会根据父窗口的大小发生改变
//这个是由于我们在父窗口中调用了setGeometry函数导致的
void TimeRuler::resizeEvent(QResizeEvent * event)
{
	m_iTotalLen = width();
	//相对于刻度尺的其实位置
	m_iCurrentPos = QPoint(0, height() - 1); 
	m_beginPos = QPoint(0, height() - 1);
	//由于窗口大小在构建后有一次变化过程，故做此以适应，
	//只在第一次窗口改变的时候做修改y坐标的值
	if (m_CurrentHandlerPos.x() == -3)
	{
		m_CurrentHandlerPos = QRect(-3, height() - 18, 4, 18);
	}
}

void TimeRuler::paintEvent(QPaintEvent *event)
{
	drawRuler();
}

//todo: 目前转换存在很严重的问题，不是可逆转的变换，误差太大，需要解决
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
	//由于鼠标释放时鼠标的位置不确定，
	//在此对鼠标的x坐标做限制，防止 “游标头”出现“越界”的行为
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
			//多偏移2个像素是为了使"游标"线正对handler的正中心
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
		//设置成员参数为修改后的数值
		int iLevel = getLevel(m_ZoomValue);
		setData(iLevel);
		if (iLevel != m_OldZoomLevel)
		{
			changeRulerAccuracy(iLevel);
			m_OldZoomLevel = iLevel;
		}
	}
	//如果用户用户鼠标点击区域在handler内部的话，执行handler的移动操作	
	QWidget::mouseMoveEvent(event);
}

//绘制刻度尺
void TimeRuler::drawRuler()
{
	//第一步： 绘制水平线
	QPainter p(this);
	p.setPen(Qt::SolidLine);
	QPainterPath path;
	QPen pen = p.pen();
	pen.setColor(QColor(61, 65, 69));
	pen.setWidth(1);
	p.setPen(pen);
	p.setBrush(QColor(61, 65, 69));
	p.save();
	
	//设置刻度线的起始位置为默认的起始位置
	QPointF endPos(m_beginPos.x() + m_iTotalLen, m_beginPos.y());
	p.drawLine(m_beginPos, endPos);

	//画竖线刻度
	int iMidLine = 0;
	for (int i = m_beginPos.x(); i < endPos.x(); i += m_iStep)
	{
		if (iMidLine == 5)
		{
			//此时应该绘制长的刻度
			p.drawLine(i, m_beginPos.y(), i, m_beginPos.y() - 5);
			iMidLine = 0;
		}
		else
		{
			p.drawLine(i, m_beginPos.y(), i, m_beginPos.y() - 2);
		}
		iMidLine++;
	}
	//绘制游标
	//设置画笔，因为游标的相较于其他的刻度线要粗一些
	p.restore();
	pen.setWidth(3);
	p.setPen(pen);
	p.save();
	//p.drawLine(m_iCurrentPos.x(), m_iCurrentPos.y(), m_iCurrentPos.x(), m_iCurrentPos.y() - 10);
	//绘制刻度文字   --初始时每5帧绘制一个时间标志
	int iTextLen = m_iFontIntervalCount * 5 * m_iStep;
	for (int i = m_beginPos.x(); i< endPos.x(); i += iTextLen)
	{
		//返回的结果其实是float变量，鉴于时间尺的精度问题，目前做只取整形部分
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
		//绘制hander
		p.drawRect(m_CurrentHandlerPos);
		qDebug() << "current handler pos is " << "("<<m_CurrentHandlerPos.x()<<","<<m_CurrentHandlerPos.y()<<")";
	}
	p.restore();
	update();
}

//初始化成员变量
void TimeRuler::initData()
{
	// 初始状态没有做放大操作
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

//重置成员变量的值
void TimeRuler::setData(int iLevel)
{
	m_iTotalLen = width();
	m_iCurrentPos = QPoint(0, height()- 1); //相对于刻度尺的其实位置
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
	//注意浮点型变量比较的表示
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

//初始化信号和槽
void TimeRuler::initConnections()
{
	
}

//获取当前缩放对应的档位
int TimeRuler::getLevel(int m_iZommSize)
{
	int iLevel = m_iZommSize / 120;
	return iLevel;
}

//改变时间尺当前的精度
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
	//改变等级一个大的尺度的长度还原
	m_iBigIntervalSize = 150;
	m_iStep = m_iBigIntervalSize / 5;

}
