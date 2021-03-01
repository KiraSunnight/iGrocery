#include "goodsdb.h"

const QString GoodsDB::FILE_NAME = "goods.bin";

void GoodsDB::load(QDataStream &stream)
{
    stream >> mGoods;
}

void GoodsDB::save(QDataStream &stream) const
{
    stream << mGoods;
}

QVector<Good*> GoodsDB::goods() const
{
    return mGoods;
}

void GoodsDB::addGood(Good good)
{
    mGoods.push_back(&good);
}

void GoodsDB::removeGood(Good &good)
{
    mGoods.removeAll(&good);
}

GoodsDB* GoodsDB::createInstance()
{
    GoodsDB *db = new GoodsDB();

    if (QFile().exists(GoodsDB::FILE_NAME)) {
        QFile f(GoodsDB::FILE_NAME);
        f.open(QIODevice::ReadOnly);
        QDataStream stream(&f);
        db->load(stream);
        f.close();
    }

    return db;
}

void GoodsDB::saveInstance(const GoodsDB &instance)
{
    QFile f(GoodsDB::FILE_NAME);
    f.open(QIODevice::WriteOnly);
    QDataStream stream(&f);
    instance.save(stream);
    f.close();
}
