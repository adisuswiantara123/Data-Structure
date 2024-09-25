// file arrayQueue.h
#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include "queue.h"
#include "myExceptions.h"
#include <sstream>

using namespace std;

template<class T>
class ArrayQueue : public Queue<T> {
public:
    ArrayQueue(int initialCapacity = 10);
    ~ArrayQueue() { delete[] queue; }
    bool empty() const override { return theFront == theBack; }
    int size() const override { return (theBack - theFront + arrayLength) % arrayLength; }
    T& front() override;
    T& back() override;
    void pop() override;
    void push(const T& theElement) override;

private:
    int theFront;
    int theBack;
    int arrayLength;
    T* queue;
};

template<class T>
ArrayQueue<T>::ArrayQueue(int initialCapacity) {
    if (initialCapacity < 1) {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw IllegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    queue = new T[arrayLength];
    theFront = 0;
    theBack = 0;
}

template<class T>
T& ArrayQueue<T>::front() {
    if (theFront == theBack)
        throw QueueEmpty();
    return queue[theFront];
}

template<class T>
T& ArrayQueue<T>::back() {
    if (theFront == theBack)
        throw QueueEmpty();
    return queue[theBack];
}

template<class T>
void ArrayQueue<T>::pop() {
    if (theFront == theBack)
        throw QueueEmpty();
    theFront = (theFront + 1) % arrayLength;
    queue[theFront].~T();  // destructor for T
}

template<class T>
void ArrayQueue<T>::push(const T& theElement) {
    if ((theBack + 1) % arrayLength == theFront) {
        // double array length
        T* newQueue = new T[2 * arrayLength];

        int start = (theFront + 1) % arrayLength;
        if (start < 2)
            copy(queue + start, queue + start + arrayLength - 1, newQueue);
        else {
            copy(queue + start, queue + arrayLength, newQueue);
            copy(queue, queue + theBack + 1, newQueue + arrayLength - start);
        }

        theFront = 2 * arrayLength - 1;
        theBack = arrayLength - 2;
        arrayLength *= 2;
        delete[] queue;
        queue = newQueue;
    }

    theBack = (theBack + 1) % arrayLength;
    queue[theBack] = theElement;
}

#endif
