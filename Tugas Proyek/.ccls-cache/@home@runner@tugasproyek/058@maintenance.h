#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Schedule {
    int id;
    string date;
    string time;
    string description;

    Schedule(int _id, const string& _date, const string& _time, const string& _desc)
        : id(_id), date(_date), time(_time), description(_desc) {}
};

struct Node {
    Schedule data;
    Node* left;
    Node* right;
    int height;

    Node(const Schedule& _data) : data(_data), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, const Schedule& schedule) {
        if (node == nullptr)
            return new Node(schedule);

        if (schedule.id < node->data.id)
            node->left = insert(node->left, schedule);
        else if (schedule.id > node->data.id)
            node->right = insert(node->right, schedule);
        else
            return node; // Duplicate ID not allowed

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && schedule.id < node->left->data.id)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && schedule.id > node->right->data.id)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && schedule.id > node->left->data.id) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && schedule.id < node->right->data.id) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void insert(const Schedule& schedule) {
        root = insert(root, schedule);
    }

    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << "ID: " << node->data.id << " | Date: " << node->data.date
                      << " | Time: " << node->data.time << " | Description: " << node->data.description << endl;
            inOrderTraversal(node->right);
        }
    }

    void displaySchedule() {
        inOrderTraversal(root);
    }
};

void readScheduleFromFile(const string& filename, AVLTree& avlTree) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    int id;
    string date, time, description;

    while (file >> id >> date >> time) {
        getline(file, description);
        avlTree.insert(Schedule(id, date, time, description));
    }

    file.close();
}

void writeScheduleToFile(const string& filename, const Schedule& schedule) {
    ofstream file(filename, ios_base::app);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    file << schedule.id << " " << schedule.date << " " << schedule.time << " " << schedule.description << endl;

    file.close();
}

void maintenance() {
    AVLTree avlTree;

    // Membaca jadwal dari file
    readScheduleFromFile("jadwal_maintenance.txt", avlTree);

    int choice;
    do {
         cout << "       _         _______          __     _                                      " << endl;
          cout << "      | |  /\\   |  __ \\ \\        / /\\   | |                                     " << endl;
          cout << "      | | /  \\  | |  | \\ \\  /\\  / /  \\  | |                                     " << endl;
          cout << "  _   | |/ /\\ \\ | |  | |\\ \\/  \\/ / /\\ \\ | |                                     " << endl;
          cout << " | |__| / ____ \\| |__| | \\  /\\  / ____ \\| |____                                " << endl;
          cout << "  \\____/_/    \\_\\_____/ _ \\/_ \\/_/___ \\_\\______| _          _   _  _____ ______" << endl;
          cout << " |  \\/  |   /\\   |_   _| \\ | |__   __|  ____| \\ | |   /\\   | \\ | |/ ____|  ____|" << endl;
          cout << " | \\  / |  /  \\    | | |  \\| |  | |  | |__  |  \\| |  /  \\  |  \\| | |    | |__  " << endl;
          cout << " | |\\/| | / /\\ \\   | | | . ` |  | |  |  __| | . ` | / /\\ \\ | . ` | |    |  __| " << endl;
          cout << " | |  | |/ ____ \\ _| |_| |\\  |  | |  | |____| |\\  |/ ____ \\| |\\  | |____| |____" << endl;
          cout << " |_|  |_/_/    \\_\\_____|_| \\_|  |_|  |______|_| \\_/_/    \\_\\_| \\_|\\_____|______|" << endl;
        cout << "\nMenu:\n";
        cout << "1. Lihat Jadwal\n";
        cout << "2. Masukkan Jadwal\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Jadwal Maintenance Rumah Sakit:\n";
                avlTree.displaySchedule();
                break;
            case 2: {
                int id;
                string date, time, description;

                cout << "Masukkan ID: ";
                cin >> id;
                cout << "Masukkan Tanggal (yyyy-mm-dd): ";
                cin >> date;
                cout << "Masukkan Waktu: ";
                cin >> time;
                cout << "Masukkan Deskripsi: ";
                cin.ignore(); // Clear newline character from buffer
                getline(cin, description);

                Schedule newSchedule(id, date, time, description);
                avlTree.insert(newSchedule);
                writeScheduleToFile("jadwal_maintenance.txt", newSchedule);
                cout << "Jadwal berhasil ditambahkan.\n";
                break;
            }
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (choice != 0);

}
