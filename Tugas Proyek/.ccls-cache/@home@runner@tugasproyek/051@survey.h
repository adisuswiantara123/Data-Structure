#ifndef SURVEY_H
#define SURVEY_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct SurveyResponse {
    string question;
    string answer;
};

class Survey {
public:
    Survey(const string& name, const string* questions, int numQuestions);

    void FillSurvey();
    void DisplayResults() const;
    void SaveResultsToTXT() const;

private:
    string surveyName;
    const string* surveyQuestions;
    int numSurveyQuestions;
    SurveyResponse* responses;
};

Survey::Survey(const string& name, const string* questions, int numQuestions)
    : surveyName(name), surveyQuestions(questions), numSurveyQuestions(numQuestions) {
    responses = new SurveyResponse[numQuestions];
}

void Survey::FillSurvey() {
    for (int i = 0; i < numSurveyQuestions; ++i) {
        cout << "Q" << i + 1 << ": " << surveyQuestions[i] << endl;
        cout << "A: ";
        cin.ignore();
        getline(cin, responses[i].answer);
    }
}

void Survey::DisplayResults() const {
    cout << "Survey Name: " << surveyName << endl;
    for (int i = 0; i < numSurveyQuestions; ++i) {
        cout << "Q" << i + 1 << ": " << surveyQuestions[i] << endl;
        cout << "A: " << responses[i].answer << endl;
    }
}

void Survey::SaveResultsToTXT() const {
    ofstream file(surveyName + "_results.txt"); // Nama file berdasarkan nama survei
    if (file.is_open()) {
        file << "Survey Name: " << surveyName << endl;
        for (int i = 0; i < numSurveyQuestions; ++i) {
            file << "Q" << i + 1 << ": " << surveyQuestions[i] << endl;
            file << "A: " << responses[i].answer << endl;
        }
        file.close();
        cout << "Hasil survey telah disimpan dalam file " << surveyName << "_results.txt" << endl;
    } else {
        cout << "Gagal membuka file untuk menyimpan hasil survey." << endl;
    }
}

