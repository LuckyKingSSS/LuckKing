#ifndef DRAGCLIP_H
#define DRAGCLIP_H

#include <QObject>
/************************************************************************/
/* ���ߣ�wangbiao
   ���ܣ���ק�Ķ�ý����Ϣ��
   ʱ�䣺2017/05/03
*/
/************************************************************************/

const int TIMELINEVIEW_TRACKITEM_HEIGHT_VIDEO = 65;
const int TIMELINEVIEW_TRACKITEM_HEIGHT_EFFECT = 42;
const int TIMELINEVIEW_TRACKITEM_HEIGHT_AUDIO = 42;
const int TIMELINEVIEW_TRACKITEM_WIDTH_HEADER = 55;

class DragClip : public QObject
{
	Q_OBJECT

public:
	DragClip(QObject *parent = nullptr);
	~DragClip();
	void SetPos(QPoint& pos);
	void setClipWidth(int iWidth);
	void setClipResName(QString strName);
	void setDragPixmap(QPixmap* map = nullptr);
	void setPixMapRect(QRect rec);

	QPoint getpos(){ return m_StayPos; };
	int getClipWidth(){ return m_ClipWidth; };
	QString getClipResName(){ return m_ClipResourceName; };
	QPixmap* getPixMap(){ return m_DragPixMap; };
	QRect getPixMapRec(){ return m_PixMapRec; };
private:
	QPoint m_StayPos;
	int m_ClipWidth;
	QString m_ClipResourceName;
	QPixmap* m_DragPixMap;//��קʱ�����ͼƬ
	//��ʱ��Ƭ��ͼ�����Ӧ�ľ������򣬷���������ж�
	QRect m_PixMapRec;
};


#endif // DRAGCLIP_H
