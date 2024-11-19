#include <iostream>
using namespace std;

#define MAX 5  // Size of the array

// Structure to represent the two stacks
struct TwoStacks {
    int arr[MAX];  // Array to hold both stacks
    int top1, top2;  // Pointers for stack1 and stack2
};

// Function to initialize the two stacks
void initializeStacks(TwoStacks &st) {
    st.top1 = -1;  // Stack1 is initially empty
    st.top2 = MAX; // Stack2 is initially empty (from the right side of the array)
}

// Function to check if stack1 is full
bool isFullStack1(const TwoStacks &st) {
    return st.top1 == st.top2 - 1;
}

// Function to check if stack2 is full
bool isFullStack2(const TwoStacks &st) {
    return st.top2 == st.top1 + 1;
}

// Function to check if stack1 is empty
bool isEmptyStack1(const TwoStacks &st) {
    return st.top1 == -1;
}

// Function to check if stack2 is empty
bool isEmptyStack2(const TwoStacks &st) {
    return st.top2 == MAX;
}

// Function to push an element to stack1
void pushStack1(TwoStacks &st, int value) {
    if (isFullStack1(st)) {
        cout << "Stack1 is Full! Cannot push " << value << endl;
    } else {
        st.arr[++st.top1] = value;
        cout << value << " pushed to Stack1." << endl;
    }
}

// Function to push an element to stack2
void pushStack2(TwoStacks &st, int value) {
    if (isFullStack2(st)) {
        cout << "Stack2 is Full! Cannot push " << value << endl;
    } else {
        st.arr[--st.top2] = value;
        cout << value << " pushed to Stack2." << endl;
    }
}

// Function to pop an element from stack1
void popStack1(TwoStacks &st) {
    if (isEmptyStack1(st)) {
        cout << "Stack1 is Empty! Cannot pop." << endl;
    } else {
        cout << "Popped " << st.arr[st.top1--] << " from Stack1." << endl;
    }
}

// Function to pop an element from stack2
void popStack2(TwoStacks &st) {
    if (isEmptyStack2(st)) {
        cout << "Stack2 is Empty! Cannot pop." << endl;
    } else {
        cout << "Popped " << st.arr[st.top2++] << " from Stack2." << endl;
    }
}

// Function to display elements of stack1
void displayStack1(const TwoStacks &st) {
    if (isEmptyStack1(st)) {
        cout << "Stack1 is Empty!" << endl;
    } else {
        cout << "Stack1 elements: ";
        for (int i = 0; i <= st.top1; i++) {
            cout << st.arr[i] << " ";
        }
        cout << endl;
    }
}

// Function to display elements of stack2
void displayStack2(const TwoStacks &st) {
    if (isEmptyStack2(st)) {
        cout << "Stack2 is Empty!" << endl;
    } else {
        cout << "Stack2 elements: ";
        for (int i = MAX - 1; i >= st.top2; i--) {
            cout << st.arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    TwoStacks stacks;
    int choice, value;

    initializeStacks(stacks); // Initialize the two stacks

    do {
        cout << "\nMenu:\n";
        cout << "1. Push to Stack1\n";
        cout << "2. Push to Stack2\n";
        cout << "3. Pop from Stack1\n";
        cout << "4. Pop from Stack2\n";
        cout << "5. Display Stack1\n";
        cout << "6. Display Stack2\n";
        cout << "7. StackFull\n";
        cout << "8. StackEmpty\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push to Stack1: ";
                cin >> value;
                pushStack1(stacks, value);
                break;
            
            case 2:
                cout << "Enter value to push to Stack2: ";
                cin >> value;
                pushStack2(stacks, value);
                break;
            
            case 3:
                popStack1(stacks);
                break;
            
            case 4:
                popStack2(stacks);
                break;
            
            case 5:
                displayStack1(stacks);
                break;
            
            case 6:
                displayStack2(stacks);
                break;
            
            case 7:
                if (isFullStack1(stacks)) {
                    cout << "Stack1 is full!" << endl;
                } else if (isFullStack2(stacks)) {
                    cout << "Stack2 is full!" << endl;
                } else {
                    cout << "Neither stack is full!" << endl;
                }
                break;
            
            case 8:
                if (isEmptyStack1(stacks)) {
                    cout << "Stack1 is empty!" << endl;
                } else if (isEmptyStack2(stacks)) {
                    cout << "Stack2 is empty!" << endl;
                } else {
                    cout << "Neither stack is empty!" << endl;
                }
                break;
            
            case 9:
                cout << "Exiting...\n";
                break;
            
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
