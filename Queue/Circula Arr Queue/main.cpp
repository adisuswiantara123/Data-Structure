#include <iostream>

using namespace std;

template<class T>
class Queue {
public:
    Queue(int MaxQueueSize = 5);
    ~Queue() { delete[] queue; }
    int IsEmpty() const { return front == rear; }
    int IsFull() const { return (((rear + 1) % MaxSize == front) ? 1 : 0); }
    T First() const; // return front element
    T Last() const;  // return last element
    Queue<T>& Enqueue(const T& x);
    Queue<T>& Dequeue(T& x);
    void Resize(); // array doubling operation jika penuh
    void PrintQueue() const;

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
    return queue[(front + 1) % MaxSize];
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
    rear = (rear + 1) % MaxSize;
    queue[rear] = x;
    return *this;
}

template<class T>
Queue<T>& Queue<T>::Dequeue(T& x) {
    if (IsEmpty()) {
        cerr << "Error: Queue is empty." << endl;
        exit(EXIT_FAILURE);
    }
    x = queue[(front + 1) % MaxSize];
    front = (front + 1) % MaxSize;
    return *this;
}

template<class T>
void Queue<T>::Resize() {
    int newSize = MaxSize * 2;
    T* newQueue = new T[newSize];

    int j = front;
    for (int i = 1; i <= MaxSize; ++i) {
        newQueue[i] = queue[j];
        j = (j + 1) % MaxSize;
    }

    front = 0;
    rear = MaxSize - 1;
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
    int i = (front + 1) % MaxSize;
    while (i != (rear + 1) % MaxSize) {
        cout << queue[i] << " ";
        i = (i + 1) % MaxSize;
    }
    cout << endl;
}

int main() {
    Queue<int> myQueue(5);

    // Enqueue elements
    myQueue.Enqueue(1);
    myQueue.PrintQueue();

    myQueue.Enqueue(2);
    myQueue.PrintQueue();

    myQueue.Enqueue(3);
    myQueue.PrintQueue();

    myQueue.Enqueue(4);
    myQueue.PrintQueue();

    myQueue.Enqueue(5);
    myQueue.PrintQueue();

    // Dequeue elements
    int hapus;
    myQueue.Dequeue(hapus);
    cout << "Dequeued element: " << hapus << endl;
    myQueue.PrintQueue();
  
    myQueue.Dequeue(hapus);
    cout << "Dequeued element: " << hapus << endl;
    myQueue.PrintQueue();

    myQueue.Dequeue(hapus);
    cout << "Dequeued element: " << hapus << endl;
    myQueue.PrintQueue();

    myQueue.Dequeue(hapus);
    cout << "Dequeued element: " << hapus << endl;
    myQueue.PrintQueue();

    myQueue.Dequeue(hapus);
    cout << "Dequeued element: " << hapus << endl;
    myQueue.PrintQueue();

  
  

    return 0;
}
