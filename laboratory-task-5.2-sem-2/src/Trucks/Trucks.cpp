#include "Trucks.hpp"

Trucks::Trucks() :
number(0)
{
    names = nullptr;
}

Trucks::Trucks(std::string* initNames, size_t initNumber) :
number(initNumber)
{
    names = new std::string[number];
    for (size_t i = 0; i < number; ++i) {
        names[i] = initNames[i];
    }
}

Trucks::Trucks(const Trucks& rhs) :
number(rhs.number)
{
    names = new std::string[number];
    for (size_t i = 0; i < number; ++i)
    {
        names[i] = rhs.names[i];
    }
    
}

Trucks::~Trucks()
{
    delete[] names;
}

Trucks& Trucks::operator=(const Trucks& rhs)
{
    if (names != nullptr) {
        delete[] names;
    }
    number = rhs.number;
    names = new std::string[number];
    for (size_t i = 0; i < number; ++i) {
        names[i] = rhs.names[i];
    }
    return *this;
}

bool Trucks::operator==(const Trucks& rhs) 
{
    if (number != rhs.number) {
        return false;
    }
    for (size_t i = 0; i < number; ++i) {
        if (names[i] != rhs.names[i]) {
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& out, const Trucks& rhs)
{
    for (size_t i = 0; i < rhs.number; ++i)
    {
        out << rhs.names[i] << '\n';
    }
    return out;
}
