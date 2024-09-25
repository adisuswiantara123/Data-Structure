// file linkedQueue.h
#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "queue.h"
#include "chainNode.h"
#include "myExceptions.h"

template<class T>
class LinkedQueue : public Queue<T> {
public:
    LinkedQueue() : queueFront(nullptr), queueBack(nullptr), queueSize(0) {}
    ~LinkedQueue();
    bool empty() const override { return queueSize == 0; }
    int size() const override { return queueSize; }
    T& front() override;
    T& back() override;
    void pop() override;
    void push(const T& theElement) override;

private:
    ChainNode<T>* queueFront;
    ChainNode<T>* queueBack;
    int queueSize;
};

template<class T>
LinkedQueue<T>::~LinkedQueue() {
    while (queueFront != nullptr) {
        ChainNode<T>* nextNode = queueFront->next;
        delete queueFront;
        queueFront = nextNode;
    }
}

template<class T>
T& LinkedQueue<T>::front() {
    if (queueSize == 0)
        throw QueueEmpty();
    return queueFront->element;
}

template<class T>
T& LinkedQueue<T>::back() {
    if (queueSize == 0)
        throw QueueEmpty();
    return queueBack->element;
}

template<class T>
void LinkedQueue<T>::pop() {
    if (queueFront == nullptr)
        throw QueueEmpty();

    ChainNode<T>* nextNode = queueFront->next;
    delete queueFront;
    queueFront = nextNode;
    queueSize--;
}

template<class T>
void LinkedQueue<T>::push(const T& theElement) {
    ChainNode<T>* newNode = new ChainNode<T>(theElement, nullptr);

    if (queueSize == 0)
        queueFront = newNode;
    else
        queueBack->next = newNode;

    queueBack = newNode;
    queueSize++;
}

#endif
