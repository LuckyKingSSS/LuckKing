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
	//����Ƥ����Դ
	void loadSkinResource(QString strSkinPath);
	//��ȡ���Ե�Ƥ����Ŀ
	int getAvailableSkinCount(){ return count(); };
	void setResPath(QString strPath){ m_ResPath = strPath; };
	QString getResPath(){ return m_ResPath; };
private:
	QString m_ResPath;//��Դ���ڵ�·��
};

#endif // SKINLISTWIDGET_H
