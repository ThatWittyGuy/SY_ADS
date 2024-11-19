#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(int data, int pos) {
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }
    Node* newNode = new Node();
    newNode->data = data;
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds\n";
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtBeginning() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void deleteAtPosition(int pos) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    if (pos == 1) {
        deleteAtBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of bounds\n";
    } else {
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }
}

void display() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, data, pos;

    while (true) {
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete at beginning\n";
        cout << "5. Delete at end\n";
        cout << "6. Delete at position\n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data to insert: ";
                cin >> data;
                insertAtEnd(data);
                break;
            case 3:
                cout << "Enter data and position: ";
                cin >> data >> pos;
                insertAtPosition(data, pos);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deleteAtPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
