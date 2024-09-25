#ifndef ADMIN_H
#define ADMIN_H

#include "../051/pasien.h"
#include "../058/maintenance.h"
#include "proses.h"
#include "kamarpasien.h"
#include "DataObat.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pasien {
  string jenispasien;
  string nama;
  int usia;
  string diagnosa;
  string umurpasien;
  string jeniskamar;
};


struct kamarpasien {
  int nomor;
  int harga;
  bool kosong;
};


class Admin {
private:
  Pasien *daftarPasien;
  int jumlahPasien;
  int kapasitasPasien;
  const string namaFilePasien = "data_pasien.txt";
  const string filekamarKelas1 = "kamar_kls1.txt";
  const string filekamarKelas2 = "kamar_kls2.txt";
  const string filekamarVIP = "kamar_vip.txt";
  const string filekamarVVIP = "kamar_vvip.txt";
  int jumlahData;

public:
  Admin() : daftarPasien(nullptr), jumlahPasien(0), kapasitasPasien(0) {
    muatDataDariFilePasien();
  }

  ~Admin() {
    simpanDataKeFilePasien();
    delete[] daftarPasien;
  }
  void tambahPasien();
  void editDataPasien();
  void tampilkanDataPasien();
  void menuKamarPasien();
  void Resize(int newSize);
  void simpanDataKeFilePasien1();
  void simpanDataKeFilePasien();
  kamarpasien *bacaDataKamar(const std::string &namaFile, int &jumlahData);
  void tampilkanDataKamar(const kamarpasien *kamar, int jumlahData,
                          int jeniskamar);
  void muatDataDariFilePasien();
  void tampilpasienumur();
  void tampilpasienumur2();
  void tampilpasientermuda();
  void tampilpasiendiagnosa();
};

void Login::menuUtama() {
  Login login;
  int pilihan;
  Admin admin;
  cout << "==========================================================================================================" << endl;
  cout << "   _____ ______ _               __  __       _______    _____       _______       _   _  _____ _ " << endl;
  cout << "  / ____|  ____| |        /\\   |  \\/  |   /\\|__   __|  |  __ \\   /\\|__   __|/\\   | \\ | |/ ____| |" << endl;
  cout << " | (___ | |__  | |       /  \\  | \\  / |  /  \\  | |     | |  | | /  \\  | |  /  \\  |  \\| | |  __| |" << endl;
  cout << "  \\___ \\|  __| | |      / /\\ \\ | |\\/| | / /\\ \\ | |     | |  | |/ /\\ \\ | | / /\\ \\ | . ` | | |_ | |" << endl;
  cout << "  ____) | |____| |____ / ____ \\| |  | |/ ____ \\| |     | |__| / ____ \\| |/ ____ \\| |\\  | |__| |_|" << endl;
  cout << " |_____/|______|______/_/    \\_\\_|  |_/_/    \\_\\_|     |_____/_/    \\_\\_/_/    \\_\\_| \\_|\\_____(_)" << endl;
  cout << "===========================================================================================================" << endl;
  do {
    cout << "=========== Menu Admin ===========\n";
    cout << "1. Tambah Pasien\n";
    cout << "2. Edit Data Pasien\n";
    cout << "3. Tampilkan Data Pasien\n";
    cout << "4. Kamar Pasien\n";
    cout << "5. Data Obat\n";
    cout << "6. Jadwal Maintenance\n";
    cout << "7. Data dokter\n";
    cout << "0. Keluar\n";
    cout << "===================================\n";
    cout << "Pilih menu (0-7): ";
    cin >> pilihan;
    cout << "===================================\n";

    switch (pilihan) {
    case 1:
      admin.tambahPasien();
      break;
    case 2:
        admin.editDataPasien();
        break;
    case 3:
      
      int kondisi;
      cout <<"============================================"<<endl;
      cout <<"1. Tampilkan semua data pasien."<<endl;
      cout <<"2. Tampilkan data pasien (umur lebih dari)." << endl;
      cout <<"3. Tampilkan data pasien (umur kurang dari)." << endl;
      cout <<"4. Tampilkan pasien termuda dari jenis pasien yang ditentukan." <<endl;
      cout <<"5. Tampilkan data pasien sesuai diagnosa yang di inginkan." << endl;
      cout <<"============================================"<<endl;
      cout << "Masukan pilihan Anda (1/2/3) : ";
      cin>>kondisi;

      if(kondisi == 1){
        admin.tampilkanDataPasien();
      }else if(kondisi == 2){
        admin.tampilpasienumur();
      }else if(kondisi == 3){
        admin.tampilpasienumur2();
      }else if(kondisi == 4){
        admin.tampilpasientermuda();
      }else if(kondisi == 5){
        admin.tampilpasiendiagnosa();
      }else{
        cout << " angka yang anda masukan salah "<<endl;
      }
      
      break;
    case 4:
      login.datakamarpasien();
      break;
    case 5:
        login.dataobat();
        break;
    case 6:
      maintenance();
      break;
    case 7:
      login.dokterbaru();
      break;
    case 0:
        cout << "Terima kasih! Keluar dari aplikasi.\n";
        break;
    default:
      cout << "Pilihan tidak valid. Silakan coba lagi.\n";
    }
  } while (pilihan != 0);
}



