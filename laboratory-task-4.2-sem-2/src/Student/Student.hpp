#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <iostream>
#include <cstdlib>
#include <string>


class Student
{
protected:
    size_t UID;
    static size_t counter;
    std::string name;
    size_t cource;
    size_t group;
    const size_t NUMBER_OF_GRADEBOOK;
public:
    Student() = delete;
    Student(std::string, size_t, size_t, size_t);
    Student(const Student&);
    virtual ~Student();
    
    void setName(std::string);
    void setName(const char*);
    void setCource(size_t);
    void setGroup(size_t);

    size_t getUID() const;
    std::string getName() const;
    size_t getCource() const;
    size_t getGroup() const;
    size_t getNumberOfGradebook() const;

    virtual double getAverage() const = 0;
    
    friend std::ostream& operator<<(std::ostream&, const Student&);
};

#endif
