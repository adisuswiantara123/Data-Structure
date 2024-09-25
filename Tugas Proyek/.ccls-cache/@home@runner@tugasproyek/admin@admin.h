#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "proses.h"
#include "pasien.h"

using namespace std;

struct Pasien {
    string jenispasien;
    string nama;
    int usia;
    string diagnosa;
};

struct KamarPasien {
    int nomor;
    string kelas;
    int harga;
    bool kosong;
};

struct Obat {
    string nama;
    int stok;
};

class Admin {
private:
    Pasien* daftarPasien;
    int jumlahPasien;
    int kapasitasPasien;
    const string namaFilePasien = "data_pasien.txt";
    const string filekamarkelas1 = "kamar_kls1.txt";
    const string filekamarkelas2 = "kamar_kls2.txt";
    const string filekamarvip = "kamar_vip.txt";
    const string filekamarvvip = "kamar_vvip.txt";
    const string namaFileObat = "obat.txt";

public:
    Admin() : daftarPasien(nullptr), jumlahPasien(0), kapasitasPasien(0) {
        // muatDataDariFilePasien();
        muatDataDariFileKamarPasien();
        // muatDataDariFileObat();
    }

    ~Admin() {
        simpanDataKeFilePasien();
        simpanDataKeFileKamarPasien();
        // simpanDataKeFileObat();
        delete[] daftarPasien;
    }
    void tambahPasien();
    void editDataPasien();
    void tampilkanDataPasien();
    void menuKamarPasien();
    void tambahObat();
    void editStokObat();
    void tampilkanDataObat();
    void pasienbaru(const Pasien& pasien);
    void simpanDataKeFilePasien();
};
void Login::menuUtama() {
        int pilihan;
        Admin admin;
        cout << "==========================================================================================================" << endl;
        cout << "\t #####                                              ######                                    " << endl;
        cout << "    #     # ###### #        ##   #    #   ##   #####    #     #   ##   #####   ##   #    #  ####  " << endl;
        cout << "    #       #      #       #  #  ##  ##  #  #    #      #     #  #  #    #    #  #  ##   # #    # " << endl;
        cout << "     #####  #####  #      #    # # ## # #    #   #      #     # #    #   #   #    # # #  # #      " << endl;
        cout << "          # #      #      ###### #    # ######   #      #     # ######   #   ###### #  # # #  ### " << endl;
        cout << "    #     # #      #      #    # #    # #    #   #      #     # #    #   #   #    # #   ## #    # " << endl;
        cout << "     #####  ###### ###### #    # #    # #    #   #      ######  #    #   #   #    # #    #  ####  " << endl;
        cout << "===========================================================================================================" << endl;
        do {
            cout << "\n=========== Menu Utama ===========\n";
            cout << "1. Tambah Pasien\n";
            cout << "2. Edit Data Pasien\n";
            cout << "3. Tampilkan Data Pasien\n";
            cout << "4. Kamar Pasien\n";
            cout << "5. Tambah Obat\n";
            cout << "6. Edit Stok Obat\n";
            cout << "7. Tampilkan Data Obat\n";
            cout << "0. Keluar\n";
            cout << "===================================\n";
            cout << "Pilih menu (0-7): ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    admin.tambahPasien();
                    break;
                // case 2:
                //     admin.editDataPasien();
                //     break;
                // case 3:
                //     admin.tampilkanDataPasien();
                //     break;
                case 4:
                    admin.menuKamarPasien();
                    break;
                // case 5:
                //     admin.tambahObat();
                //     break;
                // case 6:
                //     admin.editStokObat();
                //     break;
                // case 7:
                //     admin.tampilkanDataObat();
                //     break;
                // case 0:
                //     cout << "Terima kasih! Keluar dari aplikasi.\n";
                //     break;
                default:
                    cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            }
        } while (pilihan != 0);
}

void Admin::pasienbaru(const Pasien& pasien) {
    if (jumlahPasien == kapasitasPasien) {
        // Alami kapasitas
        kapasitasPasien = (kapasitasPasien == 0) ? 1 : kapasitasPasien * 2;
        Pasien* newArray = new Pasien[kapasitasPasien];
        for (int i = 0; i < jumlahPasien; ++i) {
            newArray[i] = daftarPasien[i];
        }
        delete[] daftarPasien;
        daftarPasien = newArray;
    }

    daftarPasien[jumlahPasien++] = pasien;
}

