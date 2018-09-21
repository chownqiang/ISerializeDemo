#include "RegistorType.h"

RegistorType::RegistorType()
{
    this->typeName = "";
}

RegistorType::RegistorType(const RegistorType &data)
{
    this->typeName = data.typeName;
    this->Keys = data.Keys;
}

RegistorType::RegistorType(const QString typeName)
{
    this->typeName = typeName;
    this->Keys = QSharedPointer<QList<SerializeData>>(new QList<SerializeData>());
}

void RegistorType::RegistorField(const void *pThis, QString key, void *keyPointer, QSharedPointer<ISerializeType> type)
{
    if(this->typeName == "")
    {
        qDebug() << "null of typeName, please use RegistorType::RegistorType(QString typeName)";
        return;
    }

    SerializeData keydata;
    keydata.key =  key;
    keydata.offset = (char*)pThis - (char*)keyPointer;
    keydata.type = type;

    this->Keys->append(keydata);
}

QSharedPointer<QList<SerializeData>> RegistorType::GetKeys()
{
    return this->Keys;
}
