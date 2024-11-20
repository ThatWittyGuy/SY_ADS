### Full Code Explanation

This program is designed to find the length of the longest valid parentheses substring within a given string consisting only of the characters `(` and `)`. The idea is to use a **stack** data structure to efficiently track valid parentheses and their matching positions.

---

### **Header Files and Constants**:

```c
#include <stdio.h>
#include <string.h>

#define MAX 100
```

- **`stdio.h`**: This is the standard input/output header file, required for input/output operations like `printf` and `scanf`.
- **`string.h`**: This is included for string manipulation, although it's only needed if we are using functions like `strlen` (not used in this code).
- **`MAX`**: A constant that defines the maximum size of the input string, in this case, 100 characters.

---

### **Global Variables**:

```c
int stack[MAX];
int top = -1;
```

- **`stack[MAX]`**: An array that functions as the stack used to store the indices of characters in the input string `s`. This stack helps us to manage the open and close parentheses.
- **`top`**: A variable that represents the index of the top element in the stack. It's initialized to `-1`, indicating that the stack is initially empty.

---

### **Stack Operations**:

#### **Push Operation**:

```c
void push(int index) {
    if (top < MAX - 1) {
        stack[++top] = index;
    }
}
```

- **`push(int index)`**: This function pushes the index of a character (either `(` or `)`) onto the stack.
  - **`if (top < MAX - 1)`**: This checks whether there is space in the stack. The `top` index should not exceed `MAX - 1`.
  - **`stack[++top] = index;`**: This increments the `top` index and then stores the `index` of the character in the stack.

#### **Pop Operation**:

```c
int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}
```

- **`pop()`**: This function pops the top element from the stack and returns its value (the index of a character).
  - **`if (top >= 0)`**: Checks if the stack is not empty (i.e., `top >= 0`).
  - **`return stack[top--];`**: Returns the top element of the stack and then decreases `top` to remove that element from the stack.
  - If the stack is empty (i.e., `top < 0`), it returns `-1`.

---

### **Longest Valid Parentheses Function**:

```c
int longestValidParentheses(char *s) {
    int maxLength = 0;
    push(-1);  // Push -1 to handle edge cases
```

- **`longestValidParentheses(char *s)`**: This is the main function to calculate the length of the longest valid parentheses substring.
  - **`maxLength = 0;`**: A variable to store the length of the longest valid parentheses substring found so far.
  - **`push(-1);`**: Push `-1` onto the stack to handle edge cases. For example, when we encounter the first valid parentheses substring (e.g., `()`) that matches indices `0` and `1`, the `-1` helps in calculating the length correctly.

#### **Iterating Over the String**:

```c
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            push(i);  // Push the index of '('
        } else {
            pop();  // Pop the last '(' index
```

- The function loops through each character in the string `s`:
  - **`for (int i = 0; s[i] != '\0'; i++)`**: Loops through the string until the null terminator `\0` is reached.
  - **`if (s[i] == '(')`**: If the character is an open parenthesis `(`, the index `i` is pushed onto the stack.
    - **`push(i);`**: The index of the `(` is added to the stack to track its position.
  - **`else`**: If the character is a closing parenthesis `)`, we attempt to match it with the last open parenthesis `(`.

#### **Matching Parentheses**:

```c
            pop();  // Pop the last '(' index
            if (top >= 0) {
                maxLength = (i - stack[top] > maxLength) ? (i - stack[top]) : maxLength;
            } else {
                push(i);  // Push the current index if stack is empty
            }
        }
    }
    return maxLength;
}
```

- **`pop();`**: Removes the last open parenthesis' index from the stack. After this pop, we either have a matched pair or we need to reset the starting index for the next potential valid substring.
  
- **`if (top >= 0)`**: After popping, if the stack is not empty, we calculate the length of the current valid substring:
  - **`maxLength = (i - stack[top] > maxLength) ? (i - stack[top]) : maxLength;`**: The current length of the valid parentheses substring is `i - stack[top]` (i.e., the difference between the current index `i` and the index of the last unmatched open parenthesis). We update `maxLength` if this new length is greater than the previously found longest length.
  
- **`else`**: If the stack is empty after popping (meaning no unmatched open parentheses are left), we push the current index `i` onto the stack to start a new potential valid parentheses substring.

---

### **Main Function**:

```c
int main() {
    char s[MAX];
    
    printf("Enter the string containing only '(' and ')': ");
    scanf("%s", s);
    
    int result = longestValidParentheses(s);
    printf("Length of the longest valid parentheses: %d\n", result);
    
    return 0;
}
```

- **`main()`**: The main function that drives the program.
  - **`char s[MAX];`**: A character array to hold the input string.
  - **`printf("Enter the string containing only '(' and ')': ");`**: Prompts the user to input the parentheses string.
  - **`scanf("%s", s);`**: Reads the string from the user.
  - **`int result = longestValidParentheses(s);`**: Calls the `longestValidParentheses()` function to compute the result.
  - **`printf("Length of the longest valid parentheses: %d\n", result);`**: Prints the length of the longest valid parentheses substring.
  - **`return 0;`**: The program ends.

---

### **Time Complexity Analysis**:

- **Time Complexity**: 
  - The algorithm performs a **single pass** over the string `s`, processing each character once.
  - Each character is pushed onto the stack at most once, and popped from the stack at most once.
  - Thus, the **time complexity** of the function is **O(n)**, where `n` is the length of the input string `s`.

- **Space Complexity**:
  - The space complexity is **O(n)**, since we use a stack that can store up to `n` elements (indices of the characters in the string).
  
---

### **Example Walkthrough**:

For the input string: `(()())`

1. The stack starts with `[-1]` (initializing the base for valid substring calculation).
2. **First iteration (`i = 0`)**: Character is `(`. Push index `0` onto the stack: `[-1, 0]`.
3. **Second iteration (`i = 1`)**: Character is `(`. Push index `1` onto the stack: `[-1, 0, 1]`.
4. **Third iteration (`i = 2`)**: Character is `)`. Pop index `1`. Calculate the valid substring length: `2 - 0 = 2`. Update `maxLength = 2`.
5. **Fourth iteration (`i = 3`)**: Character is `(`. Push index `3` onto the stack: `[-1, 0, 3]`.
6. **Fifth iteration (`i = 4`)**: Character is `)`. Pop index `3`. Calculate the valid substring length: `4 - 0 = 4`. Update `maxLength = 4`.
7. **Sixth iteration (`i = 5`)**: Character is `)`. Pop index `0`. Calculate the valid substring length: `5 - (-1) = 6`. Update `maxLength = 6`.

Thus, the length of the longest valid parentheses substring is **6**.

---

### **Final Thoughts**:

This solution efficiently solves the problem of finding the longest valid parentheses substring using a stack. It runs in linear time **O(n)** and uses linear space **O(n)**. The use of the stack allows us to track unmatched parentheses and compute valid lengths dynamically as we traverse the string.