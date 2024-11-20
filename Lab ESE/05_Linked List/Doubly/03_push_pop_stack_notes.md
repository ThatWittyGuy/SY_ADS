### Explanation of the Code

The code implements a stack data structure using a **doubly linked list**. A stack follows the Last In First Out (LIFO) principle, where the last element added is the first one to be removed.

Here is a breakdown of each block of the code:

---

### Struct Definition (`struct Node`)

```c
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
```
- This struct defines a **node** in the stack. 
  - `data` stores the integer value of the node.
  - `next` is a pointer to the next node in the stack (downward direction).
  - `prev` is a pointer to the previous node (upward direction).

### Global Variable (`top`)

```c
struct Node* top = NULL;
```
- `top` points to the top element of the stack. Initially, it is set to `NULL`, which means the stack is empty at the start.

---

### Push Function (`push`)

```c
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
```
- This function adds a new node to the stack:
  - `newNode` is a pointer to a new node created using `malloc`. 
  - The `data` passed as a parameter is assigned to `newNode->data`.
  - The `next` pointer of the new node is set to `NULL` since it is going to be the new top of the stack.
  - The `prev` pointer of the new node is set to the current `top` of the stack, linking the new node to the previous top.
  - If the stack is not empty (i.e., `top != NULL`), we set the `next` pointer of the current top node to the new node.
  - Finally, the `top` pointer is updated to point to the newly added node, making it the new top of the stack.

---

### Pop Function (`pop`)

```c
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
```
- This function removes the node from the top of the stack:
  - If the stack is empty (`top == NULL`), the function prints "Stack is empty" and returns.
  - If the stack is not empty, we store the current `top` node in `temp`.
  - The `top` pointer is updated to point to the previous node (`top->prev`), effectively removing the current top node.
  - If the new `top` is not `NULL`, we update its `next` pointer to `NULL`, ensuring that it is the last element in the stack.
  - We print the data of the popped element.
  - Finally, we free the memory allocated for the removed node (`temp`).

---

### Display Function (`display`)

```c
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
```
- This function prints all the elements in the stack from top to bottom:
  - If the stack is empty (`top == NULL`), the function prints "Stack is empty" and returns.
  - Otherwise, it iterates through the stack starting from the `top`, printing each node's `data`.
  - Since the stack is implemented as a doubly linked list, we move from the top node downwards by following the `prev` pointers.
  - The loop continues until `temp` becomes `NULL`, indicating the end of the stack.

---

### Main Function (`main`)

```c
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
```

- The `main` function handles user input and controls the program flow.
  - It presents a menu with four options: Push, Pop, Display, and Exit.
  - It uses a `while (1)` loop to continuously prompt the user for input.
  - Based on the user’s choice, it performs the corresponding stack operation:
    - **Push**: The user is prompted to enter a value, which is then pushed onto the stack.
    - **Pop**: The top element of the stack is removed and printed.
    - **Display**: The current elements of the stack are displayed.
    - **Exit**: The program terminates.
  - If the user enters an invalid choice, it prints "Invalid choice".

---

### Time Complexity

- **Push Operation**:
  - **Time Complexity**: **O(1)** — The `push` operation involves adding a new node at the top, which requires constant time since it only updates the `top` pointer and adjusts the `next` and `prev` pointers.
  
- **Pop Operation**:
  - **Time Complexity**: **O(1)** — The `pop` operation involves removing the top node, which is a constant-time operation because we just update the `top` pointer and free the memory.
  
- **Display Operation**:
  - **Time Complexity**: **O(n)** — The `display` function iterates over all elements in the stack. In the worst case, it will traverse the entire stack, making it linear with respect to the number of elements (`n`) in the stack.

---

### Space Complexity

- **Space Complexity**: **O(n)** — The space complexity is proportional to the number of elements in the stack because each element is stored in a `Node`, and each node requires space for storing data and pointers (`next` and `prev`).

---

### Example Input and Output

#### Example Run:
```
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter data to push: 10

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter data to push: 20

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
20 10 

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Popped element: 20

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
10 

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Popped element: 10

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Stack is empty
```

---

### Conclusion

- **Functionality**: The stack supports basic operations like pushing, popping, and displaying elements, along with printing the popped element.
- **Efficiency**: The time complexity for both the push and pop operations is constant, and the space complexity depends on the number of elements stored.
