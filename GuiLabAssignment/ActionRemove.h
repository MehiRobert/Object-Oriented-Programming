#pragma once
#include "Action.h"
class ActionRemove : public Action 
{
private:
	Evidence removedEvidence;
	FileRepo repository;
public:
	ActionRemove(FileRepo& r,Evidence& evd) : repository(r) , removedEvidence(evd) {}
	void executeUndo() override;
	void executeRedo() override;

};

