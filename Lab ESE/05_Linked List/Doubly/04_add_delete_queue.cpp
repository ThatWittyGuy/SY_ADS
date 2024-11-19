#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* front = nullptr;
Node* rear = nullptr;

void add(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = rear;

    if (rear != nullptr) {
        rear->next = newNode;
    }
    rear = newNode;

    if (front == nullptr) {
        front = newNode;
    }
}

void deleteNode() {
    if (front == nullptr) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front != nullptr) {
        front->prev = nullptr;
    } else {
        rear = nullptr;
    }

    delete temp;
}

void display() {
    if (front == nullptr) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, data;

    while (true) {
        cout << "1. Add (enqueue)\n";
        cout << "2. Delete (dequeue)\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to add: ";
                cin >> data;
                add(data);
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