kamarpasien *Admin::bacaDataKamar(const std::string &namaFile,
                                  int &jumlahData) {
  ifstream file(namaFile);
  kamarpasien *kamar = nullptr;
  jumlahData = 0;

  if (file.is_open()) {
    int count = 0;
    string line;
    while (getline(file, line)) {
      ++count;
    }

    kamar = new kamarpasien[count];
    file.clear();
    file.seekg(0, std::ios::beg);

    while (file >> kamar[jumlahData].nomor >> kamar[jumlahData].harga >>
           kamar[jumlahData].kosong) {
      ++jumlahData;
    }

    file.close();
  } else {
    cerr << "Gagal membuka file " << namaFile << endl;
  }

  return kamar;
}

void Admin::tampilkanDataKamar(const kamarpasien *kamar, int jumlahData,
                               int jeniskamar) {

  if (jeniskamar == 1) {
    cout << "=======================================" << endl;
    cout << "||\t\t KAMAR VIP \t\t||" << endl;
    cout << "=======================================" << endl;
  } else if (jeniskamar == 2) {
    cout << "=======================================" << endl;
    cout << "||\t\t KAMAR VVIP \t\t||" << endl;
    cout << "=======================================" << endl;
  } else if (jeniskamar == 3) {
    cout << "=======================================" << endl;
    cout << "||\t\t KAMAR KELAS 1 \t\t||" << endl;
    cout << "=======================================" << endl;
  } else if (jeniskamar == 4) {
    cout << "=======================================" << endl;
    cout << "||\t\t KAMAR KELAS 2 \t\t||" << endl;
    cout << "=======================================" << endl;
  }
  for (int i = 0; i < jumlahData; ++i) {
    cout << "||  " << kamar[i].nomor << " | " << kamar[i].harga << " | "
         << (kamar[i].kosong ? "Ya" : "Tidak") << "\n";
  }
  cout << "=======================================" << endl;
}

void Admin::Resize(int newSize) {
    if (newSize == kapasitasPasien) {
        return;
    }

    Pasien* newData = new Pasien[newSize];
    int minSize = (newSize < kapasitasPasien) ? newSize : kapasitasPasien;
    for (int i = 0; i < minSize; i++) {
        newData[i] = daftarPasien[i];
    }
    delete[] daftarPasien;
    daftarPasien = newData;
    kapasitasPasien = newSize;
}

