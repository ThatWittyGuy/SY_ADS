<!-- explain full code in different blocks but each line shouild be explained and also give analyis of result and time complexity etc -->

### **Code Explanation and Analysis**

The program implements **Kruskal's Algorithm** to find the Minimum Spanning Tree (MST) of a graph. Kruskal's algorithm is a greedy algorithm that finds the MST by adding the smallest edges to the MST while avoiding cycles. It uses **Union-Find** (Disjoint-Set) data structure to keep track of connected components.

Let’s break the code into smaller blocks and explain each line.

---

### **1. Header Files and Constants**
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
```
- `#include <stdio.h>`: Includes the standard input/output library for functions like `printf()` and `scanf()`.
- `#include <stdlib.h>`: Includes functions for dynamic memory allocation and other utility functions like `qsort()`.
- `#define MAX_VERTICES 10`: Defines a constant `MAX_VERTICES` to set the maximum number of vertices in the graph. This can be adjusted as needed.

---

### **2. Edge Struct Definition**
```c
typedef struct
{
    int u, v, weight;
} Edge;
```
- **Purpose**: This structure represents an edge in the graph.
- `u`: The starting vertex of the edge.
- `v`: The ending vertex of the edge.
- `weight`: The weight or cost of the edge.
  
This structure will help us store edges of the graph in a list, which will later be sorted by weight in Kruskal's algorithm.

---

### **3. `find` Function (Union-Find)**
```c
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
```
- **Purpose**: Finds the representative (root) of the set containing the element `i`.
- **Explanation**:
  - `if (parent[i] == -1)`: If `parent[i] == -1`, then `i` is the root of its set, and we return `i`.
  - `return find(parent, parent[i])`: If `parent[i]` is not `-1`, it means `i` is not the root of its set, so we recursively call `find()` on the parent of `i`, following the chain of parents until the root is found.

The `find()` function is used to determine whether two vertices belong to the same connected component in the graph.

---

### **4. `unionSet` Function (Union-Find)**
```c
void unionSet(int parent[], int x, int y)
{
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}
```
- **Purpose**: Merges the two sets containing `x` and `y` into one set.
- **Explanation**:
  - `int xroot = find(parent, x)`: Finds the root of the set containing `x`.
  - `int yroot = find(parent, y)`: Finds the root of the set containing `y`.
  - `parent[xroot] = yroot`: Makes the root of `x` point to the root of `y`, effectively merging the sets.

This function is used to combine two connected components when adding an edge to the MST.

---

### **5. `compareEdges` Function**
```c
int compareEdges(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}
```
- **Purpose**: A comparison function used for sorting edges by their weights.
- **Explanation**:
  - `qsort()` requires a comparison function to sort an array. This function compares the weights of two edges.
  - `(Edge *)a` and `(Edge *)b` cast the pointers `a` and `b` to `Edge *` type, so we can access the `weight` field of each edge.
  - The function returns the difference between the weights of the two edges, allowing `qsort()` to sort the edges in ascending order of their weights.

---

### **6. `kruskalMST` Function**
```c
void kruskalMST(int graph[MAX_VERTICES][MAX_VERTICES], int V)
{
    Edge edges[V * (V - 1) / 2];
    int edgeCount = 0;
```
- **Purpose**: Implements Kruskal’s Algorithm to find the Minimum Spanning Tree (MST) of a graph.
- **Explanation**:
  - `Edge edges[V * (V - 1) / 2]`: This array will hold the edges of the graph. Since a complete graph has a maximum of `V * (V - 1) / 2` edges, we define the size of the array accordingly.
  - `int edgeCount = 0`: Keeps track of the number of edges added to the `edges[]` array.

---

```c
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
- **Purpose**: Converts the adjacency matrix to an edge list.
- **Explanation**:
  - The nested loops iterate over all pairs of vertices `(i, j)` where `i < j`.
  - `if (graph[i][j] != 0)`: If there is an edge between vertices `i` and `j` (i.e., the weight is not zero), we add the edge to the `edges[]` array.
  - `edges[edgeCount].u = i; edges[edgeCount].v = j; edges[edgeCount].weight = graph[i][j];`: Adds the edge to the `edges[]` array.
  - `edgeCount++`: Increments the counter for the edges.

---

```c
    qsort(edges, edgeCount, sizeof(Edge), compareEdges);
```
- **Purpose**: Sorts the edges in ascending order based on their weights.
- **Explanation**:
  - `qsort()` is called to sort the `edges[]` array using the `compareEdges` function defined earlier. This ensures that we process the smallest edges first when constructing the MST.

---

```c
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
    }
```
- **Purpose**: Initializes the Union-Find data structure.
- **Explanation**:
  - `parent[V]`: An array to track the parent of each vertex. Initially, all vertices are in their own sets, so `parent[i]` is set to `-1` for all `i`.

---

```c
    printf("Edges in the Minimum Spanning Tree (MST):\n");
    int mstWeight = 0;
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
```
- **Purpose**: Constructs the MST by adding edges to it, ensuring no cycles are formed.
- **Explanation**:
  - For each edge, the `find()` function checks if the vertices `u` and `v` belong to different sets (i.e., they are not already connected in the MST).
  - If they are in different sets (`setU != setV`), the edge is added to the MST:
    - `printf("%d - %d : %d\n", u, v, weight)`: Prints the edge and its weight.
    - `mstWeight += weight`: Adds the weight of the edge to the total weight of the MST.
    - `unionSet(parent, setU, setV)`: Merges the two sets containing `u` and `v`.

---

```c
    printf("Total weight of MST: %d\n", mstWeight);
}
```
- **Purpose**: Prints the total weight of the MST.
- **Explanation**:
  - After adding all the edges to the MST, we print the total weight of the MST.

---

### **7. `main` Function**
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
- **Purpose**: This is the entry point of the program.
- **Explanation**:
  - The user is prompted to enter the number of vertices and the adjacency matrix representing the graph.
  - The `kruskalMST()` function is called to compute

 and print the MST.

---

### **Time Complexity Analysis**
- Sorting the edges using `qsort()` takes **O(E log E)**, where `E` is the number of edges.
- The `find()` and `unionSet()` operations are **O(α(V))** (almost constant time due to the inverse Ackermann function), and these are performed for each edge.
- Overall time complexity: **O(E log E)**.

If the graph is dense, `E` can be up to **V^2**, so the time complexity can be approximated as **O(V^2 log V)** for dense graphs.

---

### **Space Complexity**
- We store the edges in an array, which requires **O(E)** space.
- The Union-Find structure requires **O(V)** space.
- Therefore, the space complexity is **O(E + V)**.

---

### **Conclusion**
This code successfully implements Kruskal's algorithm to find the MST of a graph. It efficiently handles the edge sorting and cycle detection using the Union-Find data structure. The complexity is manageable for small to moderately sized graphs.