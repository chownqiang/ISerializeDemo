#ifndef CUSTOMERJSONSERIALIZE_QLISTTEACHER_H
#define CUSTOMERJSONSERIALIZE_QLISTTEACHER_H

#include "../SerializeLibSrc/ISerializeTypeJson.h"


class CustomerJsonSerialize_QListTeacher : public IJsonSerializeType
{

    // ISerializeType interface
public:
    QString GetId();

    // IJsonSerializeType interface
public:
    QJsonValue SerializationJson(const SerializeData *data);
    void DeserializationJson(const SerializeData *data, QJsonValue *value);
};

#endif // CUSTOMERJSONSERIALIZE_QLISTTEACHER_H
