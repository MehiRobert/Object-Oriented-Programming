#include "Writers.h"

Writers::Writers(Service& s, ScreenWriters& writ, TableModel* t,QWidget *parent)
    : QMainWindow(parent) , serv(s) , writer(writ) , tabel(t)
{
    ui.setupUi(this);

    this->ui.WriterstableView->setModel(t);
}
