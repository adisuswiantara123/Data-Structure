#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Class untuk mengelola array statis
template <class T, int N>
class Array1Dstatis {
public:
    Array1Dstatis() {
        for (int i = 0; i < N; i++) {
            data[i] = T();
        }
    }

    T& operator[](int index) {
        if (index >= 0 && index < N) {
            return data[index];
        } else {
            throw out_of_range("Index out of range");
        }
    }

    const T& operator[](int index) const {
        if (index >= 0 && index < N) {
            return data[index];
        } else {
            throw out_of_range("Index out of range");
        }
    }

private:
    T data[N];
};

// Class untuk mengelola array dinamis
template <class T>
class Array1Ddinamis {
public:
    Array1Ddinamis(int sz) : size_(sz) {
        elements_ = new T[sz];
    }

    ~Array1Ddinamis() {
        delete[] elements_;
    }

    Array1Ddinamis<T>& ReSize(int sz) {
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

    T& operator[](int index) {
        if (index >= 0 && index < size_) {
            return elements_[index];
        } else {
            throw out_of_range("Index out of range");
        }
    }

    const T& operator[](int index) const {
        if (index >= 0 && index < size_) {
            return elements_[index];
        } else {
            throw out_of_range("Index out of range");
        }
    }

    int Size() const {
        return size_;
    }

private:
    T* elements_;
    int size_;
};

// Struct untuk merepresentasikan nilai mahasiswa
template <class T>
struct Nilai {
    int nim;
    string nama;
    Array1Dstatis<char, 2> uk;
    Array1Dstatis<int, 2> uas;
    float tugas_proyek;
    float na;

    // Menghitung nilai angka berdasarkan persentase
    void HitungNA() {
        na = (uk[0] * 0.1 + uk[1] * 0.1 + tugas_proyek * 0.3 + uas[0] * 0.2 + uas[1] * 0.3);
    }
};

// Operator overloading untuk output dalam format tabel
ostream& operator<<(ostream& os, const Nilai<float>& nilai) {
    static bool headerPrinted = false; 

    if (!headerPrinted) { 
        os << "===========================================================================================================" << endl;

        os << left << setw(15) << "NIM";
        os << left << setw(40) << "Nama Mahasiswa";
        os << left << setw(20) << "Nilai";
        os << endl;

        os << "===========================================================================================================" << endl;

        os << left << setw(15) << "";
        os << left << setw(20) << "| Persentase Nilai(%)       | UK1     | UK2     | Tugas Proyek | UTS     | UAS     | NA(Angka) |  ";
        os << endl;

        os << "===========================================================================================================" << endl;

        os << left << setw(15) << "";
        os << left << setw(28) << "| 100(%)";
        os << left << setw(10) << "| 10(%)";
        os << left << setw(10) << "| 10(%)";
        os << left << setw(15) << "| 30(%)";
        os << left << setw(10) << "| 20(%)";
        os << left << setw(10) << "| 30(%)";
        os << left << setw(15) << "|";
        os << endl;
        os << "===========================================================================================================" << endl;

        headerPrinted = true; 
    }

    os << left << setw(15) << nilai.nim;
    os << left << setw(30) << nilai.nama;
    os << left << setw(10) << nilai.uk[0];
    os << left << setw(10) << nilai.uk[1];
    os << left << setw(15) << nilai.tugas_proyek;
    os << left << setw(10) << nilai.uas[0];
    os << left << setw(10) << nilai.uas[1];
    os << left << setw(15) << nilai.na;
    os << endl;

    os << "===========================================================================================================" << endl;

    return os;
}

int main() {
    // Inisialisasi data nilai mahasiswa
    Array1Ddinamis<Nilai<float>> nilaiMahasiswa(3);
    nilaiMahasiswa[0].nim = 2200018002;
    nilaiMahasiswa[0].nama = "Hamdan AL ATSARI";
    nilaiMahasiswa[0].uk[0] = 'K';
    nilaiMahasiswa[0].uk[1] = 'K';
    nilaiMahasiswa[0].uas[0] = 99.6;
    nilaiMahasiswa[0].uas[1] = 85;
    nilaiMahasiswa[0].tugas_proyek = 55;

    nilaiMahasiswa[1].nim = 2200018005;
    nilaiMahasiswa[1].nama = "Ainul Pasha M S";
    nilaiMahasiswa[1].uk[0] = 'T';
    nilaiMahasiswa[1].uk[1] = 'K';
    nilaiMahasiswa[1].uas[0] = 100;
    nilaiMahasiswa[1].uas[1] = 25;
    nilaiMahasiswa[1].tugas_proyek = 20;

    nilaiMahasiswa[2].nim = 2200018006;
    nilaiMahasiswa[2].nama = "Yuzar F N";
    nilaiMahasiswa[2].uk[0] = 'T';
    nilaiMahasiswa[2].uk[1] = 'K';
    nilaiMahasiswa[2].uas[0] = 97.8;
    nilaiMahasiswa[2].uas[1] = 30;
    nilaiMahasiswa[2].tugas_proyek = 40;

    // Hitung NA untuk setiap mahasiswa
    for (int i = 0; i < nilaiMahasiswa.Size(); i++) {
        nilaiMahasiswa[i].HitungNA();
    }

    // Cetak nilai mahasiswa dalam format tabel
    for (int i = 0; i < nilaiMahasiswa.Size(); i++) {
        cout << nilaiMahasiswa[i] << endl;
    }

    return 0;
}