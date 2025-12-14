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

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
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

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int val, choice;

    do {
        cout << "\n1.Insert\n2.Count Nodes\n3.Height\n4.Mirror Image\n5.Display Inorder\n6.Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; root = insertNode(root, val); break;
        case 2: cout << "Total Nodes: " << countNodes(root) << endl; break;
        case 3: cout << "Height: " << height(root) << endl; break;
        case 4: mirror(root); cout << "Mirror Created.\n"; break;
        case 5: inorder(root); cout << endl; break;
        }
    } while (choice != 6);

    return 0;
}

