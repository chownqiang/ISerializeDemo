#include "Student.h"
#include "Teacher.h"
#include "../SerializedTools/SerializedTool.h"

#include <QString>
#include <QtTest>

class ToolsTest : public QObject
{
    Q_OBJECT

public:
    ToolsTest();

private Q_SLOTS:
    void testCase1();
    void TestQPair_int_int();
    void TestQPair_QString_Student();
    void TestQPair_QString_PStudent();
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

void ToolsTest::TestQPair_int_int()
{
    QPair<int,int> s(1,2);

    RegistorType type = RegistorType(GETNAME(QPair_int_int));
    type.RegistorField(&s, "key", &s.first, JsonSerializedTypeInt().GetId());
    type.RegistorField(&s, "value", &s.second, JsonSerializedTypeInt().GetId());

    SerializedTool::Instance()->Registor(type);

    QString json = SerializedTool::Instance()->Serialized(&s,GETNAME(QPair_int_int));
    qDebug() << json;

    QPair<int,int> s2;
    SerializedTool::Instance()->Deserialized(&s2,GETNAME(QPair_int_int), json);


    QString json2 = SerializedTool::Instance()->Serialized(&s2,GETNAME(QPair_int_int));
    qDebug() << json2;

    QVERIFY2(json == json2, "Failure json");
}

void ToolsTest::TestQPair_QString_Student()
{
    Student st;
    st.age = 20;
    st.name = "jason";
    QPair<QString,Student> s("1",st);

    RegistorType type = RegistorType(GETNAME(QPair_QString_Student));
    type.RegistorField(&s, "key", &s.first, JsonSerializedTypeQString().GetId());
    type.RegistorField(&s, "value", &s.second, JsonSerializedTypeIJsonModel().GetId());

    SerializedTool::Instance()->Registor(type);

    QString json = SerializedTool::Instance()->Serialized(&s,GETNAME(QPair_QString_Student));
    qDebug() << json;

    QPair<QString,Student> s2;
    SerializedTool::Instance()->Deserialized(&s2,GETNAME(QPair_QString_Student), json);


    QString json2 = SerializedTool::Instance()->Serialized(&s2,GETNAME(QPair_QString_Student));
    qDebug() << json2;

    QVERIFY2(json == json2, "Failure json");
}

void ToolsTest::TestQPair_QString_PStudent()
{
    Student st;
    st.age = 20;
    st.name = "jason";
    QPair<QString,Student*> s("1",&st);

    {
        RegistorType type = RegistorType(GETNAME(QPair_QString_PStudent));
        type.RegistorField(&s, "key", &s.first, JsonSerializedTypeQString().GetId());
        type.RegistorField(&s, "value", &s.second, JsonSerializedTypePIJsonModel().GetId());

        SerializedTool::Instance()->Registor(type);
    }

    {
        RegistorType type = RegistorType(GETNAME(QPair_QString_Student));
        type.RegistorField(&s, "key", &s.first, JsonSerializedTypeQString().GetId());
        type.RegistorField(&s, "value", &s.second, JsonSerializedTypeIJsonModel().GetId());

        SerializedTool::Instance()->Registor(type);

    }



    QString json = SerializedTool::Instance()->Serialized(&s,GETNAME(QPair_QString_PStudent));
    qDebug() << json;

    QPair<QString,Student> s2;
    SerializedTool::Instance()->Deserialized(&s2,GETNAME(QPair_QString_Student), json);


    QString json2 = SerializedTool::Instance()->Serialized(&s2,GETNAME(QPair_QString_Student));
    qDebug() << json2;

    QVERIFY2(json == json2, "Failure json");
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
