#include <iostream>
using namespace std;

struct PQueue {
    char info;
    int Prioritasnya;
    PQueue *lanjutkan;
};



void cetak(PQueue *front, PQueue *rear) {
    PQueue *tampung = front;
    while (tampung != NULL) {
        cout << tampung->info << " ";
        tampung = tampung->lanjutkan;
    }
    cout << endl;

    cout << "front: " << (front ? front->info : ' ') << " rear: " << (rear ? rear->info : ' ') << endl;
}

int main() {
    PQueue *front = NULL;
    PQueue *rear = NULL;

    PQueue *A = new PQueue;
    A->info = 'A';
    A->Prioritasnya = 8;
    A->lanjutkan = NULL;

    // Enqueue A manual
    if (front == NULL || A->Prioritasnya < front->Prioritasnya) {
        A->lanjutkan = front;
        front = A;
        if (rear == NULL) {
            rear = front;
        }
    } 
    
    else {
        PQueue *tampung = front;
        PQueue *prev = NULL;
        while (tampung != NULL && A->Prioritasnya >= tampung->Prioritasnya) {
            prev = tampung;
            tampung = tampung->lanjutkan;
        }
        prev->lanjutkan = A;
        A->lanjutkan = tampung;
        if (tampung == NULL) {
            rear = A;
        }
    }

    cout << "Isi data link setelah Enqueue " << A->info << ": ";
    cetak(front, rear);
    cout << endl;

    PQueue *B = new PQueue;
    B->info = 'B';
    B->Prioritasnya = 3;
    B->lanjutkan = NULL;

    // Enqueue B manual
    if (front == NULL || B->Prioritasnya < front->Prioritasnya) {
        B->lanjutkan = front;
        front = B;
        if (rear == NULL) {
            rear = front;
        }
    } 
    else {
        PQueue *tampung = front;
        PQueue *prev = NULL;
        while (tampung != NULL && B->Prioritasnya >= tampung->Prioritasnya) {
            prev = tampung;
            tampung = tampung->lanjutkan;
        }
        prev->lanjutkan = B;
        B->lanjutkan = tampung;
        if (tampung == NULL) {
            rear = B;
        }
    }

    cout << "Isi data link setelah Enqueue " << B->info << ": ";
    cetak(front, rear);
    cout << endl;

    PQueue *C = new PQueue;
    C->info = 'C';
    C->Prioritasnya = 10;
    C->lanjutkan = NULL;

    // Enqueue C manual
    if (front == NULL || C->Prioritasnya < front->Prioritasnya) {
        C->lanjutkan = front;
        front = C;
        if (rear == NULL) {
            rear = front;
        }
    } else {
        PQueue *tampung = front;
        PQueue *prev = NULL;
        while (tampung != NULL && C->Prioritasnya >= tampung->Prioritasnya) {
            prev = tampung;
            tampung = tampung->lanjutkan;
        }
        prev->lanjutkan = C;
        C->lanjutkan = tampung;
        if (tampung == NULL) {
            rear = C;
        }
    }

    cout << "Isi data link setelah Enqueue " << C->info << ": ";
    cetak(front, rear);
    cout << endl;

    PQueue *D = new PQueue;
    D->info = 'D';
    D->Prioritasnya = 5;
    D->lanjutkan = NULL;

    // Enqueue D manual
    if (front == NULL || D->Prioritasnya < front->Prioritasnya) {
        D->lanjutkan = front;
        front = D;
        if (rear == NULL) {
            rear = front;
        }
    } 
    else {
        PQueue *tampung = front;
        PQueue *prev = NULL;
        while (tampung != NULL && D->Prioritasnya >= tampung->Prioritasnya) {
            prev = tampung;
            tampung = tampung->lanjutkan;
        }
        prev->lanjutkan = D;
        D->lanjutkan = tampung;
        if (tampung == NULL) {
            rear = D;
        }
    }

    cout << "Isi data link setelah Enqueue " << D->info << ": ";
    cetak(front, rear);
    cout << endl;


  cout<<"Dequeue berdasarkan prioritas"<<endl;


  
  // Dequeue semua
  while (front != NULL) {
      PQueue *dequeue = front;
      front = front->lanjutkan;
      if (front == NULL) {
          rear = NULL;
      }
      cout << "Dequeue: " << dequeue->info << " Prioritas: " << dequeue->Prioritasnya << endl;
      delete dequeue;

      cout << "Isi link list: ";
      cetak(front, rear);
      cout << endl;

      // Cek apakah setelah dequeue link list menjadi kosong
      if (front == NULL) {
          cout << "Isi link list kosong atau tidak ada." << endl;
      }
  }


    return 0;
}