#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "src/Person/Person.hpp"

class Student : public Person
{
private:
    int32_t course;
    int32_t group;
public:
    Student();
    Student(const char*, int32_t, int32_t);
    Student(const Student&);
    Student(Student&&);
    ~Student() override;

    Student& operator=(const Student&);

    void setCourse(int32_t);
    void setGroup(int32_t);

    int32_t getCource() const;
    int32_t getGroup() const;

    void input() override;
    void print() const override;
};


#endif
