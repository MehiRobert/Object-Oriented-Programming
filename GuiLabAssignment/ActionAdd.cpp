#include "ActionAdd.h"

void ActionAdd::executeUndo()
{
	this->repository.removeEvidence(addedEvidence.getID());

}

void ActionAdd::executeRedo()
{
	this->repository.add_Evidence(addedEvidence);
}
