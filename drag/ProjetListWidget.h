#ifndef PROJETLISTWIDGET_H
#define PROJETLISTWIDGET_H

#include <QListWidget>

class ProjetListWidget : public QListWidget
{
	Q_OBJECT

public:
	ProjetListWidget(QListWidget *parent = nullptr);
	~ProjetListWidget();

protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dragMoveEvent(QDragMoveEvent *event) override;
	void dropEvent(QDropEvent* event);

	//响应键盘的事件
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	void performDrag();
	QPoint statPos;
};

#endif // PROJETLISTWIDGET_H
