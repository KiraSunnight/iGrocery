#ifndef GOODDIALOG_H
#define GOODDIALOG_H

#include <QDialog>

namespace Ui {
class GoodDialog;
}

class GoodDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GoodDialog(QWidget *parent = nullptr);
    ~GoodDialog();

private:
    Ui::GoodDialog *ui;
};

#endif // GOODDIALOG_H