void Admin::tambahPasien() {
    Pasien pasienBaru;
    int kategori , rawatjalan;
    int jeniskamarpasien;
    string kamar;
    Admin admin;
    KamarPasien kamarpasien;
  
    cout<<"==========================================="<<endl;
    cout<<"||\t\tjenis pasien\t\t||"<<endl;
    cout<<"==========================================="<<endl;
    cout<<" 1. pasien lansia "<<endl;
    cout<<" 2. pasien parubaya "<<endl;
    cout<<" 3. pasien anak "<<endl;
    cout<<"==========================================="<<endl;
    cout<<" masukan pilihan anda : ";
    cin>>kategori;

    if(kategori == 1){
      int jenis;
      cout<<"==========================================="<<endl;
      cout<<" 1. pasien BPJS "<<endl;
      cout<<" 2. pasien umum "<<endl;
      cout<<"==========================================="<<endl;
      cout<<" masukan pilihan : ";
      cin>>jenis;
      cout<<"==========================================="<<endl;

      if (jenis == 1){
          pasienBaru.jenispasien = "bpjs";
      }else if(jenis == 2){
          pasienBaru.jenispasien = " umum ";
      }else{
        cout<<"yang anda masukan tidak sesuai "<<endl;
      }
          cout << "Masukkan Nama Pasien: ";
          cin.ignore();
          getline(cin, pasienBaru.nama);
          cout<<"==========================================="<<endl;
          
          cout << "Masukkan Usia Pasien: ";
          cin >> pasienBaru.usia;
          cout<<"==========================================="<<endl;
        
          cout << "Masukkan Diagnosa Pasien: ";
          cin.ignore(); 
          getline(cin, pasienBaru.diagnosa);
          cout<<"==========================================="<<endl;
    
          char tipePerawatan;
          cout << "Pilih Tipe Perawatan (I untuk Rawat Inap, B untuk Rawat Berjalan): ";
          cin >> tipePerawatan;
          cout<<"==========================================="<<endl;
        
    
          if (tipePerawatan == 'I' || tipePerawatan == 'i') {
              cout<<"====================================="<<endl;
              cout<<"||\t\tjenis kamar\t\t||"<<endl;
              cout<<"====================================="<<endl;
              cout<<" 1. kamar vip "<<endl;
              cout<<" 2. kamar vvip "<<endl;
              cout<<" 3. kamar kelas 1"<<endl;
    
              cout << "Pasien Rawat Inap berhasil ditambahkan.\n";
          } else if (tipePerawatan == 'B' || tipePerawatan == 'b') {
              cout<<"====================================="<<endl;
              cout<<"||\t\trawat jalan \t\t||"<<endl;
              cout<<"====================================="<<endl;
              cout<<" 1. tanggal control "<<endl;
              cout<<" 2. update kondisi "<<endl;
    
              cout << "Pasien Rawat Berjalan berhasil ditambahkan.\n";
          } else {
              cout << "Pilihan Tipe Perawatan tidak valid.\n";
          }
  
      
        admin.pasienbaru(pasienBaru);

    }else if(kategori == 2){
      int jenis;
      cout<<"==========================================="<<endl;
      cout<<" 1. pasien BPJS "<<endl;
      cout<<" 2. pasien umum "<<endl;
      cout<<"==========================================="<<endl;
      cout<<" masukan pilihan : ";
      cin>>jenis;
      cout<<"==========================================="<<endl;

      if (jenis == 1){
          pasienBaru.jenispasien = "bpjs";
      }else if(jenis == 2){
          pasienBaru.jenispasien = " umum ";
      }else{
        cout<<"yang anda masukan tidak sesuai "<<endl;
      }
          cout << "Masukkan Nama Pasien: ";
          cin.ignore();
          getline(cin, pasienBaru.nama);
          cout<<"==========================================="<<endl;

          cout << "Masukkan Usia Pasien: ";
          cin >> pasienBaru.usia;
          cout<<"==========================================="<<endl;

          cout << "Masukkan Diagnosa Pasien: ";
          cin.ignore(); 
          getline(cin, pasienBaru.diagnosa);
          cout<<"==========================================="<<endl;

          char tipePerawatan;
          cout << "Pilih Tipe Perawatan (I untuk Rawat Inap, B untuk Rawat Berjalan): ";
          cin >> tipePerawatan;
          cout<<"==========================================="<<endl;


          if (tipePerawatan == 'I' || tipePerawatan == 'i') {
              void menuKamarPasien();

              cout << "Pasien Rawat Inap berhasil ditambahkan.\n";
          } else if (tipePerawatan == 'B' || tipePerawatan == 'b') {
              cout<<"====================================="<<endl;
              cout<<"||\t\trawat jalan \t\t||"<<endl;
              cout<<"====================================="<<endl;
              cout<<" 1. tanggal control "<<endl;
              cout<<" 2. update kondisi "<<endl;
              cout<<"====================================="<<endl;
              cout<<"masukan pilihan : ";
              cin>>rawatjalan;

              // switch(rawatjalan){
              //   case 1:
                  
              // }

              cout << "Pasien Rawat Berjalan berhasil ditambahkan.\n";
          } else {
              cout << "Pilihan Tipe Perawatan tidak valid.\n";
          }


        admin.pasienbaru(pasienBaru);
    }else if(kategori == 3){
      int jenis;
      cout<<"==========================================="<<endl;
      cout<<" 1. pasien BPJS "<<endl;
      cout<<" 2. pasien umum "<<endl;
      cout<<"==========================================="<<endl;
      cout<<" masukan pilihan : ";
      cin>>jenis;
      cout<<"==========================================="<<endl;

      if (jenis == 1){
          pasienBaru.jenispasien = "bpjs";
      }else if(jenis == 2){
          pasienBaru.jenispasien = " umum ";
      }else{
        cout<<"yang anda masukan tidak sesuai "<<endl;
      }
          cout << "Masukkan Nama Pasien: ";
          cin.ignore();
          getline(cin, pasienBaru.nama);
          cout<<"==========================================="<<endl;

          cout << "Masukkan Usia Pasien: ";
          cin >> pasienBaru.usia;
          cout<<"==========================================="<<endl;

          cout << "Masukkan Diagnosa Pasien: "; 
          cin.ignore(); 
          getline(cin, pasienBaru.diagnosa);
          cout<<"==========================================="<<endl;

          char tipePerawatan;
          cout << "Pilih Tipe Perawatan (I untuk Rawat Inap, B untuk Rawat Berjalan): ";
          cin >> tipePerawatan;
          cout<<"==========================================="<<endl;


          if (tipePerawatan == 'I' || tipePerawatan == 'i') {
              cout<<"====================================="<<endl;
              cout<<"||\t\tjenis kamar\t\t||"<<endl;
              cout<<"====================================="<<endl;
              cout<<" 1. kamar vip "<<endl;
              cout<<" 2. kamar vvip "<<endl;
              cout<<" 3. kamar kelas 1"<<endl;

              cout << "Pasien Rawat Inap berhasil ditambahkan.\n";
          } else if (tipePerawatan == 'B' || tipePerawatan == 'b') {
              cout<<"====================================="<<endl;
              cout<<"||\t\trawat jalan \t\t||"<<endl;
              cout<<"====================================="<<endl;
              cout<<" 1. tanggal control "<<endl;
              cout<<" 2. update kondisi "<<endl;

              cout << "Pasien Rawat Berjalan berhasil ditambahkan.\n";
          } else {
              cout << "Pilihan Tipe Perawatan tidak valid.\n";
          }
      
        admin.pasienbaru(pasienBaru);
    
      }
}

