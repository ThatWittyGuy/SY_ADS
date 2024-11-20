This code implements **Kruskal's Algorithm** to find the Minimum Spanning Tree (MST) of a graph. The graph is represented by an adjacency matrix, and the code uses a **Quick Sort** algorithm to sort the edges by weight before applying Kruskal's algorithm. Let's break the code into blocks and explain each part in detail, including time complexity analysis.

### **1. Structure Definition:**
```c
typedef struct
{
    int u, v, weight;
} Edge;
```
- This defines a structure `Edge` to store an edge in the graph. Each edge consists of:
  - `u`: The starting vertex of the edge.
  - `v`: The ending vertex of the edge.
  - `weight`: The weight of the edge.

### **2. Find Function (Union-Find Data Structure):**
```c
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
```
- This function performs the **find** operation in the Union-Find (Disjoint Set Union, DSU) data structure, which is used to keep track of connected components.
- If the parent of the node `i` is `-1`, it indicates that `i` is the root of its set, so it returns `i`.
- Otherwise, it recursively finds the root of the set by following the parent pointers. This helps identify whether two vertices are in the same set.

### **3. Union Function (Union-Find Data Structure):**
```c
void unionSet(int parent[], int x, int y)
{
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}
```
- The **union** operation merges the sets containing vertices `x` and `y`. 
- It first finds the root of both `x` and `y`. If they belong to different sets, it makes `yroot` the parent of `xroot`, effectively joining the two sets.

### **4. Quick Sort Partition Function:**
```c
int partition(Edge edges[], int low, int high)
{
    int pivot = edges[high].weight;
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (edges[j].weight < pivot)
        {
            i++;
            Edge temp = edges[i];
            edges[i] = edges[j];
            edges[j] = temp;
        }
    }
    Edge temp = edges[i + 1];
    edges[i + 1] = edges[high];
    edges[high] = temp;
    return i + 1;
}
```
- This function partitions the `edges[]` array into two parts, one with edges of weights smaller than the pivot (last element) and the other with edges of weights greater than the pivot.
- The pivot is chosen to be the weight of the last edge, and it is placed in its correct position. The function returns the index of the pivot in the sorted array.

### **5. Quick Sort Function:**
```c
void quickSort(Edge edges[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(edges, low, high);
        quickSort(edges, low, pi - 1);  // Sort the left part
        quickSort(edges, pi + 1, high); // Sort the right part
    }
}
```
- The **quickSort** function sorts the `edges[]` array in place using the **partition** function.
- It recursively sorts the two halves of the array created by the pivot, ensuring the entire array is sorted by edge weights.

### **6. Kruskal's Algorithm for MST:**
```c
void kruskalMST(int graph[MAX_VERTICES][MAX_VERTICES], int V)
{
    Edge edges[V * (V - 1) / 2];
    int edgeCount = 0;
```
- **Edge list creation**: 
  - The graph is represented by an adjacency matrix `graph[MAX_VERTICES][MAX_VERTICES]`.
  - We first create an edge list `edges[]` to store the graph's edges. The number of edges is at most `V * (V - 1) / 2` in an undirected graph.

```c
    // Convert the adjacency matrix to an edge list
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
- This loop converts the adjacency matrix into an edge list. For each pair of vertices `i` and `j`, if there is an edge (`graph[i][j] != 0`), we store the edge information (`i`, `j`, and the weight) into the `edges[]` array.

```c
    // Sort edges based on their weights using quick sort
    quickSort(edges, 0, edgeCount - 1);
```
- The `edges[]` array is sorted by edge weight using the `quickSort` function.

```c
    // Union-Find data structure to track connected components
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
    }
```
- The **Union-Find** structure (`parent[]`) is initialized to `-1` for each vertex. Each vertex starts as its own component.

```c
    printf("Edges in the Minimum Spanning Tree (MST):\n");
    int mstWeight = 0;
```
- We print the edges that will be included in the MST and initialize the total weight of the MST to `0`.

```c
    // Process edges and add them to the MST if they do not form a cycle
    for (int i = 0; i < edgeCount; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        int setU = find(parent, u);
        int setV = find(parent, v);

        // If u and v are not in the same set, add the edge to the MST
        if (setU != setV)
        {
            printf("%d - %d : %d\n", u, v, weight);
            mstWeight += weight;
            unionSet(parent, setU, setV);
        }
    }
```
- This loop processes the sorted edges and adds each edge to the MST if it does not form a cycle. This is checked using the **find** function.
  - If the vertices `u` and `v` are not in the same set (i.e., they are not connected), the edge is added to the MST, and the **union** operation is performed to connect the two sets.

```c
    printf("Total weight of MST: %d\n", mstWeight);
}
```
- Finally, the total weight of the MST is printed.

### **7. Main Function:**
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
- The main function prompts the user to enter the number of vertices and the adjacency matrix for the graph.
- It then calls the `kruskalMST` function to compute and display the MST.

### **Time Complexity Analysis:**

1. **Edge List Creation**:
   - The nested loops to create the edge list iterate over `V * V`, resulting in **O(V²)** time complexity.

2. **Quick Sort**:
   - Sorting the edges takes **O(E log E)**, where `E` is the number of edges. In the worst case, **E** is at most **V²** in a dense graph, so the sorting time complexity becomes **O(V² log V)**.

3. **Union-Find Operations**:
   - Each **find** and **union** operation takes **O(α(V))**, where **α** is the inverse Ackermann function, which grows very slowly. For practical purposes, this is considered nearly constant time.
   - There are **E** edges to process, so the total time for union-find operations is **O(E α(V))**.

4. **Overall Time Complexity**:
   - The overall time complexity is dominated by the edge sorting step, making it **O(E log E)**, which is equivalent to **O(V² log V)** for dense graphs.

### **Conclusion:**
- The algorithm efficiently finds the Minimum Spanning Tree using **Quick Sort** to sort edges and **Union-Find** to manage connected components.
- **Time Complexity**: **O(E log E)**, with **E** being the number of edges.
- **Space Complexity**: **O(V + E)**, as we store both the graph and the union-find parent array

.