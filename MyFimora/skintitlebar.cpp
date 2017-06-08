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
	//����title Name
	SetTitleName("Skin");
	//���ñ�����ʽ
	setStyleSheet("background-color: rgb(173,202,232)");
    //ȡ����С������󻯵İ�ť
	SetButtons(TopLevelWindowTitleBar::Close);
}