void survey() {
    const int numSurveys = 5;

    string surveyNames[] = {
        "Kepuasan Pasien",
        "Kualitas Makanan",
        "Fasilitas Rumah Sakit",
        "Keamanan Pasien",
        "Kepuasan Keluarga Pasien"
    };

    string* questions[] = {
        new string[10] {
            "Seberapa puas Anda dengan pelayanan medis yang Anda terima selama kunjungan ke rumah sakit?",
            "Apakah staf medis memberikan penjelasan yang memadai tentang kondisi kesehatan Anda dan pengobatan yang Anda terima?",
            "Bagaimana pendapat Anda tentang waktu tunggu di rumah sakit sebelum mendapatkan perawatan?",
            "Apakah Anda merasa diperlakukan dengan hormat dan perhatian oleh staf medis?",
            "Sejauh mana Anda merasa informasi medis Anda dijelaskan dengan baik?",
            "Bagaimana pendapat Anda tentang kebersihan dan sanitasi di fasilitas rumah sakit?",
            "Apakah Anda puas dengan ketersediaan fasilitas penunjang seperti parkir, toilet, dan ruang tunggu?",
            "Sejauh mana Anda merasa bahwa perawatan medis yang Anda terima efektif dalam memperbaiki kondisi kesehatan Anda?",
            "Apakah Anda puas dengan komunikasi antara dokter, perawat, dan tim medis lainnya?",
            "Apakah Anda merasa bahwa rumah sakit memberikan dukungan yang cukup dalam hal tindak lanjut setelah perawatan?"
        },
        new string[10] {
            "Bagaimana kualitas makanan yang disajikan di rumah sakit menurut Anda?",
            "Apakah makanan yang Anda terima memiliki rasa yang memuaskan?",
            "Sejauh mana pilihan menu makanan di rumah sakit memenuhi preferensi Anda?",
            "Apakah makanan yang disajikan mempertimbangkan kebutuhan diet atau batasan kesehatan Anda?",
            "Bagaimana pendapat Anda tentang presentasi makanan di piring atau wadah?",
            "Apakah Anda merasa bahwa makanan yang disajikan di rumah sakit memiliki nilai gizi yang cukup?",
            "Sejauh mana Anda merasa bahwa makanan yang disajikan di rumah sakit segar?",
            "Apakah pelayanan makanan di rumah sakit tepat waktu dan efisien?",
            "Bagaimana pendapat Anda tentang variasi menu yang tersedia dalam periode waktu tertentu?",
            "Apakah Anda pernah mengalami masalah atau kekecewaan khusus terkait dengan makanan di rumah sakit? Jika ya, jelaskan."
        },
        new string[10] {
            "Sejauh mana Anda merasa fasilitas parkir di rumah sakit memadai dan mudah diakses?",
            "Bagaimana pendapat Anda tentang kenyamanan dan kebersihan ruang tunggu di rumah sakit?",
            "Apakah Anda puas dengan ketersediaan fasilitas toilet di rumah sakit?",
            "Sejauh mana fasilitas kafetaria/restoran di rumah sakit memenuhi kebutuhan Anda?",
            "Bagaimana pendapat Anda tentang ketersediaan ruang keluarga atau area istirahat bagi pasien dan keluarga?",
            "Apakah fasilitas komunikasi seperti telepon dan Wi-Fi tersedia dengan baik di rumah sakit?",
            "Bagaimana pengalaman Anda dengan ketersediaan fasilitas penyimpanan barang pribadi Anda di rumah sakit?",
            "Sejauh mana Anda merasa bahwa fasilitas transportasi seperti taksi atau transportasi publik tersedia dengan baik di sekitar rumah sakit?",
            "Apakah Anda merasa bahwa fasilitas rumah sakit memiliki petunjuk yang jelas dan peta untuk membantu pasien dan pengunjung?",
            "Bagaimana pendapat Anda tentang aksesibilitas fasilitas rumah sakit untuk orang dengan kebutuhan khusus, seperti kursi roda?",
        },
        new string[10] {
            "Apakah Anda merasa aman dan terlindungi selama tinggal di rumah sakit?",
            "Bagaimana pendapat Anda tentang langkah-langkah keamanan yang diambil oleh rumah sakit, seperti identifikasi pasien dengan gelang identifikasi?",
            "Apakah Anda merasa bahwa informasi medis Anda dijaga kerahasiaannya dengan baik oleh staf medis?",
            "Bagaimana pendapat Anda tentang tindakan keamanan yang diambil untuk mencegah infeksi nosokomial (infeksi yang terjadi di rumah sakit)?",
            "Sejauh mana Anda merasa bahwa staf medis mematuhi protokol kebersihan tangan?",
            "Apakah Anda merasa bahwa staf medis menjelaskan prosedur medis dan pengobatan dengan baik sebelum melaksanakannya?",
            "Bagaimana pendapat Anda tentang sistem peringatan atau tanda kesalahan yang ada di rumah sakit untuk mencegah kesalahan medis?",
            "Apakah Anda pernah mengalami masalah keamanan pasien, seperti kejadian jatuh atau efek samping yang tidak diinginkan selama perawatan Anda? Jika ya, jelaskan.",
            "Bagaimana pengalaman Anda dengan pengawasan keamanan pasien, terutama jika Anda memiliki kebutuhan khusus atau risiko tertentu?",
            "Apakah Anda merasa bahwa rumah sakit memberikan edukasi kepada pasien tentang keselamatan dan keamanan pasien?"
        },
        new string[10] {
            "Sejauh mana Anda merasa bahwa staf medis di rumah sakit memberikan informasi yang cukup kepada keluarga pasien tentang kondisi dan perawatan pasien?",
            "Bagaimana pendapat Anda tentang kemampuan keluarga pasien untuk berkomunikasi dengan staf medis dan mendapatkan jawaban atas pertanyaan mereka?",
            "Apakah Anda merasa bahwa keluarga pasien diberikan kesempatan untuk terlibat dalam keputusan perawatan pasien?",
            "Bagaimana pengalaman Anda dengan dukungan emosional yang diberikan kepada keluarga pasien dalam situasi kritis?",
            "Sejauh mana Anda merasa bahwa fasilitas ruang tunggu dan area keluarga di rumah sakit nyaman dan mendukung?",
            "Apakah Anda merasa bahwa rumah sakit memberikan informasi yang cukup kepada keluarga pasien tentang hak dan tanggung jawab mereka?",
            "Bagaimana pendapat Anda tentang akses keluarga pasien terhadap informasi medis pasien dan catatan medis?",
            "Sejauh mana Anda merasa bahwa rumah sakit memberikan dukungan dalam hal tindak lanjut pasien setelah perawatan di rumah sakit?",
            "Apakah Anda pernah mengalami kendala atau masalah dalam berkomunikasi dengan staf medis atau administrasi rumah sakit? Jika ya, jelaskan.",
            "Bagaimana tingkat kepuasan Anda secara keseluruhan terhadap pelayanan dan perhatian yang diberikan kepada keluarga pasien di rumah sakit?"
        }
    };

    Survey surveys[numSurveys] = {
        Survey(surveyNames[0], questions[0], 10),
        Survey(surveyNames[1], questions[1], 10),
        Survey(surveyNames[2], questions[2], 10),
        Survey(surveyNames[3], questions[3], 10),
        Survey(surveyNames[4], questions[4], 10)
    };

    int choice;
    do {
      cout << "    /$$$$$$  /$$   /$$ /$$$$$$$  /$$    /$$ /$$$$$$$$ /$$     /$$" << endl;
      cout << "   /$$__  $$| $$  | $$| $$__  $$| $$   | $$| $$_____/|  $$   /$$/" << endl;
      cout << "  | $$  \\__/| $$  | $$| $$  \\ $$| $$   | $$| $$       \\  $$ /$$/ " << endl;
      cout << "  |  $$$$$$ | $$  | $$| $$$$$$$/|  $$ / $$/| $$$$$     \\  $$$$/  " << endl;
      cout << "   \\____  $$| $$  | $$| $$__  $$ \\  $$ $$/ | $$__/      \\  $$/   " << endl;
      cout << "   /$$  \\ $$| $$  | $$| $$  \\ $$  \\  $$$/  | $$          | $$    " << endl;
      cout << "  |  $$$$$$/|  $$$$$$/| $$  | $$   \\  $/   | $$$$$$$$    | $$    " << endl;
      cout << "   \\______/  \\______/ |__/  |__/    \\_/    |________/    |__/    " << endl;
      cout << "                                                                 " << endl;
      cout << "                                                                 " << endl;
      cout << "                                                                 " << endl;
      cout << "                                                                                          " << endl;
      cout << "                                                                                          " << endl;
      cout << "                                                                                          " << endl;
      cout << "                                                                                          " << endl;
      cout << "                                                                                          " << endl;
      cout << "                                     .::--==+++++==--:.                                   " << endl;
      cout << "                                .-=+####################*+-.                              " << endl;
      cout << "                             .=*############################*=:                           " << endl;
      cout << "                           -*#################################**-                         " << endl;
      cout << "                         :*#######################################*:                       " << endl;
      cout << "                        +#######################################-                         " << endl;
      cout << "                       +################################**#######-                        " << endl;
      cout << "                      +########################**######*-::-=+###*.                       " << endl;
      cout << "                     :########################+-######+::::::::+##-         ...           " << endl;
      cout << "                     -######################*--*###*+-::-----:::-*+         :::.          " << endl;
      cout << "                     =#############*######*=:-*##*=:::::::::::::::+        ::::           " << endl;
      cout << "                     -############=*####+-::+#+=-::::::::::::::::::..     .:::.           " << endl;
      cout << "                      *#########*==#*+=:::-=-::::::::::::-==::::::::::   .:::::::..       " << endl;
      cout << "                      :########+:====-::::::::::::::::::++-=*:::::::::..::::::::::::      " << endl;
      cout << "                       =#####*:::::-::::::::::::::::::::--:::::::::::..:-------::::::     " << endl;
      cout << "                        +#####::::::::::*++*-:::::::-=-::::----:::.    :::::::=::::::     " << endl;
      cout << "             .:.        .*+++#+::::::::-+::-:::::::::::-:::----::    .:-::-----:::::.     " << endl;
      cout << "     :=--::::::::       .::::**::::::::::::::-::::::::-=::::::::   .-----:::::::::..      " << endl;
      cout << "   :::::---::::::.      .:::::+-:::::::----:::=------=-::::::..:-----------..            " << endl;
      cout << "   :-----:::::::::...    .:::::::::::::----::::::-::::::::::-------------:.               " << endl;
      cout << "   :---:::::::::::-----::...     ..::::::::::::::::::::::--------------.                  " << endl;
      cout << "    ::-=-::::::::---------------------:-::::::::::::--=------------:.                     " << endl;
      cout << "     ...:::::::::----------------------=---...... .---==-------:.                         " << endl;
      cout << "            ..    ..:------------------=--==..... -=--==--:..                             " << endl;
      cout << "                        .....:::::::--====-- .... :-====--                                " << endl;
      cout << "                                    -------:.......-------.                               " << endl;
      cout << "                                   :-------........-------:                               " << endl;
      cout << "                                   -------- .......:-------.                              " << endl;
      cout << "                                  .-------..........-------:                             " << endl;
      cout << "                                  --------......... --------                             " << endl;
      cout << "                                  -------:...........-------:                            " << endl;
      cout << "                                 .:------:....  .....------::                            " << endl;
      cout << "                                   :**===++++++*+*+++===+**                              " << endl;
      cout << "                                   =+++++++++++*+*+++++++++-                             " << endl;
      cout << "                                   -+++++++++++***++++++++++=.                           " << endl;
      cout << "                                   -++++++++++:...=+++++++++++:                          " << endl;
      cout << "                                   -++++++++++     =+++++++++++-                         " << endl;
      cout << "                                   =+++++++++-      -+++++++++++-..:----:                " << endl;
      cout << "                                   =+++++++++.       :+++++++++++++++**#*+.              " << endl;
      cout << "                                   =++++++++=         .+++++++++++*#%%%%%%+              " << endl;
      cout << "                                   =++++++++:          .++++++++*%%%%%%%%%+              " << endl;
      cout << "                                   +++++++++.           .++++++#%%%%%%%%%%.              " << endl;
      cout << "                                   ++++++++=             .=+++#%%%%%%%%%%:               " << endl;
      cout << "                                  .++++++++-              .=+#%%%%%%%%%#.                 " << endl;
      cout << "                                .-++++++++++.               *%%%%%%%%#=                   " << endl;
      cout << "                              .-+++++++++++#.               :#%%%%%*-                     " << endl;
      cout << "                             .+++++++++++#%=                   .::.                       " << endl;
      cout << "                             -#*++++++*#%+.                                                " << endl;
      cout << "                              =*##%##*=-.                                                 " << endl;
      cout << "                                                                                          " << endl;
      cout << "                                                                                          " << endl;
      cout << "                                                                                          " << endl;
      cout << "                                                                                          " << endl;
        cout << "===============================================================================================\n";
        cout << "|    ! Survey yang Anda berikan akan sangat membantu kami, untuk itu, kami harapkan Anda !    |\n";
        cout << "|    ! memberikan jawaban yang dapat membangun kami menjadi lebih baik dari sebelumnya,  !    |\n";
        cout << "|    ! Terima Kasih telah meluangkan waktu Anda untuk mengisi survey yang kami buat.     !    |\n";
        cout << "===============================================================================================\n";
        cout << "|      Pilih survei yang ingin Anda isi atau tampilkan (1-5), atau ketik 0 untuk keluar:      |\n";
        cout << "===============================================================================================\n";
        cout << "Menu Survey :\n";
        cout << "1. Kepuasan Pasien\n";
        cout << "2. Kualitas Makanan\n";
        cout << "3. Fasilitas Rumah Sakit\n";
        cout << "4. Keamanan Pasien\n";
        cout << "5. Kepuasan Keluarga Pasien\n";
        cout << "Masukkan Pilihan Survey yang akan Anda Kerjakan: ";
        cin >> choice;

        if (choice >= 1 && choice <= numSurveys) {
            choice--;
            cout << "================================\n";
            cout << "|  Anda telah memilih survei:  |\n";
            cout << "         " << surveyNames[choice] << endl;
            cout << "================================\n";
            cout << "1. Isi survei" << endl;
            cout << "2. Tampilkan hasil survei" << endl;
            cout << "0. Keluar" << endl;
            cout << "Pilih opsi (1/2/0): ";
            int option;
            cin >> option;

            switch (option) {
                case 1:
                {
                    int surveyChoice;
                    do {
                        cout << "Pilih pertanyaan yang ingin Anda jawab (1-10) atau ketik 0 untuk kembali: ";
                        cin >> surveyChoice;

                        if (surveyChoice >= 1 && surveyChoice <= 10) {
                            surveyChoice--;
                            cout << "Anda telah memilih survei: " << surveyNames[choice] << endl;
                            surveys[choice].FillSurvey();
                            surveys[choice].SaveResultsToTXT();
                        } else if (surveyChoice != 0) {
                            cout << "Survei tidak valid. Pilih antara 1 dan 10." << endl;
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
                    } while (surveyChoice != 0);
                }
                break;
                case 2:
                    surveys[choice].DisplayResults();
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
                    break;
                case 0:
                    return survey();
                    break;
                default:
                    cout << "Opsi tidak valid." << endl;
            }
        } else if (choice != 0) {
            cout << "Survei tidak valid. Pilih antara 1 dan 5." << endl;
        }
    } while (choice != 0);
}
#endif
