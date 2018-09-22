#ifndef SERIALIZEDTOOL_H
#define SERIALIZEDTOOL_H

#include "ISerialized.h"
#include "RegistorType.h"
#include "serializedtools_global.h"


#define NEWREGISTORTYPE(type) RegistorType(#type)
#define REGISTORFIELD(data, pThis, key, type) data.RegistorField((pThis), (#key), (&key), (type))

class SERIALIZEDTOOLSSHARED_EXPORT SerializedTool
{
public:
    static SerializedTool* Instance();
    void Registor(RegistorType type);
    bool ContainsKey(QString typeName);

    QString Serialized(void* data, QString typeName);
    void Deserialized(void* data, QString typeName, QString dataStr);

private:
    SerializedTool();
    QMap<QString,QSharedPointer<QList<SerializeData>>> container;
    ISerialized * itool;
};

#endif // SERIALIZEDTOOL_H
