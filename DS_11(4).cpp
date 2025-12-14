#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
};

class HashTable {
    Student* table;
    int size;

public:
    HashTable(int s) {
        size = s;
        table = new Student[size];
        for (int i = 0; i < size; i++)
            table[i].roll = -1;
    }

    int hash(int roll) { return roll % size; }

    void insert(Student s) {
        int index = hash(s.roll);

        while (table[index].roll != -1) {
            index = (index + 1) % size;
        }
        table[index] = s;
    }

    void search(int roll) {
        int index = hash(roll);
        int start = index;

        while (table[index].roll != roll) {
            index = (index + 1) % size;
            if (index == start) {
                cout << "Student Not Found!\n";
                return;
            }
        }
        cout << "Found: " << table[index].roll << " - " << table[index].name << endl;
    }
};

int main() {
    HashTable ht(10);

    ht.insert({101, "Madhura"});
    ht.insert({111, "Rohit"});
    ht.insert({121, "Priya"});

    ht.search(111);
}

