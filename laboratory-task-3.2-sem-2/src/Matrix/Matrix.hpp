#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <iomanip>

class Matrix
{
private:
    double** pMtrx; //Указатель на матрицу
    size_t rows; //Количество строк
    size_t columns; //Количество столбцов

    void mtrxMemAlloc(double**&, size_t, size_t); //Выделение памяти под матрицу
public:

    /*=========================Конструкторы и деструктор=========================*/

    //Совмещённый конструктор по умолчанию и с параметрами
    Matrix(size_t = 1, size_t = 1);

    //Коструктор копирования
    Matrix(const Matrix&);
    
    //Конструктор перемещения
    Matrix(Matrix&&);
    
    //Деструктор
    ~Matrix();

    /*====================Операторы получения доступа к элементу===================*/

    //Доступ к элементу с изменением
    double* operator[](size_t ind);
    
    //Доступ к элементу без изменения
    double* operator[](size_t ind) const;

    /*==========================Операторы присваивания===========================*/

    //Копированием
    Matrix& operator=(const Matrix&);

    //Перемещением
    Matrix& operator=(Matrix&&);

    /*====================Составные арифметические операторы=====================*/

    //Составное умножение на число
    Matrix& operator*=(double);

    //Составное деление на число
    Matrix& operator/=(double);

    //Составное прибавление матрицы
    Matrix& operator+=(const Matrix&);

    //Составное вычитание матрицы
    Matrix& operator-=(const Matrix&);

    //Составное умножение на матрицу
    Matrix& operator*=(const Matrix&);

    /*==========================Арифметические операторы=========================*/

    //Умножение на число справа
    Matrix operator*(double) const;

    //Умножение на число слева
    friend Matrix operator*(double, const Matrix&);
    
    //Деление на число
    Matrix operator/(double) const;
    
    //Прибавление матрицы
    Matrix operator+(const Matrix&) const;
    
    //Вычитание матрицы
    Matrix operator-(const Matrix&) const;
    
    //Умножение на матрицу
    Matrix operator*(const Matrix&) const;

    /*============================Операторы сравнения============================*/

    //Оператор равно
    bool operator==(const Matrix&) const;

    //Оператор не равно
    bool operator!=(const Matrix&) const;

    /*=========================Операторы работы с потоком========================*/

    //Оператор ввода
    friend std::istream& operator>>(std::istream&, Matrix&);

    //Оператор вывода
    friend std::ostream& operator<<(std::ostream&, const Matrix&);
};

#endif
