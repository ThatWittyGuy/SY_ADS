### Let's break down and explain the code step by step:

---

### 1. **Header Files and Macro Definitions**
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 5
```
- **`#include <stdio.h>`**: This header is used to provide functions for input/output operations like `printf` and `scanf`.
- **`#include <stdlib.h>`**: This header includes functions like `exit()`, which is used to terminate the program.
- **`#define MAX 5`**: This is a preprocessor directive that defines the maximum size of the double-ended queue (deque). Here, `MAX` is set to 5, meaning the deque can hold up to 5 elements.

---

### 2. **Defining the Double-Ended Queue (Deque) Structure**
```c
struct DoubleQueue {
    int front, rear;
    int arr[MAX];
};
```
- **`struct DoubleQueue`**: This structure represents a deque (Double-Ended Queue), which supports insertions and deletions from both ends (front and rear).
  - **`front`**: This holds the index of the front element in the queue.
  - **`rear`**: This holds the index of the rear element in the queue.
  - **`arr[MAX]`**: This is an array used to store the elements of the deque. The size of the array is determined by the `MAX` constant.

---

### 3. **Initialize the Deque**
```c
void initializeDeque(struct DoubleQueue* dq) {
    dq->front = dq->rear = -1;
}
```
- **`initializeDeque`**: This function initializes the deque by setting both the `front` and `rear` indices to `-1`, indicating that the deque is initially empty.

---

### 4. **Check if the Deque is Full**
```c
int isFull(struct DoubleQueue* dq) {
    return (dq->rear + 1) % MAX == dq->front;
}
```
- **`isFull`**: This function checks whether the deque is full:
  - In a circular deque, if the `rear` index is one step before `front`, it means the deque is full. This is checked using the condition `(dq->rear + 1) % MAX == dq->front`. The modulus ensures that the indices wrap around when they reach the end of the array.

---

### 5. **Check if the Deque is Empty**
```c
int isEmpty(struct DoubleQueue* dq) {
    return dq->front == -1;
}
```
- **`isEmpty`**: This function checks whether the deque is empty:
  - The deque is considered empty if the `front` index is `-1`.

---

### 6. **Insert an Element at the Front**
```c
void insertFront(struct DoubleQueue* dq, int value) {
    if (isFull(dq)) {
        printf("DoubleQueue is full. Cannot insert %d at front\n", value);
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = value;
    printf("%d inserted at front\n", value);
}
```
- **`insertFront`**: This function inserts an element at the front of the deque:
  - It first checks if the deque is full using `isFull(dq)`. If full, it prints an error message and exits.
  - If the deque is empty (`front == -1`), both `front` and `rear` are set to `0`.
  - Otherwise, the `front` index is decremented by one (with modulus to handle wraparound), making room for the new element at the front.
  - The value is then inserted into the `arr` at the `front` index.
  - Finally, it prints a confirmation message.

---

### 7. **Insert an Element at the Rear**
```c
void insertRear(struct DoubleQueue* dq, int value) {
    if (isFull(dq)) {
        printf("DoubleQueue is full. Cannot insert %d at rear\n", value);
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = value;
    printf("%d inserted at rear\n", value);
}
```
- **`insertRear`**: This function inserts an element at the rear of the deque:
  - It checks if the deque is full. If full, it prints an error and returns.
  - If the deque is empty (`front == -1`), both `front` and `rear` are set to `0`.
  - Otherwise, the `rear` index is incremented by one (with modulus for circular behavior).
  - The value is inserted at the `rear` index, and a confirmation message is printed.

---

### 8. **Delete an Element from the Front**
```c
void deleteFront(struct DoubleQueue* dq) {
    if (isEmpty(dq)) {
        printf("DoubleQueue is empty. Cannot delete from front\n");
        return;
    }
    printf("%d deleted from front\n", dq->arr[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }
}
```
- **`deleteFront`**: This function deletes an element from the front of the deque:
  - It first checks if the deque is empty using `isEmpty(dq)`. If empty, it prints an error and returns.
  - If there is only one element in the deque (`front == rear`), both `front` and `rear` are reset to `-1`, indicating the deque is empty.
  - Otherwise, the `front` index is incremented by one (with modulus for circular behavior).

---

### 9. **Delete an Element from the Rear**
```c
void deleteRear(struct DoubleQueue* dq) {
    if (isEmpty(dq)) {
        printf("DoubleQueue is empty. Cannot delete from rear\n");
        return;
    }
    printf("%d deleted from rear\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
}
```
- **`deleteRear`**: This function deletes an element from the rear of the deque:
  - It first checks if the deque is empty. If empty, it prints an error and returns.
  - If there is only one element in the deque (`front == rear`), both `front` and `rear` are reset to `-1`, indicating the deque is empty.
  - Otherwise, the `rear` index is decremented by one (with modulus for circular behavior).

---

### 10. **Display All Elements of the Deque**
```c
void display(struct DoubleQueue* dq) {
    if (isEmpty(dq)) {
        printf("DoubleQueue is empty\n");
        return;
    }
    int i = dq->front;
    printf("DoubleQueue elements: ");
    while (i != dq->rear) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", dq->arr[dq->rear]);
}
```
- **`display`**: This function displays all elements of the deque:
  - It first checks if the deque is empty using `isEmpty(dq)`. If empty, it prints a message and returns.
  - It starts from the `front` index and prints all elements until it reaches the `rear`. The modulus operator ensures the indices wrap around if necessary.
  - Finally, it prints the element at the `rear` index.

---

### 11. **Main Function: Menu-Driven Interface**
```c
int main() {
    struct DoubleQueue dq;
    initializeDeque(&dq);
    int choice, value;

    while (1) {
        printf("\nDeque Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display All Elements\n");
        printf("6. Check if DoubleQueue is Empty\n");
        printf("7. Check if DoubleQueue is Full\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                if (isEmpty(&dq)) {
                    printf("DoubleQueue is empty\n

");
                } else {
                    printf("DoubleQueue is not empty\n");
                }
                break;
            case 7:
                if (isFull(&dq)) {
                    printf("DoubleQueue is full\n");
                } else {
                    printf("DoubleQueue is not full\n");
                }
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
```
- The `main()` function provides a menu-driven interface for the user to interact with the double-ended queue. It allows the user to insert elements at the front and rear, delete elements from the front and rear, check if the deque is empty or full, and display its contents. The program will continue running until the user chooses to exit.

---

### **Time Complexity:**
- **Insertion/Deletion at Front or Rear**: O(1)
  - Each operation involves only updating indices (`front` or `rear`), making it constant time.
- **Display**: O(n)
  - Displaying all elements requires iterating over the deque, which takes linear time in the worst case, where `n` is the number of elements in the deque.
  
### **Space Complexity:**
- **Space Complexity**: O(MAX)
  - The space used is directly proportional to the size of the array `arr`, which is of size `MAX`. Thus, the space complexity is constant (`O(MAX)`), which is O(1) with respect to the number of elements in the deque.