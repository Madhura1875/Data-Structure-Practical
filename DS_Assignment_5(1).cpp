#include <iostream>
using namespace std;

struct Node {
    int price;
    Node* next;
};

Node* top = NULL;

void record(int price) {
    Node* t = new Node{price, top};
    top = t;
    cout << "Price recorded.\n";
}

void removePrice() {
    if (!top) {
        cout << "Stack Empty.\n";
        return;
    }
    Node* t = top;
    cout << "Removed Price: " << t->price << endl;
    top = top->next;
    delete t;
}

void latest() {
    if (!top)
        cout << "No prices available.\n";
    else
        cout << "Latest Price: " << top->price << endl;
}

void isEmpty() {
    cout << (top == NULL ? "Stack is Empty\n" : "Stack is Not Empty\n");
}

int main() {
    int ch, price;
    do {
        cout << "\n1.Record Price\n2.Remove Price\n3.Latest Price\n4.Is Empty\n0.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> price; record(price); break;
            case 2: removePrice(); break;
            case 3: latest(); break;
            case 4: isEmpty(); break;
        }
    } while (ch);
}

