#pragma once
#include "Action.h"
class ActionAdd : public Action
{
private:
	Evidence addedEvidence;
	FileRepo repository;
public:
	ActionAdd(FileRepo& repo,Evidence& evd) : repository(repo) , addedEvidence(evd) {}
	void executeUndo() override;
	void executeRedo() override;

};

