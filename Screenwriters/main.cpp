#include "Writers.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "TableModel.h"
#include "Scriitori.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RepoScreen repos{"scriitori.txt"};
    RepoIdeas* repoi = new RepoIdeas{"idei.txt"};
    Service serv{ repoi,repos };
    TableModel* t = new TableModel(repoi);
    for (auto& writ : serv.get_servwriters())
    {
        Scriitori* s = new Scriitori(serv, writ, t);
        s->show();
    }
    return a.exec();
}
