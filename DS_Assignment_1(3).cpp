#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int **A, **B, **C;
int n;

/* Allocate memory */
void allocate() {
    A = new int*[n];
    B = new int*[n];
    C = new int*[n];

    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
    }
}

/* Free memory */
void deallocate() {
    for (int i = 0; i < n; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;
}

/* Input matrices */
void inputMatrices() {
    cout << "\nEnter elements of Matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "\nEnter elements of Matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];
}

/* Initialize result matrix */
void clearResult() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = 0;
}

/* Display matrix */
void displayResult() {
    cout << "\nResult Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
}

/* Row-major multiplication */
void multiplyRowMajor() {
    clearResult();
    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];

    auto end = high_resolution_clock::now();
    cout << "\nRow-Major Time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms\n";
}

/* Column-major multiplication */
void multiplyColumnMajor() {
    clearResult();
    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            for (int j = 0; j < n; j++)
                C[i][j] += A[i][k] * B[k][j];

    auto end = high_resolution_clock::now();
    cout << "\nColumn-Major Time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms\n";
}

/* Main menu */
int main() {
    int choice;

    cout << "Enter matrix size (n x n): ";
    cin >> n;

    allocate();
    inputMatrices();

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Multiply using Row-Major Order\n";
        cout << "2. Multiply using Column-Major Order\n";
        cout << "3. Display Result Matrix\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                multiplyRowMajor();
                break;

            case 2:
                multiplyColumnMajor();
                break;

            case 3:
                displayResult();
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    deallocate();
    return 0;
}

