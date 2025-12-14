#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = NULL;

void insertBegin(int x) {
    Node* t = new Node{x, NULL, head};
    if (head) head->prev = t;
    head = t;
}

void insertEnd(int x) {
    Node* t = new Node{x, NULL, NULL};
    if (!head) { head = t; return; }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = t;
    t->prev = p;
}

void deleteBegin() {
    if (!head) return;
    Node* t = head;
    head = head->next;
    if (head) head->prev = NULL;
    delete t;
}

void deleteEnd() {
    if (!head) return;
    Node* p = head;
    while (p->next) p = p->next;
    if (p->prev) p->prev->next = NULL;
    else head = NULL;
    delete p;
}

void display() {
    Node* p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    int ch, x;
    do {
        cout << "\n1.Insert Begin\n2.Insert End\n3.Delete Begin\n4.Delete End\n5.Display\n0.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> x; insertBegin(x); break;
            case 2: cin >> x; insertEnd(x); break;
            case 3: deleteBegin(); break;
            case 4: deleteEnd(); break;
            case 5: display(); break;
        }
    } while (ch);
}

