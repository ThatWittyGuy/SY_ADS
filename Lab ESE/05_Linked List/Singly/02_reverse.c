#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
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

void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf("Original List: ");
    display(head);

    reverse(&head);

    printf("Reversed List: ");
    display(head);

    return 0;
}


// C++ code
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// Node* createNode(int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->next = nullptr;
//     return newNode;
// }

// void insertEnd(Node*& head, int data) {
//     Node* newNode = createNode(data);
//     if (head == nullptr) {
//         head = newNode;
//     } else {
//         Node* temp = head;
//         while (temp->next != nullptr) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// void reverse(Node*& head) {
//     Node* prev = nullptr;
//     Node* curr = head;
//     Node* next = nullptr;

//     while (curr != nullptr) {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }

//     head = prev;
// }

// void display(Node* head) {
//     while (head != nullptr) {
//         cout << head->data << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// int main() {
//     Node* head = nullptr;
//     int n, data;

//     cout << "Enter number of elements: ";
//     cin >> n;

//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> data;
//         insertEnd(head, data);
//     }

//     cout << "Original List: ";
//     display(head);

//     reverse(head);

//     cout << "Reversed List: ";
//     display(head);

//     return 0;
// }
