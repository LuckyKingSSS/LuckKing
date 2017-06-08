#include "stdafx.h"
#include "skinlistwidget.h"

SkinListWidget::SkinListWidget(QWidget *parent)
	: QListWidget(parent)
{
	m_ResPath = "";//初始时，设置resPath为空
	loadSkinResource(m_ResPath);
	initListWidget();
}

SkinListWidget::~SkinListWidget()
{

}

void SkinListWidget::initListWidget()
{
	this->setViewMode(QListWidget::IconMode);
	this->setIconSize(QSize(80, 75));
	this->setResizeMode(QListWidget::Adjust);
	this->setMovement(QListView::Static);
	this->setLayoutMode(QListView::Batched);
	this->setSelectionMode((QAbstractItemView::SelectionMode)3);
	this->setDragEnabled(true);
	this->setSpacing(10);
	this->setFocusPolicy(Qt::FocusPolicy::NoFocus);
	this->setStyleSheet("QListWidget{border: none;background: rgb(185,212,237);}");
	this->setSelectionRectVisible(false);
}

void SkinListWidget::loadSkinResource(QString strSkinPath)
{
	if (strSkinPath.isEmpty())
	{
		return;
	}
	QDir skinDir(strSkinPath);
	//加载所有的资源文件
	skinDir.setFilter(QDir::Files | QDir::NoSymLinks);
	QFileInfoList list = skinDir.entryInfoList();
	int file_count = list.count();
	if (file_count <= 0)
	{
		return;
	}
	QStringList string_list;
	for (int i = 0; i < file_count; ++i)
	{
		QFileInfo file_info = list.at(i);
		QString suffix = file_info.suffix();	
		if (QString::compare(suffix, QString("css"), Qt::CaseInsensitive) == 0)
		{
			//读取文件夹中的所有样式表文件并加载到列表中显示
			QString strFileName = file_info.fileName();
			QString strSuffix = file_info.suffix();
			int iIndex = strFileName.indexOf(strSuffix);
			strFileName = strFileName.mid(0, iIndex - 1);
			QListWidgetItem* item = new QListWidgetItem(QIcon(QPixmap(":/Image/Resources/image/time.png")), strFileName);
			//固定每一个项的大小
			item->setSizeHint(QSize(90, 90));
			addItem(item);
		}
	}
}