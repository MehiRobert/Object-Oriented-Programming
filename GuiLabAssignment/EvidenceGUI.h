#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EvidenceGUI.h"
#include "myListGUI.h"
#include "MyListTableModel.h"
#include "Service.h"

class EvidenceGUI : public QMainWindow
{
	Q_OBJECT

public:
	EvidenceGUI(Service& s,MyListTableModel* m,QWidget *parent = Q_NULLPTR);

	

private:
	Service& serv;
	MyListTableModel* model;
	myListGUI gui1{ model };
	Ui::EvidenceGUIClass ui;

	void connectSignalsandSlots();

	void populateList();

	void showMylist();

	void populateMylist();

	int getSelectedIndex() const;

	void addEvidence();

	void deleteEvidence();

	void UpdateEvidence();

	void nextEvidence();

	void saveEvidence();

	void specifiedList();

	void undoGUI();

	void redoGUI();
};
