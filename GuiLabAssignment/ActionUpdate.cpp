#include "ActionUpdate.h"

void ActionUpdate::executeUndo()
{
	this->repository.updateEvidence(oldEvidence);
}

void ActionUpdate::executeRedo()
{
	this->repository.updateEvidence(newEvidence);
}
