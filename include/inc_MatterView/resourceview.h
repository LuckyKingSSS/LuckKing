#ifndef RESOURCEVIEW_H
#define RESOURCEVIEW_H
#include "resourceview_global.h"


class ResourceTool;
class ResListView;
class NLETimeline;
class RESOURCEVIEW_EXPORT ResourceView:public QWidget
{
	Q_OBJECT
public:
	ResourceView(QWidget* parent = nullptr);
	~ResourceView();
private:
	void initUi();
	void initConnections();

public:
	void resizeEvent(QResizeEvent *event)override;
	NLETimeline* GetSelectTimeline();
	
Q_SIGNALS:
	void signalLoad(bool bPlay);
	void signalPlayMovie(QString strMoviePath);
	void signalUnload();
protected:
	void mouseDoubleClickEvent(QMouseEvent *event);
public:
	void refreshUI();
private:
	ResourceTool* toolBar; //进行导入、删除操作的工具栏
	ResListView* sourceList;//展示具体资源的视图
	QListWidgetItem* itemSelect;
};
#endif // RESOURCEVIEW_H
