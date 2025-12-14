#include <iostream>
using namespace std;

struct Node {
    int roll;
    Node* next;
};

Node *A = NULL, *B = NULL;

/* Insert node */
void insert(Node* &head, int roll) {
    Node* temp = new Node;
    temp->roll = roll;
    temp->next = head;
    head = temp;
}

/* Display list */
void display(Node* head) {
    while (head) {
        cout << head->roll << " ";
        head = head->next;
    }
    cout << endl;
}

/* Check if element exists */
bool exists(Node* head, int roll) {
    while (head) {
        if (head->roll == roll)
            return true;
        head = head->next;
    }
    return false;
}

/* Intersection A n B */
void intersection() {
    cout << "Students who like both Cricket and Football: ";
    Node* temp = A;
    while (temp) {
        if (exists(B, temp->roll))
            cout << temp->roll << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* Symmetric Difference */
void symmetricDifference() {
    cout << "Students who like either Cricket or Football but not both: ";

    Node* temp = A;
    while (temp) {
        if (!exists(B, temp->roll))
            cout << temp->roll << " ";
        temp = temp->next;
    }

    temp = B;
    while (temp) {
        if (!exists(A, temp->roll))
            cout << temp->roll << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* Neither Cricket nor Football */
void neither(int total) {
    cout << "Students who like neither Cricket nor Football: ";

    for (int i = 1; i <= total; i++) {
        if (!exists(A, i) && !exists(B, i))
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    int nA, nB, total, x;

    cout << "Enter total number of students: ";
    cin >> total;

    cout << "Enter number of students who like Cricket: ";
    cin >> nA;
    cout << "Enter roll numbers: ";
    for (int i = 0; i < nA; i++) {
        cin >> x;
        insert(A, x);
    }

    cout << "Enter number of students who like Football: ";
    cin >> nB;
    cout << "Enter roll numbers: ";
    for (int i = 0; i < nB; i++) {
        cin >> x;
        insert(B, x);
    }

    cout << "\nSet A (Cricket): ";
    display(A);

    cout << "Set B (Football): ";
    display(B);

    intersection();
    symmetricDifference();
    neither(total);

    return 0;
}

