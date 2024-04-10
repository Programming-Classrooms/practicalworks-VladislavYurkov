#include "Student.hpp"

size_t Student::counter = 0;

Student::Student(std::string initName, size_t initCource, size_t initGroup, size_t initNumberOfGradebook) :
UID(++counter),
name(initName),
cource(initCource),
group(initGroup),
NUMBER_OF_GRADEBOOK(initNumberOfGradebook)
{}

Student::Student(const Student& rhs) :
UID(++counter),
name(rhs.name),
cource(rhs.cource),
group(rhs.group),
NUMBER_OF_GRADEBOOK(rhs.NUMBER_OF_GRADEBOOK)
{}

Student::~Student()
{}

void Student::setName(std::string newName)
{
    name = newName;
}

void Student::setName(const char* newName)
{
    name = newName;
}

void Student::setCource(size_t newCource)
{
    cource = newCource;
}

void Student::setGroup(size_t newGroup)
{
    group = newGroup;
}

size_t Student::getUID() const
{
    return UID;
}

std::string Student::getName() const
{
    return name;
}

size_t Student::getCource() const
{
    return cource;
}

size_t Student::getGroup() const
{
    return group;
}

size_t Student::getNumberOfGradebook() const
{
    return NUMBER_OF_GRADEBOOK;
}

std::ostream& operator<<(std::ostream& out, const Student& rhs)
{
    out << "UID: " << rhs.UID << '\n';
    out << "Name: " << rhs.name << '\n';
    out << "Cource: " << rhs.cource << '\n';
    out << "Group number: " << rhs.group << '\n';
    out << "Number of gradebook: " << rhs.NUMBER_OF_GRADEBOOK << '\n';
    return out;
}
