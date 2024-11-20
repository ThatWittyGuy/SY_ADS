Let's break down the code and explain it line by line in different blocks, including the analysis of the result and time complexity.

### 1. **Header Files**
```c
#include <stdio.h>
#include <stdlib.h>
```
- **`<stdio.h>`**: This header is included for standard input/output functions (`printf`, `scanf`, etc.).
- **`<stdlib.h>`**: This header is included for memory management functions (`malloc`, `free`), which are used for dynamic memory allocation.

### 2. **Defining the Node Structure**
```c
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
```
- **`struct Node`**: Defines a doubly linked list node.
  - **`int data`**: Stores the data (integer) for the node.
  - **`struct Node* next`**: Pointer to the next node in the list.
  - **`struct Node* prev`**: Pointer to the previous node in the list.

### 3. **Creating a New Node**
```c
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
```
- **`createNode`**: This function creates a new node with the given `data` and initializes its `next` and `prev` pointers to `NULL`.
  - **`malloc(sizeof(struct Node))`**: Allocates memory for a new node. This returns a pointer to the newly allocated memory, which is cast to `struct Node*`.
  - The `data` is assigned to the node's `data` field.
  - `next` and `prev` pointers are initialized to `NULL`, indicating that it doesn't point to any other nodes initially.
  - Finally, it returns the pointer to the new node.

### 4. **Inserting an Element at the End**
```c
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
```
- **`insertEnd`**: Inserts a node with the given `data` at the end of the doubly linked list.
  - **`createNode(data)`**: Creates a new node using the `createNode` function.
  - **`*head == NULL`**: If the list is empty (i.e., `head` is `NULL`), the new node is set as the head of the list.
  - If the list is not empty, the function traverses the list to find the last node by checking `temp->next != NULL`.
  - Once the last node is found, the new node is appended by setting the last node's `next` pointer to the new node and setting the new node's `prev` pointer to the last node.

### 5. **Merging Two Sorted Lists**
```c
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    if (list1->data < list2->data) {
        list1->next = mergeSortedLists(list1->next, list2);
        if (list1->next != NULL) {
            list1->next->prev = list1;
        }
        list1->prev = NULL;
        return list1;
    } else {
        list2->next = mergeSortedLists(list1, list2->next);
        if (list2->next != NULL) {
            list2->next->prev = list2;
        }
        list2->prev = NULL;
        return list2;
    }
}
```
- **`mergeSortedLists`**: Merges two sorted doubly linked lists (`list1` and `list2`) into a single sorted list using a recursive approach.
  - **Base cases**: 
    - If `list1` is `NULL`, return `list2` (because if one list is empty, the other one is the merged result).
    - If `list2` is `NULL`, return `list1`.
  - **Recursive merging**:
    - If `list1->data` is smaller than `list2->data`, the first element of `list1` is placed in the merged list, and the function recursively calls itself to merge the rest of `list1` with `list2`.
    - If `list2->data` is smaller, the first element of `list2` is placed in the merged list, and the function recursively merges `list1` with the rest of `list2`.
  - The merging process ensures that the smaller element is added to the merged list first, maintaining the sorted order.
  - **Updating `prev` and `next`**: After each recursive call, we ensure the `prev` pointer of the next node is updated correctly to maintain the doubly linked list structure.

### 6. **Displaying the List**
```c
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
```
- **`display`**: Displays all elements of the doubly linked list starting from `head`.
  - If the list is empty (i.e., `head` is `NULL`), it prints "List is empty".
  - Otherwise, it traverses the list using a `while` loop and prints each node's `data`.
  - The traversal continues until `temp` becomes `NULL` (end of the list).
  
### 7. **Main Function**
```c
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n, data;

    // Input for first sorted list
    printf("Enter number of elements for first sorted list: ");
    scanf("%d", &n);
    printf("Enter elements for first sorted list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&list1, data);
    }

    // Input for second sorted list
    printf("Enter number of elements for second sorted list: ");
    scanf("%d", &n);
    printf("Enter elements for second sorted list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&list2, data);
    }

    // Merging the two sorted lists
    struct Node* mergedList = mergeSortedLists(list1, list2);

    // Display the merged sorted list
    printf("Merged sorted list: ");
    display(mergedList);

    return 0;
}
```
- **Main Logic**:
  - Initializes two empty lists `list1` and `list2` (both are `NULL` initially).
  - **Inputs**:
    - The user is prompted to enter the number of elements for both lists and then the elements themselves. These elements are inserted into `list1` and `list2` using `insertEnd`.
  - **Merge**: Once both lists are populated, the `mergeSortedLists` function is called to merge the two sorted lists into a new list (`mergedList`).
  - **Display**: The merged sorted list is then displayed using the `display` function.

### Time and Space Complexity Analysis:

- **Time Complexity**:
  - **`insertEnd`**: For each element, we traverse the list to find the end. This results in a time complexity of **O(n)** for inserting one element at the end. If there are `m` elements, inserting all elements will take **O(m) time**.
  - **`mergeSortedLists`**: The merge function compares each node of `list1` and `list2` once, so it takes **O(n + m)** time, where `n` is the number of nodes in `list1` and `m` is the number of nodes in `list2`.
  - **Overall Time Complexity**: The overall time complexity is **O(n + m)**, where `n` and `m` are the lengths of the two input lists.

- **Space Complexity**:
  - **`mergeSortedLists`**: Since we are merging the lists recursively, the space complexity is affected by the recursion depth. The maximum recursion depth would be **O(n + m)**.
  - **Overall Space Complexity**: The overall space complexity is **O(n + m)**, accounting for both the memory used to store the merged list and the recursion stack.

### Example Input and Output:

#### Input:
```
Enter number of elements for first sorted list: 3
Enter elements for first sorted list: 1 3 5
Enter number of elements for second sorted list: 3
Enter elements for second sorted list: 2 4 6
```

#### Output:
```
Merged sorted list: 1 2 3 4 5 6
```

This is the expected output where the two sorted lists have been successfully merged into

 a single sorted list.