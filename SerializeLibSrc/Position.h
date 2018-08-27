#ifndef POSITION_H
#define POSITION_H
#include "AbsSerializeData.h"
#include "QDebug"
#include "QJsonObject"
#include "QJsonDocument"
#include "QByteArray"

class Position : public AbsSerializeData
{
public:
    void SetSerializeKeys_Test()
    {
        char * p= (char *)this;
        int id =  (char *)(&(this->id)) - p;
        int username =  (char *)(&(this->username)) - p;
        int value =   (char *)(&(this->value)) - p;


        qDebug() << (Position*)p;
        qDebug() << this;
        qDebug() << (void *)(p + id);
        qDebug() << &(this->id);
        qDebug() << (void *)(p+ username);
        qDebug() << &(this->username);
        qDebug() << (void *)(p + value);
        qDebug() << &(this->value);

        qDebug() << *(QString*)(p + id);
        qDebug() << (QString)(this->id);
        qDebug() << this->id;
        qDebug() << *(QString*)(p+ username);
        qDebug() << this->username;
        qDebug() << *(double*)(p + value);
        qDebug() << this->value;
    }

    virtual void InitSerializeKeys();


public:
    QString id;
    double value;
    QString username;
    QString surname;

    QString Tostring()
    {
        return  this->SerializeToString();
    }

    QString MulJson()
    {


        char a = 'a';
        short b = 65535;
        int c = b;
        char d = b;
        QJsonObject json;
        json.insert("id", this->id);
        json.insert("value", this->value);
        json.insert("username", this->username);
        QJsonObject addr;
        addr.insert("city", "guangzhou");
        addr.insert("province", "guangdong");
        json.insert("char", a);
        json.insert("short", b);
        json.insert("int", c);
        json.insert("d", d);

        json.insert("addr", addr);
        // 构建 JSON 文档
        QJsonDocument document;
        document.setObject(json);
        QByteArray byteArray =document.toJson(QJsonDocument::Compact);
        QString strJson(byteArray);

        return strJson;
    }
};


#endif // POSITION_H
