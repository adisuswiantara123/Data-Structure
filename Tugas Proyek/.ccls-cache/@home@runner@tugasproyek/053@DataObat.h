#ifndef DATAOBAT_H
#define DATAOBAT_H

#include "admin.h"
#include "proses.h"
#include <iostream>
#include <fstream>
using namespace std;

struct DataObat {
    string nama;
    int dosis;
    int stok;
    int harga;

    DataObat* next;
};

class Obat {
public:
    Obat() : head(nullptr) {}
    ~Obat();

    void tambahdataobat();
    void tampilkandataobat();
    void editdataobat();
    void hapusdataobat();

private:
    const string namaFileObat = "obat.txt";
    DataObat* head;

    void simpankefile();
    void bacadarifile();
};

Obat::~Obat() {

    while (head) {
        DataObat* temp = head;
        head = head->next;
        delete temp;
    }
}

void Obat::tambahdataobat() {
    DataObat* baru = new DataObat;

    cout << "Masukkan nama obat: ";
    cin >> baru->nama;
    cout << "Masukkan dosis: ";
    cin >> baru->dosis;
    cout << "Masukkan stok: ";
    cin >> baru->stok;
    cout << "Masukkan harga: ";
    cin >> baru->harga;

    baru->next = head;
    head = baru;

    simpankefile();
    cout << "Data obat berhasil ditambahkan." << endl;
}

void Obat::tampilkandataobat() {
    bacadarifile();

    if (!head) {
        cout << "Tidak ada data obat." << endl;
        return;
    }

    int kondisi;
    int tampilkan;
    cout <<"============================================"<<endl;
    cout <<"1. tampilkan semua data obat "<<endl;
    cout <<"2. sorting data obat "<<endl;
    cout <<"============================================"<<endl;
    cout << "masukan pilihan anda (1 / 2) : ";
    cin>>kondisi;

    DataObat* current = head;
    switch(kondisi){
      case 1 :


          cout << endl;
          cout << "========================================" << endl;
          cout << "||\t\t\t DATA OBAT \t\t\t||" << endl;
          cout << "========================================" << endl;
          cout << "|| Nama  | Dosis | Stok | Harga ||" << endl;
          cout << "========================================" << endl;

          while (current) {
              cout << "|| " << current->nama << " | " << current->dosis << " | " << current->stok << " | " << current->harga << " || " << endl;
              current = current->next;
          }

          cout << "========================================" << endl;
          break;
      case 2 :
          int sorting;
          cout <<"============================================"<<endl;
          cout <<"1. tampilkan data obat (stok lebih dari) "<<endl;
          cout <<"2. tampilkan data obat (stok kurang dari) "<<endl;
          cout <<"3. tampilkan data obat (harga lebih dari) "<<endl;
          cout <<"4. tampilkan data obat (harga kurang dari) "<<endl;
          cout <<"============================================"<<endl;
          cout << "masukan pilihan anda (1/2/3/4) : ";
          cin>>sorting;

            if(sorting == 1){
              cout << "masukan patokan stok : ";
              cin >> tampilkan;
              // DataObat* current = head;

              cout << endl;
              cout << "========================================" << endl;
              cout << "||\t\t\t DATA OBAT \t\t\t||" << endl;
              cout << "========================================" << endl;
              cout << "|| Nama  | Dosis | Stok | Harga ||" << endl;
              cout << "========================================" << endl;

              while (current) {
                if(current->stok >= tampilkan ){
                  cout << "|| " << current->nama << " | " << current->dosis << " | " << current->stok << " | " << current->harga << " || " << endl;
                }
                  current = current->next;
              }

              cout << "========================================" << endl;
            }else if(sorting == 2){
              cout << "masukan patokan stok : ";
              cin >> tampilkan;
              // DataObat* current = head;

              cout << endl;
              cout << "========================================" << endl;
              cout << "||\t\t\t DATA OBAT \t\t\t||" << endl;
              cout << "========================================" << endl;
              cout << "|| Nama  | Dosis | Stok | Harga ||" << endl;
              cout << "========================================" << endl;

              while (current) {
                if(current->stok <= tampilkan ){
                  cout << "|| " << current->nama << " | " << current->dosis << " | " << current->stok << " | " << current->harga << " || " << endl;
                }
                  current = current->next;
              }

              cout << "========================================" << endl;
            }else if(sorting == 3){
              cout << "masukan patokan harga : ";
              cin >> tampilkan;
              // DataObat* current = head;

              cout << endl;
              cout << "========================================" << endl;
              cout << "||\t\t\t DATA OBAT \t\t\t||" << endl;
              cout << "========================================" << endl;
              cout << "|| Nama  | Dosis | Stok | Harga ||" << endl;
              cout << "========================================" << endl;

              while (current) {
                if(current->harga >= tampilkan ){
                  cout << "|| " << current->nama << " | " << current->dosis << " | " << current->stok << " | " << current->harga << " || " << endl;
                }
                  current = current->next;
              }

              cout << "========================================" << endl;
            }else if(sorting == 4){
              cout << "masukan patokan harga : ";
              cin >> tampilkan;
              // DataObat* current = head;

              cout << endl;
              cout << "========================================" << endl;
              cout << "||\t\t\t DATA OBAT \t\t\t||" << endl;
              cout << "========================================" << endl;
              cout << "|| Nama  | Dosis | Stok | Harga ||" << endl;
              cout << "========================================" << endl;

              while (current) {
                if(current->harga <= tampilkan ){
                  cout << "|| " << current->nama << " | " << current->dosis << " | " << current->stok << " | " << current->harga << " || " << endl;
                }
                  current = current->next;
              }

              cout << "========================================" << endl;
            }else{
              cout << " angka yang anda masukan salah "<<endl;
            }
        break;
    }  
}

