#include "FileRepository.h"
#include <sstream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>

using namespace std;
FileRepo::FileRepo() {}
std::vector<Evidence> FileRepo::load_evidence(string path)
{
	ifstream file{path};
	vector<Evidence> evd;
	Evidence(e);
	while (file >> e)
	{
		evd.push_back(e);
	}
	file.close();

	return evd;
}
void FileRepo::save_evidence(vector<Evidence> evidences , string path)
{
	ofstream file{ path };
	for (const auto& evidence : evidences)
		file << evidence;
	file.close();
	evidences.clear();
}
void FileRepo::add_Evidence(const Evidence& e)
{
	vector<Evidence> evidence = this->load_evidence(this->Path);
	if (checkbyID(e.getID()) != -1)
		throw RepositoryException("Object with this id exists already!");
	evidence.push_back(e);
	save_evidence(evidence , this->Path);
}
void FileRepo::set_file(const char* path)
{
	this->Path = path;
}

int FileRepo::checkbyID(int id)
{
	int cnt = 0;
	vector<Evidence> evidence = this->load_evidence(this->Path);
	for (const auto& ev : evidence)
	{

		if (ev.getID() == id) 
			return cnt;
		cnt++;
	}
	return -1;
}

void FileRepo::removeEvidence(int id)
{
	int pos = 0;
	vector<Evidence> evidence = this->load_evidence(this->Path);
	pos = checkbyID(id);
	if (pos == -1)
		throw RepositoryException("Object with this id doesn't exist!");
	evidence.erase(evidence.begin() + pos);
	save_evidence(evidence,this->Path);
}

void FileRepo::updateEvidence(Evidence e)
{
	int pos = checkbyID(e.getID());
	vector<Evidence> evidence = this->load_evidence(this->Path);
	if (pos == -1)
		throw RepositoryException("Object with this id doesn't exist!");
	evidence.at(pos) = e;
	save_evidence(evidence , this->Path);
	
}

vector<Evidence> FileRepo::get_Evidence() 
{
	vector<Evidence> evidence = this->load_evidence(this->Path);
	return evidence;
}