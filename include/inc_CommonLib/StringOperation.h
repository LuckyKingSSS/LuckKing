#pragma once
#include "commonlib_global.h"
class COMMONLIB_EXPORT StringOperation
{
public:
	StringOperation();
	~StringOperation();

	static QString GetElidedString(QFont font, int len, const QString &text);
	static int GetTextTrueLenght(QFont font, const QString &text);
};

