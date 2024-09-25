#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Ubah sesuai kebutuhan

int front = 0;
int rear = 0;
int counter = 0; // Menyimpan jumlah elemen dalam queue
int queue[MAX_SIZE];

void cetak() {
    if (counter == 0) {
        cout << "Queue kosong." << endl;
    } else {
        int current = front;
        cout << "Isi Queue: ";
        for (int i = 0; i < counter; i++) {
            cout << queue[current] << " ";
            current = (current + 1) % MAX_SIZE;
        }
        cout << endl;
    }
}

int main() {
    // Enqueue manual
    int elemen_baru = 1;
    if (counter < MAX_SIZE) {
        queue[rear] = elemen_baru;
        rear = (rear + 1) % MAX_SIZE;
        counter++;
        cout << "Enqueue: " << elemen_baru << " berhasil." << endl;
    } else {
        cout << "Queue penuh. Enqueue tidak dapat dilakukan." << endl;
    }

    elemen_baru = 2;
    if (counter < MAX_SIZE) {
        queue[rear] = elemen_baru;
        rear = (rear + 1) % MAX_SIZE;
        counter++;
        cout << "Enqueue: " << elemen_baru << " berhasil." << endl;
    } else {
        cout << "Queue penuh. Enqueue tidak dapat dilakukan." << endl;
    }

    elemen_baru = 3;
    if (counter < MAX_SIZE) {
        queue[rear] = elemen_baru;
        rear = (rear + 1) % MAX_SIZE;
        counter++;
        cout << "Enqueue: " << elemen_baru << " berhasil." << endl;
    } else {
        cout << "Queue penuh. Enqueue tidak dapat dilakukan." << endl;
    }

    cetak();

    // Dequeue manual
    if (counter > 0) {
        cout << "Dequeue: " << queue[front] << " berhasil." << endl;
        front = (front + 1) % MAX_SIZE;
        counter--;
    } else {
        cout << "Queue kosong. Dequeue tidak dapat dilakukan." << endl;
    }

    cetak();

    // Enqueue manual
    elemen_baru = 4;
    if (counter < MAX_SIZE) {
        queue[rear] = elemen_baru;
        rear = (rear + 1) % MAX_SIZE;
        counter++;
        cout << "Enqueue: " << elemen_baru << " berhasil." << endl;
    } else {
        cout << "Queue penuh. Enqueue tidak dapat dilakukan." << endl;
    }

    cetak();

    return 0;
}
