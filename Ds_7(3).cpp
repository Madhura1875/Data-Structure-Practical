#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int val) {
    Node* n = new Node(); 
    n->data = val; 
    n->left = n->right = NULL;
    return n;
}

Node* insertNode(Node* root, int val) {
    if (!root) return createNode(val);
    if (val < root->data) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);
    return root;
}

int findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int main() {
    Node* root = NULL;
    int val, choice;

    do {
        cout << "\n1.Insert\n2.Find Min\n3.Find Max\n4.Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; root = insertNode(root, val); break;
        case 2: cout << "Minimum: " << findMin(root) << endl; break;
        case 3: cout << "Maximum: " << findMax(root) << endl; break;
        }
    } while (choice != 4);

    return 0;
}

