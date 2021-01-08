#include "Scriitori.h"
using namespace std;
Scriitori::Scriitori(Service& s, ScreenWriters& writ, TableModel* t, QWidget* parent)
	: QWidget(parent), serv(s), writer(writ), tabel(t)
{
	ui.setupUi(this);

	this->setWindowTitle(QString::fromStdString(writer.get_name()));

	this->ui.ScriitoritableView->setModel(tabel);
	this->ui.ScriitoritableView->setSelectionBehavior(QAbstractItemView::SelectRows);

	this->connectSlotsandSignals();
}

Scriitori::~Scriitori()
{
}

void Scriitori::connectSlotsandSignals()
{
	if (writer.get_expertise() != "Senior")
	{
		this->ui.reviseButton->setEnabled(false);
	}
	QObject::connect(this->ui.AddButton, &QPushButton::clicked, this, &Scriitori::add);
	QObject::connect(this->ui.reviseButton, &QPushButton::clicked, this, &Scriitori::revise);
	QObject::connect(this->ui.plotButton, &QPushButton::clicked, this, &Scriitori::save_plot);
}

void Scriitori::add()
{
	std::string description = this->ui.desEdit->text().toStdString();
	int act = this->ui.ActEdit->text().toInt();
	if (description == "")
	{
		QMessageBox::critical(this, "Error", "Description is empty");
		return;
	}
	if (act != 1 && act != 2 && act != 3)
	{
		QMessageBox::critical(this, "Error", "Act should be 1 or 2 or 3");
		return;
	}
	this->serv.add_Idea(description, this->windowTitle().toStdString(), act);
	tabel->Update();
}

void Scriitori::revise()
{
	QModelIndexList indexlist = this->ui.ScriitoritableView->selectionModel()->selectedIndexes();
	QModelIndex index = indexlist.at(0);
	int row = index.row();
	vector<Idea>& vect = this->serv.get_servideas();
	Idea& idea = vect[row];
	if (idea.get_status() == "proposed")
	{
		idea.set_status("accepted");
		tabel->Update();
	}
	else
	{
		QMessageBox::critical(this, "Error", "Status can't be changed because it is already accepted");
		return;
	}
	
	
}

void Scriitori::save_plot()
{
	for (auto& idea : this->serv.get_servideas())
	{
		if (idea.get_status() == "accepted")
		{
			this->serv.write_to_file(idea);
		}
	}
}
