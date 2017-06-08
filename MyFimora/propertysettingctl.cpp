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
	//需要遍历i18n中的qm文件的个数来判断所支持的多语言数目
	languageList->append(tr("English"));
	languageList->append(tr("Chinese"));
	return languageList;
}
