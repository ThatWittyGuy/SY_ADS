This C code implements **Kruskal's Algorithm** to find the **Minimum Spanning Tree (MST)** of a connected, undirected graph. Let me break it down step by step:

### Header Files

```c
#include <stdio.h>
#include <stdlib.h>
```
- **`#include <stdio.h>`**: Includes standard input/output functions like `printf()` and `scanf()`.
- **`#include <stdlib.h>`**: Includes functions for memory allocation, such as `malloc()` and `free()`, and functions like `qsort()` for sorting.

### Structures

1. **`struct Edge`**:
    ```c
    struct Edge
    {
        int src, dest, weight;
    };
    ```
    - **Purpose**: Defines an edge in the graph.
    - **`src`**: Source vertex of the edge.
    - **`dest`**: Destination vertex of the edge.
    - **`weight`**: Weight (or cost) of the edge.

2. **`struct Graph`**:
    ```c
    struct Graph
    {
        int V, E;
        struct Edge *edges;
    };
    ```
    - **Purpose**: Defines the graph.
    - **`V`**: Number of vertices in the graph.
    - **`E`**: Number of edges in the graph.
    - **`edges`**: Array of edges (`struct Edge`) that represent the graph.

3. **`struct Subset`**:
    ```c
    struct Subset
    {
        int parent;
        int rank;
    };
    ```
    - **Purpose**: Used for **Union-Find** data structure.
    - **`parent`**: Points to the parent of the subset (used to find the root of a set).
    - **`rank`**: Used to keep the tree flat during union operations (helps in optimizing the union-find process).

### Helper Functions

1. **`find()`**: 
    ```c
    int find(struct Subset subsets[], int i)
    {
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }
    ```
    - **Purpose**: Finds the **root** of the set to which vertex `i` belongs using **path compression** (which flattens the tree for future operations).
    - **Time Complexity**: O(α(V)), where α is the inverse Ackermann function, which grows extremely slowly (almost constant time).

2. **`unionSets()`**: 
    ```c
    void unionSets(struct Subset subsets[], int x, int y)
    {
        int rootX = find(subsets, x);
        int rootY = find(subsets, y);

        if (subsets[rootX].rank < subsets[rootY].rank)
            subsets[rootX].parent = rootY;
        else if (subsets[rootX].rank > subsets[rootY].rank)
            subsets[rootY].parent = rootX;
        else
        {
            subsets[rootY].parent = rootX;
            subsets[rootX].rank++;
        }
    }
    ```
    - **Purpose**: Merges two sets containing vertices `x` and `y`. The union is done based on the **rank** (tree height) to keep the tree flat.
    - **Time Complexity**: O(α(V)), same as `find()`.

3. **`compareEdges()`**:
    ```c
    int compareEdges(const void *a, const void *b)
    {
        struct Edge *edgeA = (struct Edge *)a;
        struct Edge *edgeB = (struct Edge *)b;
        return edgeA->weight - edgeB->weight;
    }
    ```
    - **Purpose**: Comparator function for sorting edges by their weights. It's used with the **`qsort()`** function.
    - **Time Complexity**: O(E log E), where E is the number of edges (due to sorting).

### **Kruskal's Algorithm (`kruskal()` function)**

```c
void kruskal(struct Graph *graph)
{
    int V = graph->V;
    int E = graph->E;
    struct Edge result[V];
    int e = 0;
    int i = 0;
    qsort(graph->edges, E, sizeof(graph->edges[0]), compareEdges);

    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1)
    {
        struct Edge nextEdge = graph->edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y)
        {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    printf("Edges in the MST:\n");
    for (i = 0; i < e; i++)
        printf("%d - %d: %d\n", result[i].src, result[i].dest, result[i].weight);
}
```

- **Purpose**: Implements **Kruskal's Algorithm** to find the Minimum Spanning Tree (MST) of a graph.
- **Steps**:
  1. **Sort edges**: Sort all the edges in increasing order of their weights.
  2. **Union-Find Initialization**: Create a subset for each vertex, initializing each vertex as its own parent and rank 0.
  3. **Process edges**:
      - For each edge, check if it forms a cycle using the **union-find** (i.e., `find()` and `unionSets()` functions).
      - If it doesn't form a cycle (i.e., the two vertices are in different sets), add it to the MST.
  4. **Stop** when the MST contains `V-1` edges (for `V` vertices).

- **Time Complexity**:
  - Sorting the edges takes O(E log E).
  - Each find and union operation takes O(α(V)), where α is the inverse Ackermann function (almost constant time).
  - Overall, the time complexity is **O(E log E + E α(V))**. Since α(V) is very small, the complexity is approximately **O(E log E)**.

### `main()` Function

```c
int main()
{
    int V, E, src, dest, weight;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge *)malloc(E * sizeof(struct Edge));

    printf("Enter the edges (src, dest, weight):\n");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &src, &dest, &weight);
        graph->edges[i].src = src;
        graph->edges[i].dest = dest;
        graph->edges[i].weight = weight;
    }

    kruskal(graph);
    return 0;
}
```

- **Purpose**: This is the main driver function.
  - First, it reads the number of vertices (`V`) and edges (`E`) from the user.
  - Then, it allocates memory for the graph and its edges, and populates the edges by reading `src`, `dest`, and `weight`.
  - Finally, it calls `kruskal()` to compute the MST and print the result.

### Example Input/Output

**Input**:
```
Enter number of vertices: 4
Enter number of edges: 5
Enter the edges (src, dest, weight):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
```

**Output**:
```
Edges in the MST:
2 - 3: 4
0 - 3: 5
0 - 1: 10
```

### Explanation:
- The edges of the graph are sorted by weight: `[4, 5, 6, 10, 15]`.
- The MST is formed by selecting edges without forming cycles:
  - `2-3 (weight 4)`, `0-3 (weight 5)`, and `0-1 (weight 10)`.

### Final Notes:
- **Space Complexity**: O(V + E), due to storing the edges and subsets.
- Kruskal's algorithm is suitable for sparse graphs since the edge sorting step is the dominant factor in the time complexity.