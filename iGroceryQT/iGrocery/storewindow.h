#ifndef STOREWINDOW_H
#define STOREWINDOW_H

#include <QMainWindow>

namespace Ui {
class StoreWindow;
}

class StoreWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StoreWindow(QWidget *parent = nullptr);
    ~StoreWindow();

private:
    Ui::StoreWindow *ui;
};

#endif // STOREWINDOW_H
