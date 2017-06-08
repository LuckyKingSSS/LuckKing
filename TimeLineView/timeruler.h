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
	
	//�����С�ı��¼�
	void resizeEvent(QResizeEvent * event); 
	void paintEvent(QPaintEvent *event);

     //���ò��ŵ�fps
	void setFps(int iValue);
	//�ӵ�ǰ��λ�û�ȡ��ǰλ�ö�Ӧ��֡����ע�ⷵ��ֵӦ�����Ϊfloat��������Ϊ��һ���ܹ�������
	float getFrameNumFromPos(float iPos);
	//�ӵ�ǰ֡����ȡ��ǰ���ڵ�����λ�ã�X���꣩
	float getPosFromFrameNum(float iFramNum);
	void setStartFrameHandler(QPointF newPos);
	void setCurrentTimeline(NLETimeline* timeline);
    
signals:
	//�϶��α��ź�
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
	int m_iStep;          //���ò�������С�Ŀ̶ȵ�λ�����ؼ��
	int m_iTotalLen;     //�̶ȵĿ���ʾ�ܳ���
	QPointF m_iCurrentPos;//��ǰʱ��̶ȵ�λ��
	QPointF m_beginPos;  //��ǰ�α����ڵ�λ��
	int m_iZommSize;    //�̶ȳ����Ų���
	int m_iFontIntervalCount;//��������֮�������Ĵ�̶ȵĸ���
	int m_iBigIntervalSize;//������Ŀ̶ȳ�֮��ļ��
	int m_iOneStepFrames; //�̶ȳ��ϵ�һ���̶��߶�Ӧ��֡��
	int m_RawStep;
	signed int m_RestoreSizeFactor;//��ԭһ����Ŀ̶ȵļ����������Ŵ���Ϊ3��ʱ����л�ԭ

	int m_iFps;//���ŵ�֡��
	bool m_bIsPressLeftMouse;
	QPoint m_PressPoint;
	int m_iOffOriginLen;
	QRect m_CurrentHandlerPos; //��ǰ�ĵ���֡λ�õġ����顱ͷ��λ��
	bool m_bIsClickHandler;
	int m_ZoomValue;
	int m_OldZoomLevel;
	NLETimeline* m_CurrentTimeline;
};
#endif // TIMERULER_H
