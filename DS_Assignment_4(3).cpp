#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

void insert(Node*& head, int x) {
    Node* t = new Node{x, NULL, head};
    if (head) head->prev = t;
    head = t;
}

void bubbleSort(Node* head) {
    for (Node* i = head; i; i = i->next)
        for (Node* j = head; j->next; j = j->next)
            if (j->data > j->next->data)
                swap(j->data, j->next->data);
}

void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    int ch, x;

    do {
        cout << "\n1.Insert\n2.Sort\n3.Display\n0.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> x; insert(head, x); break;
            case 2: bubbleSort(head); break;
            case 3: display(head); break;
        }
    } while (ch);
}

