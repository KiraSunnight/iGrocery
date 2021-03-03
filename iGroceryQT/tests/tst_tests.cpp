#include <QtTest>

#include "../iGrocery/entities/good.h"
#include "../iGrocery/entities/user.h"
#include "../iGrocery/db/goodsdb.h"
#include "../iGrocery/db/usersdb.h"

class tests : public QObject
{
    Q_OBJECT

public:
    tests();
    ~tests();

private slots:
    void goods_comparison();
    void goods_serialization();

    void goodsdb_goods_add();
    void goodsdb_goods_remove();

    void users_comparison();
    void users_password_check();
    void users_serialization();

    void usersdb_users_add();
    void usersdb_users_get_by_type();
    void usersdb_users_get_by_login();
    void usersdb_users_remove();
};

tests::tests()
{
    QFile(UsersDB::FILE_NAME).remove();
    QFile(GoodsDB::FILE_NAME).remove();
}

tests::~tests()
{
    QFile(UsersDB::FILE_NAME).remove();
    QFile(GoodsDB::FILE_NAME).remove();
}

void tests::goods_comparison()
{
    Good g1;
    Good g2("testg", 2, 2, "tesp");
    Good g3(g2);

    QVERIFY(!(g1 == g2));
    QVERIFY(!(g1 == g3));
    QCOMPARE(g2, g3);
}

void tests::goods_serialization()
{
    QByteArray bytes;
    QDataStream qdsw(&bytes, QIODevice::WriteOnly);
    QDataStream qdsr(&bytes, QIODevice::ReadOnly);

    Good g1("testg", 2, 2, "tesp");
    Good g2;
    qdsw << g1;
    qdsr >> g2;

    QCOMPARE(g1, g2);
}

void tests::goodsdb_goods_add()
{
    GoodsDB *db = GoodsDB::createInstance();

    Good g1("testg", 2, 2, "tesp");
    db->addGood(g1);
    Good g2(g1);
    db->addGood(g2);
    Good g3(g1);
    db->addGood(g3);
    Good g4(g1);
    db->addGood(g4);

    QCOMPARE(db->goods().length(), 4);
    QCOMPARE(db->goods()[0], g1);

    GoodsDB::saveInstance(*db);

    delete db;
}

void tests::goodsdb_goods_remove()
{
    GoodsDB *db = GoodsDB::createInstance();

    Good g1 = db->goods()[0];
    db->removeGood(g1);

    QCOMPARE(db->goods().length(), 0);

    GoodsDB::saveInstance(*db);

    delete db;
}

void tests::users_comparison()
{
    User u1;
    User u2("usertf", "userts", "usertp", "usertlog", "usertpass");
    User u3(u2);

    QVERIFY(!(u1 == u2));
    QVERIFY(!(u1 == u3));
    QCOMPARE(u2, u3);
}

void tests::users_password_check()
{
    User u1("usertf", "userts", "usertp", "usertlog", "usertpass");

    QVERIFY(u1.isPasswordCorrect("usertpass"));
    QVERIFY(!u1.isPasswordCorrect("incorrectpassword"));
}

void tests::users_serialization()
{
    QByteArray bytes;
    QDataStream qdsw(&bytes, QIODevice::WriteOnly);
    QDataStream qdsr(&bytes, QIODevice::ReadOnly);

    User u1("usertf", "userts", "usertp", "usertlog", "usertpass");
    User u2;
    qdsw << u1;
    qdsr >> u2;

    QCOMPARE(u1, u2);
}

void tests::usersdb_users_add()
{
    UsersDB *db = UsersDB::createInstance();

    User u1("usertf", "userts", "usertp", "usertlog", "usertpass");
    u1.setUserType(UserType::WORKER);
    User u2(u1);
    User u3("usertf2", "userts2", "usertp2", "usertlog2", "usertpass2");
    u3.setUserType(UserType::WORKER);

    db->addUser(u1);
    QVERIFY_EXCEPTION_THROWN(db->addUser(u2), std::invalid_argument);
    db->addUser(u3);

    QCOMPARE(db->getUsersByType(UserType::WORKER).length(), 2);

    UsersDB::saveInstance(*db);

    delete db;
}

void tests::usersdb_users_get_by_type()
{
    UsersDB *db = UsersDB::createInstance();

    QCOMPARE(db->getUsersByType(UserType::WORKER).length(), 2);

    delete db;
}

void tests::usersdb_users_get_by_login()
{
    UsersDB *db = UsersDB::createInstance();

    User *u1 = db->getUserByLogin("usertlog");
    User *u2 = db->getUserByLogin("no_such_user");

    QVERIFY(u1 != nullptr);
    QVERIFY(u2 == nullptr);

    delete db;
}

void tests::usersdb_users_remove()
{
    UsersDB *db = UsersDB::createInstance();

    auto userList = db->getUsersByType(UserType::WORKER);
    User u1 = *userList[0];
    User u2 = *userList[1];

    db->removeUser(u1);
    db->removeUser(u2);
    QCOMPARE(db->getUsersByType(UserType::WORKER).length(), 0);

    delete db;
}

QTEST_APPLESS_MAIN(tests)

#include "tst_tests.moc"
