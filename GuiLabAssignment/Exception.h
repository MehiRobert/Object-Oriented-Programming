#pragma once
#include <exception>
#include <string>
#include "Evidence.h"

class RepositoryException
{
private:
	std::string message;
public:
	RepositoryException(std::string message) : message(message) {};
	std::string getMessage() { return this->message; };
};
class EvidenceException
{
private:
	std::string message;
public:
	EvidenceException(std::string message) : message(message) {};
	std::string getMessage() { return this->message; };
	
};
class InputException
{
private:
	std::string message;
public:
	InputException(std::string message) : message(message) {};
	std::string getMessage() { return this->message; };
};
class UndoException
{
private:
	std::string message;
public:
	UndoException(std::string message) : message(message) {};
	std::string getMessage() { return this->message; };


};
class RedoException
{
private:
	std::string message;
public:
	RedoException(std::string message) : message(message) {};
	std::string getMessage() { return this->message; };


};