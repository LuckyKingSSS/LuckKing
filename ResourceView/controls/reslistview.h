#ifndef RESLISTVIEW_H
#define RESLISTVIEW_H
#include <QWidget>


//资源视图控件
class ResListView : public QListWidget
{
	Q_OBJECT
public:
	ResListView(QListWidget *parent);
	~ResListView();
	void initConnections();
	void insertItem(QString strFileName);
	void deleteItem(QListWidgetItem* item);
	QString getMoivePathByKey(QString strKey);
	void initUI();
	void initData();

protected:
	void mousePressEvent(QMouseEvent *event)override;
	void mouseMoveEvent(QMouseEvent *event)override;
	//失去焦点事件
	void focusOutEvent(QFocusEvent *event)override;
Q_SIGNALS:
	void signalLeftBtnDoubleClick(QListWidgetItem* selectItem);
	void playMovie(QString strMoviePath);
	void signalUnload();

public Q_SLOTS:
	void addResInfo(QStringList mediaInfoList);
	void deleteResInfo();

private:
	QListWidgetItem* m_CurrentSelectItem;
	QMap<QString, QString> m_PathMap;
	bool bIsMousePress;
	QPoint m_pressPoint;//鼠标选中一个视频文件时当前的鼠标位置
	QListWidgetItem * itemSelect;
};
#endif // RESLISTVIEW_H
