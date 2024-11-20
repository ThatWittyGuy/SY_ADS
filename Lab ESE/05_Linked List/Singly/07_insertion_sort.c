#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void InsertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void InsertSorted(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->data < data) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void InsertionSort(struct Node** head) {
    struct Node* sorted = NULL;
    struct Node* current = *head;
    while (current != NULL) {
        struct Node* next = current->next;
        InsertSorted(&sorted, current->data);
        current = next;
    }
    *head = sorted;
}

void PrintList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        InsertEnd(&head, data);
    }

    printf("Before Insertion Sort: ");
    PrintList(head);

    InsertionSort(&head);

    printf("After Insertion Sort: ");
    PrintList(head);

    return 0;
}

// C++ code
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// void InsertEnd(Node** head, int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->next = NULL;
    
//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         Node* temp = *head;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// void InsertSorted(Node** head, int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->next = NULL;

//     if (*head == NULL || (*head)->data >= data) {
//         newNode->next = *head;
//         *head = newNode;
//     } else {
//         Node* temp = *head;
//         while (temp->next != NULL && temp->next->data < data) {
//             temp = temp->next;
//         }
//         newNode->next = temp->next;
//         temp->next = newNode;
//     }
// }

// void InsertionSort(Node** head) {
//     Node* sorted = NULL;
//     Node* current = *head;
//     while (current != NULL) {
//         Node* next = current->next;
//         InsertSorted(&sorted, current->data);
//         current = next;
//     }
//     *head = sorted;
// }

// void PrintList(Node* head) {
//     while (head != NULL) {
//         cout << head->data << " -> ";
//         head = head->next;
//     }
//     cout << "NULL" << endl;
// }

// int main() {
//     Node* head = NULL;
    
//     InsertEnd(&head, 5);
//     InsertEnd(&head, 2);
//     InsertEnd(&head, 8);
//     InsertEnd(&head, 1);
//     InsertEnd(&head, 3);

//     cout << "Before Insertion Sort: ";
//     PrintList(head);

//     InsertionSort(&head);

//     cout << "After Insertion Sort: ";
//     PrintList(head);

//     return 0;
// }
