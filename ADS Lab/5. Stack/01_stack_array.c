#include<stdio.h>
#include<stdlib.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push (int value){
    if (top == MAX -1)
        printf("Stack is Full\n");
    else{
        stack[++top] = value;
        printf("%d is pushed\n", value);
    }
}

int pop(){
    if (top == -1){
        printf("Stack is Empty\n");
        return -1;
    }
    else
        return stack[top--];
}

int main(){
    int choice, value;
    while(1){
        printf("1. Push\t2. Pop\t3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1)
                    printf("%d popped from stack\n", value);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

// Stack Implementation Using Arrays
// Theory:

//     Definition: A stack is a linear data structure that follows the Last In First Out (LIFO) principle, where the last element added is the first one to be removed.
//     Operations:
//         Push: Adds an element to the top of the stack.
//         Pop: Removes and returns the top element of the stack.
//     Limitations:
//         Fixed size: The maximum number of elements is defined at compile time.
//         Stack Overflow: Occurs when trying to push an element onto a full stack.
//         Stack Underflow: Occurs when trying to pop an element from an empty stack.

// Code Explanation:

//     Includes and Definitions:
//         #include <stdio.h> and #include <stdlib.h> for standard input/output and memory allocation.
//         #define MAX 100 defines the maximum size of the stack.
//     Global Variables:
//         int stack[MAX]: Array to store stack elements.
//         int top: Index of the top element, initialized to -1 (indicating an empty stack).
//     Functions:
//         push(int value): Adds a value to the stack if there is space.
//         pop(): Removes and returns the top value if the stack is not empty.
//     Main Function:
//         A loop to display options for push, pop, and exit.
//         Uses a switch statement to handle user choices.
