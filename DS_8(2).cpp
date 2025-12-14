#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key) {
    Node* t = new Node;
    t->key = key;
    t->left = t->right = NULL;
    return t;
}

Node* insertNode(Node* root, int key) {
    if (!root) return createNode(key);

    if (key < root->key) 
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);

    return root;
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->key) 
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* t = root->right;
            delete root;
            return t;
        }
        else if (!root->right) {
            Node* t = root->left;
            delete root;
            return t;
        }
        Node* t = findMin(root->right);
        root->key = t->key;
        root->right = deleteNode(root->right, t->key);
    }
    return root;
}

bool findNode(Node* root, int key) {
    if (!root) return false;
    if (root->key == key) return true;
    if (key < root->key) return findNode(root->left, key);
    return findNode(root->right, key);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int choice, key;

    do {
        cout << "\n1.Insert\n2.Delete\n3.Find\n4.Show(Inorder)\n5.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                root = insertNode(root, key);
                break;

            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;

            case 3:
                cout << "Enter key to find: ";
                cin >> key;
                cout << (findNode(root, key) ? "Found" : "Not Found") << endl;
                break;

            case 4:
                cout << "BST: ";
                inorder(root);
                cout << endl;
                break;

        }
    } while (choice != 5);

    return 0;
}

