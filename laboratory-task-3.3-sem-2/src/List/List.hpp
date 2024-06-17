#ifndef LIST_HPP
#define LIST_HPP
#include "src/Student/Student.hpp"

struct Element
{
    Student data;
    Element* Next;
};

class List
{
private:
    Element* Head;
public:
    List();
    List(const List&);
    ~List();

    List& operator=(const List&);

    List& insertFirst(const Student&);
    List& insertLast(const Student&);

    List& deleteFirst();
    List& deleteLast();
    List& deleteElement(const Student&);

    size_t find(const Student&);

    void watch();
    void modify(void (Student&));

    friend std::ostream& operator<<(std::ostream&, const List&);
};

#endif
