#include <stdio.h>
#include <stdlib.h>

struct Node {
    int digit;
    struct Node* next;
};

void append(struct Node** head, int digit) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->digit = digit;
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

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->digit);
        head = head->next;
    }
    printf("NULL");
    printf("\n");
}

void performOperation(struct Node* head, int key, char operation) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (operation == '+') {
            temp->digit += key;
        } else if (operation == '-') {
            temp->digit -= key;
        } else if (operation == '*') {
            temp->digit *= key;
        }
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, digit, key;
    char operation;

    printf("Enter the number of digits (max 10): ");
    scanf("%d", &n);
    if (n > 10) {
        printf("Number of digits should be 10 or less.\n");
        return 0;
    }

    printf("Enter %d digits:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &digit);
        append(&head, digit);  // Append elements to maintain input order
    }

    printf("Original List: ");
    printList(head);

    printf("\nEnter a key (an integer) to perform arithmetic operations: ");
    scanf("%d", &key);

    printf("Choose operation:\n + for Addition, - for Subtraction, * for Multiplication: ");
    scanf(" %c", &operation);  // Space before %c to ignore newline

    performOperation(head, key, operation);

    printf("\nList after performing the operation: ");
    printList(head);

    return 0;
}


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
//         cout << head->data << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// Node* AddLists(Node* head1, Node* head2) {
//     Node* result = NULL;
//     Node* temp1 = head1;
//     Node* temp2 = head2;
//     int carry = 0;

//     while (temp1 != NULL || temp2 != NULL || carry != 0) {
//         int sum = carry;
//         if (temp1 != NULL) {
//             sum += temp1->data;
//             temp1 = temp1->next;
//         }
//         if (temp2 != NULL) {
//             sum += temp2->data;
//             temp2 = temp2->next;
//         }
//         carry = sum / 10;
//         InsertEnd(&result, sum % 10);
//     }

//     return result;
// }

// Node* SubtractLists(Node* head1, Node* head2) {
//     Node* result = NULL;
//     Node* temp1 = head1;
//     Node* temp2 = head2;
//     int borrow = 0;

//     while (temp1 != NULL || temp2 != NULL) {
//         int diff = borrow;
//         if (temp1 != NULL) {
//             diff += temp1->data;
//             temp1 = temp1->next;
//         }
//         if (temp2 != NULL) {
//             diff -= temp2->data;
//             temp2 = temp2->next;
//         }
        
//         if (diff < 0) {
//             diff += 10;
//             borrow = -1;
//         } else {
//             borrow = 0;
//         }

//         InsertEnd(&result, diff);
//     }

//     return result;
// }

// int main() {
//     Node* num1 = NULL;
//     Node* num2 = NULL;

//     InsertEnd(&num1, 1);
//     InsertEnd(&num1, 2);
//     InsertEnd(&num1, 3);
//     InsertEnd(&num1, 4);
//     InsertEnd(&num1, 5);
//     InsertEnd(&num1, 6);
//     InsertEnd(&num1, 7);
//     InsertEnd(&num1, 8);
//     InsertEnd(&num1, 9);
//     InsertEnd(&num1, 0);

//     InsertEnd(&num2, 9);
//     InsertEnd(&num2, 9);
//     InsertEnd(&num2, 9);
//     InsertEnd(&num2, 9);
//     InsertEnd(&num2, 9);
//     InsertEnd(&num2, 9);
//     InsertEnd(&num2, 9);
//     InsertEnd(&num2, 9);
//     InsertEnd(&num2, 9);
//     InsertEnd(&num2, 9);

//     cout << "Number 1: ";
//     PrintList(num1);

//     cout << "Number 2: ";
//     PrintList(num2);

//     Node* sum = AddLists(num1, num2);
//     cout << "Sum: ";
//     PrintList(sum);

//     Node* difference = SubtractLists(num1, num2);
//     cout << "Difference: ";
//     PrintList(difference);

//     return 0;
// }
