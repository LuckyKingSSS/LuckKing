#ifndef TIMELINEVIEW_H
#define TIMELINEVIEW_H

#include <QObject>
#include "toolbar.h"
#include "timeruler.h"
#include "resourcestackview.h"
#ifdef TIMERULER_H
#define TIMERULER_EXPORT Q_DECL_EXPORT
#else
#define TIMERULER_EXPORT Q_DECL_IMPORT
#endif

class TIMERULER_EXPORT TimeLineView : public QWidget
{
	Q_OBJECT

public:
	TimeLineView(QWidget *parent = nullptr);
	~TimeLineView();
	void resizeEvent(QResizeEvent * event);
protected:
	void initConrols();
	void initConnections();
	void mousePressEvent(QMouseEvent* event)override;


	void dragEnterEvent(QDragEnterEvent * event);
	void mouseMoveEvent(QMouseEvent * event);
	//test
	void dropEvent(QDropEvent *event)override;
	void dragMoveEvent(QDragMoveEvent *event)override;

private:
	ToolBar* m_TimeLineToolbar;
	TimeRuler* m_TimeRuler;
	ResourceStackView * allStackView;
	//视频当前播放帧的位置
};

#endif // TIMELINEVIEW_H
