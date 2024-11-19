#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void Push(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void SortedInsert(Node** head, Node* newNode) {
    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void PrintList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    Push(&head, 10);
    Push(&head, 5);
    Push(&head, 1);

    cout << "Original List: ";
    PrintList(head);

    Node* newNode = new Node();
    newNode->data = 7;

    SortedInsert(&head, newNode);

    cout << "List after Sorted Insert: ";
    PrintList(head);

    return 0;
}


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
