#ifndef CIRCULARQUEUE_HPP
#define CIRCULARQUEUE_HPP
#include <iostream>
#include <cstdint>
#include <cstring>


template<typename T>
class CircularQueue
{
private:
    size_t capacity; //Максимальный размер
    T* queue; //Динамический массив
    int32_t front; //Индекс первого элемента
    int32_t rear; //Индекс последнего элемента

    bool isEmpty() const; //Проверка на пустоту
    bool isFull() const; //Проверка на заполненность
public:
    CircularQueue(); //Конструктор по умолчанию
    CircularQueue(unsigned); //Коструктор с заданием максимального размера
    CircularQueue(const CircularQueue&); // Конструктор копирования
    ~CircularQueue(); //Деструктор

    void push_back(const char*); //Специализация push_back под char*
    void push_back(const T&); //Вставка в конец очереди
    void pop_front(); //Удаление из начала очереди

    T operator[](unsigned ind) const; //Оператор доступа к элементу

    CircularQueue& operator=(const CircularQueue&); //Оператор присваивания

    void print(std::ostream&) const; //Функция выводящая очередь в переданный поток

    T getByIndex(unsigned) const; //Метод получения элемента по индексу
    int32_t find(const char*) const; //Специализация find под char*
    int32_t find(const T&) const; //Получение индекса элемента или -1 в случае неудачи
};

#include "CircularQueue.inl"

#endif
