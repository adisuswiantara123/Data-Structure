#include <iostream>
using namespace std;

struct simpul {
  int data;
  simpul *lanjut;
};

simpul *head = NULL;
simpul *tail = NULL;

int main() {

//   head = new simpul();
//   head->data = 5;
//   head->lanjut = head;  
//   tail = head;

  simpul* lima = new simpul();
  lima->data = 5;
  lima->lanjut = lima;
  head = lima;
  tail = lima;

  simpul *baru = new simpul();
  baru->data = 7;
  baru->lanjut = head;  
  tail->lanjut = baru;  
  tail = baru;

  simpul *baru3 = new simpul();
  baru3->data = 8;
  baru3->lanjut = head;  
  tail->lanjut = baru3;  
  tail = baru3;

  simpul *baru4 = new simpul();
  baru4->data = 10;
  baru4->lanjut = head;  
  tail->lanjut = baru4;  
  tail = baru4;

  simpul *baru2 = new simpul();
  baru2->data = 2;
  baru2->lanjut = head;  
  tail->lanjut = baru2;  
  head = baru2; 


  simpul *temp = tail->lanjut;
  cout << "Sebelum menghapus: ";
  do {
    cout << temp->data << " ";
    temp = temp->lanjut;
  } while (temp != head);
  cout << endl;


  simpul *hapus8 = tail->lanjut;
  while (hapus8->lanjut->data != 8) {
    hapus8 = hapus8->lanjut;
  }
  simpul *tempHapus8 = hapus8->lanjut;
  hapus8->lanjut = tempHapus8->lanjut;
  if (tempHapus8 == tail) {
    tail = hapus8;
  }
  delete tempHapus8;


  simpul *hapus10 = tail->lanjut;
  while (hapus10->lanjut->data != 10) {
    hapus10 = hapus10->lanjut;
  }
  simpul *tempHapus10 = hapus10->lanjut;
  hapus10->lanjut = tempHapus10->lanjut;
  if (tempHapus10 == tail) {
    tail = hapus10;
  }
  delete tempHapus10;


  temp = tail->lanjut;
  cout << "Setelah menghapus: ";
  do {
    cout << temp->data << " ";
    temp = temp->lanjut;
  } while (temp != head);
  cout << endl;




  cout<<endl;


    simpul *hapus2 = head; 
    head = head->lanjut; 
    tail->lanjut = head; 
    delete hapus2;
    
    temp = head;
      do {
    cout << temp->data << " ";
    temp = temp->lanjut;
  } while (temp != head);
  cout << endl;



  return 0;
}