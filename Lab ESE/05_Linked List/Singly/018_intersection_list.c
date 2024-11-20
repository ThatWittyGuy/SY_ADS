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

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* intersectionHead = NULL;
    struct Node* intersectionTail = NULL;
    
    struct Node* temp1 = head1;
    
    while (temp1 != NULL) {
        struct Node* temp2 = head2;
        
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = temp1->data;
                newNode->next = NULL;

                if (intersectionHead == NULL) {
                    intersectionHead = newNode;
                    intersectionTail = newNode;
                } else {
                    intersectionTail->next = newNode;
                    intersectionTail = intersectionTail->next;
                }
                break;  // Found a common element, no need to check further for this element
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return intersectionHead;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int n, data;

    printf("Enter the number of elements for the first list: ");
    scanf("%d", &n);
    printf("Enter the elements for the first list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head1, data);
    }

    printf("Enter the number of elements for the second list: ");
    scanf("%d", &n);
    printf("Enter the elements for the second list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head2, data);
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL) {
        printf("Intersection (common elements): ");
        printList(intersection);
    } else {
        printf("No common elements.\n");
    }

    return 0;
}
