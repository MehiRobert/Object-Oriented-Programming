#pragma once
#include "Domain.h"
#include <fstream>
class RepoScreen
{
private:
	std::vector<ScreenWriters> writers;
	std::string path;
public:
	RepoScreen() {};
	RepoScreen(std::string path);

	void load_writers();

	std::vector<ScreenWriters> get_writers();
};
class RepoIdeas
{
private:
	std::vector<Idea> ideas;
	std::string path;
public:
	RepoIdeas() {};
	RepoIdeas(std::string path);

	void load_ideas();

	std::vector<Idea>& get_ideas();

	void Add(Idea& idea);
};