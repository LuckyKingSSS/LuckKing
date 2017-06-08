#include "stdafx.h"
#include "settingtitle.h"

SettingTitle::SettingTitle(QWidget *parent)
	: TopLevelWindowTitleBar(parent)
{
	setAttribute(Qt::WA_StyledBackground);
	//setAttribute(Qt::WA_TranslucentBackground);
	initUI();
}

SettingTitle::~SettingTitle()
{

}

void SettingTitle::initUI()
{

	//如何设置title字体颜色？
	//最小化按钮没有显示出来？ 
	//左上角有一个跟背景不相同的区域？
	setObjectName(tr("settingWndTitle"));
	SetTitleName(tr("Setting"));
	SetButtons(TopLevelWindowTitleBar::Close);
	setStyleSheet("background-color: rgb(83,184,194)");
}
