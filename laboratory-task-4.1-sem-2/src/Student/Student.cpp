#include "Student.hpp"

Student::Student() : Person(),
course(0),
group(0)
{}

Student::Student(const char* initFuLLName, int32_t initCourse, int32_t initGroup) : Person(initFuLLName),
course(initCourse),
group(initGroup)
{}

Student::Student(const Student& rhs) : Person(rhs),
course(rhs.course),
group(rhs.group)
{}

Student::Student(Student&& rhs) : Person(rhs)
{
    course = rhs.course;
    rhs.course = 0;
    group = rhs.group;
    rhs.group = 0;
}

Student::~Student()
{}

Student& Student::operator=(const Student& rhs)
{
    dynamic_cast<Person&>(*this) = dynamic_cast<const Person&>(rhs);
    group = rhs.group;
    course = rhs.course;
    return *this;
}

void Student::setCourse(int32_t newCource)
{
    course = newCource;
}

void Student::setGroup(int32_t newGroup)
{
    group = newGroup;
}

int32_t Student::getCource() const
{
    return course;
}

int32_t Student::getGroup() const
{
    return group;
}

void Student::input()
{
    this->Person::input();
    std::cout << "Input course: ";
    std::cin >> course;
    std::cout << "Input group: ";
    std::cin >> group;
}

void Student::print() const
{
    this->Person::print();
    std::cout << "Course: " << course << '\n';
    std::cout << "Group number: " << group << '\n';
}
