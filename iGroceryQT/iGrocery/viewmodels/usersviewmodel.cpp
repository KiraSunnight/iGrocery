#include "usersviewmodel.h"

UsersViewModel::UsersViewModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

int UsersViewModel::rowCount(const QModelIndex &/*parent*/) const
{
    return mUsers.length();
}

int UsersViewModel::columnCount(const QModelIndex &/*parent*/) const
{
    return 3;
}

QVariant UsersViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0:
            return QString("Полное имя");
        case 1:
            return QString("Логин");
        case 2:
            return QString("Тип аккаунта");
        }
    }
    return QVariant();
}

QVariant UsersViewModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        auto usr = mUsers[index.row()];

        int col = index.column();
        switch (col) {
        case 0:
            return usr->fullName();
        case 1:
            return usr->login();
        case 2:
            return usr->userType() == UserType::MANAGER? "Менеджер" : "Продваец";
        }
    }
    return QVariant();
}

User *UsersViewModel::getUserAt(int idx)
{
    return mUsers[idx];
}

void UsersViewModel::setProvider(UsersDB *usersDB)
{
    mUsersDB = usersDB;
    invalidateData();
}

void UsersViewModel::invalidateData()
{
    beginResetModel();
    mUsers.clear();
    mUsers += mUsersDB->getUsersByType(UserType::MANAGER);
    mUsers += mUsersDB->getUsersByType(UserType::WORKER);
    endResetModel();
}
