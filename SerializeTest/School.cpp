#include "School.h"


School::School()
{

}

void School::InitSerializeKeys()
{
    this->SetKeyData("ts", &this->ts, SerializeDataType::list_AbsSerializeData_type);
    this->SetKeyData("ss", &this->ss, SerializeDataType::list_AbsSerializeData_type);
}
