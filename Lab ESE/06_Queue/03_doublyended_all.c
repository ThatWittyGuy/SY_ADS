#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct DoubleQueue {
    int front, rear;
    int arr[MAX];
};

void initializeDeque(struct DoubleQueue* dq) {
    dq->front = dq->rear = -1;
}

int isFull(struct DoubleQueue* dq) {
    return (dq->rear + 1) % MAX == dq->front;
}

int isEmpty(struct DoubleQueue* dq) {
    return dq->front == -1;
}

void insertFront(struct DoubleQueue* dq, int value) {
    if (isFull(dq)) {
        printf("DoubleQueue is full. Cannot insert %d at front\n", value);
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = value;
    printf("%d inserted at front\n", value);
}

void insertRear(struct DoubleQueue* dq, int value) {
    if (isFull(dq)) {
        printf("DoubleQueue is full. Cannot insert %d at rear\n", value);
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = value;
    printf("%d inserted at rear\n", value);
}

void deleteFront(struct DoubleQueue* dq) {
    if (isEmpty(dq)) {
        printf("DoubleQueue is empty. Cannot delete from front\n");
        return;
    }
    printf("%d deleted from front\n", dq->arr[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }
}

void deleteRear(struct DoubleQueue* dq) {
    if (isEmpty(dq)) {
        printf("DoubleQueue is empty. Cannot delete from rear\n");
        return;
    }
    printf("%d deleted from rear\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
}

void display(struct DoubleQueue* dq) {
    if (isEmpty(dq)) {
        printf("DoubleQueue is empty\n");
        return;
    }
    int i = dq->front;
    printf("DoubleQueue elements: ");
    while (i != dq->rear) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", dq->arr[dq->rear]);
}

int main() {
    struct DoubleQueue dq;
    initializeDeque(&dq);
    int choice, value;

    while (1) {
        printf("\nDeque Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display All Elements\n");
        printf("6. Check if DoubleQueue is Empty\n");
        printf("7. Check if DoubleQueue is Full\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                if (isEmpty(&dq)) {
                    printf("DoubleQueue is empty\n");
                } else {
                    printf("DoubleQueue is not empty\n");
                }
                break;
            case 7:
                if (isFull(&dq)) {
                    printf("DoubleQueue is full\n");
                } else {
                    printf("DoubleQueue is not full\n");
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
