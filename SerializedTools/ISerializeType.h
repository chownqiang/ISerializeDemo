#ifndef ISERIALIZETYPE_H
#define ISERIALIZETYPE_H

class SerializeData;
#include "QString"

class ISerializeType
{
public:
    virtual QString GetId()=0;
    virtual QString GetTypename()=0;
    virtual void* Serialization(const void* model, const SerializeData* data)=0;
    virtual void Deserialization(const void* model, const SerializeData* data,const void* value)=0;
};


#endif // ISERIALIZETYPE_H
