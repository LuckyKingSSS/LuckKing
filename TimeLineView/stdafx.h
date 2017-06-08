#pragma once
#include <QtWidgets/QtWidgets>
#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include "NLETimeline.h"

//多媒体资源类型
enum FilmoraMediaType
{ 
	Type_Video, //视频文件类型
	Type_Audio, //音频
	Type_Image, //图片
	Type_Unknow //未知类型
};