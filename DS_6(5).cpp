#include <iostream>
using namespace std;

// Node structure for each call
struct Node {
    string callerName;
    Node* next;
};

// Queue class using Linked List
class CallQueue {
    Node* front;
    Node* rear;

public:
    CallQueue() {
        front = rear = nullptr;
    }

    // Enqueue new customer call
    void enqueue(string name) {
        Node* newNode = new Node;
        newNode->callerName = name;
        newNode->next = nullptr;

        if (rear == nullptr) {        // first call
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Call from " << name << " added to queue.\n";
    }

    // Dequeue call for a customer service agent
    void dequeue() {
        if (front == nullptr) {
            cout << "No calls in the queue. Waiting for new calls...\n";
            return;
        }

        Node* temp = front;
        cout << "Agent attending call from: " << front->callerName << endl;

        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    // Display all waiting calls
    void display() {
        if (front == nullptr) {
            cout << "No calls waiting.\n";
            return;
        }

        cout << "Calls in queue: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->callerName << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    CallQueue cq;
    int choice;
    string name;

    do {
        cout << "\n--- Call Center Queue System ---\n";
        cout << "1. Add New Call (Enqueue)\n";
        cout << "2. Attend Next Call (Dequeue)\n";
        cout << "3. Display Waiting Calls\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter caller name: ";
            cin >> name;
            cq.enqueue(name);
            break;

        case 2:
            cq.dequeue();
            break;

        case 3:
            cq.display();
            break;

        case 4:
            cout << "Exiting system...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

