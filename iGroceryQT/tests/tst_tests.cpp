#include <QtTest>

// add necessary includes here

class tests : public QObject
{
    Q_OBJECT

public:
    tests();
    ~tests();

private slots:
    void test_case1();

};

tests::tests()
{

}

tests::~tests()
{

}

void tests::test_case1()
{

}

QTEST_APPLESS_MAIN(tests)

#include "tst_tests.moc"
