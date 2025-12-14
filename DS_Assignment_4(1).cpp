#include <iostream>
using namespace std;

struct GLL {
    int tag;          // 0 = atom, 1 = list
    char atom;
    GLL *down, *next;
};

GLL* createAtom(char ch) {
    GLL* t = new GLL();
    t->tag = 0;
    t->atom = ch;
    t->down = t->next = NULL;
    return t;
}

GLL* createList() {
    GLL* t = new GLL();
    t->tag = 1;
    t->down = t->next = NULL;
    return t;
}

void display(GLL* head) {
    cout << "{";
    while (head) {
        if (head->tag == 0)
            cout << head->atom;
        else
            display(head->down);

        if (head->next)
            cout << ", ";
        head = head->next;
    }
    cout << "}";
}

int main() {
    GLL* head = NULL;
    GLL* last = NULL;
    int n;
    char ch;

    cout << "Enter number of atomic elements in set: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element: ";
        cin >> ch;
        GLL* temp = createAtom(ch);
        if (!head) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }

    cout << "\nSet Representation:\n";
    display(head);
    return 0;
}

