//infix to postfix using stack
/*
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int top = -1;
char stack[MAX];

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

char peek() {
    return stack[top];
}

char pop() {
    if (isEmpty())
        return -1;
    else {
        return stack[top--];
    }
}

void push(char op) {
    if (isFull())
        printf("Stack is full\n");
    else {
        stack[++top] = op;
    }
}

int checkOp(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(char* exp) {
    char postfix[MAX];
    int i, j;

    for (i = 0, j = 0; exp[i]; ++i) {
        if (checkOp(exp[i]))
            postfix[j++] = exp[i];
        else if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();
            if (!isEmpty() && peek() != '(')
                printf("Invalid expression\n");
            else
                pop();  // pop '('
        } else {
            while (!isEmpty() && precedence(exp[i]) <= precedence(peek()))  //associativity
                postfix[j++] = pop();
            push(exp[i]);
        }
    }

    while (!isEmpty())
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression is: %s\n", postfix);
}

int main() {
    char exp[MAX];
    printf("Enter expression: ");
    scanf("%s", exp);

    infixToPostfix(exp);

    return 0;
}

// prefix to postfix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int top = -1;
char stack[MAX][MAX];

int isEmpty() {
    return top == -1;
}

void push(char* value) {
    if (top >= MAX - 1)
        printf("Stack is full\n");
    else
        strcpy(stack[++top], value);
}

char* pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    } else
        return stack[top--];
}

// if the character is an operator
int isOp(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

void prefixToPostfix(char* exp) {
    int length = strlen(exp);

    for (int i = length - 1; i >= 0; i--) {   // evaluate prefix expression from right to left

        if (isOp(exp[i])) { //if char is op

            char* op1 = pop();  //pop 2 operands
            char* op2 = pop();

            char temp[MAX];    // Concatenate in postfix order (op1 + op2 + operator)
            sprintf(temp, "%s%s%c", op1, op2, exp[i]);

            push(temp);  //result str in stck
        }

        else {
            char operand[2] = {exp[i], '\0'}; //directly push on stcak
            push(operand);
        }
    }

    printf("Postfix expression is: %s\n", pop());
}

int main() {
    char exp[MAX];

    printf("Enter a prefix expression: ");
    scanf("%s", exp);

    prefixToPostfix(exp);

    return 0;
}

*/
/*
// infix to prefix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

int top = -1;
char stack[MAX];

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

char peek() {
    return stack[top];
}

char pop() {
    if (isEmpty())
        return -1;
    else
        return stack[top--];
}

void push(char op) {
    if (isFull())
        printf("Stack is full\n");
    else {
        stack[++top] = op;
    }
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// reverse the str exp for infix
void reverse(char* exp) {
    int length = strlen(exp);
    for (int i = 0; i < length / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[length - i - 1];
        exp[length - i - 1] = temp;
    }
    // replace brackets too
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int j = 0;
    for (int i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty()) pop(); // pop '('
        } else if (isOperator(infix[i])) {
            while (!isEmpty() && precedence(peek()) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

// Function to convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {

    reverse(infix);

    char postfix[MAX];
    infixToPostfix(infix, postfix);

    // Reverse postfix to get prefix
    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression is: %s\n", prefix);

    return 0;
}

*/

// evaluate prefix and postfix

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int postfix(char* exp) {
    int i;

    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            int val1 = pop();
            int val2 = pop();
            switch (exp[i]) {
                case '+': push(val2 + val1);
                break;
                case '-': push(val2 - val1);
                break;
                case '*': push(val2 * val1);
                break;
                case '/': push(val2 / val1);
                break;
            }
        }
    }
    return pop();
}

int prefix(char* exp) {
    int i;
    int length = strlen(exp);

    for (i = length - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            int val1 = pop();
            int val2 = pop();
            switch (exp[i]) {
                case '+': push(val1 + val2);
                break;
                case '-': push(val1 - val2);
                break;
                case '*': push(val1 * val2);
                break;
                case '/': push(val1 / val2);
                break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    int choice;

    printf("Enter 1 for Prefix evaluation, 2 for Postfix evaluation: ");
    scanf("%d", &choice);
    printf("Enter the expression: ");
    scanf("%s", exp);

    if (choice == 1) {
        printf("Prefix evaluation result: %d\n", prefix(exp));
    } else if (choice == 2) {
        printf("Postfix evaluation result: %d\n", postfix(exp));
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
