#include <iostream>
using namespace std;

#define maks 5

int main() {
    char A[maks] = {'0'};
    int banyak = 0;

    cout << "\nIsi stack : ";
    for (int i = 0; i < banyak; i++)
        cout << A[i] << " ";

    for (char c = 'a'; c < 'g'; c++) {
        cout << "\nElemen masuk : " << c;
        if (banyak == maks) {
            cout << " Stack penuh";
        } else if (A[0] == '0') {
            A[0] = c;
            banyak++;
        } else {
            for (int i = banyak; i >= 0; i--)
                A[i + 1] = A[i];
            A[0] = c;
            banyak++;
        }

        cout << "\nIsi stack : ";
        for (int i = 0; i < banyak; i++)
            cout << A[i] << " ";
    }

    if (banyak == 0) {
        cout << "\nStack kosong";
    } else {
        cout << "\nPop stack, elemen yang di-pop : " << A[0];
        for (int i = 0; i < banyak; i++)
            A[i] = A[i + 1];
        A[banyak] = '0';
        banyak--;

        cout << "\nIsi stack : ";
        for (int i = 0; i < banyak; i++)
            cout << A[i] << " ";
    }

    cout << "\n\nCetak pakai ovrloading : ";
    cout << "\nIsi stack : ";
    for (int i = 0; i < banyak; i++)
        cout << A[i] << " ";

    return 0;
}
