#pragma once
#include <iostream>
#include <vector>
#include <sstream>
class ScreenWriters
{
private:
	std::string name;
	std::string expertise;
public:
	ScreenWriters() {};
	ScreenWriters(std::string name, std::string expertise) : name{ name }, expertise{ expertise } {}

	std::string get_name();

	std::string get_expertise();

	void set_name(std::string name);

	void set_expertise(std::string expertise);

	std::vector<std::string> tokenize(std::string input, char separator);

	friend std::istream& operator>>(std::istream& is, ScreenWriters& screenwrit);
};
class Idea
{
private:
	std::string description;
	std::string status;
	std::string creator;
	int act;
public:
	Idea() {};
	Idea(std::string description, std::string status, std::string creator, int act) : description{ description }, status{ status }, creator{ creator }, act{ act } {}

	std::string get_description();

	std::string get_status();

	std::string get_creator();

	int get_act();

	void set_description(std::string desc);

	void set_status(std::string status);

	void set_creator(std::string creator);

	void set_act(int act);

	friend bool operator<(Idea& idea,Idea& idea1);

	std::vector<std::string> tokenize(std::string input, char separator);

	friend std::istream& operator>>(std::istream& is, Idea& idea);

	friend std::ostream& operator<<(std::ostream& os, const Idea& idea);
};