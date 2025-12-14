#include <iostream>
using namespace std;

struct Node {
    int empid;
    string name;
    Node* left;
    Node* right;
};

Node* createNode(int id, string name) {
    Node* t = new Node;
    t->empid = id;
    t->name = name;
    t->left = t->right = NULL;
    return t;
}

Node* insertNode(Node* root, int id, string name) {
    if (!root) return createNode(id, name);

    if (id < root->empid)
        root->left = insertNode(root->left, id, name);
    else
        root->right = insertNode(root->right, id, name);

    return root;
}

bool search(Node* root, int id) {
    if (!root) return false;
    if (root->empid == id) return true;
    return (id < root->empid) ? search(root->left, id)
                              : search(root->right, id);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->empid << " - " << root->name << endl;
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, id;
    string name;

    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter ID and Name: ";
        cin >> id >> name;
        root = insertNode(root, id, name);
    }

    cout << "\nSorted Employee List:\n";
    inorder(root);

    cout << "\nEnter emp-id to search: ";
    cin >> id;
    if (search(root, id)) cout << "Employee Found.\n";
    else cout << "Employee Not Found.\n";

    return 0;
}

