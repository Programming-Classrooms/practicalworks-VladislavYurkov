#include "SecondSessionStudent.hpp"

SecondSessionStudent::SecondSessionStudent(
std::string initName, 
size_t initCource, 
size_t initGroup, 
size_t initNumberOfGradebook, 
size_t* initFirstSessionMarks, 
size_t* initSecondSessionMarks
) : 
FirstSessionStudent(initName, initCource, initGroup, initNumberOfGradebook, initFirstSessionMarks),
secondSessionMarks(new size_t[5])
{
    for (size_t i = 0; i < 5; ++i)
    {
        secondSessionMarks[i] = initSecondSessionMarks[i];
    }
    
}

SecondSessionStudent::SecondSessionStudent(const SecondSessionStudent& rhs) :
FirstSessionStudent(rhs),
secondSessionMarks(new size_t[5])
{
    for (size_t i = 0; i < 5; ++i)
    {
        secondSessionMarks[i] = rhs.secondSessionMarks[i];
    }
    
}

SecondSessionStudent::~SecondSessionStudent()
{
    delete[] secondSessionMarks;
}

void SecondSessionStudent::setSecondSessionMark(size_t ind, size_t newMark)
{
    if (ind > 4)
    {
        throw std::out_of_range("There are only 5 marks in second session!");
    }
    secondSessionMarks[ind] = newMark;
    
}

size_t SecondSessionStudent::getSecondSessionMark(size_t ind) const
{
    if (ind > 4)
    {
        throw std::out_of_range("There are only 5 marks in second session!");
    }
    return secondSessionMarks[ind];
}

double SecondSessionStudent::getAverage() const
{
    size_t marksSum = 0;
    for (size_t i = 0; i < 4; ++i)
    {
        marksSum += firstSessionMarks[i];
    }
    for (size_t i = 0; i < 5; ++i)
    {
        marksSum += secondSessionMarks[i];
    }
    return (static_cast<double>(marksSum) / 4.0);
    
}

std::ostream& operator<<(std::ostream& out, const SecondSessionStudent& rhs)
{
    out << *(dynamic_cast<const FirstSessionStudent*>(&rhs));
    out << "Second session marks: ";
    for (size_t i = 0; i < 5; ++i)
    {
        out << rhs.secondSessionMarks[i] << ' ';
    }
    out << '\n';
    return out;
} 
