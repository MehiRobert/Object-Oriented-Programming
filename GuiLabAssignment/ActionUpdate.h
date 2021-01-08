#pragma once
#include "Action.h"
class ActionUpdate : public Action
{
private:
	Evidence newEvidence;
	Evidence oldEvidence;
	FileRepo repository;
public:
	ActionUpdate(FileRepo& r,Evidence& newevd,Evidence& oldevd) : repository(r) , newEvidence(newevd) , oldEvidence(oldevd) {}
	void executeUndo() override;
	void executeRedo() override;
};

