#include <iostream>
using namespace std;

#define MAX 100  // Maximum size of the stack

// Structure for stack
struct Stack {
    int arr[MAX];  // Array to store stack elements
    int top;       // Index of the top element of the stack
};

// Function to initialize stack
void initStack(Stack &s) {
    s.top = -1;  // Initialize stack as empty
}

// Function to check if the stack is empty
bool isEmpty(Stack &s) {
    return s.top == -1;
}

// Function to push an element to the stack
void push(Stack &s, int value) {
    if (s.top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
    } else {
        s.arr[++s.top] = value;  // Increment top and add value
    }
}

// Function to pop an element from the stack
int pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow!" << endl;
        return -1;  // Return -1 if the stack is empty
    } else {
        return s.arr[s.top--];  // Return top value and decrement top
    }
}

// Function to generate Fibonacci series using stack and print in correct order
void fibonacci(int n) {
    if (n <= 0) return;

    Stack s;
    initStack(s);

    // Base cases for Fibonacci series
    if (n > 0) push(s, 0);  // First Fibonacci number F(0)
    if (n > 1) push(s, 1);  // Second Fibonacci number F(1)

    // Generate Fibonacci series and store in stack
    int prev = 0, curr = 1;
    for (int i = 2; i < n; ++i) {
        int next = prev + curr;  // Calculate the next Fibonacci number
        push(s, next);  // Push next Fibonacci number onto the stack
        prev = curr;    // Update prev to current
        curr = next;    // Update current to next
    }

    // Now print the Fibonacci series by popping the stack
    cout << "Fibonacci Series: ";
    // To print in correct order, we need to pop the stack in reverse
    // and push to another array or stack if necessary
    int fibArray[MAX];
    int i = 0;

    // Pop all values into an array first
    while (!isEmpty(s)) {
        fibArray[i++] = pop(s);
    }

    // Now print the Fibonacci series in correct order
    for (int j = i - 1; j >= 0; --j) {
        cout << fibArray[j] << " ";
    }
    cout << endl;
}

int main() {
    int choice, number;

    cout << "Menu:\n";
    cout << "1. Factorial\n";
    cout << "2. Fibonacci Series\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter a number to calculate its factorial: ";
            cin >> number;
            // Call the factorial function here (previously implemented)
            break;

        case 2:
            cout << "Enter the number of terms in Fibonacci series: ";
            cin >> number;
            fibonacci(number);
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}
