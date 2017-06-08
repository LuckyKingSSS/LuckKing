#ifndef __UIRENDER_H__
#define __UIRENDER_H__
#include "commonlib_global.h"
#include <QPainter>
#include <QString>
class COMMONLIB_EXPORT RenderOperation
{
public:
 	static void DrawImage(QPainter& painter, QString &strImg, const QRect& rc);
	
	static void DrawImage(QPainter& painter, QString &strImg, const QRect& rc, const QRect& rcSource);

	static void DrawImage(QPainter& painter, QString &strImg, const QRect& rc, const QRect& rcSource, const QRect &rcCorner);//rcCorner �Ź�������

	static void DrawImage(QPainter& painter, QImage & img, const QRect& rc, const QRect &rcCorner);//rcCorner �Ź�������

	static void	DrawImage( QPainter& painter,const QPixmap &pixMap, const QRect& rc, const QRect& rcSource, const QRect &rcCorner );

	static void	DrawImage( QPainter& painter,const QPixmap &pixMap, const QRect& rc);

	static void DrawImage(QPainter& painter, char *pImageMemory, unsigned int imgSize, const QRect& rc, const QRect& rcSource);
 
 	static void DrawText(QPainter& painter, QString &text, QRect& rc, QRect &rcBr, int align = Qt::AlignCenter, bool endellipsis = false);

	static void DrawImageRound(QPainter& painter, QImage img, const QRect& rc);

	// �Ź������ţ�����ͼƬ�������ڱ��棬����������

	static QPixmap * GetNinePatch( QPixmap & sImg, const QRect & rcSrc, const QRect & rcDst, const QRect & rcCorner );

	// �� strImg ͼ�� rcSrc ������г�ͼƬ�����ŵ� szDst ��С���أ�rcSrcΪ������������ͼƬ
	static QImage ScaledImage( QString & strImg, const QSize & szDst, const QRect & rcSrc = QRect() );
	static QImage ScaledImage( QImage & imgSrc, const QSize & szDst, const QRect & rcSrc = QRect() );
};


#endif // __UIRENDER_H__
