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

Node* CopyList(Node* head) {
    if (head == NULL) return NULL;

    Node* newHead = NULL;
    Node* newTail = NULL;

    while (head != NULL) {
        Node* newNode = new Node();
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

    Node* copiedList = CopyList(head);

    cout << "Copied List: ";
    PrintList(copiedList);

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
