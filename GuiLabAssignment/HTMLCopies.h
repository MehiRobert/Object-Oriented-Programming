#pragma once
#include "FilePhysicalCopies.h"
class HTMLFile: public FilePhysicalCopy
{
	void writeToFile(std::vector<Evidence> evidencecopies) override;
	void displayCopies() const override;
};