// Write a program to implement singly linked list and 
// perform the following operations a) Insert at beginning b) Insert at end 
// c) Insert after specified node d) delete at beginning e) delete at end f) delete after specified node g) display h) search an element

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void insertAfter(int key, int data) {
    struct Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (temp) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Element %d not found\n", key);
    }
}

void deleteAtBeginning() {
    if (head) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    } else {
        printf("List is empty\n");
    }
}

void deleteAtEnd() {
    if (head) {
        if (!head->next) {
            free(head);
            head = NULL;
        } else {
            struct Node* temp = head;
            while (temp->next->next) temp = temp->next;
            free(temp->next);
            temp->next = NULL;
        }
    } else {
        printf("List is empty\n");
    }
}

void deleteAfter(int key) {
    struct Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (temp && temp->next) {
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    } else {
        printf("Element %d not found or no node to delete after it\n", key);
    }
}

void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search(int key) {
    struct Node* temp = head;
    int position = 1;
    while (temp) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found\n", key);
}

int main() {
    int choice, data, key;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete After a Node\n");
        printf("7. Display List\n");
        printf("8. Search Element\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter value to insert after: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertAfter(key, data);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter value to delete after: ");
                scanf("%d", &key);
                deleteAfter(key);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}
