#include "usersdb.h"

const QString UsersDB::FILE_NAME = "users.bin";

void UsersDB::load(QDataStream &stream)
{
    stream >> mUsers;
}

void UsersDB::save(QDataStream &stream) const
{
    stream << mUsers;
}

QVector<User> UsersDB::users() const
{
    return mUsers;
}

void UsersDB::addUser(User user)
{
    if (mUsers.contains(user))
    {
        throw std::invalid_argument("User already exists!");
    }

    mUsers.push_back(user);
}

void UsersDB::removeUser(const User &user)
{
    mUsers.removeAll(user);
}

QVector<User*> UsersDB::getUsersByType(UserType userType)
{
    QVector<User*> out;

    auto it = mUsers.begin();
    while (it != mUsers.end())
    {
        it = std::find_if(it, mUsers.end(), [userType](const User &user) {
            return user.userType() == userType;
        });
        if (it != mUsers.end())
        {
            out.push_back(it++);
        }
    }

    return out;
}

User *UsersDB::getUserByLogin(QString login)
{
    auto it = std::find_if(mUsers.begin(), mUsers.end(), [login](const User &user) {
        return user.login() == login;
    });

    return it == mUsers.end()? nullptr : it;
}

UsersDB* UsersDB::createInstance()
{
    UsersDB *db = new UsersDB();

    if (QFile().exists(UsersDB::FILE_NAME)) {
        QFile f(UsersDB::FILE_NAME);
        f.open(QIODevice::ReadOnly);
        QDataStream stream(&f);
        db->load(stream);
        f.close();
    }

    return db;
}

void UsersDB::saveInstance(const UsersDB &instance)
{
    QFile f(UsersDB::FILE_NAME);
    f.open(QIODevice::WriteOnly);
    QDataStream stream(&f);
    instance.save(stream);
    f.close();
}
