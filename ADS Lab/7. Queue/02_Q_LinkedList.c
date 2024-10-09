#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if(rear == NULL)
        front = rear = temp;
    else{
        rear->next = temp;
        rear=temp;
    }
}

void dequeue(){
    if(front == NULL)
        printf("Queue Empty\n");
    else{
        Node* temp = front;
        printf("Deleted Element is: %d\n", front->data);
        front = front -> next;
        if(front == NULL){
            rear == NULL;
        }
        free(temp);
    }
}

void display(){
    if(front == NULL)
        printf("Queue Empty");
    else{
        printf("Elements: ");
        Node* temp = front;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, x;
    while (1) {
        printf("\n1. Insert element to queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display all elements of queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Insert the element in queue: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
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
