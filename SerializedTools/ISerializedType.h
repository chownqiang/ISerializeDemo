#ifndef ISERIALIZEDTYPE_H
#define ISERIALIZEDTYPE_H

class SerializedData;
#include "QString"

class ISerializedType
{
public:
    virtual QString GetId()=0;
    virtual QString GetTypename()=0;
    virtual void* Serialization(const void* model, SerializedData* data)=0;
    virtual void Deserialization(const void* model, SerializedData* data,const void* value)=0;
};


#endif // ISERIALIZEDTYPE_H
