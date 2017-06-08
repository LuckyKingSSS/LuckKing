#include "stdafx.h"
#include "reslistview.h"


ResListView::ResListView(QListWidget *parent)
	: QListWidget(parent)
{
	initUI();
	initConnections();
}

ResListView::~ResListView()
{

}

void ResListView::initConnections()
{
	//connect(this, ResListView::itemDoubleClicked,)
	connect(this, &ResListView::itemClicked, this, [&](QListWidgetItem * item){
		itemSelect = item;
	});
}

void ResListView::insertItem(QString strFileName)
{
	QListWidgetItem* item = new QListWidgetItem(QIcon(QPixmap(":/Image/Resources/image/time.png")), strFileName);
	//固定每一个项的大小
	item->setSizeHint(QSize(90, 90));
	addItem(item);
}

void ResListView::deleteItem(QListWidgetItem* item)
{

}

QString ResListView::getMoivePathByKey(QString strKey)
{
	QString path = m_PathMap[strKey];
	return path;
}

//做初始化参数操作
void ResListView::initUI()
{
	setObjectName("ResListView");
	this->setViewMode(QListWidget::IconMode);
	this->setIconSize(QSize(80, 75));
	this->setResizeMode(QListWidget::Adjust);
	this->setMovement(QListView::Static);
	this->setLayoutMode(QListView::Batched);

	this->setSelectionMode((QAbstractItemView::SelectionMode)3);
	this->setDragEnabled(true);
	this->setSpacing(10);
	this->setFocusPolicy(Qt::FocusPolicy::NoFocus);
	this->setStyleSheet("QListWidget{border: none;background: rgb(245,244,244);}");
	this->setSelectionRectVisible(false);
}

void ResListView::initData()
{
	bIsMousePress = false;
}

void ResListView::mousePressEvent(QMouseEvent *event)
{
	if (event->buttons() | Qt::LeftButton)
	{
		if (!(this->selectedItems()).empty())
		{
			QList<QListWidgetItem *> allSelectItems = this->selectedItems();
			bIsMousePress = true;
			m_pressPoint = event->pos();
		}
		else
		{
			emit signalUnload();
		}
	}
	QListWidget::mousePressEvent(event);
}

void ResListView::mouseMoveEvent(QMouseEvent *event)
{
	QPoint currentPos = event->pos();
	currentPos = currentPos - m_pressPoint;
	if (bIsMousePress  && currentPos.manhattanLength() > QApplication::startDragDistance())
	{
		auto mimeData = new QMimeData;
		QList<QListWidgetItem *> allSelectItems;
		if (currentItem() != nullptr)
		{
			allSelectItems.push_back(currentItem());
		}	
		if (!allSelectItems.empty())
		{
			QString strFileName = allSelectItems[0]->text();
			QString strFilePath = m_PathMap[strFileName];    
			mimeData->setProperty("ResourceView_FileName", strFileName);
			mimeData->setProperty("ResourceView_FilePath", strFilePath);
			int nMatterType = -1;
			int nLen = 0;
			QDrag drag(this);
			drag.setMimeData(mimeData);
			drag.exec();
		}	
	}
	QListWidget::mouseMoveEvent(event);
}

void ResListView::focusOutEvent(QFocusEvent *event)
{
    //发射 signalUnload
	emit signalUnload();
	QListWidget::focusOutEvent(event);
}

void ResListView::addResInfo(QStringList mediaInfoList)
	{
		for each (QString var in mediaInfoList)
		{
			int iIndex = var.lastIndexOf("/");
			if (iIndex == 0)
			{
				continue;
			}
			else
			{
				m_PathMap.insert(var.mid(iIndex + 1), var);
				var = var.mid(iIndex + 1);
			}
			insertItem(var);
		}
	}

void ResListView::deleteResInfo()
{
	//获取当前选中的资源项
	QList<QListWidgetItem *> allSelectItems =  selectedItems();
	QList<QListWidgetItem *>::iterator iter = allSelectItems.begin();
	for (; iter != allSelectItems.end();++iter)
	{
		int iRow = row(*iter);
		takeItem(iRow);
	}
	update();
}