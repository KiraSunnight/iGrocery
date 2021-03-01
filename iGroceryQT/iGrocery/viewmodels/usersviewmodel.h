#ifndef USERSVIEWMODEL_H
#define USERSVIEWMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QFont>

#include "../db/usersdb.h"

class UsersViewModel : public QAbstractTableModel
{
    Q_OBJECT

    QVector<User*> mUsers;
    UsersDB *mUsersDB;

public:
    UsersViewModel(QObject *parent);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    User* getUserAt(int idx);
    void setProvider(UsersDB *usersDB);
    void invalidateData();
};

#endif // USERSVIEWMODEL_H
