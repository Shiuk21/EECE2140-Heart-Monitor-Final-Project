#ifndef PERSON_H
#define PERSON_H

class Person
{
    private:
        int age;
    public:
        Person();
        void setAge(int a);
        int getAge() const;
};

#endif