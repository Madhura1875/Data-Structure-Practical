#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int marks;
    Node* left;
    Node* right;
};

Node* createNode(string name, int marks) {
    Node* t = new Node;
    t->name = name;
    t->marks = marks;
    t->left = t->right = NULL;
    return t;
}

// Insert based on marks (higher marks ? left)
Node* insertNode(Node* root, string name, int marks) {
    if (!root) return createNode(name, marks);

    if (marks > root->marks)
        root->left = insertNode(root->left, name, marks);
    else
        root->right = insertNode(root->right, name, marks);

    return root;
}

// Assign roll numbers using inorder (descending marks)
void assignRoll(Node* root, int &roll) {
    if (!root) return;

    assignRoll(root->left, roll);
    cout << "Roll No: " << roll++ << "  Name: " << root->name 
         << "  Marks: " << root->marks << endl;
    assignRoll(root->right, roll);
}

int main() {
    Node* root = NULL;
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    string name;
    int marks;

    for (int i = 0; i < n; i++) {
        cout << "Enter Name & Marks: ";
        cin >> name >> marks;
        root = insertNode(root, name, marks);
    }

    int roll = 1;
    cout << "\nAssigned Roll Numbers:\n";
    assignRoll(root, roll);

    return 0;
}

