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
	//���ó���ʹ�õı��뷽ʽ
	void setCodec();
private:
	SkinTitleBar* m_TitleBar;//���ڱ�����
	QLabel* m_LeftTips;//��ߵ���ʾ��
	QLabel* m_RightTips;//�ұߵ���ʾ��
	SkinListWidget* skinListItems;//��ǰ���пɱ�ʹ�õ�����
};
#endif // SELECTWINDOWSKIN_H
