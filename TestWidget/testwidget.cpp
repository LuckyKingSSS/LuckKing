#include "testwidget.h"
#include <QLabel>
#include "QPainter"
#include "QSpinBox"
#include "QBoxLayout"

TestWidget::TestWidget(QWidget *parent)
	: QMainWindow(parent)
{
	//QLabel* label = new QLabel();
	//label->setText("this is a label");
	////setGeometry(0, 0, width(), height());
	//QSpinBox* spin = new QSpinBox();
	//QSlider* slider = new QSlider();
	//QHBoxLayout* layout = new QHBoxLayout;
	//layout->addWidget(spin);
	//layout->addWidget(slider);
	//layout->addWidget(label);
	//this->setLayout(layout);
	//this->resize(500, 500);
}

TestWidget::~TestWidget()
{

}

void TestWidget::paintEvent(QPaintEvent *event)
{

}
