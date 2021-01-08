#pragma once

#include <QWidget>
#include "ui_myListGUI.h"
#include "MyListTableModel.h"

class myListGUI : public QWidget
{
	Q_OBJECT

public:
	myListGUI(MyListTableModel* model,QWidget *parent = Q_NULLPTR);
	~myListGUI();

private:
	Ui::myListGUI ui;
	MyListTableModel* model;
};
