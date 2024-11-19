#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;  // Pointer to the next node
};

struct Stack {
    Node* top;  

    Stack() {
        top = nullptr;  // Initially, the stack is empty
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node();  
        newNode->data = value;
        newNode->next = top;  // Point the new node's next to the current top
        top = newNode;  // Set the new node as the top of the stack
        cout << value << " pushed to stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! No element to pop." << endl;
        } else {
            Node* temp = top;
            cout << "Popped element: " << top->data << endl;
            top = top->next;  // Move the top pointer to the next node
            delete temp;  // Free the memory of the popped node
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            Node* temp = top;
            cout << "Stack elements: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;  // Move to the next node
            }
            cout << endl;
        }
    }

    // Destructor to clean up the stack and avoid memory leaks
    ~Stack() {
        while (!isEmpty()) {
            pop();  // Pop all elements
        }
    }
};

int main() {
    Stack stack;  // Create a stack instance
    int choice, value;

    // Menu-driven program
    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. IsEmpty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.display();
                break;

            case 4:
                if (stack.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
