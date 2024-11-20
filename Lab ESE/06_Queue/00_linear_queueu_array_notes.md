Let's break down the program step by step, explaining each part of the code block by block, along with time complexity and a final analysis of the program's behavior and output.

### 1. **Header File Inclusions**
```c
#include <stdio.h>
#include <stdlib.h>
```
- `#include <stdio.h>`: This header file is included for input/output operations (like `printf` and `scanf`).
- `#include <stdlib.h>`: This header file is included to provide functions like `exit()` used to terminate the program.

---

### 2. **Defining Constants and Structure**
```c
#define MAX 5
struct Queue {
    int front, rear;
    int arr[MAX];
};
```
- `#define MAX 5`: This defines the maximum size of the queue to be 5. The queue can hold up to 5 elements.
- `struct Queue`: This defines a structure `Queue` with:
  - `front`: An integer representing the front of the queue (initially set to -1).
  - `rear`: An integer representing the rear of the queue (initially set to -1).
  - `arr[MAX]`: An integer array holding the queue elements (with a fixed size of 5).

---

### 3. **Initializing the Queue**
```c
void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}
```
- `initializeQueue`: This function initializes the queue by setting the `front` and `rear` to `-1`. The `-1` indicates that the queue is empty initially.

---

### 4. **Checking if the Queue is Full**
```c
int isFull(struct Queue* q) {
    if (q->rear == MAX - 1)
        return 1;
    return 0;
}
```
- `isFull`: This function checks whether the queue is full. It returns `1` (true) if the `rear` index equals `MAX - 1` (i.e., the queue is full), otherwise it returns `0` (false).

---

### 5. **Checking if the Queue is Empty**
```c
int isEmpty(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear)
        return 1;
    return 0;
}
```
- `isEmpty`: This function checks whether the queue is empty:
  - If the `front` is `-1`, it means the queue is empty.
  - If `front > rear`, it also indicates that all elements have been deleted, so the queue is empty.
  - The function returns `1` (true) if empty, otherwise `0` (false).

---

### 6. **Inserting an Element into the Queue**
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
- `insert`: This function inserts a value into the queue:
  - First, it checks if the queue is full using `isFull(q)`. If full, it prints an error message and returns.
  - If the queue is empty (`front == -1`), the `front` is set to 0 (the first index).
  - The `rear` is incremented, and the new value is added at the `rear` position in the array.
  - It prints a message confirming the insertion.

---

### 7. **Deleting an Element from the Queue**
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
- `delete`: This function deletes the element at the front of the queue:
  - It first checks if the queue is empty using `isEmpty(q)`. If empty, it prints an error message and returns.
  - If not empty, it prints the element that was deleted and increments the `front` index to remove the element from the queue.

---

### 8. **Peeking at the Front Element**
```c
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot peek\n");
        return -1;
    }
    return q->arr[q->front];
}
```
- `peek`: This function retrieves the element at the front of the queue without removing it:
  - It checks if the queue is empty using `isEmpty(q)`. If empty, it prints an error and returns `-1`.
  - If the queue is not empty, it returns the element at the `front`.

---

### 9. **Displaying the Queue Elements**
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
- `display`: This function prints all the elements currently in the queue:
  - If the queue is empty, it prints a message indicating so.
  - Otherwise, it loops through the array from `front` to `rear`, printing each element.

---

### 10. **Main Function: Menu-Driven Interface**
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
- **Main Menu**:
  - The main function provides a menu that continuously prompts the user for an action until the user chooses to exit (option 7).
  - The user can perform one of the following operations:
    - **Insert**: Inserts a value into the queue.
    - **Delete**: Deletes the front element from the queue.
    - **Peek**: Shows the front element of the queue.
    - **Display**: Displays all elements in the queue.
    - **Check if Empty**: Checks if the queue is empty.
    - **Check if Full**: Checks if the queue is full.
    - **Exit**: Exits the program.

---

### Time Complexity:
- **Insert**: O(1) because adding an element only involves checking if the queue is full and incrementing the `rear` index.
- **Delete**: O(1) because removing an element only involves checking if the queue is empty and incrementing the `front` index.
- **Peek**: O(1) because it simply returns the element at the `front` index without modifying the queue.
- **Display**: O(n), where `n` is the number of elements in the queue, because it loops through the queue to print each element.
- **Check if Full**: O(1) because it checks if the `rear` is at `MAX - 1`.
- **Check if Empty**: O(1) because it checks if the `front` is `-1` or if `front > rear`.

---

### Space Complexity:
- **Space Complexity**: O(MAX) due to the fixed-size array used to store the queue elements (`arr[MAX]`), where `MAX` is the maximum number of elements in the queue (5 in this case).

---

### Output Example:
```
Menu:
1. Insert
2. Delete
3. Peek
4. Display
5. Check if Queue is Empty
6. Check if Queue is Full
7. Exit
Enter your choice: 1
Enter value to insert: 10
10 inserted into queue

Menu:
1. Insert
2. Delete
3. Peek
4. Display
5. Check if Queue is Empty
6. Check if Queue is Full
7. Exit
Enter your choice: 4
Queue elements: 10 
```

The user can interact with the program to insert

, delete, peek, and display elements in the queue, checking for the queue's fullness and emptiness as needed.