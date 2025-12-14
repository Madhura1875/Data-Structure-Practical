#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    int marks;
    int roll;
};

vector<Student> a;
int n = 0;

// Function to display students
void displayStudents() {
    if (n == 0) {
        cout << "No student data available.\n";
        return;
    }

    cout << "\nRoll\tMarks\tName\n";
    for (int i = 0; i < n; i++) {
        cout << (a[i].roll == 0 ? i + 1 : a[i].roll)
             << "\t" << a[i].marks << "\t" << a[i].name << "\n";
    }
    cout << endl;
}

// Bubble Sort descending (with pass by pass)
void bubbleSortPassByPass() {
    if (n == 0) {
        cout << "No student data available.\n";
        return;
    }

    int totalSwaps = 0;

    cout << "\nStarting Bubble Sort (Descending - Topper first):\n\n";

    for (int pass = 1; pass <= n - 1; pass++) {
        int swaps = 0;

        for (int j = 0; j < n - pass; j++) {
            if (a[j].marks < a[j + 1].marks) {
                swap(a[j], a[j + 1]);
                swaps++;
            }
        }

        totalSwaps += swaps;

        // Display after each pass
        cout << "After Pass " << pass << " (Swaps = " << swaps << "):\n";
        cout << "Pos\tMarks\tName\n";
        for (int k = 0; k < n; k++) {
            cout << k + 1 << "\t" << a[k].marks << "\t" << a[k].name << "\n";
        }
        cout << endl;

        if (swaps == 0) {
            cout << "Array sorted early. No more passes needed.\n\n";
            break;
        }
    }

    cout << "Total swaps performed = " << totalSwaps << "\n";
}

// Assign roll numbers after sorting
void assignRollNumbers() {
    if (n == 0) {
        cout << "No student data available.\n";
        return;
    }

    for (int i = 0; i < n; i++)
        a[i].roll = i + 1;

    cout << "\nRoll numbers assigned successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n========= MENU =========\n";
        cout << "1. Enter Student Data\n";
        cout << "2. Display Students\n";
        cout << "3. Bubble Sort (Pass-by-Pass)\n";
        cout << "4. Assign Roll Numbers\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                cout << "Enter number of students: ";
                cin >> n;

                a.clear();
                a.resize(n);

                cin.ignore();
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter name of student " << i + 1 << ": ";
                    getline(cin, a[i].name);
                    cout << "Enter marks: ";
                    cin >> a[i].marks;
                    cin.ignore();
                    a[i].roll = 0;
                }
                break;
            }

            case 2:
                displayStudents();
                break;

            case 3:
                bubbleSortPassByPass();
                break;

            case 4:
                assignRollNumbers();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}

