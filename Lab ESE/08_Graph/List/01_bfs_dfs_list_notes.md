This C program implements **Breadth-First Search (BFS)** and **Depth-First Search (DFS)** algorithms on an undirected graph using an **adjacency list** representation. Let's break down the code and explain how it works, step by step.

### Header Files

```c
#include <stdio.h>
#include <stdlib.h>
```
- **`#include <stdio.h>`**: Standard input/output functions like `printf()` and `scanf()`.
- **`#include <stdlib.h>`**: Includes functions for memory allocation (`malloc()`), deallocation (`free()`), and other utilities like `exit()`.

### Data Structures

1. **`struct Node`**:
    ```c
    struct Node
    {
        int vertex;
        struct Node *next;
    };
    ```
    - **Purpose**: This structure represents a node in the adjacency list for a graph.
    - **`vertex`**: The destination vertex of the edge.
    - **`next`**: A pointer to the next node in the list (to handle multiple edges for the same vertex).

2. **`struct Graph`**:
    ```c
    struct Graph
    {
        struct Node *adjList[MAX_VERTICES];
        int numVertices;
    };
    ```
    - **Purpose**: This structure represents a graph with an adjacency list.
    - **`adjList[]`**: An array of pointers to `struct Node`, each representing the head of a linked list for each vertex.
    - **`numVertices`**: The number of vertices in the graph.

3. **`struct Queue`**:
    ```c
    struct Queue
    {
        int items[MAX_VERTICES];
        int front, rear;
    };
    ```
    - **Purpose**: A simple queue structure to support BFS.
    - **`items[]`**: An array to hold the elements (vertices) of the queue.
    - **`front`** and **`rear`**: Indices to track the front and rear of the queue.

### Functions

1. **`initGraph()`**:
    ```c
    void initGraph(struct Graph *graph, int vertices)
    {
        graph->numVertices = vertices;
        for (int i = 0; i < vertices; i++)
        {
            graph->adjList[i] = NULL;
        }
    }
    ```
    - **Purpose**: Initializes a graph by setting the number of vertices and initializing the adjacency lists of each vertex to `NULL`.

2. **`addEdge()`**:
    ```c
    void addEdge(struct Graph *graph, int src, int dest)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->vertex = dest;
        newNode->next = NULL;

        if (graph->adjList[src] == NULL)
        {
            graph->adjList[src] = newNode;
        }
        else
        {
            struct Node *temp = graph->adjList[src];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->vertex = src;
        newNode->next = NULL;

        if (graph->adjList[dest] == NULL)
        {
            graph->adjList[dest] = newNode;
        }
        else
        {
            struct Node *temp = graph->adjList[dest];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    ```
    - **Purpose**: Adds an undirected edge between two vertices (`src` and `dest`).
    - **Steps**:
        - Create a new node for `dest` and add it to the adjacency list of `src`.
        - Create a new node for `src` and add it to the adjacency list of `dest` (since the graph is undirected).

3. **`initQueue()`**:
    ```c
    void initQueue(struct Queue *q)
    {
        q->front = 0;
        q->rear = -1;
    }
    ```
    - **Purpose**: Initializes an empty queue. The `front` is set to 0, and `rear` is set to -1 (since the queue is empty initially).

4. **`isQueueEmpty()`**:
    ```c
    int isQueueEmpty(struct Queue *q)
    {
        return q->rear < q->front;
    }
    ```
    - **Purpose**: Checks if the queue is empty. If the `rear` index is less than the `front`, it means the queue is empty.

5. **`enqueue()`**:
    ```c
    void enqueue(struct Queue *q, int value)
    {
        q->items[++q->rear] = value;
    }
    ```
    - **Purpose**: Adds an element to the queue. It increments the `rear` index and adds the `value` to the `items[]` array.

6. **`dequeue()`**:
    ```c
    int dequeue(struct Queue *q)
    {
        return q->items[q->front++];
    }
    ```
    - **Purpose**: Removes and returns the front element of the queue. It increments the `front` index to reflect the dequeue operation.

