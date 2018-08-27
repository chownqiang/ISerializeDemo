#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "Student.h"
#include "Teacher.h"
#include "../SerializeLibSrc/AbsSerializeData.h"


class Classroom: public AbsSerializeData
{
public:
    Classroom();

// AbsSerializeData interface
protected:
    void InitSerializeKeys();


public:
    QString name;
    Teacher * t;
    Student s;

};

#endif // CLASSROOM_H
