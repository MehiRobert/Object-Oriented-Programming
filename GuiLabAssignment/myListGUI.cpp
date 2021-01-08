#include "myListGUI.h"

myListGUI::myListGUI(MyListTableModel* model, QWidget* parent)
	: QWidget(parent), model{ model }
{
	ui.setupUi(this);

	ui.myListtableView->setModel(this->model);
}

myListGUI::~myListGUI()
{
	
}
