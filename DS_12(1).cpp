#include <iostream>
#include <string>
using namespace std;

struct Faculty {
    int id;
    string name;
    Faculty* next;

    Faculty(int i, string n) {
        id = i;
        name = n;
        next = nullptr;
    }
};

class HashTable {
    int size;
    Faculty** table;

public:
    HashTable(int s) {
        size = s;
        table = new Faculty*[size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insertRecord(int id, string name) {
        int index = hashFunction(id);

        Faculty* newNode = new Faculty(id, name);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Faculty* temp = table[index];
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Record inserted successfully!\n";
    }

    void searchRecord(int id) {
        int index = hashFunction(id);

        Faculty* temp = table[index];
        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "Faculty Found ? Name: " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Faculty Not Found!\n";
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Faculty* temp = table[i];
            while (temp != nullptr) {
                cout << "[" << temp->id << "|" << temp->name << "] -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht(10);
    int choice, id;
    string name;

    do {
        cout << "\n--- Faculty Hash Table (Linear Probing + Chaining Without Replacement) ---\n";
        cout << "1. Insert Faculty\n2. Search Faculty\n3. Display Table\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Faculty ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            ht.insertRecord(id, name);
            break;

        case 2:
            cout << "Enter Faculty ID to search: ";
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

