### Code Breakdown and Explanation

This C program rearranges the input name consisting of a **First Name**, **Middle Name**, and **Surname**. It uses a stack to reverse the order of the names and prints them as `Surname FirstName MiddleName`. Let's go through the program step-by-step.

---

### **Header Files and Macros**:

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100
```

- `stdio.h`: Provides functionality for input and output functions (`printf`, `fgets`, etc.).
- `string.h`: Provides string manipulation functions such as `strtok` and `strcspn`.
- `stdlib.h`: Provides memory allocation functions, though it's not directly needed in this code.
- `MAX_SIZE`: A constant for the maximum input size for names.

---

### **Stack Structure**:

```c
typedef struct {
    char* arr[MAX_SIZE];
    int top;
} Stack;
```

- `Stack`: A structure to represent the stack. It has:
  - `arr[MAX_SIZE]`: An array to hold the elements of the stack (in this case, each element is a string pointer).
  - `top`: An integer that keeps track of the top index of the stack (initialized to `-1` to indicate the stack is empty).

---

### **Functions to Manipulate the Stack**:

#### **Initialize Function**:
```c
void initialize(Stack* stack) {
    stack->top = -1;
}
```

- `initialize`: This function initializes the stack by setting the `top` pointer to `-1` to indicate that the stack is empty.

#### **isEmpty Function**:
```c
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
```

- `isEmpty`: This function checks if the stack is empty by comparing the `top` index to `-1`. If the stack is empty, it returns `1` (true), otherwise `0` (false).

#### **Push Function**:
```c
void push(Stack* stack, char* name) {
    if (stack->top < MAX_SIZE - 1) {
        stack->arr[++stack->top] = name;
    }
}
```

- `push`: This function adds an element (a string `name`) to the top of the stack. 
  - It checks if there is space in the stack (i.e., if `top` is less than `MAX_SIZE - 1`).
  - If space is available, it increments the `top` pointer and places the string `name` into the stack at the `top` position.

#### **Pop Function**:
```c
char* pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return NULL;
}
```

- `pop`: This function removes and returns the element at the top of the stack.
  - It checks if the stack is not empty by calling `isEmpty`. If the stack is not empty, it returns the element at `arr[top]` and decrements `top`.
  - If the stack is empty, it returns `NULL`.

---

### **Main Function**:

```c
int main() {
    Stack stack;
    initialize(&stack);

    char input[MAX_SIZE];
    char *firstName, *middleName, *surname;

    printf("Enter your First Name, Middle Name, and Surname (separated by spaces): ");
    fgets(input, MAX_SIZE, stdin);
    
    input[strcspn(input, "\n")] = 0;
```

- **Stack Initialization**: 
  - `Stack stack;`: Declares a variable `stack` of type `Stack`.
  - `initialize(&stack);`: Initializes the stack by setting `top` to `-1`.

- **Input Handling**:
  - `char input[MAX_SIZE];`: A character array to store the user's input string.
  - `fgets(input, MAX_SIZE, stdin);`: Reads a line of text (including spaces) from standard input (`stdin`) and stores it in `input`. The `fgets` function allows reading a line with spaces, unlike `scanf("%s", ...)`, which stops reading at the first space.
  - `input[strcspn(input, "\n")] = 0;`: This line removes the trailing newline character (`\n`) that `fgets` includes when reading input.

---

### **Tokenizing the Input String**:

```c
    firstName = strtok(input, " ");
    middleName = strtok(NULL, " ");
    surname = strtok(NULL, " ");
```

- **`strtok`**: This function breaks the input string into tokens (substrings) based on a specified delimiter (in this case, a space `" "`).
  - `firstName = strtok(input, " ");`: This call breaks `input` at the first space and returns the first token, i.e., the first name.
  - `middleName = strtok(NULL, " ");`: The second token, i.e., the middle name, is extracted using `NULL` as the first argument, which tells `strtok` to continue from where it left off.
  - `surname = strtok(NULL, " ");`: Similarly, the third token (surname) is extracted.

---

### **Pushing the Names onto the Stack**:

```c
    push(&stack, surname);
    push(&stack, firstName);
    push(&stack, middleName);
```

- The program pushes the names onto the stack in the order: **surname**, **first name**, and **middle name**.
  - `push(&stack, surname);`: Pushes the surname onto the stack.
  - `push(&stack, firstName);`: Pushes the first name onto the stack.
  - `push(&stack, middleName);`: Pushes the middle name onto the stack.

---

### **Popping and Printing the Rearranged Names**:

```c
    printf("Rearranged Names: \n");
    printf("%s %s %s\n", pop(&stack), pop(&stack), pop(&stack));
```

- `pop(&stack)`: The program pops the elements from the stack and prints them in the reversed order:
  - The surname is popped first (since it was pushed last).
  - Then, the first name and middle name are popped in the same order, effectively rearranging the names into `Surname FirstName MiddleName`.

---

### **Program Termination**:
```c
    return 0;
}
```

- The program exits with a status of `0`, indicating successful execution.

---

### **Time Complexity**:

- **Tokenization (`strtok`)**: Tokenizing the input string takes **O(n)** time, where `n` is the length of the input string, since `strtok` processes each character once.
- **Push and Pop Operations**: Both `push` and `pop` operations on the stack take **O(1)** time because they only involve manipulating the `top` index of the stack.
  - Three `push` operations are done (one for each name).
  - Three `pop` operations are done (one for each name).
  
- **Total Time Complexity**: The overall time complexity of the program is **O(n)**, where `n` is the length of the input string (for tokenizing).

---

### **Space Complexity**:

- **Stack Array**: The stack stores up to three strings (first name, middle name, and surname), and each string is stored as a pointer. Therefore, the space complexity for the stack array itself is **O(1)**, as there are only three entries in the stack.
- **Input String**: The input string takes up **O(n)** space where `n` is the length of the string.
  
- **Total Space Complexity**: The total space complexity is **O(n)**, where `n` is the size of the input string.

---

### **Analysis of Result**:

- **Input**: If the user enters `John Michael Doe`, the program will push the names onto the stack in the order: `Doe`, `John`, `Michael`.
- **Output**: The program will print `Doe John Michael`, which is the reversed order: `Surname FirstName MiddleName`.

