#ifndef RESLISTVIEW_H
#define RESLISTVIEW_H
#include <QWidget>
#include <QListWidget>


//资源视图控件
class ResListView : public QListWidget
{
	Q_OBJECT
public:
	ResListView(QListWidget *parent);
	~ResListView();
	void initConnections();
	void insertItem(QListWidgetItem* item);
	void insertItem(QString strFileName);
	void deleteItem(QListWidgetItem* item);

Q_SIGNALS:
	void signalLeftBtnDoubleClick(QListWidgetItem* selectItem);
	

private:
	QListWidgetItem* m_CurrentSelectItem;
};

#endif // RESLISTVIEW_H
