### Explanation of the Code:

#### 1. **Struct Declaration for Node**
```c
struct Node {
    int data;
    struct Node* next;
};
```
- **Purpose**: This block defines the structure `Node` that represents a single node in the linked list.
  - `int data`: Stores the data for the node.
  - `struct Node* next`: Points to the next node in the linked list.

---

#### 2. **Append Function**
```c
void Append(struct Node** head, int data) {
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
- **Purpose**: This function appends a new node with the specified `data` to the end of the linked list.
- **Steps**:
  - `struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));`: Allocates memory for the new node.
  - `newNode->data = data;`: Sets the `data` of the new node.
  - `newNode->next = NULL;`: Since this is the last node, its `next` pointer is set to `NULL`.
  - If the linked list is empty (`*head == NULL`), the new node is set as the head of the list.
  - Otherwise, it traverses the list to find the last node (`temp`), and appends the new node at the end.

---

#### 3. **SortedInsert Function**
```c
void SortedInsert(struct Node** head, struct Node* newNode) {
    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}
```
- **Purpose**: This function inserts a new node into the linked list in sorted order.
- **Steps**:
  - If the list is empty (`*head == NULL`) or if the new node should be placed at the beginning (`(*head)->data >= newNode->data`), it places the new node at the start and adjusts the `head`.
  - If the node should be inserted in the middle or end, the function traverses the list (`current`), comparing the `data` values, until it finds the correct position.
  - The `newNode` is then inserted in the correct place by adjusting the `next` pointers.

---

#### 4. **PrintList Function**
```c
void PrintList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
```
- **Purpose**: This function prints the linked list in a readable format.
- **Steps**:
  - It iterates through the linked list (`head != NULL`), printing each node's `data`.
  - After printing the data of all nodes, it prints `"NULL"` to signify the end of the list.

---

#### 5. **Main Function**
```c
int main() {
    struct Node* head = NULL;
    struct Node* newNode = NULL;
    int n, data;

    // Get user input for the list
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter %d elements for the list:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        Append(&head, data);  // Append elements to maintain input order
    }

    printf("Original List: ");
    PrintList(head);

    // Get user input for the new node to be inserted
    printf("Enter a value to insert in the sorted list: ");
    scanf("%d", &data);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    SortedInsert(&head, newNode);  // Insert the new node in sorted order

    printf("List after Sorted Insert: ");
    PrintList(head);

    return 0;
}
```
- **Purpose**: The main function orchestrates the entire program by:
  - Taking user input to build the initial linked list.
  - Calling the `Append` function to build the list in input order.
  - Calling `PrintList` to print the original list.
  - Taking input for a new node and inserting it into the list in sorted order using `SortedInsert`.
  - Printing the list after the sorted insertion.

- **Steps**:
  1. The program prompts the user for the number of elements in the list (`scanf("%d", &n)`).
  2. It then takes `n` elements from the user and appends them to the linked list using `Append`.
  3. The original list is printed using `PrintList`.
  4. The program asks the user for a value to insert into the sorted list.
  5. The new node is created and inserted into the list using `SortedInsert`.
  6. The updated list is printed after the insertion.

---

### Example Input/Output:

#### Input:
```
Enter the number of elements in the list: 4
Enter 4 elements for the list:
1 3 4 5
Original List: 1 -> 3 -> 4 -> 5 -> NULL
Enter a value to insert in the sorted list: 2
List after Sorted Insert: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
```

- **Explanation**:
  - The user enters the values `1, 3, 4, 5` to form the list: `1 -> 3 -> 4 -> 5 -> NULL`.
  - Then, the user enters `2` to insert it in the correct sorted position.
  - The sorted insertion results in the list: `1 -> 2 -> 3 -> 4 -> 5 -> NULL`.

---

### Time Complexity Analysis:
- **Append function**: O(n) where `n` is the number of nodes in the list. We have to traverse the list to find the last node and append the new node.
- **SortedInsert function**: O(n) where `n` is the number of nodes in the list. In the worst case, we have to traverse the entire list to find the correct insertion point.
- **PrintList function**: O(n) where `n` is the number of nodes in the list. It iterates through all the nodes to print their values.
  
### Space Complexity:
- The space complexity is O(n), where `n` is the number of nodes in the list, because each node requires memory allocation.

### Overall:
- **Time Complexity**: The overall time complexity for this program is O(n) for building the list, O(n) for sorted insertion, and O(n) for printing the list. Hence, the total complexity is dominated by O(n).
