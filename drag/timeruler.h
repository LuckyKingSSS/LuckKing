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
	//�ӵ�ǰ��λ�û�ȡ��ǰλ�ö�Ӧ��֡��
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
	int m_iStep;          //���ò�������С�Ŀ̶ȵ�λ�����ؼ��
	int m_iTotalLen;     //�̶ȵĿ���ʾ�ܳ���
	QPoint m_iCurrentPos;//��ǰʱ��̶ȵ�λ��
	QPoint m_beginPos;  //��ǰ�α����ڵ�λ��
	int m_iZommSize;    //�̶ȳ����Ų���
	int m_iFontIntervalCount;//��������֮�������Ĵ�̶ȵĸ���
	int m_iBigIntervalSize;//������Ŀ̶ȳ�֮��ļ��
	int m_iOneStepFrames; //�̶ȳ��ϵ�һ���̶��߶�Ӧ��֡��
	int m_RawStep;

	int m_iFps;//���ŵ�֡��
	bool m_bIsPressLeftMouse;
	QPoint m_PressPoint;
	int m_iOffOriginLen;
	QRect m_CurrentHandlerPos; //��ǰ�ĵ���֡λ�õġ����顱ͷ��λ��
	bool m_bIsClickHandler;
};

#endif // TIMERULER_H
