#pragma once
#include "Evidence.h"
#include "FileRepository.h"
class Action
{
public:
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
};