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

//���������ӿؼ���λ��
void ResourceView::resizeEvent(QResizeEvent *event)
{
	toolBar->setGeometry(0, 0, width(),30);
	sourceList->setGeometry(0, 30, width(), height() - 30);
}

//��ȡ��ǰѡ�����Ƶ��timeline
NLETimeline* ResourceView::GetSelectTimeline()
{
   //��ȡ��ǰѡ�����
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

//���˫���¼�
void ResourceView::mouseDoubleClickEvent(QMouseEvent *event)
{
	  if (event->buttons()|Qt::LeftButton)
	  {
		  //��ȡ�������
		  //sourceList
	  }
}

void ResourceView::refreshUI()
{
	
}
