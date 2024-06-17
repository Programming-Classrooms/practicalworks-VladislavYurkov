#include "CircularQueue.hpp"

template<typename T>
bool CircularQueue<T>::isEmpty() const
{
    return (front == -1 && rear == -1);
}

template<typename T>
bool CircularQueue<T>::isFull() const
{
    return (front == (rear + 1)) || (front == 0 && rear == capacity - 1);
}

template<typename T>
CircularQueue<T>::CircularQueue() :
capacity(100),
front(-1),
rear(-1)
{
    queue = new T[capacity];
}

template<typename T>
CircularQueue<T>::CircularQueue(unsigned initCapacity) :
capacity(initCapacity),
front(-1),
rear(-1)
{
    queue = new T[capacity];
}

template<typename T>
CircularQueue<T>::CircularQueue(const CircularQueue& rhs) :
capacity(rhs.capacity)
{
    queue = new T[capacity];
    *this = rhs;
}

template<>
CircularQueue<char *>::~CircularQueue()
{
    if (!isEmpty()) {
        int32_t current = front;
        while (current != (rear + 1)) {
            if (current == capacity) {
                current = 0;
            }
            delete[] queue[current];
            ++current;
        }
    }
    delete[] queue;
}

template<typename T>
CircularQueue<T>::~CircularQueue()
{
    delete[] queue;
}

template<>
void CircularQueue<char*>::push_back(const char* line)
{
    if (this->isFull()) {
        throw std::logic_error("Can't push to full queue!");
    }
    if (this->isEmpty()) {
        ++front;
    }
    ++rear;
    if (rear == capacity) {
        rear = 0;
    }
    char* buff = new char[strlen(line) + 1];
    strcpy(buff, line);
    queue[rear] = buff;
}

template<typename T>
void CircularQueue<T>::push_back(const T& value)
{
    if (this->isFull()) {
        throw std::logic_error("Can't push to full queue!");
    }
    if (this->isEmpty()) {
        ++front;
    }
    ++rear;
    if (rear == capacity) {
        rear = 0;
    }
    queue[rear] = value;
}

template<>
char* CircularQueue<char *>::operator[](unsigned ind) const
{
    if (isEmpty()) {
        throw std::logic_error("Queue is empty!");
    }
    if (ind > rear && ind < front) {
        throw std::out_of_range("Index out of queue size!");
    }
    if (front + ind >= capacity) {
        ind -= capacity;
    }
    char* buff = new char[strlen(queue[front + ind]) + 1];
    strcpy(buff, queue[front + ind]);
    return buff;
}

template<typename T>
T CircularQueue<T>::operator[](unsigned ind) const
{
    if (isEmpty()) {
        throw std::logic_error("Queue is empty!");
    }
    if (ind > rear && ind < front) {
        throw std::out_of_range("Index out of queue size!");
    }
    if (front + ind >= capacity) {
        ind -= capacity;
    }
    return queue[front + ind];
}

template<>
CircularQueue<char *>& CircularQueue<char *>::operator=(const CircularQueue<char *>& rhs)
{
    if (capacity != rhs.capacity)
    {
        throw std::logic_error("Copying queues with different sizes!");
    }
    front = -1;
    rear = -1;
    if (rhs.isEmpty()) {
        return *this;
    }
    int32_t current = rhs.front;
    while (current != rhs.rear + 1) {
        if (current == capacity) {
            current = 0;
        }
        this->push_back((const char*)(rhs[current - rhs.front]));
        ++current;
    }
    return *this;
}

template<typename T>
CircularQueue<T>& CircularQueue<T>::operator=(const CircularQueue<T>& rhs)
{
    if (capacity != rhs.capacity)
    {
        throw std::logic_error("Copying queues with different sizes!");
    }
    front = -1;
    rear = -1;
    if (rhs.isEmpty()) {
        return *this;
    }
    int32_t current = rhs.front;
    while (current != rhs.rear + 1) {
        if (current == capacity) {
            current = 0;
        }
        this->push_back(rhs.queue[current]);
        ++current;
    }
    return *this;
}

template<>
void CircularQueue<char *>::pop_front()
{
    if (this->isEmpty()) {
        throw std::logic_error("Can't delete from empty queue!");
    }
    delete[] queue[front];
    ++front;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

template<typename T>
void CircularQueue<T>::pop_front()
{
    if (this->isEmpty()) {
        throw std::logic_error("Can't delete from empty queue!");
    }
    ++front;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

template<typename T>
void CircularQueue<T>::print(std::ostream& out) const
{
    int32_t current = front;
    if (this->isEmpty()) {
        return;
    }
    while (current != rear + 1) {
        if (current == capacity) {
            current = 0;
        }
        out << queue[current] << '\n';
        ++current;
    }
}

template<typename T>
T CircularQueue<T>::getByIndex(unsigned ind) const
{
    return (*this)[ind];
}

template<>
int32_t CircularQueue<char *>::find(const char* line) const
{
    if (isEmpty()) {
        return -1;
    }
    int32_t current = front;
    while (current != rear + 1) {
        if (current == capacity) {
            current = 0;
        }
        if (!strcmp(queue[current], line)) {
            return current;
        }
        ++current;
    }
    return -1;
}

template<typename T>
int32_t CircularQueue<T>::find(const T& value) const
{
    if (isEmpty()) {
        return -1;
    }
    int32_t current = front;
    while (current != rear + 1) {
        if (current == capacity) {
            current = 0;
        }
        if (queue[current] == value) {
            return current;
        }
        ++current;
    }
    return -1;
}
