#ifndef GOODSVIEWMODEL_H
#define GOODSVIEWMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QFont>

#include "../db/goodsdb.h"

class GoodsViewModel : public QAbstractTableModel
{
    Q_OBJECT

    QVector<Good*> mGoods;
    GoodsDB *mGoodsDB;

public:
    GoodsViewModel(QObject *parent);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    Good* getGoodAt(int idx);
    void setProvider(GoodsDB *goodsDB);
    void invalidateData();
};

#endif // GOODSVIEWMODEL_H
