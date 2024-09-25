#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

void printList(Node* first) {
    Node* jalan = first;
    while (jalan != NULL) {
        cout << jalan->data << " ";
        jalan = jalan->next;
    }
    cout << endl;
}

int main() {
    // Membuat node pertama dengan data 'B'
    Node* first = new Node;
    first->data = 'B';
    first->next = NULL;
    first->prev = NULL;

    // Membuat node baru dengan data 'D' dan mengatur prev-nya ke first
    Node* baru = new Node;
    baru->data = 'D';
    baru->next = NULL;
    baru->prev = first;
    first->next = baru; // Menghubungkan first ke baru

    // Membuat node baru2 dengan data 'F' dan mengatur prev-nya ke baru
    Node* baru2 = new Node;
    baru2->data = 'F';
    baru2->next = NULL;
    baru2->prev = baru;
    baru->next = baru2; // Menghubungkan baru ke baru2

    // Menampilkan list sebelum penghapusan
    cout << "List awal: ";
    printList(first);

    // Membuat node A dan menambahkannya di depan B
    Node* A = new Node;
    A->data = 'A';
    A->next = first;
    A->prev = NULL;
    first->prev = A;
    first = A;

    // Menampilkan list setelah penambahan A
    cout << "List setelah penambahan A: ";
    printList(first);

    // Membuat node E dan menambahkannya sebelum F
    Node* E = new Node;
    E->data = 'E';
    E->next = baru2;
    E->prev = baru;
    baru->next = E;
    baru2->prev = E;



    // Menampilkan list setelah penambahan E
    cout << "List setelah penambahan E: ";
    printList(first);


  
    // Menghapus elemen pertama di bagian huruf E
    Node* hapus = E;
    if (hapus != NULL) {
        if (hapus->prev != NULL) {
            hapus->prev->next = hapus->next; // Menghapus referensi hapus dari prev-nya
        }
        if (hapus->next != NULL) {
            hapus->next->prev = hapus->prev; // Menghapus referensi hapus dari next-nya
        }
        delete hapus; // Menghapus node hapus dari memori
    }

    // Menampilkan list setelah penghapusan elemen pertama
    cout << "List setelah penghapusan elemen E: ";
    printList(first);

    // Menghapus elemen kedua di bagian F
    hapus = baru2;
    if (hapus != NULL) {
        if (hapus->prev != NULL) {
            hapus->prev->next = hapus->next; // Menghapus referensi hapus dari prev-nya
        }
        if (hapus->next != NULL) {
            hapus->next->prev = hapus->prev; // Menghapus referensi hapus dari next-nya
        }
        delete hapus; // Menghapus node hapus dari memori
    }

    // Menampilkan list setelah penghapusan elemen kedua
    cout << "List setelah penghapusan elemen F: ";
    printList(first);

    // Menghapus elemen ketiga di bagian A
    hapus = A;
    if (hapus != NULL) {
        if (hapus == first) {
            first = hapus->next;
            first->prev = NULL; // Menetapkan prev dari node pertama menjadi NULL
        } else if (hapus->prev != NULL) {
            hapus->prev->next = hapus->next; // Menghapus referensi hapus dari prev-nya
        }
        if (hapus->next != NULL) {
            hapus->next->prev = hapus->prev; // Menghapus referensi hapus dari next-nya
        }
        delete hapus; // Menghapus node hapus dari memori
    }

    // Menampilkan list setelah penghapusan elemen ketiga
    cout << "List setelah penghapusan elemen A: ";
    printList(first);

    return 0;
}
