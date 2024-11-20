### Code Explanation:

The code provided is a C program that implements a singly linked list and reverses the list before displaying it. Let's break down each part of the code and explain its functionality in detail.

---

### 1. **Struct Declaration:**

```c
struct Node {
    int data;
    struct Node* next;
};
```

- A structure `Node` is defined to represent each node in the linked list.
- The `Node` structure contains two fields:
  - `data`: Holds the data (an integer) of the node.
  - `next`: A pointer to the next node in the list. If this is `NULL`, it indicates the end of the list.

---

### 2. **createNode Function:**

```c
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
```

- The `createNode` function dynamically allocates memory for a new node using `malloc`.
- It initializes the `data` field with the given value (`data`) and sets the `next` pointer to `NULL` (indicating it is the last node in the list initially).
- The function returns the pointer to the newly created node.

---

### 3. **insertEnd Function:**

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
    }
}
```

- The `insertEnd` function inserts a new node with the given `data` at the end of the linked list.
- If the list is empty (`*head == NULL`), the new node becomes the first node.
- If the list is not empty, the function traverses to the last node (`while (temp->next != NULL)`) and then adds the new node by setting the `next` pointer of the last node to the new node.

---

### 4. **reverse Function:**

```c
void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}
```

- The `reverse` function reverses the linked list.
- The algorithm uses three pointers: 
  - `prev`: Initially `NULL`, used to track the previous node.
  - `curr`: Points to the current node (starting with `head`).
  - `next`: Temporarily stores the next node in the list.
- The loop continues until `curr` reaches `NULL`. For each node:
  - `next = curr->next`: Stores the next node.
  - `curr->next = prev`: Reverses the direction of the `next` pointer.
  - `prev = curr`: Moves `prev` to the current node.
  - `curr = next`: Moves `curr` to the next node.
- After the loop finishes, the `head` is updated to point to the last node (`prev`), which is now the first node of the reversed list.

---

### 5. **display Function:**

```c
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
```

- The `display` function prints all the elements of the linked list.
- It iterates over each node in the list, printing the `data` of each node.
- The loop continues until `head` becomes `NULL`, which indicates the end of the list.
- After printing the elements, it prints a newline.

---

### 6. **main Function:**

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

- The `main` function controls the flow of the program.
- It initializes `head` to `NULL` (empty list).
- The user is asked for the number of elements (`n`) to insert into the list. Then, the program enters a loop where the user is prompted to enter the value (`data`) for each node. The `insertEnd` function is called to insert each node at the end of the list.
- After the list is populated, the original list is displayed by calling the `display` function.
- The `reverse` function is called to reverse the linked list.
- The reversed list is displayed using the `display` function.
- The program ends with `return 0;`.

---

### Time Complexity Analysis:

1. **createNode:**  
   - `O(1)`: Memory allocation and setting fields of a new node take constant time.

2. **insertEnd:**  
   - **Best case (when the list is empty):**  
     - `O(1)` as the node is directly inserted.
   - **Worst case (when inserting at the end of a long list):**  
     - `O(n)`, where `n` is the number of nodes in the list, because we need to traverse the list to find the last node.

3. **reverse:**  
   - **Time complexity:**  
     - `O(n)`, where `n` is the number of nodes in the list. The function traverses each node once to reverse the list.

4. **display:**  
   - **Time complexity:**  
     - `O(n)`, where `n` is the number of nodes in the list, since the function iterates through each node to print the data.

---

### Final Output:

Given an input where:
```
Enter number of elements: 5
Enter elements: 1 2 3 4 5
```

The output will be:
```
Original List: 1 2 3 4 5
Reversed List: 5 4 3 2 1
```

---

### Overall Time Complexity:

- **Time complexity for inserting `n` elements:**  
  Each insertion takes `O(n)` in the worst case, leading to a total complexity of `O(n^2)` for inserting all `n` elements.

- **Time complexity for reversing the list:**  
  `O(n)`.

- **Time complexity for displaying the list:**  
  `O(n)`.

Thus, the overall time complexity of the program is dominated by the insertion process, which is `O(n^2)`.