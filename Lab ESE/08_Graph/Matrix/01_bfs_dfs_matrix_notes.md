### Code Breakdown and Explanation

This code implements both **Breadth-First Search (BFS)** and **Depth-First Search (DFS)** algorithms on an undirected graph represented as an adjacency matrix. We'll go through the code in blocks and explain each part, line by line.

---

#### **1. Header Files and Macros**
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
```
- `#include <stdio.h>`: Includes the standard input/output library, used for input/output operations like `printf()` and `scanf()`.
- `#include <stdlib.h>`: Includes the standard library for functions like memory allocation and process control.
- `#include <stdbool.h>`: Includes support for the boolean type (`true`/`false`).
- `#define MAX_VERTICES 100`: Defines a constant `MAX_VERTICES` with a value of 100. This will be the maximum number of vertices allowed in the graph.

---

#### **2. Queue Data Structure and Functions**
```c
typedef struct Queue
{
    int items[MAX_VERTICES];
    int front, rear;
} Queue;
```
- This defines a **Queue** structure to manage the queue operations.
  - `items[MAX_VERTICES]`: An array to hold the queue elements (the vertices of the graph).
  - `front`: Index of the front of the queue.
  - `rear`: Index of the rear of the queue.

---

```c
void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}
```
- Initializes the queue. Both `front` and `rear` are set to `-1`, indicating that the queue is empty.

---

```c
bool isEmpty(Queue *q)
{
    return q->front == -1;
}
```
- Checks if the queue is empty. If `front` is `-1`, the queue is empty and the function returns `true`; otherwise, it returns `false`.

---

```c
void enqueue(Queue *q, int value)
{
    if (q->rear == MAX_VERTICES - 1)
        printf("Queue is full\n");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}
```
- Adds an element (`value`) to the queue:
  - If the `rear` reaches `MAX_VERTICES - 1`, it prints "Queue is full" (overflow condition).
  - If the queue is initially empty (`front == -1`), it sets `front` to 0.
  - The `rear` is incremented, and the value is added at the `rear` of the queue.

---

```c
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
            q->front = q->rear = -1;
        return item;
    }
}
```
- Removes and returns the front element of the queue:
  - If the queue is empty, it prints "Queue is empty" and returns `-1`.
  - The front element is dequeued by incrementing the `front` pointer. If the queue becomes empty (i.e., `front > rear`), both `front` and `rear` are reset to `-1`.

---

#### **3. BFS (Breadth-First Search) Function**
```c
void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int start, int n)
{
    bool visited[MAX_VERTICES] = {false};
    Queue q;
    initQueue(&q);

    visited[start] = true;
    enqueue(&q, start);

    printf("BFS Traversal starting from node %d: ", start);
```
- `visited[MAX_VERTICES]`: A boolean array to keep track of visited nodes. Initially, all nodes are unvisited.
- `Queue q`: Declares a queue to manage the BFS process.
- `initQueue(&q)`: Initializes the queue.
- `visited[start] = true`: Marks the start node as visited.
- `enqueue(&q, start)`: Adds the start node to the queue for BFS traversal.
- Prints the starting node for BFS traversal.

---

```c
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        printf("%d ", node);

        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && !visited[i])
            {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}
```
- The `while` loop runs until the queue is empty.
- In each iteration:
  - The front node is dequeued (`dequeue(&q)`), printed, and explored.
  - The loop goes through all adjacent nodes of the current node (`for (int i = 0; i < n; i++)`).
  - If there is an edge (`graph[node][i] == 1`) and the node `i` hasn't been visited, it's marked as visited, and it's added to the queue for further exploration.
- After the traversal, it prints a newline.

---

#### **4. DFS (Depth-First Search) Utility Function**
```c
void dfsUtil(int graph[MAX_VERTICES][MAX_VERTICES], int node, bool visited[MAX_VERTICES], int n)
{
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            dfsUtil(graph, i, visited, n);
        }
    }
}
```
- This function performs a recursive DFS.
  - Marks the current node as visited (`visited[node] = true`).
  - Prints the current node.
  - Explores all adjacent nodes (`for (int i = 0; i < n; i++)`), and if a node is connected and unvisited, it recursively calls `dfsUtil()` on that node.

---

#### **5. DFS (Depth-First Search) Main Function**
```c
void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int start, int n)
{
    bool visited[MAX_VERTICES] = {false};
    printf("DFS Traversal starting from node %d: ", start);
    dfsUtil(graph, start, visited, n);
    printf("\n");
}
```
- Initializes a `visited` array to keep track of visited nodes.
- Prints the starting node for DFS traversal.
- Calls `dfsUtil()` to start the recursive DFS from the start node.

---

#### **6. Main Function**
```c
int main()
{
    int n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting node for BFS: ");
    scanf("%d", &start);
    bfs(graph, start, n);

    printf("Enter the starting node for DFS: ");
    scanf("%d", &start);
    dfs(graph, start, n);

    return 0;
}
```
- `int n, start`: Declares variables for the number of vertices (`n`) and the start node (`start`).
- Prompts the user to input the number of vertices and then the adjacency matrix (representing the graph).
- The graph is a 2D array where each element `graph[i][j] = 1` indicates an edge between vertex `i` and vertex `j`.
- Prompts for the start node for BFS and DFS, then calls `bfs()` and `dfs()` respectively to perform the searches.

---

### **Time Complexity Analysis**

1. **BFS Complexity**:
   - The BFS algorithm visits every node and edge exactly once.
   - **Time Complexity**: `O(V + E)`, where:
     - `V` is the number of vertices.
     - `E` is the number of edges.
   - Each node is enqueued and dequeued once, and each edge is checked once in the adjacency matrix.

2. **DFS Complexity**:
   - The DFS algorithm also visits every node and edge exactly once.
   - **Time Complexity**: `O(V + E)`.
   - The recursive calls process each node and its adjacent nodes.

3. **Space Complexity**:
   - Both algorithms use an additional array (`visited`) of size `O(V)` to keep track of visited nodes.
   - **Space Complexity**: `O(V)`.

### **Conclusion**
This program implements BFS and DFS for graph traversal using an adjacency matrix representation. Both algorithms explore all vertices and edges of the graph. The time complexity for both BFS and DFS is linear in terms of the number of vertices and edges, i.e., `O(V + E)`.

explain full code in different blocks but each line shouild be explained and also give analyis of result and time complexity etc