### Full Code Explanation

This code demonstrates how to implement a **stack** using two **queues**. It involves two main components:
1. **Queue**: A linear data structure that operates on a First-In-First-Out (FIFO) principle.
2. **Stack**: A linear data structure that operates on a Last-In-First-Out (LIFO) principle.

The idea here is to simulate a stack using two queues. We can push elements onto the stack using the enqueue operation of the queues, and pop elements using the dequeue operation.

### **Header Files and Constants**:

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 5
```

- **`stdio.h`**: This header is included for standard input and output functions like `printf` and `scanf`.
- **`stdlib.h`**: This is included in case memory allocation is needed, though it's not actually used in this program.
- **`MAX`**: A constant that defines the maximum size of both queues and the stack (in this case, 5).

---

### **Queue Structure and Functions**:

#### **Queue Structure**:

```c
struct Queue {
    int front, rear;
    int arr[MAX];
};
```

- **`front`**: The index pointing to the front of the queue.
- **`rear`**: The index pointing to the rear of the queue.
- **`arr[MAX]`**: An array that holds the elements of the queue.

#### **Queue Operations**:

- **`enqueue()`**: Adds an element to the rear of the queue.
- **`dequeue()`**: Removes an element from the front of the queue.
- **`isEmpty()`**: Checks if the queue is empty.
- **`isFull()`**: Checks if the queue is full.
- **`display()`**: Displays the elements of the queue.

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

- **`enqueue(struct Queue *q, int value)`**:
  - If the queue is full (`q->rear == MAX - 1`), it prints "Queue Overflow."
  - If the queue is empty (`q->front == -1`), it sets the front to `0`.
  - Adds the `value` at the `rear` of the queue and increments the `rear`.

```c
int dequeue(struct Queue *q) {
    if (q->front == -1) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int value = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1; // Reset if the queue becomes empty
        } else {
            q->front++;
        }
        return value;
    }
}
```

- **`dequeue(struct Queue *q)`**:
  - If the queue is empty (`q->front == -1`), it prints "Queue Underflow" and returns `-1`.
  - Otherwise, it removes the element from the `front` of the queue and increments the `front`. If the queue becomes empty after the dequeue operation, it resets both `front` and `rear` to `-1`.

```c
int isEmpty(struct Queue *q) {
    return q->front == -1;
}

int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

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

- **`isEmpty(struct Queue *q)`**: Returns `1` if the queue is empty, else returns `0`.
- **`isFull(struct Queue *q)`**: Returns `1` if the queue is full, else returns `0`.
- **`display(struct Queue *q)`**: Displays all elements from the `front` to the `rear` of the queue. If the queue is empty, it prints "Queue is empty."

---

### **Stack Structure and Functions**:

#### **Stack Structure**:

```c
struct Stack {
    struct Queue q1, q2;
    int top;
};
```

- **`q1`**: The first queue used for implementing the stack operations.
- **`q2`**: The second queue used for temporary storage during stack operations.
- **`top`**: An integer tracking the top of the stack (number of elements in the stack).

#### **Stack Operations**:

- **`initStack()`**: Initializes the stack.
- **`push()`**: Adds an element to the stack.
- **`pop()`**: Removes the top element from the stack.
- **`isStackEmpty()`**: Checks if the stack is empty.
- **`isStackFull()`**: Checks if the stack is full.
- **`displayStack()`**: Displays the elements of the stack.

```c
void initStack(struct Stack *s) {
    s->q1.front = s->q1.rear = -1;
    s->q2.front = s->q2.rear = -1;
    s->top = -1;
}
```

- **`initStack(struct Stack *s)`**: Initializes the stack by resetting both queues (`q1` and `q2`) to empty and setting `top` to `-1`.

```c
void push(struct Stack *s, int value) {
    if (isFull(&s->q1) && isFull(&s->q2)) {
        printf("Stack is full\n");
    } else {
        enqueue(&s->q1, value);
        s->top++;
    }
}
```

- **`push(struct Stack *s, int value)`**:
  - If both queues are full (`isFull(&s->q1)` and `isFull(&s->q2)`), it prints "Stack is full."
  - Otherwise, it enqueues the value in `q1` and increments `top`.

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

- **`pop(struct Stack *s)`**:
  - If the stack is empty (`s->top == -1`), it prints "Stack is empty" and returns `-1`.
  - Otherwise, it transfers all but the last element from `q1` to `q2`. After this, the last element in `q1` is the top element of the stack, and it is dequeued. The stacks `q1` and `q2` are swapped to maintain the correct order for subsequent operations.

```c
int isStackEmpty(struct Stack *s) {
    return s->top == -1;
}

int isStackFull(struct Stack *s) {
    return isFull(&s->q1) && isFull(&s->q2);
}

void displayStack(struct Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        display(&s->q1);
    }
}
```

- **`isStackEmpty(struct Stack *s)`**: Returns `1` if the stack is empty, else returns `0`.
- **`isStackFull(struct Stack *s)`**: Returns `1` if the stack is full (both queues are full), else returns `0`.
- **`displayStack(struct Stack *s)`**: Displays the elements in the stack by showing the contents of `q1`. If the stack is empty, it prints "Stack is empty."

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
            case 4

:
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

- **`main()`**: The driver function that allows the user to interact with the stack.
  - It initializes the stack and runs a menu-driven loop for the user to choose various operations.
  - Based on the user's choice, it performs `push`, `pop`, `isStackFull`, `isStackEmpty`, or `displayStack`.

---

### **Time Complexity Analysis**:

- **Time Complexity**:
  - **`push()`**: The time complexity of `push` is **O(1)** because we just enqueue an element in `q1`, which is an O(1) operation.
  - **`pop()`**: The time complexity of `pop` is **O(n)** because we transfer all elements from `q1` to `q2`, where `n` is the number of elements in the stack.
  - **`isStackFull()`** and **`isStackEmpty()`**: Both are **O(1)** operations.
  - **`displayStack()`**: This is **O(n)** since we need to traverse `q1` to display the stack elements.

- **Space Complexity**:
  - The space complexity is **O(n)** where `n` is the number of elements in the stack. This is because both queues (`q1` and `q2`) together hold the stack elements.

---

### **Example Walkthrough**:

For example, if we perform the following operations:

1. **Push 10**: Stack becomes `[10]`.
2. **Push 20**: Stack becomes `[10, 20]`.
3. **Pop**: Pops 20, remaining stack `[10]`.
4. **Push 30**: Stack becomes `[10, 30]`.
5. **Display**: Displays `[10, 30]`.

The program will correctly maintain and simulate a stack using two queues.

