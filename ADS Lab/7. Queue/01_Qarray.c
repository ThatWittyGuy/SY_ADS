#include <stdio.h>
#include <stdlib.h>

#define MAX 50  // Maximum size of the queue

int queue[MAX];
int front = -1;
int rear = -1;

// Function to insert an element into the queue
void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {
            front = 0;  // Initialize front if the queue is empty
        }
        printf("Insert the element in queue: ");
        scanf("%d", &item);
        rear++;
        queue[rear] = item;
    }
}

// Function to delete an element from the queue
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Element deleted from queue is: %d\n", queue[front]);
        front++;
    }
}

// Function to display the elements of the queue
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function to demonstrate queue operations
int main() {
    int choice;
    while (1) {
        printf("\n1. Insert element to queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display all elements of queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
