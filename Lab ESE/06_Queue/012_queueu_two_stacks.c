#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int arr[5];
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == 4;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

void enqueue(struct Stack* s1, struct Stack* s2, int value) {
    push(s1, value);
}

int dequeue(struct Stack* s1, struct Stack* s2) {
    if (isEmpty(s1) && isEmpty(s2)) {
        printf("Queue is empty\n");
        return -1;
    }
    if (isEmpty(s2)) {
        while (!isEmpty(s1)) {
            push(s2, pop(s1));
        }
    }
    return pop(s2);
}

void display(struct Stack* s1, struct Stack* s2) {
    if (isEmpty(s1) && isEmpty(s2)) {
        printf("Queue is empty\n");
        return;
    }
    struct Stack temp;
    initStack(&temp);
    while (!isEmpty(s2)) {
        push(&temp, pop(s2));
    }
    while (!isEmpty(s1)) {
        printf("%d ", s1->arr[s1->top]);
    }
    while (!isEmpty(&temp)) {
        printf("%d ", pop(&temp));
    }
    printf("\n");
}

int main() {
    struct Stack s1, s2;
    int choice, value;
    initStack(&s1);
    initStack(&s2);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&s1, &s2, value);
                break;
            case 2:
                value = dequeue(&s1, &s2);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                display(&s1, &s2);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
