#ifndef STUDENT_H
#define STUDENT_H

#include "../SerializeLibSrc/AbsSerializeData.h"

class Student : public AbsSerializeData
{
public:



    // AbsSerializeData interface
protected:
    virtual void InitSerializeKeys();

    //field
public:
    QString name;
    int age;
    QString classroom;
};

#endif // STUDENT_H
