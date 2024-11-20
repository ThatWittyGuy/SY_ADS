Let's break down and explain the provided C code step by step. The program implements **two stacks using a single array** and provides a menu-driven interface for the user to interact with the stacks.

### Code Breakdown:

---

### 1. Header Files and Global Definitions

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
```

- **`#include <stdio.h>`**: Includes the standard input/output library, necessary for functions like `printf()` and `scanf()`.
- **`#include <stdlib.h>`**: Includes the standard library, which isn't strictly needed in this case since there are no dynamic memory allocation calls (like `malloc` or `free`), but it is often included for utility functions.
- **`#define MAX 100`**: Defines a constant `MAX` with a value of 100, indicating the maximum size of the array used for both stacks.

---

### 2. Global Variables

```c
int arr[MAX];
int top1 = -1, top2 = MAX;
```

- **`arr[MAX]`**: An array that will be used to hold the elements for both stacks. The array size is defined by the `MAX` constant (100 in this case).
- **`top1 = -1`**: A variable that tracks the top of Stack 1. It starts at `-1` to indicate that Stack 1 is initially empty.
- **`top2 = MAX`**: A variable that tracks the top of Stack 2. It starts at `MAX`, meaning that Stack 2 starts at the end of the array.

---

### 3. Functions for Stack Operations

#### **Push Operations**

```c
void push1(int value) {
    if (top1 < top2 - 1) {
        arr[++top1] = value;
    } else {
        printf("Stack 1 is full\n");
    }
}

void push2(int value) {
    if (top1 < top2 - 1) {
        arr[--top2] = value;
    } else {
        printf("Stack 2 is full\n");
    }
}
```

- **`push1(int value)`**: 
  - Pushes a value onto Stack 1. 
  - The `if` condition checks if there is space left in the array by ensuring `top1` is less than `top2 - 1`. This ensures that Stack 1 doesn't overlap Stack 2.
  - If there is space, the value is placed at the next available position, and `top1` is incremented.
  - If the condition fails, Stack 1 is full, and the message `"Stack 1 is full"` is displayed.

- **`push2(int value)`**: 
  - Pushes a value onto Stack 2.
  - The `if` condition checks the same condition as in `push1` to avoid Stack 1 and Stack 2 from overlapping.
  - If there is space, the value is placed at the next available position, and `top2` is decremented.
  - If Stack 2 is full, the message `"Stack 2 is full"` is printed.

#### **Pop Operations**

```c
int pop1() {
    if (top1 >= 0) {
        return arr[top1--];
    } else {
        printf("Stack 1 is empty\n");
        return -1;
    }
}

int pop2() {
    if (top2 < MAX) {
        return arr[top2++];
    } else {
        printf("Stack 2 is empty\n");
        return -1;
    }
}
```

- **`pop1()`**: 
  - Pops the top element from Stack 1.
  - If `top1` is `>= 0`, it returns the element at `arr[top1]` and decrements `top1`.
  - If `top1` is `-1`, Stack 1 is empty, and the message `"Stack 1 is empty"` is printed.

- **`pop2()`**: 
  - Pops the top element from Stack 2.
  - If `top2` is `< MAX`, it returns the element at `arr[top2]` and increments `top2`.
  - If `top2` is `MAX`, Stack 2 is empty, and the message `"Stack 2 is empty"` is printed.

#### **Stack Full and Empty Check Functions**

```c
int stackFull() {
    return top1 >= top2 - 1;
}

int stackEmpty1() {
    return top1 == -1;
}

int stackEmpty2() {
    return top2 == MAX;
}
```

- **`stackFull()`**: 
  - Returns `true` if both stacks are full, i.e., if `top1` is greater than or equal to `top2 - 1`.
  - If both stacks are full, there is no space left in the array for further operations.

- **`stackEmpty1()`**: 
  - Returns `true` if Stack 1 is empty (`top1 == -1`).

- **`stackEmpty2()`**: 
  - Returns `true` if Stack 2 is empty (`top2 == MAX`).

