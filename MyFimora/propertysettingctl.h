#ifndef PROPERTYSETTINGCTL_H
#define PROPERTYSETTINGCTL_H

#include <QObject>
class QComboBox;
class PropertySettingCtl : public QObject
{
	Q_OBJECT

public:
	PropertySettingCtl(QObject *parent);
	~PropertySettingCtl();
	QList<QString>* getLanguageList();
private:
	
};

#endif // PROPERTYSETTINGCTL_H
