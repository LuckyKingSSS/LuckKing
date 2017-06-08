#include "stdafx.h"
#include "displayview.h"

DisplayView::DisplayView(QWidget *parent)
	: QWidget(parent)
{
	initUI();
}

DisplayView::~DisplayView()
{

}

void DisplayView::resizeEvent(QResizeEvent *event)
{
     
}

void DisplayView::initUI()
{
	setAttribute(Qt::WA_StyledBackground);
	setObjectName("DisplayView");
	//this->setStyleSheet("background:blue");
	//this->setStyleSheet("background-color:rgb(0,0,255)");

}
