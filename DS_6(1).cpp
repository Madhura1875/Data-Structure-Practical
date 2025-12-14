#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> patientQueue;   // Queue to store patients
    int choice;
    string name;

    while (true) {
        cout << "\n--- Medical Clinic System ---\n";
        cout << "1. Check-in Patient\n";
        cout << "2. Assign Patient to Doctor\n";
        cout << "3. View Waiting Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter patient name: ";
            cin >> name;
            patientQueue.push(name);
            cout << "Patient " << name << " checked in successfully.\n";
            break;

        case 2:
            if (!patientQueue.empty()) {
                cout << "Doctor is now seeing: " << patientQueue.front() << endl;
                patientQueue.pop();
            } else {
                cout << "No patients waiting.\n";
            }
            break;

        case 3:
            if (patientQueue.empty()) {
                cout << "No patients in the waiting list.\n";
            } else {
                cout << "Patients in queue: ";
                queue<string> temp = patientQueue; // Copy for display
                while (!temp.empty()) {
                    cout << temp.front() << " ";
                    temp.pop();
                }
                cout << endl;
            }
            break;

        case 4:
            cout << "Exiting system. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

