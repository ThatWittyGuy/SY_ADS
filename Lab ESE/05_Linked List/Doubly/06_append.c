#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void InsertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void InsertFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void AppendToFront(struct Node** head1, struct Node** head2) {
    if (*head2 == NULL) return;
    struct Node* temp = *head2;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *head1;
    if (*head1 != NULL) {
        (*head1)->prev = temp;
    }
    *head1 = *head2;
    *head2 = NULL;
}

void AppendToEnd(struct Node** head1, struct Node** head2) {
    if (*head2 == NULL) return;
    if (*head1 == NULL) {
        *head1 = *head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = *head2;
        (*head2)->prev = temp;
    }
    *head2 = NULL;
}

void PrintList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at end of List 1\n");
        printf("2. Insert at end of List 2\n");
        printf("3. Append List 2 to the start of List 1\n");
        printf("4. Append List 2 to the end of List 1\n");
        printf("5. Print List 1\n");
        printf("6. Print List 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert into List 1: ");
                scanf("%d", &data);
                InsertEnd(&list1, data);
                break;
            case 2:
                printf("Enter data to insert into List 2: ");
                scanf("%d", &data);
                InsertEnd(&list2, data);
                break;
            case 3:
                AppendToFront(&list1, &list2);
                printf("List 2 appended to the start of List 1.\n");
                break;
            case 4:
                AppendToEnd(&list1, &list2);
                printf("List 2 appended to the end of List 1.\n");
                break;
            case 5:
                printf("List 1: ");
                PrintList(list1);
                break;
            case 6:
                printf("List 2: ");
                PrintList(list2);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}



// OLD C++ CODE
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* prev;
//     Node* next;
// };

// void InsertEnd(Node** head, int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->next = NULL;
//     if (*head == NULL) {
//         newNode->prev = NULL;
//         *head = newNode;
//         return;
//     }
//     Node* temp = *head;
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }
//     temp->next = newNode;
//     newNode->prev = temp;
// }

// void InsertFront(Node** head, int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->prev = NULL;
//     newNode->next = *head;
//     if (*head != NULL) {
//         (*head)->prev = newNode;
//     }
//     *head = newNode;
// }

// void AppendToFront(Node** head1, Node** head2) {
//     if (*head2 == NULL) return;
//     Node* temp = *head2;
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }
//     temp->next = *head1;
//     if (*head1 != NULL) {
//         (*head1)->prev = temp;
//     }
//     *head1 = *head2;
//     *head2 = NULL;
// }

// void AppendToEnd(Node** head1, Node** head2) {
//     if (*head2 == NULL) return;
//     if (*head1 == NULL) {
//         *head1 = *head2;
//     } else {
//         Node* temp = *head1;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = *head2;
//         (*head2)->prev = temp;
//     }
//     *head2 = NULL;
// }

// void PrintList(Node* head) {
//     if (head == NULL) {
//         cout << "List is empty." << endl;
//         return;
//     }
//     while (head != NULL) {
//         cout << head->data << " <-> ";
//         head = head->next;
//     }
//     cout << "NULL" << endl;
// }

// int main() {
//     Node* list1 = NULL;
//     Node* list2 = NULL;
//     int choice, data;

//     do {
//         cout << "\nMenu:" << endl;
//         cout << "1. Insert at end of List 1" << endl;
//         cout << "2. Insert at end of List 2" << endl;
//         cout << "3. Append List 2 to the start of List 1" << endl;
//         cout << "4. Append List 2 to the end of List 1" << endl;
//         cout << "5. Print List 1" << endl;
//         cout << "6. Print List 2" << endl;
//         cout << "7. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter data to insert into List 1: ";
//                 cin >> data;
//                 InsertEnd(&list1, data);
//                 break;
//             case 2:
//                 cout << "Enter data to insert into List 2: ";
//                 cin >> data;
//                 InsertEnd(&list2, data);
//                 break;
//             case 3:
//                 AppendToFront(&list1, &list2);
//                 cout << "List 2 appended to the start of List 1." << endl;
//                 break;
//             case 4:
//                 AppendToEnd(&list1, &list2);
//                 cout << "List 2 appended to the end of List 1." << endl;
//                 break;
//             case 5:
//                 cout << "List 1: ";
//                 PrintList(list1);
//                 break;
//             case 6:
//                 cout << "List 2: ";
//                 PrintList(list2);
//                 break;
//             case 7:
//                 cout << "Exiting..." << endl;
//                 break;
//             default:
//                 cout << "Invalid choice! Please try again." << endl;
//         }
//     } while (choice != 7);

//     return 0;
// }



// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* prev;
//     Node* next;
// };

// void InsertEnd(Node** head, int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->next = NULL;
//     if (*head == NULL) {
//         newNode->prev = NULL;
//         *head = newNode;
//         return;
//     }
//     Node* temp = *head;
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }
//     temp->next = newNode;
//     newNode->prev = temp;
// }

// void InsertFront(Node** head, int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->prev = NULL;
//     newNode->next = *head;
//     if (*head != NULL) {
//         (*head)->prev = newNode;
//     }
//     *head = newNode;
// }

// void AppendToFront(Node** head1, Node** head2) {
//     if (*head2 == NULL) return;
//     Node* temp = *head2;
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }
//     temp->next = *head1;
//     if (*head1 != NULL) {
//         (*head1)->prev = temp;
//     }
//     *head1 = *head2;
//     *head2 = NULL;
// }

// void AppendToEnd(Node** head1, Node** head2) {
//     if (*head2 == NULL) return;
//     if (*head1 == NULL) {
//         *head1 = *head2;
//     } else {
//         Node* temp = *head1;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = *head2;
//         (*head2)->prev = temp;
//     }
//     *head2 = NULL;
// }

// void PrintList(Node* head) {
//     while (head != NULL) {
//         cout << head->data << " <-> ";
//         head = head->next;
//     }
//     cout << "NULL" << endl;
// }

// int main() {
//     Node* list1 = NULL;
//     Node* list2 = NULL;

//     InsertEnd(&list1, 1);
//     InsertEnd(&list1, 2);
//     InsertEnd(&list1, 3);

//     InsertEnd(&list2, 4);
//     InsertEnd(&list2, 5);
    
//     cout << "List1: ";
//     PrintList(list1);
//     cout << "List2: ";
//     PrintList(list2);

//     AppendToFront(&list1, &list2);
//     cout << "List1 after appending list2 to front: ";
//     PrintList(list1);

//     InsertEnd(&list2, 6);
//     cout << "List2 after insert: ";
//     PrintList(list2);

//     AppendToEnd(&list1, &list2);
//     cout << "List1 after appending list2 to end: ";
//     PrintList(list1);

//     return 0;
// }
