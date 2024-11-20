Let's break down the provided C code, explaining each block in detail, including the analysis of the result, and providing insights into the time and space complexity.

### Code Breakdown and Explanation:

#### 1. **Struct Definition**:
```c
struct Stack {
    int arr[MAX];
    int top;
};
```
- A `struct Stack` is defined to represent a stack. It contains two members:
  - `arr[MAX]`: An array that will store the stack elements (up to `MAX` elements).
  - `top`: An integer variable that tracks the top index of the stack, initialized to `-1` (indicating an empty stack).

#### 2. **initStack Function**:
```c
void initStack(struct Stack *s) {
    s->top = -1;
}
```
- This function initializes the stack by setting `top` to `-1`, which signifies an empty stack.
- The parameter `struct Stack *s` is a pointer to a stack structure, so the function modifies the stack directly.

#### 3. **isEmpty Function**:
```c
int isEmpty(struct Stack *s) {
    return s->top == -1;
}
```
- This function checks if the stack is empty by verifying if `top` is `-1`.
- If `top` is `-1`, it returns `1` (true), indicating the stack is empty. Otherwise, it returns `0` (false).

#### 4. **peek Function**:
```c
int peek(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return -1;
}
```
- This function returns the top element of the stack without removing it.
- It checks if the stack is not empty using `isEmpty`. If it's not empty, it returns the element at the `top` index.
- If the stack is empty, it returns `-1` to indicate no element is available.

#### 5. **push Function**:
```c
void push(struct Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = value;
    }
}
```
- This function adds a new element to the stack.
- It first checks if there is space in the stack (`top < MAX - 1`). If there is space, it increments `top` and stores the `value` at the `top` index.

#### 6. **pop Function**:
```c
int pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return -1;
}
```
- The `pop` function removes and returns the top element from the stack.
- It checks if the stack is not empty. If the stack has elements, it decrements `top` and returns the element at the `top` index.
- If the stack is empty, it returns `-1`.

#### 7. **sortStack Function**:
```c
void sortStack(struct Stack *s, int order) {
    struct Stack tempStack;
    initStack(&tempStack);
    int temp;

    while (!isEmpty(s)) {
        temp = pop(s);
        if (order == 2) {  // Descending order
            while (!isEmpty(&tempStack) && peek(&tempStack) > temp) {
                push(s, pop(&tempStack));
            }
        } else {  // Ascending order
            while (!isEmpty(&tempStack) && peek(&tempStack) < temp) {
                push(s, pop(&tempStack));
            }
        }
        push(&tempStack, temp);
    }

    while (!isEmpty(&tempStack)) {
        push(s, pop(&tempStack));
    }

    printf("Sorted Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
```
- The `sortStack` function sorts the stack in either ascending or descending order using another temporary stack (`tempStack`).
- **Steps**:
  1. **Initialization**: A temporary stack is created and initialized.
  2. **Pop from Original Stack**: The function pops elements from the original stack (`s`).
  3. **Insertion into Temp Stack**:
     - If the order is **ascending**, it compares the popped element with the top of the temporary stack. If the top of the temporary stack is smaller, it moves elements back to the original stack.
     - If the order is **descending**, it does the opposite.
  4. **Push to Temp Stack**: The current element is pushed onto the temporary stack.
  5. **Final Transfer**: After sorting the elements into the temporary stack, they are transferred back into the original stack to maintain the order.
  6. The sorted stack is displayed.

#### 8. **main Function**:
```c
int main() {
    struct Stack s;
    initStack(&s);
    int choice, value, order;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Stack is Empty\n");
        printf("5. Sort Stack\n");
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
                value = peek(&s);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                } else {
                    printf("Stack is empty\n");
                }
                break;
            case 4:
                if (isEmpty(&s)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                printf("Choose sorting order:\n");
                printf("1. Ascending\n");
                printf("2. Descending\n");
                printf("Enter your choice: ");
                scanf("%d", &order);
                sortStack(&s, order);
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
- The `main` function displays a menu to the user and allows the user to interact with the stack by selecting options.
- **Choices**:
  1. **Push**: Pushes an element onto the stack.
  2. **Pop**: Pops an element from the stack.
  3. **Peek**: Displays the top element of the stack.
  4. **Check if Empty**: Checks if the stack is empty.
  5. **Sort Stack**: Prompts the user to choose the sorting order (ascending or descending) and sorts the stack.
  6. **Exit**: Exits the program.

---

### Time and Space Complexity Analysis:

1. **Push Operation**:
   - Time complexity: **O(1)** (push operation is constant time).
   - Space complexity: **O(1)** (only the `top` index is updated).

2. **Pop Operation**:
   - Time complexity: **O(1)** (pop operation is constant time).
   - Space complexity: **O(1)** (only the `top` index is updated).

3. **SortStack Function**:
   - **Time Complexity**:
     - The main loop iterates over all elements of the original stack (`O(n)` where `n` is the number of elements in the stack).
     - For each element, we perform comparisons and push/pop operations on both the original stack and the temporary stack. Each comparison and move operation takes constant time, so the time complexity is **O(n^2)**.
   - **Space Complexity**:
     - We use one additional stack (`tempStack`) which requires space proportional to the number of elements in the stack, so the space complexity is **O(n)**.

4. **Main Function**:
   - The `main` function provides a menu and handles user interaction. It processes each operation based on user input, which does not significantly impact the overall time or space complexity.

### Final Complexity Summary:
- **Time complexity for sorting**: **O(n^2)** (due to the nested loops for element comparisons and stack transfers).
- **Space complexity for sorting**: **O(n)** (due to the additional temporary stack).

### Conclusion:
This program simulates a stack and allows various operations, including sorting the stack in ascending or descending order using an auxiliary stack. The sorting operation is the most time-intensive, with a time complexity of **O(n^2)** due to the nature of the sorting approach. The space complexity remains **O(n)** due to the temporary stack used during sorting.