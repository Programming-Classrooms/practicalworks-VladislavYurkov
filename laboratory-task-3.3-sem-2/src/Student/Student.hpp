#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <iostream>
#include <string.h>

class Student
{
private:
    std::string surname;
    uint32_t graduate;
    uint32_t groupNumber;
    uint32_t* marks;
    double averageMark;
public:
    Student();
    Student(std::string, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
    Student(const char*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
    ~Student();


    Student& operator=(const Student&);

    bool operator==(const Student&);

    void setSurname(std::string);
    void setSurname(const char*);
    void setGraduate(uint32_t);
    void setGroupNumber(uint32_t);
    void setMarks(uint32_t, uint32_t, uint32_t);

    std::string getSurname() const;
    uint32_t getGraduate() const;
    uint32_t getGroupNumber() const;
    uint32_t* getMarks() const;
    double getAverageMark() const;
    
    friend std::ostream& operator<<(std::ostream&, const Student&);
};

#endif
