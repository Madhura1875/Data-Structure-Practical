#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class HashTable {
    Node** table;
    int size;

public:
    HashTable(int s) {
        size = s;
        table = new Node*[size];
        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }

    int hash(int key) { return key % size; }

    void insert(int key) {
        int index = hash(key);
        Node* newNode = new Node{key, NULL};

        if (table[index] == NULL)
            table[index] = newNode;
        else {
            Node* temp = table[index];
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << " : ";
            Node* temp = table[i];
            while (temp) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht(10);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.insert(5);
    ht.display();
}

