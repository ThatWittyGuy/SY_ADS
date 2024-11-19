#include <iostream>
using namespace std;

#define MAX 5  

struct Stack {
    int arr[MAX];  
    int top;       
};

void initializeStack(Stack &s) {
    s.top = -1;  
}

bool isFull(const Stack &s) {
    return s.top == MAX - 1;
}

bool isEmpty(const Stack &s) {
    return s.top == -1;
}

void push(Stack &s, int value) {
    if (isFull(s)) {
        cout << "Stack Overflow! Cannot push " << value << endl;
    } else {
        s.arr[++s.top] = value;  // Increment top and push value
        cout << value << " pushed to stack." << endl;
    }
}


void pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow! No element to pop." << endl;
    } else {
        cout << "Popped element: " << s.arr[s.top--] << endl;  // Pop the top element
    }
}


void display(const Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = 0; i <= s.top; i++) {
            cout << s.arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Stack stack;  // Declare a stack variable
    initializeStack(stack);  // Initialize the stack
    int choice, value;

    // Menu-driven program
    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. IsEmpty\n";
        cout << "5. IsFull\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(stack, value);
                break;

            case 2:
                pop(stack);
                break;

            case 3:
                display(stack);
                break;

            case 4:
                if (isEmpty(stack)) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;

            case 5:
                if (isFull(stack)) {
                    cout << "Stack is full." << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
