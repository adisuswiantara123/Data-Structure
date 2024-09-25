#include "053/proses.h"
#include "051/pasien.h"
#include "053/admin.h"
#include "053/dokter.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std; 

const int maxUsers = 100; 

void Register(User users[], int& userCount) {
    if (userCount < maxUsers) {
        User newUser;
        cout << "==========================================================================================" << endl;
        cout << "  _____               _        __ _                                   _                " << endl;
        cout << " |  __ \\             | |      / _| |                            /\\   | |               " << endl;
        cout << " | |__) |__ _ __   __| | __ _| |_| |_ __ _ _ __ __ _ _ __      /  \\  | | ___   _ _ __  " << endl;
        cout << " |  ___/ _ \\ '_ \\ / _` |/ _` |  _| __/ _` | '__/ _` | '_ \\    / /\\ \\ | |/ / | | | '_ \\ " << endl;
        cout << " | |  |  __/ | | | (_| | (_| | | | || (_| | | | (_| | | | |  / ____ \\|   <| |_| | | | |" << endl;
        cout << " |_|   \\___|_| |_|\\__,_|\\__,_|_|  \\__\\__,_|_|  \\__,_|_| |_| /_/    \\_\\_|\\_\\__,_|_| |_|" << endl;
        cout << "=========================================================================================" << endl << endl;
        cout << "\t\t\t\tSilahkan isi Biodata!" << endl;
        cout << "Username: ";
        cin >> newUser.username;
        cout << "Password: ";
        cin >> newUser.password;
        cout << "Nama Lengkap: ";
        cin.ignore();
        getline(cin, newUser.fullName);
        cout << "Tanggal Lahir (YYYY-MM-DD) : ";
        cin >> newUser.birthDate;

        cout << "Jenis Kelamin : " << endl;
        cout << "1. Pria" << endl;
        cout << "2. Wanita" << endl;

        int kelaminChoice;
        cout << "Pilih Jenis Kelamin (1/2): " << endl;
        cin >> kelaminChoice;
        cin.ignore();

        switch (kelaminChoice) {
            case 1:
                newUser.gender = "Pria";
                break;
            case 2:
                newUser.gender = "Wanita";
                break;
            default:
                cout << "Pilihan kelamin tidak valid." << endl;
                break;
        }

        cout << "Riwayat Penyakit: " << endl;
        cout << "1. Tidak Ada." << endl;
        cout << "2. Penyakit Ringan." << endl;
        cout << "3. Penyakit Alergi." << endl;
        cout << "4. Penyakit Kronis." << endl; 

        int penyakitChoice;
        cout << "Pilih Jenis Penyakit : ";
        cin >> penyakitChoice;
        cin.ignore();

        switch (penyakitChoice) {
            case 1:
                newUser.medicalHistory = "-";
                break;
            case 2:
                cout << "Masukkan Riwayat Penyakit Ringan : ";
                getline(cin, newUser.medicalHistory);
                break;
            case 3:
                cout << "Masukkan Riwayat Penyakit Alergi : ";
                getline(cin, newUser.medicalHistory);
                break;
            case 4:
                cout << "Masukkan Riwayat Penyakit Kronis : ";
                getline(cin, newUser.medicalHistory);
                break;
            default:
                cout << "Pilihan kelamin tidak valid." << endl;
                break;
        }

        cout << "Golongan Darah: ";
        cin >> newUser.bloodType;

        cout << "Asuransi (Pilih jenis asuransi):" << endl;
        cout << "1. BPJS" << endl;
        cout << "2. Non-BPJS" << endl;
        cout << "3. Asuransi Lainnya" << endl;

        int insuranceChoice;
        cout << "Pilih jenis asuransi (1/2/3): ";
        cin >> insuranceChoice;
        cin.ignore();

        switch (insuranceChoice) {
            case 1:
                newUser.insurance = "BPJS";
                break;
            case 2:
                newUser.insurance = "Non-BPJS";
                break;
            case 3:
                cout << "Masukkan jenis asuransi lainnya: ";
                getline(cin, newUser.insurance);
                break;
            default:
                cout << "Pilihan asuransi tidak valid. Menggunakan asuransi default." << endl;
                newUser.insurance = "Non-BPJS";
                break;
        }

        users[userCount] = newUser;
        userCount++;

        SaveUsersToFile(users, userCount);

        cout << "Akun berhasil didaftarkan. Kembali ke Menu.\n";
    } else {
        cout << "Batas maksimal pengguna telah tercapai. Tidak dapat mendaftar akun baru.\n";
    }
}

int LoginUser(User users[], int userCount) {
    string username;
    string password;
    cin.ignore();
    cout << "==========================================================================" << endl;
    cout << "  _    _       _                               _                 _       " << endl;
    cout << " | |  | |     | |                             | |               (_)      " << endl;
    cout << " | |__| | __ _| | __ _ _ __ ___   __ _ _ __   | |     ___   __ _ _ _ __  " << endl;
    cout << " |  __  |/ _` | |/ _` | '_ ` _ \\ / _` | '_ \\  | |    / _ \\ / _` | | '_ \\ " << endl;
    cout << " | |  | | (_| | | (_| | | | | | | (_| | | | | | |___| (_) | (_| | | | | |" << endl;
    cout << " |_|  |_|\\__,_|_|\\__,_|_| |_| |_|\\__,_|_| |_| |______\\___/ \\__, |_|_| |_|" << endl;
    cout << "                                                          __/ |          " << endl;
    cout << "                                                         |___/           " << endl;
    cout << "==========================================================================" << endl << endl;
    cout << "\t\tSilahkan login terlebih dahulu!" << endl;
    cout << "Username: ";
    getline(cin , username);
    cout << "Password: ";
    getline(cin , password);

    for (int i = 0; i < userCount; i++) {
        if (users[i].username == username && users[i].password == password) {
            if (users[i].username == "admin" && users[i].password == "admin123") {
                cout << "Login berhasil. Selamat datang, admin." << endl;
                return 1;
            } else {
                cout << "Login berhasil. Selamat datang, " << users[i].fullName << "!" << endl;
                return 2;
            }
        }
    }
    cout << "Akun tidak ditemukan atau password salah. Login gagal." << endl;
    return 3;
}