void Admin::tambahPasien() {
  Pasien pasienBaru;
  int kategori, rawatjalan;
  int jeniskamarpasien;
  string namaFile;
  Admin admin;

  
  cout << "===========================================" << endl;
  cout << "||\t\tJenis Pasien\t\t||" << endl;
  cout << "===========================================" << endl;
  cout << " 1. Pasien Lansia " << endl;
  cout << " 2. Pasien Parubaya " << endl;
  cout << " 3. Pasien Anak " << endl;
  cout << "===========================================" << endl;
  cout << " Masukan Pilihan Anda : ";
  cin >> kategori;

  if (kategori == 1) {
    int jenis;
    pasienBaru.umurpasien = "lansia";
    cout << "===========================================" << endl;
    cout << " 1. Pasien BPJS " << endl;
    cout << " 2. Pasien Umum " << endl;
    cout << "===========================================" << endl;
    cout << " Masukan Pilihan : ";
    cin >> jenis;
    cout << "===========================================" << endl;

    if (jenis == 1) {
      pasienBaru.jenispasien = "BPJS";
    } else if (jenis == 2) {
      pasienBaru.jenispasien = " Umum ";
    } else {
      cout << "yang Anda masukkan tidak sesuai " << endl;
    }
    cout << "Masukkan Nama Pasien: ";
    cin.ignore();
    getline(cin, pasienBaru.nama);
    cout << "===========================================" << endl;

    cout << "Masukkan Usia Pasien: ";
    cin >> pasienBaru.usia;
    cout << "===========================================" << endl;

    cout << "Masukkan Diagnosa Pasien: ";
    cin.ignore();
    getline(cin, pasienBaru.diagnosa);
    cout << "===========================================" << endl;

    char tipePerawatan;
    cout << "Pilih Tipe Perawatan (I untuk Rawat Inap, B untuk Rawat "
            "Berjalan): ";
    cin >> tipePerawatan;
    cout << "===========================================" << endl;

    if (tipePerawatan == 'I' || tipePerawatan == 'i') {
      int jeniskamar, nomerkamar;
    
      cout << "=====================================" << endl;
      cout << "||\t\tJenis Kamar\t\t||" << endl;
      cout << "=====================================" << endl;
      cout << " 1. Kamar VIP " << endl;
      cout << " 2. Kamar VVIP " << endl;
      cout << " 3. Kamar Kelas 1" << endl;
      cout << " 4. Kamar Kelas 2" << endl;
      cout << "=====================================" << endl;
      cout << "Masukan Pilihan (1-4) : ";
      cin >> jeniskamar;

      switch (jeniskamar) {
      case 1:
        namaFile = filekamarVIP;
        pasienBaru.jeniskamar = "VIP";
        break;
      case 2:
        namaFile = filekamarVVIP;
        pasienBaru.jeniskamar = "VVIP";
        break;
      case 3:
        namaFile = filekamarKelas1;
        pasienBaru.jeniskamar = "KELAS1";
        break;
      case 4:
        namaFile = filekamarKelas2;
        pasienBaru.jeniskamar = "KELAS2";
        break;
      default:
        cout << "Kelas kamar tidak valid." << endl;
        return;
      }

      kamarpasien *kamar = bacaDataKamar(namaFile, jumlahData);

      tampilkanDataKamar(kamar, jumlahData, jeniskamar);
      cout << "masukan pilihan (masukan monor kamar) : ";
      cin >> nomerkamar;

      cout << "Pasien Rawat Inap berhasil ditambahkan.\n";
    } else if (tipePerawatan == 'B' || tipePerawatan == 'b') {
      cout << "=====================================" << endl;
      cout << "||\t\tRawat Jalan \t\t||" << endl;
      cout << "=====================================" << endl;
      cout << " 1. Tanggal Kontrol " << endl;
      cout << " 2. Update Kondisi " << endl;

      cout << "Pasien Rawat Berjalan berhasil ditambahkan.\n";
    } else {
      cout << "Pilihan Tipe Perawatan tidak valid.\n";
    }

    // pasienbaru(pasienBaru);
  } else if (kategori == 2) {

    int jenis;
    pasienBaru.umurpasien = "parubaya";
    cout << "===========================================" << endl;
    cout << " 1. Pasien BPJS " << endl;
    cout << " 2. Pasien Umum " << endl;
    cout << "===========================================" << endl;
    cout << " Masukan Pilihan : ";
    cin >> jenis;
    cout << "===========================================" << endl;

    if (jenis == 1) {
      pasienBaru.jenispasien = "bpjs";
    } else if (jenis == 2) {
      pasienBaru.jenispasien = " umum ";
    } else {
      cout << "yang anda masukan tidak sesuai " << endl;
    }
    cout << "Masukkan Nama Pasien: ";
    cin.ignore();
    getline(cin, pasienBaru.nama);
    cout << "===========================================" << endl;

    cout << "Masukkan Usia Pasien: ";
    cin >> pasienBaru.usia;
    cout << "===========================================" << endl;

    cout << "Masukkan Diagnosa Pasien: ";
    cin.ignore();
    getline(cin, pasienBaru.diagnosa);
    cout << "===========================================" << endl;

    char tipePerawatan;
    cout << "Pilih Tipe Perawatan (I untuk Rawat Inap, B untuk Rawat "
            "Berjalan): ";
    cin >> tipePerawatan;
    cout << "===========================================" << endl;

    if (tipePerawatan == 'I' || tipePerawatan == 'i') {
      int jeniskamar, nomerkamar;

      cout << "=====================================" << endl;
      cout << "||\t\tJenis Kamar\t\t||" << endl;
      cout << "=====================================" << endl;
      cout << " 1. Kamar VIP " << endl;
      cout << " 2. Kamar VVIP " << endl;
      cout << " 3. Kamar Kelas 1" << endl;
      cout << " 4. Kamar Kelas 2" << endl;
      cout << "=====================================" << endl;
      cout << "Masukan Pilihan (1-4) : ";
      cin >> jeniskamar;

      switch (jeniskamar) {
      case 1:
        namaFile = filekamarVIP;
        pasienBaru.jeniskamar = "VIP";
        break;
      case 2:
        namaFile = filekamarVVIP;
        pasienBaru.jeniskamar = "VVIP";
        break;
      case 3:
        namaFile = filekamarKelas1;
        pasienBaru.jeniskamar = "KELAS1";
        break;
      case 4:
        namaFile = filekamarKelas2;
        pasienBaru.jeniskamar = "KELAS2";
        break;
      default:
        cout << "Kelas kamar tidak valid." << endl;
        return;
      }

      kamarpasien *kamar = bacaDataKamar(namaFile, jumlahData);

      tampilkanDataKamar(kamar, jumlahData, jeniskamar);
      cout << "masukan pilihan (masukan monor kamar) : ";
      cin >> nomerkamar;

      cout << "Pasien Rawat Inap berhasil ditambahkan.\n";
    } else if (tipePerawatan == 'B' || tipePerawatan == 'b') {
      cout << "=====================================" << endl;
      cout << "||\t\tRawat Jalan \t\t||" << endl;
      cout << "=====================================" << endl;
      cout << " 1. Tanggal Kontrol " << endl;
      cout << " 2. Update Kondisi " << endl;
      cout << "=====================================" << endl;
      cout << "Masukan Pilihan : ";
      cin >> rawatjalan;

      // switch(rawatjalan){
      //   case 1:

      // }

      cout << "Pasien Rawat Berjalan berhasil ditambahkan.\n";
    } else {
      cout << "Pilihan Tipe Perawatan tidak valid.\n";
    }

    // pasienbaru(pasienBaru);
  } else if (kategori == 3) {
    int jenis;
    pasienBaru.umurpasien = "anak";
    cout << "===========================================" << endl;
    cout << " 1. Pasien BPJS " << endl;
    cout << " 2. Pasien Umum " << endl;
    cout << "===========================================" << endl;
    cout << " Masukan Pilihan : ";
    cin >> jenis;
    cout << "===========================================" << endl;

    if (jenis == 1) {
      pasienBaru.jenispasien = "bpjs";
    } else if (jenis == 2) {
      pasienBaru.jenispasien = " umum ";
    } else {
      cout << "yang anda masukan tidak sesuai " << endl;
    }
    cout << "Masukkan Nama Pasien: ";
    cin.ignore();
    getline(cin, pasienBaru.nama);
    cout << "===========================================" << endl;

    cout << "Masukkan Usia Pasien: ";
    cin >> pasienBaru.usia;
    cout << "===========================================" << endl;

    cout << "Masukkan Diagnosa Pasien: ";
    cin.ignore();
    getline(cin, pasienBaru.diagnosa);
    cout << "===========================================" << endl;

    char tipePerawatan;
    cout << "Pilih Tipe Perawatan (I untuk Rawat Inap, B untuk Rawat "
            "Berjalan): ";
    cin >> tipePerawatan;
    cout << "===========================================" << endl;

    if (tipePerawatan == 'I' || tipePerawatan == 'i') {
      int jeniskamar, nomerkamar ;

      cout << "=====================================" << endl;
      cout << "||\t\tJenis Kamar\t\t||" << endl;
      cout << "=====================================" << endl;
      cout << " 1. Kamar VIP " << endl;
      cout << " 2. Kamar VVIP " << endl;
      cout << " 3. Kamar Kelas 1" << endl;
      cout << " 4. Kamar Kelas 2" << endl;
      cout << "=====================================" << endl;
      cout << "Masukan Pilihan (1-4) : ";
      cin >> jeniskamar;

      switch (jeniskamar) {
      case 1:
        namaFile = filekamarVIP;
        pasienBaru.jeniskamar = "VIP";
        break;
      case 2:
        namaFile = filekamarVVIP;
        pasienBaru.jeniskamar = "VVIP";
        break;
      case 3:
        namaFile = filekamarKelas1;
        pasienBaru.jeniskamar = "KELAS1";
        break;
      case 4:
        namaFile = filekamarKelas2;
        pasienBaru.jeniskamar = "KELAS2";
        break;
      default:
        cout << "Kelas kamar tidak valid." << endl;
        return;
      }

      kamarpasien *kamar = bacaDataKamar(namaFile, jumlahData);

      tampilkanDataKamar(kamar, jumlahData, jeniskamar);
      cout << "masukan pilihan (masukan monor kamar) : ";
      cin >> nomerkamar;
      
      cout << "Pasien Rawat Inap berhasil ditambahkan.\n";
    } else if (tipePerawatan == 'B' || tipePerawatan == 'b') {
      int masukdatabaru;
      cout << "=====================================" << endl;
      cout << "||\t\tRawat Jalan \t\t||" << endl;
      cout << "=====================================" << endl;
      cout << " 1. Tanggal Kontrol " << endl;
      cout << " 2. Update Kondisi " << endl;
      cout << "=====================================" << endl;
      cout << " masukan pilihan : ";
      // cin >> masukdatabaru;

      // if(masukdatabaru == 1){
      //   tampilkanDataPasien();

        
        
      // }

      cout << "Pasien Rawat Berjalan berhasil ditambahkan.\n";
    } else {
      cout << "Pilihan Tipe Perawatan tidak valid.\n";
    }

    // pasienbaru(pasienBaru);
  }
  Resize(jumlahPasien + 1);
  daftarPasien[jumlahPasien++] = pasienBaru;
  simpanDataKeFilePasien();
}

