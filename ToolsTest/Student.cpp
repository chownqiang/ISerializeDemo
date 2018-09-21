#include "Student.h"
#include "../SerializedTools/SerializedTool.h"

Student::Student()
{
    RegistorType type = NEWREGISTORTYPE(Student);
    REGISTORFIELD(type, this, age, nullptr);
    REGISTORFIELD(type, this, name, nullptr);

    SerializedTool::Instance()->Registor(type);
}
