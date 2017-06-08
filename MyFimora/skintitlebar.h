#ifndef SKINTITLEBAR_H
#define SKINTITLEBAR_H

#include <QWidget>
#include "TopLevelWindowTitleBar.h"


class SkinTitleBar : public TopLevelWindowTitleBar
{
	Q_OBJECT

public:
	SkinTitleBar(QWidget *parent);
	~SkinTitleBar();
	void initUI();
private:
	
};

#endif // SKINTITLEBAR_H