void Admin::editDataPasien() {
    cout << "                              .:----=====---:." << endl;
    cout << "                           :-=--:::::::::::::-=-." << endl;
    cout << "                         -=-::::::::::::::::::::=:" << endl;
    cout << "                       :=-:::::::::::::::::::::::====-:." << endl;
    cout << "                      -=::::::::::::::::::::::::::::::-==." << endl;
    cout << "                     -=::::::::::::::::::::::::::::::::::=:" << endl;
    cout << "                    .+::::::::::::::::::::::::::::::::::::+:" << endl;
    cout << "                    =-:::::::::::::::::::::::::==-::::::::-=" << endl;
    cout << "                    +:::::::::::::::::::::::-==:.:==-::::::+" << endl;
    cout << "                    +:::::::::::::::::::--==-.......==:::::+" << endl;
    cout << "                    +-::::::--=======----:...........-+:::-=" << endl;
    cout << "                    -=:::-==::........................-=::=:" << endl;
    cout << "                    .+::-=.............................+::+" << endl;
    cout << "                    .==:+:.............................+:==." << endl;
    cout << "                    =-+-+..............................+-+:=." << endl;
    cout << "                    -=--++..............................++-:=" << endl;
    cout << "                    .=:=+..............................+=:=." << endl;
    cout << "                     .--=..............................=--." << endl;
    cout << "                       .=:.............................=." << endl;
    cout << "                        :-............................-:" << endl;
    cout << "                         -:..........................:-" << endl;
    cout << "                          -:........................:-" << endl;
    cout << "                           :-:.....................-:" << endl;
    cout << "                             :-:................:-:" << endl;
    cout << "                              =----::......::----=" << endl;
    cout << "                              =::::----------::::=" << endl;
    cout << "                       .::::::=::::::::::::::::::=::::::." << endl;
    cout << "                   .:::.      .---:::::::::::::--.      .:::." << endl;
    cout << "                 ::.             :--::::::::--:             .::." << endl;
    cout << "              .::                  :========:                  :." << endl;
    cout << "             ::                     :======:                     ::" << endl;
    cout << "           .-.                       :====:                       -." << endl;
    cout << "          .-                         .====.                         -." << endl;
    cout << "         .-                          ======                          -." << endl;
    cout << "         -                          -======-                          -" << endl;
    cout << "        ::                         .========.                         ::" << endl;
    cout << "        -.                         ==========                          -" << endl;
    cout << "        =:::::::::::::::::::::::::-==========-:::::::::::::::::::::::::" << endl;
    string namaPasien;
    tampilkanDataPasien();
    
    cout << "Masukkan Nama Pasien yang akan diedit: ";
    cin.ignore();
    getline(cin, namaPasien);

    int index = -1;
    for (int i = 0; i < jumlahPasien; ++i) {
        if (daftarPasien[i].nama == namaPasien) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Masukkan data baru untuk pasien " << namaPasien << ":\n";
        cout << "Usia: ";
        cin >> daftarPasien[index].usia;
        cout << "Diagnosa: ";
        cin.ignore();
        getline(std::cin, daftarPasien[index].diagnosa);
        cout << "Jenis Pasien: ";
        cin >> daftarPasien[index].jenispasien;
        cout << "Data pasien berhasil diupdate.\n";
    } else {
        cout << "Pasien dengan nama " << namaPasien << " tidak ditemukan.\n";
    }

    simpanDataKeFilePasien1();
  
}
void Admin::muatDataDariFilePasien() {
  ifstream file(namaFilePasien);
  daftarPasien = nullptr;
  jumlahPasien = 0;

  if (file.is_open()) {
    int count = 0;
    string line;
    while (getline(file, line)) {
      ++count;
    }

    daftarPasien = new Pasien[count];
    file.clear();
    file.seekg(0, std::ios::beg);

    while (file >> daftarPasien[jumlahPasien].nama >>
           daftarPasien[jumlahPasien].usia >>
           daftarPasien[jumlahPasien].diagnosa >>
           daftarPasien[jumlahPasien].jenispasien >>
           daftarPasien[jumlahPasien].umurpasien ) {
      ++jumlahPasien;
    }

    file.close();

    for (int i = 0; i < jumlahPasien - 1; ++i) {
      for (int j = 0; j < jumlahPasien - i - 1; ++j) {
        if (daftarPasien[j].nama > daftarPasien[j + 1].nama) {
          Pasien temp = daftarPasien[j];
          daftarPasien[j] = daftarPasien[j + 1];
          daftarPasien[j + 1] = temp;
        }
      }
    }
  } else {
    cerr << "Gagal membuka file " << namaFilePasien << std::endl;
  }
}



