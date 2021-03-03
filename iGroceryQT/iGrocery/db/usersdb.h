#ifndef USERSDB_H
#define USERSDB_H

#include <QVector>
#include <QFile>
#include <QDataStream>

#include "../entities/user.h"

class UsersDB
{
private:
    QVector<User> mUsers;

    UsersDB() = default;

public:
    static const QString FILE_NAME;

    void load(QDataStream &stream);
    void save(QDataStream &stream) const;

    QVector<User> users() const;
    void addUser(User user);
    void removeUser(const User &user);
    QVector<User*> getUsersByType(UserType userType);
    User* getUserByLogin(QString login);

    static UsersDB* createInstance();
    static void saveInstance(const UsersDB &instance);
};

#endif // USERSDB_H
