#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an item onto the stack
void push(Stack* s, char item) {
    if (s->top < MAX - 1) {
        s->items[++s->top] = item;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an item from the stack
char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack underflow\n");
        return '\0'; // Return null character if stack is empty
    }
}

// Function to get the top item of the stack without using peek
char topItem(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0'; // Return null character if stack is empty
}

// Function to check operator precedence
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            // If the character is an operand, add it to output
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            // If the character is '(', push it to stack
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            // If the character is ')', pop and output from the stack
            while (!isEmpty(&s) && topItem(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Pop '(' from the stack
        } else {
            // An operator is encountered
            while (!isEmpty(&s) && precedence(topItem(&s)) >= precedence(infix[i])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
        i++;
    }

    // Pop all the operators from the stack
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin); // Read infix expression from user

    // Remove newline character if present
    infix[strcspn(infix, "\n")] = 0;

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
