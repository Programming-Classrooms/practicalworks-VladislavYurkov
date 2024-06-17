#include "src/List/List.hpp"

List::List() :
Head(nullptr)
{}

List::List(const List& rhs)
{
    Head = nullptr;
    Element* current = rhs.Head;
    while(current != nullptr) {
        this->insertLast(current->data);
        current = current->Next;
    }
}

List::~List()
{
    Element* current = Head;
    Element* buff;
    while (current != nullptr)
    {
        buff = current;
        current = current->Next;
        delete buff;
    }
}

List& List::operator=(const List& rhs)
{
    delete this;
    Head = nullptr;
    Element* current = rhs.Head;
    while (current != nullptr)
    {
        this->insertLast(current->data);
    }
    return *this;
}

List& List::insertFirst(const Student& data)
{
    Element* second = Head;
    Head = new Element;
    Head->data = data;
    Head->Next = second;
    return *this;
}

List& List::insertLast(const Student& data)
{
    if (Head == nullptr) {
        Head = new Element;
        Head->Next = nullptr;
        Head->data = data;
        return *this;
    }
    Element* current = Head;
    while (current->Next != nullptr)
    {
        current = current->Next;
    }
    current->Next = new Element;
    current = current->Next;
    current->Next = nullptr;
    current->data = data;
    return *this;
}

List& List::deleteFirst()
{
    if (Head == nullptr) {
        throw std::logic_error("List is empty\n");
    }
    Element* buff = Head;
    Head = Head->Next;
    delete buff;
    return *this;
}

List& List::deleteLast()
{
    if (Head == nullptr) {
        throw std::logic_error("List is empty\n");
    }
    Element* current = Head;
    if (current->Next == nullptr) {
        this->deleteFirst();
        return *this;
    }
    while (current->Next->Next != nullptr)
    {
        current = current->Next;
    }
    delete current->Next;
    current->Next = nullptr;
    return *this;
}

List& List::deleteElement(const Student& data)
{
    size_t index = this->find(data);
    if (index == (size_t)-1) {
        throw std::logic_error("Element doesn't exist");
    }
    if (index == 0) {
        this->deleteFirst();
        return *this;
    }
    Element* current = Head;
    for (size_t i = 0; i < index - 1; ++i)
    {
        current = current->Next;
    }
    Element* nextNext = current->Next->Next;
    delete current->Next;
    current->Next = nextNext;
    return *this;
}

size_t List::find(const Student& data) {
    Element* current = Head;
    size_t index = 0;
    while (current != nullptr)
    {
        if (current->data == data) {
            return index;
        }
        current = current->Next;
        ++index;
    }
    return -1;
}

void List::watch()
{
    Element* current = Head;
    while (current != nullptr)
    {
        std::cout << current->data;
        current = current->Next;
    }
    
}

void List::modify(void modFunc(Student& rhs))
{
    Element* current = Head;
    while (current != nullptr)
    {
        modFunc(current->data);
        current = current->Next;
    }
}

std::ostream& operator<<(std::ostream& out, const List& rhs)
{
    Element* current = rhs.Head;
    while (current != nullptr)
    {
        out << current->data << '\n';
        current = current->Next;
    }
    return out;
}
