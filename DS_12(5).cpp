#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    string company;
    bool deleted;

    Student() {
        id = -1;
        name = "";
        company = "";
        deleted = false;
    }
};

class PlacementPortal {
private:
    vector<Student> table;
    int currentSize;
    int capacity;

    int hash1(int key) {
        return key % capacity;
    }

    // Secondary hash function for double hashing
    int hash2(int key) {
        return 7 - (key % 7);
    }

    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }

    int nextPrime(int n) {
        while (!isPrime(n)) n++;
        return n;
    }

    // Dynamic Rehashing
    void rehash() {
        cout << "\n?? Rehashing… Expanding table size for better efficiency!\n";

        vector<Student> oldTable = table;
        capacity = nextPrime(capacity * 2);
        table.clear();
        table.resize(capacity);

        currentSize = 0;

        for (auto &s : oldTable) {
            if (s.id != -1 && !s.deleted)
                insertStudent(s.id, s.name, s.company, false);
        }
    }

public:
    PlacementPortal(int size = 10) {
        capacity = nextPrime(size);
        table.resize(capacity);
        currentSize = 0;
    }

    void insertStudent(int id, string name, string company, bool showMsg = true) {
        if ((currentSize * 1.0) / capacity > 0.6) {
            rehash();
        }

        int index = hash1(id);
        int step = hash2(id);

        int i = 0;
        while (true) {
            int pos = (index + i * step) % capacity;

            if (table[pos].id == -1 || table[pos].deleted) {
                table[pos].id = id;
                table[pos].name = name;
                table[pos].company = company;
                table[pos].deleted = false;
                currentSize++;
                if (showMsg) cout << "? Student inserted successfully!\n";
                return;
            }
            i++;
        }
    }

    void searchStudent(int id) {
        int index = hash1(id);
        int step = hash2(id);

        for (int i = 0; i < capacity; i++) {
            int pos = (index + i * step) % capacity;

            if (table[pos].id == id && !table[pos].deleted) {
                cout << "\n?? Student Found!\n";
                cout << "ID: " << table[pos].id << "\nName: " << table[pos].name
                     << "\nPlaced In: " << table[pos].company << endl;
                return;
            }
        }
        cout << "? Student not found.\n";
    }

    void deleteStudent(int id) {
        int index = hash1(id);
        int step = hash2(id);

        for (int i = 0; i < capacity; i++) {
            int pos = (index + i * step) % capacity;

            if (table[pos].id == id && !table[pos].deleted) {
                table[pos].deleted = true;
                cout << "? Record deleted successfully!\n";
                return;
            }
        }
        cout << "? Student not found.\n";
    }

    void display() {
        cout << "\n===== ?? PLACEMENT PORTAL TABLE =====\n";
        for (int i = 0; i < capacity; i++) {
            cout << i << ": ";

            if (table[i].id != -1 && !table[i].deleted) {
                cout << "[ID: " << table[i].id << ", Name: " << table[i].name
                     << ", Company: " << table[i].company << "]";
            } else {
                cout << "----";
            }
            cout << endl;
        }
    }
};

int main() {
    PlacementPortal portal(10);

    int choice, id;
    string name, company;

    while (true) {
        cout << "\n======= SMART COLLEGE PLACEMENT PORTAL =======\n";
        cout << "1. Insert Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display Placement Table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Placement Company: ";
            cin >> company;
            portal.insertStudent(id, name, company);
            break;

        case 2:
            cout << "Enter ID to search: ";
            cin >> id;
            portal.searchStudent(id);
            break;

        case 3:
            cout << "Enter ID to delete: ";
            cin >> id;
            portal.deleteStudent(id);
            break;

        case 4:
            portal.display();
            break;

        case 5:
            cout << "Thank you for using the Smart Placement Portal!\n";
            return 0;

        default:
            cout << "? Invalid option! Try again.\n";
        }
    }
}

