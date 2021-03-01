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

#endif // GOOD_H
