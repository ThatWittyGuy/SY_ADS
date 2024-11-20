// Write a program to implement Linear queue using array and perform the
// following operations a)Insert b)delete c)peek d)queue full() e)queue empty()

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Queue {
    int front, rear;
    int arr[MAX];
};

void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue* q) {
    if (q->rear == MAX - 1)
        return 1;
    return 0;
}

int isEmpty(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear)
        return 1;
    return 0;
}

void insert(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert %d\n", value);
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->arr[q->rear] = value;
    printf("%d inserted into queue\n", value);
}

void delete(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot delete\n");
        return;
    }
    printf("%d deleted from queue\n", q->arr[q->front]);
    q->front++;
}

int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot peek\n");
        return -1;
    }
    return q->arr[q->front];
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    int choice, value;
    initializeQueue(&q);

    while(1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Queue is Empty\n");
        printf("6. Check if Queue is Full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&q, value);
                break;
            case 2:
                delete(&q);
                break;
            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Peek: %d\n", value);
                }
                break;
            case 4:
                display(&q);
                break;
            case 5:
                if (isEmpty(&q)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 6:
                if (isFull(&q)) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
