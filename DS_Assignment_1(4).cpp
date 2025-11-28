#include <iostream>
using namespace std;

#define MAX 50   // Maximum non-zero elements

// Structure for sparse matrix in triplet form
struct Sparse {
    int row;
    int col;
    int value;
};

// Convert normal matrix ? sparse representation
int createSparse(int a[][10], Sparse s[], int r, int c) {
    int k = 1;  // index starts from 1 (0th index stores header)

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] != 0) {
                s[k].row = i;
                s[k].col = j;
                s[k].value = a[i][j];
                k++;
            }
        }
    }

    // Header information
    s[0].row = r;
    s[0].col = c;
    s[0].value = k - 1;

    return k;
}

// Display sparse matrix
void displaySparse(Sparse s[]) {
    cout << "\nRow\tCol\tValue\n";
    int n = s[0].value;

    for (int i = 0; i <= n; i++) {
        cout << s[i].row << "\t" << s[i].col << "\t" << s[i].value << "\n";
    }
}

// Simple Transpose of Sparse Matrix
void simpleTranspose(Sparse s[], Sparse t[]) {
    int n = s[0].value;

    // Header
    t[0].row = s[0].col;
    t[0].col = s[0].row;
    t[0].value = n;

    int k = 1;

    // Traverse column-wise
    for (int col = 0; col < s[0].col; col++) {
        for (int i = 1; i <= n; i++) {
            if (s[i].col == col) {
                t[k].row = s[i].col;
                t[k].col = s[i].row;
                t[k].value = s[i].value;
                k++;
            }
        }
    }
}

int main() {
    int r, c, choice;
    int a[10][10];
    Sparse s[MAX], t[MAX];
    int count;

    while (true) {
        cout << "\n===== SPARSE MATRIX MENU =====\n";
        cout << "1. Input Matrix\n";
        cout << "2. Display Sparse Matrix (Triplet Form)\n";
        cout << "3. Simple Transpose\n";
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
                        cin >> a[i][j];

                count = createSparse(a, s, r, c);

                cout << "\nSparse Matrix Created Successfully!\n";
                break;

            case 2:
                cout << "\nSparse Matrix (Triplet Representation):\n";
                displaySparse(s);
                break;

            case 3:
                simpleTranspose(s, t);
                cout << "\nTranspose (Simple Method):\n";
                displaySparse(t);
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid Choice!\n";
        }
    }

    return 0;
}

