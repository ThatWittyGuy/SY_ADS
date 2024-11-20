This C code implements **Prim's Algorithm** for finding the **Minimum Spanning Tree (MST)** of a graph using an **adjacency list** representation. The graph is undirected, and each edge has a weight associated with it. The goal of Prim's algorithm is to find the subset of edges that connects all vertices in the graph while minimizing the total weight.

Let's break down the code and explain each part in detail.

### Header Files

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
```
- **`#include <stdio.h>`**: Includes standard input/output functions such as `printf()` and `scanf()`.
- **`#include <stdlib.h>`**: Includes functions for memory allocation (`malloc()`), deallocation (`free()`), and other utilities.
- **`#include <limits.h>`**: Provides the `INT_MAX` constant, which is used to represent infinity (a very large value).

### Structures

1. **`struct AdjListNode`**:
    ```c
    struct AdjListNode
    {
        int dest;
        int weight;
        struct AdjListNode *next;
    };
    ```
    - **Purpose**: Defines a node in the adjacency list.
    - **`dest`**: The destination vertex of the edge.
    - **`weight`**: The weight of the edge between the current node and the destination.
    - **`next`**: A pointer to the next node in the adjacency list, allowing multiple edges to be stored for a single vertex.

2. **`struct AdjList`**:
    ```c
    struct AdjList
    {
        struct AdjListNode *head;
    };
    ```
    - **Purpose**: Represents the adjacency list for a single vertex.
    - **`head`**: A pointer to the first node in the adjacency list for the vertex. It points to the list of all neighbors of the vertex.

3. **`struct Graph`**:
    ```c
    struct Graph
    {
        int V;
        struct AdjList *array;
    };
    ```
    - **Purpose**: Represents the entire graph.
    - **`V`**: The number of vertices in the graph.
    - **`array`**: An array of adjacency lists, each corresponding to a vertex in the graph. Each list stores the neighbors of the vertex and their corresponding edge weights.

### Functions

1. **`newAdjListNode()`**:
    ```c
    struct AdjListNode *newAdjListNode(int dest, int weight)
    {
        struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
        newNode->dest = dest;
        newNode->weight = weight;
        newNode->next = NULL;
        return newNode;
    }
    ```
    - **Purpose**: Creates a new adjacency list node with a given destination vertex and edge weight.
    - **Steps**: 
        - Dynamically allocates memory for the node.
        - Sets the destination vertex and edge weight.
        - Initializes the `next` pointer to `NULL` (since it is the last node in the list when created).
    - **Time Complexity**: O(1), as it only creates a single node.

2. **`createGraph()`**:
    ```c
    struct Graph *createGraph(int V)
    {
        struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
        graph->V = V;
        graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));
        for (int i = 0; i < V; i++)
        {
            graph->array[i].head = NULL;
        }
        return graph;
    }
    ```
    - **Purpose**: Creates a new graph with the specified number of vertices `V`.
    - **Steps**:
        - Dynamically allocates memory for the graph structure.
        - Initializes the adjacency lists for each vertex to `NULL`, indicating no edges initially.
    - **Time Complexity**: O(V), where `V` is the number of vertices, as we initialize each adjacency list.

3. **`addEdge()`**:
    ```c
    void addEdge(struct Graph *graph, int src, int dest, int weight)
    {
        struct AdjListNode *newNode = newAdjListNode(dest, weight);
        newNode->next = graph->array[src].head;
        graph->array[src].head = newNode;

        newNode = newAdjListNode(src, weight);
        newNode->next = graph->array[dest].head;
        graph->array[dest].head = newNode;
    }
    ```
    - **Purpose**: Adds an undirected edge between two vertices, `src` and `dest`, with a given `weight`.
    - **Steps**:
        - Create a new node for the edge from `src` to `dest` and insert it at the beginning of the adjacency list for `src`.
        - Similarly, create a new node for the edge from `dest` to `src` and insert it at the beginning of the adjacency list for `dest` (since the graph is undirected).
    - **Time Complexity**: O(1) for each edge, as adding a node to the adjacency list is done in constant time by inserting at the beginning of the list.

