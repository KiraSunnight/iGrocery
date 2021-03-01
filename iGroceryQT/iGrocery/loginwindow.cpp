#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    mUsersDB = UsersDB::createInstance();

    check();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::check()
{
    if (mUsersDB->getUsersByType(UserType::ADMINISTRATOR).length() > 0)
    {
        return;
    }

    QMessageBox::information(this,
                             "Уведомление",
                             "Вы в первый раз запускаете систему, зарегистрируйте нового пользователя."
                             "Данный пользователь будет выбран в качестве администратора вне зависимости "
                             "от выбранного значения поля типа аккаунта.");

    UserDialog *userDialog = new UserDialog(this);

    if (userDialog->exec() != UserDialog::Accepted)
    {
        QMessageBox::critical(this,
                             "Ошибка",
                             "Для дальнейшей работы системы требуется аккаунт администратора.");
        close();
        return;
    }

    User *user = userDialog->getUser();
    mUsersDB->addUser(*user);

    QMessageBox::information(this,
                             "Ошибка",
                             "Для дальнейшей работы системы требуется аккаунт администратора.");
}

void LoginWindow::auth()
{
    try {
        QString login = ui->login->text().trimmed();
        QString password = ui->password->text().trimmed();

        if (login.isEmpty() || password.isEmpty())
        {
            throw std::runtime_error("Поля авторизации не могут быть пустыми");
        }

        User *user = mUsersDB->getUserByLogin(login);
        if (user == nullptr)
        {
            throw std::runtime_error("Пользователь не найден");
        }
        if (!user->isPasswordCorrect(password))
        {
            throw std::runtime_error("Пароль не верен");
        }

        QMainWindow *w;
        if (user->userType() == UserType::ADMINISTRATOR)
        {
            w = AdministratorWindow::withUser(user);
        }
        else
        {
            w = StoreWindow::withUser(user);
        }
        close();
        w->show();
    }  catch (const std::runtime_error &e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}

