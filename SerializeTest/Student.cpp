#include "Student.h"
#include "../SerializeLibSrc/ISerializeTypeJson.h"

void Student::InitSerializeKeys()
{
    this->SetKeyData("name",&this->name, new DefaultJsonSerialize_QString());
    this->SetKeyData("age",&this->age,  new DefaultJsonSerialize_Int());
    this->SetKeyData("classroom",&this->classroom, new DefaultJsonSerialize_QString());
}
