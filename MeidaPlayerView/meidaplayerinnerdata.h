#ifndef MEIDAPLAYERINNERDATA_H
#define MEIDAPLAYERINNERDATA_H

#include <QtWidgets/QWidget>


class DisplayView;
class MediaPlayerControl;
class IMediaPlayerControl;
class MediaPlayerToolBar;
class FullScreenControl;

class MeidaPlayerInnerData : public QWidget
{
	Q_OBJECT

public:
	MeidaPlayerInnerData(QWidget *parent);
	~MeidaPlayerInnerData();
	IMediaPlayerControl* getMediaControler(){ return reinterpret_cast<IMediaPlayerControl*>(m_DisplayControl); }
	void initConnections();
Q_SIGNALS:
	void signalSliderValueChange(int iNewValue);
	void sigalDurationChanged(int iNewValue);
	void sigalSyncRulerHandler(int iNewValue);

public Q_SLOTS:
	void slotSeekToFrame(int iFrame);
protected:
	void resizeEvent(QResizeEvent *event);

private:
	DisplayView* m_DisplayView; 
	MediaPlayerControl* m_DisplayControl;
	MediaPlayerToolBar* m_PlayerToolBar;
	FullScreenControl* m_FullScreenContol;
};

#endif // MEIDAPLAYERINNERDATA_H
