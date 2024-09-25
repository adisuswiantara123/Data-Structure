#include <iostream>
using namespace std;

const int MAX_SIZE = 10; // Ubah sesuai kebutuhan

int front = 0;
int rear = -1;
int queue[MAX_SIZE];

void cetak() {
    if (rear < front) {
        cout << "Queue kosong." << endl;
    } else {
        cout << "Isi Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Enqueue manual
    int elemen_baru = 1;
    if (rear < MAX_SIZE - 1) {
        rear = rear + 1;
        queue[rear] = elemen_baru;
        cout << "Enqueue: " << elemen_baru << " berhasil." << endl;
    } else {
        cout << "Queue penuh. Enqueue tidak dapat dilakukan." << endl;
    }

    elemen_baru = 2;
    if (rear < MAX_SIZE - 1) {
        rear = rear + 1;
        queue[rear] = elemen_baru;
        cout << "Enqueue: " << elemen_baru << " berhasil." << endl;
    } else {
        cout << "Queue penuh. Enqueue tidak dapat dilakukan." << endl;
    }

    elemen_baru = 3;
    if (rear < MAX_SIZE - 1) {
        rear = rear + 1;
        queue[rear] = elemen_baru;
        cout << "Enqueue: " << elemen_baru << " berhasil." << endl;
    } else {
        cout << "Queue penuh. Enqueue tidak dapat dilakukan." << endl;
    }

    cetak();

    // Dequeue manual
    if (front <= rear) {
        cout << "Dequeue: " << queue[front] << " berhasil." << endl;
        front = front + 1;
    } else {
        cout << "Queue kosong. Dequeue tidak dapat dilakukan." << endl;
    }

    cetak();

    // Enqueue manual
    elemen_baru = 4;
    if (rear < MAX_SIZE - 1) {
        rear = rear + 1;
        queue[rear] = elemen_baru;
        cout << "Enqueue: " << elemen_baru << " berhasil." << endl;
    } else {
        cout << "Queue penuh. Enqueue tidak dapat dilakukan." << endl;
    }

    cetak();

    return 0;
}
