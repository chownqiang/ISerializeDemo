#include "Teacher.h"


void Teacher::InitSerializeKeys()
{
    this->SetKeyData("name", &this->name,SerializeDataType::QString_type);
    this->SetKeyData("age", &this->age,  SerializeDataType::int_type);
    this->SetKeyData("salary", &this->salary,SerializeDataType::qlonglong_type);
}
