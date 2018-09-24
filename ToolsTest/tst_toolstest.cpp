#include "Student.h"

#include <QString>
#include <QtTest>

class ToolsTest : public QObject
{
    Q_OBJECT

public:
    ToolsTest();

private Q_SLOTS:
    void testCase1();
    void TestStudent();
};

ToolsTest::ToolsTest()
{
}

void ToolsTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void ToolsTest::TestStudent()
{
    Student s1 ;
    s1.age = 20;
    s1.name = "abc";

    QString json =  s1.EncodeToJson();

    Student s2;
    s2.DecodeFromJson(json);

    QVERIFY2(s1.age == s2.age, "Failure age");
    QVERIFY2(s1.name == s2.name,"Failure name");
}

QTEST_APPLESS_MAIN(ToolsTest)

#include "tst_toolstest.moc"
