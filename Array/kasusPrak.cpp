#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Class untuk  array statis
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

// Class untuk array dinamis
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

// Struct 
struct Praktikum {
    Array1Dstatis<string, 2> matkul;
    Array1Ddinamis<string> slot;

    Praktikum() : slot(3) {
        slot[0] = "";
        slot[1] = "";
        slot[2] = "";
    }
};

// Operator overloading untuk output
ostream& operator<<(ostream& os, const Praktikum& praktikum) {
    os << left << setw(15) << praktikum.matkul[0];
    for (int i = 0; i < praktikum.slot.Size(); i++) {
        os << left << setw(15) << praktikum.slot[i];
    }
    os << endl;
    return os;
}

int main() {
    Array1Ddinamis<Praktikum> dataPraktikum(8);

    dataPraktikum[0].matkul[0] = "Struktur Data";
    dataPraktikum[0].slot[0] = "KIRANI";
    dataPraktikum[0].slot[1] = "PINASTI";
    dataPraktikum[0].slot[2] = "LIFA";

    dataPraktikum[1].matkul[0] = "";
    dataPraktikum[1].slot[0] = "PINASTI";
    dataPraktikum[1].slot[1] = "FIRDA";
    dataPraktikum[1].slot[2] = "RIZALDY";

    dataPraktikum[2].matkul[0] = "";
    dataPraktikum[2].slot[0] = "LIFA";
    dataPraktikum[2].slot[1] = "";
    dataPraktikum[2].slot[2] = "KIRANI";

    dataPraktikum[3].matkul[0] = "";
    dataPraktikum[3].slot[0] = "RIJALUL";

    dataPraktikum[4].matkul[0] = "Diskrit";
    dataPraktikum[4].slot[0] = "LIFA";
    dataPraktikum[4].slot[1] = "PASCAL";
    dataPraktikum[4].slot[2] = "FIRDA";

    dataPraktikum[5].matkul[0] = "";
    dataPraktikum[5].slot[0] = "RIZALDY";
    dataPraktikum[5].slot[1] = "TIRTA";
    dataPraktikum[5].slot[2] = "DHANDY";

    dataPraktikum[6].matkul[0] = "";
    dataPraktikum[6].slot[0] = "KIRANI";
    dataPraktikum[6].slot[1] = "KIRANI";
    dataPraktikum[6].slot[2] = "PINASTI";

    dataPraktikum[7].matkul[0] = "";
    dataPraktikum[7].slot[0] = "";
    dataPraktikum[7].slot[1] = "FIRDA";
    dataPraktikum[7].slot[2] = "SYHAB";

    cout << "=====================================================" << endl;
    cout << left << setw(15) << "Mata Kuliah";
    cout << left << setw(15) << "Slot 1";
    cout << left << setw(15) << "Slot 2";
    cout << left << setw(15) << "Slot 3";
    cout << endl;
    cout << "=====================================================" << endl;

    for (int i = 0; i < dataPraktikum.Size(); i++) {
        cout << dataPraktikum[i];
    }

    return 0;
}
