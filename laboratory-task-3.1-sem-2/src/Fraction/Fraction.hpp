#ifndef FRACTION_HPP
#define FRACTION_HPP


#include <iostream>
#include <cstdint>
#include <cmath>
#include <string>
#include <exception>


class Fraction
{
private:
    int32_t numerator; //Числитель
    uint32_t denominator; //Знаменатель

    Fraction reduce(); //Сокращение
public:
    /*================== Конструкторы ====================*/
    Fraction(); //По умолчанию
    Fraction(int32_t, int32_t); //С параметрами
    Fraction(const Fraction&); //Копированием
    Fraction(Fraction&&); //Перемещения

    ~Fraction(); //Деструктор

    /*============== Операторы присваивания ==============*/
    Fraction& operator=(int32_t); //К числу
    Fraction& operator=(const Fraction&); //К дроби
    Fraction& operator=(Fraction&&); //С перемещением

    /*====================================================*/
    /*============== Арифметические операции =============*/
    /*====================================================*/

    /*================== С числом справа =================*/
    Fraction operator+(int32_t);
    Fraction operator-(int32_t);
    Fraction operator*(int32_t);
    Fraction operator/(int32_t);

    /*===================== С дробью =====================*/
    Fraction operator+(const Fraction&);
    Fraction operator-(const Fraction&);
    Fraction operator*(const Fraction&);
    Fraction operator/(const Fraction&);

    /*================== С числом слева ==================*/
    friend Fraction operator+(int32_t, const Fraction&);
    friend Fraction operator-(int32_t, const Fraction&);
    friend Fraction operator*(int32_t, const Fraction&);
    friend Fraction operator/(int32_t, const Fraction&);

    /*====================================================*/
    /*========= Составные операторы присваивания =========*/
    /*====================================================*/

    /*===================== С числом =====================*/
    Fraction& operator+=(int32_t);
    Fraction& operator-=(int32_t);
    Fraction& operator*=(int32_t);
    Fraction& operator/=(int32_t);

    /*===================== С дробью =====================*/
    Fraction& operator+=(const Fraction&);
    Fraction& operator-=(const Fraction&);
    Fraction& operator*=(const Fraction&);
    Fraction& operator/=(const Fraction&);

    /*====================================================*/
    /*=============== Операторы сравнения ================*/
    /*====================================================*/

    /*===================== С числом =====================*/
    bool operator==(int32_t);
    bool operator!=(int32_t);
    bool operator<(int32_t);
    bool operator>(int32_t);
    bool operator<=(int32_t);
    bool operator>=(int32_t);
    
    /*===================== С дробью ======================*/
    bool operator==(const Fraction&);
    bool operator!=(const Fraction&);
    bool operator<(const Fraction&);
    bool operator>(const Fraction&);
    bool operator<=(const Fraction&);
    bool operator>=(const Fraction&);
    
    /*=============== Инкремент и декремент ===============*/
    Fraction& operator++(); //Префиксный инкремент
    Fraction operator++(int); //Постфиксный инкремент
    Fraction& operator--(); //Префиксный декремент
    Fraction operator--(int); //Постфиксный декремент


    friend const Fraction operator-(const Fraction&); //Унарный минус


    friend const Fraction operator!(const Fraction&); //Получение обратной дроби


    double toDouble(); //Преобразование к действительному числу


    /*============== Операторы ввода/вывода ===============*/
    friend std::ostream& operator<<(std::ostream &, const Fraction &);
    friend std::istream& operator>>(std::istream&, Fraction&);

};

#endif