void Admin::simpanDataKeFilePasien() {
    ofstream file(namaFilePasien);

    if (file.is_open()) {
        for (int i = 0; i < jumlahPasien; ++i) {
            file << daftarPasien[i].nama << " " << daftarPasien[i].usia << " " << daftarPasien[i].diagnosa << daftarPasien[i].jenispasien << "  \n";
        }
        file.close();
    } else {
        cout << "Gagal membuka file untuk menyimpan data pasien.\n";
    }
}

void menuKamarPasien() {
    int pilihan ;
    do {
        cout << "\n=========== Kamar Pasien ===========\n";
        cout << "1. Tampilkan Status Kamar\n";
        cout << "2. Perbarui Data Kamar\n";
        cout << "0. Kembali ke Menu Utama\n";
        cout << "===================================\n";
        cout << "Pilih menu (0-2): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanStatusKamarPasien();
                break;
            case 2:
                perbaruiDataKamarPasien();
                break;
            case 0:
                cout << "Kembali ke Menu Utama.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 0);
}
void tampilkanStatusKamarPasien() {
    int kelaskamar;
  
    cout << "================================================"<<endl;
    cout << "1. kamar vip "<<endl;
    cout << "2. kamar vvip "<<endl;
    cout << "3. kamar kelas 1 "<<endl;
    cout << "4. kamar kelas 2 "<<endl;
    cout << "================================================"<<endl;
    cout << "masukan pilihan anda : ";
    cin >> kelaskamar;

    switch(kelaskamar){
      case 1 :
        ifstream file(filekamarvip);

        if (file.is_open()) {
            cout << "\n==========================================\n";
            cout << "| No Kamar | Kelas | Harga | Status       | \n";
            cout << "==========================================\n";

            int nomorKamar, harga;
            string kelas, status;

            while (file >> nomorKamar >> kelas >> harga >> status) {
                cout << "| " << nomorKamar << "\t\t| " << kelas << "\t| " << harga << "\t| " << status << "\t|\n";
            }

            cout << "==========================================\n";
            file.close();
        } else {
            cout << "Gagal membuka file " << namaFileKamarPasien << ".\n";
        }
    }
    ifstream file(namaFileKamarPasien);

    if (file.is_open()) {
        cout << "\n==========================================\n";
        cout << "| No Kamar | Kelas | Harga | Status       | \n";
        cout << "==========================================\n";

        int nomorKamar, harga;
        string kelas, status;

        while (file >> nomorKamar >> kelas >> harga >> status) {
            cout << "| " << nomorKamar << "\t\t| " << kelas << "\t| " << harga << "\t| " << status << "\t|\n";
        }

        cout << "==========================================\n";
        file.close();
    } else {
        cout << "Gagal membuka file " << namaFileKamarPasien << ".\n";
    }
}
#endif