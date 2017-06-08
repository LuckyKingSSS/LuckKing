/********************************************************************************
** Form generated from reading UI file 'testwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWIDGET_H
#define UI_TESTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestWidgetClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestWidgetClass)
    {
        if (TestWidgetClass->objectName().isEmpty())
            TestWidgetClass->setObjectName(QStringLiteral("TestWidgetClass"));
        TestWidgetClass->resize(600, 400);
        menuBar = new QMenuBar(TestWidgetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TestWidgetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestWidgetClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TestWidgetClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TestWidgetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TestWidgetClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TestWidgetClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestWidgetClass->setStatusBar(statusBar);

        retranslateUi(TestWidgetClass);

        QMetaObject::connectSlotsByName(TestWidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestWidgetClass)
    {
        TestWidgetClass->setWindowTitle(QApplication::translate("TestWidgetClass", "TestWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class TestWidgetClass: public Ui_TestWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWIDGET_H
