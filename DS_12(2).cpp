#include <iostream>
#include <string>
using namespace std;

struct Faculty {
    int id;
    string name;
};

class HashTable {
    int size;
    Faculty* table;

public:
    HashTable(int s) {
        size = s;
        table = new Faculty[size];
        for (int i = 0; i < size; i++)
            table[i].id = -1;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insertRecord(int id, string name) {
        int index = hashFunction(id);

        if (table[index].id == -1) {
            table[index] = { id, name };
        }
        else {
            int existingHash = hashFunction(table[index].id);

            if (existingHash != index) {
                Faculty temp = table[index];
                table[index] = { id, name };

                insertRecord(temp.id, temp.name);
            } else {
                int i = (index + 1) % size;
                while (table[i].id != -1)
                    i = (i + 1) % size;
                table[i] = { id, name };
            }
        }
        cout << "Record Inserted Successfully!\n";
    }

    void searchRecord(int id) {
        int index = hashFunction(id);

        for (int i = 0; i < size; i++) {
            int pos = (index + i) % size;
            if (table[pos].id == id) {
                cout << "Faculty Found ? Name: " << table[pos].name << endl;
                return;
            }
        }
        cout << "Faculty Not Found\n";
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (table[i].id != -1)
                cout << table[i].id << " | " << table[i].name;
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(10);

    int choice, id;
    string name;

    do {
        cout << "\n--- Faculty DB (Linear Probing + Chaining WITH Replacement) ---\n";
        cout << "1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            ht.insertRecord(id, name);
            break;

        case 2:
            cout << "Enter ID: ";
            cin >> id;
            ht.searchRecord(id);
            break;

        case 3:
            ht.display();
            break;

        case 4:
            return 0;
        }
    } while (true);
}

