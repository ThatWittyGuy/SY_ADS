Let's break down and explain the provided code in multiple sections, along with an analysis of time complexity, space complexity, and results.

### 1. **Header Files and Structure Definition**
```c
#include <stdio.h>
#include <stdlib.h>
```
- **`<stdio.h>`**: Provides functions for standard input/output operations such as `printf` and `scanf`.
- **`<stdlib.h>`**: Provides functions for memory allocation and process control, specifically `malloc`, `free`, and `exit`.

```c
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
```
- **`struct Node`**: Defines a node in the doubly linked list.
  - **`int data`**: Stores the data value of the node (in this case, an integer).
  - **`struct Node* prev`**: Pointer to the previous node in the list.
  - **`struct Node* next`**: Pointer to the next node in the list.

```c
struct Node* head = NULL;
```
- **`head`**: A global pointer to the first node of the doubly linked list. It is initially set to `NULL`, indicating the list is empty.

### 2. **Inserting a Node at the Beginning**
```c
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head) head->prev = newNode;
    head = newNode;
}
```
- **`insertAtBeginning`**: Inserts a new node at the beginning of the doubly linked list.
  - **`malloc(sizeof(struct Node))`**: Allocates memory for the new node.
  - **`newNode->data = data`**: Assigns the given data to the new node.
  - **`newNode->prev = NULL`**: Since the new node will be the first, its `prev` pointer is set to `NULL`.
  - **`newNode->next = head`**: Sets the `next` pointer of the new node to the current head, which is the previous first node.
  - **`head->prev = newNode`**: If the list is not empty (i.e., `head` is not `NULL`), the `prev` pointer of the old first node is updated to point to the new node.
  - **`head = newNode`**: The `head` pointer is updated to point to the new node, making it the new first node in the list.

### 3. **Inserting a Node at the End**
```c
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}
```
- **`insertAtEnd`**: Inserts a new node at the end of the doubly linked list.
  - **`newNode->data = data`**: Sets the data for the new node.
  - **`newNode->next = NULL`**: The `next` pointer of the new node is set to `NULL` since it will be the last node.
  - **`head == NULL`**: If the list is empty (`head` is `NULL`), the new node becomes both the head and the only node in the list, with no previous node.
  - **`temp->next = newNode`**: If the list is not empty, it traverses the list to find the last node (i.e., `temp->next == NULL`), and links the new node to the last node.
  - **`newNode->prev = temp`**: Updates the `prev` pointer of the new node to point to the previous last node (`temp`).

### 4. **Inserting a Node After a Given Node**
```c
void insertAfter(int key, int data) {
    struct Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (temp) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }
}
```
- **`insertAfter`**: Inserts a new node after a node that contains the given `key` value.
  - **Traversal**: It searches through the list to find the node containing `key`. If `key` is found (`temp` is not `NULL`), a new node is created.
  - **`newNode->data = data`**: Assigns the data value to the new node.
  - **Linking**:
    - **`newNode->next = temp->next`**: The `next` pointer of the new node is set to the node after `temp` (if any).
    - **`newNode->prev = temp`**: The `prev` pointer of the new node is set to point to `temp`.
    - **`temp->next->prev = newNode`**: If `temp` has a next node, its `prev` pointer is updated to point to the new node.
    - **`temp->next = newNode`**: Finally, the `next` pointer of `temp` is updated to point to the new node.

### 5. **Deleting a Node at the Beginning**
```c
void deleteAtBeginning() {
    if (head) {
        struct Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        free(temp);
    }
}
```
- **`deleteAtBeginning`**: Deletes the first node in the list.
  - If the list is not empty (`head != NULL`), it stores the `head` in `temp` and updates `head` to point to the second node (`head->next`).
  - If the new `head` exists, it updates its `prev` pointer to `NULL`.
  - It then frees the memory allocated to the old head.

