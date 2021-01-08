#include "Service.h"
#include <iterator>
using namespace std;

vector<Evidence> Service::getEvidenceRepo() 
{
	return this->repo.get_Evidence();
}

void Service::addEvidenceServ(int id, const string &measurement,double imagequality,int quantity,const string &image)
{
	
	Evidence e{id,measurement,imagequality,quantity,image};
	ValidateEvidence evd;
	evd.validate(e);
	this->repo.add_Evidence(e);
	unique_ptr<Action> act = make_unique<ActionAdd>(this->repo,e);
	this->undo_stack.push_back(move(act));
	
}

void Service::removeEvidenceServ(int id)
{
	int result;
	vector<Evidence> arr = this->repo.get_Evidence();
	result = this->repo.checkbyID(id);
	if (result != -1)
	{
		Evidence e = arr.at(result);
		unique_ptr<Action> act = make_unique<ActionRemove>(this->repo, e);
		this->undo_stack.push_back(move(act));
	}
	this->repo.removeEvidence(id);
	
}

void Service::updateEvidenceServ(int id,const string& newmeasure, double newimagequality, int newquantity, const string& newimage)
{
	int result = 0;
	Evidence newe{ id,newmeasure,newimagequality,newquantity,newimage };
	vector<Evidence> arr = this->repo.get_Evidence();
	result = this->repo.checkbyID(id);
	if (result != -1)
	{
		Evidence oldevd = arr.at(result);
		unique_ptr<Action> act = make_unique<ActionUpdate>(this->repo, newe,oldevd);
		this->undo_stack.push_back(move(act));
		this->repo.updateEvidence(newe);
	}
}

void Service::addPhysicalCopy(Evidence e)
{
	this->repo2->addCopies(e); 
	this->mylistrepo->writeToFile(this->getPhysicalRepo());
}
vector<Evidence> Service::getPhysicalRepo() const
{
	return this->repo2->getPhysicalCopies();
}

void Service::serv_savebyP(int id)
{
	int result = 0;
	vector<Evidence> arr = this->repo.get_Evidence();
	result = this->repo.checkbyID(id);
	if (result != -1)
	{
		Evidence e = arr.at(result);
		this->repo2->addCopies(e);
		this->mylistrepo->writeToFile(this->getPhysicalRepo());

	}
}

void Service::serv_set_file(const char* filename)
{
	this->repo.set_file(filename);
}

void Service::set_file_physical(std::string& filename1)
{
	if (filename1.substr(filename1.length() - 5) == ".html")
		this->mylistrepo = new HTMLFile{};
	else if(filename1.substr(filename1.length() - 4) == ".csv")
		this->mylistrepo = new CsvFile{};
	this->mylistrepo->setFilename(filename1);
}

void Service::undo()
{
	if (this->undo_stack.size() == 0)
	{
		throw UndoException("No more undos");
	}
	unique_ptr<Action> lastAct = move(this->undo_stack.back());
	lastAct->executeUndo();
	this->redo_stack.push_back(move(lastAct));
	this->undo_stack.pop_back();
}

void Service::redo()
{
	if (this->redo_stack.size() == 0)
	{
		throw RedoException("No more redos");
	}
	unique_ptr<Action> lastAct = move(this->redo_stack.back());
	lastAct->executeRedo();
	this->undo_stack.push_back(move(lastAct));
	this->redo_stack.pop_back();
}

void Service::serv_display()
{
	this->mylistrepo->displayCopies();
}

void Service::initIterator()
{
	next_evidence = this->getEvidenceRepo();
	this->it = next_evidence.end();
}

int Service::getPosbyID(int id)
{
	int result = 0;
	result = this->repo.checkbyID(id);
	return result;
}

vector<Evidence>::iterator Service::next()
{
	if (it != next_evidence.end())
		++it;
	if (it == next_evidence.end())
		it = next_evidence.begin();
	return it;
}
vector<Evidence>::iterator Service::getIT()
{
	return it;
}


