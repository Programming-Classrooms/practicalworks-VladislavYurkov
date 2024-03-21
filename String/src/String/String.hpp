#ifndef STRING_HPP
#define STRING_HPP

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include <cmath>


class String 
{
private:
    char *pStr;
    size_t size;
    size_t capacity;

    static void extend(String&);
public:

/*========Конструкторы и деструктор String========*/
    String();
    String(const char *);
    String(const String &);
    String(String &&);
    ~String();


/*======Методы изменения String======*/

// Метод расширения вместимости строки


// Метод добавления символа в конец строки

    void push_back(char);

// Метод добавления подстрокиd к концу строки

    void append(const char *);
    void append(const String &);

// Метод вставки подстроки в строку

    void insert(const char *, size_t);
    void insert(const String &, size_t);


// Метод замены подстроки

    void replace(const char *, size_t, size_t = 0);
    void replace(const String &, size_t, size_t = 0);

// Метод очистки String
    void clear();

/*===================Гетеры===================*/ 

    bool empty() const;
    char *c_str() const;
    size_t getSize() const;
    String substr(size_t, size_t = 0) const;


/*===================Операторы===================*/
   
// Операторы для работы со строкой

    String operator+(const String&) const;
    String& operator=(const String &);
    char& operator[](size_t);

// Операторы сравнения  

    bool operator==(const String &) const;
    bool operator!=(const String &) const;
    bool operator<(const String &) const;
    bool operator>(const String &) const;
    bool operator<=(const String &) const;
    bool operator>=(const String &) const;
   

// Операторы приобразвания типов

    explicit operator std::string() const;
    explicit operator int64_t() const;
    explicit operator double() const;


// Операторы ввода, вывода
    friend std::ostream& operator<<(std::ostream &, String &);
    friend std::istream& operator>>(std::istream &, String &);

};

#endif