void Admin::tampilkanDataPasien() {
  muatDataDariFilePasien();
  cout << "========================================================" << endl;
  cout << "||\t\t\tDATA PASIEN\t\t\t||" << endl;
  cout << "========================================================" << endl;
  cout << "|| Nama    |    Usia    |    Diagnosa    |    jenis   ||" << endl;
  cout << "========================================================" << endl;
  for (int i = 0; i < jumlahPasien; ++i) {
    cout <<"\t"<<daftarPasien[i].nama << " \t\t" << daftarPasien[i].usia << "\t\t\t "
         << daftarPasien[i].diagnosa << " \t\t\t" << daftarPasien[i].jenispasien<<"\t\t"
         << daftarPasien[i].umurpasien <<"\n";
    cout << "========================================================" << endl;
  }
}

void Admin::tampilpasienumur() {
  int patokanumur;
  muatDataDariFilePasien();
  cout << "masukan patokan umur : ";
  cin>>patokanumur;

  cout << "========================================================" << endl;
  cout << "||\t\t\tDATA PASIEN\t\t\t||" << endl;
  cout << "========================================================" << endl;
  cout << "|| Nama    |    Usia    |    Diagnosa    |    jenis   ||" << endl;
  cout << "========================================================" << endl;
  for (int i = 0; i < jumlahPasien; ++i) {
    if (daftarPasien[i].usia >= patokanumur){
      cout <<"\t"<<daftarPasien[i].nama << " \t\t" << daftarPasien[i].usia << "\t\t\t "
       << daftarPasien[i].diagnosa << " \t\t\t" << daftarPasien[i].jenispasien<< "\t\t"
       << daftarPasien[i].umurpasien <<"\n";
    }
    cout << "========================================================" << endl;
  }
}

