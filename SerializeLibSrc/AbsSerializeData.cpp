#include "AbsSerializeData.h"
#include "JsonSerializeTool.h"

AbsSerializeData::AbsSerializeData()
{
    // JsonSerializeTool XMLSerializeTool ...
    this->serializeTool = new JsonSerializeTool();
    this->Keys = new QList<SerializeData>();
}

AbsSerializeData::~AbsSerializeData()
{
    //delete JsonSerializeTool XMLSerializeTool ...
    delete this->serializeTool ;
    delete this->Keys;
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


void AbsSerializeData::SetKeyData(QString key,void* keyPointer,QSharedPointer<ISerializeType> type)
{

    SerializeData keydata;
    keydata.key =  key;
    keydata.offset = keyPointer;
    keydata.type = type;

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