void Obat::editdataobat() {
    bacadarifile();

    if (!head) {
        cout << "Tidak ada data obat." << endl;
        return;
    }

    string namaEdit;
    cout << "Masukkan nama obat yang ingin diedit: ";
    cin >> namaEdit;

    DataObat* current = head;
    bool found = false;

    while (current) {
        if (current->nama == namaEdit) {
            cout << "Masukkan dosis baru: ";
            cin >> current->dosis;
            cout << "Masukkan stok baru: ";
            cin >> current->stok;
            cout << "Masukkan harga baru: ";
            cin >> current->harga;

            found = true;
            break;
        }

        current = current->next;
    }

    if (!found) {
        cout << "Obat dengan nama " << namaEdit << " tidak ditemukan." << endl;
    } else {
        cout << "Data obat berhasil diubah." << endl;
        simpankefile(); 
    }
}

void Obat::hapusdataobat() {
    bacadarifile();

    if (!head) {
        cout << "Tidak ada data obat." << endl;
        return;
    }

    string namaHapus;
    cout << "Masukkan nama obat yang ingin dihapus: ";
    cin >> namaHapus;

    DataObat* current = head;
    DataObat* prev = nullptr;
    bool found = false;

    while (current) {
        if (current->nama == namaHapus) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }

            delete current;
            found = true;
            break;
        }

        prev = current;
        current = current->next;
    }

    if (!found) {
        cout << "Obat dengan nama " << namaHapus << " tidak ditemukan." << endl;
    } else {
        cout << "Data obat berhasil dihapus." << endl;
        simpankefile(); 
    }
}

void Obat::simpankefile() {
    ofstream file(namaFileObat);

    if (!file.is_open()) {
        cerr << "Gagal membuka file." << endl;
        return;
    }

    DataObat* current = head;

    while (current) {
        file << current->nama << " " << current->dosis << " " << current->stok << " " << current->harga << endl;
        current = current->next;
    }

    file.close();
}

void Obat::bacadarifile() {
    ifstream file(namaFileObat);

    if (!file.is_open()) {
        cerr << "File tidak ditemukan. Membuat file baru." << endl;
        return;
    }


    while (head) {
        DataObat* temp = head;
        head = head->next;
        delete temp;
    }

    while (file >> ws, !file.eof()) { 
        DataObat* baru = new DataObat;
        file >> baru->nama >> baru->dosis >> baru->stok >> baru->harga;
        baru->next = head;
        head = baru;
    }

    file.close();
}

