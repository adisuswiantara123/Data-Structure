//link list
#ifndef KUISIONER_H
#define KUISIONER_H

#include <fstream>
#include <iostream>
#include "../053/proses.h"

using namespace std;

// Struktur data untuk node linked list
struct KuisionerNode {
  string nama;
  int usia;
  int kepuasan;
  KuisionerNode *next;
};

// Fungsi untuk menampilkan pertanyaan dan mengambil jawaban
int tanyakanPertanyaan(const string &pertanyaan) {
  int jawaban;
  cout << pertanyaan;
  cin >> jawaban;
  return jawaban;
}

// Fungsi untuk menambahkan data kuisioner ke linked list
void tambahkanKuisioner(KuisionerNode *&head) {
  KuisionerNode *newNode = new KuisionerNode;

  cout << "   __    __  __    __  ______   ______   ______   ______   __    __  ________  _______" << endl;
  cout << "  /  |  /  |/  |  /  |/      | /      \\ /      | /      \\ /  \\  /  |/        |/       \\" << endl;
  cout << "  $$ | /$$/ $$ |  $$ |$$$$$$/ /$$$$$$  |$$$$$$/ /$$$$$$  |$$  \\ $$ |$$$$$$$$/ $$$$$$$  |" << endl;
  cout << "  $$ |/$$/  $$ |  $$ |  $$ |  $$ \\__$$/   $$ |  $$ |  $$ |$$$  \\$$ |$$ |__    $$ |__$$ |" << endl;
  cout << "  $$  $$<   $$ |  $$ |  $$ |  $$      \\   $$ |  $$ |  $$ |$$$$  $$ |$$    |   $$    $$<" << endl;
  cout << "  $$$$$  \\  $$ |  $$ |  $$ |   $$$$$$  |  $$ |  $$ |  $$ |$$ $$ $$ |$$$$$/    $$$$$$$  |" << endl;
  cout << "  $$ |$$  \\ $$ \\__$$ | _$$ |_ /  \\__$$ | _$$ |_ $$ \\__$$ |$$ |$$$$ |$$ |_____ $$ |  $$ |" << endl;
  cout << "  $$ | $$  |$$    $$/ / $$   |$$    $$/ / $$   |$$    $$/ $$ | $$$ |$$       |$$ |  $$ |" << endl;
  cout << "  $$/   $$/  $$$$$$/  $$$$$$/  $$$$$$/  $$$$$$/  $$$$$$/  $$/   $$/ $$$$$$$$/ $$/   $$/ " << endl;
  cout << "                                                                                       " << endl;
  cout << "                                                                                       " << endl;

  cout << "                                                      .:---::..                 " << endl;
  cout << "                                                   :=+**++++----:               " << endl;
  cout << "                                                 :##+===**-=+=----:             " << endl;
  cout << "                                                .#*::.::-=+==+++===-            " << endl;
  cout << "                                               .*#:.....::-+*###+++=.           " << endl;
  cout << "                                              .*%==-....::-+#%%##+*=-           " << endl;
  cout << "                                             :*#---+::-==-=*#%%##*+-           " << endl;
  cout << "                                            :+#=..:::---=*+*%%###**+:           " << endl;
  cout << "                                           :+**+--::--:.::-*%####**+:           " << endl;
  cout << "                                           -+#*#:-:--=-::-+#%##*##*+:           " << endl;
  cout << "                                           -#%%#-::::----=*%%%#**###+           " << endl;
  cout << "                                          ..=*%%*::::--=+*#%@%%#*###+           " << endl;
  cout << "                                           .-+#%@%#+=+++***###%###*=#=          " << endl;
  cout << "                                         ...=*%%%%%=-----==*=#%@%###%=          " << endl;
  cout << "                                         . =####*%*-::::----=%@%#*+=-           " << endl;
  cout << "  .        ..                          ..=+#%%#*#*=-::::-:-++#%#*+:.......      " << endl;
  cout << "     ...............                 ..=+*#%%*++*=----:::-+::-++*-.......::.    " << endl;
  cout << "          .::::---::..              ..::==--:.-:--::::::.:-...:-=-....::...::   " << endl;
  cout << "                 .::.:.              .-:.::...-.-::::::..=....:::....:.:::::..  " << endl;
  cout << "                   .:...            .........-..-::::..-::.....-..:::::.:::-   " << endl;
  cout << "                    .::::.         .:::.....:-.:-::::..-:.......:=::..:::::--   " << endl;
  cout << "                     .:::::.       :::-......-.--:::..::........:==-:::::::-.   " << endl;
  cout << "                      .::::::.    ::::--:...:-.-+::..::...::.:--==*=-:-:--==:   " << endl;
  cout << "                       :-::::-:. ::::-==.....::.+-..-:....::::--===+=-::--==:   " << endl;
  cout << "                        :--:::---=-----=:.....-.::.-:.....::-:----++=------=-   " << endl;
  cout << "                         :-------==----::::::::-::::...::::-----==+=-:-----==:  " << endl;
  cout << "                          .--------===+:.-----:-=====-----------==++. -----==-  " << endl;
  cout << "                            :------===.  .::---==++++===---::---=-=.  :==-===-  " << endl;
  cout << "                              :---==.     ::::-=:=+=+=========--------------=-. " << endl;
  cout << "                                .:.       :::::-:-+::----==+++++====----------. " << endl;
  cout << "                                         .:::::=..=::.:::-----+**++++++++++++=. " << endl;
  cout << "                                          ..:.:-.:=:::::::-:---=+= .::-=+++++=  " << endl;
  cout << "                                          :::::-:=+:::::::----===-=      ....   " << endl;
  cout << "                                         .::--:-::+::::::-:----=-==-            " << endl;
  cout << "                                          ::::::-:-+::::::--:-----+=-            " << endl;
  cout << "                                         .::.:::-:=::::::::::::::---.           " << endl;
  cout << "                                          ..:.:-.:=::::::-:----=-==-            " << endl;

  cout << "Masukkan Nama: ";
  cin >> newNode->nama;
  cout << "Masukkan Usia: ";
  cin >> newNode->usia;

  cout << "Tingkat kepuasan terhadap pernyataan:\n";
  cout << "(1 tidak puas, 2 kurang puas, 3 cukup, 4 sangat puas)" << endl;
  newNode->kepuasan =
      tanyakanPertanyaan("Ruang rawat inap tertata rapi dan bersih (1-4): ");
  tanyakanPertanyaan("Ruang rawat inap nyaman (1-4): ");
  tanyakanPertanyaan("Memiliki alat-alat medis yang cukup lengkap (1-4):");
  tanyakanPertanyaan("Kursi roda/Trolli tersedia di kantor penerimaan untuk "
                     "membawa pasien ke ruang rawat inap(1-4): ");
  tanyakanPertanyaan("Tempat tidur telah disiapkan dalam keadaan rapi, bersih "
                     "dan siap pakai(1-4): ");
  tanyakanPertanyaan("Alat makan dan minum bersih dan baik(1-4): ");
  tanyakanPertanyaan("Keramahan perawat(1-4): ");
  tanyakanPertanyaan("Penampilan perawat bersih dan rapi(1-4): ");
  tanyakanPertanyaan("Perawat yang merawat Anda tanggap terhadap pertanyaan "
                     "atau keluhan Anda(1-4): ");
  tanyakanPertanyaan(
      "Perawat memberikan kesempatan bertanya kepada pasien(1-4): ");
  tanyakanPertanyaan(
      "Perawat memberikan pengetahuan dan penjelasan perawatan(1-4): ");
  tanyakanPertanyaan("Kecepatan perawat membantu.(1-4):");
  tanyakanPertanyaan("Menjelaskan dan meminta persetujuan tentang "
                     "tindakan-tindakan perawat yang dilakukan(1-4): ");
  tanyakanPertanyaan("Memenuhi kebutuhan pasien.(1-4):");
  tanyakanPertanyaan("Selalu melakukan kunjungan ke kamar pasien secara "
                     "teratur pada saat (aplusan/ganti shif).(1-4): ");
  tanyakanPertanyaan("Perawat melaporkan secara detail perubahan pasien kepada "
                     "Dokter sewaktu melakukan kunjungan (1-4): ");
  tanyakanPertanyaan("Prosedur penerimaan pasien dilayani secara cepat dan "
                     "tidak berbelit-belit(1-4): ");
  tanyakanPertanyaan("Perawat datang tepat waktu (1-4): ");
  tanyakanPertanyaan("Kesiapan perawat melayani pasien(1-4): ");
  tanyakanPertanyaan("Perawat bertindak cepat(1-4): ");
  tanyakanPertanyaan("Perawat melaporkan segala detail perubahan pasien kepada "
                     "Dokter sewaktu melakukan kunjungan(1-4): ");
  tanyakanPertanyaan("Perawat selalu memberi obat pasien sesuai prosedur "
                     "pemberian obat(1-4): ");
  tanyakanPertanyaan("Perawat segera menghubungi Dokter mengenai obat dan "
                     "makanan pasien(1-4): ");
  tanyakanPertanyaan("Perawat memperhatikan keluhan keluarga pasien(1-4): ");
  newNode->next = head;
  head = newNode;
}

