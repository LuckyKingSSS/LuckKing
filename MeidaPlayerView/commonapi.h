#pragma once
#include "Linux32_Typedef.h"


//////////////////////////////////////////////////////////////////////////

#ifndef WIN32

typedef  void*  HWND;

//struct RECT
//{
//	long    left;
//	long    top;
//	long    right;
//	long    bottom;
//};

#endif


class MediaPlayerToolBar;
class QPropertyAnimation;
class QTimer;

class FullScreenControl : public QObject
{
public:
	FullScreenControl( QWidget *w);
	void SetToolbar(MediaPlayerToolBar *toolbar){ m_toolbar = toolbar; }
	void FullScreen();
	void Restore();
	bool IsFullScreen();
	void ResizeEvent(QWidget *displayView, QRect rect);
	// 工具栏动画效果
	void MayShowToolbar(QRect rect, QPoint p);
private:
	void StopAnimation();
	bool IsToolBarShow();
	bool IsAnimationRunning();
	void SetFullScreen(bool fullscreen);
	
private:
	QWidget *m_mediaPlayerViewPrivate;
	MediaPlayerToolBar *m_toolbar;

	QPropertyAnimation *m_hideAnimation;
	QPropertyAnimation *m_showAnimation;
	QTimer *m_hideAnimTimer;
	QPoint m_curPoint;
	QRect m_dispplayRect;
};