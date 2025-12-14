#include <iostream>
using namespace std;

#define MAX 5   // maximum number of orders

class PizzaParlour {
    int orders[MAX];
    int front, rear;

public:
    PizzaParlour() {
        front = -1;
        rear = -1;
    }

    // Function to add order
    void placeOrder(int orderID) {
        // Check if queue is full
        if ((front == 0 && rear == MAX - 1) || (rear + 1 == front)) {
            cout << "Order full! No more orders can be accepted.\n";
            return;
        }

        // Insert first order
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        orders[rear] = orderID;
        cout << "Order " << orderID << " placed successfully.\n";
    }

    // Function to serve order
    void serveOrder() {
        if (front == -1) {
            cout << "No orders to serve!\n";
            return;
        }

        cout << "Serving Order " << orders[front] << endl;

        if (front == rear) {
            // Queue becomes empty
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    // Function to display pending orders
    void displayOrders() {
        if (front == -1) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Pending Orders: ";
        int i = front;
        while (true) {
            cout << orders[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    PizzaParlour p;
    int choice, orderID;

    do {
        cout << "\n--- Pizza Parlour Menu ---\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Pending Orders\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Order ID: ";
            cin >> orderID;
            p.placeOrder(orderID);
            break;
        case 2:
            p.serveOrder();
            break;
        case 3:
            p.displayOrders();
            break;
        case 4:
            cout << "Thank you for visiting Pizza Parlour!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

