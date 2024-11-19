#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct CircularQueue {
    int front, rear;
    int arr[MAX];
};

void initializeQueue(struct CircularQueue* q) {
    q->front = q->rear = -1;
}

int isFull(struct CircularQueue* q) {
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(struct CircularQueue* q) {
    return q->front == -1;
}

void insert(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert %d\n", value);
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    printf("%d inserted into queue\n", value);
}

void dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot delete\n");
        return;
    }
    printf("%d deleted from queue\n", q->arr[q->front]);
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MAX;
}

void displayFront(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", q->arr[q->front]);
}

void displayRear(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Rear element: %d\n", q->arr[q->rear]);
}

void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->arr[q->rear]);
}

int main() {
    struct CircularQueue q;
    initializeQueue(&q);
    int choice, value;

    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display Front\n");
        printf("4. Display Rear\n");
        printf("5. Display All Elements\n");
        printf("6. Check if Queue is Empty\n");
        printf("7. Check if Queue is Full\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayFront(&q);
                break;
            case 4:
                displayRear(&q);
                break;
            case 5:
                display(&q);
                break;
            case 6:
                if (isEmpty(&q)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 7:
                if (isFull(&q)) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
