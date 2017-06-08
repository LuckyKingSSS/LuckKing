#include "stdafx.h"
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QApplication>
#include <QMimeData>
#include <QDrag>
#include <QMessageBox>
#include "ProjetListWidget.h"

ProjetListWidget::ProjetListWidget(QListWidget *parent)
	: QListWidget(parent)
{
	setAcceptDrops(true);
}

ProjetListWidget::~ProjetListWidget()
{

}

void ProjetListWidget::dragEnterEvent(QDragEnterEvent *event)
{
	ProjetListWidget *source = qobject_cast<ProjetListWidget *>(event->source());
	if (source && source != this)
	{
		//event->setDropAction(Qt::MoveAction);
		event->accept();
	}
}

void ProjetListWidget::dragMoveEvent(QDragMoveEvent *event)
{
	ProjetListWidget *source = qobject_cast<ProjetListWidget *>(event->source());
	if (source && source != this)
	{
		event->setDropAction(Qt::MoveAction);
		event->accept();
	}
}

void ProjetListWidget::dropEvent(QDropEvent* event)
{
	ProjetListWidget *source = qobject_cast<ProjetListWidget *>(event->source());
	if (source && source != this)
	{
		addItem(event->mimeData()->text());
		event->setDropAction(Qt::MoveAction);
		event->accept();
	}
}

void ProjetListWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		statPos = event->pos();
		QListWidget::mousePressEvent(event);
	}
}

void ProjetListWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() & Qt::LeftButton)
	{
		int distance = (event->pos() - statPos).manhattanLength();
		if (distance >= QApplication::startDragDistance())
		{
			performDrag();
		}
	}
	QListWidget::mouseMoveEvent(event);
}

void ProjetListWidget::performDrag()
{
	QListWidgetItem *item = currentItem();
	if (item)
	{
		QMimeData *mimeData = new QMimeData;
		mimeData->setText(item->text());
		QDrag *drag = new QDrag(this);
		drag->setMimeData(mimeData);
		drag->setPixmap(QPixmap(":/drag/Resources/1.png"));
		//调用并启动拖放操作
		if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
		{
			delete item;
		}
	}
}
