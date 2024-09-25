#include <iostream>
using namespace std;

struct node {
  int data;
  node* next;
};

// Fungsi untuk menampilkan linked list
void displayList(node* head) {
  node* current = head;
  while (current != NULL) {
    cout << current->data << " --> ";
    current = current->next;
  }
  cout << "NULL" << endl;
}

// Fungsi untuk menambahkan node di depan
node* insertFront(node* head, int newData) {
  node* newNode = new node;
  newNode->data = newData;
  newNode->next = head;
  return newNode;
}

// Fungsi untuk menambahkan node di tengah
node* insertMiddle(node* head, int newData, int position) {
  node* newNode = new node;
  newNode->data = newData;

  if (position == 1) {
    newNode->next = head;
    return newNode;
  }

  node* current = head;
  for (int i = 1; i < position - 1 && current != NULL; i++) {
    current = current->next;
  }

  if (current == NULL) {
    cout << "Posisi tidak valid" << endl;
    return head;
  }

  newNode->next = current->next;
  current->next = newNode;
  return head;
}

// Fungsi untuk menambahkan node di belakang
node* insertTail(node* head, int newData) {
  node* newNode = new node;
  newNode->data = newData;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  node* current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
  return head;
}

// Fungsi untuk menghapus node di depan
node* deleteFront(node* head) {
  if (head == NULL) {
    cout << "Linked list kosong" << endl;
    return head;
  }

  node* temp = head;
  head = head->next;
  delete temp;
  return head;
}

// Fungsi untuk menghapus node di tengah
node* deleteMiddle(node* head, int position) {
  if (head == NULL) {
    cout << "Linked list kosong" << endl;
    return head;
  }

  if (position == 1) {
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }

  node* current = head;
  for (int i = 1; i < position - 1 && current != NULL; i++) {
    current = current->next;
  }

  if (current == NULL || current->next == NULL) {
    cout << "Posisi tidak valid" << endl;
    return head;
  }

  node* temp = current->next;
  current->next = current->next->next;
  delete temp;
  return head;
}


// Fungsi untuk menghapus node di belakang
node* deleteTail(node* head) {
  if (head == NULL) {
    cout << "Linked list kosong" << endl;
    return head;
  }

  if (head->next == NULL) {
    delete head;
    head = NULL;
    return head;
  }

  node* current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  delete current->next;
  current->next = NULL;
  return head;
}

int main() {
  node* head = NULL;

  while (true) {
    cout << "Pilih operasi: " << endl;
    cout << "1. Tambah depan" << endl;
    cout << "2. Tambah tengah" << endl;
    cout << "3. Tambah belakang" << endl;
    cout << "4. Hapus depan" << endl;
    cout << "5. Hapus tengah" << endl;
    cout << "6. Hapus belakang" << endl;
    cout << "7. Keluar" << endl;

    int choice;
    cout << "Masukkan pilihan: ";
    cin >> choice;

    if (choice == 7) {
      break;
    }

    int data, position;
    switch (choice) {
      case 1:
        cout << "Masukkan data: ";
        cin >> data;
        head = insertFront(head, data);
        break;
      case 2:
        cout << "Masukkan data: ";
        cin >> data;
        cout << "Masukkan posisi: ";
        cin >> position;
        head = insertMiddle(head, data, position);
        break;
      case 3:
        cout << "Masukkan data: ";
        cin >> data;
        head = insertTail(head, data);
        break;
      case 4:
        head = deleteFront(head);
        break;
      case 5:
        cout << "Masukkan posisi: ";
        cin >> position;
        head = deleteMiddle(head, position);
        break;
      case 6:
        head = deleteTail(head);
        break;
      default:
        cout << "Pilihan tidak valid" << endl;
    }

    cout << "Linked list: ";
    displayList(head);
  }

  return 0;
}
