#include <iostream>
using namespace std;

#define MAX 50   // Maximum non-zero elements

// Structure for sparse matrix term
struct Sparse {
    int row, col, value;
};

// Convert normal matrix to sparse matrix (triplet form)
int createSparse(int A[][10], Sparse S[], int r, int c) {
    int k = 1;   // Start filling from index 1 (0 is header)

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (A[i][j] != 0) {
                S[k].row = i;
                S[k].col = j;
                S[k].value = A[i][j];
                k++;
            }
        }
    }

    // Header
    S[0].row = r;
    S[0].col = c;
    S[0].value = k - 1;

    return k - 1;   // Number of non-zero terms
}

// Display sparse matrix
void displaySparse(Sparse S[]) {
    int n = S[0].value;

    cout << "\nRow\tCol\tValue\n";
    for (int i = 0; i <= n; i++) {
        cout << S[i].row << "\t" << S[i].col << "\t" << S[i].value << "\n";
    }
}

// FAST TRANSPOSE
void fastTranspose(Sparse S[], Sparse T[]) {
    int r = S[0].row;
    int c = S[0].col;
    int n = S[0].value;

    // Header for transpose
    T[0].row = c;
    T[0].col = r;
    T[0].value = n;

    if (n > 0) {
        int row_terms[10] = {0};   // Count of terms in each column of original
        int start_pos[10] = {0};   // Starting position of each column in transpose

        // Step 1: Count number of elements in each column of S
        for (int i = 1; i <= n; i++)
            row_terms[S[i].col]++;

        // Step 2: Compute starting positions
        start_pos[0] = 1;
        for (int i = 1; i < c; i++)
            start_pos[i] = start_pos[i - 1] + row_terms[i - 1];

        // Step 3: Place elements in T in sorted column manner
        for (int i = 1; i <= n; i++) {
            int col = S[i].col;
            int pos = start_pos[col];

            T[pos].row = S[i].col;
            T[pos].col = S[i].row;
            T[pos].value = S[i].value;

            start_pos[col]++;  // Move to next open slot
        }
    }
}

int main() {
    int r, c, choice;
    int A[10][10];
    Sparse S[MAX], T[MAX];
    int nonZero;

    while (true) {
        cout << "\n===== FAST TRANSPOSE MENU =====\n";
        cout << "1. Input Matrix\n";
        cout << "2. Display Sparse Matrix\n";
        cout << "3. Fast Transpose\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter rows and columns: ";
                cin >> r >> c;

                cout << "Enter matrix elements:\n";
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        cin >> A[i][j];

                nonZero = createSparse(A, S, r, c);

                cout << "\nSparse Matrix created successfully!\n";
                break;

            case 2:
                cout << "\nSparse Matrix (Triplet Form):\n";
                displaySparse(S);
                break;

            case 3:
                fastTranspose(S, T);
                cout << "\nFast Transpose Result:\n";
                displaySparse(T);
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

