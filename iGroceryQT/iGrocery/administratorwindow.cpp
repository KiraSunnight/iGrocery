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
