#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Class untuk mengelola array statis
template <class T, int N>
class Array1Dstatis {
public:
    Array1Dstatis();

    T& operator[](int index);
    const T& operator[](int index) const;

private:
    T data[N];
};

template <class T, int N>
Array1Dstatis<T, N>::Array1Dstatis() {
    for (int i = 0; i < N; i++) {
        data[i] = T();
    }
}

template <class T, int N>
T& Array1Dstatis<T, N>::operator[](int index) {
    if (index >= 0 && index < N) {
        return data[index];
    } else {
        throw out_of_range("Index out of range");
    }
}

template <class T, int N>
const T& Array1Dstatis<T, N>::operator[](int index) const {
    if (index >= 0 && index < N) {
        return data[index];
    } else {
        throw out_of_range("Index out of range");
    }
}

// Class untuk mengelola array dinamis
template <class T>
class Array1Ddinamis {
public:
    Array1Ddinamis(int sz);

    ~Array1Ddinamis();

    Array1Ddinamis<T>& ReSize(int sz);

    T& operator[](int index);
    const T& operator[](int index) const;

    int Size() const;

private:
    T* elements_;
    int size_;
};

template <class T>
Array1Ddinamis<T>::Array1Ddinamis(int sz) : size_(sz) {
    elements_ = new T[sz];
}

template <class T>
Array1Ddinamis<T>::~Array1Ddinamis() {
    delete[] elements_;
}

template <class T>
Array1Ddinamis<T>& Array1Ddinamis<T>::ReSize(int sz) {
    if (sz == size_) {
        return *this;
    }

    T* newData = new T[sz];
    int minSize = (sz < size_) ? sz : size_;
    for (int i = 0; i < minSize; i++) {
        newData[i] = elements_[i];
    }
    delete[] elements_;
    elements_ = newData;
    size_ = sz;
    return *this;
}

template <class T>
T& Array1Ddinamis<T>::operator[](int index) {
    if (index >= 0 && index < size_) {
        return elements_[index];
    } else {
        throw out_of_range("Index out of range");
    }
}

template <class T>
const T& Array1Ddinamis<T>::operator[](int index) const {
    if (index >= 0 && index < size_) {
        return elements_[index];
    } else {
        throw out_of_range("Index out of range");
    }
}

template <class T>
int Array1Ddinamis<T>::Size() const {
    return size_;
}

// Struct untuk merepresentasikan item barang
struct Item {
    string nama;
    Array1Dstatis<int, 2> harga;
    Array1Dstatis<int, 2> stok;
};

// Operator overloading untuk input dan output
ostream& operator<<(ostream& os, const Item& item);

istream& operator>>(istream& is, Item& item);

// Class untuk mengelola daftar barang secara dinamis
template <class T>
class BarangList {
public:
    Array1Ddinamis<T> data;

    BarangList(int sz);

    int Size() const;

    void TambahBarang(const T& item);
};

template <class T>
BarangList<T>::BarangList(int sz) : data(sz) {}

template <class T>
int BarangList<T>::Size() const {
    return data.Size();
}

template <class T>
void BarangList<T>::TambahBarang(const T& item) {
    data.ReSize(data.Size() + 1);
    data[data.Size() - 1] = item;
}

// Implementasi operator overloading untuk input dan output
ostream& operator<<(ostream& os, const Item& item) {
    static bool headerPrinted = false;

    if (!headerPrinted) {
        os << left << setw(15) << "Nama Barang";
        os << left << setw(10) << "1Liter";
        os << left << setw(10) << "Stok";
        os << left << setw(10) << "2Liter";
        os << left << setw(10) << "Stok";
        os << endl;

        headerPrinted = true;
    }

    os << left << setw(15) << item.nama;
    os << left << setw(10) << item.harga[0];
    os << left << setw(10) << item.stok[0];
    os << left << setw(10) << item.harga[1];
    os << left << setw(10) << item.stok[1];
    os << endl;

    return os;
}


istream& operator>>(istream& is, Item& item) {
    cout << "Nama Barang: ";
    is >> item.nama;
    cout << "Harga 1 Liter: ";
    is >> item.harga[0];
    cout << "Stok 1 Liter: ";
    is >> item.stok[0];
    cout << "Harga 2 Liter: ";
    is >> item.harga[1];
    cout << "Stok 2 Liter: ";
    is >> item.stok[1];
    return is;
}

int main() {
    int choice;

    BarangList<Item> barangList(0);

    do {
        cout << "Menu: \n";
        cout << "1. Admin\n";
        cout << "2. Pembeli\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int adminChoice;
                do {
                    cout << "Menu Admin: \n";
                    cout << "1. Perlihatkan Stok\n";
                    cout << "2. Tambah Barang\n";
                    cout << "3. Kembali\n";
                    cout << "Pilihan: ";
                    cin >> adminChoice;

                    if (adminChoice == 1) {
                        // Perlihatkan stok
                        for (int i = 0; i < barangList.Size(); i++) {
                            cout << barangList.data[i] << endl;
                        }
                    } else if (adminChoice == 2) {
                        // Tambah barang
                        Item newItem;
                        cin >> newItem;
                        barangList.TambahBarang(newItem);
                    }
                } while (adminChoice != 3);
                break;
            }
            case 2: {
                // Menu pembeli
                for (int i = 0; i < barangList.Size(); i++) {
                    cout << "Barang ke-" << i + 1 << ": " << barangList.data[i].nama << endl;
                }

                int selectedBarang;
                cout << "Pilih nomor barang yang ingin dibeli (1-" << barangList.Size() << "): ";
                cin >> selectedBarang;

                if (selectedBarang >= 1 && selectedBarang <= barangList.Size()) {
                    selectedBarang--; // Index array dimulai dari 0

                    int selectedLiter;
                    cout << "Pilih liter (1 Liter - 1, 2 Liter - 2): ";
                    cin >> selectedLiter;

                    if (selectedLiter == 1 || selectedLiter == 2) {
                        selectedLiter--; // Index array dimulai dari 0

                        if (barangList.data[selectedBarang].stok[selectedLiter] > 0) {
                            // Barang tersedia
                            cout << "Harga per Liter: " << barangList.data[selectedBarang].harga[selectedLiter] << endl;
                            int jumlahBeli;
                            cout << "Masukkan jumlah yang ingin dibeli: ";
                            cin >> jumlahBeli;

                            if (jumlahBeli <= barangList.data[selectedBarang].stok[selectedLiter]) {
                                // Pembelian berhasil
                                int totalHarga = jumlahBeli * barangList.data[selectedBarang].harga[selectedLiter];
                                cout << "Total Harga: " << totalHarga << endl;

                                // Update stok
                                barangList.data[selectedBarang].stok[selectedLiter] -= jumlahBeli;
                            } else {
                                cout << "Stok tidak mencukupi." << endl;
                            }
                        } else {
                            cout << "Stok barang habis." << endl;
                        }
                    } else {
                        cout << "Pilihan liter tidak valid." << endl;
                    }
                } else {
                    cout << "Nomor barang tidak valid." << endl;
                }

                break;
            }
        }
    } while (choice != 3);

    return 0;
}
