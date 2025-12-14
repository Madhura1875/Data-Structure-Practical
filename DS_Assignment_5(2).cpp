#include <iostream>
#include <stack>
using namespace std;

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    string infix, postfix = "";
    stack<char> s;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
            cout << "Output: " << postfix << endl;
        }
        else {
            while (!s.empty() && priority(s.top()) >= priority(c)) {
                postfix += s.top();
                s.pop();
                cout << "Pop from stack\n";
            }
            s.push(c);
            cout << "Push " << c << endl;
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix Expression: " << postfix << endl;
}

