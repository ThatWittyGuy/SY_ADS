#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void partitionList(struct Node** head, int x) {
    struct Node *lessHead = NULL, *greaterHead = NULL;
    struct Node *lessTail = NULL, *greaterTail = NULL;
    struct Node* temp = *head;

    while (temp != NULL) {
        if (temp->data < x) {
            if (lessHead == NULL) {
                lessHead = temp;
                lessTail = lessHead;
            } else {
                lessTail->next = temp;
                lessTail = lessTail->next;
            }
        } else {
            if (greaterHead == NULL) {
                greaterHead = temp;
                greaterTail = greaterHead;
            } else {
                greaterTail->next = temp;
                greaterTail = greaterTail->next;
            }
        }
        temp = temp->next;
    }

    if (lessTail != NULL) {
        lessTail->next = greaterHead;
    }

    if (greaterTail != NULL) {
        greaterTail->next = NULL;
    }

    *head = (lessHead != NULL) ? lessHead : greaterHead;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data, x;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Enter the partition value (x): ");
    scanf("%d", &x);

    printf("Original List: ");
    printList(head);

    partitionList(&head, x);

    printf("Partitioned List: ");
    printList(head);

    return 0;
}
