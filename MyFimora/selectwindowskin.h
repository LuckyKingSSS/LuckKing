#ifndef SELECTWINDOWSKIN_H
#define SELECTWINDOWSKIN_H

#include <QWidget>
#include "skintitlebar.h"
#include "skinlistwidget.h"

#define  CSS_FILE  ".css"
class SelectWindowSkin : public QWidget
{
	Q_OBJECT

public:
	SelectWindowSkin(QWidget *parent);
	~SelectWindowSkin();
	void initUI();
	void initConnections();

public Q_SLOTS:
	void putOnNewSkin(QString strQssFilePath);

protected:
	void resizeEvent(QResizeEvent *event)override;
	//设置程序使用的编码方式
	void setCodec();
private:
	SkinTitleBar* m_TitleBar;//窗口标题栏
	QLabel* m_LeftTips;//左边的提示语
	QLabel* m_RightTips;//右边的提示语
	SkinListWidget* skinListItems;//当前所有可被使用的主题
};
#endif // SELECTWINDOWSKIN_H
