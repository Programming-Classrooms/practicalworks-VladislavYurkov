#include "FirstSessionStudent.hpp"

FirstSessionStudent::FirstSessionStudent(
std::string initName, 
size_t initCource, 
size_t initGroup, 
size_t initNumberOfGradeBook, 
size_t* initFirstSessionMarks
) : 
Student(initName, initCource, initGroup, initNumberOfGradeBook),
firstSessionMarks(new size_t[4])
{
    for (size_t i = 0; i < 4; ++i)
    {
        firstSessionMarks[i] = initFirstSessionMarks[i];
    }
}

FirstSessionStudent::FirstSessionStudent(const FirstSessionStudent& rhs) :
Student(rhs),
firstSessionMarks(new size_t[4])
{
    for (size_t i = 0; i < 4; ++i)
    {
        firstSessionMarks[i] = rhs.firstSessionMarks[i];
    }
    
}

FirstSessionStudent::~FirstSessionStudent()
{
    delete[] firstSessionMarks;
}

void FirstSessionStudent::setFirstSessionMark(size_t ind, size_t newMark)
{
    if (ind > 3) {
        throw std::out_of_range("There are only 4 marks in first session");
    }
    firstSessionMarks[ind] = newMark;
}

size_t FirstSessionStudent::getFirstSessionMark(size_t ind) const
{
    if (ind > 3) {
        throw std::out_of_range("There are only 4 marks in first session");
    }
    return firstSessionMarks[ind];
}

double FirstSessionStudent::getAverage() const
{
    size_t marksSum = 0;
    for (size_t i = 0; i < 4; ++i)
    {
        marksSum += firstSessionMarks[i];
    }
    return (static_cast<double>(marksSum) / 4.0);
}

std::ostream& operator<<(std::ostream& out, const FirstSessionStudent& rhs)
{
    out << (*(dynamic_cast<const Student*>(&rhs)));
    out << "First session marks: ";
    for (size_t i = 0; i < 4; ++i)
    {
        out << rhs.firstSessionMarks[i] << ' ';
    }
    out << '\n';
    return out;
}

