#include "stdafx.h"
#include "propertysettingctl.h"

PropertySettingCtl::PropertySettingCtl(QObject *parent)
	: QObject(parent)
{

}

PropertySettingCtl::~PropertySettingCtl()
{

}

QList<QString>* PropertySettingCtl::getLanguageList()
{
	QList<QString>* languageList = new QList < QString > ;
	//��Ҫ����i18n�е�qm�ļ��ĸ������ж���֧�ֵĶ�������Ŀ
	languageList->append(tr("English"));
	languageList->append(tr("Chinese"));
	return languageList;
}