#### **Display Functions**

```c
void display1() {
    if (top1 == -1) {
        printf("Stack 1 is empty\n");
    } else {
        printf("Stack 1 elements: ");
        for (int i = 0; i <= top1; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void display2() {
    if (top2 == MAX) {
        printf("Stack 2 is empty\n");
    } else {
        printf("Stack 2 elements: ");
        for (int i = MAX - 1; i >= top2; i--) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
```

- **`display1()`**: 
  - Displays all elements in Stack 1. It loops from `0` to `top1` and prints each element.
  - If Stack 1 is empty (`top1 == -1`), it prints `"Stack 1 is empty"`.

- **`display2()`**: 
  - Displays all elements in Stack 2. It loops from `MAX - 1` down to `top2` and prints each element.
  - If Stack 2 is empty (`top2 == MAX`), it prints `"Stack 2 is empty"`.

---

### 4. Main Function and Menu

```c
int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Check if Stack 1 is full\n");
        printf("6. Check if Stack 2 is full\n");
        printf("7. Check if Stack 1 is empty\n");
        printf("8. Check if Stack 2 is empty\n");
        printf("9. Display Stack 1\n");
        printf("10. Display Stack 2\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push to Stack 1: ");
                scanf("%d", &value);
                push1(value);
                break;
            case 2:
                printf("Enter value to push to Stack 2: ");
                scanf("%d", &value);
                push2(value);
                break;
            case 3:
                value = pop1();
                if (value != -1) {
                    printf("Popped from Stack 1: %d\n", value);
                }
                break;
            case 4:
                value = pop2();
                if (value != -1) {
                    printf("Popped from Stack 2: %d\n", value);
                }
                break;
            case 5:
                if (stackFull()) {
                    printf("Both stacks are full\n");
                } else {
                    printf("Both stacks are not full\n");
                }
                break;
            case 6:
                if (stackFull()) {
                    printf("Both stacks are full\n");
                } else {
                    printf("Both stacks are not full\n");
                }
                break;
            case 7:
                if (stackEmpty1()) {
                    printf("Stack 1 is empty\n");
                } else {
                    printf("Stack 1 is not empty\n");
                }
                break;
            case 8:
                if (stackEmpty2()) {
                    printf("Stack 2 is empty\n");
                } else {
                    printf("Stack 2 is not empty\n");
                }
                break;
            case 9:
                display1();
                break;
            case 10:
                display2();
                break;
            case 11:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
```

### Explanation of `main()`:
- The program presents a menu of options to the user to interact with Stack 1 and Stack 2.
- Based on user input, it calls the corresponding function (push, pop, display, etc.).
- The `switch` statement handles all the menu options, and the program loops until the user chooses to exit (option 11).

---

### Time Complexity Analysis:



1. **Push Operations (`push1`, `push2`)**:  
   - Time complexity: **O(1)**.  
   - Pushing an element involves checking if the stack is full (constant time) and then adding the element at the next available position (constant time).

2. **Pop Operations (`pop1`, `pop2`)**:  
   - Time complexity: **O(1)**.  
   - Popping an element involves checking if the stack is empty (constant time) and then removing the element (constant time).

3. **Stack Full and Empty Checks (`stackFull`, `stackEmpty1`, `stackEmpty2`)**:  
   - Time complexity: **O(1)**.  
   - These functions simply compare the stack pointers (`top1`, `top2`) with constant-time operations.

4. **Display Operations (`display1`, `display2`)**:  
   - Time complexity: **O(n)**, where `n` is the number of elements in the respective stack.  
   - These functions loop through the elements of the stack to display them, so their time complexity depends on the number of elements in the stack.

### Space Complexity:
- The space complexity is **O(MAX)** because we are using a single array of size `MAX` to store both stacks.

---

### Conclusion:
The program efficiently implements two stacks using a single array, with constant time operations for push, pop, and stack checks. The time complexity for displaying stack contents depends on the number of elements, but all basic operations run in constant time. The design is optimal for the given constraints.