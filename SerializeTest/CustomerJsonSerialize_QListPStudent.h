#ifndef CUSTOMERJSONSERIALIZE_QLISTPSTUDENT_H
#define CUSTOMERJSONSERIALIZE_QLISTPSTUDENT_H

#include "../SerializeLibSrc/ISerializeTypeJson.h"


class CustomerJsonSerialize_QListPStudent : public IJsonSerializeType
{
    // ISerializeType interface
public:
    QString GetId();

    // IJsonSerializeType interface
public:
    QJsonValue SerializationJson(const SerializeData *data);
    void DeserializationJson(const SerializeData *data, QJsonValue *value);
};

#endif // CUSTOMERJSONSERIALIZE_QLISTPSTUDENT_H
