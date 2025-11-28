#include <iostream>
using namespace std;

// ---------- PRINT ARRAY ----------
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// ---------- DIVIDE & CONQUER MIN/MAX ----------
void findMinMax(int a[], int low, int high, int &minVal, int &maxVal) {
    // If only one element
    if (low == high) {
        if (a[low] < minVal) minVal = a[low];
        if (a[low] > maxVal) maxVal = a[low];
        return;
    }

    // If two elements
    if (high == low + 1) {
        if (a[low] < a[high]) {
            if (a[low] < minVal) minVal = a[low];
            if (a[high] > maxVal) maxVal = a[high];
        } else {
            if (a[high] < minVal) minVal = a[high];
            if (a[low] > maxVal) maxVal = a[low];
        }
        return;
    }

    // Divide array into halves
    int mid = (low + high) / 2;

    findMinMax(a, low, mid, minVal, maxVal);
    findMinMax(a, mid + 1, high, minVal, maxVal);
}

// ---------- QUICK SORT WITH PASS-BY-PASS ----------
int passNum = 1;

int partitionFunc(int a[], int low, int high, int n) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            // swap
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Final swap
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    cout << "Pass " << passNum++ << ": ";
    printArray(a, n);

    return (i + 1);
}

void quickSort(int a[], int low, int high, int n) {
    if (low < high) {
        int p = partitionFunc(a, low, high, n);
        quickSort(a, low, p - 1, n);
        quickSort(a, p + 1, high, n);
    }
}

// --------------------- MAIN ---------------------
int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int a[n];
    cout << "Enter marks of students:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nOriginal Marks: ";
    printArray(a, n);

    // Quick Sort with pass analysis
    quickSort(a, 0, n - 1, n);

    cout << "\nSorted Marks (Ascending): ";
    printArray(a, n);

    // Find min and max using divide & conquer
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    findMinMax(a, 0, n - 1, minVal, maxVal);

    cout << "\nMinimum Marks = " << minVal;
    cout << "\nMaximum Marks = " << maxVal << endl;

    return 0;
}

