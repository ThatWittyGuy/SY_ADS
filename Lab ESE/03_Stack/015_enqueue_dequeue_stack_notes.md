### Full Explanation of the Code:

This program implements a **queue** using two **stacks**. A queue follows the **First In, First Out (FIFO)** principle, whereas a stack follows the **Last In, First Out (LIFO)** principle. Using two stacks, we can simulate the FIFO behavior of a queue by performing stack operations in a certain way.

### **Header Files and Constants:**

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
```

- **`stdio.h`**: This header file is used for standard input/output operations like `printf` and `scanf`.
- **`stdlib.h`**: This header provides memory allocation, process control, and other utilities (although not directly used in this code).
- **`MAX`**: Defines the maximum size of the stack array, which is set to 100.

---

### **Stack Data Structure and Operations:**

#### **Stack Structure:**

```c
struct Stack {
    int arr[MAX];
    int top;
};
```

- **`arr[MAX]`**: An array of integers that stores the elements in the stack.
- **`top`**: An integer representing the top index of the stack. It is initialized to `-1` when the stack is empty.

#### **Stack Operations:**

1. **Initialize Stack**:
   ```c
   void initStack(struct Stack *s) {
       s->top = -1;
   }
   ```
   - **Purpose**: Initializes the stack by setting the `top` index to `-1` (indicating the stack is empty).
   
2. **Check if Stack is Empty**:
   ```c
   int isEmpty(struct Stack *s) {
       return s->top == -1;
   }
   ```
   - **Purpose**: Returns `1` if the stack is empty, otherwise returns `0`. This is checked by seeing if `top` is `-1`.

3. **Push to Stack**:
   ```c
   void push(struct Stack *s, int value) {
       if (s->top < MAX - 1) {
           s->arr[++(s->top)] = value;
       }
   }
   ```
   - **Purpose**: Adds the `value` to the stack by incrementing `top` and inserting the value at the new `top` index.
   - It checks if `top` is less than `MAX - 1` to ensure there is space in the stack.

4. **Pop from Stack**:
   ```c
   int pop(struct Stack *s) {
       if (!isEmpty(s)) {
           return s->arr[(s->top)--];
       }
       return -1;
   }
   ```
   - **Purpose**: Removes and returns the value at the top of the stack, and then decrements the `top` index.
   - If the stack is empty, it returns `-1`.

5. **Peek Top Element of Stack**:
   ```c
   int peek(struct Stack *s) {
       if (!isEmpty(s)) {
           return s->arr[s->top];
       }
       return -1;
   }
   ```
   - **Purpose**: Returns the top value of the stack without removing it. If the stack is empty, it returns `-1`.

---

### **Queue Data Structure Using Two Stacks:**

#### **Queue Structure:**

```c
struct MyQueue {
    struct Stack stack1;
    struct Stack stack2;
};
```

- **`stack1`** and **`stack2`**: Two stacks used to simulate the queue. 
- **`MyQueue`** is a structure that encapsulates the two stacks used for enqueue and dequeue operations.

#### **Queue Operations:**

1. **Initialize Queue**:
   ```c
   void initQueue(struct MyQueue *q) {
       initStack(&q->stack1);
       initStack(&q->stack2);
   }
   ```
   - **Purpose**: Initializes both `stack1` and `stack2` by calling `initStack()` for each stack. These two stacks will be used to implement the queue's enqueue and dequeue operations.

2. **Enqueue (Add Element to Queue)**:
   ```c
   void enqueue(struct MyQueue *q, int value) {
       push(&q->stack1, value);
   }
   ```
   - **Purpose**: Adds `value` to the queue by pushing it onto `stack1`. This operation is efficient (O(1)) because it simply involves a push onto `stack1`.

3. **Dequeue (Remove Element from Queue)**:
   ```c
   int dequeue(struct MyQueue *q) {
       if (isEmpty(&q->stack2)) {
           while (!isEmpty(&q->stack1)) {
               push(&q->stack2, pop(&q->stack1));
           }
       }
       return pop(&q->stack2);
   }
   ```
   - **Purpose**: Removes and returns the front element of the queue.
   - If `stack2` is empty, it transfers all elements from `stack1` to `stack2`, effectively reversing the order of elements to simulate the FIFO behavior of a queue.
   - After this transfer, `pop()` is called on `stack2` to remove the front element from the queue. This process ensures that the oldest element (which was pushed into `stack1` first) is dequeued first.
   - **Time Complexity of Dequeue**: The worst-case time complexity is **O(n)**, where `n` is the number of elements in the queue, because all elements in `stack1` must be moved to `stack2`. However, this happens only when `stack2` is empty, and subsequent `dequeue()` operations take **O(1)**.

---

### **Main Function:**

```c
int main() {
    struct MyQueue q;
    initQueue(&q);
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                } else {
                    printf("Queue is empty\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
```

- **`main()`**: This is the entry point of the program. It uses a menu-driven interface to allow the user to perform `enqueue`, `dequeue`, and `exit` operations on the queue.
- The user interacts with the program by entering a choice from the menu, which either performs the respective queue operation or exits the program.
- The `enqueue` operation calls `enqueue(&q, value)`, which adds an element to `stack1`.
- The `dequeue` operation calls `dequeue(&q)`, which removes an element from the queue by transferring elements from `stack1` to `stack2` if necessary.

---

### **Time Complexity Analysis:**

1. **Enqueue Operation (`enqueue()`)**:
   - Time complexity: **O(1)**. Adding an element to `stack1` is a simple push operation, which takes constant time.

2. **Dequeue Operation (`dequeue()`)**:
   - In the worst case, when `stack2` is empty, we need to transfer all elements from `stack1` to `stack2`. This transfer operation takes **O(n)** time, where `n` is the number of elements in `stack1`.
   - After the transfer, removing an element from `stack2` takes **O(1)** time.
   - **Overall worst-case time complexity**: **O(n)**. However, since each element is moved from `stack1` to `stack2` only once, the amortized time complexity of each `dequeue()` is **O(1)**.

3. **Peek Operation**:
   - **O(1)**. The `peek()` operation checks the top element of `stack2` if it exists. If `stack2` is empty, it returns `-1`.

---

### **Space Complexity:**

- The space complexity is **O(n)**, where `n` is the number of elements in the queue. This is because both stacks (`stack1` and `stack2`) together store all the elements in the queue.

---

### **Summary of Time Complexity**:
- **Enqueue (push operation)**: **O(1)**
- **Dequeue (pop operation)**: Worst-case **O(n)**, amortized **O(1)** per dequeue.
- **Peek**: **O(1)**
