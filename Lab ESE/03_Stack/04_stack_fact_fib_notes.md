### Code Breakdown and Explanation

This C program implements a simple menu-driven application where the user can either calculate the factorial of a number or generate the Fibonacci series using a stack. Let's break down the code and understand it block by block.

---

### **Header Files and Constants**:

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
```

- **`stdio.h`**: This header file is included to use input-output functions like `printf` and `scanf`.
- **`stdlib.h`**: This header is included but not necessary in this specific code (used for memory allocation and other utilities, though not used here).
- **`MAX`**: A constant defining the maximum size of the stack. The stack can hold up to 100 elements.

---

### **Global Variables**:

```c
int stack[MAX];
int top = -1;
```

- **`stack[MAX]`**: An array of integers to simulate a stack.
- **`top`**: An integer that keeps track of the top index of the stack. It is initialized to `-1` to indicate that the stack is empty.

---

### **Stack Operations**:

#### **Push Operation**:

```c
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}
```

- The **`push`** function adds an element to the stack.
  - **`if (top < MAX - 1)`**: Checks if there is space in the stack (i.e., `top` is less than `MAX - 1`).
  - **`stack[++top] = value;`**: Increments `top` and then assigns the value to the stack at the new `top` index.
  - If the stack is full, it prints `"Stack Overflow"`.

#### **Pop Operation**:

```c
int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}
```

- The **`pop`** function removes and returns the top element from the stack.
  - **`if (top >= 0)`**: Checks if the stack is not empty (i.e., `top` is not `-1`).
  - **`return stack[top--];`**: Returns the element at `stack[top]` and then decrements `top` to point to the next element.
  - If the stack is empty, it prints `"Stack Underflow"` and returns `-1`.

---

### **Factorial Function**:

```c
void factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        push(i);
    }
    while (top >= 0) {
        result *= pop();
    }
    printf("Factorial of %d is %d\n", n, result);
}
```

- The **`factorial`** function calculates the factorial of a given number `n` using the stack.
  - **`int result = 1;`**: Initializes the result variable to 1.
  - **`for (int i = 1; i <= n; i++) { push(i); }`**: Pushes all integers from `1` to `n` onto the stack.
  - **`while (top >= 0)`**: Pops each value from the stack and multiplies it with `result` to calculate the factorial.
  - **`printf("Factorial of %d is %d\n", n, result);`**: Prints the result.

- **Example**:
  - For `n = 5`, the stack will store `1, 2, 3, 4, 5` and then pop them to calculate the factorial `5 * 4 * 3 * 2 * 1 = 120`.

---

### **Fibonacci Function**:

```c
void fibonacci(int n) {
    if (n <= 0) return;
    push(0);
    if (n > 1) push(1);
    printf("Fibonacci Series: 0 ");
    if (n > 1) printf("1 ");
    for (int i = 2; i < n; i++) {
        int a = pop();
        int b = stack[top];
        push(a);
        int next = a + b;
        push(next);
        printf("%d ", next);
    }
    printf("\n");
}
```

- The **`fibonacci`** function generates the Fibonacci series up to `n` terms using the stack.
  - **`if (n <= 0) return;`**: If `n` is less than or equal to 0, it returns immediately as the Fibonacci series doesn't make sense for such values.
  - **`push(0);`**: Pushes the first Fibonacci number `0` onto the stack.
  - **`if (n > 1) push(1);`**: Pushes the second Fibonacci number `1` onto the stack if `n` is greater than 1.
  - **`printf("Fibonacci Series: 0 ");`**: Prints the first Fibonacci number.
  - **`if (n > 1) printf("1 ");`**: Prints the second Fibonacci number if `n > 1`.
  - **`for (int i = 2; i < n; i++)`**: For each subsequent Fibonacci number:
    - **`int a = pop();`**: Pops the top value (the previous Fibonacci number).
    - **`int b = stack[top];`**: Peeks at the second-to-top value (the one before the previous Fibonacci number).
    - **`push(a);`**: Pushes the value `a` back onto the stack.
    - **`int next = a + b;`**: Calculates the next Fibonacci number.
    - **`push(next);`**: Pushes the calculated next Fibonacci number onto the stack.
    - **`printf("%d ", next);`**: Prints the next Fibonacci number.
  - **`printf("\n");`**: Prints a newline after displaying the Fibonacci series.

- **Example**:
  - For `n = 5`, the stack will store the Fibonacci numbers as it goes: `0, 1, 1, 2, 3`.

---

### **Main Function**:

```c
int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Calculate Factorial\n");
        printf("2. Generate Fibonacci Series\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to calculate factorial: ");
                scanf("%d", &value);
                factorial(value);
                break;
            case 2:
                printf("Enter the number of terms for Fibonacci series: ");
                scanf("%d", &value);
                fibonacci(value);
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

- The **`main`** function presents a menu to the user and prompts them to choose an option:
  - **Option 1**: Calculate the factorial of a number by calling the `factorial` function.
  - **Option 2**: Generate the Fibonacci series up to a specified number of terms by calling the `fibonacci` function.
  - **Option 3**: Exit the program.
- The program continues to run in a loop until the user chooses to exit (Option 3).

---

### **Time Complexity**:

- **Push and Pop Operations**: Each operation (push or pop) takes **O(1)** time.
  
- **Factorial Function**: 
  - Pushing and popping numbers from 1 to `n` takes **O(n)** time. 
  - Thus, the **factorial function** has a time complexity of **O(n)**.

- **Fibonacci Function**: 
  - The Fibonacci function involves pushing and popping numbers for `n` terms. Each iteration involves pushing two numbers and popping one number, making it **O(n)**.
  - Hence, the **Fibonacci function** also has a time complexity of **O(n)**.

- **Overall Time Complexity**: The overall time complexity of the program depends on the user's choice and input:
  - For calculating factorial or generating Fibonacci series, the time complexity is **O(n)**.

### **Space Complexity**:

- **Space for the Stack**: The stack can store up to `n` elements (for factorial and Fibonacci functions), so the space complexity is **O(n)**.
- **Overall Space Complexity**: **O(n)** due to the stack size.

### **Conclusion**:

This program uses a stack to calculate the factorial of a number and generate the Fibonacci series. Each operation (push and pop) takes constant time, and both the factorial and Fibonacci operations have linear time complexity in terms of the input size. The space complexity is also linear due to the stack usage. The code is efficient and demonstrates stack usage in solving mathematical problems.