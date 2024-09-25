#pragma once

#include <stdexcept>

template <class T>
class Node {
public:
    T data;
    Node<T>* link;
};

template <class T>
class LinkedQueue {
public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}
    ~LinkedQueue();
    bool IsEmpty() const { return (front == nullptr); }
    bool IsFull() const;
    T First() const;
    T Last() const;
    LinkedQueue<T>& Add(const T& x);
    LinkedQueue<T>& Delete(T& x);

private:
    Node<T>* front;
    Node<T>* rear;
};

template <class T>
LinkedQueue<T>::~LinkedQueue() {
    Node<T>* next;
    while (front) {
        next = front->link;
        delete front;
        front = next;
    }
    rear = nullptr;
}

template <class T>
bool LinkedQueue<T>::IsFull() const {
    Node<T>* p;
    try {
        p = new Node<T>;
        delete p;
        return false;
    }
    catch (std::bad_alloc&) {
        return true;
    }
}

template <class T>
T LinkedQueue<T>::First() const {
    if (IsEmpty())
        throw std::out_of_range("Queue is empty");
    return front->data;
}

template <class T>
T LinkedQueue<T>::Last() const {
    if (IsEmpty())
        throw std::out_of_range("Queue is empty");
    return rear->data;
}

template <class T>
LinkedQueue<T>& LinkedQueue<T>::Add(const T& x) {
    Node<T>* p = new Node<T>;
    p->data = x;
    p->link = nullptr;
    if (front)
        rear->link = p;
    else
        front = p;
    rear = p;
    return *this;
}

template <class T>
LinkedQueue<T>& LinkedQueue<T>::Delete(T& x) {
    if (IsEmpty())
        throw std::out_of_range("Queue is empty");
    x = front->data;
    Node<T>* p = front;
    front = front->link;
    delete p;
    if (!front)
        rear = nullptr;
    return *this;
}
