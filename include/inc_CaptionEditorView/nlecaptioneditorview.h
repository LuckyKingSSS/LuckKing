/*
*Author:		zhy
*Date:			2016.07.22
*Description:	文字编辑控件,对文字大小、颜色、动画等编辑并保存
*/


#ifndef NLECAPTIONEDTORVIEW_H
#define NLECAPTIONEDTORVIEW_H


#ifdef WIN32

#ifdef NLECAPTIONEDITORVIEW_EXPORT
#define NLECAPTIONEDITORVIEW_EXT __declspec(dllexport)
#else
#define NLECAPTIONEDITORVIEW_EXT __declspec(dllimport)
#endif

#else
#define NLECAPTIONEDITORVIEW_EXT  
#endif



#include <QtWidgets/QDialog>

class NLETimeline;
class CaptionEditorViewPrivate;
class  NLECAPTIONEDITORVIEW_EXT NLECaptionEditorView : public QDialog
{
	Q_OBJECT
public:
	NLECaptionEditorView(QWidget *parent);

	// 弹出字体编辑窗口
	bool DoModal(NLETimeline *captionTimeline, NLETimeline *playerTimeline);

private:
	CaptionEditorViewPrivate *m_p;
};




#endif // CAPTIONEDTORVIEW_H
