#pragma once
#include "Repo.h"

class Service
{
private:
	RepoIdeas* idearepo;
	RepoScreen reposcreen;
public:
	Service(RepoIdeas* repoi, RepoScreen& repos) : idearepo{ repoi }, reposcreen{ repos } {}

	std::vector<ScreenWriters> get_servwriters();

	std::vector<Idea>& get_servideas();

	void add_Idea(std::string description,std::string creator,int act);

	void write_to_file(Idea& idea);
};