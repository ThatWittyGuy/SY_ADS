#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void InsertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
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

void PrintList(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void BubbleSort(struct Node** head) {
    if (*head == NULL) return;
    int swapped;
    struct Node* temp;
    struct Node* last = NULL;

    do {
        swapped = 0;
        temp = *head;

        while (temp->next != last) {
            if (temp->data > temp->next->data) {
                // Swap data between nodes
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = 1;
            }
            temp = temp->next;
        }
        last = temp;
    } while (swapped);
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        InsertEnd(&head, data);
    }

    printf("Before Bubble Sort: ");
    PrintList(head);

    BubbleSort(&head);

    printf("After Bubble Sort: ");
    PrintList(head);

    return 0;
}


// C++ code
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* prev;
// };

// void InsertEnd(Node** head, int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->next = NULL;
//     newNode->prev = NULL;

//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         Node* temp = *head;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//         newNode->prev = temp;
//     }
// }

// void PrintList(Node* head) {
//     while (head != NULL) {
//         cout << head->data << " <-> ";
//         head = head->next;
//     }
//     cout << "NULL" << endl;
// }

// void BubbleSort(Node** head) {
//     if (*head == NULL) return;
//     bool swapped;
//     Node* temp;
//     Node* last = NULL;

//     do {
//         swapped = false;
//         temp = *head;

//         while (temp->next != last) {
//             if (temp->data > temp->next->data) {
//                 swap(temp->data, temp->next->data);
//                 swapped = true;
//             }
//             temp = temp->next;
//         }
//         last = temp;
//     } while (swapped);
// }

// int main() {
//     Node* head = NULL;

//     InsertEnd(&head, 5);
//     InsertEnd(&head, 2);
//     InsertEnd(&head, 8);
//     InsertEnd(&head, 1);
//     InsertEnd(&head, 3);

//     cout << "Before Bubble Sort: ";
//     PrintList(head);

//     BubbleSort(&head);

//     cout << "After Bubble Sort: ";
//     PrintList(head);

//     return 0;
// }


// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* prev;
// };

// void InsertEnd(Node** head, int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->next = NULL;
//     newNode->prev = NULL;

//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         Node* temp = *head;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//         newNode->prev = temp;
//     }
// }

// void PrintList(Node* head) {
//     while (head != NULL) {
//         cout << head->data << " <-> ";
//         head = head->next;
//     }
//     cout << "NULL" << endl;
// }

// void BubbleSort(Node** head) {
//     if (*head == NULL) return;
//     bool swapped;
//     Node* temp;
//     Node* last = NULL;

//     do {
//         swapped = false;
//         temp = *head;

//         while (temp->next != last) {
//             if (temp->data > temp->next->data) {
//                 swap(temp->data, temp->next->data);
//                 swapped = true;
//             }
//             temp = temp->next;
//         }
//         last = temp;
//     } while (swapped);
// }

// int main() {
//     Node* head = NULL;
//     int n, value;

//     cout << "Enter the number of elements: ";
//     cin >> n;

//     cout << "Enter " << n << " elements:" << endl;
//     for (int i = 0; i < n; ++i) {
//         cin >> value;
//         InsertEnd(&head, value);
//     }

//     cout << "\nBefore Bubble Sort: ";
//     PrintList(head);

//     BubbleSort(&head);

//     cout << "After Bubble Sort: ";
//     PrintList(head);

//     return 0;
// }
