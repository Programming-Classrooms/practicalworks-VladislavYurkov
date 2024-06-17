#include "Employee.hpp"
#include "src/Surnames/Surnames.hpp"

bool isPosDigit(int32_t num)
{
    return (0 <= num) && (num <= 9);
}

void fillEmployyes(Employee*& employees, size_t employeesSize, int32_t* allNumbers, size_t allNumbersSize, std::string* allSurnames)
{
size_t allNumbersElemInd = 0;
for (size_t i = 0; i < employeesSize;) {
    if (allNumbersElemInd != allNumbersSize) {
        if(isPosDigit(allNumbers[allNumbersElemInd])) {
            employees[i].surname = allSurnames[i];
            employees[i].children = allNumbers[allNumbersElemInd];
            ++i;
        }
        ++allNumbersElemInd;
    }
    else {
        int32_t buff;
        std::cout << "Enter children number for " << allSurnames[i] << ": ";
        std::cin >> buff;
        if (isPosDigit(buff)) {
            employees[i].surname = allSurnames[i];
            employees[i].children = buff;
            ++i;
        }
        else {
            std::cout << "This is not a positive digit\n";
        }
    }
}
}

void printEmployees(Employee* employees, size_t employeesSize) {
    for (size_t i = 0; i < employeesSize; ++i)
    {
        std::cout << employees[i].surname << ' ' << employees[i].children << '\n';
    }
    
}

bool compareEmployees(const Employee& lhs, const Employee& rhs) {
    if(compareSurnames(lhs.surname, rhs.surname)) {
        return true;
    }
    if(compareSurnames(rhs.surname, lhs.surname)) {
        return false;
    }
    if(rhs.children > lhs.children) {
        return true;
    }
    return false;
}

void employeesToTxt(std::ofstream& out, Employee* employees, size_t employeesSize)
{
    for (size_t i = 0; i < employeesSize; ++i)
    {
        out << employees[i].surname << ' ' << employees[i].children << '\n';
    }
    
}

void employeesToBin(std::ofstream& out, Employee* employees, size_t employeesSize)
{
    for (size_t i = 0; i < employeesSize; ++i) {
        std::string buffstr = employees[i].surname + std::to_string(employees[i].children);
        char * buff = (char*)buffstr.c_str();
        size_t buffSize = sizeof(employees[i].surname)/8;
        out.write(buff,buffSize);
    }
}

void printBin(std::ifstream& in, Employee* employees, size_t employeesSize)
{
    in.seekg(0);
    char* buff;
    for (size_t i = 0; i < employeesSize; ++i) {
        size_t sizeofBuff = (sizeof(employees[i].surname))/8;
        buff = new char[sizeofBuff];
        in.read(buff, sizeofBuff);
        buff[sizeofBuff] = '\0';
        std::cout << buff << '\n';
        buff = nullptr;
    }

}
