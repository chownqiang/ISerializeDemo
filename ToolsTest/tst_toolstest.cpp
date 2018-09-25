#include "Student.h"
#include "Teacher.h"

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
    void TestTeacher();
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

    qDebug() << json;

    Student s2;
    s2.DecodeFromJson(json);

    QVERIFY2(s1.age == s2.age, "Failure age");
    QVERIFY2(s1.name == s2.name,"Failure name");
}

void ToolsTest::TestTeacher()
{
    Teacher t ;
    t.st->age = 20;
    t.st->name = "abc";
    t.st2.age = 10;
    t.age = 30;
    t.name = "teacher";

    QString json = t.EncodeToJson();
    qDebug() << json;

    Teacher t2 ;
    t2.DecodeFromJson(json);
    QString json2 = t2.EncodeToJson();
    qDebug() << json2;

    QVERIFY2(json == json2,"json == json");
    QVERIFY2(t.age == t2.age,"t.age");
    QVERIFY2(t.name == t2.name,"t.name");
    QVERIFY2(t.st->age == t2.st->age,"t.st->age");
    QVERIFY2(t.st->name == t2.st->name,"t.st->name");
}

QTEST_APPLESS_MAIN(ToolsTest)

#include "tst_toolstest.moc"