void Login::dataobat(){
    int pilihmenu;
    Obat dataobat;

    do {
        cout << "                                                                                          " << endl;
        cout << "                                                                                          " << endl;
        cout << "                                                                                          " << endl;
        cout << "                                                                                          " << endl;
        cout << "                                                                                          " << endl;
        cout << "                                                                                          " << endl;
        cout << "                                                                                          " << endl;
        cout << "                    .:---:.                                                                " << endl;
        cout << "                :=*#########*=.                              .--=+++==:.                  " << endl;
        cout << "              :+##+=--+##--=+##+.                         .=*##*******##*-.               " << endl;
        cout << "             -##+----:+##.....+##-                      .+##*+====-----=*##=              " << endl;
        cout << "            :##+---:..+##......=##:                   .+##*====--::::::::=##+             " << endl;
        cout << "            +##---:...*#*.......##+                 .+##*====-::::::::::::-##=            " << endl;
        cout << "            +#*--:....*#*.......*#+               .+##*====--::::::::::::::+##            " << endl;
        cout << "            -##=-.....##+......:##-             .=##*====--::::::::::::::::+##            " << endl;
        cout << "             +#*=.....##=.....:##+            .=##*====--::::::::::::::::::*#+            " << endl;
        cout << "           .  =##+:...##=...:+##=           .=##*====--:::::::::::::::::::*#*.            " << endl;
        cout << "               .=*#*++##+=+##*=.          .+##*====--:::::::::::::::::::+##+.             " << endl;
        cout << "                  .-=+**++=-:           .+##*====-::::::::::::::::::::+##+:               " << endl;
        cout << "                                      .+###*===-::::::::::::::::::::+##+:                 " << endl;
        cout << "                                    .+##*+*##+-:::::::::::::::::::+##*:                   " << endl;
        cout << "                                  .+##*=---=*##+::::::::::::::::+##*:                     " << endl;
        cout << "                                .+##*=----:..-*##+::::::::::::+##*:                       " << endl;
        cout << "                              .=##*=----:......-*##=::::+##*:                             " << endl;
        cout << "                            .=##*=----:..........-*##=+##*:                               " << endl;
        cout << "                          .=##*=----:........::....-*##=+                              " << endl;
        cout << "                        .=##*=----:........:.........=###+:                               " << endl;
        cout << "                      .+##*=----:..................:+##+:                                 " << endl;
        cout << "                     =##*=----:..................:+##*:                                   " << endl;
        cout << "                    +##+----:..................:+##*:                                     " << endl;
        cout << "                   -##+---:..................:+##*:                                      " << endl;
        cout << "                   =##---:.................:+##*:                                        " << endl;
        cout << "                   =##=-:................:=##*:                                          " << endl;
        cout << "                   .##*-:..............:=##*:                                            " << endl;
        cout << "                    -##*:............:=##*:                                              " << endl;
        cout << "                     :*##+-:......:-+##+:                                                 " << endl;
        cout << "                       :+*##**++**##*=:                                                    " << endl;
        cout << "                          .--====-:.                                                       " << endl;
        cout << "                                                                                          " << endl;
        cout << "                                                                                          " << endl;
        cout << "                                                                                          " << endl;
        cout << "                                                                                          " << endl;
        cout << "                                                                                          " << endl;
        cout << "                                                                                          " << endl;
        cout << "                                                                                          " << endl;
        cout << endl;
        cout << "========================================" << endl;
        cout << "||\t\t\t MENU OBAT \t\t\t||" << endl;
        cout << "========================================" << endl;
        cout << "1. Tambah obat baru " << endl;
        cout << "2. Tampilkan data obat " << endl;
        cout << "3. Edit data obat " << endl;
        cout << "4. Hapus data obat " << endl;
        cout << "0. Keluar " << endl;

        cout << "========================================" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilihmenu;

        switch (pilihmenu) {
        case 1:
            dataobat.tambahdataobat();
            break;
        case 2:
            dataobat.tampilkandataobat();
            break;
        case 3:
            dataobat.editdataobat();
            break;
        case 4:
            dataobat.hapusdataobat();
            break;
        case 0:
            cout << "Program selesai. Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }
    } while (pilihmenu != 0);

}


#endif