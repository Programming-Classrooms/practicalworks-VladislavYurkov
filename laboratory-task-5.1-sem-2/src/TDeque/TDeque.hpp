#ifndef TDEQUE_HPP
#define TDEQUE_HPP
#include <iostream>
#include <cstring>
#include <typeinfo>

template<typename TInfo>
class TDeque /* дек – двустороння очередь */
{
protected:
struct TDequeItem // элемент дека
{
TDequeItem(); // конструктор по умолчанию
TDequeItem(const char*); // конструктор для char*
TDequeItem(const TInfo&); // конструктор с параметрами
~TDequeItem(); // деструктор
TInfo Info; // данные
TDequeItem* next; // указатель на следующий элемент
TDequeItem* prev; // указатель на предыдущий элемент
};
TDequeItem* front; //ссылка на первый элемент дэка
TDequeItem* rear; //ссылка на последний элемент дэка
int size; // количество элементов в деке
void Erase(); // удаление всех элементов
void Clone(const TDeque&); // копирование дека в текущий
void DeleteItem(TDequeItem*); // удаление элемента по указателю
void* PtrByIndex(unsigned) const; // указатель на элемент с заданным индексом
public:
TDeque(); // конструктор
TDeque(const TDeque &); // конструктор копирования
virtual ~TDeque(); // деструктор
void InsFront(const TInfo&); // включить элемент в голову дека
void InsFront(const char*); // специаллизация для char*
void InsRear(const TInfo&); // включить элемент в хвост дека
void InsRear(const char*); // специаллизация для char*
bool DelFront(); // исключить элемент из головы дека
bool DelRear(); // исключить элемент из хвоста дека
const TDeque& operator = (const TDeque &);// оператор присваивания
const TInfo& GetByIndex(unsigned)const; // получить элемент по индексу
void SetByIndex(TInfo, unsigned); // изменить элемент по индексу
void Browse(void(TInfo&)); // просмотр с изменением элементов
void Browse(void(TInfo const)); // просмотр без изменения элементов
};

#include "TDeque.inl"

#endif
