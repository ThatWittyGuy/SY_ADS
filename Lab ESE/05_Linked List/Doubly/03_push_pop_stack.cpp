#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* top = nullptr;

void push(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = top;

    if (top != nullptr) {
        top->next = newNode;
    }
    top = newNode;
}

void pop() {
    if (top == nullptr) {
        cout << "Stack is empty\n";
        return;
    }

    Node* temp = top;
    top = top->prev;

    if (top != nullptr) {
        top->next = nullptr;
    }

    delete temp;
}

void display() {
    if (top == nullptr) {
        cout << "Stack is empty\n";
        return;
    }

    Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    int choice, data;

    while (true) {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to push: ";
                cin >> data;
                push(data);
                break;
            case 2:
                pop();
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
