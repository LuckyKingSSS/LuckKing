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
	//从当前的位置获取当前位置对应的帧数，注意返回值应该设计为float变量，因为不一定能够被整除
	float getFrameNumFromPos(float iPos);
	//从当前帧数获取当前所在的坐标位置（X坐标）
	float getPosFromFrameNum(float iFramNum);
	void setStartFrameHandler(QPointF newPos);
	void setCurrentTimeline(NLETimeline* timeline);
    
signals:
	//拖动游标信号
	void frameMove(QPointF point); 

protected:
	void mousePressEvent(QMouseEvent* event)override;
	void mouseReleaseEvent(QMouseEvent* event)override;
	void mouseMoveEvent(QMouseEvent* event)override;
	void drawRuler();
private:
	void initData();
	void setData(int iLevel);
	bool canDrag(QPointF pos);
	void initConnections();
	int getLevel(int m_iZommSize);
	void changeRulerAccuracy(int iAccuracyLevel);
private:
	int m_iStep;          //设置步长，最小的刻度单位的像素间隔
	int m_iTotalLen;     //刻度的可显示总长度
	QPointF m_iCurrentPos;//当前时间刻度的位置
	QPointF m_beginPos;  //当前游标所在的位置
	int m_iZommSize;    //刻度尺缩放参数
	int m_iFontIntervalCount;//两个文字之间相间隔的大刻度的个数
	int m_iBigIntervalSize;//两个大的刻度尺之间的间隔
	int m_iOneStepFrames; //刻度尺上的一个刻度线对应的帧数
	int m_RawStep;
	signed int m_RestoreSizeFactor;//还原一个大的刻度的间距参数，当放大倍数为3的时候进行还原

	int m_iFps;//播放的帧率
	bool m_bIsPressLeftMouse;
	QPoint m_PressPoint;
	int m_iOffOriginLen;
	QRect m_CurrentHandlerPos; //当前的调整帧位置的“滑块”头的位置
	bool m_bIsClickHandler;
	int m_ZoomValue;
	int m_OldZoomLevel;
	NLETimeline* m_CurrentTimeline;
};
#endif // TIMERULER_H
