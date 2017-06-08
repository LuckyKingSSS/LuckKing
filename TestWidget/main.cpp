#include "testwidget.h"
#include <QtWidgets/QApplication>
#include "QLabel"
#include "QSpinBox"
#include "QBoxLayout"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestWidget w;
	QLabel* label = new QLabel(&w);
	label->setText("this is a label");
	//setGeometry(0, 0, width(), height());
	QSpinBox* spin = new QSpinBox(&w);
	QSlider* slider = new QSlider(&w);
	QHBoxLayout* layout = new QHBoxLayout;
	layout->addWidget(spin);
	layout->addWidget(slider);
	layout->addWidget(label);
	w.setLayout(layout);
	w.resize(500, 500);
	w.show();
	return a.exec();
}
