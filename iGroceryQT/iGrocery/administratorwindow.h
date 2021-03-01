#ifndef ADMINISTRATORWINDOW_H
#define ADMINISTRATORWINDOW_H

#include <QMainWindow>

#include "./entities/user.h"

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

private:
    Ui::AdministratorWindow *ui;

    User *mUser;
};

#endif // ADMINISTRATORWINDOW_H
