#ifndef SIMPLECLASS_H
#define SIMPLECLASS_H

#include <ISerializedModel.h>
#include <qpair.h>
#include <qvector.h>



class SimpleClass : IJsonModel
{
public:
    SimpleClass();

    QVector<int> p;

    // ISerializedModel interface
public:
    void RegistorTool();

    // IJsonModel interface
public:
    QString EncodeToJson();
    void DecodeFromJson(QString json);
};

#endif // SIMPLECLASS_H
