### Explanation of the Code in Blocks:

#### 1. **Struct Definition:**

```c
struct Node {
    int data;
    struct Node* next;
};
```

- **`struct Node`** is a data structure representing a node in a linked list. It contains:
  - **`data`**: an integer storing the data of the node.
  - **`next`**: a pointer to the next node in the linked list.

#### 2. **InsertEnd Function:**

```c
void InsertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
```

- **Purpose**: This function inserts a new node at the end of the linked list.
- **Steps**:
  - A new node is created with the given `data`.
  - If the list is empty (`*head == NULL`), the new node becomes the head of the list.
  - Otherwise, it traverses to the last node (`while (temp->next != NULL)`) and links the new node after the last node.

- **Time Complexity**: O(n), where `n` is the number of nodes in the list. This is because we traverse the list to find the end.

#### 3. **InsertSorted Function:**

```c
void InsertSorted(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->data < data) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
```

- **Purpose**: This function inserts a new node into the linked list while keeping the list sorted in ascending order.
- **Steps**:
  - A new node is created with the given `data`.
  - If the list is empty or the new node's data is smaller than or equal to the head's data, the new node is inserted at the beginning.
  - Otherwise, it traverses the list and finds the correct position for the new node.
  - The new node is inserted by adjusting the `next` pointers.
  
- **Time Complexity**: O(n) in the worst case, where `n` is the number of nodes in the list, because we may need to traverse the entire list to find the correct position.

#### 4. **InsertionSort Function:**

```c
void InsertionSort(struct Node** head) {
    struct Node* sorted = NULL;
    struct Node* current = *head;
    while (current != NULL) {
        struct Node* next = current->next;
        InsertSorted(&sorted, current->data);
        current = next;
    }
    *head = sorted;
}
```

- **Purpose**: This function sorts the linked list using the insertion sort algorithm.
- **Steps**:
  - A new list `sorted` is initialized as `NULL`.
  - It iterates over each node in the original list (`while (current != NULL)`).
  - For each node, it inserts the node's data into the sorted list using the `InsertSorted` function.
  - After sorting, the head of the list is updated to point to the sorted list.
  
- **Time Complexity**: O(n^2) where `n` is the number of nodes. The reason for this quadratic complexity is that for each node, we potentially traverse the entire sorted list to insert it into the correct position.

#### 5. **PrintList Function:**

```c
void PrintList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
```

- **Purpose**: This function prints the linked list.
- **Steps**:
  - It iterates through each node in the linked list.
  - For each node, it prints the `data` followed by `" -> "`.
  - When the end of the list is reached, it prints `"NULL"` to indicate the end of the list.

- **Time Complexity**: O(n), where `n` is the number of nodes. We traverse the entire list to print the data.

#### 6. **Main Function:**

```c
int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        InsertEnd(&head, data);
    }

    printf("Before Insertion Sort: ");
    PrintList(head);

    InsertionSort(&head);

    printf("After Insertion Sort: ");
    PrintList(head);

    return 0;
}
```

- **Purpose**: The main function handles user input, manages the linked list operations, and displays the output.
- **Steps**:
  - Initializes an empty linked list (`head = NULL`).
  - Asks the user for the number of elements `n` and then reads the data for each element, inserting them at the end of the list using `InsertEnd`.
  - It prints the list before sorting using `PrintList`.
  - It sorts the list using `InsertionSort`.
  - Finally, it prints the list after sorting using `PrintList`.

### Example Input/Output:

#### Input:

```
Enter number of elements: 5
Enter elements: 5 2 8 1 3
```

#### Output:

```
Before Insertion Sort: 5 -> 2 -> 8 -> 1 -> 3 -> NULL
After Insertion Sort: 1 -> 2 -> 3 -> 5 -> 8 -> NULL
```

### Analysis:

- **Before Insertion Sort**: The linked list contains the elements as entered by the user.
- **After Insertion Sort**: The linked list is sorted in ascending order using the insertion sort algorithm.

### Time Complexity:

- **InsertEnd**: O(n) for each insertion. Overall, for `n` insertions, it is O(n^2) in total.
- **InsertSorted**: O(n) for each insertion in the sorted list. Therefore, for `n` insertions, it is O(n^2) in total.
- **InsertionSort**: Since we call `InsertSorted` for every element in the list, the overall time complexity of insertion sort is **O(n^2)**.
- **PrintList**: O(n) to print the entire list.

### Conclusion:
- The time complexity for sorting the list is **O(n^2)** due to the insertion sort.
- The program correctly takes input, sorts the list using insertion sort, and displays the result before and after sorting.