#include <iostream>
using namespace std;

class HashTable {
    int *table;
    int size;

public:
    HashTable(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1;   // -1 means empty
    }

    int hash(int key) { return key % size; }

    void insert(int key) {
        int index = hash(key);
        int start = index;

        while (table[index] != -1) {
            index = (index + 1) % size;   // linear probing
            if (index == start) {
                cout << "Hash Table Full!\n";
                return;
            }
        }
        table[index] = key;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << "Index " << i << " : " << table[i] << endl;
    }
};

int main() {
    HashTable ht(10);
    ht.insert(12);
    ht.insert(22);
    ht.insert(32);
    ht.insert(42);

    ht.display();
}

