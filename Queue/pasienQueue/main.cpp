#include <iostream>
#include <string>
#include "linkedQueue.h"
#include "myExceptions.h"

using namespace std;

class Patient {
public:
    Patient(const string& name, int age) : name(name), age(age) {}

    friend ostream& operator<<(ostream& os, const Patient& patient) {
        os << "Name: " << patient.name << ", Age: " << patient.age;
        return os;
    }

private:
    string name;
    int age;
};

int main() {
    try {
        LinkedQueue<Patient> patientQueue;

        // Add a few patients to the queue
        patientQueue.push(Patient("John Doe", 25));
        patientQueue.push(Patient("Jane Smith", 30));
        patientQueue.push(Patient("Bob Johnson", 45));

        cout << "Patient queue:" << endl;

        // Display the patient queue
        while (!patientQueue.empty()) {
            cout << "Queue front is " << patientQueue.front() << endl;
            patientQueue.pop();
            cout << "Popped front element" << endl;
        }

        // Try to pop from an empty queue
        try {
            patientQueue.pop();
        } catch (const QueueEmpty& message) {
            cout << "Last pop failed" << endl;
            message.outputMessage();
        }

    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
