#pragma once
#include "Evidence.h"
#include "Exception.h"
#include "PhysicalCopies.h"
#include <vector>
#include <iostream>

class FileRepo
{
private:
	std::string Path;
	std::vector<Evidence> load_evidence(std::string path);
	std::vector<Evidence>::iterator it;
	void save_evidence(std::vector<Evidence> ev , std::string path);
public:
	FileRepo();
	void add_Evidence(const Evidence& e);
	void set_file(const char* path);
	int checkbyID(int id);
	void removeEvidence(int id);
	void updateEvidence(Evidence e);
	std::vector<Evidence> get_Evidence() ;
	friend class PhysicalCopies;


};

