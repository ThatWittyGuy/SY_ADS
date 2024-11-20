The provided code is a C program that implements a **stack** using two **queues**. A stack follows the **Last In, First Out (LIFO)** principle, whereas a queue follows the **First In, First Out (FIFO)** principle. By using two queues, we can simulate stack operations.

### **Breakdown of Code in Different Blocks**

---

### **Header Files and Constants:**

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 5
```

- **`stdio.h`**: This header file is included to use standard input/output functions like `printf` and `scanf`.
- **`stdlib.h`**: Though not used directly in this program, this header is often used for memory allocation functions and other utilities.
- **`MAX`**: A constant that defines the maximum size of the queue and stack. Here, it is set to 5.

---

### **Queue Data Structure and Functions:**

#### **Queue Structure**:

```c
struct Queue {
    int arr[MAX];
    int front, rear;
};
```

- **`arr[MAX]`**: This is an array of integers that stores the elements of the queue. The size is fixed to `MAX`, which is 5 in this case.
- **`front`**: Points to the front element in the queue.
- **`rear`**: Points to the last element in the queue.

#### **Queue Operations**:

1. **Enqueue (Add Element to Queue)**:
   ```c
   void enqueue(struct Queue *q, int value) {
       if (q->rear == MAX - 1) {
           printf("Queue Overflow\n");
       } else {
           if (q->front == -1) q->front = 0;
           q->arr[++(q->rear)] = value;
       }
   }
   ```
   - **Purpose**: Adds an element `value` to the rear of the queue.
   - If the queue is full (`rear == MAX - 1`), it prints "Queue Overflow".
   - If the queue is empty (`front == -1`), it initializes `front` to `0`.
   - The `value` is inserted at the `rear`, and `rear` is incremented.

2. **Dequeue (Remove Element from Queue)**:
   ```c
   int dequeue(struct Queue *q) {
       if (q->front == -1) {
           printf("Queue Underflow\n");
           return -1;
       } else {
           int value = q->arr[q->front];
           if (q->front == q->rear) {
               q->front = q->rear = -1;
           } else {
               q->front++;
           }
           return value;
       }
   }
   ```
   - **Purpose**: Removes the element at the front of the queue and returns it.
   - If the queue is empty (`front == -1`), it prints "Queue Underflow".
   - The element at `front` is returned, and if the queue becomes empty, both `front` and `rear` are reset to `-1`.

3. **Check if Queue is Empty**:
   ```c
   int isEmpty(struct Queue *q) {
       return q->front == -1;
   }
   ```
   - **Purpose**: Returns `1` if the queue is empty, otherwise returns `0`.

4. **Check if Queue is Full**:
   ```c
   int isFull(struct Queue *q) {
       return q->rear == MAX - 1;
   }
   ```
   - **Purpose**: Returns `1` if the queue is full, otherwise returns `0`.

5. **Display Queue Elements**:
   ```c
   void display(struct Queue *q) {
       if (isEmpty(q)) {
           printf("Queue is empty\n");
       } else {
           printf("Queue elements: ");
           for (int i = q->front; i <= q->rear; i++) {
               printf("%d ", q->arr[i]);
           }
           printf("\n");
       }
   }
   ```
   - **Purpose**: Displays the elements of the queue from `front` to `rear`. If the queue is empty, it prints "Queue is empty".

---

### **Stack Data Structure Using Two Queues:**

#### **Stack Structure**:

```c
struct Stack {
    struct Queue q1, q2;
    int top;
};
```

- **`q1` and `q2`**: Two queues that are used to simulate stack operations.
- **`top`**: An integer that tracks the number of elements in the stack (it works like the `top` in the typical stack implementation).

#### **Stack Operations**:

1. **Initialize the Stack**:
   ```c
   void initStack(struct Stack *s) {
       s->q1.front = s->q1.rear = -1;
       s->q2.front = s->q2.rear = -1;
       s->top = -1;
   }
   ```
   - **Purpose**: Initializes the two queues (`q1` and `q2`) to be empty (`front` and `rear` are set to `-1`), and sets `top` to `-1`.

2. **Push (Add Element to Stack)**:
   ```c
   void push(struct Stack *s, int value) {
       if (isFull(&s->q1)) {
           printf("Stack is full\n");
       } else {
           enqueue(&s->q1, value);
           s->top++;
       }
   }
   ```
   - **Purpose**: Adds an element `value` to the stack by enqueuing it into `q1`.
   - If `q1` is full, it prints "Stack is full". Otherwise, it enqueues the element into `q1` and increments the `top` of the stack.

3. **Pop (Remove Element from Stack)**:
   ```c
   int pop(struct Stack *s) {
       if (s->top == -1) {
           printf("Stack is empty\n");
           return -1;
       } else {
           while (s->q1.front != s->q1.rear) {
               enqueue(&s->q2, dequeue(&s->q1));
           }
           int value = dequeue(&s->q1);
           s->top--;
           struct Queue temp = s->q1;
           s->q1 = s->q2;
           s->q2 = temp;
           return value;
       }
   }
   ```
   - **Purpose**: Removes the top element from the stack and returns it.
   - This is achieved by transferring all elements from `q1` to `q2`, leaving the last element in `q1` as the top of the stack. That element is dequeued, and the queues are swapped.
   - If the stack is empty (`top == -1`), it prints "Stack is empty".

4. **Check if Stack is Empty**:
   ```c
   int isStackEmpty(struct Stack *s) {
       return s->top == -1;
   }
   ```
   - **Purpose**: Returns `1` if the stack is empty, otherwise returns `0`.

5. **Check if Stack is Full**:
   ```c
   int isStackFull(struct Stack *s) {
       return isFull(&s->q1);
   }
   ```
   - **Purpose**: Returns `1` if the stack is full, otherwise returns `0`.

6. **Display Stack Elements**:
   ```c
   void displayStack(struct Stack *s) {
       if (isStackEmpty(s)) {
           printf("Stack is empty\n");
       } else {
           display(&s->q1);
       }
   }
   ```
   - **Purpose**: Displays the elements of the stack by calling the `display()` function of `q1`. If the stack is empty, it prints "Stack is empty".

---

### **Main Function**:

```c
int main() {
    struct Stack s;
    initStack(&s);
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if Stack is Full\n");
        printf("4. Check if Stack is Empty\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                if (isStackFull(&s)) {
                    printf("Stack is full\n");
                } else {
                    printf("Stack is not full\n");
                }
                break;
            case 4:
                if (isStackEmpty(&s)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                displayStack(&s);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
```

- **`main()`**: This is the main function that runs the menu-driven program. It initializes the stack and allows

 the user to perform the operations like `push`, `pop`, `check if full/empty`, and `display stack`.

---

### **Time Complexity Analysis**:

- **Push Operation (`push()`)**: **O(1)** – Enqueuing into `q1` takes constant time.
- **Pop Operation (`pop()`)**: **O(n)** – In the worst case, we need to transfer all elements from `q1` to `q2`, where `n` is the number of elements in the stack.
- **isStackEmpty()** and **isStackFull()**: **O(1)** – Checking whether the stack is empty or full is a constant time operation.
- **Display Stack (`displayStack()`)**: **O(n)** – Displaying the stack elements requires iterating through the elements in `q1`.

---

### **Space Complexity**:
The space complexity is **O(n)**, where `n` is the number of elements in the stack, as both queues (`q1` and `q2`) hold all the elements of the stack.

