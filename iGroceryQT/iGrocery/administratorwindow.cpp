#include "administratorwindow.h"
#include "ui_administratorwindow.h"

AdministratorWindow::AdministratorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdministratorWindow)
{
    ui->setupUi(this);
}

AdministratorWindow::~AdministratorWindow()
{
    delete ui;
}

AdministratorWindow *AdministratorWindow::withUser(User *user)
{
    mUser = user;
    ui->username->setText(mUser->fullName());
    return this;
}
