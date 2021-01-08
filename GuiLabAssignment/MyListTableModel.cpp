#include "MyListTableModel.h"

int MyListTableModel::rowCount(const QModelIndex& parent) const
{
	return this->repocopy->getPhysicalCopies().size();
}

int MyListTableModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant MyListTableModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int col = index.column();
	Evidence evd = this->repocopy->getPhysicalCopies()[row];

	if (role == Qt::DisplayRole)
	{
		switch (col)
		{
		case 0:
			return QString::number(evd.getID());
		case 1:
			return QString::fromStdString(evd.getmeasure());
		case 2:
			return QString::number(evd.getclarity());
		case 3:
			return QString::number(evd.getquantity());
		case 4:
			return QString::fromStdString(evd.getIMAGE());
		default:
			break;
		}
	}
	return QVariant();
	
}

QVariant MyListTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString("Id");
			case 1:
				return QString("Measurement");
			case 2:
				return QString("Image clarity");
			case 3:
				return QString("Quantity");
			case 4:
				return QString("Image");
			default:
				break;
			}
		}
	}
	return QVariant();
}

void MyListTableModel::Update()
{
	emit layoutAboutToBeChanged();
	emit layoutChanged();
}
