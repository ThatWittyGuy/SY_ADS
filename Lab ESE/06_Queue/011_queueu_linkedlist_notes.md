### Code Explanation: Linear Queue Using Array

This code implements a **queue** using an array with a fixed size of `MAX = 5`. The queue allows insertion, deletion, peeking, and checking whether the queue is empty or full. Let's break down the code into blocks and explain each line in detail.

---

### 1. **Header Files and Macro Definition**

```c
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
```

- `#include <stdio.h>`: Includes the standard input-output library, which is required to use `printf` and `scanf` functions for displaying messages and reading user input.
- `#include <stdlib.h>`: Includes the standard library for functions like `exit()`, which is used to terminate the program.
- `#define MAX 5`: Defines a macro `MAX` with a value of `5`, representing the maximum size of the queue. The array used in the queue will have a size of 5.

---

### 2. **Queue Structure Definition**

```c
struct Queue {
    int front, rear;
    int arr[MAX];
};
```

- `struct Queue`: Defines a structure `Queue` which contains:
  - `int front`: This pointer (or index) keeps track of the front of the queue. Initially, it is set to `-1` to indicate an empty queue.
  - `int rear`: This pointer (or index) keeps track of the last element in the queue. It is also initialized to `-1` to indicate an empty queue.
  - `int arr[MAX]`: This array stores the elements of the queue, with a fixed size defined by `MAX`.

---

### 3. **initializeQueue Function**

```c
void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}
```

- `initializeQueue(struct Queue* q)`: This function initializes the queue by setting both `front` and `rear` to `-1`, which indicates the queue is empty.
- `q->front = -1; q->rear = -1;`: Set both `front` and `rear` of the queue to `-1`, marking an empty queue.

---

### 4. **isFull Function**

```c
int isFull(struct Queue* q) {
    if (q->rear == MAX - 1)
        return 1;
    return 0;
}
```

- `isFull(struct Queue* q)`: This function checks if the queue is full.
- `if (q->rear == MAX - 1)`: Checks if the `rear` pointer has reached the maximum index (`MAX - 1`). If true, the queue is full.
- `return 1;`: Returns `1` to indicate that the queue is full.
- `return 0;`: Returns `0` to indicate that the queue is not full.

---

### 5. **isEmpty Function**

```c
int isEmpty(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear)
        return 1;
    return 0;
}
```

- `isEmpty(struct Queue* q)`: This function checks if the queue is empty.
- `if (q->front == -1 || q->front > q->rear)`: The queue is empty if:
  - `front == -1`: No elements have been inserted into the queue.
  - `front > rear`: This condition occurs after elements have been deleted and the front pointer has surpassed the rear pointer (a situation after multiple deletions).
- `return 1;`: Returns `1` to indicate that the queue is empty.
- `return 0;`: Returns `0` to indicate that the queue is not empty.

---

### 6. **insert Function**

```c
void insert(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert %d\n", value);
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->arr[q->rear] = value;
    printf("%d inserted into queue\n", value);
}
```

- `insert(struct Queue* q, int value)`: This function inserts a value into the queue.
- `if (isFull(q))`: Checks if the queue is full using the `isFull()` function. If the queue is full, it prints a message and exits the function.
- `if (q->front == -1)`: If the queue is empty (`front == -1`), set `front = 0` to indicate that the first element is inserted.
- `q->rear++`: Increment the `rear` pointer to point to the next available position in the array.
- `q->arr[q->rear] = value;`: Insert the new value at the position pointed by `rear`.
- `printf("%d inserted into queue\n", value);`: Print a confirmation message indicating that the value has been inserted.

---

### 7. **delete Function**

```c
void delete(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot delete\n");
        return;
    }
    printf("%d deleted from queue\n", q->arr[q->front]);
    q->front++;
}
```

- `delete(struct Queue* q)`: This function deletes the front element from the queue.
- `if (isEmpty(q))`: Checks if the queue is empty using the `isEmpty()` function. If the queue is empty, it prints a message and exits the function.
- `printf("%d deleted from queue\n", q->arr[q->front]);`: Prints the value of the element that is being deleted from the front of the queue.
- `q->front++`: Moves the `front` pointer to the next element in the queue. This effectively deletes the front element by making it unreachable.

---

### 8. **peek Function**

```c
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot peek\n");
        return -1;
    }
    return q->arr[q->front];
}
```

- `peek(struct Queue* q)`: This function returns the front element of the queue without deleting it.
- `if (isEmpty(q))`: Checks if the queue is empty. If empty, it prints a message and returns `-1` to indicate there is nothing to peek.
- `return q->arr[q->front];`: If the queue is not empty, it returns the value of the element at the `front` pointer.

---

### 9. **display Function**

```c
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
```

- `display(struct Queue* q)`: This function displays all the elements in the queue.
- `if (isEmpty(q))`: Checks if the queue is empty using `isEmpty()`. If empty, it prints a message and exits the function.
- `printf("Queue elements: ");`: Prints the introductory message for displaying queue elements.
- `for (int i = q->front; i <= q->rear; i++)`: Loops through all elements in the queue from `front` to `rear`.
- `printf("%d ", q->arr[i]);`: Prints each element of the queue.
- `printf("\n");`: Adds a newline after printing all elements.

---

### 10. **main Function**

```c
int main() {
    struct Queue q;
    int choice, value;
    initializeQueue(&q);

    while(1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Queue is Empty\n");
        printf("6. Check if Queue is Full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&q, value);
                break;
            case 2:
                delete(&q);
                break;
            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Peek: %d\n", value);
                }
                break;
            case 4:
                display(&q);
                break;
            case 5:
                if (isEmpty(&q)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 6:
                if (isFull(&q)) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
```

- **`struct Queue q;`**: Declares a queue variable `q`.
- **`initializeQueue(&q);`**: Initializes the queue before starting the menu-driven operations.
- The `while(1)` loop keeps the program running indefinitely until the user selects the "Exit" option.
- The `switch(choice)`

 statement presents the menu options and executes the corresponding function based on the user's input (Insert, Delete, Peek, Display, Check Empty/Full, Exit).

---

### **Time Complexity Analysis**

- **Insert Operation**: O(1) – The insert operation only involves incrementing the `rear` pointer and adding the element.
- **Delete Operation**: O(1) – The delete operation involves simply incrementing the `front` pointer.
- **Peek Operation**: O(1) – The peek operation only accesses the element at the `front` pointer.
- **Display Operation**: O(n) – In the worst case, the display function iterates over all elements in the queue from `front` to `rear`.
- **isEmpty and isFull Operations**: O(1) – These functions just check the values of `front` and `rear` or compare `rear` with `MAX - 1`.

### **Space Complexity**
- **O(MAX)** – The space complexity is constant (O(MAX)) because the array `arr[MAX]` used to store the queue elements has a fixed size of `MAX` (5 in this case).

---

### **Summary**

This code implements a queue with fixed size using an array. It supports basic operations such as insertion, deletion, peeking, and checking the queue's state (empty or full). The time complexity of each operation is generally O(1), except for `display`, which is O(n). The space complexity is O(MAX) due to the fixed-size array.