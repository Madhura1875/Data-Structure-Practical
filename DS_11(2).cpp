#include <iostream>
#include <list>
using namespace std;

class HashTable {
    int size;
    list<int>* table;

public:
    HashTable(int s) {
        size = s;
        table = new list<int>[size];
    }

    int hash(int key) { return key % size; }

    void insert(int key) {
        int index = hash(key);
        table[index].push_back(key);  // chaining
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << " : ";
            for (int x : table[i])
                cout << x << " -> ";
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht(10);
    ht.insert(11);
    ht.insert(21);
    ht.insert(31);
    ht.insert(4);
    ht.insert(14);

    ht.display();
}

