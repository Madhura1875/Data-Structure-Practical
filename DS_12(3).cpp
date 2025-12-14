#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
};

class HashTable {
    int size;
    Employee* table;

public:
    HashTable(int s) {
        size = s;
        table = new Employee[size];
        for (int i = 0; i < size; i++)
            table[i].id = -1;
    }

    int midSquareHash(int key) {
        long long sq = (long long)key * key;
        sq = (sq / 10) % 1000;  
        return sq % size;
    }

    void insert(int id, string name) {
        int index = midSquareHash(id);

        while (table[index].id != -1)
            index = (index + 1) % size;

        table[index] = { id, name };
        cout << "Inserted!\n";
    }

    void search(int id) {
        int index = midSquareHash(id);

        for (int i = 0; i < size; i++) {
            int pos = (index + i) % size;
            if (table[pos].id == id) {
                cout << "Employee Found ? " << table[pos].name << endl;
                return;
            }
        }
        cout << "Employee Not Found\n";
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
    HashTable ht(20);
    int ch, id;
    string name;

    do {
        cout << "\n--- Employee DB (Mid-Square Hashing) ---\n";
        cout << "1. Insert\n2. Search\n3. Display\n4. Exit\n";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Name: "; cin >> name;
            ht.insert(id, name);
            break;

        case 2:
            cout << "Enter ID: "; cin >> id;
            ht.search(id);
            break;

        case 3:
            ht.display();
            break;

        case 4:
            return 0;
        }
    } while (true);
}

