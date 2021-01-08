#include "ActionRemove.h"

void ActionRemove::executeUndo()
{
	this->repository.add_Evidence(removedEvidence);
}

void ActionRemove::executeRedo()
{
	this->repository.removeEvidence(removedEvidence.getID());
}
