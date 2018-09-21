#ifndef REGISTORTYPE_H
#define REGISTORTYPE_H
#include "SerializeData.h"

#include <QSharedPointer>
#include <QString>

class RegistorType
{
public:
    RegistorType();
    RegistorType(const RegistorType& data);
    RegistorType(const QString typeName);
    void RegistorField(const void* pThis, QString key, void* keyPointer,QSharedPointer<ISerializeType> type);
    QSharedPointer<QList<SerializeData>> GetKeys();

    QString typeName;
    // Field:
private:
    QSharedPointer<QList<SerializeData>> Keys;
};

#endif // REGISTORTYPE_H
