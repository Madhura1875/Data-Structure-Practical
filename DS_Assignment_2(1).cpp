#include <iostream>
#include <string>
using namespace std;

struct Student {
    string year;
    string division;
    string name;
    int roll;
};

int main() {
    int n;
    cout << "Enter total number of students: ";
    cin >> n;

    Student s[n];

    cout << "\nEnter details of students:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Year (SY/TY/BTech): ";
        cin >> s[i].year;
        cout << "Division: ";
        cin >> s[i].division;
        cout << "Name: ";
        cin >> s[i].name;
        cout << "Roll No.: ";
        cin >> s[i].roll;
    }

    // Target student details
    string targetYear = "SY";
    string targetDiv = "X";
    string targetName = "XYZ";
    int targetRoll = 17;

    // Linear search
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (s[i].year == targetYear &&
            s[i].division == targetDiv &&
            s[i].name == targetName &&
            s[i].roll == targetRoll) {

            cout << "\nStudent FOUND at position " << (i + 1) << "!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent NOT FOUND!\n";
    }

    return 0;
}

