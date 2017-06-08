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
    //��ť������
public:
	enum  ButtonType
	{
        Type_BackFrame,
		Type_Play,
		Type_Pause,
		Type_FrontFrame,
		Type_Stop,
		Type_FullScreen,   //ȫ��Ч��
		Type_Restore      //ȡ��ȫ��
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
	//���õ�ǰ������Ƶ����֡��
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
	//�л� ���� ֹͣ��������ť��״̬
	void TransferMixButton(ButtonType newType);
	
private:
	QMap<int, BaseButton*> m_toolbarButtons; 
	//����int�ķ�Χ��ȫ�ܹ����һ����Ƶ�ļ���������֡����������slider�ķ�Χ��֡���ķ�Χ
	ToolBarSlider* m_slider;
	IMediaPlayerControl*  m_mediaPlayerControl;
	
};

#endif // MEDIAPLAYERTOOLBAR_H
