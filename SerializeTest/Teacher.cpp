#include "Teacher.h"
#include "../SerializeLibSrc/ISerializeTypeJson.h"


void Teacher::InitSerializeKeys()
{
    this->SetKeyData("name", &this->name, QSharedPointer<ISerializeType>(new DefaultJsonSerialize_QString()));
    this->SetKeyData("age", &this->age,  QSharedPointer<ISerializeType>(new DefaultJsonSerialize_Int()));
    this->SetKeyData("salary", &this->salary,QSharedPointer<ISerializeType>(new DefaultJsonSerialize_Qlonglong()));
}
