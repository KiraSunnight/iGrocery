#ifndef ADMINISTRATORWINDOW_H
#define ADMINISTRATORWINDOW_H

#include <QMainWindow>
#include <QItemSelection>

#include "./entities/user.h"
#include "./db/usersdb.h"
#include "./loginwindow.h"
#include "./viewmodels/usersviewmodel.h"

namespace Ui {
class AdministratorWindow;
}

class AdministratorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdministratorWindow(QWidget *parent = nullptr);
    ~AdministratorWindow();

    AdministratorWindow* withUser(User *user);

private slots:
    void on_addUser_triggered();
    void on_deleteUser_triggered();
    void on_editUser_triggered();

    void onDataChanged();

private:
    Ui::AdministratorWindow *ui;

    User *mUser;
    UsersDB *mUsersDB;
    UsersViewModel *uvm;

signals:
    void dataChanged();
};

#endif // ADMINISTRATORWINDOW_H
