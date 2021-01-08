#pragma once
#include "Evidence.h"
class PhysicalCopies
{
private:
	std::vector<Evidence> copies;
public:
	void addCopies(Evidence& e);
	std::vector<Evidence> getPhysicalCopies() const;
};