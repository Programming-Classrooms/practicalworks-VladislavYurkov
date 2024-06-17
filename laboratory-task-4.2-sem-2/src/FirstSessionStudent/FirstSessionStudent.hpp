#ifndef FIRSTSESSIONSTUDENT_HPP
#define FIRSTSESSIONSTUDENT_HPP
#include "src/Student/Student.hpp"

class FirstSessionStudent : public Student
{
protected:
    size_t* firstSessionMarks;
public:
    FirstSessionStudent(std::string, size_t, size_t, size_t, size_t*);
    FirstSessionStudent(const FirstSessionStudent&);
    virtual ~FirstSessionStudent() override;

    void setFirstSessionMark(size_t, size_t);

    size_t getFirstSessionMark(size_t) const;

    double getAverage() const override;

    friend std::ostream& operator<<(std::ostream&, const FirstSessionStudent&);
};


#endif
