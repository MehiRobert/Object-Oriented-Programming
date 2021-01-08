#pragma once
#include <qtableview.h>
#include <qheaderview.h>
#include "Repo.h"

class TableModel : public QAbstractTableModel
{
private:
	RepoIdeas* repo;
public:
	TableModel(RepoIdeas* r) : repo{r} {}
	int rowCount(const QModelIndex& parent = QModelIndex()) const;

	int columnCount(const QModelIndex& parent = QModelIndex()) const;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

	QVariant headerData(int section, Qt::Orientation orientation, int role) const;

	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);

	Qt::ItemFlags flags(const QModelIndex& index) const;

	void Update();
};