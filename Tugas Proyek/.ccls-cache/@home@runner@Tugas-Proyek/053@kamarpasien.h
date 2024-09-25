#ifndef KAMARPASIEN_H
#define KAMARPASIEN_H

#include "admin.h"
#include "proses.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

struct KamarPasien {
  int nomor;
  int harga;
  bool kosong;

  KamarPasien *next;
  KamarPasien *prev;
};

class Kamar {
public:
  Kamar();
  void tampilDataKamar();
  void perbaruiDataKamar();
  void tambahDataKamar();

private:
  int kelasKamar;
  const string fileKamarKelas1 = "kamar_kls1.txt";
  const string fileKamarKelas2 = "kamar_kls2.txt";
  const string fileKamarVIP = "kamar_vip.txt";
  const string fileKamarVVIP = "kamar_vvip.txt";

  KamarPasien *head, *tail, *cur, *newNode;

  void bacaDataKamar(const string &namaFile);
  void tulisDataKamar(const string &namaFile, const KamarPasien *head);
};

Kamar::Kamar() : head(nullptr), tail(nullptr) {}

void Kamar::bacaDataKamar(const string &namaFile) {
  ifstream file(namaFile);
  if (!file) {
    cout << "File " << namaFile << " tidak dapat dibaca." << endl;
    return;
  }

  int nomor, harga;
  bool kosong;
  string line;

  head = tail = nullptr;

  while (getline(file, line)) {
    istringstream iss(line);
    if (!(iss >> nomor >> harga >> kosong)) {
      cerr << "Error: Invalid data in file." << endl;
      continue;
    }

    newNode = new KamarPasien();
    newNode->nomor = nomor;
    newNode->harga = harga;
    newNode->kosong = kosong;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }

  file.close();
}

void Kamar::tulisDataKamar(const string &namaFile, const KamarPasien *head) {
  ofstream file(namaFile);
  if (!file) {
    cout << "File " << namaFile << " tidak dapat ditulis." << endl;
    return;
  }

  const KamarPasien *current = head;
  while (current) {
    file << current->nomor << " " << current->harga << " " << current->kosong
         << endl;
    current = current->next;
  }

  file.close();
}

