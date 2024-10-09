#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d is pushed\n", value);
}

int pop(){
    if(top == NULL){
        printf("Stack is empty\n");
        return -1;
    } else{
        struct Node* temp = top;
        int popped = temp->data;
        top = top->next;
        free(temp);
        return popped;
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Push\t2. Pop\t3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("%d popped from stack\n", value);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } 
    return 0;
}







// Stack Implementation Using Linked List
// Theory:

//     Definition: A stack can also be implemented using a linked list, where each element points to the next one, allowing dynamic memory allocation.
//     Operations:
//         Push: Creates a new node and adds it to the top of the stack.
//         Pop: Removes the node from the top of the stack and returns its value.
//     Advantages:
//         Dynamic size: The stack can grow and shrink as needed, limited only by system memory.
//         No overflow: Can push elements until memory is exhausted.

// Code Explanation:

//     Includes and Structure Definition:
//         #include <stdio.h> and #include <stdlib.h> for standard input/output and memory allocation.
//         struct Node: Defines a node with data and a pointer to the next node.
//     Global Variable:
//         struct Node* top: Pointer to the top node of the stack, initialized to NULL.
//     Functions:
//         push(int value): Allocates memory for a new node, sets its data, and updates the top pointer.
//         pop(): Checks if the stack is empty, retrieves the top value, updates the top pointer, and frees the memory of the popped node.
//     Main Function:
//         A loop to display options for push, pop, and exit.
//         Uses conditional statements to handle user choices.
