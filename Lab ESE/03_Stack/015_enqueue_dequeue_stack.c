#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = value;
    }
}

int pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return -1;
}

int peek(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return -1;
}

struct MyQueue {
    struct Stack stack1;
    struct Stack stack2;
};

void initQueue(struct MyQueue *q) {
    initStack(&q->stack1);
    initStack(&q->stack2);
}

void enqueue(struct MyQueue *q, int value) {
    push(&q->stack1, value);
}

int dequeue(struct MyQueue *q) {
    if (isEmpty(&q->stack2)) {
        while (!isEmpty(&q->stack1)) {
            push(&q->stack2, pop(&q->stack1));
        }
    }
    return pop(&q->stack2);
}

int main() {
    struct MyQueue q;
    initQueue(&q);
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                } else {
                    printf("Queue is empty\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
