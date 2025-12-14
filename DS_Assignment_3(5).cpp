#include <iostream>
using namespace std;

struct Node {
    int bit;
    Node *prev, *next;
};

Node* head = NULL;
Node* tail = NULL;

/* Insert bit at end */
void insertBit(int b) {
    Node* temp = new Node;
    temp->bit = b;
    temp->next = NULL;

    if (!head) {
        temp->prev = NULL;
        head = tail = temp;
    } else {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

/* Display binary number */
void display(Node* h) {
    while (h) {
        cout << h->bit;
        h = h->next;
    }
    cout << endl;
}

/* 1's Complement */
void onesComplement() {
    Node* temp = head;
    while (temp) {
        temp->bit = (temp->bit == 0) ? 1 : 0;
        temp = temp->next;
    }
}

/* 2's Complement */
void twosComplement() {
    onesComplement();

    Node* temp = tail;
    int carry = 1;

    while (temp && carry) {
        int sum = temp->bit + carry;
        temp->bit = sum % 2;
        carry = sum / 2;
        temp = temp->prev;
    }
}

/* Add two binary numbers */
Node* addBinary(Node* h1, Node* h2) {
    Node *t1 = h1, *t2 = h2;
    while (t1 && t1->next) t1 = t1->next;
    while (t2 && t2->next) t2 = t2->next;

    Node* resHead = NULL;
    int carry = 0;

    while (t1 || t2 || carry) {
        int sum = carry;
        if (t1) { sum += t1->bit; t1 = t1->prev; }
        if (t2) { sum += t2->bit; t2 = t2->prev; }

        Node* temp = new Node;
        temp->bit = sum % 2;
        temp->prev = NULL;
        temp->next = resHead;

        if (resHead)
            resHead->prev = temp;

        resHead = temp;
        carry = sum / 2;
    }
    return resHead;
}

int main() {
    int n, b;

    cout << "Enter number of bits: ";
    cin >> n;
    cout << "Enter binary number: ";
    for (int i = 0; i < n; i++) {
        cin >> b;
        insertBit(b);
    }

    cout << "\nOriginal Binary Number: ";
    display(head);

    Node* copyHead = head;

    onesComplement();
    cout << "1's Complement: ";
    display(head);

    twosComplement();
    cout << "2's Complement: ";
    display(head);

    /* Second number for addition */
    Node* head2 = NULL;
    Node* tail2 = NULL;

    cout << "\nEnter bits for second binary number: ";
    for (int i = 0; i < n; i++) {
        cin >> b;
        Node* temp = new Node;
        temp->bit = b;
        temp->next = NULL;
        temp->prev = tail2;

        if (!head2)
            head2 = tail2 = temp;
        else {
            tail2->next = temp;
            tail2 = temp;
        }
    }

    Node* result = addBinary(copyHead, head2);
    cout << "Addition Result: ";
    display(result);

    return 0;
}

