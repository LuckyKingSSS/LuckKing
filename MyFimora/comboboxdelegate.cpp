#include "stdafx.h"
#include "comboboxdelegate.h"

ComboBoxDelegate::ComboBoxDelegate(QObject *parent)
	: QItemDelegate(parent)
{

}

ComboBoxDelegate::~ComboBoxDelegate()
{

}

void ComboBoxDelegate::drawFocus(QPainter *painter, const QStyleOptionViewItem &option, const QRect &rect) const
{

}
