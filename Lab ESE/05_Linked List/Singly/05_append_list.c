#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Append(struct Node **a, struct Node **b)
{
    if (*a == NULL)
    {
        *a = *b;
    }
    else
    {
        struct Node *temp = *a;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = *b;
    }
    *b = NULL;
}

void PrintList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node *CreateNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    struct Node *a = NULL, *b = NULL;

    a = CreateNode(1);
    a->next = CreateNode(2);

    b = CreateNode(3);
    b->next = CreateNode(4);

    Append(&a, &b);

    PrintList(a);
    return 0;
}

// C++
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

// void Append(Node** a, Node** b) {
//     if (*a == NULL) {
//         *a = *b;
//     } else {
//         Node* temp = *a;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = *b;
//     }
//     *b = NULL;
// }

// void PrintList(Node* head) {
//     while (head != NULL) {
//         cout << head->data << " -> ";
//         head = head->next;
//     }
//     cout << "NULL" << endl;
// }

// int main() {
//     Node* a = NULL;
//     Node* b = NULL;
//     int n, value;

//     cout << "Enter the number of elements for list a: ";
//     cin >> n;
//     cout << "Enter " << n << " elements for list a:" << endl;
//     for (int i = 0; i < n; ++i) {
//         cin >> value;
//         Push(&a, value);
//     }

//     cout << "Enter the number of elements for list b: ";
//     cin >> n;
//     cout << "Enter " << n << " elements for list b:" << endl;
//     for (int i = 0; i < n; ++i) {
//         cin >> value;
//         Push(&b, value);
//     }

//     cout << "\nList a before append: ";
//     PrintList(a);
//     cout << "List b before append: ";
//     PrintList(b);

//     Append(&a, &b);

//     cout << "\nList a after append: ";
//     PrintList(a);
//     cout << "List b after append: ";
//     PrintList(b);

//     return 0;
// }
