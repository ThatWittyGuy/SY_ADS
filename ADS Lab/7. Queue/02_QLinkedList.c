#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

// Function to insert an element into the queue
void insert(int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to delete an element from the queue
void delete() {
    if (front == NULL) {
        printf("Queue Underflow\n");
    } else {
        Node* temp = front;
        printf("Element deleted from queue is: %d\n", front->data);
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        free(temp);
    }
}

// Function to display the elements of the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        Node* temp = front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to demonstrate queue operations
int main() {
    int choice, item;
    while (1) {
        printf("1. Insert element to queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display all elements of queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Insert the element in queue: ");
                scanf("%d", &item);
                insert(item);
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
