#ifndef STOREWINDOW_H
#define STOREWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "./entities/user.h"
#include "./db/goodsdb.h"
#include "./loginwindow.h"
#include "./viewmodels/goodsviewmodel.h"
#include "./gooddialog.h"

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

private slots:
    void onAddGoodClicked();
    void onEditGoodClicked();
    void onRemoveGoodClicked();
    void onDataChanged();

private:
    Ui::StoreWindow *ui;

    User *mUser;
    GoodsDB *mGoodsDB;
    GoodsViewModel *gvm;

signals:
    void dataChanged();
};

#endif // STOREWINDOW_H