void Admin::tampilpasienumur2() {
  int patokanumur;
  muatDataDariFilePasien();
  cout << "masukan patokan umur : ";
  cin>>patokanumur;

  cout << "========================================================" << endl;
  cout << "||\t\t\tDATA PASIEN\t\t\t||" << endl;
  cout << "========================================================" << endl;
  cout << "|| Nama    |    Usia    |    Diagnosa    |    jenis   ||" << endl;
  cout << "========================================================" << endl;
  for (int i = 0; i < jumlahPasien; ++i) {
    if (daftarPasien[i].usia <= patokanumur){
      cout <<"\t"<<daftarPasien[i].nama << " \t\t" << daftarPasien[i].usia << "\t\t\t"
       << daftarPasien[i].diagnosa << " \t\t\t" << daftarPasien[i].jenispasien<< "\t\t"
       << daftarPasien[i].umurpasien <<"\n";
    }
    cout << "========================================================" << endl;
  }
}

void Admin::tampilpasiendiagnosa() {
  string patokan;
  muatDataDariFilePasien();
  tampilkanDataPasien();
  cout << "masukan patokan umur : ";
  cin>>patokan;

  cout << "========================================================" << endl;
  cout << "||\t\t\tDATA PASIEN\t\t\t||" << endl;
  cout << "========================================================" << endl;
  cout << "|| Nama    |    Usia    |    Diagnosa    |    jenis   ||" << endl;
  cout << "========================================================" << endl;
  for (int i = 0; i < jumlahPasien; ++i) {
    if (daftarPasien[i].diagnosa == patokan){
      cout <<"\t"<<daftarPasien[i].nama << " \t\t" << daftarPasien[i].usia << "\t\t\t "
       << daftarPasien[i].diagnosa << " \t\t\t" << daftarPasien[i].jenispasien<< "\t\t\t"
       << daftarPasien[i].umurpasien <<"\n";
    }
  }
  cout << "========================================================" << endl;
}

