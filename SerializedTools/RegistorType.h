#ifndef REGISTORTYPE_H
#define REGISTORTYPE_H
#include "SerializedData.h"

#include <QSharedPointer>
#include <QString>

class RegistorType
{
public:
    RegistorType();
    RegistorType(const RegistorType& data);
    RegistorType(const QString typeName);
    void RegistorField(const void* pThis, QString key, void* keyPointer, QString iSerializedTypeId);
    void RegistorField(const void *pThis, QString key, void *keyPointer, QString iSerializedTypeId, std::function<QString(void* data)> customerFunc );

    QList<SerializedData>* GetKeys();

    QString typeName;
    // Field:
private:
    QList<SerializedData>* Keys;
};

#endif // REGISTORTYPE_H
