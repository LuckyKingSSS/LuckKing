#include "stdafx.h"
#include <QDragEnterEvent>
#include <QDrag>
#include <QtDebug>
#include "timelineview.h"
#include "QMessageBox"

TimeLineView::TimeLineView(QWidget *parent)
	: QWidget(parent)
{
	initConrols();
	initConnections();
	this->setAcceptDrops(true);
}

TimeLineView::~TimeLineView()
{

}

void TimeLineView::resizeEvent(QResizeEvent * event)
{
	//m_TimeRuler->move(55, 68);
	//m_TimeLineToolbar->move(0,0);
	////当窗口变化时，对应的子控件也发生变化
	//m_TimeRuler->resize(width(), height());
	//m_TimeLineToolbar->resize(width(), 50);
	m_TimeLineToolbar->setGeometry(50, 20, width() - 50, 35);
	m_TimeRuler->setGeometry(55, 68, width(), 20);
	allStackView->setGeometry(0, 90, width(), height() - 120);
}


void TimeLineView::initConrols()
{
	m_TimeRuler = new TimeRuler(this);
	m_TimeLineToolbar = new ToolBar(this);
	allStackView = new ResourceStackView(this);
	this->resize(850, 850);
	//m_TimeRuler->move(0, 100);
	//this->setWindowFlags(Qt::FramelessWindowHint);
}

void TimeLineView::initConnections()
{
	connect(m_TimeRuler, &TimeRuler::frameMove, allStackView, &ResourceStackView::FramePosChange);
}

void TimeLineView::mousePressEvent(QMouseEvent* event)
{
	
}


void TimeLineView::dragEnterEvent(QDragEnterEvent * event)
{
	event->acceptProposedAction();
}

void TimeLineView::mouseMoveEvent(QMouseEvent * event)
{
	QDrag *drag = new QDrag(this);
	drag->setPixmap(QPixmap(":/drag/Resources/1.png"));
	drag->exec(Qt::MoveAction);
	QWidget::mouseMoveEvent(event);
}




void TimeLineView::dropEvent(QDropEvent *event)
{
	qDebug()<< "test event working****************************";
}

void TimeLineView::dragMoveEvent(QDragMoveEvent *event)
{
	event->accept();
	qDebug() << "test dragMoveEvent working****************************";
}
