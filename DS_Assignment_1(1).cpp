#include <iostream>
using namespace std;

// Function to calculate length of string
int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to copy string
void stringCopy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Function to reverse string
void stringReverse(char str[]) {
    int len = stringLength(str);
    int i = 0, j = len - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to concatenate two strings
void stringConcat(char str1[], char str2[]) {
    int len1 = stringLength(str1);
    int i = 0;

    while (str2[i] != '\0') {
        str1[len1 + i] = str2[i];
        i++;
    }
    str1[len1 + i] = '\0';
}

int main() {
    char str1[100], str2[100], temp[100];
    int choice;

    while (true) {
        cout << "\n===== STRING OPERATIONS MENU =====";
        cout << "\n1. Length of String";
        cout << "\n2. Copy String";
        cout << "\n3. Reverse String";
        cout << "\n4. Concatenate Strings";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a string: ";
                cin.ignore();
                cin.getline(str1, 100);
                cout << "Length = " << stringLength(str1) << endl;
                break;

            case 2:
                cout << "Enter string to copy: ";
                cin.ignore();
                cin.getline(str1, 100);
                stringCopy(temp, str1);
                cout << "Copied String = " << temp << endl;
                break;

            case 3:
                cout << "Enter a string: ";
                cin.ignore();
                cin.getline(str1, 100);
                stringReverse(str1);
                cout << "Reversed String = " << str1 << endl;
                break;

            case 4:
                cout << "Enter first string: ";
                cin.ignore();
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                stringConcat(str1, str2);
                cout << "Concatenated String = " << str1 << endl;
                break;

            case 5:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

