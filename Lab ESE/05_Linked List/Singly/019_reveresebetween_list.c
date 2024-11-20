#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void reverseBetween(struct ListNode **head, int startIndex, int endIndex) {
    if (*head == NULL || startIndex == endIndex) return;

    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = *head;
    struct ListNode *prev = dummy;

    // Move `prev` to the node just before the startIndex
    for (int i = 1; i < startIndex; i++) {
        prev = prev->next;
    }

    struct ListNode *curr = prev->next;
    struct ListNode *next = NULL;
    
    // Reverse the sublist from startIndex to endIndex
    for (int i = startIndex; i < endIndex; i++) {  // Only reverse until endIndex - 1
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    *head = dummy->next;
    free(dummy);
}

void printList(struct ListNode *head) {
    struct ListNode *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

struct ListNode* createList(int size) {
    struct ListNode *head = NULL, *temp = NULL;
    int value;
    for (int i = 0; i < size; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

int main() {
    int size, startIndex, endIndex;

    printf("Enter the number of nodes: ");
    scanf("%d", &size);

    struct ListNode *head = createList(size);

    printf("Enter start index and end index for reversal: ");
    scanf("%d %d", &startIndex, &endIndex);

    printf("Original List: ");
    printList(head);

    reverseBetween(&head, startIndex, endIndex);

    printf("Reversed List: ");
    printList(head);

    return 0;
}
