### Explanation of the Singly Linked List Program:

This program implements a **Singly Linked List** in C with basic operations, such as inserting, deleting, displaying, and searching elements. Below is the breakdown of the program.

---

### **1. Header Files and Structure Definition**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
```

- **`#include <stdio.h>`**: Provides standard input/output functions like `printf` and `scanf`.
- **`#include <stdlib.h>`**: Includes functions for memory allocation (`malloc` and `free`).
- **`#include <string.h>`**: Contains functions for string manipulation, although not directly needed here.
- **`#include <ctype.h>`**: Provides functions to check characters' types (`isdigit`, etc.).

- **`struct Node`**: Defines the structure of a **node** in the linked list:
  - `data`: An integer to store the node's data.
  - `next`: A pointer to the next node in the list.
  
- **`head`**: A pointer to the first node in the list, initially set to `NULL` to represent an empty list.

---

### **2. Insert at Beginning**

```c
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
```

- **Purpose**: Inserts a new node at the beginning of the linked list.
- **Explanation**:
  - Allocate memory for a new node.
  - Set the node's `data` field to the input value.
  - Point the `next` field of the new node to the current `head` (i.e., the first node).
  - Update `head` to point to the new node, making it the new first node.

---

### **3. Insert at End**

```c
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}
```

- **Purpose**: Inserts a new node at the end of the linked list.
- **Explanation**:
  - Allocate memory for a new node and set its `data` field.
  - Set `next` of the new node to `NULL`, as it will be the last node.
  - If the list is empty (`head == NULL`), set `head` to the new node.
  - If the list is not empty, traverse to the last node using a `while` loop (`temp->next`), and set its `next` pointer to the new node.

---

### **4. Insert After Specified Node**

```c
void insertAfter(int key, int data) {
    struct Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (temp) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Element %d not found\n", key);
    }
}
```

- **Purpose**: Inserts a new node after a specified node (identified by `key`).
- **Explanation**:
  - Traverse the list to find the node with the value `key`.
  - If found, allocate memory for a new node, set its `data`, and update the `next` pointer to the next node of the found node.
  - Update the `next` pointer of the found node to point to the new node.
  - If `key` is not found, print an error message.

---

### **5. Delete at Beginning**

```c
void deleteAtBeginning() {
    if (head) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    } else {
        printf("List is empty\n");
    }
}
```

- **Purpose**: Deletes the node at the beginning of the list.
- **Explanation**:
  - If the list is not empty (`head != NULL`), store the current `head` in `temp`.
  - Update `head` to the next node in the list (`head->next`).
  - Free the memory of the original `head` node.
  - If the list is empty, print an error message.

---

### **6. Delete at End**

```c
void deleteAtEnd() {
    if (head) {
        if (!head->next) {
            free(head);
            head = NULL;
        } else {
            struct Node* temp = head;
            while (temp->next->next) temp = temp->next;
            free(temp->next);
            temp->next = NULL;
        }
    } else {
        printf("List is empty\n");
    }
}
```

- **Purpose**: Deletes the node at the end of the list.
- **Explanation**:
  - If the list is not empty:
    - If there is only one node (`head->next == NULL`), free the `head` node and set `head` to `NULL`.
    - Otherwise, traverse the list to find the second-to-last node (`temp->next->next == NULL`).
    - Free the last node and update the second-to-last node's `next` pointer to `NULL`.
  - If the list is empty, print an error message.

---

### **7. Delete After Specified Node**

```c
void deleteAfter(int key) {
    struct Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (temp && temp->next) {
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    } else {
        printf("Element %d not found or no node to delete after it\n", key);
    }
}
```

- **Purpose**: Deletes the node after a specified node (identified by `key`).
- **Explanation**:
  - Traverse the list to find the node with the value `key`.
  - If the node is found and it has a `next` node, store the `next` node in `toDelete`.
  - Update the `next` pointer of the `key` node to skip the `toDelete` node.
  - Free the `toDelete` node.
  - If `key` is not found or there is no node to delete after it, print an error message.

---

### **8. Display the List**

```c
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
```

- **Purpose**: Displays the contents of the linked list.
- **Explanation**:
  - If the list is empty (`head == NULL`), print a message indicating the list is empty.
  - Otherwise, traverse the list from the `head` and print each node's `data`, followed by `->`.
  - After the traversal, print `NULL` to indicate the end of the list.

---

### **9. Search for an Element**

```c
void search(int key) {
    struct Node* temp = head;
    int position = 1;
    while (temp) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found\n", key);
}
```

- **Purpose**: Searches for an element (`key`) in the linked list.
- **Explanation**:
  - Traverse the list from `head`, checking each node's `data`.
  - If a match is found, print the position of the element and return.
  - If the end of the list is reached without finding the element, print a message indicating the element is not found.

---

### **10. Main Function**

```c
int main() {
    int choice, data, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete After a Node\n");
        printf("7. Display List\n");
        printf("8. Search Element\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter value to insert

 after: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertAfter(key, data);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter value to delete after: ");
                scanf("%d", &key);
                deleteAfter(key);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
```

- **Purpose**: This is the entry point for the program, which provides a **menu-driven interface** to interact with the singly linked list.
- **Explanation**:
  - The program repeatedly displays the menu and prompts the user to select an operation.
  - Based on the user's choice, it calls the corresponding function to perform the desired operation (insert, delete, display, search, etc.).
  - The program runs in a loop until the user selects the **Exit** option (`9`).

---

### **Time Complexity Analysis**

- **Insert at Beginning**: O(1) — Direct insertion at the head.
- **Insert at End**: O(n) — Requires traversing the entire list.
- **Insert After Node**: O(n) — Requires searching for the specified node.
- **Delete at Beginning**: O(1) — Direct deletion at the head.
- **Delete at End**: O(n) — Requires traversing the list to find the second-to-last node.
- **Delete After Node**: O(n) — Requires searching for the node to delete after.
- **Display**: O(n) — Requires traversing the entire list to print each node.
- **Search**: O(n) — Requires traversing the entire list to find the element.

---

### **Space Complexity**: O(n) — Space is used for storing the nodes of the linked list. Each node requires O(1) space, and there are `n` nodes in the list.

