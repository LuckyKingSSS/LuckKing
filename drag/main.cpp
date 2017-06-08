#include "stdafx.h"
#include "drag.h"
#include "ui_drag.h"
#include <QtWidgets/QApplication>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "ProjetListWidget.h"
#include "timeruler.h"
#include "toolbar.h"
#include "timelineview.h"
#include "resourcestackview.h"

/************************************************************************/
/* 作者：wangbiao
   功能：文件编辑器
   时间：2017/04/27
*/
/************************************************************************/
//如何使用ui文件做开发？
//


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//Ui::Form ui;
	//QWidget* d = new QWidget;
	//ui.setupUi(d);
	//d->show();

	// QWidget* widget = new QWidget;
	//QListWidget* listWidget = new QListWidget;
	//QVBoxLayout* layout = new QVBoxLayout;
	//QListWidgetItem* lst1 = new QListWidgetItem("data", listWidget);
	//QListWidgetItem* lst2 = new QListWidgetItem("decision", listWidget);
	//QListWidgetItem* lst3 = new QListWidgetItem("document", listWidget);
	//QListWidgetItem* lst4 = new QListWidgetItem("process", listWidget);
	//QListWidgetItem* lst5 = new QListWidgetItem("printer", listWidget);
	//listWidget->insertItem(1, lst1);
	//listWidget->insertItem(2, lst2);
	//listWidget->insertItem(3, lst3);
	//listWidget->insertItem(4, lst4);
	//listWidget->insertItem(5, lst5);
	//listWidget->show();
	//layout->addWidget(listWidget);
	//widget->setLayout(layout);
	//widget->show();
	 /*QVBoxLayout* vLayout = new QVBoxLayout;
	 QHBoxLayout* hLayout = new QHBoxLayout;

	 QLabel* labelLeft = new QLabel("projectA");
	 labelLeft->setWindowTitle("projectA");
	 labelLeft->show();
	 QLabel* labelRight = new QLabel("projectB");
	 labelRight->setWindowTitle("projectB");
	 labelRight->show();
	 hLayout->addWidget(labelLeft);
	 hLayout->addWidget(labelRight);

	 QHBoxLayout* layout = new QHBoxLayout;
	 QListWidget* listWidget1 = new ProjetListWidget(nullptr);
	 QListWidgetItem* lst1 = new QListWidgetItem("11111",     listWidget1);
	 QListWidgetItem* lst2 = new QListWidgetItem("decision", listWidget1);
	 QListWidgetItem* lst3 = new QListWidgetItem("document", listWidget1);
	 QListWidgetItem* lst4 = new QListWidgetItem("process", listWidget1);
	 QListWidgetItem* lst5 = new QListWidgetItem("printer", listWidget1);
	 listWidget1->insertItem(1, lst1);
	 listWidget1->insertItem(2, lst2);
	 listWidget1->insertItem(3, lst3);
	 listWidget1->insertItem(4, lst4);
	 listWidget1->insertItem(5, lst5);
	 listWidget1->show();


	 QListWidget* listWidget2 = new ProjetListWidget(nullptr);
	 QListWidgetItem* lst11 = new QListWidgetItem("data", listWidget2);
	 QListWidgetItem* lst21 = new QListWidgetItem("decision", listWidget2);
	 QListWidgetItem* lst31 = new QListWidgetItem("document", listWidget2);
	 QListWidgetItem* lst41 = new QListWidgetItem("process", listWidget2);
	 QListWidgetItem* lst51 = new QListWidgetItem("printer", listWidget2);
	 listWidget2->insertItem(1, lst11);
	 listWidget2->insertItem(2, lst21);
	 listWidget2->insertItem(3, lst31);
	 listWidget2->insertItem(4, lst41);
	 listWidget2->insertItem(5, lst51);
	 listWidget2->show();


	 layout->addWidget(listWidget1);
	 layout->addWidget(listWidget2);
	 vLayout->addLayout(hLayout);
	 vLayout->addLayout(layout);

	 widget->setLayout(vLayout);
	 widget->show();*/
	 //设置父窗口的大小
	// widget->setFixedSize(980, 610);
	//TimeRuler ruler;
	//ruler.show();

	//ToolBar bar;
	//bar.show();
	TimeLineView* timeline = new TimeLineView();
	timeline->show();

	// widget->show();
	//ResourceStackView* stackView = new ResourceStackView;
	//stackView->show();
	return a.exec();
}
