### Explanation of Code in Different Blocks

#### **1. Header Files and Definitions:**
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
```
- **`#include <stdio.h>`**: Includes the standard input-output library, allowing us to use `printf`, `scanf`, and other input/output functions.
- **`#include <stdlib.h>`**: Includes the standard library for functions like `malloc`, `free`, and `qsort`. We’re using it for memory management and other utilities (though `qsort` is not used here, it’s important for any other dynamic memory functions you may use).
- **`#define MAX_VERTICES 10`**: Defines a constant that sets the maximum number of vertices in the graph to 10. This is useful for creating arrays with fixed sizes.

#### **2. Edge Structure:**
```c
typedef struct
{
    int u, v, weight;
} Edge;
```
- **`Edge` Structure**: Defines a structure to store an edge in the graph with the following properties:
  - `u`: The starting vertex of the edge.
  - `v`: The ending vertex of the edge.
  - `weight`: The weight or cost associated with the edge.

#### **3. Find Function (Disjoint Set):**
```c
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
```
- **`find` Function**: This is part of the **Disjoint Set Union (DSU)** or **Union-Find** data structure.
  - The `parent[]` array is used to track the parent of each vertex. If `parent[i] == -1`, then vertex `i` is a root of a set (meaning it’s its own parent).
  - Otherwise, the function recursively finds the root of the set to which vertex `i` belongs. This helps in checking if two vertices belong to the same set during the Union operation.

#### **4. Union Function (Disjoint Set):**
```c
void unionSet(int parent[], int x, int y)
{
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}
```
- **`unionSet` Function**: Merges the sets of two vertices, `x` and `y`. This function:
  - Uses `find` to find the roots of the sets containing `x` and `y`.
  - If they are not in the same set (i.e., `xroot != yroot`), it sets the root of `x` to point to the root of `y`, effectively merging the two sets into one.

#### **5. Bubble Sort Function:**
```c
void bubbleSort(Edge edges[], int edgeCount)
{
    for (int i = 0; i < edgeCount - 1; i++)
    {
        for (int j = 0; j < edgeCount - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}
```
- **`bubbleSort` Function**: Sorts the edges by their weights using **Bubble Sort**, a simple comparison-based sorting algorithm.
  - The algorithm repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
  - After each pass, the largest element "bubbles" up to the end of the list, and the process repeats for the unsorted portion of the list.

#### **6. Kruskal's Algorithm (Main Function for MST):**
```c
void kruskalMST(int graph[MAX_VERTICES][MAX_VERTICES], int V)
{
    Edge edges[V * (V - 1) / 2];
    int edgeCount = 0;

    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (graph[i][j] != 0)
            {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }
```
- **Convert Graph to Edge List**: Converts the adjacency matrix into a list of edges:
  - The matrix `graph[][]` represents the graph.
  - The nested loops iterate over the upper triangle of the matrix (i.e., `i < j`), because an undirected edge is represented twice in an adjacency matrix (once as `(i, j)` and once as `(j, i)`).
  - For each non-zero entry in the matrix, an edge is created and added to the `edges[]` array.

```c
    bubbleSort(edges, edgeCount);

    int parent[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
    }

    printf("Edges in the Minimum Spanning Tree (MST):\n");
    int mstWeight = 0;
```
- **Sorting Edges**: The `edges[]` array is sorted by the weight of the edges using the `bubbleSort` function.
- **Parent Array Initialization**: The `parent[]` array is initialized to `-1` for each vertex. This represents the disjoint sets where initially each vertex is its own set.
- **MST Weight Initialization**: The variable `mstWeight` is used to accumulate the total weight of the edges included in the Minimum Spanning Tree (MST).

```c
    for (int i = 0; i < edgeCount; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        int setU = find(parent, u);
        int setV = find(parent, v);

        if (setU != setV)
        {
            printf("%d - %d : %d\n", u, v, weight);
            mstWeight += weight;
            unionSet(parent, setU, setV);
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
}
```
- **Kruskal's Algorithm Core**:
  - **Iteration**: For each edge in the sorted list, the algorithm checks if the two vertices of the edge belong to different sets using the `find` function.
  - If the vertices belong to different sets (i.e., they are not connected yet), the edge is added to the MST, and the `unionSet` function merges the sets.
  - The weight of the added edge is added to the `mstWeight` variable.
  - The algorithm continues until all edges are processed or the MST is complete.

#### **7. Main Function:**
```c
int main()
{
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix (use 0 for no edge, non-zero for weight of edge):\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    kruskalMST(graph, V);

    return 0;
}
```
- **Input Handling**: The program starts by prompting the user to enter the number of vertices `V`. It then asks the user to input the adjacency matrix, representing the graph.
- **Call to `kruskalMST`**: After the adjacency matrix is entered, the function `kruskalMST` is called to compute and display the MST.
- **Program Exit**: After the MST is displayed, the program ends with a return value of 0.

### **Analysis of Time Complexity:**
1. **Edge Generation**: The first nested loop iterates over the upper triangle of the adjacency matrix. This results in a time complexity of **O(V²)** for edge creation.
2. **Bubble Sort**: Sorting the edges with Bubble Sort takes **O(E * V)** time (where `E` is the number of edges). The worst case is when all possible edges are present, so the complexity is **O(V²)** in the worst case.
3. **Find and Union**: For each edge, the `find` and `unionSet` operations are used. Since each of these operations is almost constant time, the overall time complexity for processing all edges is **O(E log V)** for union-find operations using path compression and union by rank (which is not implemented here, but would improve performance).
4. **Overall Complexity**: The total time complexity of the program is dominated by the Bubble Sort step, so it is **O(V²)** in the worst case, where `V` is the number of vertices and `E` is the number of edges. This can be inefficient for large graphs, as **Bubble Sort** is suboptimal for large datasets.

