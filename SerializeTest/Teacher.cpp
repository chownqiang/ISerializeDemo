#include "Teacher.h"
#include "../SerializeLibSrc/ISerializeTypeJson.h"


void Teacher::InitSerializeKeys()
{
    this->SetKeyData("name", &this->name,new DefaultJsonSerialize_QString());
    this->SetKeyData("age", &this->age,  new DefaultJsonSerialize_Int());
    this->SetKeyData("salary", &this->salary,new DefaultJsonSerialize_Qlonglong());
}
