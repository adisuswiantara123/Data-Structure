#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* first = nullptr;
Node* tail = nullptr;

void cetak() {
    Node* jalan = first;
    cout << "List saat ini = ";
    do {
        cout << jalan->data << " ";
        jalan = jalan->next;
    } while (jalan != first);
    cout << endl;
}

int main(){
  // Deklarasi awal 5
  Node* lima = new Node;
  lima->data = 5;
  lima->next = lima;
  first = lima;
  tail = lima;
  cetak();


  // Tambah 8 di belakang
  Node* delapan = new Node;
  delapan->data = 8;
  delapan->next = first;
  tail->next = delapan;
  tail = delapan;
  cetak();

  // Tambah 10 di belakang
  Node* sepuluh = new Node;
  sepuluh->data = 10;
  sepuluh->next = first;
  tail->next = sepuluh;
  tail = sepuluh;
  cetak();
  
  // Tambah 2 di depan
  Node* dua = new Node;
  dua->data = 2;
  dua->next = first;
  tail->next = dua;
  first = dua;
  cetak();

  //Tambah 7 di tengah
  Node* tujuh = new Node;
  tujuh->data = 7;
  tujuh->next = delapan;
  lima->next = tujuh;
  cetak();

  // Hapus 8 di tengah
  Node* hapus = delapan;
  Node* jalan = first;
  while (jalan->next != delapan) {
      jalan = jalan->next;
  }
  jalan->next = delapan->next;
  if (tail == delapan) {
      tail = jalan;
  }
  delete hapus;
  cetak();


  // Hapus 10 di belakang
  hapus = sepuluh;
  jalan = first;
  while (jalan->next != sepuluh) {
      jalan = jalan->next;
  }
  jalan->next = sepuluh->next;
  if (tail == sepuluh) {
      tail = jalan;
  }
  delete hapus;
  cetak();

   //2 dihapus dari depan
    hapus = first; 
    first = first->next; 
    tail->next = first; 
    delete hapus;
    cetak();

  
  
  return 0;
  
}