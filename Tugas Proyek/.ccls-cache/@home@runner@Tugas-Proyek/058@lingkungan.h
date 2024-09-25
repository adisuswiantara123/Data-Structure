#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "../053/proses.h"

using namespace std;

// Definisi simpul pohon untuk parameter lingkungan
struct EnvironmentalNode {
    string location;
    double temperature;
    double humidity;
    double airQuality;
    string airQualityStatus;
    vector<EnvironmentalNode*> children; // Simpul anak

    // Konstruktor untuk membuat simpul baru
    EnvironmentalNode(string loc, double temp, double hum, double airQ)
        : location(loc), temperature(temp), humidity(hum), airQuality(airQ) {
            // Menentukan status kualitas udara
            airQualityStatus = (airQuality <= 0.5) ? "Baik" : "Tidak Baik";
        }

    // Fungsi untuk menambahkan simpul anak
    void addChild(string loc, double temp, double hum, double airQ) {
        children.push_back(new EnvironmentalNode(loc, temp, hum, airQ));
    }

    // Fungsi untuk membersihkan memori dengan melepaskan simpul anak
    ~EnvironmentalNode() {
        for (const auto& child : children) {
            delete child;
        }
    }
};
void gambar();
// Fungsi rekursif untuk menampilkan pohon dengan tampilan tabel dan garis pemisah
void displayEnvironmentTree(EnvironmentalNode* node, int depth, ostream& outStream);
void displayEnvironmentInfo(EnvironmentalNode* node, ostream& outStream);

