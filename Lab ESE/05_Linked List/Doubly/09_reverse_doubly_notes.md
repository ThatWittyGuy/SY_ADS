Let's break down and explain the full C code step by step, block by block, to understand how it works, and then analyze the time complexity, space complexity, and the result of the program.

### 1. **Struct Definition**:

```c
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
```

- **Purpose**: Defines a `Node` structure for a doubly linked list.
  - `data`: Stores the value of the node (integer type).
  - `next`: Pointer to the next node in the list.
  - `prev`: Pointer to the previous node in the list (used for doubly linked list).

### 2. **createNode function**:

```c
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
```

- **Purpose**: Allocates memory for a new node and initializes it with the provided data.
  - Allocates memory using `malloc` for the new node.
  - Sets the `data` field of the node to the value passed as an argument.
  - Initializes both `next` and `prev` pointers to `NULL` because it is a new node with no connections.
  - Returns a pointer to the newly created node.

### 3. **insertEnd function**:

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

- **Purpose**: Inserts a new node at the end of the doubly linked list.
  - First, a new node is created using `createNode`.
  - If the list is empty (`*head == NULL`), the new node is set as the head.
  - If the list is not empty, we traverse the list to find the last node (`temp->next == NULL`).
  - The new node is then added after the last node. The `next` pointer of the last node is updated to point to the new node, and the `prev` pointer of the new node is updated to point to the last node.

### 4. **reverse function**:

```c
void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }

    *head = prev;
}
```

- **Purpose**: Reverses the doubly linked list in place.
  - The function uses three pointers: `prev`, `curr`, and `next`.
    - `prev`: Initially `NULL`, it will eventually point to the previous node as the list is reversed.
    - `curr`: Starts at the head of the list and will traverse the list one node at a time.
    - `next`: Temporarily stores the next node to keep track of the list during reversal.
  - The while loop traverses the list:
    - For each node, it changes the `next` pointer to point to the previous node and the `prev` pointer to point to the next node.
    - The list is reversed by adjusting the `prev` and `next` pointers as we go through each node.
  - After the loop finishes, `prev` points to the new head of the reversed list, so we update the head of the list to `prev`.

### 5. **display function**:

```c
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
```

- **Purpose**: Displays the data of the doubly linked list.
  - This function traverses the list from the head to the last node, printing the `data` field of each node.
  - After reaching the last node, the loop exits and prints a newline (`\n`).

### 6. **main function**:

```c
int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf("Original List: ");
    display(head);

    reverse(&head);

    printf("Reversed List: ");
    display(head);

    return 0;
}
```

- **Purpose**: This is the entry point of the program, where user interaction occurs.
  - The user is asked to enter the number of elements (`n`) they want to insert into the doubly linked list.
  - Then, a loop runs to take `n` data inputs and insert them into the list using the `insertEnd` function.
  - After inserting all elements, the `display` function is called to print the original list.
  - The list is then reversed by calling the `reverse` function.
  - Finally, the reversed list is printed using the `display` function.

### 7. **Program Flow**:

1. **Input**:
   - The user is prompted to enter the number of elements and the data for each element.
   
2. **Original List**:
   - The list is displayed in the order it was entered.
   
3. **Reversing the List**:
   - The list is reversed using the `reverse` function.
   
4. **Reversed List**:
   - The reversed list is displayed.

### 8. **Example Input/Output**:

#### Input:
```
Enter number of elements: 5
Enter elements: 10 20 30 40 50
```

#### Output:
```
Original List: 10 20 30 40 50 
Reversed List: 50 40 30 20 10
```

### 9. **Analysis**:

#### **Time Complexity**:
- **insertEnd**: O(n) for each insertion (because we traverse to the end of the list). So for `n` insertions, it takes O(n^2) in the worst case.
- **reverse**: O(n), as we traverse the entire list once.
- **display**: O(n), as we traverse the entire list to print it.
  
Thus, the overall time complexity for this program is dominated by the `insertEnd` function, which has a time complexity of O(n^2) due to the way nodes are inserted at the end.

#### **Space Complexity**:
- The space complexity is O(n), where `n` is the number of nodes in the list, because each node stores a `data`, `prev`, and `next` pointer.

#### **Summary**:
- This program constructs a doubly linked list, allows the user to add elements at the end, reverses the list, and prints both the original and reversed lists.
- It does not handle memory cleanup (e.g., freeing the allocated memory), but that could be added as an improvement.
