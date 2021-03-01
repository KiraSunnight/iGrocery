#include "gooddialog.h"
#include "ui_gooddialog.h"

GoodDialog::GoodDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GoodDialog)
{
    ui->setupUi(this);
}

GoodDialog::~GoodDialog()
{
    delete ui;
}

Good *GoodDialog::getGood()
{
    return mGood;
}

void GoodDialog::setGood(Good *good, bool powerUser)
{
    mGood = good;
    ui->baseInfoBox->setEnabled(powerUser);
    ui->name->setText(mGood->name());
    ui->provider->setText(mGood->providerName());
    ui->amountInStorage->setValue(mGood->amountInStorage());
    ui->shelfNumber->setValue(mGood->shelfNumber());
}

void GoodDialog::accept()
{
    try {
        QString name = ui->name->text().trimmed();
        QString provider = ui->provider->text().trimmed();
        if (name.isEmpty() || provider.isEmpty())
        {
            throw std::runtime_error("Проверьте правильность заполнения формы!");
        }

        int amountInStorage = ui->amountInStorage->value();
        int shelfNumber = ui->shelfNumber->value();
        if (mGood == nullptr)
        {
            mGood = new Good();
        }
        mGood->setName(name);
        mGood->setProviderName(provider);
        mGood->setAmountInStorage(amountInStorage);
        mGood->setShelfNumber(shelfNumber);
    }  catch (const std::runtime_error &e) {
        QMessageBox::critical(this, "Ошибка", e.what());
        return;
    }

    QDialog::accept();
}