void Admin::tampilpasientermuda() {
  int patokan;
  muatDataDariFilePasien();
  cout << "===========================================" << endl;
  cout << "||\t\tJenis Pasien\t\t||" << endl;
  cout << "===========================================" << endl;
  cout << " 1. Pasien Lansia " << endl;
  cout << " 2. Pasien Parubaya " << endl;
  cout << " 3. Pasien Anak " << endl;
  cout << "===========================================" << endl;
  cout << " Masukan Pilihan Anda : ";
  cin>>patokan;
  string data;

  if ( patokan == 1 ){
    data = "lansia";
  }else if ( patokan == 2){
    data = "parubaya";
  }else if ( patokan == 3){
    data = "anak";
  }

  vector<Pasien> pasienBerdasarkanJenis;

  for (int i = 0; i < jumlahPasien; ++i) {
    if (daftarPasien[i].umurpasien == data) {
        pasienBerdasarkanJenis.push_back(daftarPasien[i]);
    }
  }

  if (pasienBerdasarkanJenis.empty()) {
    cout << "Tidak ada data pasien dengan jenis " << data << ".\n";
    return;
  }

  sort(pasienBerdasarkanJenis.begin(), pasienBerdasarkanJenis.end(),
     [](const Pasien& a, const Pasien& b) { return a.usia < b.usia; });

  cout << "========================================================" << endl;
  cout << "||\t\t\tDATA PASIEN\t\t\t||" << endl;
  cout << "========================================================" << endl;
  cout << "|| Nama    |    Usia    |    Diagnosa    |    jenis   ||" << endl;
  cout << "========================================================" << endl;
      cout << pasienBerdasarkanJenis[0].nama << "\t" << pasienBerdasarkanJenis[0].usia << "\t"
       << pasienBerdasarkanJenis[0].diagnosa << "\t" << pasienBerdasarkanJenis[0].jenispasien << "\t"
       << pasienBerdasarkanJenis[0].umurpasien << "\n";
    cout << "========================================================" << endl;
  }

