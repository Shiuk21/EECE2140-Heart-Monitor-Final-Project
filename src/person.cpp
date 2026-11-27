//Michael's Class
#include "person.h"

Person::Person()
{
    age = 18;
}

void Person::setAge(int a)
{
    age = a;
}

int Person::getAge() const
{
    return age;
}