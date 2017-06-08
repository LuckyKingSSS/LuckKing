#include "stdafx.h"
#include "undocommandbase.h"

UndoCommandBase::UndoCommandBase(OperatorBase* pOperator, QObject *parent)
	: QObject(parent)
{

}

UndoCommandBase::~UndoCommandBase()
{

}
