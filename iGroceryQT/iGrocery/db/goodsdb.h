#ifndef GOODSDB_H
#define GOODSDB_H

#include <QVector>
#include <QFile>
#include <QDataStream>

#include "../entities/good.h"

class GoodsDB
{
private:
    QVector<Good> mGoods;

    GoodsDB() = default;

public:
    static const QString FILE_NAME;

    void load(QDataStream &stream);
    void save(QDataStream &stream) const;

    QVector<Good> goods() const;
    void addGood(Good good);
    void removeGood(const Good &good);

    static GoodsDB* createInstance();
    static void saveInstance(const GoodsDB &instance);
};

#endif // GOODSDB_H
