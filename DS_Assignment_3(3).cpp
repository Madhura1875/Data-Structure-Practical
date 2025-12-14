#include <iostream>
using namespace std;

struct Member {
    int prn;
    string name;
    Member* next;
};

Member* head1 = NULL;   // Division 1
Member* head2 = NULL;   // Division 2

/* Add member */
void addMember(Member* &head) {
    Member* temp = new Member;
    cout << "Enter PRN: ";
    cin >> temp->prn;
    cout << "Enter Name: ";
    cin >> temp->name;
    temp->next = NULL;

    int choice;
    cout << "1. Add as President\n2. Add as Secretary\n3. Add Normal Member\nChoice: ";
    cin >> choice;

    if (head == NULL || choice == 1) {
        temp->next = head;
        head = temp;
    }
    else if (choice == 2) {
        Member* t = head;
        while (t->next)
            t = t->next;
        t->next = temp;
    }
    else {
        temp->next = head->next;
        head->next = temp;
    }
}

/* Display members */
void display(Member* head) {
    if (!head) {
        cout << "List empty!\n";
        return;
    }
    Member* temp = head;
    while (temp) {
        cout << "PRN: " << temp->prn << " Name: " << temp->name << endl;
        temp = temp->next;
    }
}

/* Count members */
void countMembers(Member* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    cout << "Total Members: " << count << endl;
}

/* Delete member */
void deleteMember(Member* &head) {
    int prn;
    cout << "Enter PRN to delete: ";
    cin >> prn;

    Member* temp = head;
    Member* prev = NULL;

    while (temp && temp->prn != prn) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Member not found!\n";
        return;
    }

    if (temp == head)
        head = head->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Member deleted.\n";
}

/* Search by PRN */
void searchPRN(Member* head) {
    int prn;
    cout << "Enter PRN to search: ";
    cin >> prn;

    while (head) {
        if (head->prn == prn) {
            cout << "Member Found: " << head->name << endl;
            return;
        }
        head = head->next;
    }
    cout << "Member not found!\n";
}

/* Reverse list */
void reverseList(Member* &head) {
    Member *prev = NULL, *curr = head, *next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    cout << "List reversed.\n";
}

/* Sort by PRN */
void sortByPRN(Member* head) {
    for (Member* i = head; i && i->next; i = i->next) {
        for (Member* j = i->next; j; j = j->next) {
            if (i->prn > j->prn) {
                swap(i->prn, j->prn);
                swap(i->name, j->name);
            }
        }
    }
    cout << "List sorted by PRN.\n";
}

/* Concatenate two lists */
void concatenate() {
    if (!head1) {
        head1 = head2;
        head2 = NULL;
        return;
    }

    Member* temp = head1;
    while (temp->next)
        temp = temp->next;

    temp->next = head2;
    head2 = NULL;
    cout << "Lists concatenated.\n";
}

/* Main Menu */
int main() {
    int choice, listChoice;

    do {
        cout << "\n---- Vertex Club Management ----\n";
        cout << "1. Add Member\n";
        cout << "2. Delete Member\n";
        cout << "3. Display Members\n";
        cout << "4. Count Members\n";
        cout << "5. Search by PRN\n";
        cout << "6. Reverse List\n";
        cout << "7. Sort by PRN\n";
        cout << "8. Concatenate Two Divisions\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 7) {
            cout << "Select Division (1 or 2): ";
            cin >> listChoice;
        }

        switch (choice) {
            case 1:
                addMember(listChoice == 1 ? head1 : head2);
                break;
            case 2:
                deleteMember(listChoice == 1 ? head1 : head2);
                break;
            case 3:
                display(listChoice == 1 ? head1 : head2);
                break;
            case 4:
                countMembers(listChoice == 1 ? head1 : head2);
                break;
            case 5:
                searchPRN(listChoice == 1 ? head1 : head2);
                break;
            case 6:
                reverseList(listChoice == 1 ? head1 : head2);
                break;
            case 7:
                sortByPRN(listChoice == 1 ? head1 : head2);
                break;
            case 8:
                concatenate();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 9);

    return 0;
}

