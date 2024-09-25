#ifndef DOKTER_H
#define DOKTER_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "proses.h"

using namespace std;

const int MAX_DOKTER = 100;  

struct Pesan {
    int idDokter;
    string namaDokter;
    string namaPasien;
    string isiPesan;
};

struct Dokter {
    int id;
    string nama;
    string spesialis;
    vector<Pesan> pesanKePasien;
};

class RumahSakit {
private:
    Dokter daftarDokter[MAX_DOKTER];
    int jumlahDokter;

public:
    RumahSakit() : jumlahDokter(0) {}

    void tambahDokter(int id, const string& nama, const string& spesialis);
    void tambahPesanDokter(int idDokter, const string& namaPasien, const string& isiPesan);
    void tampilkanInfoDokter(int id);
    void tampilkanSemuaDokter();
    void simpanKeFile();
    void bacaDariFile();
    void simpanPesanKeFile(const Pesan& pesanDokter);
    void tampilkanPesanDokter(int idDokter);
    void editDokter(int id);
    void tampilkanSemuaDokterkecil();
    void tampilkanSemuaDokterbesar();

};
    void RumahSakit::tambahDokter(int id, const string& nama, const string& spesialis) {
        if (jumlahDokter < MAX_DOKTER) {
            Dokter dokter;
            dokter.id = id;
            dokter.nama = nama;
            dokter.spesialis = spesialis;
            daftarDokter[jumlahDokter++] = dokter;


            simpanKeFile();
        } else {
            cerr << "Kapasitas array dokter sudah mencapai batas maksimum." << endl;
        }
    }

    void RumahSakit::simpanKeFile() {
        ofstream file("dokter.txt");
        if (file.is_open()) {
            for (int i = 0; i < jumlahDokter; ++i) {
                file << daftarDokter[i].id << " " << daftarDokter[i].nama << " " << daftarDokter[i].spesialis << '\n';
            }
            file.close();
        } else {
            cerr << "Gagal membuka file untuk penyimpanan data dokter." << endl;
        }
    }

    void RumahSakit::bacaDariFile() {
        ifstream file("dokter.txt");
        if (file.is_open()) {
            jumlahDokter = 0; 
            while (!file.eof() && jumlahDokter < MAX_DOKTER) {
                file >> daftarDokter[jumlahDokter].id;
                file.ignore(); 
                getline(file, daftarDokter[jumlahDokter].nama);
                getline(file, daftarDokter[jumlahDokter].spesialis, '\n');

                if (!daftarDokter[jumlahDokter].nama.empty() && !daftarDokter[jumlahDokter].spesialis.empty()) {
                    jumlahDokter++;
                }
            }

            file.close();
        } else {
            cerr << "Gagal membuka file untuk membaca data dokter." << endl;
        }
    }

    void RumahSakit::tambahPesanDokter(int idDokter, const string& namaPasien, const string& isiPesan) {
        auto it = find_if(daftarDokter, daftarDokter + jumlahDokter,
                          [idDokter](const Dokter& dokter) { return dokter.id == idDokter; });

        if (it != daftarDokter + jumlahDokter) {
            Pesan pesanDokter;
            pesanDokter.idDokter = it->id;
            pesanDokter.namaDokter = it->nama;
            pesanDokter.namaPasien = namaPasien;
            pesanDokter.isiPesan = isiPesan;

            it->pesanKePasien.push_back(pesanDokter);


            RumahSakit::simpanPesanKeFile(pesanDokter);
        } else {
            cout << "Dokter dengan ID " << idDokter << " tidak ditemukan." << endl;
        }
    }

    void RumahSakit::simpanPesanKeFile(const Pesan& pesanDokter) {
        ofstream file("pesan_dokter.txt", ios::app);
        if (file.is_open()) {
            file << pesanDokter.idDokter << " " << pesanDokter.namaDokter << " " << pesanDokter.namaPasien
                 << " " << pesanDokter.isiPesan << '\n';
            file.close();
        } else {
            cerr << "Gagal membuka file untuk penyimpanan pesan dokter." << endl;
        }
    }

    void RumahSakit::tampilkanPesanDokter(int idDokter) {
        auto it = find_if(daftarDokter, daftarDokter + jumlahDokter,
                          [idDokter](const Dokter& dokter) { return dokter.id == idDokter; });

        if (it != daftarDokter + jumlahDokter) {
            cout << "Pesan dari Dokter " << it->nama << " untuk Pasien:\n";
            for (const Pesan& pesan : it->pesanKePasien) {
                cout << "  Nama Pasien: " << pesan.namaPasien << "\n";
                cout << "  Isi Pesan: " << pesan.isiPesan << "\n";
                cout << "---------------------\n";
            }
        } else {
            cout << "Dokter dengan ID " << idDokter << " tidak ditemukan." << endl;
        }
    }

    void RumahSakit::editDokter(int id) {
        auto it = find_if(daftarDokter, daftarDokter + jumlahDokter,
                          [id](const Dokter& dokter) { return dokter.id == id; });

        if (it != daftarDokter + jumlahDokter) {
            cout << "Masukkan Nama Dokter Baru (dr.nama) : ";
            cin.ignore();
            getline(cin, it->nama);

            cout << "Masukkan Spesialis Dokter Baru: ";
            getline(cin, it->spesialis);

            cout << "Data Dokter berhasil diubah." << endl;


            simpanKeFile();
        } else {
            cout << "Dokter dengan ID " << id << " tidak ditemukan." << endl;
        }
    }

    void RumahSakit::tampilkanInfoDokter(int id) {
        auto it = find_if(daftarDokter, daftarDokter + jumlahDokter,
                          [id](const Dokter& dokter) { return dokter.id == id; });

        if (it != daftarDokter + jumlahDokter) {
            cout << "ID Dokter: " << it->id << endl;
            cout << "Nama Dokter: " << it->nama << endl;
            cout << "Spesialis: " << it->spesialis << endl;
        } else {
            cout << "Dokter dengan ID " << id << " tidak ditemukan." << endl;
        }
    }

    void RumahSakit::tampilkanSemuaDokter() {
        cout << "===================================================" << endl;
        cout << "Daftar Dokter di Rumah Sakit:" << endl;
        cout << "===================================================" << endl;
        for (int i = 0; i < jumlahDokter; ++i) {
            cout << "ID Dokter: " << daftarDokter[i].id << ", Nama Dokter: " << daftarDokter[i].nama
                 << ", Spesialis: " << daftarDokter[i].spesialis << endl;
        }
        cout << "===================================================" << endl;
    }

    void RumahSakit::tampilkanSemuaDokterkecil() {
      int patokan;
      cout<<"masukan angka patokan :";
      cin>>patokan;
        cout << "===================================================" << endl;
        cout << "Daftar Dokter di Rumah Sakit:" << endl;
        cout << "===================================================" << endl;
        for (int i = 0; i < jumlahDokter; ++i) {
          if(daftarDokter[i].id <= patokan){
            cout << "ID Dokter: " << daftarDokter[i].id << ", Nama Dokter: " << daftarDokter[i].nama
                 << ", Spesialis: " << daftarDokter[i].spesialis << endl;
          }
        }
        cout << "===================================================" << endl;
    }

    void RumahSakit::tampilkanSemuaDokterbesar() {
      int patokan;
      cout<<"masukan angka patokan :";
      cin>>patokan;
        cout << "===================================================" << endl;
        cout << "Daftar Dokter di Rumah Sakit:" << endl;
        cout << "===================================================" << endl;
        for (int i = 0; i < jumlahDokter; ++i) {
          if(daftarDokter[i].id >= patokan){
            cout << "ID Dokter: " << daftarDokter[i].id << ", Nama Dokter: " << daftarDokter[i].nama
                 << ", Spesialis: " << daftarDokter[i].spesialis << endl;
          }
        }
        cout << "===================================================" << endl;
    }


 void Login::dokterbaru(){
    RumahSakit rumahSakit;

    rumahSakit.bacaDariFile();

    int pilihan;
    do {
        cout << "\nMenu: \n";
        cout << "1. Tambah Dokter\n";
        cout << "2. Edit Data Dokter\n";
        cout << "3. Tampilkan Semua Dokter\n";
        cout << "4. Tampilkan Info Dokter\n";
        cout << "5. Tambah Pesan Dokter untuk Pasien\n";
        cout << "6. Tampilkan Pesan Dokter untuk Pasien\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu (1-7): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int id;
                string nama, spesialis;
                cout << "Masukkan ID Dokter: ";
                cin >> id;
                cout << "Masukkan Nama Dokter (dr.nama): ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Spesialis Dokter: ";
                getline(cin, spesialis);
                rumahSakit.tambahDokter(id, nama, spesialis);
                break;
            }
            case 2: {
                rumahSakit.tampilkanSemuaDokter();
                int id2;
                cout << "Masukkan ID Dokter yang ingin diubah: ";
                cin >> id2;
                rumahSakit.editDokter(id2);
                break;
            }
            case 3:
                int pilih;
                cout <<"==================================="<<endl;
                cout <<" 1. tampilkan semua data dokter "<<endl;
                cout <<" 2. tampilkan dokter dengan id < patokan "<<endl;
                cout <<" 3. tampilkan dokter dengan id > patokan "<<endl;
                cout <<"==================================="<<endl;
                cout <<"masukan pilihan : ";
                cin >> pilih;

                if(pilih == 1){
                  rumahSakit.tampilkanSemuaDokter();
                }else if(pilih == 2){
                  rumahSakit.tampilkanSemuaDokterkecil();
          
                  
                }else if(pilih == 3){
                  rumahSakit.tampilkanSemuaDokterbesar();
                }else{
                  cout <<"data yang masukan tidak sesuai"<<endl;
                }
                break;
            case 4: {
                int id3;
                cout << "Masukkan ID Dokter yang ingin ditampilkan informasinya: ";
                cin >> id3;
                rumahSakit.tampilkanInfoDokter(id3);
                break;
            }
            case 5: {
                int idDokter;
                string namaPasien, pesan;
                cout << "Masukkan ID Dokter: ";
                cin >> idDokter;
                cout << "Masukkan Nama Pasien: ";
                cin.ignore();
                getline(cin, namaPasien);
                cout << "Masukkan Pesan untuk Pasien: ";
                getline(cin, pesan);
                rumahSakit.tambahPesanDokter(idDokter, namaPasien, pesan);
                break;
            }
            case 6: {
                int idDokter;
                cout << "Masukkan ID Dokter untuk menampilkan pesan: ";
                cin >> idDokter;
                rumahSakit.tampilkanPesanDokter(idDokter);
                break;
            }
            case 7:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 7);

 }


#endif