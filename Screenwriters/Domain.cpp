#include "Domain.h"
using namespace std;
std::string ScreenWriters::get_name()
{
	return this->name;
}

std::string ScreenWriters::get_expertise()
{
	return this->expertise;
}

void ScreenWriters::set_name(std::string name)
{
	this->name = name;
}

void ScreenWriters::set_expertise(std::string expertise)
{
	this->expertise = expertise;
}

std::vector<std::string> ScreenWriters::tokenize(std::string input, char separator)
{
	vector<string> result;
	stringstream ss(input);
	std::string token;
	while (getline(ss, token, separator))
		result.push_back(token);
	return result;
}

std::istream& operator>>(std::istream& is, ScreenWriters& screenwrit)
{
	std::string line{};
	getline(is, line);

	std::vector<std::string> tokens = screenwrit.tokenize(line, '|');

	if (tokens.size() != 2)
	{
		return is;
	}
	screenwrit.set_name(tokens.at(0));
	screenwrit.set_expertise(tokens.at(1));
	return is;
}

bool operator<(Idea& idea,Idea& idea1)
{
	return (idea.get_act() < idea1.get_act());
}

std::istream& operator>>(std::istream& is, Idea& idea)
{
	std::string line{};
	getline(is, line);

	std::vector<std::string> tokens = idea.tokenize(line, '|');

	if (tokens.size() != 4)
	{
		return is;
	}
	idea.set_description(tokens.at(0));
	idea.set_status(tokens.at(1));
	idea.set_creator(tokens.at(2));
	idea.set_act(stoi(tokens.at(3)));
	return is;
}

std::ostream& operator<<(std::ostream& os, const Idea& idea)
{
	os << idea.act << "-" << " (" << idea.creator << ") " << idea.description << "\n";
	return os;
}

std::string Idea::get_description()
{
	return this->description;
}

std::string Idea::get_status()
{
	return this->status;
}

std::string Idea::get_creator()
{
	return this->creator;
}

int Idea::get_act()
{
	return this->act;
}

void Idea::set_description(std::string desc)
{
	this->description = desc;
}

void Idea::set_status(std::string status)
{
	this->status = status;
}

void Idea::set_creator(std::string creator)
{
	this->creator = creator;
}

void Idea::set_act(int act)
{
	this->act = act;
}

std::vector<std::string> Idea::tokenize(std::string input, char separator)
{
	vector<string> result;
	stringstream ss(input);
	std::string token;
	while (getline(ss, token, separator))
		result.push_back(token);
	return result;
}
