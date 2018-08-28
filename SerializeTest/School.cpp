#include "School.h"
#include "../SerializeLibSrc/ISerializeTypeJson.h"
#include "CustomerJsonSerialize_QListTeacher.h"
#include "CustomerJsonSerialize_QListPStudent.h"

School::School()
{

}

void School::InitSerializeKeys()
{
    this->SetKeyData("ts", &this->ts, QSharedPointer<ISerializeType>(new CustomerJsonSerialize_QListTeacher()));
    this->SetKeyData("ss", &this->ss, QSharedPointer<ISerializeType>(new CustomerJsonSerialize_QListPStudent()));
}
