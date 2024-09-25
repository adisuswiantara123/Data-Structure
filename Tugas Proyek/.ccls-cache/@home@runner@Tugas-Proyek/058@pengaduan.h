//circular link list
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Aduan {
    int bagian;
    string aduan;
    Aduan* next;
};

Aduan* tambahAduan(Aduan* tail) {
    Aduan* aduanBaru = new Aduan;
    cout << " /$$$$$$$  /$$$$$$$$ /$$   /$$  /$$$$$$   /$$$$$$  /$$$$$$$  /$$   /$$  /$$$$$$  /$$   /$$" << endl;
    cout << "| $$__  $$| $$_____/| $$$ | $$ /$$__  $$ /$$__  $$| $$__  $$| $$  | $$ /$$__  $$| $$$ | $$" << endl;
    cout << "| $$  \\ $$| $$      | $$$$| $$| $$  \\__/| $$  \\ $$| $$  \\ $$| $$  | $$| $$  \\ $$| $$$$| $$" << endl;
    cout << "| $$$$$$$/| $$$$$   | $$ $$ $$| $$ /$$$$| $$$$$$$$| $$  | $$| $$  | $$| $$$$$$$$| $$ $$ $$" << endl;
    cout << "| $$____/ | $$__/   | $$  $$$$| $$|_  $$| $$__  $$| $$  | $$| $$  | $$| $$__  $$| $$  $$$$" << endl;
    cout << "| $$      | $$      | $$\\  $$$| $$  \\ $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$\\  $$$" << endl;
    cout << "| $$      | $$$$$$$$| $$ \\  $$|  $$$$$$/| $$  | $$| $$$$$$$/|  $$$$$$/| $$  | $$| $$ \\  $$" << endl;
    cout << "|__/      |________/|__/  \\__/ \\______/ |__/  |__/|_______/  \\______/ |__/  |__/|__/  \\__/" << endl;
    cout << "                                                                                          " << endl;
    cout << "                                                                                          " << endl;
    cout << "                                                                                          " << endl;

    cout << "Bagian Mana yang ingin anda lapor?" << endl;
    cout << "1. Pelayanan" << endl;
    cout << "2. Kebersihan" << endl;
    cout << "3. Fasilitas" << endl;
    cout << "4. Poli Jantung" << endl;
    cout << "5. Poli Kulit" << endl;
    cout << "6. Poli anak" << endl;
    cout << "7. Poli Gigi" << endl;
    cout << "8. Poli Penyakit Dalam" << endl;
    cout << "9. Poli Saraf" << endl;
    cout << "10. Labolatorium" << endl;
    cout << "Pilih: ";
    cin >> aduanBaru->bagian;
    cin.ignore();  // Membersihkan buffer keyboard

    string bagianText;
    switch (aduanBaru->bagian) {
        case 1:
            bagianText = "Pelayanan";
            break;
        case 2:
            bagianText = "Kebersihan";
            break;
        case 3:
            bagianText = "Fasilitas";
            break;
        case 4:
            bagianText = "Poli Jantung";
            break;
        case 5:
            bagianText = "Poli Kulit";
            break;
        case 6:
            bagianText = "Poli anak";
            break;
        case 7:
            bagianText = "Poli Gigi";
            break;
        case 8:
            bagianText = "Poli Penyakit Dalam";
            break;
        case 9:
            bagianText = "Poli Saraf";
            break;
        case 10:
            bagianText = "Labolatorium";
            break;
        default:
            bagianText = "Unknown";
    }

    cout << "Pengaduan yang ingin anda laporkan: ";
    getline(cin, aduanBaru->aduan);

    aduanBaru->next = nullptr;
    if (tail == nullptr) {
        aduanBaru->next = aduanBaru;  // Point to itself to form a circular list
    } else {
        aduanBaru->next = tail->next;  
        tail->next = aduanBaru;  
    }
    return aduanBaru;
}

void simpanKeFile(Aduan* head) {
    ofstream file("pengaduan.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Gagal membuka file pengaduan.txt" << endl;
        return;
    }

    Aduan* current = head;
    do {
        string bagianText;
        switch (current->bagian) {
            case 1:
                bagianText = "Pelayanan";
                break;
            case 2:
                bagianText = "Kebersihan";
                break;
            case 3:
                bagianText = "Fasilitas";
                break;
            case 4:
                bagianText = "Poli Jantung";
                break;
            case 5:
                bagianText = "Poli Kulit";
                break;
            case 6:
                bagianText = "Poli anak";
                break;
            case 7:
                bagianText = "Poli Gigi";
                break;
            case 8:
                bagianText = "Poli Penyakit Dalam";
                break;
            case 9:
                bagianText = "Poli Saraf";
                break;
            case 10:
                bagianText = "Labolatorium";
                break;
            default:
                bagianText = "Unknown";
        }

        file << "Bagian: " << bagianText << endl;
        file << "Pengaduan: " << current->aduan << endl;
        file << "----------------------------------------" << endl;
        current = current->next;
    } while (current != head);  

    file.close();
}

void pengaduan () {
    Aduan* head = nullptr;  
    char lanjut;
    do {
        head = tambahAduan(head);

        cout << "Lanjutkan (y/n)? ";
        cin >> lanjut;

        if (lanjut != 'y') {
            break;
        }
    } while (lanjut == 'y');

    simpanKeFile(head);
}