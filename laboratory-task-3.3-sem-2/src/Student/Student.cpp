#include "Student.hpp"


Student::Student() :
surname("No surname"),
graduate(0),
groupNumber(0),
marks(new uint32_t[3]),
averageMark(0)
{
    for (size_t i = 0; i < 3; ++i)
    {
        marks[i] = 0;
    }
    
}

Student::~Student()
{
    delete[] marks;
}

Student::Student(
    std::string initSurname, 
    uint32_t initGraduate, 
    uint32_t initGroupNumber, 
    uint32_t initFirstMark, 
    uint32_t initSecondMark, 
    uint32_t initThirdMark
) :
surname(initSurname),
graduate(initGraduate),
groupNumber(initGroupNumber),
marks(new uint32_t[3])
{
    marks[0] = initFirstMark;
    marks[1] = initSecondMark;
    marks[2] = initThirdMark;
    averageMark = static_cast<double>(marks[0] + marks[1] + marks[2]) / 3.0;
}

Student::Student(
    const char* initSurname, 
    uint32_t initGraduate, 
    uint32_t initGroupNumber, 
    uint32_t initFirstMark, 
    uint32_t initSecondMark, 
    uint32_t initThirdMark
) :
surname(initSurname),
graduate(initGraduate),
groupNumber(initGroupNumber),
marks(new uint32_t[3])
{
    marks[0] = initFirstMark;
    marks[1] = initSecondMark;
    marks[2] = initThirdMark;
    averageMark = static_cast<double>(marks[0] + marks[1] + marks[2]) / 3.0;
}

Student& Student::operator=(const Student& rhs)
{
    surname = rhs.surname;
    graduate = rhs.graduate;
    groupNumber = rhs.groupNumber;
    marks = new uint32_t[3];
    for (size_t i = 0; i < 3; ++i)
    {
        marks[i] = rhs.marks[i];
    }
    averageMark = rhs.averageMark;
    return *this;
}

bool Student::operator==(const Student& rhs)
{
    return 
    surname == rhs.surname &&
    graduate == rhs.graduate &&
    groupNumber == rhs.groupNumber &&
    marks[0] == rhs.marks[0] &&
    marks[1] == rhs.marks[1] &&
    marks[2] == rhs.marks[2] &&
    averageMark == averageMark;
}

void Student::setSurname(std::string newSurname)
{
    surname = newSurname;
}

void Student::setSurname(const char* newSurname)
{
    std::string newSurnameStr(newSurname);
    this->setSurname(newSurnameStr);
}

void Student::setGraduate(uint32_t newGraduate)
{
    graduate = newGraduate;
}

void Student::setGroupNumber(uint32_t newGroupNumber)
{
    groupNumber = newGroupNumber;
}

void Student::setMarks(uint32_t newFirstMark, uint32_t newSecondMark, uint32_t newThirdMark)
{
    marks[0] = newFirstMark;
    marks[1] = newSecondMark;
    marks[2] = newThirdMark;
    averageMark = static_cast<double>(marks[0] + marks[1] + marks[2]) / 3.0;
}

std::string Student::getSurname() const
{
    return surname;
}

uint32_t Student::getGraduate() const
{
    return graduate;
}

uint32_t Student::getGroupNumber() const
{
    return groupNumber;
}

uint32_t* Student::getMarks() const
{
    uint32_t* marksCpy = new uint32_t[3];
    for (size_t i = 0; i < 3; ++i)
    {
        marksCpy[i] = marks[i];
    }
    return marksCpy;
}

double Student::getAverageMark() const
{
    return averageMark;
}

std::ostream& operator<<(std::ostream& out, const Student& rhs)
{
    out << "Surname: " << rhs.surname << '\n';
    out << "Graduate: " << rhs.graduate << '\n';
    out << "Group number: " << rhs.groupNumber << '\n';
    out << "Marks: " << rhs.marks[0] << ' ' << rhs.marks[1] << ' ' << rhs.marks[2] << '\n';
    out << "Average mark: " << rhs.averageMark << '\n';
    return out;
}
