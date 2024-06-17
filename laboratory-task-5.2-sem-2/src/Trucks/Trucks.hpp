#ifndef TRUCKS_HPP
#define TRUCKS_HPP
#include <iostream>
#include <cstdint>
#include <string>

class Trucks
{
private:
    std::string* names; //Названия грузовиков
    size_t number; //Количество грузовиков
public:
    Trucks(); //Коструктор по умолчанию
    Trucks(std::string*, size_t); //Коструктор по массиву и его длинне
    Trucks(const Trucks&); //Конструктор копирования
    ~Trucks(); //Деструктор

    Trucks& operator=(const Trucks&); //Оператор присваивания

    bool operator==(const Trucks&); //Оператор сравнения

    friend std::ostream& operator<<(std::ostream&, const Trucks&); //Вывод в поток 
};

#endif
