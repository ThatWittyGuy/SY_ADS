#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int minStack[MAX];
int top = -1;

void push(int val) {
    if (top < MAX - 1) {
        stack[++top] = val;
        if (top == 0 || val < minStack[top - 1]) {
            minStack[top] = val;
        } else {
            minStack[top] = minStack[top - 1];
        }
    }
}

void pop() {
    if (top >= 0) {
        top--;
    }
}

int topElement() {
    if (top >= 0) {
        return stack[top];
    }
    return -1;
}

int getMin() {
    if (top >= 0) {
        return minStack[top];
    }
    return -1;
}

int isEmpty() {
    return top == -1;
}

void display() {
    if (top >= 0) {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("Stack is empty\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Get Min\n");
        printf("5. Check if stack is empty\n");
        printf("6. Display stack\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                printf("Popped top element.\n");
                break;
            case 3:
                value = topElement();
                if (value != -1) {
                    printf("Top element: %d\n", value);
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            case 4:
                value = getMin();
                if (value != -1) {
                    printf("Minimum element: %d\n", value);
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            case 5:
                if (isEmpty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