void SaveUsersToFile(User users[], int userCount) {
    ofstream userFile("users.txt");

    if (userFile.is_open()) {
        for (int i = 0; i < userCount; i++) {
            userFile << users[i].username << " "
                     << users[i].password << " "
                     << users[i].fullName << " "
                     << users[i].birthDate << " "
                     << users[i].gender << " "
                     << users[i].medicalHistory << " "
                     << users[i].bloodType << " "
                     << users[i].insurance << endl;
        }
        userFile.close();
        cout << "Data pengguna berhasil disimpan ke users.txt.\n";
    } else {
        cout << "Gagal membuka file untuk menyimpan data pengguna.\n";
    }
}

void LoadUsersFromFile(User users[], int& userCount) {
    ifstream userFile("users.txt");

    if (userFile.is_open()) {
        while (userCount < maxUsers && userFile >> users[userCount].username >> users[userCount].password >> users[userCount].fullName
                     >> users[userCount].birthDate >> users[userCount].gender >> users[userCount].medicalHistory
                     >> users[userCount].bloodType >> users[userCount].insurance) {
            userCount++;
        }
        userFile.close();
    } else {
        cout << "Gagal membuka file untuk membaca data pengguna." << endl;
    }
}

int main() {
  User users[maxUsers];
  int userCount = 0;
  int choice;
  Login newpasien;

  LoadUsersFromFile(users, userCount);

    do {
        cout << setw(73) << "SELAMAT DATANG DI" << endl << endl;
        cout << "$$$$$$$\\  $$\\   $$\\ $$\\      $$\\  $$$$$$\\  $$\\   $$\\        $$$$$$\\   $$$$$$\\  $$\\   $$\\ $$$$$$\\ $$$$$$$$\\       $$\\   $$\\  $$$$$$\\  $$$$$$$\\ " << endl;
        cout << "$$  __$$\\ $$ |  $$ |$$$\\    $$$ |$$  __$$\\ $$ |  $$ |      $$  __$$\\ $$  __$$\\ $$ | $$  |\\_$$  _|\\__$$  __|      $$ |  $$ |$$  __$$\\ $$  __$$\\ " << endl;
        cout << "$$ |  $$ |$$ |  $$ |$$$$\\  $$$$ |$$ /  $$ |$$ |  $$ |      $$ /  \\__|$$ /  $$ |$$ |$$  /   $$ |     $$ |         $$ |  $$ |$$ /  $$ |$$ |  $$ |" << endl;
        cout << "$$$$$$$\\ |$$ |  $$ |$$\\$$\\$$ $$ |$$$$$$$$ |$$$$$$$$ |      \\$$$$$$\\  $$$$$$$$ |$$$$$  /    $$ |     $$ |         $$ |  $$ |$$$$$$$$ |$$ |  $$ |" << endl;
        cout << "$$  __$$\\ $$ |  $$ |$$ \\$$$  $$ |$$  __$$ |$$  __$$ |       \\____$$\\ $$  __$$ |$$  $$<     $$ |     $$ |         $$ |  $$ |$$  __$$ |$$ |  $$ |" << endl;
        cout << "$$ |  $$ |$$ |  $$ |$$ |\\$  /$$ |$$ |  $$ |$$ |  $$ |      $$\\   $$ |$$ |  $$ |$$ |\\$$\\    $$ |     $$ |         $$ |  $$ |$$ |  $$ |$$ |  $$ |" << endl;
        cout << "$$ |  $$ |\\$$$$$$  |$$ | \\_/ $$ |$$ |  $$ |$$ |  $$ |      \\$$$$$$  |$$ |  $$ |$$ |  $$ |$$$$$$\\    $$ |         \\$$$$$$  |$$ |  $$ |$$$$$$$  |" << endl;
        cout << "\\__|  \\__| \\______/ \\__|     \\__|\\__|  \\__|\\__|  \\__|       \\______/ \\__|  \\__|\\__|  \\__|\\______|   \\__|          \\______/ \\__|  \\__|\\_______/ " << endl << endl;
        cout << setw(81) << "|===== Manajemen Pasien =====|\n";
        cout << setw(68) << "| 1. Register Akun" << setw(13) << "|\n";
        cout << setw(60) << "| 2. Login" << setw(21) << "|\n";
        cout << setw(61) << "| 3. Keluar" << setw(20) << "|\n";
        cout << setw(81) << "|============================|\n";
        cout << setw(66) << "Pilihan Anda: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                Register(users, userCount);
                SaveUsersToFile(users, userCount);
                break;
            case 2: {
                int loginResult = LoginUser(users, userCount);
                switch (loginResult) {
                    case 1:
                        newpasien.menuUtama();
                        break;
                    case 2:
                        newpasien.menu_pasien();
                        break;
                }
                break; 
            }
            break;
            case 3:
                cout << "Terima kasih. Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (choice != 3);
    return 0;
}