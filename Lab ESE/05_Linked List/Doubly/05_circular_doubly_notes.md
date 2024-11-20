Let's go through the code step-by-step, explaining each section and analyzing the time complexity and expected behavior of each part.

### **1. Header Files and Struct Definition**

```c
#include <stdio.h>
#include <stdlib.h>
```

- **`stdio.h`**: Provides the necessary functions for input and output, such as `printf` and `scanf`.
- **`stdlib.h`**: Provides functions for memory allocation (`malloc`), process control, and exit (`exit`).

---

```c
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
```

- Defines a **`Node`** structure representing an element in a **circular doubly linked list**:
  - **`data`**: Stores the value of the node.
  - **`next`**: A pointer to the next node in the list.
  - **`prev`**: A pointer to the previous node in the list.

---

```c
struct Node* head = NULL;
```

- **`head`** is a pointer to the first node of the circular doubly linked list. Initially, it is set to `NULL`, indicating the list is empty.

---

### **2. Insertion Operations**

#### **Insert at the Beginning**

```c
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
```

- A new node (`newNode`) is dynamically allocated using `malloc` to store the data.
- **`newNode->data = data;`** sets the node's data field to the value passed.

```c
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }
```

- If the list is empty (i.e., `head == NULL`), both `next` and `prev` pointers of the new node point to itself, making it a circular linked list of one node. The `head` pointer is then updated to point to this new node.

```c
    else {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
```

- If the list is not empty:
  1. **Traverse**: Find the last node (`temp`) by iterating until `temp->next` points to `head`.
  2. **Link the new node**: The `newNode` is inserted between the `temp` (last node) and `head`.
  3. The `head` is updated to point to the new node.

**Time Complexity**: **O(n)**, where `n` is the number of nodes in the list. This is because we need to traverse the entire list to find the last node.

---

#### **Insert at the End**

```c
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
```

- A new node (`newNode`) is created, and its data is initialized to the given value.

```c
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }
```

- If the list is empty, the `newNode` becomes the only node in the list, and both `next` and `prev` point to itself.

```c
    else {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }
}
```

- If the list is not empty:
  1. Traverse the list to find the last node (`temp`).
  2. The `newNode` is inserted after the `temp` node, with the appropriate `next` and `prev` pointers updated.
  3. `head->prev` is set to point to the new node, completing the circular linkage.

**Time Complexity**: **O(n)**, where `n` is the number of nodes. We need to traverse the list to find the last node.

---

#### **Insert After a Specific Node**

```c
void insertAfter(int key, int data) {
    struct Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
```

- We start by looking for a node containing the specified `key`. If the node is found, we proceed with the insertion; otherwise, the function does nothing.

```c
    if (temp) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = temp->next;
        newNode->prev = temp;
```

- If the node is found, a new node (`newNode`) is created. The `next` pointer of `newNode` is set to point to the node after `temp`. The `prev` pointer of `newNode` is set to point to `temp`.

```c
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }
}
```

- If `temp->next` is not `head`, we update the `prev` pointer of `temp->next` to point to `newNode`.
- Finally, we update `temp->next` to point to the new node.

**Time Complexity**: **O(n)**, where `n` is the number of nodes in the list. We need to traverse the list to find the node with the matching `key`.

---

### **3. Deletion Operations**

#### **Delete at the Beginning**

```c
void deleteAtBeginning() {
    if (head) {
        struct Node* temp = head;
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            struct Node* last = head->prev;
            head = head->next;
            last->next = head;
            head->prev = last;
            free(temp);
        }
    }
}
```

- If the list is not empty:
  1. If there is only one node, we free it and set `head` to `NULL`.
  2. If there are multiple nodes:
     - The last node (`last`) is identified by `head->prev`.
     - The `head` is updated to the next node, and the `last->next` pointer is updated to point to the new `head`.
     - The `head->prev` pointer is updated to point to `last`.
     - The old `head` is freed.

**Time Complexity**: **O(1)**, as we only need to update a few pointers and free the old head.

---

#### **Delete at the End**

```c
void deleteAtEnd() {
    if (head) {
        struct Node* temp = head;
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            while (temp->next != head) temp = temp->next;
            temp->prev->next = head;
            head->prev = temp->prev;
            free(temp);
        }
    }
}
```

- If the list is not empty:
  1. If there is only one node, we free it and set `head` to `NULL`.
  2. If there are multiple nodes, we traverse the list to find the last node.
  3. The previous node (`temp->prev`) is updated to point to `head`, and the `head->prev` pointer is updated to point to `temp->prev`.
  4. The last node is freed.

**Time Complexity**: **O(n)**, where `n` is the number of nodes in the list, as we need to traverse the list to find the last node.

---

#### **Delete After a Specific Node**

```c
void deleteAfter(int key) {
    struct Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
```

- We search for the node with the specified `key`. If found, we proceed with the deletion.

```c
    if (temp && temp->next != head) {
        struct Node* toDelete = temp->next;
        temp->next = toDelete->next;
        toDelete->next->prev = temp;
        free(toDelete);
    }
}
```

- If the `key` is found and the next node is not `head`, we:
  1. Identify the node to delete (`toDelete`).
  2. Update the `next` pointer of `temp` to point to the node after `toDelete`.
  3. Update the `prev` pointer of `toDelete->next` to point to `temp`.
  4. Free the `toDelete` node.

**Time Complexity**: **O(n)**, where `n` is the number of nodes, since we have to traverse the list to find the node with the `key`.

---

### **4. Display and Search Operations**

#### **Display the List**

```c
void display() {
    if (head) {
        struct Node* temp = head;
        do {
            printf("%d <-> ", temp->data);
            temp =

 temp->next;
        } while (temp != head);
        printf("(head)\n");
    } else {
        printf("List is empty\n");
    }
}
```

- Displays the list in a circular manner starting from `head`. It prints each node’s data until it loops back to the `head`.

**Time Complexity**: **O(n)**, where `n` is the number of nodes, as we have to traverse all nodes once.

---

#### **Search for an Element**

```c
void search(int key) {
    struct Node* temp = head;
    int position = 1;  // Start counting positions from 1
    if (temp) {
        do {
            if (temp->data == key) {
                printf("Element %d found at position %d\n", key, position);
                return;
            }
            temp = temp->next;
            position++;
        } while (temp != head);
    }
    printf("Element %d not found\n", key);
}
```

- Searches for the element with the given `key` and prints its position. If the element is not found, it prints a message saying so.

**Time Complexity**: **O(n)**, where `n` is the number of nodes, as we have to check each node in the list.

---

### **5. Main Function**

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
                printf("Circular Doubly Linked List: ");
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

- The **menu-driven program** prompts the user to choose an operation on the circular doubly linked list. Depending on the user's choice, it performs the corresponding function like inserting, deleting, displaying, or searching. The program continues running until the user chooses to exit.

**Time Complexity of Main Menu Operations**:
- **Insert at Beginning**: O(1)
- **Insert at End**: O(n)
- **Insert After**: O(n)
- **Delete at Beginning**: O(1)
- **Delete at End**: O(n)
- **Delete After**: O(n)
- **Display**: O(n)
- **Search**: O(n)