#include <iostream>
#include <stack>

using namespace std;

void DeskripsiA() {
    cout << "Deskripsi A" << endl;
}

void DeskripsiB() {
    cout << "Deskripsi B" << endl;
}

void DeskripsiC() {
    cout << "Deskripsi C" << endl;
}

int main() {
    stack<void(*)()> forward, backward;
    forward.push(DeskripsiA);
    forward.push(DeskripsiB);
    forward.push(DeskripsiC);

    int pilihan;
    while (!forward.empty()) {
        void (*currentDeskripsi)() = forward.top();
        currentDeskripsi();

        cout << "Back/Next(0/1): ";
        cin >> pilihan;

        if (pilihan == 1 && forward.size() > 1) {
            backward.push(forward.top());
            forward.pop();
        } else if (pilihan == 0 && !backward.empty()) {
            forward.push(backward.top());
            backward.pop();
        } else {
            break;
        }
    }

    return 0;
}
