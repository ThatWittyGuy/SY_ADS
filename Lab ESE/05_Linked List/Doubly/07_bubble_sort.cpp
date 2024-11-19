#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void InsertEnd(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void PrintList(Node* head) {
    while (head != NULL) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void BubbleSort(Node** head) {
    if (*head == NULL) return;
    bool swapped;
    Node* temp;
    Node* last = NULL;

    do {
        swapped = false;
        temp = *head;

        while (temp->next != last) {
            if (temp->data > temp->next->data) {
                swap(temp->data, temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }
        last = temp;
    } while (swapped);
}

int main() {
    Node* head = NULL;

    InsertEnd(&head, 5);
    InsertEnd(&head, 2);
    InsertEnd(&head, 8);
    InsertEnd(&head, 1);
    InsertEnd(&head, 3);

    cout << "Before Bubble Sort: ";
    PrintList(head);

    BubbleSort(&head);

    cout << "After Bubble Sort: ";
    PrintList(head);

    return 0;
}


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
