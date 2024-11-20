This C code implements **Dijkstra's Algorithm** for finding the **shortest path** in a **weighted graph**. The graph is represented using an **adjacency list**, and the algorithm calculates the shortest path from a given source node to a destination node.

Let's break down the code in detail.

### Header Files

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
```
- **`#include <stdio.h>`**: Includes standard input/output functions such as `printf()` and `scanf()`.
- **`#include <stdlib.h>`**: Includes functions for memory allocation (`malloc()`), deallocation (`free()`), and other utilities like random number generation.
- **`#include <limits.h>`**: Includes constants like `INT_MAX`, which is used to represent infinity in the distance array.

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
    - **`weight`**: The weight of the edge.
    - **`next`**: Pointer to the next node in the adjacency list, enabling the linked list structure for storing edges.

2. **`struct AdjList`**:
    ```c
    struct AdjList
    {
        struct AdjListNode *head;
    };
    ```
    - **Purpose**: Represents an adjacency list for a vertex.
    - **`head`**: Pointer to the first node in the linked list of edges for a vertex.

3. **`struct Graph`**:
    ```c
    struct Graph
    {
        int V;
        struct AdjList *array;
    };
    ```
    - **Purpose**: Represents the graph itself.
    - **`V`**: The number of vertices in the graph.
    - **`array`**: An array of adjacency lists, each representing a vertex.

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
    - **Purpose**: Creates a new adjacency list node and initializes its `dest`, `weight`, and `next` pointer.
    - **Time Complexity**: O(1) since it's just allocating memory for a new node and setting its values.

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
    - **Purpose**: Creates a graph with `V` vertices. Each vertex has an empty adjacency list (head is `NULL` initially).
    - **Time Complexity**: O(V) because it initializes an array of size `V`.

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
    - **Purpose**: Adds an undirected edge between `src` and `dest` with a given `weight`. The graph is bidirectional, so the edge is added in both directions.
    - **Time Complexity**: O(1) for each edge added because we only modify the `head` of the linked list for the respective vertices.

4. **`minDistance()`**:
    ```c
    int minDistance(int dist[], int sptSet[], int V)
    {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++)
        {
            if (sptSet[v] == 0 && dist[v] <= min)
            {
                min = dist[v], min_index = v;
            }
        }
        return min_index;
    }
    ```
    - **Purpose**: Finds the vertex with the minimum distance value from the set of vertices not yet included in the shortest path tree (SPT).
    - **Parameters**:
        - `dist[]`: The array storing the shortest distances from the source vertex.
        - `sptSet[]`: A set that keeps track of vertices whose shortest distance from the source is already finalized.
    - **Time Complexity**: O(V) because we check all the vertices to find the one with the minimum distance.

5. **`dijkstra()`**:
    ```c
    void dijkstra(struct Graph *graph, int src, int dest)
    {
        int V = graph->V;
        int dist[V];
        int sptSet[V];
        for (int i = 0; i < V; i++)
        {
            dist[i] = INT_MAX;
            sptSet[i] = 0;
        }
        dist[src] = 0;
        for (int count = 0; count < V - 1; count++)
        {
            int u = minDistance(dist, sptSet, V);
            sptSet[u] = 1;
            struct AdjListNode *pCrawl = graph->array[u].head;
            while (pCrawl != NULL)
            {
                int v = pCrawl->dest;
                if (sptSet[v] == 0 && dist[u] != INT_MAX && dist[u] + pCrawl->weight < dist[v])
                {
                    dist[v] = dist[u] + pCrawl->weight;
                }
                pCrawl = pCrawl->next;
            }
        }
        if (dist[dest] != INT_MAX)
        {
            printf("Shortest distance from node %d to node %d is %d\n", src, dest, dist[dest]);
        }
        else
        {
            printf("No path exists from node %d to node %d\n", src, dest);
        }
    }
    ```
    - **Purpose**: Implements **Dijkstra's Algorithm** to find the shortest path from the source vertex `src` to the destination vertex `dest`.
    - **Steps**:
        1. **Initialize**: Set all distances to infinity (`INT_MAX`) and mark all vertices as not yet included in the shortest path tree (SPT).
        2. **Relaxation**: For each vertex `u`, update the distances to its adjacent vertices `v` if a shorter path is found.
        3. **Terminate**: After processing all vertices, print the shortest distance from `src` to `dest`, or indicate if no path exists.
    - **Time Complexity**:
        - **Finding the minimum distance** (`minDistance()`) takes O(V) time.
        - **Relaxing edges** takes O(E) because we process each edge once.
        - Overall time complexity is **O(V^2)** for a graph represented by an adjacency list using this implementation. Optimizations (like using a priority queue) can reduce this to **O(E + V log V)**.

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
    printf("Enter the source node: ");
    scanf("%d", &src);
    printf("Enter the destination node: ");
    scanf("%d", &dest);
    dijkstra(graph, src, dest);
    return 0;
}
```
- **Purpose**: The main function handles user input and graph creation, then calls Dijkstra’s algorithm to compute the shortest path between a source and destination node.
- It prompts the user for the number of vertices, edges, and the details of each edge, followed by the source and destination nodes.

### Example Input/Output

**Input**:
```
Enter number of vertices: 5
Enter number of edges: 7
Enter the edges (src, dest, weight):
0 1 10
0 2 5
1 2 2
1 3 1
2 3 9
2 4 3
3 4 4
Enter the source node: 0
Enter the destination node: 4
```

**Output**:
```
Shortest distance from node 0 to node 4 is 8
```

### Final Notes

- **Space Complexity**: O(V + E) due

 to the adjacency list and additional arrays for distances and the shortest path tree.
- **Time Complexity**: O(V^2) in this implementation due to the linear scan of all vertices for the minimum distance. Optimizations (such as using a priority queue) can improve this to **O(E + V log V)**, which is more efficient for large graphs.
