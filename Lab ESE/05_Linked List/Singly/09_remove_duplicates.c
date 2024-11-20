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

void PrintList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void RemoveDuplicates(struct Node* head) {
    if (head == NULL) return;
    
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        InsertEnd(&head, value);
    }

    printf("\nBefore removing duplicates: ");
    PrintList(head);

    RemoveDuplicates(head);

    printf("After removing duplicates: ");
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

// void PrintList(Node* head) {
//     while (head != NULL) {
//         cout << head->data << " -> ";
//         head = head->next;
//     }
//     cout << "NULL" << endl;
// }

// void RemoveDuplicates(Node* head) {
//     if (head == NULL) return;
    
//     Node* current = head;
//     while (current != NULL && current->next != NULL) {
//         if (current->data == current->next->data) {
//             Node* temp = current->next;
//             current->next = current->next->next;
//             delete temp;
//         } else {
//             current = current->next;
//         }
//     }
// }

// int main() {
//     Node* head = NULL;

//     InsertEnd(&head, 1);
//     InsertEnd(&head, 2);
//     InsertEnd(&head, 2);
//     InsertEnd(&head, 3);
//     InsertEnd(&head, 3);
//     InsertEnd(&head, 4);
//     InsertEnd(&head, 5);

//     cout << "Before removing duplicates: ";
//     PrintList(head);

//     RemoveDuplicates(head);

//     cout << "After removing duplicates: ";
//     PrintList(head);

//     return 0;
// }


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

// void PrintList(Node* head) {
//     while (head != NULL) {
//         cout << head->data << " -> ";
//         head = head->next;
//     }
//     cout << "NULL" << endl;
// }

// void RemoveDuplicates(Node* head) {
//     if (head == NULL) return;
    
//     Node* current = head;
//     while (current != NULL && current->next != NULL) {
//         if (current->data == current->next->data) {
//             Node* temp = current->next;
//             current->next = current->next->next;
//             delete temp;
//         } else {
//             current = current->next;
//         }
//     }
// }

// int main() {
//     Node* head = NULL;
//     int n, value;

//     cout << "Enter the number of elements: ";
//     cin >> n;

//     cout << "Enter " << n << " elements in sorted order:" << endl;
//     for (int i = 0; i < n; ++i) {
//         cin >> value;
//         InsertEnd(&head, value);
//     }

//     cout << "\nBefore removing duplicates: ";
//     PrintList(head);

//     RemoveDuplicates(head);

//     cout << "After removing duplicates: ";
//     PrintList(head);

//     return 0;
// }
