#ifndef TOOLBAR_H
#define TOOLBAR_H
#include <QWidget>
#include <QLabel>
#include <QSlider>


class ToolBar : public QWidget
{
	Q_OBJECT
	enum btnType
	{
	Type_Redo,  //redo��ť
	Type_Undo,  //undo��ť
	Type_Cut,  
	Type_Delete,
	Type_Crop
	};
public:
	ToolBar(QWidget *parent = nullptr);
	~ToolBar();
	QLabel* createNewLabel(QString picturePath);
	void resizeEvent(QResizeEvent * event)override;

	//������
	void dragEnterEvent(QDragEnterEvent * event);
	void dragMoveEvent(QDragMoveEvent *event);
	void dropEvent(QDropEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	void performDrag();

Q_SIGNALS:
	void clicked(btnType type);
	void signalButtonClicked(btnType type);

protected:
	void mousePressEvent(QMouseEvent * event)override;
	void initControls();
	void initConnections();
private:
	QList<QLabel*> m_toolBar;
	QSlider*       m_ZoomSlider;  //�Ŵ���С�������Ŀؼ�
	QPoint         m_StartPos;
};
#endif // TOOLBAR_H
