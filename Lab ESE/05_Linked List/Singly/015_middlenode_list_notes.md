Here is the full explanation of the C code, broken down into different sections, with a detailed analysis of the result and time complexity.

### 1. **Node Structure Definition**
```c
struct Node {
    int data;
    struct Node* next;
};
```
- **Purpose**: Defines the structure of a node in a singly linked list.
- **Data Members**:
  - `data`: Holds the integer value of the node.
  - `next`: A pointer to the next node in the list.

### 2. **append function**
```c
void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
```
- **Purpose**: Appends a new node with the given data at the end of the linked list.
- **Steps**:
  1. **Memory Allocation**: A new node is created using `malloc` to allocate memory dynamically.
  2. **Assign Data**: The new node's `data` is assigned the value passed to the function.
  3. **Handle Empty List**: If the list is empty (`*head == NULL`), the new node becomes the head of the list.
  4. **Traverse to the End**: If the list is not empty, the code traverses the list to find the last node (node with `next == NULL`).
  5. **Append the Node**: The `next` pointer of the last node is set to the new node, effectively appending the new node to the end of the list.

### 3. **findMiddleNode function**
```c
struct Node* findMiddleNode(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
```
- **Purpose**: Finds and returns the middle node of the linked list using the "Tortoise and Hare" approach.
- **Explanation**:
  1. **Slow and Fast Pointers**: Two pointers are initialized at the head:
     - `slow` moves one step at a time.
     - `fast` moves two steps at a time.
  2. **Loop**: The loop continues until `fast` reaches the end of the list or `fast->next` is `NULL` (i.e., the end of the list is reached).
  3. **Middle Node**: When `fast` reaches the end, `slow` will be at the middle node. If the list has an even number of nodes, `slow` will be at the second middle node (as required).
  
- **Why This Works**: By moving `fast` two steps at a time and `slow` one step at a time, when `fast` reaches the end, `slow` will have moved to the middle. This ensures that for odd-length lists, the exact middle is found, and for even-length lists, the second middle node is returned.

### 4. **printList function**
```c
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
```
- **Purpose**: Prints the entire linked list in the format `data -> data -> ... -> NULL`.
- **Steps**:
  1. **Traversal**: The list is traversed node by node starting from `head`.
  2. **Printing**: The `data` of each node is printed followed by `->` to show the linkage.
  3. **End**: When the last node is reached (`head == NULL`), it prints `NULL` to signify the end of the list.

### 5. **main function**
```c
int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("List: ");
    printList(head);

    struct Node* middle = findMiddleNode(head);
    if (middle != NULL) {
        printf("Middle Node: %d\n", middle->data);
    }

    return 0;
}
```
- **Purpose**: The `main` function drives the program, handles user input, and calls necessary functions to perform the required tasks.
- **Steps**:
  1. **Input**:
     - The user is prompted to enter the number of elements in the list (`n`).
     - The user is then prompted to enter each of the `n` elements one by one.
  2. **Appending Data**: Each data element is appended to the list by calling `append`.
  3. **Printing List**: After constructing the list, `printList` is called to display the contents of the list.
  4. **Finding the Middle**: `findMiddleNode` is called to find and return the middle node of the list.
  5. **Displaying the Middle**: If the middle node is found, its `data` is printed.

### Sample Input/Output:

#### Input:
```
Enter the number of elements: 5
Enter the elements: 1 2 3 4 5
```

#### Output:
```
List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Middle Node: 3
```

#### Input:
```
Enter the number of elements: 4
Enter the elements: 1 2 3 4
```

#### Output:
```
List: 1 -> 2 -> 3 -> 4 -> NULL
Middle Node: 3
```

### Time Complexity Analysis:

- **`append` function**: 
  - The `append` function traverses the list to find the last node and then appends the new node. The time complexity of `append` is **O(n)**, where `n` is the number of nodes in the list.

- **`findMiddleNode` function**:
  - The `findMiddleNode` function uses the slow and fast pointer technique. It traverses the list in a single pass, with the fast pointer moving two steps at a time and the slow pointer moving one step. The time complexity is **O(n)**, where `n` is the number of nodes in the list.

- **`printList` function**:
  - The `printList` function traverses the entire list to print its elements. The time complexity is **O(n)**, where `n` is the number of nodes in the list.

### Overall Time Complexity:
- The time complexity of the program is **O(n)**, where `n` is the number of nodes in the list. This is because the operations of appending elements, finding the middle node, and printing the list all take linear time.

### Space Complexity:
- The space complexity is **O(n)** because the linked list stores `n` nodes, each requiring memory allocation.