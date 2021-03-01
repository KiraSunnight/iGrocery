#include "goodsviewmodel.h"

GoodsViewModel::GoodsViewModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

int GoodsViewModel::rowCount(const QModelIndex &/*parent*/) const
{
    return mGoods.length();
}

int GoodsViewModel::columnCount(const QModelIndex &/*parent*/) const
{
    return 4;
}

QVariant GoodsViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0:
            return QString("Название");
        case 1:
            return QString("Поставщик");
        case 2:
            return QString("Номер полки");
        case 3:
            return QString("Количество на складе");
        }
    }
    return QVariant();
}

QVariant GoodsViewModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        Good *good = mGoods[index.row()];

        int col = index.column();
        switch (col) {
        case 0:
            return good->name();
        case 1:
            return good->providerName();
        case 2:
            return good->shelfNumber();
        case 3:
            return good->amountInStorage();
        }
    }
    return QVariant();
}

Good* GoodsViewModel::getGoodAt(int idx)
{
    return mGoods[idx];
}

void GoodsViewModel::setProvider(GoodsDB *goodsDB)
{
    mGoodsDB = goodsDB;
    invalidateData();
}

void GoodsViewModel::invalidateData()
{
    beginResetModel();
    mGoods.clear();
    foreach (auto good, mGoodsDB->goods())
    {
        mGoods.push_back(new Good(good));
    }
    endResetModel();
}
