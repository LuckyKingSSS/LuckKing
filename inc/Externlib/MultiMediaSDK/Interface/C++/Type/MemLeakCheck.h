﻿#pragma once

#ifdef WIN32
	#ifdef _DEBUG 
	#define _CRTDBG_MAP_ALLOC 
	#include <stdlib.h> 
	#include <crtdbg.h> 
	#endif 
#endif