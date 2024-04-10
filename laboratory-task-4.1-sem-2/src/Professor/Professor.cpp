#include "Professor.hpp"

Professor::Professor() : 
Person(),
departament(new char[1])
{
    departament[0] = '\0';
}

Professor::Professor(const char* initFullName, const char* initDepartament) : Person(initFullName)
{
    departament = new char[strlen(initDepartament) + 1];
    strcpy(departament, initDepartament);
}

Professor::Professor(const Professor& rhs) : Person(rhs)
{
    departament = new char[strlen(rhs.departament) + 1];
    strcpy(departament, rhs.departament);
}

Professor::Professor(Professor&& moved) : Person(moved)
{
    departament = moved.departament;
    moved.departament = nullptr;
}

Professor::~Professor() 
{
    delete[] departament;
}

void Professor::setDepartament(const char* newDepartament) {
    if (departament != nullptr) {
        delete[] departament;
    }
    departament = new char[strlen(newDepartament) + 1];
    strcpy(departament, newDepartament);
}

char* Professor::getDepartament() const
{
    char* temp = new char[strlen(departament) + 1];
    strcpy(temp, departament);
    return temp;
}

void Professor::input()
{
    this->Person::input();
    std::cout << "Input departament name: ";
    std::string buff;
    std::getline(std::cin, buff);
    delete[] departament;
    departament = new char(buff.length() + 1);
    strcpy(departament, buff.c_str());
}

void Professor::print() const
{
    this->Person::print();
    std::cout << "Departament: " << departament << '\n';
}
