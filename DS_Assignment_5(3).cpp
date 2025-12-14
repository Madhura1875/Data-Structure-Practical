#include <iostream>
using namespace std;

#define SIZE 10
int arr[SIZE];
int top1 = -1, top2 = SIZE;

void push1(int x) {
    if (top1 + 1 == top2)
        cout << "Stack Overflow\n";
    else
        arr[++top1] = x;
}

void push2(int x) {
    if (top2 - 1 == top1)
        cout << "Stack Overflow\n";
    else
        arr[--top2] = x;
}

void pop1() {
    if (top1 == -1)
        cout << "Stack Underflow\n";
    else
        cout << "Popped: " << arr[top1--] << endl;
}

void pop2() {
    if (top2 == SIZE)
        cout << "Stack Underflow\n";
    else
        cout << "Popped: " << arr[top2++] << endl;
}

void display() {
    cout << "Stack1: ";
    for (int i = 0; i <= top1; i++) cout << arr[i] << " ";
    cout << "\nStack2: ";
    for (int i = SIZE - 1; i >= top2; i--) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int ch, x;
    do {
        cout << "\n1.Push Stack1\n2.Pop Stack1\n3.Push Stack2\n4.Pop Stack2\n5.Display\n0.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> x; push1(x); break;
            case 2: pop1(); break;
            case 3: cin >> x; push2(x); break;
            case 4: pop2(); break;
            case 5: display(); break;
        }
    } while (ch);
}

