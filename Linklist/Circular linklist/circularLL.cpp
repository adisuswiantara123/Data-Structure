#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void cetak(Node* first) {
    Node* jalan = first;
    cout << "List saat ini = ";
    do {
        cout << jalan->data << " ";
        jalan = jalan->next;
    } while (jalan != first);
    cout << endl;
}

int main() {
    Node* first = nullptr;

    // Membuat node pertama dengan data 'B'
    Node* B = new Node;
    B->data = 'B';
    B->next = B;
    first = B;

    cetak(first);

    // Menambahkan elemen 'C' dari belakang
    Node* C = new Node;
    C->data = 'C';
    C->next = first;
    B->next = C;

    cetak(first);

    // Menambahkan elemen 'E' dari belakang
    Node* E = new Node;
    E->data = 'E';
    E->next = first;
    C->next = E;

    cetak(first);


    // Menambahkan elemen 'D' di antara 'C' dan 'E'
    Node* D = new Node;
    D->data = 'D';
    D->next = E;
    C->next = D;

    cetak(first);

  

    // Menambahkan elemen 'F' dari belakang
    Node* F = new Node;
    F->data = 'F';
    F->next = first;
    E->next = F;

    cetak(first);

    // Menambahkan elemen 'A' di depan
    Node* A = new Node;
    A->data = 'A';
    A->next = first;
    F->next = A;
    first = A;


    cetak(first);
  

    // Menghapus elemen 'E' di tengah
    Node* hapus = E;
    Node* jalan = first;

    while (jalan->next != E) {
        jalan = jalan->next;
    }

    jalan->next = E->next;
    delete hapus;

    cetak(first);

    // Menghapus elemen 'F' di belakang
    hapus = F;
    jalan = first;

    while (jalan->next != F) {
        jalan = jalan->next;
    }

    jalan->next = F->next;
    delete hapus;

    cetak(first);

    // Menghapus elemen 'A' di depan
    hapus = first;
    first = first->next;

    while (jalan->next != hapus) {
        jalan = jalan->next;
    }

    jalan->next = first;
    delete hapus;

    cetak(first);

    return 0;
}
