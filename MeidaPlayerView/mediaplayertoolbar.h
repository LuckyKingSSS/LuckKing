#ifndef MEDIAPLAYERTOOLBAR_H
#define MEDIAPLAYERTOOLBAR_H

#include <QtWidgets/QWidget>
#include <QMap>
class BaseButton;
class ToolBarSlider;
class IMediaPlayerControl;
class FullScreenControl;
class MediaPlayerToolBar : public QWidget
{
	Q_OBJECT
    //按钮的类型
public:
	enum  ButtonType
	{
        Type_BackFrame,
		Type_Play,
		Type_Pause,
		Type_FrontFrame,
		Type_Stop,
		Type_FullScreen,   //全屏效果
		Type_Restore      //取消全屏
	};
public:
	MediaPlayerToolBar(QWidget *parent);
	~MediaPlayerToolBar();
	void initUI();
	void initData();
	void initConnectios();
	void EnableButton(bool isEnabel);
	void Open();
	void Close();
	void Play();
	void Stop();
	void Pause();
	void Forward();
	void Backward();
	bool IsSeeking();
	//设置当前播放视频的总帧数
	void SetDuration(int  iFrameNumber);
	void SetFPS(float m_fps);
	void SeekManual(int frames, int accurate);
	void stopPlay();
	void DblMouseButtonFullScreen();

Q_SIGNALS:
	void Clicked(int id, QPoint p);
	void signalSliderValueChange(int inewValue);
	void sigalDurationChanged(int inewValue);
	void sigalSyncRulerHandler(int iValue);
protected:
	void createToolBarButtons(int id,const QString objectName);
	void CreateToolBarMixButton(int firstId, QString firstObjectName, int secondId, QString secondObjectName);
	void ButtonClicked(int id,QPoint p);
	void resizeEvent(QResizeEvent *event);
	BaseButton* GetButton(int id);
	//切换 播放 停止这两个按钮的状态
	void TransferMixButton(ButtonType newType);
	
private:
	QMap<int, BaseButton*> m_toolbarButtons; 
	//鉴于int的范围完全能够表达一个视频文件所包含的帧，所以设置slider的范围是帧数的范围
	ToolBarSlider* m_slider;
	IMediaPlayerControl*  m_mediaPlayerControl;
	
};

#endif // MEDIAPLAYERTOOLBAR_H
