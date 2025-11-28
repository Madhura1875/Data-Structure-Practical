#include <iostream>
using namespace std;

void generateOddMagicSquare(int n) {
    int magic[n][n];
    int i = 0, j = n / 2;

    for (int num = 1; num <= n * n; ) {
        if (i < 0 && j == n) { 
            i += 2;
            j--;
        } else {
            if (i < 0) i = n - 1;
            if (j == n) j = 0;
        }

        if (magic[i][j]) { 
            i += 2;
            j--;
            continue;
        } else
            magic[i][j] = num++;

        i--;
        j++;
    }

    cout << "\nMagic Square of Order " << n << ":\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << magic[i][j] << "\t";
        cout << endl;
    }

    cout << "\nMagic Constant = " << n * (n * n + 1) / 2 << endl;
}

void generateDoublyEvenMagicSquare(int n) {
    int magic[n][n], i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            magic[i][j] = (n * i) + j + 1;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if ((i % 4 == j % 4) || (i % 4 + j % 4 == 3))
                magic[i][j] = n * n + 1 - magic[i][j];

    cout << "\nMagic Square of Order " << n << ":\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << magic[i][j] << "\t";
        cout << endl;
    }

    cout << "\nMagic Constant = " << n * (n * n + 1) / 2 << endl;
}

int main() {
    int n;
    cout << "Enter order of magic square: ";
    cin >> n;

    if (n < 3) {
        cout << "Magic square not possible for n < 3.";
        return 0;
    }

    if (n % 2 == 1)
        generateOddMagicSquare(n);
    else if (n % 4 == 0)
        generateDoublyEvenMagicSquare(n);
    else
        cout << "Singly even order (like 6x6) not implemented.\n";

    return 0;
}