7. **`bfs()`** (Breadth-First Search):
    ```c
    void bfs(struct Graph *graph, int startVertex)
    {
        int visited[MAX_VERTICES] = {0};
        struct Queue q;
        initQueue(&q);
        visited[startVertex] = 1;
        enqueue(&q, startVertex);

        while (!isQueueEmpty(&q))
        {
            int currentVertex = dequeue(&q);
            printf("%d ", currentVertex);

            struct Node *temp = graph->adjList[currentVertex];
            while (temp)
            {
                int adjVertex = temp->vertex;
                if (!visited[adjVertex])
                {
                    visited[adjVertex] = 1;
                    enqueue(&q, adjVertex);
                }
                temp = temp->next;
            }
        }
    }
    ```
    - **Purpose**: Performs a **Breadth-First Search (BFS)** starting from the `startVertex`.
    - **Steps**:
        - Initialize a `visited[]` array to track visited vertices.
        - Use a queue to store the vertices to visit next.
        - Start BFS by marking the `startVertex` as visited and enqueue it.
        - In the BFS loop, dequeue a vertex, print it, and enqueue all unvisited adjacent vertices.
        - Repeat until the queue is empty.

8. **`dfsUtil()`** (Depth-First Search Helper):
    ```c
    void dfsUtil(struct Graph *graph, int vertex, int visited[MAX_VERTICES])
    {
        visited[vertex] = 1;
        printf("%d ", vertex);

        struct Node *temp = graph->adjList[vertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex])
            {
                dfsUtil(graph, adjVertex, visited);
            }
            temp = temp->next;
        }
    }
    ```
    - **Purpose**: A recursive utility function for **Depth-First Search (DFS)**.
    - **Steps**:
        - Mark the current `vertex` as visited and print it.
        - Recursively visit all unvisited adjacent vertices.

9. **`dfs()`** (Depth-First Search):
    ```c
    void dfs(struct Graph *graph, int startVertex)
    {
        int visited[MAX_VERTICES] = {0};
        dfsUtil(graph, startVertex, visited);
    }
    ```
    - **Purpose**: Initializes the DFS algorithm by calling `dfsUtil()` with the `startVertex`.

### Main Function

```c
int main()
{
    struct Graph graph;
    int vertices, edges, src, dest, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    printf("Enter the starting vertex for BFS and DFS: ");
    scanf("%d", &startVertex);

    printf("BFS starting from vertex %d: ", startVertex);
    bfs(&graph, startVertex);
    printf("\n");

    printf("DFS starting from vertex %d: ", startVertex);
    dfs(&graph, startVertex);
    printf("\n");

    return 0;
}
```

- **Purpose**: The main function takes input from the user for the number of vertices and edges in the graph. It initializes the graph, adds the edges, and performs both BFS and DFS starting from a given vertex.
- **Steps**:
    - Prompts the user to input the number of vertices and edges.
    - Takes the edge inputs and calls `addEdge()` to add them to the graph.
    - Takes the starting vertex for BFS and DFS and calls the respective functions to perform the searches.

### Example Input and Output

**Input:**
```
Enter the number of vertices: 5
Enter the number of edges: 4
Enter edge (src dest): 0 1
Enter edge (src dest): 0 2
Enter edge (src dest): 1

 3
Enter edge (src dest): 1 4
Enter the starting vertex for BFS and DFS: 0
```

**Output:**
```
BFS starting from vertex 0: 0 1 2 3 4
DFS starting from vertex 0: 0 1 3 4 2
```

### Time Complexity

- **BFS Time Complexity**: O(V + E)
    - Every vertex and every edge is visited once.
  
- **DFS Time Complexity**: O(V + E)
    - Every vertex and every edge is visited once (due to recursive calls).

### Space Complexity

- **Space Complexity**: O(V + E)
    - The graph requires O(V + E) space for the adjacency list, and both BFS and DFS require O(V) space for the visited array and queue (for BFS).