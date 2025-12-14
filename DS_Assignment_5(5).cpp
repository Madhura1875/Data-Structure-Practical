#include <iostream>
#include <stack>
using namespace std;

int apply(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int main() {
    string postfix;
    stack<int> st;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    for (char c : postfix) {
        if (isdigit(c))
            st.push(c - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(apply(a, b, c));
        }
    }

    cout << "Result = " << st.top() << endl;
}

