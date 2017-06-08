#ifndef SKINLISTWIDGET_H
#define SKINLISTWIDGET_H

#include <QListWidget>

class SkinListWidget : public QListWidget
{
	Q_OBJECT

public:
	SkinListWidget(QWidget *parent);
	~SkinListWidget();
	void initListWidget();
	//加载皮肤资源
	void loadSkinResource(QString strSkinPath);
	//获取可以的皮肤数目
	int getAvailableSkinCount(){ return count(); };
	void setResPath(QString strPath){ m_ResPath = strPath; };
	QString getResPath(){ return m_ResPath; };
private:
	QString m_ResPath;//资源所在的路径
};

#endif // SKINLISTWIDGET_H
