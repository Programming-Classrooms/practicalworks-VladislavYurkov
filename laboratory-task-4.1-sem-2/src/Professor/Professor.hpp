#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include "src/Person/Person.hpp"

class Professor : public Person
{
private:
    char* departament;
public:
    Professor();
    Professor(const char*, const char*);
    Professor(const Professor&);
    Professor(Professor&&);
    ~Professor() override;

    void setDepartament(const char*);

    char* getDepartament() const;

    void input() override;
    void print() const override;
};

#endif
