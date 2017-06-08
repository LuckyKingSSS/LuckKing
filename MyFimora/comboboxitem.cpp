#include "stdafx.h"
#include "comboboxitem.h"

ComboboxItem::ComboboxItem(QWidget *parent)
	: QWidget(parent)
{
	initUI();
}

ComboboxItem::~ComboboxItem()
{

}

void ComboboxItem::setLabelContent(QString strText)
{
	QByteArray strByteArray = strText.toLatin1();
	char* strTextToShow = strByteArray.data();
	m_label->setText(tr(strTextToShow));
}

void ComboboxItem::initUI()
{
	m_img = new QLabel(this);
	QPixmap pic(QStringLiteral(""));
	m_img->setPixmap(pic);
	m_img->setFixedSize(pic.size());
	m_label = new QLabel(this);
	m_layout = new QHBoxLayout(this);
	//需要重新设置值，因为有默认初始值
	m_layout->setContentsMargins(0, 0, 0, 0);
	m_layout->addWidget(m_label);
	m_layout->addStretch();
	m_layout->addWidget(m_img);
	setLayout(m_layout);
	m_bIsPressed = false;
	m_iCurrentIntemIndex = 0;
}

void ComboboxItem::paintEvent(QPaintEvent *event)
{

}

void ComboboxItem::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bIsPressed = true;
	}
}

void ComboboxItem::mouseReleaseEvent(QMouseEvent *event)
{
	if (m_bIsPressed)
	{
		emit singalChooseAccount(m_label->text());
		emit signalCurrentIndexChanged(m_iCurrentIntemIndex);
		m_bIsPressed = false;
	}
}

void ComboboxItem::slotEmpty()
{

}
