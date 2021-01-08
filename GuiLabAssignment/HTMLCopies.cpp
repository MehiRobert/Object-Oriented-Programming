#include "HTMLCopies.h"
#include <windows.h>
#include <ShellAPI.h>
#include <fstream>

using namespace std;

void HTMLFile::writeToFile(std::vector<Evidence> evidencecopies)
{
	ofstream file(this->Path);
	
	file << "<!DOCTYPE html>" << endl;
	file << "<html>" << endl;
	file << "<head><title>Evidence Copies</title></head>" << endl;
	file << "<body style=\"background-color:white;\"><table border=\"1\">" << endl;

	file << "<tr>" << endl;
	file << "<td>Id</td>" << endl;
	file << "<td>Measurement</td>" << endl;
	file << "<td>Image Clarity</td>" << endl;
	file << "<td>Quantity</td>" << endl;
	file << "<td>Image</td>" << endl;
	file << "</tr>" << endl;
	for (const auto& evidence : evidencecopies) {
		file << "<tr>" << endl;
		file << "<td>" << evidence.getID() << "</td>" << endl;
		file << "<td>" << evidence.getmeasure() << "</td>" << endl;
		file << "<td>" << evidence.getclarity() << "</td>" << endl;
		file << "<td>" << evidence.getquantity() << "</td>" << endl;
		file << "<td>" << evidence.getIMAGE() << "</td>" << endl;
		file << "</tr>" << endl;
	}
	file << "</table>" << endl;
	file << "</body>" << endl;
	file << "</html>" << endl;
	file.close();
}

void HTMLFile::displayCopies() const
{
	std::string filename = "\"" + this->Path + "\"";
	ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe", filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}

