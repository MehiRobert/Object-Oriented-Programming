#pragma once
#include "Evidence.h"
#include "Exception.h"
class ValidateEvidence
{
public:
	void validate(const Evidence& e);
};
class ValidateInput
{
public:
	void validateInput(char* input);
};