4. **`minKey()`**:
    ```c
    int minKey(int key[], int mstSet[], int V)
    {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++)
        {
            if (mstSet[v] == 0 && key[v] < min)
            {
                min = key[v], min_index = v;
            }
        }
        return min_index;
    }
    ```
    - **Purpose**: Finds the vertex with the smallest key value that has not yet been included in the Minimum Spanning Tree (MST).
    - **Parameters**:
        - `key[]`: Array storing the minimum edge weight for each vertex.
        - `mstSet[]`: Array indicating whether a vertex is already included in the MST.
        - `V`: The number of vertices in the graph.
    - **Steps**:
        - Iterate over all vertices and find the one with the smallest key value that is not yet included in the MST (`mstSet[v] == 0`).
    - **Time Complexity**: O(V), as it scans through all the vertices to find the minimum key.

5. **`primMST()`**:
    ```c
    void primMST(struct Graph *graph)
    {
        int V = graph->V;
        int parent[V];
        int key[V];
        int mstSet[V];

        for (int i = 0; i < V; i++)
        {
            key[i] = INT_MAX;
            mstSet[i] = 0;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; count++)
        {
            int u = minKey(key, mstSet, V);
            mstSet[u] = 1;

            struct AdjListNode *pCrawl = graph->array[u].head;
            while (pCrawl != NULL)
            {
                int v = pCrawl->dest;
                if (mstSet[v] == 0 && pCrawl->weight < key[v])
                {
                    key[v] = pCrawl->weight;
                    parent[v] = u;
                }
                pCrawl = pCrawl->next;
            }
        }

        for (int i = 1; i < V; i++)
        {
            printf("%d - %d: %d\n", parent[i], i, key[i]);
        }
    }
    ```
    - **Purpose**: Implements **Prim's Algorithm** to find the Minimum Spanning Tree (MST) of the graph.
    - **Steps**:
        - Initialize the `key[]` array to infinity (`INT_MAX`) for all vertices except the first, which is set to 0.
        - Initialize the `mstSet[]` array to track whether a vertex is included in the MST.
        - Set the `parent[]` array to store the parent of each vertex in the MST.
        - **Main loop**:
            - Select the vertex `u` with the minimum key value using `minKey()`.
            - Add `u` to the MST by setting `mstSet[u] = 1`.
            - Update the `key[]` values for all adjacent vertices of `u` if a smaller weight edge is found.
        - After constructing the MST, print the edges included in the MST, along with their weights.
    - **Time Complexity**: O(V^2) due to the use of a simple array-based method for finding the minimum key value. A priority queue could reduce this to O(E log V) for sparse graphs.

### Main Function

```c
int main()
{
    int V, E, src, dest, weight;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    struct Graph *graph = createGraph(V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter the edges (src, dest, weight):\n");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }
    primMST(graph);
    return 0;
}
```
- **Purpose**

: This is the entry point for the program.
    - Prompts the user to enter the number of vertices and edges.
    - Accepts the edge list and adds each edge to the graph using `addEdge()`.
    - Finally, calls `primMST()` to compute and print the MST.

### Example Input/Output

**Input:**
```
Enter number of vertices: 5
Enter number of edges: 7
Enter the edges (src, dest, weight):
0 1 2
0 3 6
1 3 8
1 2 3
2 3 7
2 4 5
3 4 9
```

**Output:**
```
0 - 1: 2
1 - 2: 3
0 - 3: 6
2 - 4: 5
```

### Time Complexity

- **Time Complexity**: 
    - **`minKey()`** takes O(V) time to find the minimum key in each iteration. The loop runs `V` times, so the overall complexity of Prim's algorithm is O(V^2).
    - **Space Complexity**: O(V + E) to store the graph and auxiliary arrays (`key[]`, `parent[]`, `mstSet[]`).

This implementation works well for dense graphs but can be optimized using a priority queue or a Fibonacci heap for sparse graphs.