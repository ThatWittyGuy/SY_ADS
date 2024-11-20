Let's break down the entire program block by block, explaining each line of the code and its function, followed by a time complexity and result analysis.

### 1. **Header File Inclusions**
```c
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
```
- `#include <stdio.h>`: This header file allows the program to perform input and output operations, including functions like `printf()` for output and `scanf()` for input.
- `#include <stdlib.h>`: This is included for the `exit()` function to terminate the program if needed.
- `#define MAX 5`: This defines the maximum size of the queue as 5. This means the queue can hold a maximum of 5 elements.

---

### 2. **Defining the Queue Structure**
```c
struct Queue
{
    int front, rear;
    int arr[MAX];
};
```
- `struct Queue`: A structure to represent a queue. It contains the following members:
  - `front`: The index of the front element of the queue. It starts at `-1` to represent an empty queue.
  - `rear`: The index of the rear element of the queue. It also starts at `-1` and will be updated as elements are added.
  - `arr[MAX]`: An array of integers that stores the actual elements of the queue. The array size is defined by `MAX` (which is 5 in this case).

---

### 3. **Initializing the Queue**
```c
void initializeQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}
```
- `initializeQueue`: This function initializes the queue. The `front` and `rear` are both set to `-1`, indicating that the queue is empty when initialized.

---

### 4. **Checking if the Queue is Full**
```c
int isFull(struct Queue *q)
{
    if (q->rear == MAX - 1)
        return 1;
    return 0;
}
```
- `isFull`: This function checks whether the queue is full. 
  - If the `rear` index is equal to `MAX - 1` (i.e., the queue has reached its capacity), it returns `1` (true), meaning the queue is full.
  - Otherwise, it returns `0` (false).

---

### 5. **Checking if the Queue is Empty**
```c
int isEmpty(struct Queue *q)
{
    if (q->front == -1 || q->front > q->rear)
        return 1;
    return 0;
}
```
- `isEmpty`: This function checks whether the queue is empty:
  - If `front` is `-1`, it means the queue is empty.
  - If `front > rear`, it means that all elements have been dequeued, so the queue is effectively empty.
  - The function returns `1` (true) if the queue is empty, and `0` (false) if the queue has elements.

---

### 6. **Inserting an Element into the Queue**
```c
void insert(struct Queue *q, int value)
{
    if (isFull(q))
    {
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
- `insert`: This function inserts an element into the queue:
  - First, it checks if the queue is full by calling `isFull(q)`. If full, it prints an error message and exits the function.
  - If the queue is empty (`front == -1`), it sets `front` to `0` to indicate the queue is no longer empty.
  - It increments `rear` to add the new element at the next available position.
  - It stores the value at `arr[rear]` and prints a confirmation message.

---

### 7. **Dequeuing (Deleting) an Element from the Queue**
```c
void dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot delete\n");
        return;
    }
    printf("%d deleted from queue\n", q->arr[q->front]);
    q->front++;
}
```
- `dequeue`: This function removes (dequeues) an element from the front of the queue:
  - First, it checks if the queue is empty by calling `isEmpty(q)`. If empty, it prints an error message and exits.
  - If the queue is not empty, it prints the value of the element being deleted from the queue (`q->arr[q->front]`).
  - It increments the `front` index to point to the next element, effectively removing the element from the queue.

---

### 8. **Peeking at the Front Element of the Queue**
```c
int peek(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot peek\n");
        return -1;
    }
    return q->arr[q->front];
}
```
- `peek`: This function retrieves the element at the front of the queue without removing it:
  - If the queue is empty, it prints an error message and returns `-1` to indicate that no element can be peeked.
  - If the queue is not empty, it returns the element at the front of the queue (`q->arr[q->front]`).

---

### 9. **Displaying the Queue Elements**
```c
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
```
- `display`: This function prints all the elements in the queue:
  - If the queue is empty, it prints a message saying so.
  - Otherwise, it loops through the `arr` array from `front` to `rear` and prints each element.

---

### 10. **Main Function: Menu-Driven Interface**
```c
int main()
{
    struct Queue q;
    initializeQueue(&q);
    int choice, value;

    while (1)
    {
        printf("\nQueue Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Queue is Empty\n");
        printf("6. Check if Queue is Full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(&q, value);
            break;

        case 2:
            dequeue(&q);
            break;

        case 3:
            printf("Front element: %d\n", peek(&q));
            break;

        case 4:
            display(&q);
            break;

        case 5:
            if (isEmpty(&q))
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;

        case 6:
            if (isFull(&q))
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("Queue is not full\n");
            }
            break;

        case 7:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
```
- **Main Function**:
  - The program enters an infinite loop (`while (1)`) which presents a menu to the user.
  - The user is prompted to enter a choice, which is processed via a `switch` statement:
    - **Choice 1**: Insert an element into the queue.
    - **Choice 2**: Remove (dequeue) an element from the queue.
    - **Choice 3**: Peek at the front element of the queue.
    - **Choice 4**: Display all elements in the queue.
    - **Choice 5**: Check if the queue is empty.
    - **Choice 6**: Check if the queue is full.
    - **Choice 7**: Exit the program.

  - If the user selects an invalid option, the program prints an error message and prompts the user to try again.

---

### Time Complexity:
- **Insert** (`insert()`): O(1) because inserting an element only involves checking if the queue is full, and then updating the `rear` and adding the element to the queue.
- **Delete** (`dequeue()`): O(1) because removing an element only involves checking if the queue is empty and incrementing the `front` index.
- **Peek** (`peek()`): O(1) because it directly returns the front element without modifying the queue.
- **Display** (`display()`): O(n), where `n` is the number of elements in the queue, because it loops through the elements from `front` to `rear`.
- **isFull** (`isFull()`), **isEmpty** (`isEmpty()`): O(1) because these functions only perform simple checks.

---

### Space Complexity:
- **

Space Complexity**: O(MAX) because the queue uses a fixed-size array `arr[MAX]` to store elements. The space used is proportional to the queue size, which is 5 in this case.

---

### Result Analysis:
- The program provides a menu-driven interface for performing operations on a queue, allowing the user to insert, delete, peek, and display elements. The program handles edge cases (queue full, queue empty) and works efficiently within the constraints set by `MAX`.