void Kamar::tampilDataKamar() {
  cout << "                                                               .      -#:      ." << endl;
  cout << "                                                               ==#==::+#=:::::::" << endl;
  cout << "                                                              =##*##= -#:       " << endl;
  cout << "                                                              =#= +#+ -#:       " << endl;
  cout << "                                                              =#=.-#= -#:       " << endl;
  cout << "                                                              =#####= -#:       " << endl;
  cout << "                                                               :#-+:  -#:       " << endl;
  cout << "                                                                *     -#:       " << endl;
  cout << "                                                               .+     -#:       " << endl;
  cout << "                                                              .+.     -#:       " << endl;
  cout << "        :+***+-                                             :-=       -#:       " << endl;
  cout << "       +#######*.                              :------------:         -#:       " << endl;
  cout << "      .#########=                            =-.                      -#:       " << endl;
  cout << "       *########:===--:                     +.                        -#:       " << endl;
  cout << ":+*+*#*=+*###*=+#=*##+===--.   ..          =-                         -#:       " << endl;
  cout << "##########*-   ##:#######*+++++#####**++++#=--::..                    -#:       " << endl;
  cout << ".=*########+:. =##=-+###############################*=-.              -#:       " << endl;
  cout << "    :=*#######*=-=*#*==========*########################*-            -#:       " << endl;
  cout << "       .-+########+=++####################################*           -#:       " << endl;
  cout << "           .=+########+===+*###############################:          -#:       " << endl;
  cout << "              :=*#######################################-        -#:       " << endl;
  cout << "                 .:=*#######################################-.     -#:       " << endl;
  cout << "                     :=*#####################################*     -#:       " << endl;
  cout << "                        .###################################*     -#:       " << endl;
  cout << "      =+++++++++++++++*#####################################*.     -#:       " << endl;
  cout << "     .#######################################################*.    -#:       " << endl;
  cout << "      ..:.::+##+-------------------------------------------=##+     -#:       " << endl;
  cout << "            =##-                                           :##+     =#:       " << endl;
  cout << "            =##-                                           :##+     =#:       " << endl;
  cout << "            =##-                                           :##+     =#:       " << endl;
  cout << "            =##*++++++++++++++++++++++++++++++++++++++++++++##+     =#:       " << endl;
  cout << "            =##=-:--:-:--:-::-:--:-::-:-::-:--:-::-:--:-:--=##+  .--+#=--.    " << endl;
  cout << "            +##-                                           -##* :**=-----=#*.  " << endl;
  cout << "           :####                                           ####:=##-       =##= " << endl;
  cout << "================================================" << endl;
  cout << "1. kamar vip " << endl;
  cout << "2. kamar vvip " << endl;
  cout << "3. kamar kelas 1 " << endl;
  cout << "4. kamar kelas 2 " << endl;
  cout << "================================================" << endl;
  cout << "Masukkan kelas kamar yang ingin ditampilkan: ";
  cin >> kelasKamar;

  switch (kelasKamar) {
  case 1:
    bacaDataKamar(fileKamarVIP);
    break;
  case 2:
    bacaDataKamar(fileKamarVVIP);
    break;
  case 3:
    bacaDataKamar(fileKamarKelas1);
    break;
  case 4:
    bacaDataKamar(fileKamarKelas2);
    break;
  default:
    cout << "Kelas kamar tidak valid." << endl;
    return;
  }

  if (kelasKamar == 1) {
    cout << "=======================================" << endl;
    cout << "||\t\t\t KAMAR VIP \t\t\t||" << endl;
    cout << "=======================================" << endl;
  } else if (kelasKamar == 2) {
    cout << "=======================================" << endl;
    cout << "||\t\t\t KAMAR VVIP \t\t\t||" << endl;
    cout << "=======================================" << endl;
  } else if (kelasKamar == 3) {
    cout << "=======================================" << endl;
    cout << "||\t\t\t KAMAR KELAS 1 \t\t\t||" << endl;
    cout << "=======================================" << endl;
  } else if (kelasKamar == 4) {
    cout << "=======================================" << endl;
    cout << "||\t\t\t KAMAR KELAS 2 \t\t\t||" << endl;
    cout << "=======================================" << endl;
  }

  if (head == nullptr) {
    cout << "Data kamar kosong." << endl;
  } else {
    cur = head;
    while (cur != nullptr) {
      cout << "|| " << cur->nomor << "  " << cur->harga << "  " << cur->kosong
           << " ||" << endl;
      cur = cur->next;
    }
  }
}

void Kamar::perbaruiDataKamar() {
  int nomor;
  bool kosong;

  tampilDataKamar();

  cout << "Masukkan nomor kamar yang ingin diperbarui: ";
  cin >> nomor;

  KamarPasien *current = head;
  while (current) {
    if (current->nomor == nomor) {
      cout << "Status sekarang: " << (current->kosong ? "Kosong" : "Isi")
           << endl;
      cout << "Ubah status kamar? (1 untuk Kosong, 0 untuk Isi): ";
      cin >> kosong;

      current->kosong = kosong;

      switch (kelasKamar) {
      case 1:
        tulisDataKamar(fileKamarVIP, head);
        break;
      case 2:
        tulisDataKamar(fileKamarVVIP, head);
        break;
      case 3:
        tulisDataKamar(fileKamarKelas1, head);
        break;
      case 4:
        tulisDataKamar(fileKamarKelas2, head);
        break;
      default:
        cout << "Kelas kamar tidak valid." << endl;
        return;
      }

      cout << "Data kamar berhasil diperbarui." << endl;
      return;
    }
    current = current->next;
  }

  cout << "Nomor kamar tidak ditemukan." << endl;
}

