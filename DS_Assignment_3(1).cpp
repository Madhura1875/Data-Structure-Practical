#include <iostream>
#include <cstdlib>
using namespace std;

struct Seat {
    int seatNo;
    bool booked;
    Seat *next;
    Seat *prev;
};

Seat* head[8];   // Array of head pointers (one per row)

/* Create doubly circular linked list for each row */
void createRows() {
    for (int i = 0; i < 8; i++) {
        Seat *first = NULL, *last = NULL;

        for (int j = 1; j <= 8; j++) {
            Seat *temp = new Seat;
            temp->seatNo = j;
            temp->booked = (rand() % 2); // randomly booked
            temp->next = temp->prev = NULL;

            if (first == NULL) {
                first = last = temp;
                first->next = first->prev = first;
            } else {
                temp->prev = last;
                temp->next = first;
                last->next = temp;
                first->prev = temp;
                last = temp;
            }
        }
        head[i] = first;
    }
}

/* Display available seats */
void displaySeats() {
    cout << "\nAvailable Seats:\n";
    for (int i = 0; i < 8; i++) {
        cout << "Row " << i + 1 << ": ";
        Seat *temp = head[i];
        bool any = false;

        do {
            if (!temp->booked) {
                cout << temp->seatNo << " ";
                any = true;
            }
            temp = temp->next;
        } while (temp != head[i]);

        if (!any)
            cout << "No seats available";
        cout << endl;
    }
}

/* Book seats */
void bookSeat() {
    int row, seat;
    cout << "Enter Row (1-8): ";
    cin >> row;
    cout << "Enter Seat Number (1-8): ";
    cin >> seat;

    if (row < 1 || row > 8 || seat < 1 || seat > 8) {
        cout << "Invalid selection!\n";
        return;
    }

    Seat *temp = head[row - 1];
    do {
        if (temp->seatNo == seat) {
            if (!temp->booked) {
                temp->booked = true;
                cout << "Seat booked successfully!\n";
            } else {
                cout << "Seat already booked!\n";
            }
            return;
        }
        temp = temp->next;
    } while (temp != head[row - 1]);
}

/* Cancel booking */
void cancelSeat() {
    int row, seat;
    cout << "Enter Row (1-8): ";
    cin >> row;
    cout << "Enter Seat Number (1-8): ";
    cin >> seat;

    if (row < 1 || row > 8 || seat < 1 || seat > 8) {
        cout << "Invalid selection!\n";
        return;
    }

    Seat *temp = head[row - 1];
    do {
        if (temp->seatNo == seat) {
            if (temp->booked) {
                temp->booked = false;
                cout << "Booking cancelled successfully!\n";
            } else {
                cout << "Seat is already available!\n";
            }
            return;
        }
        temp = temp->next;
    } while (temp != head[row - 1]);
}

/* Main Menu */
int main() {
    int choice;
    createRows();

    do {
        cout << "\n----- Galaxy Multiplex Ticket System -----\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book Seat\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                cancelSeat();
                break;
            case 4:
                cout << "Thank you!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

