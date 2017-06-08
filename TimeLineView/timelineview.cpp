#include "stdafx.h"
#include <QDragEnterEvent>
#include <QDrag>
#include <QtDebug>
#include "inc_TimelineView/timelineview.h"
#include "QMessageBox"
#include "../include/inc_CommonLib/NLEWraper.h"

TimeLineView::TimeLineView(QWidget *parent)
	: QWidget(parent)
{
	initConrols();
	initConnections();
	initData();
	this->setAcceptDrops(true);
}

TimeLineView::~TimeLineView()
{

}

void TimeLineView::resizeEvent(QResizeEvent * event)
{
	m_TimeLineToolbar->setGeometry(50, 20, width() - 50, 35);
	m_TimeRuler->setGeometry(55, 68, width(), 20);
	allStackView->setGeometry(0, 90, width(), height() - 120);
}

// 获取时间线   
NLETimeline* TimeLineView::GetTimeline()
{
	return m_ComplexTimeline;
}

//todo:    获取当前是第几帧
int TimeLineView::GetCurrentFrame()
{
	return 0;
}

void TimeLineView::initConrols()
{
	m_TimeRuler = new TimeRuler(this);
	m_TimeLineToolbar = new ToolBar(this);
	allStackView = new ResourceStackView(this);
}

void TimeLineView::initConnections()
{
	connect(m_TimeRuler, &TimeRuler::frameMove, allStackView, &ResourceStackView::FramePosChange);
	connect(this, &TimeLineView::signalSyncPlayerSlider, allStackView, &ResourceStackView::signalSyncPlayerSlider);
	connect(m_TimeRuler, &TimeRuler::frameMove, allStackView, [&](QPointF point){
		//同步播放器slider控件
		QPointF  ralativeToRulerPoint = QPointF(point.x() - 55.00, 0.00);
		emit signalSyncPlayerSlider(ralativeToRulerPoint);
	});
	connect(allStackView, &ResourceStackView::frameHanlerChange, m_TimeRuler, &TimeRuler::setStartFrameHandler);
	connect(allStackView, &ResourceStackView::frameLineChange, allStackView, &ResourceStackView::FramePosChange);
	connect(allStackView, &ResourceStackView::signalAddClipTimeline, this, [&](NLETimeline* timeline,QPointF pos){
		addNewClipTimeline(timeline, pos);
	});
	connect(allStackView, &ResourceStackView::signalRemoveClipTimeline, this, [&](NLETimeline* timeline){
		m_ComplexTimeline->RemoveClip(timeline);
	});
	connect(allStackView, &ResourceStackView::signalSyncPlayerSlider, this, [&](QPointF pos){
		float fRealFrame = m_TimeRuler->getFrameNumFromPos(pos.x());
		emit signalSeekToFrame(fRealFrame);
		emit signalPlaySliderValueChanged(fRealFrame);
	});
	connect(allStackView, &ResourceStackView::sigalDurationChanged, this, &TimeLineView::sigalDurationChanged);
	connect(this, &TimeLineView::sigalSyncRulerHandler, m_TimeRuler, [&](int iFrameNum){
		QPoint pos(m_TimeRuler->getPosFromFrameNum(iFrameNum), m_TimeRuler->height() - 18);
		m_TimeRuler->setStartFrameHandler(pos);
		//改变ruler的同时同步“游标针”
		//加上55 是为了做坐标较正，因为stack 和ruler的坐标起始点不一样
		allStackView->FramePosChange(QPoint(pos.x() + 55,0));
	});
	//响应工具栏按钮点击事件
	connect(m_TimeLineToolbar, &ToolBar::signalButtonClicked, allStackView, &ResourceStackView::signalButtonClicked);
	connect(allStackView, &ResourceStackView::signalSeekToFrame, this, &TimeLineView::signalSeekToFrame);
}

void TimeLineView::mousePressEvent(QMouseEvent* event)
{
	
}

void TimeLineView::initData()
{
	NLEComPtr<INLETimelineBase> pSrcTimeline = NLEWraper::GetInstance().GetPlayerMaterProvider()->CreateEmptyTimeline();
	m_ComplexTimeline = new NLETimeline(pSrcTimeline);
	allStackView->setRuler(m_TimeRuler);
	allStackView->setTimeline(m_ComplexTimeline);
	m_TimeRuler->setCurrentTimeline(m_ComplexTimeline);
}

void TimeLineView::dragEnterEvent(QDragEnterEvent * event)
{
	event->acceptProposedAction();
}

void TimeLineView::mouseMoveEvent(QMouseEvent * event)
{
	QDrag *drag = new QDrag(this);
	drag->setPixmap(QPixmap(":/images/images/normal/TimelineView_TextEdit_h.png"));
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

void TimeLineView::addNewClipTimeline(NLETimeline* newTimeline,QPointF pos)
{
	//由于传递过来的点的坐标是相对于stack 所以需要做坐标转换
	//55 为stack 相较于ruler 相对于父窗口往左移动的距离
	float iXRalativeToRuler = pos.x() - 55.00;
	float iOffFrameNum = m_TimeRuler->getFrameNumFromPos(iXRalativeToRuler);
	//todo:AddClip 的第三个参数是level  后期实现多轨道需要参数化该参数
	m_ComplexTimeline->AddClip(newTimeline, iOffFrameNum, 1);
	QPoint  qReslut = m_ComplexTimeline->GetRange();
	int iTotalFrameNum = qReslut.y() - qReslut.x();
	emit sigalDurationChanged(iTotalFrameNum);
}

void TimeLineView::seekToPos(QPointF pos)
{
	float iRealFrame = m_TimeRuler->getFrameNumFromPos(pos.x());
}

void TimeLineView::refreshUI()
{
	
}
