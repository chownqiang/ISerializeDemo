#include "Student.h"


void Student::InitSerializeKeys()
{
    this->SetKeyData("name",&this->name,SerializeDataType::QString_type);
    this->SetKeyData("age",&this->age,  SerializeDataType::int_type);
    this->SetKeyData("classroom",&this->classroom,SerializeDataType::QString_type);
}
