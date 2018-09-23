#ifndef SERIALIZEDTOOL_H
#define SERIALIZEDTOOL_H

#include "ISerialized.h"
#include "JsonSerializedType.h"
#include "RegistorType.h"
#include "serializedtools_global.h"


#define NEWREGISTORTYPE(type) RegistorType(#type)
#define REGISTORFIELD(data, pThis, key, type) data.RegistorField((pThis), (#key), (&key), (type))

class SERIALIZEDTOOLSSHARED_EXPORT SerializedTool
{
public:
    static SerializedTool* Instance();
    void Registor(RegistorType type);

    QString Serialized(void* data, QString typeName);
    void Deserialized(void* data, QString typeName, QString dataStr);

private:
    SerializedTool();
    QMap<QString, QList<SerializedData>*> container;
    ISerialized * itool;

    QMap<QString,ISerializedType*> serializedType;
};

#endif // SERIALIZEDTOOL_H
