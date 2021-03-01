#include "storewindow.h"
#include "ui_storewindow.h"

StoreWindow::StoreWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StoreWindow)
{
    ui->setupUi(this);
}

StoreWindow::~StoreWindow()
{
    delete ui;
}

StoreWindow *StoreWindow::withUser(User *user)
{
    mUser = user;
    ui->username->setText(user->fullName());
    return this;
}
