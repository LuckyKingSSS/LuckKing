/********************************************************************************
** Form generated from reading UI file 'drag.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAG_H
#define UI_DRAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QStringListModel>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QListView *listView;
    QListView *listView_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(471, 300);
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 40, 91, 16));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 40, 91, 16));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 110, 41, 31));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 160, 41, 31));
        listView = new QListView(Form);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(30, 80, 141, 171));
		QStringList insertValue;
		insertValue<<QString("1") << QString("2") << QString("3") << QString("4");
		addListItem(listView, insertValue);
        listView_2 = new QListView(Form);
        listView_2->setObjectName(QStringLiteral("listView_2"));
        listView_2->setGeometry(QRect(260, 80, 141, 171));
		insertValue.clear();
		insertValue << QString("a") << QString("b") << QString("c") << QString("d");
		addListItem(listView_2, insertValue);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi


	void addListItem(QListView * insertListView, QStringList insertValue)
	{
		QStringListModel *model = new QStringListModel(insertValue);
		insertListView->setModel(model);
	}




    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "DragTest", 0));
        label->setText(QApplication::translate("Form", "Project A", 0));
        label_2->setText(QApplication::translate("Form", "Project B", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAG_H
