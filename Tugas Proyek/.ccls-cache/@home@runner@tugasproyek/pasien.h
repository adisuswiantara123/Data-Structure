#ifndef PASIEN_H
#define PASIEN_H

#include "053/proses.h"
#include "058/kuisioner.h"
#include "058/pengaduan.h"
#include "058/survey.h"
#include "058/edukasi.h"
#include "058/lingkungan.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <stack>
#include <cstdlib>
#include <algorithm>

using namespace std;

extern const int MAKS_DOKTER = 5;
extern const int MAKS_SLOT = 3;
const int MAX_SIZE = 100;

string dokter[MAKS_DOKTER] = {"Dr. Joni", "Dr. Sarah", "Dr. Agus", "Dr. Bakwan", "Dr. WakWaW"};
string jadwalDokter[MAKS_DOKTER][MAKS_SLOT] = {
    {"Senin 10:00 AM", "Selasa 2:00 PM", "Rabu 11:30 AM"},
    {"Senin 3:00 PM", "Kamis 9:30 AM", "Jumat 1:00 PM"},
    {"Rabu 4:45 PM", "Sabtu 10:35 AM", "Selasa 3:50 PM"},
    {"Kamis 5:30 PM", "Kamis 11:25 AM", "Jumat 1:30 PM"},
    {"Selasa 5:45 PM", "Jumat 9:30 AM", "Rabu 5:15 PM"}
};

struct Janji {
    string dokter;
    string slot;
};

struct PesanDokter {
    string dokter;
    string pesan;
};

struct User {
    string username;
    string password;
    string fullName;
    string birthDate;
    string gender;
    string medicalHistory;
    string bloodType;
    string insurance;
};

extern const int maxUsers;

class PasienManager {
  public:
    void lihatDataPasien();
    void sortAndDisplayByGender(User users[], int userCount, string genderToDisplay);
    void displayGenderMenu();
    void displaySortByBirthDateMenu();
    void sortUsersByBirthDateFromFile();
    void tampilkanJadwalDokter(int indeksDokter);
    void simpanJanjiKeFile();
    void muatJanjiDariFile();
    void lihatJanjiDokterDariFile();
    void ubahJanjiDokter();
    void lihatPesanDokter();
    void muatPesanDokterDariFile();
    void ubahUsername(User users[], int userCount);
    void ubahKataSandi(User users[], int userCount);
    void ubahJenisKelamin(User users[], int userCount);
    void ubahTanggalLahir(User users[], int userCount);
    void hapusAkun(User users[], int& userCount);

    friend void SaveUsersToFile(const User users[], int userCount);

  private:
    int currentUserIndex;
    vector<PesanDokter> pesanDokter;
    vector<Janji> janjiDokter;
};

class AntrianDokter {
private:
    struct Pasien {
        string nama;
        int nomor;
    };

