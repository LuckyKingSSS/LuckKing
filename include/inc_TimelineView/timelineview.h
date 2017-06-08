#ifndef TIMELINEVIEW_H
#define TIMELINEVIEW_H

#include <QObject>
#include "toolbar.h"
#include "timeruler.h"
#include "timelineview_global.h"
#include "resourcestackview.h"
#include "..\inc_CommonLib\NLETimeline.h"

class TimeRuler;
class TIMELINEVIEW_EXPORT TimeLineView : public QWidget
{
	Q_OBJECT
public:
	TimeLineView(QWidget *parent = nullptr);
	~TimeLineView();
	void resizeEvent(QResizeEvent * event);
	NLETimeline* GetTimeline();
	int GetCurrentFrame();

Q_SIGNALS:
	void signalSeekToFrame(int iFrame);
	void signalPlaySliderValueChanged(int iValue);
	void sigalDurationChanged(int iNewValue);
	void sigalSyncRulerHandler(int iNewValue);
	void signalSyncPlayerSlider(QPointF point);
	
protected:
	void initConrols();
	void initConnections();
	void mousePressEvent(QMouseEvent* event)override;
	void initData();

	void dragEnterEvent(QDragEnterEvent * event);
	void mouseMoveEvent(QMouseEvent * event);
	//test
	void dropEvent(QDropEvent *event)override;
	void dragMoveEvent(QDragMoveEvent *event)override;
	void addNewClipTimeline(NLETimeline* newTimeline,QPointF pos);
public Q_SLOTS:
	void seekToPos(QPointF pos);
public: 
	void refreshUI();
private:
	ToolBar* m_TimeLineToolbar;
	TimeRuler* m_TimeRuler;
	ResourceStackView * allStackView;
	NLETimeline* m_ComplexTimeline;
};

#endif // TIMELINEVIEW_H
