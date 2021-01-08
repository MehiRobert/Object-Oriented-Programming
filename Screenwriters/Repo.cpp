#include "Repo.h"
using namespace std;
RepoScreen::RepoScreen(std::string path)
{
	this->path = path;
	this->load_writers();
}

void RepoScreen::load_writers()
{
	ifstream file{ this->path };
	ScreenWriters writer;
	while (file >> writer)
	{
		this->writers.push_back(writer);
	}
}

vector<ScreenWriters> RepoScreen::get_writers()
{
	return this->writers;
}

RepoIdeas::RepoIdeas(std::string path)
{
	this->path = path;
	this->load_ideas();
}

void RepoIdeas::load_ideas()
{
	ifstream file{ this->path };
	Idea idea;
	while (file >> idea)
	{
		this->ideas.push_back(idea);
	}
}

std::vector<Idea>& RepoIdeas::get_ideas()
{
	return this->ideas;
}

void RepoIdeas::Add(Idea& idea)
{
	this->ideas.push_back(idea);
}
