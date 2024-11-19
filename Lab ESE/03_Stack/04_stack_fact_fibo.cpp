#include <iostream>
using namespace std;

#define MAX 100  

struct Stack {
    int arr[MAX];  
    int top;       
};

void initStack(Stack &s) {
    s.top = -1;  
}

bool isFull(Stack &s) {
    return s.top == MAX - 1;
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

void push(Stack &s, int value) {
    if (isFull(s)) {
        cout << "Stack Overflow!" << endl;
    } else {
        s.arr[++s.top] = value;  
    }
}

int pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow!" << endl;
        return -1;  
    } else {
        return s.arr[s.top--];  
    }
}

int factorial(int n) {
    Stack s;
    initStack(s);
    int result = 1;

    for (int i = 1; i <= n; ++i) {
        push(s, i);
    }

    while (!isEmpty(s)) {
        result *= pop(s);
    }

    return result;
}

void fibonacci(int n) {
    Stack s;
    initStack(s);

    push(s, 0);  // F(0)
    push(s, 1);  // F(1)

    // Generate Fibonacci series up to n terms
    for (int i = 2; i < n; ++i) {
        int a = pop(s);  // Pop last element (F(i-1))
        int b = s.arr[s.top];  // Peek at the new top (F(i-2))
        push(s, a);  // Push F(i-1) back
        push(s, a + b);  // Push F(i)
    }

    // Display the Fibonacci series (in reverse order)
    cout << "Fibonacci Series: ";
    while (!isEmpty(s)) {
        cout << pop(s) << " ";
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
            cout << "Factorial of " << number << " is " << factorial(number) << endl;
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
