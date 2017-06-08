#include "stdafx.h"
#include "skintitlebar.h"

SkinTitleBar::SkinTitleBar(QWidget *parent)
	: TopLevelWindowTitleBar(parent)
{
	initUI();
}

SkinTitleBar::~SkinTitleBar()
{

}

void SkinTitleBar::initUI()
{
	setObjectName("SkinTitleBar");
	//设置title Name
	SetTitleName("Skin");
	//设置背景样式
	setStyleSheet("background-color: rgb(173,202,232)");
    //取消最小化和最大化的按钮
	SetButtons(TopLevelWindowTitleBar::Close);
}

