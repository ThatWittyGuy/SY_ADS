#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAtPosition(Node*& head, int data, int pos) {
    if (pos == 1) {
        insertAtBeginning(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds\n";
    } else {
        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

void deleteAtPosition(Node*& head, int pos) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    if (pos == 1) {
        deleteAtBeginning(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds\n";
    } else {
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
}

void display(Node* head) {
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
    Node* head = nullptr;
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
                cout << "Enter data: ";
                cin >> data;
                insertAtBeginning(head, data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                insertAtEnd(head, data);
                break;
            case 3:
                cout << "Enter data and position: ";
                cin >> data >> pos;
                insertAtPosition(head, data, pos);
                break;
            case 4:
                deleteAtBeginning(head);
                break;
            case 5:
                deleteAtEnd(head);
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deleteAtPosition(head, pos);
                break;
            case 7:
                display(head);
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
