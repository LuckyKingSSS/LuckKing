#ifndef MYFIMORAPRIVATE_H
#define MYFIMORAPRIVATE_H

#include <QWidget>
class ResourceView;
class MeidaPlayerView;
class TimeLineView;
class ToolBarView;
class IMediaPlayerControl;
class MyFimoraPrivate : public QWidget
{
	Q_OBJECT
public:
	MyFimoraPrivate(QWidget *parent);
	~MyFimoraPrivate();
	void initUI();
	void resizeEvent(QResizeEvent *event);
	IMediaPlayerControl* GetPlayerControler();
	void refreshUI();

public Q_SLOTS:
void slotChangeLanguage();

protected:
	void initConnections();
	void LoadTimeline();
public:
	ResourceView* resView;
	MeidaPlayerView* playerView;
	ToolBarView* toolbarView;
	TimeLineView* timelineView;
Q_SIGNALS:
	void sign();
	void sigalDurationChanged(int iNewValue);
	void signalChangeLanguge();

private:
	QHBoxLayout* hLayout;
	QVBoxLayout* vLayout;
};

#endif // MYFIMORAPRIVATE_H
