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

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int leafCount(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return leafCount(root->left) + leafCount(root->right);
}

Node* mirror(Node* root) {
    if (!root) return NULL;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
    return root;
}

int main() {
    Node* root = NULL;
    int val, choice;

    do {
        cout << "\n1.Insert\n2.Inorder\n3.Preorder\n4.Leaf Count\n5.Mirror Image\n6.Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cin >> val; root = insertNode(root, val); break;
        case 2: inorder(root); cout << endl; break;
        case 3: preorder(root); cout << endl; break;
        case 4: cout << "Leaf Nodes: " << leafCount(root) << endl; break;
        case 5: mirror(root); cout << "Mirror Created.\n"; break;
        }
    } while (choice != 6);

    return 0;
}

