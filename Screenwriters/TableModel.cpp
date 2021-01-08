#include "TableModel.h"
using namespace std;
int TableModel::rowCount(const QModelIndex& parent) const
{
	return this->repo->get_ideas().size();
}

int TableModel::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant TableModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int col = index.column();
	vector<Idea>& vect = this->repo->get_ideas();
	std::sort(vect.begin(), vect.end());
	Idea idea = vect[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (col)
		{
		case 0:
			return QString::fromStdString(idea.get_description());
		case 1:
			return QString::fromStdString(idea.get_status());
		case 2:
			return QString::fromStdString(idea.get_creator());
		case 3:
			return QString::number(idea.get_act());
		default:
			break;
		}
	}
	return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString("Description");
			case 1:
				return QString("Status");
			case 2:
				return QString("Creator");
			case 3:
				return QString("Act");
			default:
				break;
			}
		}
	}
	return QVariant();
}

bool TableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (role != Qt::EditRole)
		return false;

	int row = index.row();
	int col = index.column();
	Idea& currentIdea = this->repo->get_ideas()[row];

	switch (col)
	{
	case 0:
		break;
	case 1:
		currentIdea.set_status(value.toString().toStdString());
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
	emit dataChanged(index, index);
	return true;
	
}

Qt::ItemFlags TableModel::flags(const QModelIndex& index) const
{
	int col = index.column();
	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void TableModel::Update()
{
	emit layoutAboutToBeChanged();
	emit layoutChanged();
}
