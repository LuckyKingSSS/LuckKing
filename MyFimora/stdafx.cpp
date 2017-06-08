#include "stdafx.h"

#ifdef _DEBUG
#pragma comment(lib, "CommonLibD.lib")
#pragma comment(lib, "MeidaPlayerViewD.lib")
#pragma comment(lib, "ResourceViewD.lib")
#pragma comment(lib, "TimeLineViewD.lib")

#else
#pragma comment(lib, "CommonLib.lib")
#pragma comment(lib, "MediaPlayerView.lib")
#pragma comment(lib, "MatterView.lib")
#pragma comment(lib, "TimeLineView.lib")
#endif