#include <iostream>
#include <string>
using namespace std;

struct Faculty {
    int id;
    string name;
    string dept;
};

class FacultyDB {
    Faculty* table;
    int size;

public:
    FacultyDB(int s) {
        size = s;
        table = new Faculty[size];
        for (int i = 0; i < size; i++)
            table[i].id = -1;
    }

    int hash(int id) { return id % size; }

    void insert(Faculty f) {
        int index = hash(f.id);

        while (table[index].id != -1) {
            index = (index + 1) % size; // Linear probing
        }
        table[index] = f;
    }

    void search(int id) {
        int index = hash(id);
        int start = index;

        while (table[index].id != id) {
            index = (index + 1) % size;
            if (index == start) {
                cout << "Faculty NOT Found!\n";
                return;
            }
        }

        cout << "\nFaculty Found:\n";
        cout << "ID: " << table[index].id << endl;
        cout << "Name: " << table[index].name << endl;
        cout << "Department: " << table[index].dept << endl;
    }
};

int main() {
    FacultyDB db(10);

    // inserting sample data
    db.insert({101, "Dr. Sharma", "Computer"});
    db.insert({111, "Dr. Patil", "IT"});
    db.insert({121, "Dr. Shetty", "ENTC"});

    int id;
    cout << "Enter Faculty ID to Search: ";
    cin >> id;

    db.search(id);
}

