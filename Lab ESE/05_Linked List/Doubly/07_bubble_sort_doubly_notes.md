Let's go through the provided C code in different blocks and explain each line and its purpose. We will also analyze the time complexity and explain the result.

### Code Explanation

#### 1. Structure Definition: `struct Node`
```c
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
```
- **Purpose**: This defines a doubly linked list node. Each `Node` contains:
  - `data`: stores an integer value.
  - `next`: a pointer to the next node in the list.
  - `prev`: a pointer to the previous node in the list.

#### 2. Function to Insert Elements at the End of the List: `InsertEnd()`
```c
void InsertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
```
- **Purpose**: This function inserts a new node with the provided `data` at the end of the doubly linked list.
- **Step-by-step**:
  - `newNode` is created using `malloc()`, and its `data`, `next`, and `prev` pointers are initialized.
  - If the list is empty (`*head == NULL`), `newNode` becomes the first node in the list.
  - If the list is not empty, the function traverses the list using a `while` loop (`temp = temp->next`) until the last node is found.
  - Once the last node is found, the `next` pointer of the last node is updated to point to the new node, and the `prev` pointer of the new node is updated to point to the last node.
  
#### 3. Function to Print the List: `PrintList()`
```c
void PrintList(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
```
- **Purpose**: This function prints all the nodes in the doubly linked list.
- **Step-by-step**:
  - A `while` loop is used to traverse through the list until `head` becomes `NULL`, meaning the end of the list has been reached.
  - The data in each node is printed in the format `data <->`.
  - When the loop ends, `"NULL"` is printed to indicate the end of the list.

#### 4. Bubble Sort on Doubly Linked List: `BubbleSort()`
```c
void BubbleSort(struct Node** head) {
    if (*head == NULL) return;
    int swapped;
    struct Node* temp;
    struct Node* last = NULL;

    do {
        swapped = 0;
        temp = *head;

        while (temp->next != last) {
            if (temp->data > temp->next->data) {
                // Swap data between nodes
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = 1;
            }
            temp = temp->next;
        }
        last = temp;
    } while (swapped);
}
```
- **Purpose**: This function implements the **Bubble Sort** algorithm to sort the doubly linked list in ascending order.
- **Step-by-step**:
  - **Initial Checks**: The function checks if the list is empty (`*head == NULL`) and returns if true.
  - **Main Sorting Loop**:
    - The sorting process is repeated as long as at least one swap occurs (`swapped` flag).
    - A `while` loop is used to traverse the list. If the current node's data is greater than the next node's data (`temp->data > temp->next->data`), the data values are swapped.
    - After each pass, the `last` pointer is moved one step back, indicating the sorted portion of the list.
    - The inner `while` loop continues until it reaches the node before `last` (which is already sorted).
  
#### 5. Main Function: `main()`
```c
int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        InsertEnd(&head, data);
    }

    printf("Before Bubble Sort: ");
    PrintList(head);

    BubbleSort(&head);

    printf("After Bubble Sort: ");
    PrintList(head);

    return 0;
}
```
- **Purpose**: The main function drives the entire program.
- **Step-by-step**:
  - The user is asked for the number of elements (`n`) and their values. These values are inserted into the list one by one using the `InsertEnd()` function.
  - After inserting all the elements, the list is printed using `PrintList()`.
  - The `BubbleSort()` function is then called to sort the list.
  - Finally, the sorted list is printed again using `PrintList()`.

### Time and Space Complexity

#### Time Complexity:
- **Bubble Sort**: The time complexity of the bubble sort in a doubly linked list is **O(n^2)**, where `n` is the number of nodes in the list. The outer loop will run `n` times, and the inner loop will run at most `n-1` times in each pass.
- **Insertion**: Each insertion of a node at the end of the list takes **O(n)** time in the worst case, because you need to traverse the entire list to find the last node.

Thus, the total time complexity of the program is **O(n^2)** due to the bubble sort step being the most time-consuming.

#### Space Complexity:
- **Space Complexity**: The space complexity of the program is **O(n)** because we are allocating memory for `n` nodes, each requiring a constant amount of space. No additional memory is used beyond the memory required for the list itself.

### Example Input and Output

#### Input:
```
Enter the number of elements: 5
Enter the elements:
5 2 8 1 3
```

#### Output:
```
Before Bubble Sort: 5 <-> 2 <-> 8 <-> 1 <-> 3 <-> NULL
After Bubble Sort: 1 <-> 2 <-> 3 <-> 5 <-> 8 <-> NULL
```

### Explanation of Output:
- **Before Bubble Sort**: The list is printed as it was inserted. The numbers are shown in the order they were entered: `5 <-> 2 <-> 8 <-> 1 <-> 3`.
- **After Bubble Sort**: The list is sorted in ascending order using bubble sort: `1 <-> 2 <-> 3 <-> 5 <-> 8`.

### Conclusion:
This C program implements a doubly linked list and uses bubble sort to sort the list in ascending order. The user is prompted for the number of elements and their values, and the program then outputs the list both before and after sorting. The program operates with a time complexity of **O(n^2)** for the sorting step.