#include "String.hpp"

/*================================================*/
/*=======Конструкторы и деструктор String=========*/
/*================================================*/

MyString::MyString() :
size(0),
capacity(2)
{
    pStr = new char[2];
    pStr[0] = '\0';
}

MyString::MyString(const char* line) :
size(strlen(line)),
capacity(size + size/2)
{
    pStr = new char[capacity + 1];
    strcpy(pStr, line);
}

MyString::MyString(const MyString& src) :
size(src.size),
capacity(src.capacity)
{
    pStr = new char[capacity];
    strcpy(pStr, src.pStr);
}

MyString::MyString(MyString&& src) :
size(src.size),
capacity(src.capacity)
{
    pStr = src.pStr;
    src.size = 0;
    src.capacity = 0;
    src.pStr = nullptr;
}

MyString::~MyString()
{
    delete[] pStr;
}

/*================================================*/
/*============Методы изменения String=============*/
/*================================================*/

/*=======Метод расширения вместимости строки======*/

void MyString::extend(MyString& rhs)
{
        char* temp = new char[rhs.capacity];
        strcpy(temp, rhs.pStr);
        delete[] rhs.pStr;
        rhs.capacity += rhs.capacity / 2;
        rhs.pStr = new char[rhs.capacity];
        strcpy(rhs.pStr, temp);
        delete[] temp;
}

/*=====Метод добавления символа в конец строки====*/

void MyString::push_back(char letter)
{
    if ((size + 1) == capacity) {
        extend(*this);
    }

    pStr[size++] = letter;
    pStr[size] = '\0';
}

/*====Метод добавления подстроки к концу строки===*/

void MyString::append(const char* line)
{
    size_t lineSize = strlen(line);
    for(size_t i = 0; i < lineSize; ++i) {
        (*this).push_back(line[i]);
    }
}

void MyString::append(const MyString& rhs)
{
    for(size_t i = 0; i < rhs.size; ++i) {
        (*this).push_back(rhs.pStr[i]);
    }
}

/*========Метод вставки подстроки в строку========*/

void MyString::insert(const char* rhs, size_t substrSize)
{
    if (substrSize > strlen(rhs)) {
        throw std::logic_error("Substring is bigger than original one");
    }
    char* substr = new char[substrSize + 1];
    for (size_t i = 0; i < substrSize; ++i) {
        substr[i] = rhs[i];
    }
    substr[substrSize] = '\0';
    this->append(substr);
}

void MyString::insert(const MyString& rhs, size_t substrSize)
{
    if (substrSize > rhs.size) {
        throw std::logic_error("Substring is bigger than original one");
    }
    char* substr = new char[substrSize + 1];
    for (size_t i = 0; i < substrSize; ++i) {
        substr[i] = rhs.pStr[i];
    }
    substr[substrSize] = '\0';
    this->append(substr);
}

/*=============Метод замены подстроки=============*/

void MyString::replace(const char* line, size_t quantity, size_t begin)
{
    if (this->size < (begin + quantity)) {
        throw std::logic_error("Replacing out of range");
    }
    size_t lineSize = strlen(line);
    if (lineSize < quantity) {
        throw std::logic_error("Replacing string is not so big");
    }
    for (size_t i = 0; i < lineSize; ++i) {
        (this->pStr)[i + begin] = line[i];
    }
}

void MyString::replace(const MyString& str, size_t quantity, size_t begin)
{
    if (this->size < (begin + quantity)) {
        throw std::logic_error("Replacing out of range");
    }
    if (str.size < quantity) {
        throw std::logic_error("Replacing string is not so big");
    }
    for (size_t i = 0; i < quantity; ++i) {
        (this->pStr)[i + begin] = (str.pStr)[i];
    }
}

/*==============Метод очистки строки==============*/

void MyString::clear()
{
    size = 0;
    capacity = 2;
    pStr = new char[2];
    pStr[0] = '\0';
}

/*================================================*/
/*=====================Гетеры=====================*/ 
/*================================================*/

bool MyString::empty() const
{
    return !size;
}

char* MyString::c_str() const
{
    char* temp = new char[size + 1];
    strcpy(temp, pStr);
    return temp;
}

size_t MyString::getSize() const
{
    return size;
}

MyString MyString::substr(size_t quantity, size_t begin) const
{
    if ((begin + quantity) > size) {
        throw std::logic_error("Substring gone out of string");
    }
    char* subStr = new char[quantity + 1];
    for (size_t i = 0; i < quantity; ++i) {
        subStr[i] = pStr[begin + i];
    }
    subStr[quantity] = '\0';
    MyString temp(subStr);
    return temp;
}

/*================================================*/
/*===================Операторы====================*/
/*================================================*/

/*========Операторы для работы со строкой========*/

MyString MyString::operator+(const MyString& rhs) const
{
    MyString temp;
    temp.append(*this);
    temp.append(rhs);
    return temp;
}

MyString& MyString::operator=(const MyString& rhs)
{
    if (this == &rhs) {
        return *this;
    }
    this->clear();
    this->append(rhs);
    return *this;
}

char& MyString::operator[](size_t index)
{
    if (index >= size) {
        throw std::logic_error("Index out of string");
    }
    return pStr[index];
}

/*==============Операторы сравнивания=============*/

bool MyString::operator==(const MyString& rhs) const
{
    return !(*this != rhs);
}

bool MyString::operator!=(const MyString& rhs) const
{
    return strcmp(pStr, rhs.pStr);
}

bool MyString::operator<(const MyString& rhs) const
{
    return (strcmp(pStr, rhs.pStr) < 0);
}

bool MyString::operator>(const MyString& rhs) const
{
    return (*this != rhs) && !(*this < rhs);
}

bool MyString::operator<=(const MyString& rhs) const
{
    return !(*this > rhs);
}

bool MyString::operator>=(const MyString& rhs) const
{
    return !(*this < rhs);
}

/*==========Операторы приобразвания типов=========*/

MyString::operator std::string() const
{
    std::string temp(pStr);
    return temp;
}

MyString::operator int64_t() const
{
    return std::stoll((std::string) *this);
}

MyString::operator double() const
{
    return std::stod((std::string) *this);
}

/*=============Операторы ввода, вывода============*/

std::ostream& operator<<(std::ostream& out, MyString& rhs)
{
    if (rhs.empty()) {
        out << "";
    }
    else {
        out << (std::string)rhs;
    }
    return out;
}

std::istream& operator>>(std::istream& in, MyString& rhs)
{
    std::string strIn;
    in >> strIn;
    rhs.clear();
    rhs.append(strIn.c_str());
    return in;
}
