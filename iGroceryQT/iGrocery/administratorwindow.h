#ifndef ADMINISTRATORWINDOW_H
#define ADMINISTRATORWINDOW_H

#include <QMainWindow>

namespace Ui {
class AdministratorWindow;
}

class AdministratorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdministratorWindow(QWidget *parent = nullptr);
    ~AdministratorWindow();

private:
    Ui::AdministratorWindow *ui;
};

#endif // ADMINISTRATORWINDOW_H
