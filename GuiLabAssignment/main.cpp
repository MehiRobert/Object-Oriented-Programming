#include "EvidenceGUI.h"
#include <QtWidgets/QApplication>
#include "FileRepository.h"
#include "Validate.h"
#include "Service.h"
#include "EvidenceGUI.h";
#include "myListGUI.h"
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	FileRepo repo{};
	repo.set_file("Lab9.txt");
	ValidateInput input{};
	PhysicalCopies* repo2 = new PhysicalCopies{};
	Service service{ repo , repo2 };
	string filename;
	fstream file{ "File.txt" };
	getline(file, filename);
	service.set_file_physical(filename);
	MyListTableModel* model1 = new MyListTableModel{ repo2 };
	myListGUI gui1{ model1 };
	EvidenceGUI gui{ service,model1};
	gui.show();
	return a.exec();
}
