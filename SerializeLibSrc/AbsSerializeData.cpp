#include "AbsSerializeData.h"
#include "JsonSerializeTool.h"

AbsSerializeData::AbsSerializeData()
{
    // JsonSerializeTool XMLSerializeTool ...
    this->serializeTool = QSharedPointer<ISerializeTool>(new JsonSerializeTool());
    this->Keys = QSharedPointer<QList<SerializeData>>(new QList<SerializeData>());
}

AbsSerializeData::~AbsSerializeData()
{
    //QSharedPointer JsonSerializeTool XMLSerializeTool ...
    //delete this->serializeTool ;
    //delete this->Keys;  // QSharedPointer
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

    return this->Keys.data();
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
