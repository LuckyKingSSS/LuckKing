#ifndef COMBOBOXITEM_H
#define COMBOBOXITEM_H

#include <QWidget>

class QHBoxLayout;
class ComboboxItem : public QWidget
{
	Q_OBJECT

public:
	ComboboxItem(QWidget *parent);
	~ComboboxItem();
	void setLabelContent(QString strText);
	void initUI();
	void paintEvent(QPaintEvent *event);
	void setCurrentIndex(int iInedex){ m_iCurrentIntemIndex = iInedex; };
	int getCurrentIndex(){ return m_iCurrentIntemIndex; };
protected:
	void mousePressEvent(QMouseEvent *event)override;
	void mouseReleaseEvent(QMouseEvent *event)override;

Q_SIGNALS:
	void singalChooseAccount(const QString&);
	void signalCurrentIndexChanged(int iIndex);

	public Q_SLOTS:
	void slotEmpty();

private:
	QLabel* m_img; //右边的图片
	QLabel* m_label;//左边显示的文字
	QHBoxLayout* m_layout;//使用的布局
	bool m_bIsPressed;// 当前项是否被选中
	int m_iCurrentIntemIndex;//当前项在QListWidget中对应的序号
};

#endif // COMBOBOXITEM_H
