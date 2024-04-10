#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <cstring>


class Person
{
protected:
    char* fullName;
public:
    Person();
    Person(const char*);
    Person(const Person&);
    Person(Person&&);
    virtual ~Person();

    virtual Person& operator=(const Person&);
    
    void setFullName(const char*);

    char* getFullName() const;

    virtual void input();
    virtual void print() const;
};

#endif
