#pragma once

#include <QWidget>
#include "ui_Scriitori.h"
#include "Service.h"
#include "TableModel.h"
#include "qmessagebox.h"
#include "qtextedit.h"

class Scriitori : public QWidget 
{
	Q_OBJECT

public:
	Scriitori(Service& s, ScreenWriters& writ, TableModel* t, QWidget *parent = Q_NULLPTR);
	~Scriitori();

private:
	Service& serv;
	ScreenWriters& writer;
	TableModel* tabel;
	Ui::Scriitori ui;

	void connectSlotsandSignals();

	void add();
	
	void revise();

	void save_plot();
};
