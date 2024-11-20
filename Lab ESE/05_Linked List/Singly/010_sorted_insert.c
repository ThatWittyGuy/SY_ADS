#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void Append(struct Node** head, int data) {
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

void SortedInsert(struct Node** head, struct Node* newNode) {
    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
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
    struct Node* newNode = NULL;
    int n, data;

    // Get user input for the list
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter %d elements for the list:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        Append(&head, data);  // Append elements to maintain input order
    }

    printf("Original List: ");
    PrintList(head);

    // Get user input for the new node to be inserted
    printf("Enter a value to insert in the sorted list: ");
    scanf("%d", &data);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    SortedInsert(&head, newNode);  // Insert the new node in sorted order

    printf("List after Sorted Insert: ");
    PrintList(head);

    return 0;
}

// OLD CODE
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// void Push(Node** head, int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->next = *head;
//     *head = newNode;
// }

// void SortedInsert(Node** head, Node* newNode) {
//     if (*head == NULL || (*head)->data >= newNode->data) {
//         newNode->next = *head;
//         *head = newNode;
//     } else {
//         Node* current = *head;
//         while (current->next != NULL && current->next->data < newNode->data) {
//             current = current->next;
//         }
//         newNode->next = current->next;
//         current->next = newNode;
//     }
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

//     Push(&head, 10);
//     Push(&head, 5);
//     Push(&head, 1);

//     cout << "Original List: ";
//     PrintList(head);

//     Node* newNode = new Node();
//     newNode->data = 7;

//     SortedInsert(&head, newNode);

//     cout << "List after Sorted Insert: ";
//     PrintList(head);

//     return 0;
// }


// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// void Push(Node** head, int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->next = *head;
//     *head = newNode;
// }

// void SortedInsert(Node** head, Node* newNode) {
//     if (*head == NULL || (*head)->data >= newNode->data) {
//         newNode->next = *head;
//         *head = newNode;
//     } else {
//         Node* current = *head;
//         while (current->next != NULL && current->next->data < newNode->data) {
//             current = current->next;
//         }
//         newNode->next = current->next;
//         current->next = newNode;
//     }
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
//     int n, value;

//     cout << "Enter the number of elements in the list: ";
//     cin >> n;

//     cout << "Enter " << n << " elements in sorted order:" << endl;
//     for (int i = 0; i < n; ++i) {
//         cin >> value;
//         Push(&head, value);
//     }

//     cout << "\nOriginal List: ";
//     PrintList(head);

//     Node* newNode = new Node();
//     cout << "\nEnter the new value to insert: ";
//     cin >> newNode->data;

//     SortedInsert(&head, newNode);

//     cout << "\nList after Sorted Insert: ";
//     PrintList(head);

//     return 0;
// }
