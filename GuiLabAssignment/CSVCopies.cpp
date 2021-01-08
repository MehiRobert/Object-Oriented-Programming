#include "CSVCopies.h"
#include <sstream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <ShellAPI.h>


using namespace std;
void CsvFile::writeToFile(vector<Evidence> evidencecopies)
{
	ofstream file{ this->Path };
	for (const auto& evidence : evidencecopies)
		file << evidence;
	file.close();
}

void CsvFile::displayCopies() const
{
	std::string filename = "\"" + this->Path + "\"";
	ShellExecuteA(NULL, NULL, "C:\\WINDOWS\\system32\\notepad.exe", filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}
