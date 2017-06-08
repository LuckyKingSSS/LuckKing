#ifndef DISPLAYVIEW_H
#define DISPLAYVIEW_H

#include <QtWidgets/QWidget>

class DisplayView : public QWidget
{
	Q_OBJECT

public:
	DisplayView(QWidget *parent);
	~DisplayView();
	void resizeEvent(QResizeEvent *event);
	void initUI();

private:
	
};

#endif // DISPLAYVIEW_H
