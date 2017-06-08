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
	QLabel* m_img; //�ұߵ�ͼƬ
	QLabel* m_label;//�����ʾ������
	QHBoxLayout* m_layout;//ʹ�õĲ���
	bool m_bIsPressed;// ��ǰ���Ƿ�ѡ��
	int m_iCurrentIntemIndex;//��ǰ����QListWidget�ж�Ӧ�����
};

#endif // COMBOBOXITEM_H
