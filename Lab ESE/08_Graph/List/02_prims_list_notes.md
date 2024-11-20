This C code implements **Prim's Algorithm** for finding the **Minimum Spanning Tree (MST)** of a connected, undirected, weighted graph. The graph is represented using an **adjacency list** where each vertex is connected to its neighbors via weighted edges.

Let's break down the code and explain each part in detail.

### Header Files

```c
#include <stdio.h>
#include <stdlib.h>
```
- **`#include <stdio.h>`**: Includes standard input/output functions such as `printf()` and `scanf()`.
- **`#include <stdlib.h>`**: Includes functions for memory allocation (`malloc()`), deallocation (`free()`), and other utilities like random number generation.

### Macros

```c
#define INF 999999
#define MAX_VERTICES 100
```
- **`INF`**: A constant representing infinity (a large value) used to indicate that a vertex is initially unreachable or unvisited in the graph.
- **`MAX_VERTICES`**: A constant defining the maximum number of vertices the graph can have, set to 100 in this case.

### Structures

1. **`struct Node`**:
    ```c
    struct Node
    {
        int vertex, weight;
        struct Node *next;
    };
    ```
    - **Purpose**: Defines a node for the adjacency list.
    - **`vertex`**: The destination vertex for the edge.
    - **`weight`**: The weight of the edge.
    - **`next`**: A pointer to the next node in the adjacency list for this vertex. This allows the adjacency list to store multiple edges for each vertex.

2. **`struct Graph`**:
    ```c
    struct Graph
    {
        struct Node *adjList[MAX_VERTICES];
        int numVertices;
    };
    ```
    - **Purpose**: Represents the graph itself.
    - **`adjList[MAX_VERTICES]`**: An array of pointers to adjacency lists (one list per vertex). Each list contains all the neighboring vertices and the corresponding edge weights.
    - **`numVertices`**: The number of vertices in the graph.

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
    - **Purpose**: Initializes a graph with a specified number of vertices.
    - **Steps**:
        - Set the number of vertices.
        - Initialize each adjacency list to `NULL`, meaning there are no edges initially.
    - **Time Complexity**: O(V), where `V` is the number of vertices.

2. **`addEdge()`**:
    ```c
    void addEdge(struct Graph *graph, int src, int dest, int weight)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->vertex = dest;
        newNode->weight = weight;
        newNode->next = graph->adjList[src];
        graph->adjList[src] = newNode;

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->vertex = src;
        newNode->weight = weight;
        newNode->next = graph->adjList[dest];
        graph->adjList[dest] = newNode;
    }
    ```
    - **Purpose**: Adds an undirected edge between two vertices, `src` and `dest`, with a given `weight`.
    - **Steps**:
        - Create a new node for the edge from `src` to `dest` and add it to the adjacency list of `src`.
        - Similarly, create a new node for the edge from `dest` to `src` and add it to the adjacency list of `dest` (since the graph is undirected).
    - **Time Complexity**: O(1) for each edge added, since it only involves creating a new node and inserting it at the beginning of the list.

3. **`minKey()`**:
    ```c
    int minKey(int key[], int mstSet[], int vertices)
    {
        int min = INF, minIndex;
        for (int v = 0; v < vertices; v++)
        {
            if (mstSet[v] == 0 && key[v] < min)
            {
                min = key[v];
                minIndex = v;
            }
        }
        return minIndex;
    }
    ```
    - **Purpose**: Finds the vertex with the minimum key value that hasn't been included in the MST yet.
    - **Parameters**:
        - `key[]`: An array that stores the smallest weight edge connecting each vertex to the MST.
        - `mstSet[]`: An array that keeps track of which vertices have been added to the MST.
    - **Steps**:
        - Iterate over all vertices and find the one with the minimum key value that hasn’t been included in the MST (`mstSet[v] == 0`).
    - **Time Complexity**: O(V), where `V` is the number of vertices in the graph, because it scans through all vertices to find the minimum.

4. **`primMST()`**:
    ```c
    void primMST(struct Graph *graph)
    {
        int parent[MAX_VERTICES];
        int key[MAX_VERTICES];
        int mstSet[MAX_VERTICES];
        int vertices = graph->numVertices;

        for (int i = 0; i < vertices; i++)
        {
            key[i] = INF;
            mstSet[i] = 0;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < vertices - 1; count++)
        {
            int u = minKey(key, mstSet, vertices);
            mstSet[u] = 1;

            struct Node *temp = graph->adjList[u];
            while (temp)
            {
                int v = temp->vertex;
                if (mstSet[v] == 0 && temp->weight < key[v])
                {
                    parent[v] = u;
                    key[v] = temp->weight;
                }
                temp = temp->next;
            }
        }

        for (int i = 1; i < vertices; i++)
        {
            printf("%d - %d\n", parent[i], i);
        }
    }
    ```
    - **Purpose**: Implements **Prim’s Algorithm** to find the minimum spanning tree of the graph.
    - **Steps**:
        - Initialize:
            - `key[]`: Set to `INF` for all vertices except the first, which is set to 0.
            - `mstSet[]`: A set that tracks which vertices are included in the MST.
            - `parent[]`: Tracks the parent of each vertex in the MST.
        - **Main Loop**: For each vertex, find the vertex `u` with the minimum key value (using `minKey()`), add it to the MST, and update the key values of its neighbors if a shorter edge is found.
        - After the loop finishes, print the edges of the MST (using the `parent[]` array).
    - **Time Complexity**:
        - **`minKey()`** is called `V` times, and each call takes O(V) time.
        - The loop iterates through all vertices and edges. Thus, the total time complexity is **O(V^2)**. For a graph with sparse edges, this can be improved using a priority queue, reducing it to **O(E log V)**.

### Main Function

```c
int main()
{
    struct Graph graph;
    int vertices, edges, src, dest, weight;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (src dest weight): ");
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&graph, src, dest, weight);
    }

    primMST(&graph);

    return 0;
}
```
- **Purpose**: The main function handles user input, initializes the graph, adds edges, and calls `primMST()` to compute and display the Minimum Spanning Tree (MST).
- **Steps**:
    1. Input the number of vertices and edges.
    2. Input the details of each edge (source, destination, weight).
    3. Call `primMST()` to compute the MST and print the result.

### Example Input/Output

**Input**:
```
Enter the number of vertices: 5
Enter the number of edges: 7
Enter edge (src dest weight): 
0 1 2
0 3 6
1 3 8
1 2 3
2 3 7
2 4 5
3 4 9
```

**Output**:
```
0 - 1
1 - 2
0 - 3
2 - 4
```

This output indicates the edges included in the Minimum Spanning Tree (MST) of the graph:
- `0 - 1: weight 2`
- `1 - 2: weight 3`
- `0 - 3: weight 6`
- `2 - 4: weight 5`

### Time and Space Complexity

- **Time Complexity

**: O(V^2) (due to `minKey()` function), where `V` is the number of vertices in the graph. For graphs with fewer edges, using a priority queue can reduce this to O(E log V).
- **Space Complexity**: O(V + E) for storing the graph and the auxiliary arrays (`key[]`, `parent[]`, `mstSet[]`).