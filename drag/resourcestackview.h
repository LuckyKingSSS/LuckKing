#ifndef RESOURCESTACKVIEW_H
#define RESOURCESTACKVIEW_H

#include <Qwidget>
#include <QButtonGroup>

class DragClip;
class TimeRuler;
class ResourceStackView : public QWidget
{
	Q_OBJECT
	enum headType{TYPE_MOVIE,TYPE_EFFECT,TYPE_MUSIC};
public:
	ResourceStackView(QWidget *parent = nullptr);
	~ResourceStackView();
	int getDrapLipeTopPos(QPoint dragPos);

protected:
	void resizeEvent(QResizeEvent* event)override;
	void paintEvent(QPaintEvent* event);
	void dropEvent(QDropEvent* event)override;
	void dragEnterEvent(QDragEnterEvent *evnet);
	void dragMoveEvent(QDragMoveEvent * event);
	void mouseMoveEvent(QMouseEvent * event)override;
	void mousePressEvent(QMouseEvent *evnet)override;
	void mouseReleaseEvent(QMouseEvent * event)override;

	public Q_SLOTS:
	void FramePosChange(QPoint point);

private:
	void initData();
	void initConnections();
	void createHeadPixMap(headType type, int iIndex, QPainter& picPainter);
	bool canDrag(QPoint newPos);
	
private:
	int m_OffsetLen; //竖直线跟最左边窗口的距离
	int m_firstDistance;
	int m_Distance;
	int m_initalHeight;
	int m_CurrentGridHeight;
	//用户拖拽的视频片段信息
	QList<DragClip*> m_AllClipInfo;
	DragClip* m_currentDragClip;
	bool m_bIsleftMousePress;
	QPoint m_SpinLinePos;
	TimeRuler* m_Ruler;
};

#endif // RESOURCESTACKVIEW_H
