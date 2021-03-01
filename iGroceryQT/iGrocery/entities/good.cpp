#include "good.h"

bool operator==(const Good &l, const Good &r)
{
    return l.mName == r.mName && l.mAmountInStorage == r.mAmountInStorage
            && l.mShelfNumber == r.mShelfNumber && l.mProviderName == r.mShelfNumber;
}

QDataStream& operator<<(QDataStream &stream, const Good &good)
{
    stream << good.mName << good.mAmountInStorage << good.mShelfNumber << good.mProviderName;
    return stream;
}

QDataStream& operator>>(QDataStream &stream, Good &good)
{
    stream >> good.mName >> good.mAmountInStorage >> good.mShelfNumber >> good.mProviderName;
    return stream;
}

Good::Good(QString name, int amountInStorage, int shelfNumber, QString providerName)
    : mName(name), mAmountInStorage(amountInStorage), mShelfNumber(shelfNumber), mProviderName(providerName)
{

}

QString Good::name() const
{
    return mName;
}

void Good::setName(const QString &name)
{
    mName = name;
}

int Good::amountInStorage() const
{
    return mAmountInStorage;
}

void Good::setAmountInStorage(int amountInStorage)
{
    mAmountInStorage = amountInStorage;
}

int Good::shelfNumber() const
{
    return mShelfNumber;
}

void Good::setShelfNumber(int shelfNumber)
{
    mShelfNumber = shelfNumber;
}

QString Good::providerName() const
{
    return mProviderName;
}

void Good::setProviderName(const QString &providerName)
{
    mProviderName = providerName;
}
