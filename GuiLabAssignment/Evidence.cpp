#include "Evidence.h"
#include <Windows.h>
#include <shellapi.h>
#include <string>
#include <stdlib.h>

using namespace std;

Evidence::Evidence() : id(0) , measurement(""), imageclaritylevel(0.0), quantity(0),image("")
{

}

Evidence::Evidence(int id, const string& measurement, double imageclaritylevel, int quantity, const std::string& image)
{
	this->id = id;
	this->measurement = measurement;
	this->imageclaritylevel = imageclaritylevel;
	this->quantity = quantity;
	this->image = image;
}

string Evidence::toString()
{
	return "\nID:" + std::to_string(this->getID()) + "\nMeasure: " + this->getmeasure()+ "\nImageClarity: " + std::to_string(this->getclarity()) + "\nQuantity: " + std::to_string(this->getquantity()) + "\nImage: " + this->getIMAGE() +"\n";
}

void Evidence::setID(int id)
{
	this->id = id;
}

void Evidence::setmeasure(const string& newmeasure)
{
	this->measurement = newmeasure;
}

void Evidence::setclarity(double newimageclarity)
{
	this->imageclaritylevel = newimageclarity;
}

void Evidence::setquantity(int newquantity)
{
	this->quantity = newquantity;
}

void Evidence::setImage(const string& newimage)
{
	this->image = newimage;
}

void Evidence::reset_evidence()
{
	this->id = 0;
	this->measurement = "";
	this->imageclaritylevel = 0.0;
	this->quantity = 0;
	this->image = "";
}

vector<string> Evidence::tokenize(string input , char separator)
{
	vector<string> result;
	stringstream ss(input);
	std::string token;
	while (getline(ss, token, separator))
		result.push_back(token);
	return result;
}

bool operator==(const Evidence& e1, const Evidence& e2)
{
	return {
			e1.getID() == e2.getID() && e1.getclarity() == e2.getclarity() && e1.getIMAGE() == e2.getIMAGE() && e1.getmeasure() == e2.getmeasure() &&
			e1.getquantity() == e2.getquantity()
	};

}

bool operator!=(const Evidence& e1, const Evidence& e2)
{
	return
	{
		e1.getID() != e2.getID()
	};
}

std::istream& operator>>(std::istream& is, Evidence& evidence)
{
	evidence.reset_evidence();

	std::string line{};
	getline(is, line);

	std::vector<std::string> tokens = evidence.tokenize(line, ',');
	if (tokens.size() != 5)
		return is;
	evidence.setID(stoi(tokens.at(0)));
	evidence.setmeasure(tokens.at(1));
	const char* newtoken = tokens.at(2).c_str();
	evidence.setclarity(atof(newtoken));
	evidence.setquantity(stoi(tokens.at(3)));
	evidence.setImage(tokens.at(4));

	return is;
}

std::ostream& operator<<(std::ostream& os, const Evidence& evidence)
{
	os << evidence.getID() << "," << evidence.getmeasure() << "," << evidence.getclarity() << "," << evidence.getquantity() << "," << evidence.getIMAGE() << "\n";
	return os;
}




