#pragma once
#include "FileRepository.h"
#include "CSVCopies.h"
#include "FilePhysicalCopies.h"
#include "HTMLCopies.h"
#include "Validate.h"
#include "Action.h"
#include "ActionAdd.h"
#include "ActionRemove.h"
#include "ActionUpdate.h"
class Service
{
private:
	std::vector<Evidence>::iterator it;
	std::vector<Evidence> next_evidence;
	PhysicalCopies* repo2;
	FilePhysicalCopy* mylistrepo;
	FileRepo repo;
	std::vector<std::unique_ptr<Action>> undo_stack;
	std::vector<std::unique_ptr<Action>> redo_stack;
public:
	Service(FileRepo& r, PhysicalCopies* r2) : repo{ r }, repo2{ r2 } {this->mylistrepo = nullptr; }

	std::vector<Evidence> getEvidenceRepo() ;

	void addEvidenceServ( int id, const std::string& measurement,double imagequality, int quantity,const std::string& image);

	void removeEvidenceServ(int id);

	void updateEvidenceServ(int id,const std::string& newmeasure, double newimagequality, int newquantity,const std::string& newimage);

	void addPhysicalCopy(Evidence e);
	
	std::vector<Evidence> getPhysicalRepo() const;

	void serv_savebyP(int id);

	void serv_set_file(const char* filename);

	void set_file_physical(std::string& filename1);

	void undo();

	void redo();

	void serv_display();

	void initIterator();

	int getPosbyID(int id);

	std::vector<Evidence>::iterator next();

	std::vector<Evidence>::iterator getIT();


};