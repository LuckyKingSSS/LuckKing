#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H

#include <QItemDelegate>

class ComboBoxDelegate : public QItemDelegate
{
	Q_OBJECT

public:
	ComboBoxDelegate(QObject *parent);
	~ComboBoxDelegate();
	void drawFocus(QPainter *painter, const QStyleOptionViewItem &option, const QRect &rect) const;
private:

};

#endif // COMBOBOXDELEGATE_H
