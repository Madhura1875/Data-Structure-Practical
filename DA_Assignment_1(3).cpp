#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define MAX 100

// Row-major matrix multiplication
void rowMajorMultiply(int A[][MAX], int B[][MAX], int C[][MAX], int n) {
    for (int i = 0; i < n; i++) {                // row of A
        for (int j = 0; j < n; j++) {            // column of B
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {        // common dimension
                C[i][j] += A[i][k] * B[k][j];   // row-major access
            }
        }
    }
}

// Column-major access matrix multiplication
void colMajorMultiply(int A[][MAX], int B[][MAX], int C[][MAX], int n) {
    for (int i = 0; i < n; i++) {               // row of A
        for (int j = 0; j < n; j++) {           // column of B
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {       // common dimension
                C[i][j] += A[k][i] * B[j][k];  // column-major access (BAD LOCALITY)
            }
        }
    }
}

int main() {
    int n, choice;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    while (true) {
        cout << "\n===== MATRIX MULTIPLICATION MENU =====\n";
        cout << "1. Row-Major Order Multiplication\n";
        cout << "2. Column-Major Order Multiplication\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 3)
            break;

        cout << "Enter size of matrix (n x n): ";
        cin >> n;

        cout << "Enter Matrix A:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];

        cout << "Enter Matrix B:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> B[i][j];

        auto start = high_resolution_clock::now();

        if (choice == 1) {
            rowMajorMultiply(A, B, C, n);
        } else if (choice == 2) {
            colMajorMultiply(A, B, C, n);
        } else {
            cout << "Invalid choice!\n";
            continue;
        }

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        cout << "\nResult Matrix C:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\nExecution Time = " << duration.count() << " microseconds\n";
    }

    return 0;
}

