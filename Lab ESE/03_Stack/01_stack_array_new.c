#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

int peek() {
    if (top >= 0) {
        return stack[top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
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

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if stack is empty\n");
        printf("6. Check if stack is full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Stack is full. Cannot push new element.\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(value);
                }
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty()) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 6:
                if (isFull()) {
                    printf("Stack is full\n");
                } else {
                    printf("Stack is not full\n");
                }
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


// #include <stdio.h>
// #define MAX 5

// int stack[MAX];
// int top = -1;

// void push(int value) {
//     if (top < MAX - 1) {
//         stack[++top] = value;
//     } else {
//         printf("Stack Overflow\n");
//     }
// }

// int pop() {
//     if (top >= 0) {
//         return stack[top--];
//     } else {
//         printf("Stack Underflow\n");
//         return -1;
//     }
// }

// int peek() {
//     if (top >= 0) {
//         return stack[top];
//     } else {
//         printf("Stack is empty\n");
//         return -1;
//     }
// }

// int main() {
//     push(10);
//     push(20);
//     push(30);
//     printf("Top element: %d\n", peek());
//     printf("Popped element: %d\n", pop());
//     printf("Top element after pop: %d\n", peek());
//     return 0;
// }
