#include <iostream>
#include <string>
using namespace std;

// Product Node Structure
struct Node {
    string code;         // BST KEY
    string name;
    float price;
    int qty;
    string received;
    string expiry;
    Node* left;
    Node* right;
};

// Create new product node
Node* createNode(string code, string name, float price, int qty,
                 string rec, string exp) {

    Node* t = new Node;
    t->code = code;
    t->name = name;
    t->price = price;
    t->qty = qty;
    t->received = rec;
    t->expiry = exp;
    t->left = t->right = NULL;
    return t;
}

// Insert sorted by UNIQUE product code (BST Key)
Node* insertProduct(Node* root, string code, string name, float price,
                    int qty, string rec, string exp) {

    if (root == NULL)
        return createNode(code, name, price, qty, rec, exp);

    if (code < root->code)
        root->left = insertProduct(root->left, code, name, price, qty, rec, exp);
    else
        root->right = insertProduct(root->right, code, name, price, qty, rec, exp);

    return root;
}

// Find minimum node (used in delete)
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// 1?? Delete product by UNIQUE PRODUCT CODE
Node* deleteByCode(Node* root, string code) {
    if (!root) return NULL;

    if (code < root->code) 
        root->left = deleteByCode(root->left, code);

    else if (code > root->code)
        root->right = deleteByCode(root->right, code);

    else {
        // Node found ? delete it
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }
        else if (!root->left) {
            Node* t = root->right;
            delete root;
            return t;
        }
        else if (!root->right) {
            Node* t = root->left;
            delete root;
            return t;
        }
        else {
            Node* t = findMin(root->right);
            root->code = t->code;
            root->name = t->name;
            root->price = t->price;
            root->qty = t->qty;
            root->received = t->received;
            root->expiry = t->expiry;

            root->right = deleteByCode(root->right, t->code);
        }
    }
    return root;
}

// 2?? Delete ALL expired products based on today's date
Node* deleteExpired(Node* root, string today) {
    if (!root) return NULL;

    root->left = deleteExpired(root->left, today);
    root->right = deleteExpired(root->right, today);

    // If expired, delete node
    if (root->expiry < today) {
        cout << "Deleting Expired Product: " << root->name << endl;
        return deleteByCode(root, root->code);
    }
    return root;
}

// Display inventory (inorder)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);

    cout << "\nCode: " << root->code
         << "\nName: " << root->name
         << "\nPrice: " << root->price
         << "\nQty: " << root->qty
         << "\nReceived: " << root->received
         << "\nExpiry: " << root->expiry
         << "\n------------------------------";

    inorder(root->right);
}

int main() {

    Node* root = NULL;
    int choice, qty;
    float price;
    string code, name, rec, exp, today;

    cout << "Enter today's date (YYYY-MM-DD): ";
    cin >> today;

    do {
        cout << "\n-------------------------------";
        cout << "\n1. Insert Product";
        cout << "\n2. Delete Product by Code";
        cout << "\n3. Delete All Expired Products";
        cout << "\n4. Display Inventory";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "\nEnter Code, Name, Price, Qty, Received Date, Expiry:\n";
                cin >> code >> name >> price >> qty >> rec >> exp;
                root = insertProduct(root, code, name, price, qty, rec, exp);
                break;

            case 2:
                cout << "Enter Product Code to delete: ";
                cin >> code;
                root = deleteByCode(root, code);
                break;

            case 3:
                cout << "\nDeleting all expired products...\n";
                root = deleteExpired(root, today);
                break;

            case 4:
                cout << "\n----- INVENTORY -----\n";
                inorder(root);
                cout << "\n----------------------\n";
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice!";
        }

    } while (choice != 5);

    return 0;
}

