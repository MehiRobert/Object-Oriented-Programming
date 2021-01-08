#pragma once
#include <iostream>
#include <vector>
#include <sstream>

class Evidence
{
private:
	int id, quantity;
	std::string image;
	std::string measurement;
	double imageclaritylevel;
public:
	Evidence();
	//Constructor with parameteres
	Evidence(int id, const std::string& measurement, double imageclaritylevel, int quantity, const std::string& image);

	int getID() const { return id; }

	std::string getmeasure() const { return measurement; }

	double getclarity() const { return imageclaritylevel; }

	int getquantity() const { return quantity; }

	std::string getIMAGE() const { return image; }

	std::string toString();

	void setID(int id);

	void setmeasure(const std::string& newmeasure);

	void setclarity(double newimageclarity);

	void setquantity(int newquantity);

	void setImage(const std::string& newimage);

	void reset_evidence();

	std::vector<std::string> tokenize(std::string input, char separator);

	friend bool operator==(const Evidence& e1, const Evidence& e2);

	friend bool operator!=(const Evidence& e1, const Evidence& e2);
	 
	friend std::istream& operator>>(std::istream& is, Evidence& evidence);

	friend std::ostream& operator<<(std::ostream& os, const Evidence& evidence);    


};