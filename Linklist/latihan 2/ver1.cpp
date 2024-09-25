#include <iostream>
using namespace std;

struct node {
  int data;
  node* next;
};

// Fungsi untuk menambahkan node dari depan
void tambahDepan(node*& head, int newData) {
  node* newNode = new node;
  newNode->data = newData;
  newNode->next = head;
  head = newNode;
  cout << "Node dengan data " << newData << " ditambahkan di depan." << endl;
}

// Fungsi untuk menambahkan node dari tengah
void tambahTengah(node* prevNode, int newData) {
  if (prevNode == nullptr) {
    cout << "Node sebelumnya tidak boleh null." << endl;
    return;
  }
  node* newNode = new node;
  newNode->data = newData;
  newNode->next = prevNode->next;
  prevNode->next = newNode;
  cout << "Node dengan data " << newData << " ditambahkan setelah node dengan data " << prevNode->data << "." << endl;
}

// Fungsi untuk menambahkan node dari belakang
void tambahBelakang(node*& head, int newData) {
  node* newNode = new node;
  newNode->data = newData;
  newNode->next = nullptr;

  if (head == nullptr) {
    head = newNode;
    cout << "Node dengan data " << newData << " ditambahkan di belakang sebagai node pertama." << endl;
    return;
  }

  node* current = head;
  while (current->next != nullptr) {
    current = current->next;
  }

  current->next = newNode;
  cout << "Node dengan data " << newData << " ditambahkan di belakang." << endl;
}

// Fungsi untuk menghapus node dari depan
void hapusDepan(node*& head) {
  if (head == nullptr) {
    cout << "Linked list sudah kosong." << endl;
    return;
  }

  node* temp = head;
  head = head->next;
  cout << "Node pertama dengan data " << temp->data << " dihapus." << endl;
  delete temp;
}

// Fungsi untuk menghapus node dari tengah
void hapusTengah(node* prevNode) {
  if (prevNode == nullptr || prevNode->next == nullptr) {
    cout << "Node sebelumnya tidak valid." << endl;
    return;
  }

  node* temp = prevNode->next;
  prevNode->next = temp->next;
  cout << "Node dengan data " << temp->data << " dihapus." << endl;
  delete temp;
}

// Fungsi untuk menghapus node dari belakang
void hapusBelakang(node*& head) {
  if (head == nullptr) {
    cout << "Linked list sudah kosong." << endl;
    return;
  }

  if (head->next == nullptr) {
    delete head;
    head = nullptr;
    cout << "Node terakhir dihapus, linked list menjadi kosong." << endl;
    return;
  }

  node* current = head;
  while (current->next->next != nullptr) {
    current = current->next;
  }

  delete current->next;
  current->next = nullptr;
  cout << "Node terakhir dihapus." << endl;
}

// Fungsi untuk menampilkan seluruh linked list
void tampilkanList(node* head) {
  node* current = head;
  while (current != nullptr) {
    cout << current->data << " --> ";
    current = current->next;
  }
  cout << "NULL" << endl;
}

int main() {
  node* head = nullptr;

  tambahBelakang(head, 1);
  tambahBelakang(head, 2);
  tambahBelakang(head, 4);
  tampilkanList(head);

  tambahDepan(head, 0);
  tampilkanList(head);

  tambahTengah(head->next, 3);
  tampilkanList(head);

  hapusDepan(head);
  tampilkanList(head);

  hapusTengah(head->next);
  tampilkanList(head);

  hapusBelakang(head);
  tampilkanList(head);

  return 0;
}
