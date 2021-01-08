#include "Service.h"
using namespace std;
std::vector<ScreenWriters> Service::get_servwriters()
{
	return this->reposcreen.get_writers();
}

std::vector<Idea>& Service::get_servideas()
{
	return this->idearepo->get_ideas();
}

void Service::add_Idea(std::string description, std::string creator, int act)
{
	Idea idea{ description,"proposed",creator,act };
	this->idearepo->Add(idea);

}

void Service::write_to_file(Idea& idea)
{
	ofstream file{ "Plot.txt" };
	for (const auto& idea : this->idearepo->get_ideas())
		file << idea;
	file.close();

}

