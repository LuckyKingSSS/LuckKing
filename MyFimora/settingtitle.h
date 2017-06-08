#ifndef SETTINGTITLE_H
#define SETTINGTITLE_H
#include "TopLevelWindowTitleBar.h"


class SettingTitle : public TopLevelWindowTitleBar
{
	Q_OBJECT

public:
	SettingTitle(QWidget *parent);
	~SettingTitle();
	void initUI();
private:
	//TODO: 1123
	
};

#endif // SETTINGTITLE_H
