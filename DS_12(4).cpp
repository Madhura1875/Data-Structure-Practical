#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    bool deleted;

    Student() {
        roll = -1;
        deleted = false;
    }
};

class HashTable {
    int size;
    Student* table;

public:
    HashTable(int s) {
        size = s;
        table = new Student[size];
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int roll, string name) {
        int index = hashFunction(roll);

        while (table[index].roll != -1 && !table[index].deleted)
            index = (index + 1) % size;

        table[index].roll = roll;
        table[index].name = name;
        table[index].deleted = false;

        cout << "Student Inserted\n";
    }

    void search(int roll) {
        int index = hashFunction(roll);

        for (int i = 0; i < size; i++) {
            int pos = (index + i) % size;

            if (table[pos].roll == roll && !table[pos].deleted) {
                cout << "Found ? " << table[pos].name << endl;
                return;
            }
        }
        cout << "Student Not Found\n";
    }

    void Delete(int roll) {
        int index = hashFunction(roll);

        for (int i = 0; i < size; i++) {
            int pos = (index + i) % size;

            if (table[pos].roll == roll) {
                table[pos].deleted = true;
                cout << "Deleted Successfully\n";
                return;
            }
        }
        cout << "Record Not Found\n";
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (table[i].roll != -1 && !table[i].deleted)
                cout << table[i].roll << " | " << table[i].name;
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(15);
    int ch, roll;
    string name;

    do {
        cout << "\n--- Student DB (Hashing: Insert, Search, Delete) ---\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter Roll: "; cin >> roll;
            cout << "Enter Name: "; cin >> name;
            ht.insert(roll, name);
            break;

        case 2:
            cout << "Enter Roll: "; cin >> roll;
            ht.search(roll);
            break;

        case 3:
            cout << "Enter Roll: "; cin >> roll;
            ht.Delete(roll);
            break;

        case 4:
            ht.display();
            break;

        case 5:
            return 0;
        }
    } while (true);
}

