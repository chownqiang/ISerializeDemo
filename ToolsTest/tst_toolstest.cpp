#include <QString>
#include <QtTest>

class ToolsTest : public QObject
{
    Q_OBJECT

public:
    ToolsTest();

private Q_SLOTS:
    void testCase1();
};

ToolsTest::ToolsTest()
{
}

void ToolsTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ToolsTest)

#include "tst_toolstest.moc"
