### Full Code Explanation

This C program implements a stack with an additional feature to efficiently track the minimum element in the stack. The main idea is to use two stacks: one for storing the elements (`stack`) and another (`minStack`) to store the minimum elements at each level of the stack.

Let’s break down the program and explain each part.

---

### **Header Files and Constants**:

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
```

- **`stdio.h`**: This header file is included to allow input and output operations using functions like `printf` and `scanf`.
- **`stdlib.h`**: This header file is included but not used in the code (it's typically used for memory management, random number generation, etc.).
- **`MAX`**: A constant defining the maximum size of the stack. In this case, the stack can hold up to 100 elements.

---

### **Global Variables**:

```c
int stack[MAX];
int minStack[MAX];
int top = -1;
```

- **`stack[MAX]`**: The array used to store the elements of the stack.
- **`minStack[MAX]`**: An auxiliary stack used to store the minimum element at each level. The minimum element of the stack is always at the same position in `minStack` as the corresponding element in `stack`.
- **`top`**: An integer variable that tracks the index of the top element in the `stack`. Initially, `top` is set to `-1` to indicate that the stack is empty.

---

### **Stack Operations**:

#### **Push Operation**:

```c
void push(int val) {
    if (top < MAX - 1) {
        stack[++top] = val;
        if (top == 0 || val < minStack[top - 1]) {
            minStack[top] = val;
        } else {
            minStack[top] = minStack[top - 1];
        }
    }
}
```

- The **`push`** function adds an element to the stack.
  - **`if (top < MAX - 1)`**: Ensures that there is space in the stack.
  - **`stack[++top] = val;`**: Increments the `top` and adds the element `val` to the `stack`.
  - **Minimum Tracking**: 
    - **`if (top == 0 || val < minStack[top - 1])`**: If the stack is empty or the current element is smaller than the previous minimum, the current element is pushed onto `minStack` as the new minimum.
    - **`minStack[top] = minStack[top - 1];`**: Otherwise, the previous minimum remains the same, and the current element is pushed onto `minStack`.
    
- The key idea is to maintain the `minStack` such that each element of `minStack` represents the minimum value in the `stack` up to that point.

#### **Pop Operation**:

```c
void pop() {
    if (top >= 0) {
        top--;
    }
}
```

- The **`pop`** function removes the top element from the `stack` by decrementing `top`. 
  - **`if (top >= 0)`**: Ensures that the stack is not empty before popping.
  - After the element is popped from the stack, the corresponding element is also removed from the `minStack` as they are linked.

#### **Top Element**:

```c
int topElement() {
    if (top >= 0) {
        return stack[top];
    }
    return -1;
}
```

- The **`topElement`** function returns the element at the top of the stack.
  - **`if (top >= 0)`**: If the stack is not empty, the top element is returned.
  - If the stack is empty, it returns `-1`.

#### **Get Minimum Element**:

```c
int getMin() {
    if (top >= 0) {
        return minStack[top];
    }
    return -1;
}
```

- The **`getMin`** function returns the minimum element in the stack.
  - **`if (top >= 0)`**: If the stack is not empty, it returns the top element from the `minStack` (which always contains the minimum element at the corresponding position in the `stack`).
  - If the stack is empty, it returns `-1`.

#### **Check if Stack is Empty**:

```c
int isEmpty() {
    return top == -1;
}
```

- The **`isEmpty`** function checks if the stack is empty.
  - **`return top == -1;`**: If `top` is `-1`, it means the stack is empty, so it returns `1` (true). Otherwise, it returns `0` (false).

#### **Display Stack**:

```c
void display() {
    if (top >= 0) {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("Stack is empty\n");
    }
}
```

- The **`display`** function prints all elements in the stack.
  - **`if (top >= 0)`**: If the stack is not empty, it iterates through the stack from index `0` to `top` and prints each element.
  - If the stack is empty, it prints `"Stack is empty"`.

---

### **Main Function**:

```c
int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Get Min\n");
        printf("5. Check if stack is empty\n");
        printf("6. Display stack\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                printf("Popped top element.\n");
                break;
            case 3:
                value = topElement();
                if (value != -1) {
                    printf("Top element: %d\n", value);
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            case 4:
                value = getMin();
                if (value != -1) {
                    printf("Minimum element: %d\n", value);
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            case 5:
                if (isEmpty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
```

- The **`main`** function presents a menu-driven interface to the user with the following options:
  1. **Push**: Adds an element to the stack.
  2. **Pop**: Removes the top element from the stack.
  3. **Top**: Displays the top element in the stack.
  4. **Get Min**: Displays the minimum element in the stack.
  5. **Check if stack is empty**: Checks if the stack is empty.
  6. **Display stack**: Displays all elements in the stack.
  7. **Exit**: Exits the program.

- The program runs in a loop until the user chooses to exit.

---

### **Time Complexity Analysis**:

- **Push Operation**: 
  - Each push operation involves adding an element to the `stack` and updating the `minStack`. Both of these operations are **O(1)**.
  
- **Pop Operation**: 
  - Each pop operation involves removing the top element from both the `stack` and the `minStack`. This operation is also **O(1)**.

- **Top Element**: 
  - Retrieving the top element from the `stack` takes **O(1)** time.

- **Get Minimum Element**: 
  - Retrieving the minimum element from the `minStack` also takes **O(1)** time.

- **Is Empty**: 
  - Checking whether the stack is empty involves comparing `top` to `-1`, which is an **O(1)** operation.

- **Display Stack**: 
  - Displaying the stack involves iterating through the elements from `0` to `top`. Thus, the time complexity for this operation is **O(n)**, where `n` is the number of elements in the stack.

### **Space Complexity**:

- **Stack**: The space used by the `stack` is **O(n)**, where `n` is the number of elements in the stack.
- **Min Stack**: The space used by the `minStack` is also **O(n)**.
- Overall, the **space complexity** of the program is **O(n)**.

---

### **Conclusion**:

This program provides an efficient implementation of a stack that tracks the minimum element in constant time. The key optimization here is the use of an auxiliary