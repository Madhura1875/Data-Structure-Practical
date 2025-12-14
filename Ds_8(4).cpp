#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    string code;
    float price;
    int qty;
    string received;
    string expiry;
    Node* left;
    Node* right;
};

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

// Insert sorted by Product Name
Node* insertProduct(Node* root, string code, string name, float price,
                    int qty, string rec, string exp) {

    if (!root)
        return createNode(code, name, price, qty, rec, exp);

    if (name < root->name)
        root->left = insertProduct(root->left, code, name, price, qty, rec, exp);
    else
        root->right = insertProduct(root->right, code, name, price, qty, rec, exp);

    return root;
}

// Inorder = alphabetical inventory
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);

    cout << root->name << " (" << root->code << ")  Qty:" << root->qty 
         << "  Price:" << root->price << "  Exp:" << root->expiry << endl;

    inorder(root->right);
}

// Preorder listing of expired items
void listExpired(Node* root, string today) {
    if (!root) return;

    if (root->expiry < today)
        cout << root->name << "  Expired on: " << root->expiry << endl;

    listExpired(root->left, today);
    listExpired(root->right, today);
}

int main() {
    Node* root = NULL;

    int n, qty;
    float price;
    string code, name, received, expiry, today;

    cout << "Enter today's date (YYYY-MM-DD): ";
    cin >> today;

    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Product Code, Name, Price, Qty, Received Date, Expiry Date:\n";
        cin >> code >> name >> price >> qty >> received >> expiry;

        root = insertProduct(root, code, name, price, qty, received, expiry);
    }

    cout << "\n--- INVENTORY (Inorder Sorted by Name) ---\n";
    inorder(root);

    cout << "\n--- EXPIRED PRODUCTS (Preorder) ---\n";
    listExpired(root, today);

    return 0;
}

