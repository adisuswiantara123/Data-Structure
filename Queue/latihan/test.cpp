#include <iostream>

using namespace std;

template<class T>
class Queue {
public:
    Queue(int MaxQueueSize = 5);
    ~Queue() { delete[] queue; }
    int IsEmpty() const { return front == rear; }
    int IsFull() const { return (((rear + 1) % MaxSize) == front ? 1 : 0); }
    T First() const; // return front element
    T Last() const;  // return last element
    Queue<T>& Enqueue(const T& x);
    Queue<T>& Dequeue(T& x);
    void Resize(); // array doubling operation jika penuh
    void PrintQueue() const;
    int FrontIndex() const { return front; }
    int RearIndex() const { return rear; }

private:
    int MaxSize;   // ukuran maksimum queue
    int front;     // indeks posisi elemen terdepan
    int rear;      // indeks posisi elemen terakhir
    T* queue;      // array elemen queue
};

template<class T>
Queue<T>::Queue(int MaxQueueSize) : MaxSize(MaxQueueSize + 1), front(0), rear(0) {
    queue = new T[MaxSize];
}

template<class T>
T Queue<T>::First() const {
    if (IsEmpty()) {
        cerr << "Error: Queue is empty." << endl;
        exit(EXIT_FAILURE);
    }
    return queue[front];
}

template<class T>
T Queue<T>::Last() const {
    if (IsEmpty()) {
        cerr << "Error: Queue is empty." << endl;
        exit(EXIT_FAILURE);
    }
    return queue[rear];
}

template<class T>
Queue<T>& Queue<T>::Enqueue(const T& x) {
    if (IsFull()) {
        Resize();
    }
    queue[rear] = x;
    rear = (rear + 1) % MaxSize;
    return *this;
}

template<class T>
Queue<T>& Queue<T>::Dequeue(T& x) {
    if (IsEmpty()) {
        cerr << "Error: Queue is empty." << endl;
        exit(EXIT_FAILURE);
    }
    x = queue[front];
    front = (front + 1) % MaxSize;
    return *this;
}

template<class T>
void Queue<T>::Resize() {
    int newSize = MaxSize * 2;
    T* newQueue = new T[newSize];

    int j = 0;
    for (int i = front; i != rear; i = (i + 1) % MaxSize) {
        newQueue[j] = queue[i];
        ++j;
    }

    front = 0;
    rear = j;
    MaxSize = newSize;
    delete[] queue;
    queue = newQueue;

    cout << "Resizing array. New size: " << MaxSize << endl;
}

template<class T>
void Queue<T>::PrintQueue() const {
    if (IsEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue elements: ";
    int i = FrontIndex();
    while (i != RearIndex()) {
        cout << "(" << queue[i] << ") ";
        i = (i + 1) % MaxSize;
    }
    cout << "(" << queue[i] << ")" << endl;

    // Menampilkan nilai front dan rear
    cout << "Front Index: " << FrontIndex() << ", Rear Index: " << RearIndex() << endl;
}

int main() {
    Queue<int> myQueue(5);

    // Enqueue elements
    myQueue.Enqueue(1);
    cout << "After Enqueue:" << endl;
    myQueue.PrintQueue();

    myQueue.Enqueue(2);
    cout << "After Enqueue:" << endl;
    myQueue.PrintQueue();

    myQueue.Enqueue(3);
    cout << "After Enqueue:" << endl;
    myQueue.PrintQueue();

    myQueue.Enqueue(4);
    cout << "After Enqueue:" << endl;
    myQueue.PrintQueue();

    myQueue.Enqueue(5);
    cout << "After Enqueue:" << endl;
    myQueue.PrintQueue();

    // Dequeue elements
    int hapus;
    myQueue.Dequeue(hapus);
    cout << "Dequeued element: " << hapus << endl;
    cout << "After Dequeue:" << endl;
    myQueue.PrintQueue();

    myQueue.Dequeue(hapus);
    cout << "Dequeued element: " << hapus << endl;
    cout << "After Dequeue:" << endl;
    myQueue.PrintQueue();

    myQueue.Dequeue(hapus);
    cout << "Dequeued element: " << hapus << endl;
    cout << "After Dequeue:" << endl;
    myQueue.PrintQueue();

    myQueue.Dequeue(hapus);
    cout << "Dequeued element: " << hapus << endl;
    cout << "After Dequeue:" << endl;
    myQueue.PrintQueue();

    myQueue.Dequeue(hapus);
    cout << "Dequeued element: " << hapus << endl;
    cout << "After Dequeue:" << endl;
    myQueue.PrintQueue();

    return 0;
}