void Admin::simpanDataKeFilePasien() {
    ifstream fileCheck(namaFilePasien);
    string line;

    while (getline(fileCheck, line)) {
        if (line.find(daftarPasien[jumlahPasien - 1].nama) != string::npos) {
            cout << "Data pasien dengan nama " << daftarPasien[jumlahPasien - 1].nama << " sudah ada dalam file.\n";
            return;
        }
    }

    fileCheck.close();

          ofstream file("data_pasien.txt", ios::app); 

          if (file.is_open()) {
            for (int i = jumlahPasien - 1; i < jumlahPasien; ++i) {
                file << daftarPasien[i].nama << " "
                     << daftarPasien[i].usia << " "
                     << daftarPasien[i].diagnosa << " "
                     << daftarPasien[i].jenispasien << " "
                     << daftarPasien[i].umurpasien << endl;
            }

            file.close();
        
    } else {
        cout << "Gagal membuka file untuk menyimpan data pasien.\n";
    }
}

void Admin::simpanDataKeFilePasien1() {
  ofstream file("data_pasien.txt");
  
  
  if (file.is_open()) { 
    for (int i = 0; i < jumlahPasien; ++i) {
      file << daftarPasien[i].nama << " " 
           << daftarPasien[i].usia << " "
           << daftarPasien[i].diagnosa << " " 
           << daftarPasien[i].jenispasien << " "
           << daftarPasien[i].umurpasien << endl;
    }

    file.close();
  } else {
    cout << "Gagal membuka file untuk menyimpan data pasien.\n";
  }
}

#endif