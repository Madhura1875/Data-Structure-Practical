#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> passengers;     // queue to store passenger names
    int choice;
    string name;

    do {
        cout << "\n--- Ticket Agent Queue System ---\n";
        cout << "1. Add Passenger to Queue\n";
        cout << "2. View Front Passenger\n";
        cout << "3. Remove Front Passenger\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Passenger Name: ";
            cin >> name;
            passengers.push(name);
            cout << name << " added to queue.\n";
            break;

        case 2:
            if (!passengers.empty()) {
                cout << "Front Passenger: " << passengers.front() << endl;
            } else {
                cout << "Queue is empty!\n";
            }
            break;

        case 3:
            if (!passengers.empty()) {
                cout << "Removing Passenger: " << passengers.front() << endl;
                passengers.pop();
            } else {
                cout << "No passengers to remove!\n";
            }
            break;

        case 4:
            cout << "\nProgram ending...\n";
            cout << "Passengers left in queue: " << passengers.size() << endl;
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

