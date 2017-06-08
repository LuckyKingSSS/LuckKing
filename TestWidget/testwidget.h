#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QtWidgets/QMainWindow>
#include "ui_testwidget.h"

class TestWidget : public QMainWindow
{
	Q_OBJECT

public:
	TestWidget(QWidget *parent = 0);
	~TestWidget();
	void paintEvent(QPaintEvent *event)override;

private:
	Ui::TestWidgetClass ui;
};

#endif // TESTWIDGET_H
