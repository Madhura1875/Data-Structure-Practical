#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee {
    string name;
    float height, weight, avg;
};

// Function to calculate average
void calculateAvg(vector<Employee> &emp) {
    for (auto &e : emp) {
        e.avg = (e.height + e.weight) / 2.0;
    }
}

// Display employee list
void display(const vector<Employee> &emp) {
    cout << "\nName\tHeight\tWeight\tAverage\n";
    for (const auto &e : emp) {
        cout << e.name << "\t" << e.height << "\t" << e.weight << "\t" << e.avg << "\n";
    }
    cout << endl;
}

/*-------------------------------------------
       SELECTION SORT (ascending by avg)
--------------------------------------------*/
void selectionSort(vector<Employee> emp) {
    int n = emp.size();
    int swaps = 0, comparisons = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (emp[j].avg < emp[minIndex].avg)
                minIndex = j;
        }

        if (minIndex != i) {
            swap(emp[i], emp[minIndex]);
            swaps++;
        }
    }

    cout << "\n--- Selection Sort Result ---\n";
    display(emp);

    cout << "Time Complexity: O(n²)\n";
    cout << "Comparisons: " << comparisons << "\n";
    cout << "Swaps: " << swaps << "\n";
}

/*-------------------------------------------
       MERGE SORT (ascending by avg)
--------------------------------------------*/

// Merge two halves
void merge(vector<Employee> &emp, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Employee> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = emp[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = emp[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].avg <= R[j].avg) {
            emp[k] = L[i];
            i++;
        } else {
            emp[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        emp[k] = L[i];
        i++; k++;
    }

    while (j < n2) {
        emp[k] = R[j];
        j++; k++;
    }
}

// Recursive MergeSort
void mergeSort(vector<Employee> &emp, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(emp, left, mid);
        mergeSort(emp, mid + 1, right);
        merge(emp, left, mid, right);
    }
}

void mergeSortDisplay(vector<Employee> emp) {
    mergeSort(emp, 0, emp.size() - 1);

    cout << "\n--- Merge Sort Result ---\n";
    display(emp);

    cout << "Time Complexity: O(n log n)\n";
}

/*-------------------------------------------
                 MAIN MENU
--------------------------------------------*/
int main() {
    int choice, n;
    vector<Employee> emp;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Enter Employee Data\n";
        cout << "2. Display Employees\n";
        cout << "3. Sort using Selection Sort\n";
        cout << "4. Sort using Merge Sort\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                cout << "Enter number of employees: ";
                cin >> n;

                emp.resize(n);
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter name: ";
                    cin >> emp[i].name;
                    cout << "Enter height: ";
                    cin >> emp[i].height;
                    cout << "Enter weight: ";
                    cin >> emp[i].weight;
                }
                calculateAvg(emp);
                break;
            }

            case 2:
                if (emp.empty()) cout << "No data available!\n";
                else display(emp);
                break;

            case 3:
                if (emp.empty()) cout << "No data available!\n";
                else selectionSort(emp);
                break;

            case 4:
                if (emp.empty()) cout << "No data available!\n";
                else mergeSortDisplay(emp);
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

