#ifndef SECONDSESSIONSTUDENT_HPP
#define SECONDSESSIONSTUDENT_HPP
#include "src/FirstSessionStudent/FirstSessionStudent.hpp"

class SecondSessionStudent : public FirstSessionStudent
{
private:
    size_t* secondSessionMarks;
public:
    SecondSessionStudent(std::string, size_t, size_t, size_t, size_t*, size_t*);
    SecondSessionStudent(const SecondSessionStudent&);
    ~SecondSessionStudent() override;

    void setSecondSessionMark(size_t, size_t);

    size_t getSecondSessionMark(size_t) const;

    double getAverage() const override;

    friend std::ostream& operator<<(std::ostream&, const SecondSessionStudent&);
};

#endif