void Kamar::tambahDataKamar() {
  int nomor, harga;
  bool kosong;

  cout << "================================================" << endl;
  cout << "1. kamar vip " << endl;
  cout << "2. kamar vvip " << endl;
  cout << "3. kamar kelas 1 " << endl;
  cout << "4. kamar kelas 2 " << endl;
  cout << "================================================" << endl;
  cout << "Masukkan kelas kamar yang ingin diperbarui: ";
  cin >> kelasKamar;

  if (kelasKamar < 1 || kelasKamar > 4) {
    cout << "Kelas kamar tidak valid." << endl;
    return;
  }

  if (kelasKamar == 1) {
    cout << "=======================================" << endl;
    cout << "||\t\t KAMAR VIP \t\t||" << endl;
    cout << "=======================================" << endl;
  } else if (kelasKamar == 2) {
    cout << "=======================================" << endl;
    cout << "||\t\t KAMAR VVIP \t\t||" << endl;
    cout << "=======================================" << endl;
  } else if (kelasKamar == 3) {
    cout << "=======================================" << endl;
    cout << "||\t\t KAMAR KELAS 1 \t\t||" << endl;
    cout << "=======================================" << endl;
  } else if (kelasKamar == 4) {
    cout << "=======================================" << endl;
    cout << "||\t\t KAMAR KELAS 2 \t\t||" << endl;
    cout << "=======================================" << endl;
  }

  cout << "Masukkan nomor kamar: ";
  cin >> nomor;

  cout << "Masukkan harga kamar: ";
  cin >> harga;

  cout << "Apakah kamar kosong? (1 untuk Ya, 0 untuk Tidak): ";
  cin >> kosong;

  KamarPasien *newKamar = new KamarPasien{nomor, harga, kosong};

  if (head == nullptr) {
    head = tail = newKamar;
  } else {
    tail->next = newKamar;
    newKamar->prev = tail;
    tail = newKamar;
  }

  switch (kelasKamar) {
  case 1:
    tulisDataKamar(fileKamarVIP, head);
    break;
  case 2:
    tulisDataKamar(fileKamarVVIP, head);
    break;
  case 3:
    tulisDataKamar(fileKamarKelas1, head);
    break;
  case 4:
    tulisDataKamar(fileKamarKelas2, head);
    break;
  default:
    cout << "Kelas kamar tidak valid." << endl;
    delete newKamar;
    return;
  }

  cout << "Data kamar berhasil ditambahkan." << endl;
}

void Login::datakamarpasien() {
  int pilihan;
  Kamar kamar;

  do {
    cout << "    _  __           __  __            _____     " << endl;
      cout << "   | |/ /    /\\    |  \\/  |    /\\    |  __ \\    " << endl;
      cout << "   | ' /    /  \\   | \\  / |   /  \\   | |__) |   " << endl;
      cout << "   |  <    / /\\ \\  | |\\/| |  / /\\ \\  |  _  /    " << endl;
      cout << "   | . \\  / ____ \\ | |  | | / ____ \\ | | \\ \\    " << endl;
      cout << "   |_|\\_\\/_/    \\_\\|_|__|_|/_/__  \\_\\|_|  \\_\\ _ " << endl;
      cout << "   |  __ \\  /\\     / ____||_   _||  ____|| \\ | |" << endl;
      cout << "   | |__) |/  \\   | (___    | |  | |__   |  \\| |" << endl;
      cout << "   |  ___// /\\ \\   \\___ \\   | |  |  __|  | . ` |" << endl;
      cout << "   | |   / ____ \\  ____) | _| |_ | |____ | |\\  |" << endl;
      cout << "   |_|  /_/    \\_\\|_____/ |_____||______||_| \\_|" << endl;
      cout << "                                                 " << endl;
      cout << "                                                 " << endl;

    cout << "\n=========== Kamar Pasien ===========\n";
    cout << "1. Tampilkan Status Kamar\n";
    cout << "2. Perbarui Data Kamar\n";
    cout << "3. Tambah Data Kamar\n";
    cout << "0. Kembali ke Menu Utama\n";
    cout << "===================================\n";
    cout << "Pilih menu (0-3): ";
    cin >> pilihan;

    switch (pilihan) {
    case 1:
      kamar.tampilDataKamar();
      break;
    case 2:
      kamar.perbaruiDataKamar();
      break;
    case 3:
      kamar.tambahDataKamar();
      break;
    case 0:
      cout << "Kembali ke Menu Utama.\n";
      break;
    default:
      cout << "Pilihan tidak valid. Silakan coba lagi.\n";
    }
  } while (pilihan != 0);

}

#endif