void lingkungan() {
    gambar();
    // Membuat pohon lingkungan rumah sakit
    EnvironmentalNode* environmentTree = new EnvironmentalNode("Luar Rumah Sakit", 33, 53, 0.8);

    // Menambahkan cabang pohon untuk luar rumah sakit
    environmentTree->addChild("Parkiran", 32, 50, 0.8);
    environmentTree->addChild("Kantin", 30, 55, 0.8);

    // Menambahkan cabang pohon untuk dalam rumah sakit
    EnvironmentalNode* dalamRumahSakitNode = new EnvironmentalNode("Dalam Rumah Sakit", 30, 55, 0.5);
    dalamRumahSakitNode->addChild("Ruang Tunggu", 31, 60, 0.6);
    dalamRumahSakitNode->addChild("Apotek", 29, 55, 0.3);
    dalamRumahSakitNode->addChild("Poli Jiwa", 29, 58, 0.4);
    dalamRumahSakitNode->addChild("Poli Gigi", 31, 50, 0.4);
    dalamRumahSakitNode->addChild("Poli Anak", 28, 65, 0.5);
    dalamRumahSakitNode->addChild("Poli Kulit", 30, 52, 0.1);
    dalamRumahSakitNode->addChild("Poli Jantung", 31, 55, 0.3);
    dalamRumahSakitNode->addChild("Poli Saraf", 30, 56, 0.4);
    dalamRumahSakitNode->addChild("Poli Dalam", 30, 60, 0.3);
    dalamRumahSakitNode->addChild("Poli Mata", 31, 58, 0.4);

    // Menyambungkan pohon dalam rumah sakit ke pohon utama
    environmentTree->children.push_back(dalamRumahSakitNode);

    int choice;
    cout << "Pemantauan Lingkungan Rumah Sakit:" << endl;
    cout << "1. Tampilkan semua tempat" << endl;
    cout << "2. Tampilkan tempat tertentu" << endl;
    cout << "Pilih opsi (1/2): ";
    cin >> choice;

  ofstream outFile("lingkungan.txt", ios::app);

    switch (choice) {
        case 1:
            // Menampilkan semua tempat ke konsol dan file
            displayEnvironmentTree(environmentTree, 0, cout);
            displayEnvironmentTree(environmentTree, 0, outFile);
            break;
        case 2: {
            // Menampilkan tempat tertentu ke konsol dan file
            int locationChoice;
            cout << "Pilih tempat berdasarkan angka berikut:" << endl;
            cout << "1. Luar Rumah Sakit" << endl;
            cout << "2. Dalam Rumah Sakit" << endl;
            cout << "Pilih opsi (1/2): ";
            cin >> locationChoice;

            if (locationChoice == 1) {
                cout << "Pilih tempat di Luar Rumah Sakit:" << endl;
                cout << "1. Parkiran" << endl;
                cout << "2. Kantin" << endl;
                cout << "Pilih tempat (1-2): ";
                cin >> locationChoice;

                if (locationChoice == 1 || locationChoice == 2) {
                    // Menampilkan informasi di tempat yang dipilih dari anak-anak "Luar Rumah Sakit"
                    displayEnvironmentInfo(environmentTree->children[locationChoice - 1], cout);
                    displayEnvironmentInfo(environmentTree->children[locationChoice - 1], outFile);
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }
            } else if (locationChoice == 2) {
                cout << "Pilih tempat di Dalam Rumah Sakit:" << endl;
                for (int i = 0; i < dalamRumahSakitNode->children.size(); ++i) {
                    cout << i + 1 << ". " << dalamRumahSakitNode->children[i]->location << endl;
                }
                cout << "Pilih tempat (1-" << dalamRumahSakitNode->children.size() << "): ";
                cin >> locationChoice;

                if (locationChoice >= 1 && locationChoice <= dalamRumahSakitNode->children.size()) {
                    // Menampilkan informasi di tempat yang dipilih dari anak-anak "Dalam Rumah Sakit"
                    displayEnvironmentInfo(dalamRumahSakitNode->children[locationChoice - 1], cout);
                    displayEnvironmentInfo(dalamRumahSakitNode->children[locationChoice - 1], outFile);
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }
            } else {
                cout << "Pilihan tidak valid." << endl;
            }
            break;
        }
        default:
            cout << "Pilihan tidak valid." << endl;
    }

    // Menutup file
    outFile.close();

    // Membersihkan memori dengan melepaskan simpul pohon
    delete environmentTree;

  int continueChoice;
  cout << "=================================================" << endl;
  cout << "Apakah Anda ingin kembali ke Menu Pasien (1/2)?\n";
  cout << "(1) Untuk Kembali ke Menu Pasien.\n";
  cout << "(2) Untuk Keluar dari Program.\n";
  cout << "=================================================" << endl;
  cout << "Masukkan Pilihan Anda : ";
  cin >> continueChoice;

  switch (continueChoice)
  {
  case 1:
      Login login;
      login.menu_pasien();
      break;
  case 2:
      exit(0);
      break;
  default:
      cout << "\nPilihan tidak valid!";
      break;
  }
    
}

// Fungsi rekursif untuk menampilkan pohon dengan tampilan tabel dan garis pemisah
void displayEnvironmentTree(EnvironmentalNode* node, int depth, ostream& outStream) {
    if (node == nullptr) {
        return;
    }

    // Tampilkan header tabel
    if (depth == 0) {
        outStream << left << setw(20) << "Lokasi" << "|" << setw(10) << "Suhu (C)" << "|" << setw(15) << "Kelembapan (%)" << "|" << setw(20) << "Kualitas Udara" << endl;
        outStream << setfill('-') << setw(60) << "" << setfill(' ') << endl; // Garis pemisah
    }

    // Tampilkan data lokasi
    outStream << left << setw(20) << node->location << "|" << setw(10) << node->temperature << "|" << setw(15) << node->humidity << "|" << setw(20) << node->airQuality << " (" << node->airQualityStatus << ")" << endl;

    // Tampilkan anak-anaknya
    for (const auto& child : node->children) {
        displayEnvironmentTree(child, depth + 1, outStream);
    }

    // Tampilkan baris kosong antar tempat
    if (depth == 0 && !node->children.empty()) {
        outStream << endl;
    }
}

