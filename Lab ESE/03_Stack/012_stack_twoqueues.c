#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    int arr[MAX];
    int front, rear;
};

void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->arr[++(q->rear)] = value;
    }
}

int dequeue(struct Queue *q) {
    if (q->front == -1) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int value = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front++;
        }
        return value;
    }
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

struct Stack {
    struct Queue q1, q2;
    int top;
};

void initStack(struct Stack *s) {
    s->q1.front = s->q1.rear = -1;
    s->q2.front = s->q2.rear = -1;
    s->top = -1;
}

void push(struct Stack *s, int value) {
    if (isFull(&s->q1)) {
        printf("Stack is full\n");
    } else {
        enqueue(&s->q1, value);
        s->top++;
    }
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        while (s->q1.front != s->q1.rear) {
            enqueue(&s->q2, dequeue(&s->q1));
        }
        int value = dequeue(&s->q1);
        s->top--;
        struct Queue temp = s->q1;
        s->q1 = s->q2;
        s->q2 = temp;
        return value;
    }
}

int isStackEmpty(struct Stack *s) {
    return s->top == -1;
}

int isStackFull(struct Stack *s) {
    return isFull(&s->q1);
}

void displayStack(struct Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        display(&s->q1);
    }
}

int main() {
    struct Stack s;
    initStack(&s);
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if Stack is Full\n");
        printf("4. Check if Stack is Empty\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                if (isStackFull(&s)) {
                    printf("Stack is full\n");
                } else {
                    printf("Stack is not full\n");
                }
                break;
            case 4:
                if (isStackEmpty(&s)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                displayStack(&s);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
