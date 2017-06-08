#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>
#include <QTextStream>

#ifdef _DEBUG
#pragma comment(lib, "CommonLibD.lib")
#else
#pragma comment(lib, "CommonLib.lib")
#endif


enum ImportFilterType{ FilterType_Video, FilterType_Audio, FilterType_Image, FilterType_All };
static const QString ImportFilter[][2] = {
		{ "Video files", "*.wmv *.mov *.mp4 *.avi *.flv *.rmvb *.mkv *3g2 *3gp *dv *flv *m4v *mpg *ts *webm *tp *trp *m2t *m2ts" },
		{ "Audio files", "*.mp3 *.mp2 *.wav *.wma" },
		{ "Image files", "*.bmp *.jpg *.png *.jpeg" },
		{ "All files", "(*.*)" }
};