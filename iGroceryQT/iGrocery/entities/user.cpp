#include "user.h"

bool operator==(const User &l, const User &r)
{
    return l.mName == r.mName && l.mSurname == r.mSurname && l.mPatronymic == r.mPatronymic
            && l.mLogin == r.mLogin && l.mPassword == r.mPassword && l.mUserType == r.mUserType;
}

QDataStream& operator<<(QDataStream &stream, const User &usr)
{
    stream << usr.mName << usr.mSurname << usr.mPatronymic << usr.mLogin << usr.mPassword << usr.mUserType;
    return stream;
}

QDataStream& operator>>(QDataStream &stream, User &usr)
{
    stream >> usr.mName >> usr.mSurname >> usr.mPatronymic >> usr.mLogin >> usr.mPassword >> usr.mUserType;
    return stream;
}

User::User(QString name, QString surname, QString patronymic, QString login, QString password)
    : mName(name), mSurname(surname), mPatronymic(patronymic), mLogin(login), mPassword(password)
{

}

QString User::name() const
{
    return mName;
}

QString User::surname() const
{
    return mSurname;
}

QString User::patronymic() const
{
    return mPatronymic;
}

QString User::fullName() const
{
    return QString("%1 %2 %3").arg(mSurname).arg(mName).arg(mPatronymic);
}

QString User::login() const
{
    return mLogin;
}

bool User::isPasswordCorrect(const QString &password) const
{
    return mPassword == password;
}

UserType User::userType() const
{
    return mUserType;
}

void User::setUserType(const UserType &userType)
{
    mUserType = userType;
}
