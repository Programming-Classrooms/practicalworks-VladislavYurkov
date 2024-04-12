#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include <cmath>


class MyString 
{
private:
    char *pStr;
    size_t size;
    size_t capacity;

    static void extend(MyString&);
public:

/*========Конструкторы и деструктор MyString========*/
    MyString();
    MyString(const char *);
    MyString(const MyString &);
    MyString(MyString &&);
    ~MyString();


/*======Методы изменения String======*/

// Метод расширения вместимости строки


// Метод добавления символа в конец строки

    void push_back(char);

// Метод добавления подстрокиd к концу строки

    void append(const char *);
    void append(const MyString &);

// Метод вставки подстроки в строку

    void insert(const char *, size_t);
    void insert(const MyString &, size_t);


// Метод замены подстроки

    void replace(const char *, size_t, size_t = 0);
    void replace(const MyString &, size_t, size_t = 0);

// Метод очистки String
    void clear();

/*===================Гетеры===================*/ 

    bool empty() const;
    char *c_str() const;
    size_t getSize() const;
    MyString substr(size_t, size_t = 0) const;


/*===================Операторы===================*/
   
// Операторы для работы со строкой

    MyString operator+(const MyString&) const;
    MyString& operator=(const MyString &);
    char& operator[](size_t);

// Операторы сравнения  

    bool operator==(const MyString &) const;
    bool operator!=(const MyString &) const;
    bool operator<(const MyString &) const;
    bool operator>(const MyString &) const;
    bool operator<=(const MyString &) const;
    bool operator>=(const MyString &) const;
   

// Операторы приобразвания типов

    explicit operator std::string() const;
    explicit operator int64_t() const;
    explicit operator double() const;


// Операторы ввода, вывода

    friend std::ostream& operator<<(std::ostream &, MyString &);
    friend std::istream& operator>>(std::istream &, MyString &);

};

#endif // MYSTRING_HPP
