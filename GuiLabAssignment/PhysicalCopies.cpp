#include "PhysicalCopies.h"

void PhysicalCopies::addCopies(Evidence& e)
{
	this->copies.push_back(e);
}
std::vector<Evidence> PhysicalCopies::getPhysicalCopies() const
{
	return this->copies;
}