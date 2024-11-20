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

struct Node* findKthFromEnd(struct Node* head, int k) {
    struct Node* first = head;
    struct Node* second = head;
    
    for (int i = 0; i < k; i++) {
        if (first == NULL) {
            return NULL;
        }
        first = first->next;
    }
    
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    
    return second;
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
    int n, data, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    struct Node* result = findKthFromEnd(head, k);
    if (result != NULL) {
        printf("The %d-th node from the end is: %d\n", k, result->data);
    } else {
        printf("The list has fewer than %d nodes.\n", k);
    }

    return 0;
}
