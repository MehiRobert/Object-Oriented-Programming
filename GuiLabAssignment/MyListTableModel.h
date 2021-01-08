#pragma once
#include <qabstractitemmodel.h>
#include <qheaderview.h>
#include "PhysicalCopies.h"
using namespace std;
class MyListTableModel : public QAbstractTableModel
{
private:
	PhysicalCopies* repocopy;

public:
	MyListTableModel(PhysicalCopies* rp) : repocopy(rp) {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const;

	int columnCount(const QModelIndex& parent = QModelIndex()) const;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

	QVariant headerData(int section, Qt::Orientation orientation, int role) const;

	void Update();

};