### 6. **Deleting a Node at the End**
```c
void deleteAtEnd() {
    if (head) {
        if (!head->next) {  // Only one element
            free(head);
            head = NULL;
        } else {
            struct Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->prev->next = NULL;
            free(temp);
        }
    }
}
```
- **`deleteAtEnd`**: Deletes the last node in the list.
  - If the list only contains one node (`!head->next`), it frees the `head` and sets it to `NULL`.
  - Otherwise, it traverses to the last node, updates the second-to-last node's `next` pointer to `NULL`, and frees the last node.

### 7. **Deleting a Node After a Given Node**
```c
void deleteAfter(int key) {
    struct Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (temp && temp->next) {
        struct Node* toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete->next) toDelete->next->prev = temp;
        free(toDelete);
    }
}
```
- **`deleteAfter`**: Deletes the node immediately following the node containing the `key`.
  - It first traverses to find the node containing `key`.
  - If the node is found and it has a next node (`temp->next`), it updates `temp->next` to point to `toDelete->next` and updates `toDelete->next->prev` to point to `temp`.
  - Finally, it frees the memory allocated for the node to be deleted.

### 8. **Displaying the List**
```c
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
```
- **`display`**: Displays the entire doubly linked list.
  - If the list is empty (`head == NULL`), it prints "List is empty".
  - Otherwise, it traverses through each node, printing the `data` of each node, followed by the string `<->` to show the bidirectional links.
  - The traversal stops when `temp` becomes `NULL` (end of the list), and it prints `"NULL"` to indicate the end.

### 9. **Searching for a Node**
```c
void search(int key) {
    struct Node* temp = head;
    int position = 1;
    while (temp) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        temp

 = temp->next;
        position++;
    }
    printf("Element %d not found\n", key);
}
```
- **`search`**: Searches for a node containing the specified `key`.
  - It starts from the `head` and traverses the list, incrementing the `position` variable.
  - If a node with `data == key` is found, it prints the position.
  - If the traversal ends without finding the key, it prints that the element was not found.

### 10. **Main Function (Menu-driven)**
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
        printf("8. Search for an Element\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter the key after which to insert: ");
                scanf("%d", &key);
                printf("Enter data to insert after %d: ", key);
                scanf("%d", &data);
                insertAfter(key, data);
                break;
            case 4:
                deleteAtBeginning();
                printf("Deleted node from the beginning.\n");
                break;
            case 5:
                deleteAtEnd();
                printf("Deleted node from the end.\n");
                break;
            case 6:
                printf("Enter the key after which to delete: ");
                scanf("%d", &key);
                deleteAfter(key);
                printf("Deleted node after %d.\n", key);
                break;
            case 7:
                printf("Doubly Linked List: ");
                display();
                break;
            case 8:
                printf("Enter data to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
```
- **`main`**: A menu-driven interface that allows the user to choose various operations (insert, delete, display, search).
  - Based on the user's input (`choice`), it calls the corresponding function to perform the desired operation.

### **Time Complexity**
- **Insertions (Beginning, End, After a Key)**:
  - **Insert at Beginning**: O(1).
  - **Insert at End**: O(n) (since it requires traversing the entire list to find the last node).
  - **Insert After a Key**: O(n) (since it requires searching for the key in the list).
  
- **Deletions (Beginning, End, After a Key)**:
  - **Delete at Beginning**: O(1).
  - **Delete at End**: O(n) (since it requires traversing the list to find the last node).
  - **Delete After a Key**: O(n) (since it requires searching for the key in the list).

- **Display**: O(n) (since it traverses the entire list to print the elements).
- **Search**: O(n) (since it searches through the entire list).

### **Space Complexity**
- **Space Complexity**: O(n) for the list as it stores `n` nodes, each requiring memory for storing an integer and two pointers.

### **Result Example**
Assuming the following operations:
1. Insert elements at the beginning, end, and after certain nodes.
2. Display the list.
3. Delete nodes from the beginning, end, and after certain nodes.
4. Search for specific elements.

The program will provide outputs based on these actions. For example:
- After inserting 10, 20, and 30, the list might look like: `10 <-> 20 <-> 30 <-> NULL`.
- If you search for `20`, it will print: `Element 20 found at position 2`.
