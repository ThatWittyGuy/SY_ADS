#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* CopyList(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* newHead = NULL;
    struct Node* newTail = NULL;

    while (head != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = head->data;
        newNode->next = NULL;

        if (newHead == NULL) {
            newHead = newNode;
            newTail = newNode;
        } else {
            newTail->next = newNode;
            newTail = newNode;
        }

        head = head->next;
    }

    return newHead;
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
    struct Node* newHead = NULL;
    struct Node* temp;
    int n, data;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    printf("Original List: ");
    PrintList(head);

    newHead = CopyList(head);

    printf("Copied List: ");
    PrintList(newHead);

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

// Node* CopyList(Node* head) {
//     if (head == NULL) return NULL;

//     Node* newHead = NULL;
//     Node* newTail = NULL;

//     while (head != NULL) {
//         Node* newNode = new Node();
//         newNode->data = head->data;
//         newNode->next = NULL;

//         if (newHead == NULL) {
//             newHead = newNode;
//             newTail = newNode;
//         } else {
//             newTail->next = newNode;
//             newTail = newNode;
//         }

//         head = head->next;
//     }

//     return newHead;
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

//     Node* copiedList = CopyList(head);

//     cout << "Copied List: ";
//     PrintList(copiedList);

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

// Node* CopyList(Node* head) {
//     if (head == NULL) return NULL;

//     Node* newHead = NULL;
//     Node* newTail = NULL;

//     while (head != NULL) {
//         Node* newNode = new Node();
//         newNode->data = head->data;
//         newNode->next = NULL;

//         if (newHead == NULL) {
//             newHead = newNode;
//             newTail = newNode;
//         } else {
//             newTail->next = newNode;
//             newTail = newNode;
//         }

//         head = head->next;
//     }

//     return newHead;
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

//     cout << "Enter " << n << " elements:" << endl;
//     for (int i = 0; i < n; ++i) {
//         cin >> value;
//         Push(&head, value);
//     }

//     cout << "\nOriginal List: ";
//     PrintList(head);

//     Node* copiedList = CopyList(head);

//     cout << "Copied List: ";
//     PrintList(copiedList);

//     return 0;
// }
