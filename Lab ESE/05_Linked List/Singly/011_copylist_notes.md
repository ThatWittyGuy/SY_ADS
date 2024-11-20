Here is a breakdown of the code and an explanation for each section along with time complexity analysis.

### 1. Struct Definition

```c
struct Node {
    int data;
    struct Node* next;
};
```
- This defines a structure called `Node` with two members:
  - `data`: This is an integer that holds the value of the node.
  - `next`: A pointer to the next node in the linked list (this forms the linked structure).

### 2. CopyList Function

```c
struct Node* CopyList(struct Node* head) {
    if (head == NULL) return NULL;
```
- **Function Definition**: `CopyList` takes a pointer to the head of a linked list and returns a new linked list that is a copy of the original.
- **Base case**: If the original list is empty (`head == NULL`), it returns `NULL`, indicating there is nothing to copy.

```c
    struct Node* newHead = NULL;
    struct Node* newTail = NULL;
```
- Two pointers are declared:
  - `newHead`: Points to the first node of the copied list.
  - `newTail`: Points to the last node of the copied list (used to append new nodes).

```c
    while (head != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = head->data;
        newNode->next = NULL;
```
- The loop starts with the `head` of the original list. For each node in the original list:
  - A new node `newNode` is created by dynamically allocating memory.
  - The `data` of the new node is set to the `data` of the original node.
  - The `next` pointer of the new node is set to `NULL` (as this will be the last node of the copied list unless another node follows).

```c
        if (newHead == NULL) {
            newHead = newNode;
            newTail = newNode;
        } else {
            newTail->next = newNode;
            newTail = newNode;
        }
```
- If the new list (`newHead`) is empty, meaning this is the first node being added, both `newHead` and `newTail` point to the new node.
- If `newHead` is not `NULL`, the `newTail->next` pointer is updated to point to the new node, and `newTail` is then updated to the new node.

```c
        head = head->next;
    }
```
- Move to the next node in the original list.

```c
    return newHead;
}
```
- After the loop finishes copying all nodes, `newHead` (which points to the first node of the new list) is returned.

### 3. PrintList Function

```c
void PrintList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
```
- **Purpose**: This function takes a pointer to the head of a linked list and prints all the elements in the list.
- **Loop**: It iterates through the list until it reaches the end (`head == NULL`), printing each node's `data` followed by `->`.
- **End**: When the end of the list is reached, it prints `NULL` to indicate the end of the list.

### 4. Main Function

```c
int main() {
    struct Node* head = NULL;
    struct Node* newHead = NULL;
    struct Node* temp;
    int n, data;
```
- **Variable Declaration**:
  - `head`: Pointer to the first node of the original list.
  - `newHead`: Pointer to the first node of the copied list.
  - `temp`: A temporary pointer used while building the original list.
  - `n`: Number of elements in the list.
  - `data`: Integer used to input data for each node.

```c
    printf("Enter number of elements: ");
    scanf("%d", &n);
```
- Asks the user to input the number of elements for the linked list and stores the value in `n`.

```c
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
```
- A loop runs for `n` iterations, asking the user to input `data` for each element.

```c
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
```
- For each element, a new node is created with `data` set to the user-inputted value, and `next` is initialized to `NULL`.

```c
        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
```
- If `head` is `NULL`, meaning the list is empty, the first node (`newNode`) is set as the head.
- Otherwise, the loop finds the last node of the existing list and appends the new node to it.

```c
    printf("Original List: ");
    PrintList(head);
```
- After constructing the original list, it prints the list using the `PrintList` function.

```c
    newHead = CopyList(head);
```
- The `CopyList` function is called, which returns a new list (`newHead`) that is a copy of the original list.

```c
    printf("Copied List: ");
    PrintList(newHead);
```
- The copied list is printed using the `PrintList` function.

### 5. Time Complexity Analysis

- **Time Complexity**:
  - The time complexity of the `CopyList` function is O(n), where `n` is the number of elements in the original list. This is because the function iterates over each node in the original list once to create a new node in the copied list.
  - The `PrintList` function also has a time complexity of O(n), as it traverses the entire list to print the elements.
  - Overall, the time complexity of the main function is O(n) for copying the list and printing both lists.

- **Space Complexity**:
  - The space complexity is O(n), where `n` is the number of nodes in the list, because new nodes are created in the copied list.

### Example Output:

**Input:**
```
Enter number of elements: 4
Enter elements:
1 2 3 4
```

**Output:**
```
Original List: 1 -> 2 -> 3 -> 4 -> NULL
Copied List: 1 -> 2 -> 3 -> 4 -> NULL
```