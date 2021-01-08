#include "EvidenceGUI.h"
#include <QtWidgets\qmessagebox.h>
#include <QInputDialog>

using namespace std;

EvidenceGUI::EvidenceGUI(Service& s,MyListTableModel* m,QWidget *parent)
	: QMainWindow(parent) , serv(s) , model(m)
{
	ui.setupUi(this);

	this->populateList();

	this->connectSignalsandSlots();

	this->serv.initIterator();
}

void EvidenceGUI::connectSignalsandSlots()
{
	QObject::connect(this->ui.EvidenceListWidget, &QListWidget::itemSelectionChanged, [this]() {
		int selectedIndex = this->getSelectedIndex();

		if (selectedIndex < 0)
			return;
		Evidence e = this->serv.getEvidenceRepo()[selectedIndex];
		this->ui.IdlineEdit->setText(QString::fromStdString(to_string(e.getID())));
		this->ui.MeasurementlineEdit->setText(QString::fromStdString(e.getmeasure()));
		this->ui.ClaritylineEdit->setText(QString::fromStdString(to_string(e.getclarity())));
		this->ui.QuantitylineEdit->setText(QString::fromStdString(to_string(e.getquantity())));
		this->ui.ImagelineEdit->setText(QString::fromStdString(e.getIMAGE()));
		});
	QObject::connect(this->ui.DeleteButton, &QPushButton::clicked, this, &EvidenceGUI::deleteEvidence);
	QObject::connect(this->ui.AddButton, &QPushButton::clicked, this, &EvidenceGUI::addEvidence);
	QObject::connect(this->ui.UpdateButton, &QPushButton::clicked, this, &EvidenceGUI::UpdateEvidence);
	QObject::connect(this->ui.nextButton, &QPushButton::clicked, this, &EvidenceGUI::nextEvidence);
	QObject::connect(this->ui.saveButton, &QPushButton::clicked, this, &EvidenceGUI::saveEvidence);
	QObject::connect(this->ui.SpecifyList, &QPushButton::clicked, this, &EvidenceGUI::specifiedList);
	QObject::connect(this->ui.UndoButton, &QPushButton::clicked, this, &EvidenceGUI::undoGUI);
	QObject::connect(this->ui.redoButton, &QPushButton::clicked, this, &EvidenceGUI::redoGUI);
	QObject::connect(this->ui.mylistButton, &QPushButton::clicked, this, &EvidenceGUI::showMylist);
}

void EvidenceGUI::populateList()
{
	this->ui.EvidenceListWidget->clear();

	vector<Evidence> allEvidence = this->serv.getEvidenceRepo();
	for (auto& s : allEvidence)
		this->ui.EvidenceListWidget->addItem(QString::fromStdString(to_string(s.getID())) + " - " + QString::fromStdString(s.getmeasure()) + " - "
			+ QString::fromStdString(to_string(s.getclarity())) + " - " + QString::fromStdString(to_string(s.getquantity())) + " - " + QString::fromStdString(s.getIMAGE()));
}
void EvidenceGUI::showMylist()
{
	this->model->Update();
	gui1.show();
}
int EvidenceGUI::getSelectedIndex() const
{
	QModelIndexList selectedIndexes = this->ui.EvidenceListWidget->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		this->ui.IdlineEdit->clear();
		this->ui.MeasurementlineEdit->clear();
		this->ui.ClaritylineEdit->clear();
		this->ui.QuantitylineEdit->clear();
		this->ui.ImagelineEdit->clear();
		return -1;
	}

	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}
void EvidenceGUI::addEvidence()
{
	int id = this->ui.IdlineEdit->text().toInt();
	string measurement = this->ui.MeasurementlineEdit->text().toStdString();
	double imageclarity = this->ui.ClaritylineEdit->text().toDouble();
	int quantity = this->ui.QuantitylineEdit->text().toInt();
	string image = this->ui.ImagelineEdit->text().toStdString();
	try {
		this->serv.addEvidenceServ(id, measurement, imageclarity, quantity, image);
	}
	catch (RepositoryException& r)
	{
		QMessageBox::critical(this, "Error", r.getMessage().c_str());
	}
	catch (EvidenceException& e)
	{
		QMessageBox::critical(this, "Error", e.getMessage().c_str());
	}
	this->populateList();
	int lastElement = this->serv.getEvidenceRepo().size() - 1;
	this->ui.EvidenceListWidget->setCurrentRow(lastElement);


}
void EvidenceGUI::deleteEvidence()
{
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No evidence was selected to be removed!");
		return;
	}

	Evidence e = this->serv.getEvidenceRepo()[selectedIndex];
	this->serv.removeEvidenceServ(e.getID());
	this->populateList();
}
void EvidenceGUI::UpdateEvidence()
{
	int selectedIndex = this->getSelectedIndex();

	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No evidence was selected to be updated!");
		return;
	}
	Evidence e = this->serv.getEvidenceRepo()[selectedIndex];
	string measurement = this->ui.MeasurementlineEdit->text().toStdString();
	double imageclarity = this->ui.ClaritylineEdit->text().toDouble();
	int quantity = this->ui.QuantitylineEdit->text().toInt();
	string image = this->ui.ImagelineEdit->text().toStdString();
	this->serv.updateEvidenceServ(e.getID(), measurement, imageclarity, quantity, image);
	this->populateList();
	

}

void EvidenceGUI::nextEvidence()
{
	vector<Evidence>::iterator it = this->serv.next();
	this->ui.EvidenceListWidget->setCurrentRow((this->serv.getPosbyID((*it).getID())));
}

void EvidenceGUI::saveEvidence()
{
	/*vector<Evidence>::iterator it = this->serv.getIT();*/
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No evidence was selected to be saved!");
		return;
	}
	Evidence e = this->serv.getEvidenceRepo()[selectedIndex];
	this->serv.addPhysicalCopy(e);
	this->model->Update();
	
	
}

void EvidenceGUI::specifiedList()
{
	QMessageBox Msgbox;
	string text;
	int sum;
	QString measurement = QInputDialog::getText(this, "Specified List", "Measurement");
	QString quantitytext = QInputDialog::getText(this, "Specified List", "Quantity");
	string measure = measurement.toStdString();
	int quantity = quantitytext.toInt();
	vector<Evidence> evlist = this->serv.getEvidenceRepo();
	for (int i = 0; i < evlist.size(); i++)
	{
		Evidence e = evlist.at(i);
		if (e.getmeasure() == measure && e.getquantity() >= quantity)
		{
			text += e.toString();
			
		}
	}
	QString str = QString::fromStdString(text);
	Msgbox.setText(str);
	if (str == NULL)
		Msgbox.setText("No match for the specified list");
	Msgbox.exec();
}

void EvidenceGUI::undoGUI()
{
	try {
		this->serv.undo();
	}
	catch (UndoException& und)
	{
		QMessageBox::critical(this,"Error", und.getMessage().c_str());
	}
	this->populateList();
}

void EvidenceGUI::redoGUI()
{
	try {
		this->serv.redo();
	}
	catch (RedoException& redo)
	{
		QMessageBox::critical(this, "Error", redo.getMessage().c_str());
	}
	this->populateList();
}
