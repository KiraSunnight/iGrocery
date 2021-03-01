#ifndef STOREWINDOW_H
#define STOREWINDOW_H

#include <QMainWindow>

#include "./entities/user.h"

namespace Ui {
class StoreWindow;
}

class StoreWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StoreWindow(QWidget *parent = nullptr);
    ~StoreWindow();

    StoreWindow* withUser(User *user);

private:
    Ui::StoreWindow *ui;

    User *mUser;
};

#endif // STOREWINDOW_H
