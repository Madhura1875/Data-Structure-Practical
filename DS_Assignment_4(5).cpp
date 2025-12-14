#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& head, int x) {
    Node* t = new Node{x, head};
    head = t;
}

void FrontBackSplit(Node* source, Node*& front, Node*& back) {
    if (!source || !source->next) {
        front = source;
        back = NULL;
        return;
    }

    Node *slow = source, *fast = source->next;
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    front = source;
    back = slow->next;
    slow->next = NULL;
}

void display(Node* h) {
    while (h) {
        cout << h->data << " ";
        h = h->next;
    }
}

int main() {
    Node* head = NULL;
    Node *front = NULL, *back = NULL;
    int ch, x;

    do {
        cout << "\n1.Insert\n2.Split\n3.Display Front & Back\n0.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> x; push(head, x); break;
            case 2: FrontBackSplit(head, front, back); break;
            case 3:
                cout << "Front List: ";
                display(front);
                cout << "\nBack List: ";
                display(back);
        }
    } while (ch);
}

