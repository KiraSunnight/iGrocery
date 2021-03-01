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

    static AdministratorWindow* withUser(User *user);

private:
    Ui::AdministratorWindow *ui;
};

#endif // ADMINISTRATORWINDOW_H
