#pragma once
#include "Evidence.h"
#include "PhysicalCopies.h"
class FilePhysicalCopy: public PhysicalCopies
{
protected:
	std::string Path;
public:
	FilePhysicalCopy() : PhysicalCopies{}, Path{ "" }{};
	virtual ~FilePhysicalCopy() {};
	virtual void writeToFile(std::vector<Evidence> evidencecopies) = 0;
	virtual void displayCopies() const = 0;
	void setFilename(std::string filename);
};