// Fungsi untuk menyimpan data kuisioner ke dalam file "kuisoner.txt"
void simpanKuisonerKeFile(const KuisionerNode *head) {
  ofstream file("kuisoner.txt");
  const KuisionerNode *current = head;

  while (current != nullptr) {
    file << "=================================================================="
            "=================="
         << endl;
    file << "Nama: " << current->nama << "\n";
    file << "Usia: " << current->usia << "\n";
    file << "Kepuasan:\n";
    file << "Ruang rawat inap tertata rapi dan bersih(1-4): "
         << current->kepuasan << "\n";
    file << "Memiliki alat-alat medis yang cukup lengkap (1-4): "
         << current->kepuasan << "\n";
    file << "Kursi roda/Trolli tersedia di kantor penerimaan untuk membawa "
            "pasien ke ruang rawat inap(1-4): "
         << current->kepuasan << "\n";
    file << "Tempat tidur telah disiapkan dalam keadaan rapi, bersih dan siap "
            "pakai(1-4): "
         << current->kepuasan << "\n";
    file << "Alat makan dan minum bersih dan baik(1-4): " << current->kepuasan
         << "\n";
    file << "Keramahan perawat(1-4): " << current->kepuasan << "\n";
    file << "Penampilan perawat bersih dan rapi(1-4): " << current->kepuasan
         << "\n";
    file << "Perawat yang merawat Anda tanggap terhadap pertanyaan atau "
            "keluhan Anda(1-4): "
         << current->kepuasan << "\n";
    file << "Perawat memberikan kesempatan bertanya kepada pasien.(1-4): "
         << current->kepuasan << "\n";
    file << "Perawat memberikan pengetahuan dan penjelasan perawatan.(1-4): "
         << current->kepuasan << "\n";
    file << "Kecepatan perawat membantu.(1-4): " << current->kepuasan << "\n";
    file << "Menjelaskan dan meminta persetujuan tentang tindakan-tindakan "
            "perawat yang dilakukan.(1-4): "
         << current->kepuasan << "\n";
    file << "Memenuhi kebutuhan pasien.(1-4):" << current->kepuasan << "\n";
    file << "Selalu melakukan kunjungan ke kamar pasien secara teratur pada "
            "saat (aplusan/ganti shif) (1-4): "
         << current->kepuasan << "\n";
    file << "Perawat melaporkan secara detail perubahan pasien kepada Dokter "
            "sewaktu melakukan kunjungan (1-4): "
         << current->kepuasan << "\n";
    file << "Prosedur penerimaan pasien dilayani secara cepat dan tidak "
            "berbelit-belit.(1-4): "
         << current->kepuasan << "\n";
    file << "Perawat datang tepat waktu (1-4): " << current->kepuasan << "\n";
    file << "Kesiapan perawat melayani pasien (1-4): " << current->kepuasan
         << "\n";
    file << "Perawat bertindak cepat (1-4):" << current->kepuasan << "\n";
    file << "Perawat melaporkan segala detail perubahan pasien kepada Dokter "
            "sewaktu melakukan kunjungan (1-4): "
         << current->kepuasan << "\n";
    file << "Perawat selalu memberi obat pasien sesuai prosedur pemberian obat "
            "(1-4) :"
         << current->kepuasan << "\n";
    file << "Perawat segera menghubungi Dokter mengenai obat dan makanan "
            "pasien(1-4) :"
         << current->kepuasan << "\n";
    file << "Perawat memperhatikan keluhan keluarga pasien(1-4): "
         << current->kepuasan << "\n";
    current = current->next;
  }

  file.close();
}

void kuisoner() {
  KuisionerNode *head = nullptr;
  char lanjut;

  do {
    tambahkanKuisioner(head);
    cout << "Ingin menambahkan data kuisioner lainnya? (y/n): ";
    cin >> lanjut;
  } while (lanjut == 'y' || lanjut == 'Y');

  // Simpan data kuisioner ke dalam file
  simpanKuisonerKeFile(head);

  // Hapus linked list untuk menghindari kebocoran memori
  while (head != nullptr) {
    KuisionerNode *temp = head;
    head = head->next;
    delete temp;
  }

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
#endif