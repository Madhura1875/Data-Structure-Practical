#include <iostream>
using namespace std;

struct Appointment {
    int start;
    int end;
    Appointment* next;
};

Appointment* head = NULL;

const int MIN_DURATION = 30;
const int MAX_DURATION = 120;

/* Convert time to minutes */
int toMinutes(int h, int m) {
    return h * 60 + m;
}

/* Insert appointment randomly */
void bookAppointment() {
    int sh, sm, eh, em;
    cout << "Enter start time (hh mm): ";
    cin >> sh >> sm;
    cout << "Enter end time (hh mm): ";
    cin >> eh >> em;

    int start = toMinutes(sh, sm);
    int end = toMinutes(eh, em);

    int duration = end - start;

    if (duration < MIN_DURATION || duration > MAX_DURATION || start >= end) {
        cout << "Invalid appointment duration!\n";
        return;
    }

    Appointment* temp = new Appointment;
    temp->start = start;
    temp->end = end;
    temp->next = head;
    head = temp;

    cout << "Appointment booked successfully!\n";
}

/* Display available appointments */
void displayAppointments() {
    if (!head) {
        cout << "No appointments scheduled.\n";
        return;
    }

    Appointment* temp = head;
    cout << "\nAppointments:\n";
    while (temp) {
        cout << "Start: " << temp->start / 60 << ":" << temp->start % 60
             << " End: " << temp->end / 60 << ":" << temp->end % 60 << endl;
        temp = temp->next;
    }
}

/* Cancel appointment */
void cancelAppointment() {
    int sh, sm;
    cout << "Enter appointment start time to cancel (hh mm): ";
    cin >> sh >> sm;

    int start = toMinutes(sh, sm);

    Appointment* temp = head;
    Appointment* prev = NULL;

    while (temp) {
        if (temp->start == start) {
            if (prev)
                prev->next = temp->next;
            else
                head = temp->next;

            delete temp;
            cout << "Appointment cancelled.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Appointment not found!\n";
}

/* Sort by swapping data */
void sortByData() {
    if (!head) return;

    for (Appointment* i = head; i->next; i = i->next) {
        for (Appointment* j = i->next; j; j = j->next) {
            if (i->start > j->start) {
                swap(i->start, j->start);
                swap(i->end, j->end);
            }
        }
    }
    cout << "Sorted using data swapping.\n";
}

/* Sort using pointer manipulation */
void sortByPointers() {
    if (!head || !head->next) return;

    Appointment *sorted = NULL;

    while (head) {
        Appointment* curr = head;
        head = head->next;

        if (!sorted || curr->start < sorted->start) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Appointment* temp = sorted;
            while (temp->next && temp->next->start < curr->start)
                temp = temp->next;

            curr->next = temp->next;
            temp->next = curr;
        }
    }
    head = sorted;
    cout << "Sorted using pointer manipulation.\n";
}

/* Main Menu */
int main() {
    int choice;

    do {
        cout << "\n---- Appointment Scheduling System ----\n";
        cout << "1. Display Appointments\n";
        cout << "2. Book Appointment\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Sort by Time (Data Swap)\n";
        cout << "5. Sort by Time (Pointer Manipulation)\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: displayAppointments(); break;
            case 2: bookAppointment(); break;
            case 3: cancelAppointment(); break;
            case 4: sortByData(); break;
            case 5: sortByPointers(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

