#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "./entities/user.h"

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDialog(QWidget *parent = nullptr);
    ~UserDialog();

    User* getUser();
    void setUser(User *user);
public slots:
    void accept();

private:
    Ui::UserDialog *ui;

    User *mUser = nullptr;
};

#endif // USERDIALOG_H
