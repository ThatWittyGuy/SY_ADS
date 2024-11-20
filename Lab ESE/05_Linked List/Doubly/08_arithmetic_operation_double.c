#include <stdio.h>
#include <stdlib.h>

struct Node {
    int digit;
    struct Node* next;
    struct Node* prev;
};

void append(struct Node** head, int digit) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->digit = digit;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->digit);
        head = head->next;
    }
    printf("NULL");
    printf("\n");
}

void performOperation(struct Node* head, int key, char operation) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (operation == '+') {
            temp->digit += key;
        } else if (operation == '-') {
            temp->digit -= key;
        } else if (operation == '*') {
            temp->digit *= key;
        }
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, digit, key;
    char operation;

    printf("Enter the number of digits (max 10): ");
    scanf("%d", &n);
    if (n > 10) {
        printf("Number of digits should be 10 or less.\n");
        return 0;
    }

    printf("Enter %d digits:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &digit);
        append(&head, digit);  // Append elements to maintain input order
    }

    printf("Original List: ");
    printList(head);

    printf("\nEnter a key (an integer) to perform arithmetic operations: ");
    scanf("%d", &key);

    printf("Choose operation:\n + for Addition, - for Subtraction, * for Multiplication: ");
    scanf(" %c", &operation);  // Space before %c to ignore newline

    performOperation(head, key, operation);

    printf("\nList after performing the operation: ");
    printList(head);

    return 0;
}
