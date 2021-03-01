#ifndef GOOD_H
#define GOOD_H

#include <QString>
#include <QDataStream>

class Good
{
private:
    QString mName;
    int mAmountInStorage = 0;
    int mShelfNumber = -1;
    QString mProviderName;

public:
    Good() = default;
    Good(QString name, int amountInStorage, int shelfNumber, QString providerName);
    QString name() const;
    void setName(const QString &name);
    int amountInStorage() const;
    void setAmountInStorage(int amountInStorage);
    int shelfNumber() const;
    void setShelfNumber(int shelfNumber);
    QString providerName() const;
    void setProviderName(const QString &providerName);

    friend bool operator==(const Good &l, const Good &r);
    friend QDataStream& operator<<(QDataStream &stream, const Good &good);
    friend QDataStream& operator>>(QDataStream &stream, Good &good);
};

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

#endif // GOOD_H
