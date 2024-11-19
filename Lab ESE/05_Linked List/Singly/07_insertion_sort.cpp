#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void InsertEnd(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void InsertSorted(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL && temp->next->data < data) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void InsertionSort(Node** head) {
    Node* sorted = NULL;
    Node* current = *head;
    while (current != NULL) {
        Node* next = current->next;
        InsertSorted(&sorted, current->data);
        current = next;
    }
    *head = sorted;
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
    
    InsertEnd(&head, 5);
    InsertEnd(&head, 2);
    InsertEnd(&head, 8);
    InsertEnd(&head, 1);
    InsertEnd(&head, 3);

    cout << "Before Insertion Sort: ";
    PrintList(head);

    InsertionSort(&head);

    cout << "After Insertion Sort: ";
    PrintList(head);

    return 0;
}
