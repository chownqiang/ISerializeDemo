#include "School.h"
#include "../SerializeLibSrc/ISerializeTypeJson.h"

School::School()
{

}

void School::InitSerializeKeys()
{
    this->SetKeyData("ts", &this->ts, NULL);
    this->SetKeyData("ss", &this->ss, NULL);
}
