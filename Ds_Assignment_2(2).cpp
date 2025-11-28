#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int roll;
    int marks;
};

// Function to swap student structures
void swapStudents(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

// ------------------- BUBBLE SORT -------------------
int bubbleSort(Student s[], int n) {
    int swapCount = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].roll > s[j + 1].roll) {
                swapStudents(s[j], s[j + 1]);
                swapCount++;
            }
        }
    }

    return swapCount;
}

// ------------------- QUICK SORT -------------------
int quickSwapCount = 0;

int partitionFunc(Student s[], int low, int high) {
    int pivot = s[high].roll;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (s[j].roll < pivot) {
            i++;
            swapStudents(s[i], s[j]);
            quickSwapCount++;
        }
    }

    swapStudents(s[i + 1], s[high]);
    quickSwapCount++;

    return (i + 1);
}

void quickSort(Student s[], int low, int high) {
    if (low < high) {
        int pi = partitionFunc(s, low, high);
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, high);
    }
}

// ------------------- DISPLAY -------------------
void display(Student s[], int n) {
    cout << "\nRoll\tName\tMarks\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].roll << "\t" << s[i].name << "\t" << s[i].marks << "\n";
    }
}

int main() {
    int n, choice;
    Student S[50], temp[50];

    cout << "Enter number of students: ";
    cin >> n;

    cout << "\nEnter student details:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> S[i].name;
        cout << "Roll No.: ";
        cin >> S[i].roll;
        cout << "Total Marks: ";
        cin >> S[i].marks;
    }

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Bubble Sort (by Roll No)\n";
        cout << "2. Quick Sort (by Roll No)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 3)
            break;

        // Copy original array into temp each time
        for (int i = 0; i < n; i++)
            temp[i] = S[i];

        switch (choice) {
            case 1: {
                int swaps = bubbleSort(temp, n);
                cout << "\nSorted using Bubble Sort:\n";
                display(temp, n);
                cout << "\nTotal Swaps (Bubble Sort) = " << swaps << "\n";
                break;
            }

            case 2: {
                quickSwapCount = 0;
                quickSort(temp, 0, n - 1);
                cout << "\nSorted using Quick Sort:\n";
                display(temp, n);
                cout << "\nTotal Swaps (Quick Sort) = " << quickSwapCount << "\n";
                break;
            }

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}

