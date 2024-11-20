#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = NULL;

    int collisions = 0;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node* current = hashTable[index];
        while (current != NULL) {
            collisions++;
            current = current->next;
        }
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
    printf("Inserted %d with %d collisions\n", key, collisions);
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* current = hashTable[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, value;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &value);
        insert(value);
    }

    display();
    return 0;
}

// #include <stdio.h>

// #define TABLE_SIZE 10

// int hashTable[TABLE_SIZE];

// int hash(int key) {
//     return key % TABLE_SIZE;
// }

// void insert(int key) {
//     int index = hash(key);
//     int originalIndex = index;
//     int collisions = 0;

//     while (hashTable[index] != 0) {
//         collisions++;
//         index = (index + 1) % TABLE_SIZE;  // Linear probing
//         if (index == originalIndex) {
//             printf("Table is full\n");
//             return;
//         }
//     }

//     hashTable[index] = key;
//     printf("Inserted %d with %d collisions\n", key, collisions);
// }

// void display() {
//     for (int i = 0; i < TABLE_SIZE; i++) {
//         if (hashTable[i] != 0) {
//             printf("Index %d: %d\n", i, hashTable[i]);
//         }
//     }
// }

// int main() {
//     int n, value;
//     printf("Enter number of elements to insert: ");
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         printf("Enter element %d: ", i+1);
//         scanf("%d", &value);
//         insert(value);
//     }

//     display();
//     return 0;
// }
