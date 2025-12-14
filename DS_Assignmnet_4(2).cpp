#include <iostream>
using namespace std;

struct Poly {
    int coef, exp;
    Poly* next;
};

void insert(Poly*& head, int c, int e) {
    Poly* t = new Poly{c, e, NULL};
    if (!head || head->exp < e) {
        t->next = head;
        head = t;
    } else {
        Poly* p = head;
        while (p->next && p->next->exp > e)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void display(Poly* p) {
    while (p) {
        cout << p->coef << "x^" << p->exp;
        if (p->next) cout << " + ";
        p = p->next;
    }
}

void addPoly(Poly* p1, Poly* p2, Poly*& res) {
    while (p1 && p2) {
        if (p1->exp == p2->exp) {
            insert(res, p1->coef + p2->coef, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            insert(res, p1->coef, p1->exp);
            p1 = p1->next;
        } else {
            insert(res, p2->coef, p2->exp);
            p2 = p2->next;
        }
    }
    while (p1) { insert(res, p1->coef, p1->exp); p1 = p1->next; }
    while (p2) { insert(res, p2->coef, p2->exp); p2 = p2->next; }
}

int main() {
    Poly *p1 = NULL, *p2 = NULL, *res = NULL;
    int n, c, e;

    cout << "Enter number of terms in Polynomial 1: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> e;
        insert(p1, c, e);
    }

    cout << "Enter number of terms in Polynomial 2: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> e;
        insert(p2, c, e);
    }

    addPoly(p1, p2, res);

    cout << "\nResultant Polynomial: ";
    display(res);
}