// Fungsi untuk menampilkan informasi lingkungan tempat tertentu
void displayEnvironmentInfo(EnvironmentalNode* node, ostream& outStream) {
    outStream << "Informasi Lingkungan di " << node->location << ":" << endl;
    outStream << "Suhu: " << node->temperature << " C" << endl;
    outStream << "Kelembapan: " << node->humidity << " %" << endl;
    outStream << "Kualitas Udara: " << node->airQuality << " (" << node->airQualityStatus << ")" << endl;
}


void gambar(){
  cout << "   /$$       /$$$$$$ /$$   /$$  /$$$$$$  /$$   /$$ /$$   /$$ /$$   /$$  /$$$$$$   /$$$$$$  /$$   /$$         " << endl;
  cout << "  | $$      |_  $$_/| $$$ | $$ /$$__  $$| $$  /$$/| $$  | $$| $$$ | $$ /$$__  $$ /$$__  $$| $$$ | $$         " << endl;
  cout << "  | $$        | $$  | $$$$| $$| $$  \\__/| $$ /$$/ | $$  | $$| $$$$| $$| $$  \\__/| $$  \\ $$| $$$$| $$         " << endl;
  cout << "  | $$        | $$  | $$ $$ $$| $$ /$$$$| $$$$$/  | $$  | $$| $$ $$ $$| $$ /$$$$| $$$$$$$$| $$ $$ $$         " << endl;
  cout << "  | $$        | $$  | $$  $$$$| $$|_  $$| $$  $$  | $$  | $$| $$  $$$$| $$|_  $$| $$__  $$| $$  $$$$         " << endl;
  cout << "  | $$        | $$  | $$\\  $$$| $$  \\ $$| $$\\  $$ | $$  | $$| $$\\  $$$| $$  \\ $$| $$  | $$| $$\\  $$$         " << endl;
  cout << "  | $$$$$$$$ /$$$$$$| $$ \\  $$|  $$$$$$/| $$ \\  $$|  $$$$$$/| $$ \\  $$|  $$$$$$/| $$  | $$| $$ \\  $$         " << endl;
  cout << "  |________/|______/|__/  \\__/ \\______/ |__/  \\__/ \\______/ |__/  \\__/ \\______/ |__/  |__/|__/  \\__/         " << endl;
  cout << "   /$$$$$$$  /$$   /$$ /$$      /$$  /$$$$$$  /$$   /$$        /$$$$$$   /$$$$$$  /$$   /$$ /$$$$$$ /$$$$$$$$" << endl;
  cout << "  | $$__  $$| $$  | $$| $$$    /$$$ /$$__  $$| $$  | $$       /$$__  $$ /$$__  $$| $$  /$$/|_  $$_/|__  $$__/" << endl;
  cout << "  | $$  \\ $$| $$  | $$| $$$$  /$$$$| $$  \\ $$| $$  | $$      | $$  \\__/| $$  \\ $$| $$ /$$/   | $$     | $$   " << endl;
  cout << "  | $$$$$$$/| $$  | $$| $$ $$/$$ $$| $$$$$$$$| $$$$$$$$      |  $$$$$$ | $$$$$$$$| $$$$$/    | $$     | $$   " << endl;
  cout << "  | $$__  $$| $$  | $$| $$  $$$| $$| $$__  $$| $$__  $$       \\____  $$| $$__  $$| $$  $$    | $$     | $$   " << endl;
  cout << "  | $$  \\ $$| $$  | $$| $$\\  $ | $$| $$  | $$| $$  | $$      /$$  \\ $$| $$  | $$| $$\\  $$   | $$     | $$   " << endl;
  cout << "  | $$  | $$|  $$$$$$/| $$ \\/  | $$| $$  | $$| $$  | $$     |  $$$$$$/| $$  | $$| $$ \\  $$ /$$$$$$   | $$   " << endl;
  cout << "  |__/  |__/ \\______/ |__/     |__/|__/  |__/|__/  |__/      \\______/ |__/  |__/|__/  \\__/|______/   |__/   " << endl;
  cout << "                                                                                                              " << endl;
  cout << "                                                                                                              " << endl;
  cout << "                                                                                                              " << endl;
}