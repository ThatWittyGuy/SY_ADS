#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Insert at the beginning of the list
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at the end of the list
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }
}

// Insert after a specific node
void insertAfter(int key, int data) {
    struct Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (temp) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }
}

// Delete node at the beginning
void deleteAtBeginning() {
    if (head) {
        struct Node* temp = head;
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            struct Node* last = head->prev;
            head = head->next;
            last->next = head;
            head->prev = last;
            free(temp);
        }
    }
}

// Delete node at the end
void deleteAtEnd() {
    if (head) {
        struct Node* temp = head;
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            while (temp->next != head) temp = temp->next;
            temp->prev->next = head;
            head->prev = temp->prev;
            free(temp);
        }
    }
}

// Delete node after a specific key
void deleteAfter(int key) {
    struct Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (temp && temp->next != head) {
        struct Node* toDelete = temp->next;
        temp->next = toDelete->next;
        toDelete->next->prev = temp;
        free(toDelete);
    }
}

// Display the list
void display() {
    if (head) {
        struct Node* temp = head;
        do {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("(head)\n");
    } else {
        printf("List is empty\n");
    }
}

// Search for an element in the list
void search(int key) {
    struct Node* temp = head;
    int position = 1;  // Start counting positions from 1
    if (temp) {
        do {
            if (temp->data == key) {
                printf("Element %d found at position %d\n", key, position);
                return;
            }
            temp = temp->next;
            position++;
        } while (temp != head);
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
        printf("8. Search for an Element\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 3:
                printf("Enter the key after which to insert: ");
                scanf("%d", &key);
                printf("Enter data to insert after %d: ", key);
                scanf("%d", &data);
                insertAfter(key, data);
                break;

            case 4:
                deleteAtBeginning();
                printf("Deleted node from the beginning.\n");
                break;

            case 5:
                deleteAtEnd();
                printf("Deleted node from the end.\n");
                break;

            case 6:
                printf("Enter the key after which to delete: ");
                scanf("%d", &key);
                deleteAfter(key);
                printf("Deleted node after %d.\n", key);
                break;

            case 7:
                printf("Circular Doubly Linked List: ");
                display();
                break;

            case 8:
                printf("Enter data to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
