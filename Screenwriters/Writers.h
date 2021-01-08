#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Writers.h"
#include "Service.h"
#include "TableModel.h"

class Writers : public QMainWindow
{
    Q_OBJECT

public:
    Writers(Service& s,ScreenWriters& writ,TableModel* t,QWidget *parent = Q_NULLPTR);

private:
    Service& serv;
    ScreenWriters& writer;
    TableModel* tabel;
    Ui::WritersClass ui;
};
