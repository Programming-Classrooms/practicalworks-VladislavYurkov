#include "Person.hpp"

Person::Person() :
fullName(new char[1])
{
    fullName[0] = '\0';
}

Person::Person(const char* initFullName)
{
    fullName = new char[strlen(initFullName) + 1];
    strcpy(fullName, initFullName);
}

Person::Person(const Person& rhs)
{
    fullName = new char[strlen(rhs.fullName) + 1];
    strcpy(fullName, rhs.fullName);
}

Person::Person(Person&& moved)
{
    fullName = moved.fullName;
    moved.fullName = nullptr;
}

Person::~Person()
{
    delete[] fullName;
}

Person& Person::operator=(const Person& rhs)
{
    delete[] this->fullName;
    this->fullName = new char[strlen(rhs.fullName) + 1];
    strcpy(this->fullName, rhs.fullName);
    return *this;
}

void Person::setFullName(const char* newFullName)
{
    delete[] fullName;
    fullName = new char[strlen(newFullName) + 1];
    strcpy(fullName, newFullName);
}

char* Person::getFullName() const
{
    char* temp = new char[strlen(fullName) + 1];
    strcpy(temp, fullName);
    return temp;
}

void Person::input()
{
    std::cout << "Input name of this person: ";
    std::string buff;
    std::cin.ignore(1);
    std::getline(std::cin, buff);
    delete[] fullName;
    fullName = new char[strlen(buff.c_str()) + 1];
    strcpy(fullName, buff.c_str());
}

void Person::print() const
{
    std::cout << "Full name: " << fullName << '\n';
}
