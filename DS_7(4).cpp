#include <iostream>
#include <stack>
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

void nonRecInorder(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void nonRecPreorder(Node* root) {
    if (!root) return;
    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* temp = st.top(); st.pop();
        cout << temp->data << " ";

        if (temp->right) st.push(temp->right);
        if (temp->left)  st.push(temp->left);
    }
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
        cout << "\n1.Insert\n2.NonRecursive Inorder\n3.NonRecursive Preorder\n4.Leaf Count\n5.Mirror Image\n6.Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cin >> val; root = insertNode(root, val); break;
        case 2: nonRecInorder(root); cout << endl; break;
        case 3: nonRecPreorder(root); cout << endl; break;
        case 4: cout << "Leaf Nodes: " << leafCount(root) << endl; break;
        case 5: mirror(root); cout << "Mirror Created.\n"; break;
        }
    } while (choice != 6);
}

