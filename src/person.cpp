#include "person.h"

Person::Person()
{
    age = 0;
}

void Person::setAge(int a)
{
    age = a;
}

int Person::getAge() const
{
    return age;
}