#ifndef TIMERULER_H
#define TIMERULER_H
#include <QWidget>
#include <QPoint>
#include <QtCore/qobjectdefs.h>
class  TimeRuler : public QWidget
{
	Q_OBJECT
public:
	TimeRuler(QWidget *parent = nullptr);
	~TimeRuler();
	
	//窗体大小改变事件
	void resizeEvent(QResizeEvent * event); 
	void paintEvent(QPaintEvent *event);

     //设置播放的fps
	void setFps(int iValue);
	//从当前的位置获取当前位置对应的帧数
	int getFrameNumFromPos(int iPos);
signals:
	void frameMove(QPoint point);

protected:
	void mousePressEvent(QMouseEvent* event)override;
	void mouseReleaseEvent(QMouseEvent* event)override;
	void mouseMoveEvent(QMouseEvent* event)override;
	void drawRuler();
private:
	void initData();
	void setData();
	bool canDrag(QPoint pos);
	void initConnections();
private:
	int m_iStep;          //设置步长，最小的刻度单位的像素间隔
	int m_iTotalLen;     //刻度的可显示总长度
	QPoint m_iCurrentPos;//当前时间刻度的位置
	QPoint m_beginPos;  //当前游标所在的位置
	int m_iZommSize;    //刻度尺缩放参数
	int m_iFontIntervalCount;//两个文字之间相间隔的大刻度的个数
	int m_iBigIntervalSize;//两个大的刻度尺之间的间隔
	int m_iOneStepFrames; //刻度尺上的一个刻度线对应的帧数
	int m_RawStep;

	int m_iFps;//播放的帧率
	bool m_bIsPressLeftMouse;
	QPoint m_PressPoint;
	int m_iOffOriginLen;
	QRect m_CurrentHandlerPos; //当前的调整帧位置的“滑块”头的位置
	bool m_bIsClickHandler;
};

#endif // TIMERULER_H
