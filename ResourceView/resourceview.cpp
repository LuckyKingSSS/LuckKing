#include "stdafx.h"
#include "resourceview.h"
#include "resourcetool.h"
#include "..\controls\reslistview.h"
#include "NLEComPtr.h"
#include "INLETimelineBase.h"
#include "NLEWraper.h"
#include "NLETimeline.h"


ResourceView::ResourceView(QWidget* parent):
QWidget(parent)
{
	initUi();
	initConnections();
}

ResourceView::~ResourceView()
{

}

void ResourceView::initUi()
{
	toolBar = new ResourceTool(this);
	sourceList = new ResListView(reinterpret_cast<QListWidget*>(this));
}

void ResourceView::initConnections()
{
	connect(toolBar, &ResourceTool::signalImportMediaInfo, sourceList, &ResListView::addResInfo);
	connect(sourceList, &ResListView::itemDoubleClicked, this, [&](QListWidgetItem * selectItem){emit signalPlayMovie(selectItem->text()); });
	connect(sourceList, &ResListView::signalUnload, this, &ResourceView::signalUnload);
	connect(toolBar, &ResourceTool::signalRemoveBtnClicked, sourceList, &ResListView::deleteResInfo);
	connect(sourceList, &ResListView::itemSelectionChanged, toolBar, &ResourceTool::signalEnableRemoveBtn);
}

//调整各个子控件的位置
void ResourceView::resizeEvent(QResizeEvent *event)
{
	toolBar->setGeometry(0, 0, width(),30);
	sourceList->setGeometry(0, 30, width(), height() - 30);
}

//获取当前选择的视频的timeline
NLETimeline* ResourceView::GetSelectTimeline()
{
   //获取当前选择的项
	QList<QListWidgetItem *> allSelectItems = sourceList->selectedItems();
	if (allSelectItems.size() <= 0)
	{
		return nullptr;
	}
	QListWidgetItem * item = allSelectItems.first();
	if (item == nullptr)
	{
		return nullptr;
	}
	NLEComPtr<INLETimelineBase> ptimeline;
	QString strPath = item->text();
	ptimeline = NLEWraper::GetInstance().GetPlayerMaterProvider()->CreateMediaTimeline(sourceList->getMoivePathByKey(strPath));
	NLETimeline* timeline = new NLETimeline(ptimeline);
	return timeline;
}

//鼠标双击事件
void ResourceView::mouseDoubleClickEvent(QMouseEvent *event)
{
	  if (event->buttons()|Qt::LeftButton)
	  {
		  //获取点击的项
		  //sourceList
	  }
}

void ResourceView::refreshUI()
{
	
}
