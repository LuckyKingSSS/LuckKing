#ifndef MEIDAPLAYERVIEW_H
#define MEIDAPLAYERVIEW_H

#include "meidaplayerview_global.h"
#include <QtWidgets/QWidget>

class MeidaPlayerInnerData;
class NLETimeline;
class IMediaPlayerControl;
class MEIDAPLAYERVIEW_EXPORT MeidaPlayerView : public QWidget
{
	Q_OBJECT
public:
	MeidaPlayerView(QWidget* parent = nullptr);
	~MeidaPlayerView();
	IMediaPlayerControl* GetPlayerControler();
	void initConnection();

public Q_SLOTS:
void playMovie(QString strMoviePath);

Q_SIGNALS:
void signalSeekToPos(int iFrame);
void signalPlaySliderValueChanged(int iNewValue);
void sigalDurationChanged(int iNewValue);
//slider 同步
void sigalSyncRulerHandler(int iNewValue);

protected:
	void resizeEvent(QResizeEvent *event);
public:
	void refreshUI();
private:
	MeidaPlayerInnerData* m_InnerData;
};

//导出此模块中的所有的样式表
MEIDAPLAYERVIEW_EXPORT QString gGetMediaPlayerStyles();

#endif // MEIDAPLAYERVIEW_H
