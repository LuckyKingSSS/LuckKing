/*
*Author:		zhy
*Date:			2016.07.22
*Description:	���ֱ༭�ؼ�,�����ִ�С����ɫ�������ȱ༭������
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

	// ��������༭����
	bool DoModal(NLETimeline *captionTimeline, NLETimeline *playerTimeline);

private:
	CaptionEditorViewPrivate *m_p;
};




#endif // CAPTIONEDTORVIEW_H
