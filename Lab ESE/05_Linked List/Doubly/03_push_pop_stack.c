#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* top = NULL;

// Push data onto the stack
void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = top;

    if (top != NULL) {
        top->next = newNode;
    }
    top = newNode;
}

// Pop data from the stack and print the popped element
void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = top;
    top = top->prev;

    if (top != NULL) {
        top->next = NULL;
    }

    printf("Popped element: %d\n", temp->data);  // Print the data of the popped element
    free(temp);
}

// Display the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* prev;
// };

// Node* top = nullptr;

// void push(int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->next = nullptr;
//     newNode->prev = top;

//     if (top != nullptr) {
//         top->next = newNode;
//     }
//     top = newNode;
// }

// void pop() {
//     if (top == nullptr) {
//         cout << "Stack is empty\n";
//         return;
//     }

//     Node* temp = top;
//     top = top->prev;

//     if (top != nullptr) {
//         top->next = nullptr;
//     }

//     delete temp;
// }

// void display() {
//     if (top == nullptr) {
//         cout << "Stack is empty\n";
//         return;
//     }

//     Node* temp = top;
//     while (temp != nullptr) {
//         cout << temp->data << " ";
//         temp = temp->prev;
//     }
//     cout << endl;
// }

// int main() {
//     int choice, data;

//     while (true) {
//         cout << "1. Push\n";
//         cout << "2. Pop\n";
//         cout << "3. Display\n";
//         cout << "4. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter data to push: ";
//                 cin >> data;
//                 push(data);
//                 break;
//             case 2:
//                 pop();
//                 break;
//             case 3:
//                 display();
//                 break;
//             case 4:
//                 return 0;
//             default:
//                 cout << "Invalid choice\n";
//         }
//     }

//     return 0;
// }
