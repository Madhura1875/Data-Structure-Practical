#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insertNode(root->left, val);
    else if (val > root->data)
        root->right = insertNode(root->right, val);

    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL) return root;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        if (root->left == NULL) {
            Node* temp = root->right; delete root; return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left; delete root; return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void levelDisplay(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    cout << "Levelwise Display: ";
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

int main() {
    Node* root = NULL;
    int choice, val;

    do {
        cout << "\n1.Insert\n2.Delete\n3.Levelwise Display\n4.Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; root = insertNode(root, val); break;
        case 2: cout << "Enter value: "; cin >> val; root = deleteNode(root, val); break;
        case 3: levelDisplay(root); break;
        case 4: break;
        }
    } while (choice != 4);

    return 0;
}