    Pasien antrian[MAX_SIZE];
    int front, rear;

public:
    AntrianDokter() {
        front = 0;
        rear = -1;
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    bool isEmpty() {
        return (front > rear);
    }

    void enqueue(const string& nama, int nomor) {
        if (isFull()) {
            cout << "Antrian penuh, tidak bisa menambahkan nomor.\n";
        } else {
            rear++;
            antrian[rear].nama = nama;
            antrian[rear].nomor = nomor;
            cout << "Nomor " << nomor << " atas nama " << nama << " ditambahkan ke antrian.\n";
        }

        int continueChoice;
                    cout << "\n=================================================" << endl;
                    cout << "Apakah Anda ingin kembali ke Menu Pasien (1/2)?\n";
                    cout << "(1) Untuk Kembali ke Menu Pasien.\n";
                    cout << "(2) Untuk Keluar dari Program.\n";
                    cout << "===================================================" << endl;
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

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong, tidak ada yang bisa dipanggil.\n";
        } else {
            cout << "Nomor " << antrian[front].nomor << " atas nama " << antrian[front].nama << " dipanggil.\n";
            front++;
        }

        int continueChoice;
                    cout << "\n=================================================" << endl;
                    cout << "Apakah Anda ingin kembali ke Menu Pasien (1/2)?\n";
                    cout << "(1) Untuk Kembali ke Menu Pasien.\n";
                    cout << "(2) Untuk Keluar dari Program.\n";
                    cout << "===================================================" << endl;
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

    void clearQueue() {
        front = 0;
        rear = -1;
        cout << "Antrian telah dikosongkan.\n";

        int continueChoice;
                    cout << "\n=================================================" << endl;
                    cout << "Apakah Anda ingin kembali ke Menu Pasien (1/2)?\n";
                    cout << "(1) Untuk Kembali ke Menu Pasien.\n";
                    cout << "(2) Untuk Keluar dari Program.\n";
                    cout << "===================================================" << endl;
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

    void displayQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong.\n";
        } else {
            cout << "\nDaftar Antrian:\n";
            for (int i = front; i <= rear; ++i) {
                cout << antrian[i].nomor << " - " << antrian[i].nama << "\n";
            }
        }

        int continueChoice;
                    cout << "\n=================================================" << endl;
                    cout << "Apakah Anda ingin kembali ke Menu Pasien (1/2)?\n";
                    cout << "(1) Untuk Kembali ke Menu Pasien.\n";
                    cout << "(2) Untuk Keluar dari Program.\n";
                    cout << "===================================================" << endl;
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

    void displayMenu() {
        int pilih, nomor;
        string nama;

        do {
            cout << "=========== Menu Antrian Dokter ===========\n";
            cout << "1. Tambah Antrian\n";
            cout << "2. Panggil Antrian\n";
            cout << "3. Tampilkan daftar Antrian\n";
            cout << "4. Kosongkan Antrian\n";
            cout << "5. Kembali\n";
            cout << "===========================================\n";
            cout << "Pilih: ";
            cin >> pilih;

            switch (pilih) {
                case 1:
                    cout << "Masukkan nama pasien: ";
                    cin.ignore();
                    getline(cin, nama);
                    cout << "Masukkan nomor antrian: ";
                    cin >> nomor;
                    enqueue(nama, nomor);
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    displayQueue();
                    break;
                case 4:
                    clearQueue();
                    break;
                case 5:
                    int continueChoice;
                    cout << "\n=================================================" << endl;
                    cout << "Apakah Anda ingin kembali ke Menu Pasien (1/2)?\n";
                    cout << "(1) Untuk Kembali ke Menu Pasien.\n";
                    cout << "(2) Untuk Keluar dari Program.\n";
                    cout << "===================================================" << endl;
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
                    break;
                default:
                    cout << "Pilihan tidak valid. Coba lagi.\n";
            }
        } while (pilih != 5);
    }
};

void Login::menu_pasien(){
    PasienManager pasienManager;
    AntrianDokter antrianDokter;
    User users[maxUsers];
    int userCount = 0;

    cout << "==========================================================================================================" << endl;
    cout << "   _____ ______ _               __  __       _______    _____       _______       _   _  _____ _ " << endl;
    cout << "  / ____|  ____| |        /\\   |  \\/  |   /\\|__   __|  |  __ \\   /\\|__   __|/\\   | \\ | |/ ____| |" << endl;
    cout << " | (___ | |__  | |       /  \\  | \\  / |  /  \\  | |     | |  | | /  \\  | |  /  \\  |  \\| | |  __| |" << endl;
    cout << "  \\___ \\|  __| | |      / /\\ \\ | |\\/| | / /\\ \\ | |     | |  | |/ /\\ \\ | | / /\\ \\ | . ` | | |_ | |" << endl;
    cout << "  ____) | |____| |____ / ____ \\| |  | |/ ____ \\| |     | |__| / ____ \\| |/ ____ \\| |\\  | |__| |_|" << endl;
    cout << " |_____/|______|______/_/    \\_\\_|  |_/_/    \\_\\_|     |_____/_/    \\_\\_/_/    \\_\\_| \\_|\\_____(_)" << endl;
    cout << "===========================================================================================================" << endl;
    cout << "|================== Menu Pasien ==================|\n";
    cout << "| 1. Lihat Data Pribadi Pasien\t\t\t  |\n";
    cout << "| 2. Tampilkan Akun Berdasarkan\t\t\t  |\n";
    cout << "| 3. Janji Temu dengan Dokter\t\t\t  |\n";
    cout << "| 4. Lihat Pesan Dokter\t\t\t\t  |\n";
    cout << "| 5. Menu Antrian Dokter\t\t\t  |\n";
    cout << "| 6. Pengaturan Akun\t\t\t\t  |\n";
    cout << "| 7. Kuisioner\t\t\t\t\t  |\n";
    cout << "| 8. Pengaduan\t\t\t\t\t  |\n";
    cout << "| 9. Survey\t\t\t\t\t  |\n";
    cout << "| 10. Edukasi\t\t\t\t\t  |\n";
    cout << "| 11. Lihat Pemantauan Lingkungan Rumah Sakit\t  |\n";
    cout << "| 12. Keluar dari Akun\t\t\t\t  |\n";
    cout << "|=================================================|\n";
    cout << "Pilihan Anda: ";

    int pasienchoice;
    cin >> pasienchoice;

    cout << "===================================\n";

    switch (pasienchoice) {

    case 1:
        pasienManager.lihatDataPasien();
        break;

    case 2:
    {
        int sortChoice;
        cout << "===================================\n";
        cout << "|           Menu Sorting:         |\n";
        cout << "===================================\n";
        cout << "1. Sorting Berdasarkan Jenis Kelamin" << endl;
        cout << "2. Sorting Berdasarkan Tanggal Lahir" << endl;
        cout << "===================================\n";
        cout << "Masukkan Pilihan : ";
        cin >> sortChoice;

        switch (sortChoice) {
            case 1:
                {
                    pasienManager.displayGenderMenu();
                    int genderChoice;
                    cin >> genderChoice;

                    string genderToDisplay;
                    if (genderChoice == 1) {
                        genderToDisplay = "Pria";
                    } else if (genderChoice == 2) {
                        genderToDisplay = "Wanita";
                    } else {
                        cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                        break;
                    }

                    pasienManager.sortAndDisplayByGender(users, userCount, genderToDisplay);
                    break;
                }
            case 2:
                pasienManager.displaySortByBirthDateMenu();
                pasienManager.sortUsersByBirthDateFromFile();
                break;
        }
        
    }
    break;
        
    case 3:
        while (true)
        {
            int pilihjadwal;
            cout << "===================================\n";
            cout << "|    Jadwal Janji Temu Dokter:    |\n";
            cout << "===================================\n";
            cout << "1. Buat Janji Temu dengan Dokter\n";
            cout << "2. Tampilkan Jadwal Pertemuan dengan Dokter\n";
            cout << "3. Ubah Jadwal Temu dengan Dokter\n";
            cout << "4. Kembali Ke Menu\n";
            cout << "Pilihan Anda: ";
            cin >> pilihjadwal;

            switch (pilihjadwal)
            {
            case 1:
                int indeksDokter;
                pasienManager.tampilkanJadwalDokter(indeksDokter);
                break;
            case 2:
                pasienManager.lihatJanjiDokterDariFile();
                break;
            case 3:
                pasienManager.ubahJanjiDokter();
                break;
            case 4:
                return Login::menu_pasien();
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
            }
            break; 
        }
        break;

    case 4:
        pasienManager.lihatPesanDokter();
        break;

    case 5:
        antrianDokter.displayMenu();
        break;

    case 6:
        int pengaturan;
        cout << "=================================\n";
        cout << "|  Pilih Opsi Pengaturan Akun:  |\n";
        cout << "=================================\n";
        cout << "| 1. Ubah Username Anda\t\t|\n";
        cout << "| 2. Ubah Kata Sandi Anda\t|\n";
        cout << "| 3. Ubah Jenis Kelamin Anda\t|\n";
        cout << "| 4. Ubah Tanggal Lahir Anda\t|\n";
        cout << "| 5. Hapus Akun Anda\t\t|\n";
        cout << "| 6. Kembali Ke Menu\t\t|\n";
        cout << "=================================\n";
        cout << "Pilihan Anda: ";
        cin >> pengaturan;
        cout << "=================================\n";

    switch (pengaturan)
    {
        case 1:
            cout << "1. Ubah Username Anda\n";
            pasienManager.ubahUsername(users, maxUsers);
            break;
        case 2:
            cout << "1. Ubah Kata Sandi Anda\n";
            pasienManager.ubahKataSandi(users, maxUsers);
            break;
        case 3:
            cout << "1. Ubah Jenis Kelamin Anda\n";
            pasienManager.ubahJenisKelamin(users, maxUsers);
            break;
        case 4:
            cout << "1. Ubah Tanggal Lahir Anda\n";
            pasienManager.ubahTanggalLahir(users, maxUsers);
            break;
        case 5:
            int continueChoice;
            cout << "===========================================================" << endl;
            cout << "Maaf, fitur masih dalam pengembangan!" << endl;
            cout << "Anda dapat menggunakan fitur ini dalam beberapa waktu lagi." << endl;
            cout << "===========================================================" << endl;
            cout << "Silahkan kembali atau keluar dari program\n\n";
            cout << "Untuk kembali ke menu pasien, silahkan ketik 1\n";
            cout << "Untuk keluar dari program, silahkan ketik 2\n";
            cout << "===========================================================" << endl;
            cout << "Masukkan pilihan Anda : ";
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
            break;
        case 6:
            return Login::menu_pasien();
            break;
        default:
            cout << "Pilihan tidak valid. Coba lagi.\n";
        break;
    }
    break;

  case 7:
    kuisoner();
    break;   

  case 8:
    pengaduan();
    break;

  case 9:
    survey();
    break;

  case 10:
    edukasi();
    break;

  case 11:
    lingkungan();
    break;

  case 12:
      return;
      break;
    
  default:
    cout << "Pilihan tidak valid. Coba lagi.\n";
    }
}

void SaveUsersToFile(const User users[], int userCount) {
    ofstream userFile("users.txt", ios::app);

    if (userFile.is_open()) {
        for (int i = 0; i < userCount; i++) {
            userFile << users[i].username << " " << users[i].password << " " << users[i].fullName << " "
                     << users[i].birthDate << " " << users[i].gender << " " << users[i].medicalHistory << " "
                     << users[i].bloodType << " " << users[i].insurance << endl;
        }
        userFile.close();
    } else {
        cout << "Gagal membuka file untuk menyimpan data pengguna." << endl;
    }
}

void PasienManager::lihatDataPasien() {
    ifstream dataPasienFile("data_pasien.txt");

    if (dataPasienFile.is_open()) {
        cout << "===============================================================" << endl;
        cout << "||                        Data Pasien:                       ||" << endl;
        cout << "===============================================================" << endl;
        cout << "|| Nama            | Usia  | Diagnosa         | Jenis Pasien ||" << endl;
        cout << "===============================================================" << endl;

        string line;
        while (getline(dataPasienFile, line)) {
            stringstream ss(line);
            string nama, usia, diagnosa, jenisPasien;
            ss >> nama >> usia >> diagnosa >> jenisPasien;
            cout << "|| " << setw(15) << left << nama << " | " << setw(5) << usia << " | " << setw(16) << diagnosa << " | " << setw(12) << jenisPasien << " ||" << endl;
        }

        cout << "===============================================================" << endl;
        dataPasienFile.close();

        int continueChoice;
        cout << "\n=================================================" << endl;
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
    } else {
        cout << "Gagal membuka file data pasien." << endl;
    }
}

void PasienManager::displayGenderMenu() {
    cout << "Pilih Jenis Kelamin yang Ingin Dilihat:\n";
    cout << "1. Pria\n";
    cout << "2. Wanita\n";
    cout << "Pilihan Anda: ";
}

void PasienManager::sortAndDisplayByGender(User users[], int userCount, string genderToDisplay) {
    ifstream userFile("users.txt");
    if (userFile.is_open()) {
        while (userCount < maxUsers && userFile >> users[userCount].username >> users[userCount].password >> users[userCount].fullName
                     >> users[userCount].birthDate >> users[userCount].gender >> users[userCount].medicalHistory
                     >> users[userCount].bloodType >> users[userCount].insurance) {
            if (users[userCount].gender == genderToDisplay) {
                userCount++;
            }
        }
        userFile.close();
    } else {
        cout << "Gagal membuka file untuk membaca data pengguna." << endl;
        return;
    }

    for (int i = 0; i < userCount - 1; i++) {
        for (int j = 0; j < userCount - i - 1; j++) {
            if (users[j].gender > users[j + 1].gender) {
                swap(users[j], users[j + 1]);
            }
        }
    }

    cout << "Daftar Akun Berdasarkan Jenis Kelamin " << genderToDisplay << ":\n";
    cout << "------------------------------------\n";
    for (int i = 0; i < userCount; ++i) {
        if (users[i].gender == genderToDisplay) {
            cout << "Username: " << users[i].username << "\n";
            cout << "Nama Lengkap: " << users[i].fullName << "\n";
            cout << "Jenis Kelamin: " << users[i].gender << "\n";
            cout << "------------------------------------\n";
        }
    }

    int continueChoice;
        cout << "\n=================================================" << endl;
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

void PasienManager::displaySortByBirthDateMenu() {
    cout << "Pilih Tanggal Lahir yang Ingin Diurutkan (YYYY-MM-DD):\n";
    cout << "Contoh: 2000-01-01\n";
    cout << "Tanggal Lahir: ";
}

void PasienManager::sortUsersByBirthDateFromFile() {
    string chosenDate;
    cout << "Masukkan Tanggal Lahir yang Ingin Diurutkan (YYYY-MM-DD): ";
    cin >> chosenDate;

    ifstream userFile("users.txt");
    if (userFile.is_open()) {
        vector<User> users;
        User tempUser;
        while (userFile >> tempUser.username >> tempUser.password >> tempUser.fullName
                     >> tempUser.birthDate >> tempUser.gender >> tempUser.medicalHistory
                     >> tempUser.bloodType >> tempUser.insurance) {
            users.push_back(tempUser);
        }
        userFile.close();

        vector<User> matchingUsers;
        for (const auto &user : users) {
            if (user.birthDate == chosenDate) {
                matchingUsers.push_back(user);
            }
        }

        sort(matchingUsers.begin(), matchingUsers.end(),
             [](const User &a, const User &b) {
                 return a.birthDate < b.birthDate;
             });

        cout << "Daftar Pengguna dengan Tanggal Lahir " << chosenDate << ":\n";
        cout << "------------------------------------\n";
        for (const auto &user : matchingUsers) {
            cout << "Username: " << user.username << "\n";
            cout << "Nama Lengkap: " << user.fullName << "\n";
            cout << "Tanggal Lahir: " << user.birthDate << "\n";
            cout << "------------------------------------\n";
        }

        int continueChoice;
        cout << "\n=================================================" << endl;
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
    } else {
        cout << "Gagal membuka file untuk membaca data pengguna." << endl;
    }
}

void PasienManager::tampilkanJadwalDokter(int indeksDokter) {
    muatJanjiDariFile();

    for (int i = 0; i < MAKS_DOKTER; i++) {
        cout << i << ": " << dokter[i] << endl;
    }

    cout << "Silakan pilih dokter yang ingin Anda temui (pilih nomor dokter): ";
    int dokterDipilih;
    cin >> dokterDipilih;

    if (dokterDipilih >= 0 && dokterDipilih < MAKS_DOKTER) {
        cout << "Jadwal Dokter: " << dokter[dokterDipilih] << endl;
        cout << "Waktu yang Tersedia:" << endl;

        for (int i = 0; i < MAKS_SLOT; i++) {
            cout << "- " << jadwalDokter[dokterDipilih][i] << endl;
        }

        cout << "Silakan pilih waktu janji (contoh: 'Senin 10:00 AM'): ";
        string slotDipilih;
        cin.ignore();
        getline(cin, slotDipilih);

        bool slotValid = false;
        for (int i = 0; i < MAKS_SLOT; i++) {
            if (jadwalDokter[dokterDipilih][i] == slotDipilih) {
                slotValid = true;
                break;
            }
        }

        if (slotValid) {
            Janji janji;
            janji.dokter = dokter[dokterDipilih];
            janji.slot = slotDipilih;
            janjiDokter.push_back(janji);

            simpanJanjiKeFile();

            cout << "Janji Anda dengan " << dokter[dokterDipilih] << " pada " << slotDipilih << " berhasil terdaftar." << endl << endl;

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
            
        } else {
            cout << "Waktu janji tidak valid atau tidak tersedia." << endl;
        }
    } else {
        cout << "Dokter tidak ditemukan." << endl;
    }
}

void PasienManager::ubahJanjiDokter() {
    muatJanjiDariFile();

    cout << "Selamat datang di Sistem Perubahan Janji Dokter" << endl;
    cout << "Berikut adalah janji-janji yang sudah terdaftar:" << endl;

    for (size_t i = 0; i < janjiDokter.size(); i++) {
        cout << i + 1 << ". Dokter: " << janjiDokter[i].dokter << ", Slot: " << janjiDokter[i].slot << endl;
    }

    cout << "Silakan pilih nomor janji yang ingin Anda ubah: ";
    int nomorJanji;
    cin >> nomorJanji;

    if (nomorJanji > 0 && nomorJanji <= janjiDokter.size()) {
        cout << "Silakan pilih dokter baru (contoh: 'Dr. John'): ";
        string dokterBaru;
        cin.ignore();
        getline(cin, dokterBaru);

        cout << "Silakan pilih slot waktu baru (contoh: 'Senin 10:00 AM'): ";
        string slotBaru;
        getline(cin, slotBaru);

        janjiDokter[nomorJanji - 1].dokter = dokterBaru;
        janjiDokter[nomorJanji - 1].slot = slotBaru;

        simpanJanjiKeFile();

        int continueChoice;
        cout << "\n=================================================" << endl;
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

        cout << "Janji dokter berhasil diubah." << endl;
    } else {
        cout << "Nomor janji tidak valid." << endl;
    }
}

void PasienManager::lihatPesanDokter() {
    muatPesanDokterDariFile();

    cout << "Pesan dari Dokter:" << endl;

    if (pesanDokter.empty()) {
        cout << "Dokter belum memberikan pesan apapun!" << endl;
    } else {
        for (const PesanDokter &pesan : pesanDokter) {
            for (int i = 0; i < MAKS_DOKTER; i++) {
                if (pesan.dokter == dokter[i]) {
                    cout << "Dokter: " << pesan.dokter << endl;
                    cout << "Pesan: " << pesan.pesan << endl;
                }
            }
        }
    }

    int continueChoice;
        cout << "\n=================================================" << endl;
        cout << " Apakah Anda ingin kembali ke Menu Pasien (1/2)?\n";
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

void PasienManager::muatPesanDokterDariFile() {
    ifstream file("pesan_dokter.txt");

    if (file.is_open()) {
        string line;
        pesanDokter.clear();

        while (getline(file, line)) {
            size_t pos = line.find(",");
            if (pos != string::npos) {
                PesanDokter pesan;
                pesan.dokter = line.substr(0, pos);
                pesan.pesan = line.substr(pos + 1);
                pesanDokter.push_back(pesan);
            }
        }

        file.close();
    } else {
        cout << "Gagal membuka file pesan dokter." << endl;
    }
}

void PasienManager::simpanJanjiKeFile() {
    ofstream file("janji.txt");
    if (file.is_open()) {
        for (const Janji &janji : janjiDokter) {
            file << janji.dokter << "," << janji.slot << endl;
        }
        file.close();
    } else {
        cout << "Gagal membuka file untuk menyimpan janji." << endl;
    }
}

void PasienManager::muatJanjiDariFile() {
    ifstream file("janji.txt");
    if (file.is_open()) {
        string baris;
        while (getline(file, baris)) {
            size_t pos = baris.find(",");
            if (pos != string::npos) {
                Janji janji;
                janji.dokter = baris.substr(0, pos);
                janji.slot = baris.substr(pos + 1);
                janjiDokter.push_back(janji);
            }
        }
        file.close();
    }
}

void PasienManager::lihatJanjiDokterDariFile() {
    ifstream file("janji.txt");

    if (file.is_open()) {
        string line;
        cout << "Janji Dokter:" << endl;

        while (getline(file, line)) {
            size_t pos = line.find(",");

            if (pos != string::npos) {
                string dokter = line.substr(0, pos);
                string slot = line.substr(pos + 1);
                cout << "Dokter: " << dokter << ", Slot: " << slot << endl;
            }
        }

        int continueChoice;
        cout << "\n=================================================" << endl;
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

        file.close();
    } else {
        cout << "Gagal membuka file janji." << endl;
    }
}

void PasienManager::ubahUsername(User users[], int userCount) {
    string newUsername;
    cout << "Masukkan username baru: ";
    cin >> newUsername;
    cin.ignore();

    if (currentUserIndex == 0) {
        users[currentUserIndex].username = newUsername;
        SaveUsersToFile(users, maxUsers);

        cout << "Kata sandi berhasil diubah." << endl;
        int continueChoice;
        cout << "\n=================================================" << endl;
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
    } else {
        cout << "Anda harus masuk terlebih dahulu untuk mengubah username." << endl;
    }
}

void PasienManager::ubahKataSandi(User users[], int userCount) {
    if (currentUserIndex >= 0) {
        string newPassword;
        cout << "Masukkan kata sandi baru: ";
        cin >> newPassword;
        cin.ignore();

        users[currentUserIndex].password = newPassword;
        SaveUsersToFile(users, maxUsers);

        cout << "Kata sandi berhasil diubah." << endl;

        int continueChoice;
        cout << "\n=================================================" << endl;
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
    } else {
        cout << "Anda harus masuk terlebih dahulu untuk mengubah kata sandi." << endl;
    }
}

void PasienManager::ubahJenisKelamin(User users[], int userCount) {
    string newGender;
    cout << "Masukkan jenis kelamin baru: ";
    cin >> newGender;
    cin.ignore();

    if (currentUserIndex == 0) {
        users[currentUserIndex].gender = newGender;
        SaveUsersToFile(users, maxUsers);

        cout << "Jenis Kelamin berhasil diubah." << endl;

        int continueChoice;
        cout << "\n=================================================" << endl;
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
    } else {
        cout << "Anda harus masuk terlebih dahulu untuk mengubah jenis kelamin." << endl;
    }
}

void PasienManager::ubahTanggalLahir(User users[], int userCount) {
    string newBirthDate;
    cout << "Masukkan tanggal lahir baru: ";
    cin >> newBirthDate;
    cin.ignore();

    if (currentUserIndex == 0) {
        users[currentUserIndex].birthDate = newBirthDate;
        SaveUsersToFile(users, maxUsers);

        cout << "Tanggal Lahir berhasil diubah." << endl;

        int continueChoice;
        cout << "\n=================================================" << endl;
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
    } else {
        cout << "Anda harus masuk terlebih dahulu untuk mengubah tanggal lahir." << endl;
    }
}

void PasienManager::hapusAkun(User users[], int& userCount) {
    string usernameToDelete;
    cout << "Masukkan username akun yang ingin dihapus: ";
    cin >> usernameToDelete;

    int indexToDelete = -1;
    for (int i = 0; i < userCount; ++i) {
        if (users[i].username == usernameToDelete) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete != -1) {
        for (int i = indexToDelete; i < userCount - 1; ++i) {
            users[i] = users[i + 1];
        }
        userCount--;

        SaveUsersToFile(users, userCount);

        cout << "Akun dengan username '" << usernameToDelete << "' berhasil dihapus.\n";

        int continueChoice;
        cout << "\n=================================================" << endl;
        cout << "Apakah Anda ingin kembali ke Menu Pasien (1/2)?\n";
        cout << "(1) Untuk Kembali ke Menu Pasien.\n";
        cout << "(2) Untuk Keluar dari Program.\n";
        cout << "=================================================" << endl;
        cout << "Masukkan Pilihan Anda : ";
        cin >> continueChoice;

        switch (continueChoice) {
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
    } else {
        cout << "Akun dengan username '" << usernameToDelete << "' tidak ditemukan.\n";
    }
}

#endif