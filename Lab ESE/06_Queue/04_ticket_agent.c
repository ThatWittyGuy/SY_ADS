#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    int front, rear;
    int arr[MAX];
};

void initializeQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isFull(struct Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void insert(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert passenger.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    printf("Passenger %d added to the queue.\n", value);
}

void removeFront(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No passenger to remove.\n");
        return;
    }
    printf("Passenger %d removed from the queue.\n", q->arr[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

void displayFront(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Passenger at the front: %d\n", q->arr[q->front]);
}

int main() {
    struct Queue q;
    initializeQueue(&q);
    int choice, passengerID;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Passenger at rear\n");
        printf("2. Display Passenger at front\n");
        printf("3. Remove Passenger from front\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Passenger ID to add: ");
                scanf("%d", &passengerID);
                insert(&q, passengerID);
                break;
            case 2:
                displayFront(&q);
                break;
            case 3:
                removeFront(&q);
                break;
            case 4:
                printf("Number of passengers left in queue: ");
                if (isEmpty(&q)) {
                    printf("0\n");
                } else {
                    int count = (q.rear - q.front + MAX) % MAX + 1;
                    printf("%d\n", count);
                }
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
