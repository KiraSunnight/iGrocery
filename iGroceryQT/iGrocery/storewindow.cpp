#include "storewindow.h"
#include "ui_storewindow.h"

StoreWindow::StoreWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StoreWindow)
{
    ui->setupUi(this);

    connect(ui->logout, &QPushButton::clicked, this, [this]() {
        LoginWindow *w = new LoginWindow();
        w->show();
        close();
    });

    connect(ui->info, &QPushButton::clicked, this, [this]() {
        QString infoText = "Скоро закончатся:\n";

        foreach (auto g, mGoodsDB->goods())
        {
            if (g.amountInStorage() > 10)
            {
                continue;
            }
            infoText += tr("- '%1' (от '%2') - %3\n").arg(g.name()).arg(g.providerName()).arg(g.amountInStorage());
        }

        QMessageBox::information(this, "Справка", infoText);
    });

    connect(this, &StoreWindow::dataChanged, this, &StoreWindow::onDataChanged);

    mGoodsDB = GoodsDB::createInstance();

    gvm = new GoodsViewModel(this);
    gvm->setProvider(mGoodsDB);

    ui->goodsTable->setModel(gvm);

    gvm->invalidateData();

    connect(ui->goodsTable->selectionModel(), &QItemSelectionModel::selectionChanged, [this](const QItemSelection &selected) {
        bool itemSelected = selected.length() != 0;
        ui->editGood->setEnabled(itemSelected);
        ui->removeGood->setEnabled(itemSelected);
    });
}

StoreWindow::~StoreWindow()
{
    delete ui;
}

StoreWindow *StoreWindow::withUser(User *user)
{
    mUser = user;
    ui->username->setText(user->fullName());
    if (mUser->userType() == UserType::WORKER)
    {
        ui->addGood->setVisible(false);
        ui->removeGood->setVisible(false);
    }
    return this;
}

void StoreWindow::onAddGoodClicked()
{
    GoodDialog *goodDialog = new GoodDialog(this);

    if (goodDialog->exec() != UserDialog::Accepted)
    {
        return;
    }

    Good *good = goodDialog->getGood();
    try {
        mGoodsDB->addGood(*good);
        emit dataChanged();
    }  catch (const std::invalid_argument &e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}

void StoreWindow::onEditGoodClicked()
{
    int idx = ui->goodsTable->selectionModel()->selectedIndexes()[0].row();
    Good *good = gvm->getGoodAt(idx);
    GoodDialog *goodDialog = new GoodDialog(this);
    goodDialog->setGood(good, mUser->userType() == UserType::MANAGER);

    if (goodDialog->exec() != UserDialog::Accepted)
    {
        return;
    }
    mGoodsDB->removeGood(*good);
    mGoodsDB->addGood(*good);

    emit dataChanged();
}

void StoreWindow::onRemoveGoodClicked()
{
    int idx = ui->goodsTable->selectionModel()->selectedIndexes()[0].row();
    mGoodsDB->removeGood(*gvm->getGoodAt(idx));
    emit dataChanged();
}

void StoreWindow::onDataChanged()
{
    GoodsDB::saveInstance(*mGoodsDB);
    gvm->invalidateData();
}
