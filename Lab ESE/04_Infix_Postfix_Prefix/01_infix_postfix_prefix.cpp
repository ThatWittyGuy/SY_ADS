#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// Function to check if the character is an operand
bool isOperand(char ch) {
    return isalpha(ch); // Operand is considered a letter (A-Z, a-z)
}

// Function to check operator precedence
int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0; // For non-operator characters
}

// Function to check if the character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert Infix to Postfix
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix;
    for (char ch : infix) {
        if (isOperand(ch)) {
            postfix += ch; // Add operand to postfix
        } else if (ch == '(') {
            s.push(ch); // Push '(' to stack
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top(); // Pop operators to postfix until '(' is found
                s.pop();
            }
            s.pop(); // Pop '('
        } else if (isOperator(ch)) {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top(); // Pop operators to postfix based on precedence
                s.pop();
            }
            s.push(ch); // Push the current operator to the stack
        }
    }
    // Pop all remaining operators in the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// Function to reverse a string
string reverseString(const string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

// Function to convert Infix to Prefix
string infixToPrefix(const string& infix) {
    string reversedInfix = reverseString(infix);
    string reversedPrefix = infixToPostfix(reversedInfix); // Get postfix of the reversed string
    return reverseString(reversedPrefix); // Reverse the result to get the prefix
}

// Menu-driven function
int main() {
    int choice;
    string infix, result;

    do {
        cout << "\nMenu:\n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "2. Convert Infix to Prefix\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Infix expression: ";
                cin >> infix;
                result = infixToPostfix(infix);
                cout << "Postfix Expression: " << result << endl;
                break;

            case 2:
                cout << "Enter Infix expression: ";
                cin >> infix;
                result = infixToPrefix(infix);
                cout << "Prefix Expression: " << result << endl;
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
