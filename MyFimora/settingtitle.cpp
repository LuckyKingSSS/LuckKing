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

	//�������title������ɫ��
	//��С����ťû����ʾ������ 
	//���Ͻ���һ������������ͬ������
	setObjectName(tr("settingWndTitle"));
	SetTitleName(tr("Setting"));
	SetButtons(TopLevelWindowTitleBar::Close);
	setStyleSheet("background-color: rgb(83,184,194)");
}
