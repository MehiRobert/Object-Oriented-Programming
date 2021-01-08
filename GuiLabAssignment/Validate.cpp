#pragma warning (disable : 4996)
#include "Validate.h"
#include <string>

using namespace std;


void ValidateEvidence::validate(const Evidence& e)
{
	string errors;
	string img = e.getIMAGE();
	if (img.length() < 5)
		errors += "The image format is too short";
	else if (img.substr(img.length() - 4) != ".JPG")
	{
		errors += "The image format needs to be .JPG\n";
	}
	if (errors.size() > 0)
		throw EvidenceException(errors);

	
}

void ValidateInput::validateInput(char* input)
{
	string errors;
	char* copy = strdup(input);
	char* imagequality;
	char* measure;
	char* image;
	char* notgood;
	char* id;
	char* quantity;
	notgood = strtok(copy, " ");
	id = strtok(NULL, " ");
	measure = strtok(NULL, " ");
	imagequality = strtok(NULL, " ");
	quantity = strtok(NULL, " ");
	image = strtok(NULL, " ");
	if (id == NULL || measure == NULL || imagequality == NULL || quantity == NULL || image == NULL)
	{
		errors += "The syntax is too short";
	}
	else
	{
		if (strspn(id, "0123456789") != strlen(id))
		{
			errors += "The id should be an integer\n";
		}
		if (strspn(quantity, "0123456789") != strlen(quantity))
		{
			errors += "The quantity should be an integer\n";
		}
	}
	free(copy);
	if(errors.size() > 0)
		throw InputException(errors);
}
