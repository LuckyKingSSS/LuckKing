#pragma once
#include "commonlib_global.h"
class COMMONLIB_EXPORT PathOperation
{
public:
	PathOperation();
	~PathOperation();

	static QString MakeWorkPath(const QString &strSubPath);  //�ڹ���Ŀ¼����ƴ��strSubPath·��

	static QString GetUserSelectDir(QString title,WId wid);
};

