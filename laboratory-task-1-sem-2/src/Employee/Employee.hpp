#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <string>
#include <iostream>

struct Employee
{
    std::string surname;
    size_t children;
};


bool isPosDigit(int32_t);

void fillEmployyes(Employee*&, size_t, int32_t*, size_t, std::string*);

void printEmployees(Employee*, size_t);

bool compareEmployees(const Employee&, const Employee&);

void employeesToTxt(std::ofstream&, Employee*, size_t);

void employeesToBin(std::ofstream&, Employee*, size_t);

void printBin(std::ifstream&, Employee*, size_t);

#endif
