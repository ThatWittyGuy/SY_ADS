The provided code is an implementation of a **doubly linked list-based queue** in C. It allows enqueueing (adding elements to the queue), dequeueing (removing elements from the queue), and displaying the contents of the queue.

### **Code Breakdown**

#### **Structure Definition:**
```c
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
```
- **struct Node** defines a node in the doubly linked list.
  - **`int data`** stores the data for each node.
  - **`struct Node* next`** points to the next node in the list.
  - **`struct Node* prev`** points to the previous node in the list.

This structure supports both forward and backward traversal in the queue.

#### **Global Pointers:**
```c
struct Node* front = NULL;
struct Node* rear = NULL;
```
- **`front`**: Points to the front node of the queue.
- **`rear`**: Points to the rear node of the queue.

Both of these pointers are initialized to `NULL` since the queue is initially empty.

### **Functions Breakdown**

#### **`add(int data)` Function (Enqueue):**
```c
void add(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear != NULL) {
        rear->next = newNode;
    }
    rear = newNode;

    if (front == NULL) {
        front = newNode;
    }
}
```
- **Purpose**: Adds a new node at the rear (end) of the queue.
- **Steps**:
  - A new node is created using `malloc`, and its `data` is set to the passed argument.
  - The `next` pointer of the new node is set to `NULL` (since it will be the last node).
  - The `prev` pointer of the new node points to the current `rear` node.
  - If the `rear` pointer is not `NULL`, the current `rear` node's `next` pointer is updated to point to the new node.
  - The `rear` pointer is updated to the new node, making it the last node.
  - If the `front` pointer is still `NULL` (indicating the queue was empty), it is set to the new node, making it the first node.

- **Time Complexity**: 
  - **O(1)**: Inserting at the rear is a constant-time operation because we always have direct access to the `rear` pointer.

#### **`deleteNode()` Function (Dequeue):**
```c
void deleteNode() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    front = front->next;

    if (front != NULL) {
        front->prev = NULL;
    } else {
        rear = NULL;
    }

    free(temp);
}
```
- **Purpose**: Removes the front node from the queue.
- **Steps**:
  - If the queue is empty (`front == NULL`), print an error message.
  - If the queue is not empty, a temporary pointer `temp` is created to hold the `front` node.
  - The `front` pointer is updated to the next node in the queue.
  - If the new `front` node is not `NULL`, its `prev` pointer is set to `NULL`.
  - If the new `front` node is `NULL`, it means the queue is now empty, so the `rear` pointer is also set to `NULL`.
  - The memory occupied by the old front node (`temp`) is freed using `free`.

- **Time Complexity**: 
  - **O(1)**: Removing from the front of the queue is a constant-time operation because we always have direct access to the `front` pointer.

#### **`display()` Function:**
```c
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
```
- **Purpose**: Displays the elements of the queue from front to rear.
- **Steps**:
  - If the queue is empty (`front == NULL`), print an error message.
  - Otherwise, a temporary pointer `temp` is set to `front`, and we traverse the queue by following the `next` pointers.
  - Each node's `data` is printed as we traverse the list.
  - The loop terminates when `temp` reaches `NULL`, which signifies the end of the queue.
  
- **Time Complexity**: 
  - **O(n)**: In the worst case, we have to traverse all `n` nodes in the queue.

### **Main Function:**
```c
int main() {
    int choice, data;

    while (1) {
        printf("1. Add (enqueue)\n");
        printf("2. Delete (dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add: ");
                scanf("%d", &data);
                add(data);
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
```
- **Purpose**: This is the main loop that provides the user interface to interact with the queue.
- **Steps**:
  - The program presents a menu with the following options:
    - **1. Add (enqueue)**: Add data to the queue by calling the `add()` function.
    - **2. Delete (dequeue)**: Remove data from the queue by calling the `deleteNode()` function.
    - **3. Display**: Display the queue contents by calling the `display()` function.
    - **4. Exit**: Exit the program.
  - The user is prompted to enter a choice, and the program executes the corresponding action based on the choice.

- **Loop**: The program keeps running until the user chooses to exit (option `4`).

### **Time Complexity Analysis**:
- **`add` function**: O(1) — Inserting an element at the rear of the queue is a constant-time operation because we maintain a pointer to the rear node.
- **`deleteNode` function**: O(1) — Removing an element from the front of the queue is a constant-time operation because we maintain a pointer to the front node.
- **`display` function**: O(n) — In the worst case, we traverse the entire queue to print all elements, where `n` is the number of nodes in the queue.

### **Space Complexity**:
- **O(n)** — We allocate memory for each node dynamically using `malloc`, so the space complexity depends on the number of elements in the queue (`n`).

### **Example Input and Output**:

#### **Example Run 1**:
```
1. Add (enqueue)
2. Delete (dequeue)
3. Display
4. Exit
Enter your choice: 1
Enter data to add: 10

1. Add (enqueue)
2. Delete (dequeue)
3. Display
4. Exit
Enter your choice: 1
Enter data to add: 20

1. Add (enqueue)
2. Delete (dequeue)
3. Display
4. Exit
Enter your choice: 3
10 20

1. Add (enqueue)
2. Delete (dequeue)
3. Display
4. Exit
Enter your choice: 2
Queue is empty
```

### **Edge Cases**:
1. **Empty Queue**: If the queue is empty and a delete operation is attempted, the program will print `"Queue is empty"`.
2. **Display Empty Queue**: If the queue is empty and a display operation is performed, the program will print `"Queue is empty"`.
3. **Single Element in Queue**: If there is only one element in the queue, both the front and rear pointers will point to it. Deleting this element will make the queue empty.

This implementation efficiently manages a queue using a doubly linked list with constant-time enqueue and dequeue operations, making it suitable for real-time systems or applications requiring fast queue management.