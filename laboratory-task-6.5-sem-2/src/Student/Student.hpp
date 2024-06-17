#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Student
{
private:
    std::string fullName;
    size_t course;
    size_t group;
public:
    Student();
    Student(std::string);
    virtual ~Student();

    friend bool isEarlierInAlphabet(const Student&, const Student&);
    friend bool isEarlierInGroups(const Student&, const Student&);

    friend void printStudentsInFile(const std::vector<Student>&, std::ofstream&); 
};

void checkFile(std::ifstream&);

void readStudents(std::vector<Student>&, std::ifstream&);

bool isEarlierInAlphabet(const Student&, const Student&);

void sortByAlphabet(std::vector<Student>&);

bool isEarlierInGroups(const Student&, const Student&);

void sortByGroups(std::vector<Student>&);

void printStudentsInFile(const std::vector<Student>&, std::ofstream&);

#endif
