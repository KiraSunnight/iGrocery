#include "administratorwindow.h"
#include "ui_administratorwindow.h"

AdministratorWindow::AdministratorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdministratorWindow)
{
    ui->setupUi(this);

    connect(ui->logout, &QPushButton::clicked, this, [this]() {
        LoginWindow *w = new LoginWindow();
        w->show();
        close();
    });

    connect(this, &AdministratorWindow::dataChanged, this, &AdministratorWindow::onDataChanged);

    mUsersDB = UsersDB::createInstance();

    uvm = new UsersViewModel(this);
    ui->usersTable->setModel(uvm);

    uvm->setProvider(mUsersDB);
    uvm->invalidateData();

    connect(ui->usersTable->selectionModel(), &QItemSelectionModel::selectionChanged, [this](const QItemSelection &selected) {
        bool itemSelected = selected.length() != 0;
        ui->editUser->setEnabled(itemSelected);
        ui->deleteUser->setEnabled(itemSelected);
    });
}

AdministratorWindow::~AdministratorWindow()
{
    delete ui;

    delete uvm;
}

AdministratorWindow *AdministratorWindow::withUser(User *user)
{
    mUser = user;
    ui->username->setText(mUser->fullName());
    return this;
}

void AdministratorWindow::on_addUser_triggered()
{
    UserDialog *userDialog = new UserDialog(this);

    if (userDialog->exec() != UserDialog::Accepted)
    {
        return;
    }

    User *user = userDialog->getUser();
    try {
        mUsersDB->addUser(*user);
        emit dataChanged();
    }  catch (const std::invalid_argument &e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}

void AdministratorWindow::on_deleteUser_triggered()
{
    if (ui->usersTable->selectionModel()->selectedIndexes().length() == 0)
    {
        return;
    }
    int idx = ui->usersTable->selectionModel()->selectedIndexes()[0].row();
    mUsersDB->removeUser(*uvm->getUserAt(idx));
    emit dataChanged();
}

void AdministratorWindow::on_editUser_triggered()
{
    if (ui->usersTable->selectionModel()->selectedIndexes().length() == 0)
    {
        return;
    }
    int idx = ui->usersTable->selectionModel()->selectedIndexes()[0].row();
    User *user = uvm->getUserAt(idx);
    UserDialog *userDialog = new UserDialog(this);
    userDialog->setUser(user);

    if (userDialog->exec() != UserDialog::Accepted)
    {
        return;
    }

    emit dataChanged();
}

void AdministratorWindow::onDataChanged()
{
    UsersDB::saveInstance(*mUsersDB);
    uvm->invalidateData();
}
