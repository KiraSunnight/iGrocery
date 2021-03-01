#include "userdialog.h"
#include "ui_userdialog.h"

UserDialog::UserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    ui->setupUi(this);
}

UserDialog::~UserDialog()
{
    delete ui;
}

User *UserDialog::getUser()
{
    return mUser;
}

void UserDialog::setUser(User *user)
{
    mUser = user;
    ui->mainBox->setEnabled(false);
    ui->authBox->setEnabled(false);
    ui->firstName->setText(mUser->name());
    ui->secondName->setText(mUser->surname());
    ui->patronymic->setText(mUser->patronymic());
    ui->login->setText(mUser->login());
    ui->accountType->setCurrentIndex((int)mUser->userType());
}

void UserDialog::accept()
{
    try {
        if (mUser == nullptr)
        {
            QString firstName = ui->firstName->text().trimmed();
            QString secondName = ui->secondName->text().trimmed();
            QString patronymic = ui->patronymic->text().trimmed();
            QString login = ui->login->text().trimmed();
            QString password = ui->password->text().trimmed();
            if (firstName.isEmpty() || secondName.isEmpty() || patronymic.isEmpty()
                    || login.isEmpty() || password.isEmpty())
            {
                throw std::runtime_error("Проверьте правильность заполнения формы!");
            }
            mUser = new User();
        }
        UserType userType = (UserType)ui->accountType->currentIndex();
        mUser->setUserType(userType);
    }  catch (const std::runtime_error &e) {
        QMessageBox::critical(this, "Ошибка", e.what());
        return;
    }

    QDialog::accept();
}
