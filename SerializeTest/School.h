#ifndef SCHOOL_H
#define SCHOOL_H

#include "../SerializeLibSrc/AbsSerializeData.h"
#include "Teacher.h"
#include "Student.h"

class School: public AbsSerializeData
{
public:
    School();

    // AbsSerializeData interface
protected:
    void InitSerializeKeys();

public:
    QList<Teacher*> ts;
    QList<Student*> ss;
};

#endif // SCHOOL_H
