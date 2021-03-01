#ifndef GOODDIALOG_H
#define GOODDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "./entities/good.h"

namespace Ui {
class GoodDialog;
}

class GoodDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GoodDialog(QWidget *parent = nullptr);
    ~GoodDialog();

    Good* getGood();
    void setGood(Good *good, bool powerUser);
public slots:
    void accept();

private:
    Ui::GoodDialog *ui;

    Good *mGood = nullptr;
};

#endif // GOODDIALOG_H
