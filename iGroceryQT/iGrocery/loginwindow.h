#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "./db/usersdb.h"
#include "./userdialog.h"
#include "./administratorwindow.h"
#include "./storewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT
    UsersDB *mUsersDB;

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

    void check();

public slots:
    void auth();

private:
    Ui::LoginWindow *ui;
};
#endif // LOGINWINDOW_H
