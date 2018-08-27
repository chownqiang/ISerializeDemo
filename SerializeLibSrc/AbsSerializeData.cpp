#include "AbsSerializeData.h"
#include "JsonSerializeTool.h"

AbsSerializeData::AbsSerializeData()
{
    // JsonSerializeTool XMLSerializeTool ...
    this->serializeTool = new JsonSerializeTool();
    this->Keys = new QList<SerializeData>();
}


QString AbsSerializeData::SerializeToString()
{
    return this->serializeTool->Serialization(this);
}


void AbsSerializeData::DeserializeByString(QString strData)
{
    this->serializeTool->Deserialization(this,strData);
}


QList<SerializeData>* AbsSerializeData::GetKeys()
{
    this->Init();

    return this->Keys;
}


void AbsSerializeData::SetKeyData(QString key,void* keyPointer,SerializeDataType type)
{
    char * p= (char *)this;
    int offset =  (char *)keyPointer - (char *)this;

    SerializeData keydata;
    keydata.key =  key;
    keydata.offset =  offset;
    keydata.type =  type;
    keydata.defaultPointer =  p;

    this->Keys->append(keydata);
}



void AbsSerializeData::Init()
{
    if(!setKeys)
    {
        this->InitSerializeKeys();
        setKeys = true;
    }
}
