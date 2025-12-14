#include<iostream>
using namespace std;

#define MAX 10  // total size of array

class MultipleQueues {
    int arr[MAX];
    int front1, rear1;
    int front2, rear2;

public:
    MultipleQueues() {
        front1 = rear1 = -1;   // Queue 1
        front2 = rear2 = MAX;  // Queue 2 (starts from end)
    }

    // Add to Queue
    void enqueue(int qn, int value) {
        if (qn == 1) {
            if (rear1 + 1 == front2) {
                cout << "Queue 1 Overflow!\n";
                return;
            }
            if (front1 == -1)
                front1 = 0;
            rear1++;
            arr[rear1] = value;
            cout << value << " added to Queue 1\n";
        }
        else if (qn == 2) {
            if (rear2 - 1 == rear1) {
                cout << "Queue 2 Overflow!\n";
                return;
            }
            if (front2 == MAX)
                front2 = MAX - 1;
            rear2--;
            arr[rear2] = value;
            cout << value << " added to Queue 2\n";
        }
        else {
            cout << "Invalid Queue Number!\n";
        }
    }

    // Delete from Queue
    void dequeue(int qn) {
        if (qn == 1) {
            if (front1 == -1 || front1 > rear1) {
                cout << "Queue 1 Underflow!\n";
                return;
            }
            cout << "Deleted from Queue 1: " << arr[front1] << endl;
            front1++;
        }
        else if (qn == 2) {
            if (front2 == MAX || front2 < rear2) {
                cout << "Queue 2 Underflow!\n";
                return;
            }
            cout << "Deleted from Queue 2: " << arr[front2] << endl;
            front2--;
        }
        else {
            cout << "Invalid Queue Number!\n";
        }
    }

    // Display Queue
    void display(int qn) {
        if (qn == 1) {
            if (front1 == -1 || front1 > rear1) {
                cout << "Queue 1 is empty!\n";
                return;
            }
            cout << "Queue 1: ";
            for (int i = front1; i <= rear1; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
        else if (qn == 2) {
            if (front2 == MAX || front2 < rear2) {
                cout << "Queue 2 is empty!\n";
                return;
            }
            cout << "Queue 2: ";
            for (int i = front2; i >= rear2; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
        else {
            cout << "Invalid Queue Number!\n";
        }
    }
};

int main() {
    MultipleQueues mq;
    int choice, qn, value;

    do {
        cout << "\n--- Multiple Queue Menu ---\n";
        cout << "1. Add to Queue\n";
        cout << "2. Delete from Queue\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Queue Number (1 or 2): ";
            cin >> qn;
            cout << "Enter Value: ";
            cin >> value;
            mq.enqueue(qn, value);
            break;

        case 2:
            cout << "Enter Queue Number (1 or 2): ";
            cin >> qn;
            mq.dequeue(qn);
            break;

        case 3:
            cout << "Enter Queue Number (1 or 2): ";
            cin >> qn;
            mq.display(qn);
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

