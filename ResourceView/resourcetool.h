#ifndef RESOURCETOOL_H
#define RESOURCETOOL_H
#include <QtWidgets\QWidget>


class IconButton;
class ResourceTool : public QWidget
{
	Q_OBJECT

public:
	ResourceTool(QWidget *parent);
	~ResourceTool();
	
private:
	void initUI();
	void initConnections();
	
public Q_SLOTS:
	void slotImportBtnClicked();
	void slotRemoveBtnClicked();
	void slotEnableRemoveBtn();
Q_SIGNALS:
	void signalImportMediaInfo(QStringList mediaStrInfo);
	void signalRemoveBtnClicked();
	void signalEnableRemoveBtn();
protected:
	void resizeEvent(QResizeEvent *event);
	void paintEvent(QPaintEvent *event);
private:
	IconButton* m_importRes;
	IconButton* m_removeRes;
};
#endif // RESOURCETOOL_H