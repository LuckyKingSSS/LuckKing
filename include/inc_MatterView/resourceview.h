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
	ResourceTool* toolBar; //���е��롢ɾ�������Ĺ�����
	ResListView* sourceList;//չʾ������Դ����ͼ
	QListWidgetItem* itemSelect;
};
#endif // RESOURCEVIEW_H
