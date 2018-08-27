#include <QString>
#include <QtTest>
#include "Teacher.h"
#include "Student.h"
#include "Classroom.h"
#include "School.h"

class SerializeTestTest : public QObject
{
    Q_OBJECT

public:
    SerializeTestTest();

private Q_SLOTS:
    void testCase1();
    void TestTeacher();
    void TestStudent();
    void TestTeacher_Student();
    void TestClassroom();

    void TestSchool();
};

SerializeTestTest::SerializeTestTest()
{
}

void SerializeTestTest::testCase1()
{
    QVERIFY2(true, "Failure");

}

void SerializeTestTest::TestTeacher()
{
    Teacher t1;
    t1.age = 22;
    t1.name = "Jason";
    t1.salary = 8000000000;
    QString tJson =  t1.SerializeToString();
    Teacher t2;
    t2.DeserializeByString(tJson);
    qDebug() << tJson;

    QVERIFY2(t1.age == t2.age, "Failure age");
    QVERIFY2(t1.name == t2.name, "Failure name");
    QVERIFY2(t1.salary == t2.salary, "Failure salary");

}

void SerializeTestTest::TestStudent()
{
    Student s1;
    s1.age = 22;
    s1.name = "Jason";
    s1.classroom = "class1";
    QString sJson =  s1.SerializeToString();
    Student s2;
    s2.DeserializeByString(sJson);
    qDebug() << sJson;

    QVERIFY2(s1.age == s2.age, "Failure age");
    QVERIFY2(s1.name == s2.name, "Failure name");
    QVERIFY2(s1.classroom == s2.classroom, "Failure classroom");

}

void SerializeTestTest::TestTeacher_Student()
{
    Teacher t1;
    t1.age = 22;
    t1.name = "Jason";
    t1.salary = 8000000000;
    QString tJson =  t1.SerializeToString();
    Student s2;
    s2.DeserializeByString(tJson);
    qDebug() << tJson;

    QVERIFY2(t1.age == s2.age, "Failure age");
    QVERIFY2(t1.name == s2.name, "Failure name");
    QVERIFY2("" == s2.classroom, "Failure classroom");
}

void SerializeTestTest::TestClassroom()
{
    Classroom cr;
    Teacher t1;
    t1.age = 22;
    t1.name = "Jason";
    t1.salary = 8000000000;

    Student s1;
    s1.age = 22;
    s1.name = "Jason";
    s1.classroom = "class1";


    cr.name = "class1";
    cr.t = &t1;
    cr.s = s1;

    QString crJson =  cr.SerializeToString();
    Classroom cr2;
    cr2.DeserializeByString(crJson);
    qDebug() << crJson;

    QVERIFY2(cr.name == cr2.name, "Failure cr.name");
    QVERIFY2(cr.t->age == cr2.t->age, "Failure t->age");
    QVERIFY2(cr.t->name == cr2.t->name, "Failure t->name");
    QVERIFY2(cr.t->salary == cr2.t->salary, "Failure t->salary");
    QVERIFY2(cr.s.age == cr2.s.age, "Failure s.age");
    QVERIFY2(cr.s.name == cr2.s.name, "Failure s.name");
    QVERIFY2(cr.s.classroom == cr2.s.classroom, "Failure s.classroom");
}

void SerializeTestTest::TestSchool()
{

}


QTEST_APPLESS_MAIN(SerializeTestTest)

#include "tst_serializetesttest.moc"
