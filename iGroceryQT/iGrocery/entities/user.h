#ifndef USER_H
#define USER_H

#include <QString>

enum class UserType {
    WORKER,
    MANAGER,
    ADMINISTRATOR,
    UNKNOWN
};

class User
{
private:
    QString mName;
    QString mSurname;
    QString mPatronymic;
    QString mLogin;
    QString mPassword;

    UserType mUserType = UserType::UNKNOWN;

public:
    User() = default;
    User(QString name, QString surname, QString patronymic, QString login, QString password);
    QString name() const;
    QString surname() const;
    QString patronymic() const;
    QString fullName() const;
    QString login() const;
    bool isPasswordCorrect(const QString &password) const;
    UserType userType() const;
    void setUserType(const UserType &userType);
};

#endif // USER_H
