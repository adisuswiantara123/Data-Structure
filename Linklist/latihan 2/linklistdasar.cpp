#include <iostream>
using namespace std;

struct node {
  int data;
  node* next;
};

int main() {
  // Membuat node D terlebih dahulu agar dapat terbaca
  node* D = new node;
  D->data = 4;
  D->next = NULL;

  // Membuat node B
  node* B = new node;
  B->data = 2;
  B->next = D;

  // Membuat node A
  node* A = new node;
  A->data = 1;
  A->next = B;

  // Menampilkan data dari semua node menggunakan pointer next
  cout<<"Data awal"<<endl;
  cout << "A: " << A->data << " --> ";
  cout << "B: " << A->next->data << " --> ";
  cout << "D: " << A->next->next->data << " --> NULL" << endl;

  // Membuat node C dan menyisipkannya setelah node B
  node* C = new node;
  C->data = 3;
  C->next = B->next;
  B->next = C;

  // Menampilkan data setelah penyisipan node C
  cout<<endl;
  cout<<"Sisip C di depan B dan di belakang D"<<endl;
  cout << "A: " << A->data << " --> ";
  cout << "B: " << A->next->data << " --> ";
  cout << "C: " << A->next->next->data << " --> ";
  cout << "D: " << A->next->next->next->data << " --> NULL" << endl;

  // Menghapus node B dari linked list dengan A-> nunjuk C jadi B tidak terpakai atau terhapus
  A->next = C;
  delete B;

  // Menampilkan data setelah penghapusan node B
  cout<<endl;
  cout<<"Hapus B"<<endl;
  cout << "A: " << A->data << " --> ";
  cout << "C: " << A->next->data << " --> ";
  cout << "D: " << A->next->next->data << " --> NULL" << endl;



  return 0;
}
