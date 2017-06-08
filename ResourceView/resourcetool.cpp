#include "stdafx.h"
#include "resourcetool.h"
#include ".\controls\IconButton.h"
#include  ".\controls\reslistview.h"

ResourceTool::ResourceTool(QWidget *parent)
	: QWidget(parent)
{
	initUI();
	initConnections();
	//setStyleSheet("color: rgb(0,255,255);");
}

ResourceTool::~ResourceTool()
{

}

void ResourceTool::initUI()
{
	setObjectName("resourceToolBar");
	m_importRes = new IconButton(tr("Import"),this);
	m_removeRes = new IconButton(tr("Remove"),this);
	m_importRes->SetIconImage(":/Image/Resources/image/addbutton.png", QSize(13, 13));
	m_removeRes->SetIconImage(":/Image/Resources/image/delete5213.png", QSize(13, 13));
	//设置按钮所在的位置
	m_importRes->setGeometry(20, 10, 100, 20);
	m_removeRes->setGeometry(100,10, 100, 20);
	m_removeRes->SetEnabled(false);
}

//初始化信号和槽
void ResourceTool::initConnections()
{
	connect(m_importRes, &IconButton::clicked, this, &ResourceTool::slotImportBtnClicked);
	connect(m_removeRes, &IconButton::clicked, this, &ResourceTool::slotRemoveBtnClicked);
	connect(this, &ResourceTool::signalEnableRemoveBtn, this, &ResourceTool::slotEnableRemoveBtn);
}


//导入按钮响应函数
void ResourceTool::slotImportBtnClicked()
{
	QStringList filters;
	filters << QString("All supported files (%1 %2 %3)").arg(ImportFilter[FilterType_Video][1], ImportFilter[FilterType_Audio][1], ImportFilter[FilterType_Image][1])
		<< QString("%1 (%2)").arg(ImportFilter[FilterType_Video][0], ImportFilter[FilterType_Video][1])
		<< QString("%1 (%2)").arg(ImportFilter[FilterType_Audio][0], ImportFilter[FilterType_Audio][1])
		<< QString("%1 (%2)").arg(ImportFilter[FilterType_Image][0], ImportFilter[FilterType_Image][1])
		<< QString("%1 (%2)").arg(ImportFilter[FilterType_All][0], ImportFilter[FilterType_All][1]);

	QFileDialog dialog(this);
	dialog.setNameFilters(filters);
	dialog.setAcceptMode(QFileDialog::AcceptOpen);
	dialog.setFileMode(QFileDialog::ExistingFiles);
	if (dialog.exec())
	{
		QStringList list = dialog.selectedFiles();
		if (list.empty()) return;
		emit signalImportMediaInfo(list);
	}
}

void ResourceTool::slotRemoveBtnClicked()
{
	emit signalRemoveBtnClicked();
}

void ResourceTool::slotEnableRemoveBtn()
{
	m_removeRes->SetEnabled(true);
}

void ResourceTool::resizeEvent(QResizeEvent *event)
{
	m_importRes->setGeometry(20, 10, 100, 20);
	m_removeRes->setGeometry(100, 10, 100, 20);
}

//窗口重绘事件
void ResourceTool::paintEvent(QPaintEvent *event)
{

}

