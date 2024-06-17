#include "TDeque.hpp"

void copyCharPtr(char* &dest, const char* src)
{
    delete[] dest;
    dest = new char[strlen(src) + 1];
    strcpy(dest, src);
}

template<>
TDeque<char*>::TDequeItem::TDequeItem() :
next(nullptr),
prev(nullptr)
{
    Info = new char('\0');
}

template<typename T>
TDeque<T>::TDequeItem::TDequeItem() :
next(nullptr),
prev(nullptr),
Info(0)
{}

template<>
TDeque<char*>::TDequeItem::TDequeItem(const char* initInfo) :
next(nullptr),
prev(nullptr)
{
    copyCharPtr(Info, initInfo);
}

template<typename T>
TDeque<T>::TDequeItem::TDequeItem(const T& initInfo) :
next(nullptr),
prev(nullptr)
{
    Info = initInfo;
}

template<typename T>
TDeque<T>::TDequeItem::~TDequeItem()
{}

template<>
TDeque<char*>::TDequeItem::~TDequeItem()
{
    delete Info;
}

template<typename T>
void TDeque<T>::Erase()
{
    while (size > 0)
    {
        DelFront();
    }
}

template<typename T>
void TDeque<T>::Clone(const TDeque<T>& src)
{
    this->Erase();
    TDequeItem current = src.front;
    for (size_t i = 0; i < src.size; ++i)
    {
        this->InsRear(current.Info);
        current = current.next;
    }
}

template<typename T>
void TDeque<T>::DeleteItem(TDequeItem* ptr)
{
    if (ptr->prev == nullptr && ptr->next != nullptr) {
        ptr->next->prev = nullptr;
    }
    else if (ptr->prev != nullptr && ptr->next == nullptr) {
        ptr->prev->next = nullptr;
    }
    else if (ptr->prev != nullptr && ptr->next != nullptr) {
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
    }
    delete ptr;
    --size;
}

template<typename T>
void* TDeque<T>::PtrByIndex(unsigned ind) const
{
    TDequeItem* current = front;
    for (size_t i = 0; i < ind; ++i)
    {
        current = current->next;
    }
    return current;
}

template<typename T>
TDeque<T>::TDeque() :
front(nullptr),
rear(nullptr),
size(0)
{}

template<typename T>
TDeque<T>::~TDeque()
{
    Erase();
}

template<>
void TDeque<char*>::InsFront(const char* value)
{
    if (size == 0) {
        front = new TDequeItem(value);
        rear = front;
    }
    else {
        front->prev = new TDequeItem(value);
        front->prev->next = front;
        front = front->prev;
    }
    ++size;
}

template<typename T>
void TDeque<T>::InsFront(const T& value)
{
    if (size == 0) {
        front = new TDequeItem(value);
        rear = front;
    }
    else {
        front->prev = new TDequeItem(value);
        front->prev->next = front;
        front = front->prev;
    }
    ++size;
}

template<>
void TDeque<char*>::InsRear(const char* value)
{
    if (size == 0) {
        InsFront(value);
    }
    else {
        rear->next = new TDequeItem(value);
        rear->next->prev = rear;
        rear = rear->next;
    }
    ++size;
}

template<typename T>
void TDeque<T>::InsRear(const T& value)
{
    if (size == 0) {
        InsFront(value);
    }
    else {
        rear->next = new TDequeItem(value);
        rear->next->prev = rear;
        rear = rear->next;
    }
    ++size;
}

template<typename T>
bool TDeque<T>::DelFront()
{
    if (size == 0) {
        return false;
    }
    if (size == 1) {
        DeleteItem(front);
        front = nullptr;
        rear = nullptr;
    }
    if (size >= 2) 
    {
        front = front->next;
        DeleteItem(front->prev);
        front->prev = nullptr;
    }
    return true;
}

template<typename T>
bool TDeque<T>::DelRear()
{
    if (size == 0)
    {
        return false;
    }
    if (size == 1)
    {
        DeleteItem(rear);
        rear = nullptr;
        front = nullptr;
    }
    if (size >= 2)
    {
        rear = rear->prev;
        DeleteItem(rear->next);
        rear->next = nullptr;
    }
    return true;
}

template<typename T>
const TDeque<T>& TDeque<T>::operator=(const TDeque<T> &rhs)
{
    this->Clone(rhs);
    return *this;
}

template<typename T>
const T& TDeque<T>::GetByIndex(unsigned ind) const
{
    return static_cast<TDequeItem*>(PtrByIndex(ind))->Info;
}

template<typename T>
void TDeque<T>::SetByIndex(T newValue, unsigned ind)
{
    copyCharPtr(static_cast<TDequeItem*>(PtrByIndex(ind))->Info,newValue);
}

template<typename T>
void TDeque<T>::Browse(void change(T& elem))
{
    for (size_t i = 0; i < size; ++i)
    {
        SetByIndex(change(GetByIndex(i)),i);
    }
}

template<typename T>
void TDeque<T>::Browse(void view(T const elem))
{
    for (size_t i = 0; i < size; ++i)
    {
        view(GetByIndex(i));
    }
}
