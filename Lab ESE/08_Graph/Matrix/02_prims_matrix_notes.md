### Code Explanation and Analysis

This code implements **Prim's Algorithm** to find the Minimum Spanning Tree (MST) of a graph. It takes an adjacency matrix as input, which represents the graph with weighted edges. The key steps in Prim's Algorithm are to start from a chosen vertex, grow the MST by adding the minimum weight edge that connects a vertex in the MST to a vertex outside it, and repeat until all vertices are included.

---

### **1. Header Files and Constants**
```c
#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10
```
- `#include <stdio.h>`: Includes the standard input/output library for using functions like `printf()` and `scanf()`.
- `#include <limits.h>`: Includes definitions for limits of integral types, used here for setting the initial key values to `INT_MAX` (infinity).
- `#define MAX_VERTICES 10`: Defines a constant that specifies the maximum number of vertices the graph can have (here, it's set to 10).

---

### **2. `minKey` Function**
```c
int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}
```
- **Purpose**: This function finds the vertex with the minimum key value that hasn't been included in the MST yet (i.e., the vertex that is closest to the MST).
- **Parameters**:
  - `key[]`: Array storing the minimum weight edge that connects each vertex to the MST.
  - `mstSet[]`: Boolean array where `mstSet[v] = 1` if vertex `v` is included in the MST, otherwise `0`.
  - `V`: Number of vertices in the graph.
  
- **Explanation**:
  - `min = INT_MAX`: Initializes the `min` variable to infinity, representing the largest possible weight.
  - A loop iterates over all vertices `v` to find the one with the smallest `key[v]` that is not yet included in the MST (`mstSet[v] == 0`).
  - If a vertex `v` satisfies this condition, it updates `min` to the new smaller value and `minIndex` to the index of this vertex.
  - Finally, the function returns the `minIndex` (the vertex with the smallest key).

---

### **3. `printMST` Function**
```c
void printMST(int parent[], int V) {
    for (int i = 1; i < V; i++) {
        printf("%d - %d\n", parent[i], i);
    }
}
```
- **Purpose**: This function prints the edges of the Minimum Spanning Tree (MST).
- **Parameters**:
  - `parent[]`: Array where `parent[i]` stores the vertex that is connected to vertex `i` in the MST.
  - `V`: Number of vertices in the graph.
  
- **Explanation**:
  - The function prints all edges in the MST. It starts from vertex 1 because vertex 0 is the starting point and has no parent.
  - For each vertex `i`, it prints the edge between `parent[i]` and `i`.

---

### **4. `primMST` Function**
```c
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;
```
- **Purpose**: This is the main function implementing Prim's Algorithm to find the MST of the graph.
- **Parameters**:
  - `graph[MAX_VERTICES][MAX_VERTICES]`: 2D array representing the graph’s adjacency matrix, where `graph[i][j]` stores the weight of the edge between vertex `i` and vertex `j`.
  - `V`: Number of vertices in the graph.

- **Explanation**:
  - `parent[]`: Array to store the parent vertex of each vertex in the MST.
  - `key[]`: Array to store the minimum weight edge that connects a vertex to the MST.
  - `mstSet[]`: Boolean array to check if a vertex is included in the MST or not.
  - The `for` loop initializes the arrays:
    - `key[i] = INT_MAX`: Initially, all vertices have an infinite key value, except for vertex 0 (the starting vertex).
    - `mstSet[i] = 0`: All vertices are initially not included in the MST.
  - `key[0] = 0`: Set the key of the starting vertex to 0.
  - `parent[0] = -1`: The starting vertex has no parent.

---

```c
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, V);
}
```
- **Explanation**:
  - The outer `for` loop runs `V-1` times, each time adding a vertex to the MST. It ensures all `V` vertices are eventually included in the MST.
  - **Step 1**: Find the vertex `u` with the minimum `key[u]` value that has not yet been included in the MST (using the `minKey()` function).
  - **Step 2**: Mark vertex `u` as included in the MST by setting `mstSet[u] = 1`.
  - **Step 3**: Update the `key[]` and `parent[]` arrays for all adjacent vertices `v` of `u`:
    - If `graph[u][v]` is non-zero (i.e., there is an edge between `u` and `v`), and `v` is not yet in the MST (`mstSet[v] == 0`), and the weight of the edge `graph[u][v]` is less than the current `key[v]`, then update:
      - `parent[v] = u`: Set `u` as the parent of `v` in the MST.
      - `key[v] = graph[u][v]`: Update the key value of `v` to the weight of the edge connecting `u` to `v`.
  - **Final Step**: After all vertices have been processed, call `printMST()` to print the edges of the MST.

---

### **5. `main` Function**
```c
int main() {
    int V;
    
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix (use 0 for no edge, non-zero for weight of edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Edges in the Minimum Spanning Tree (MST):\n");
    primMST(graph, V);

    return 0;
}
```
- **Purpose**: This is the entry point of the program.
- **Explanation**:
  - `int V`: Declares the variable to store the number of vertices.
  - The user is prompted to enter the number of vertices and the adjacency matrix.
    - The adjacency matrix is entered where `graph[i][j]` is the weight of the edge between vertex `i` and vertex `j`, or `0` if no edge exists.
  - After the adjacency matrix is entered, `primMST(graph, V)` is called to compute and print the MST.

---

### **Time Complexity Analysis**

1. **Finding the Minimum Key (minKey)**:
   - The `minKey` function scans through all vertices to find the one with the minimum key. This takes `O(V)` time.
  
2. **Prim's Algorithm**:
   - For each of the `V` vertices, the algorithm finds the minimum key and updates the key and parent arrays for all adjacent vertices. 
   - In the worst case, for each vertex, we examine all `V` vertices, so the inner loop takes `O(V)` time.
   - Thus, the overall time complexity is `O(V^2)`.

3. **Space Complexity**:
   - The space complexity is determined by the size of the arrays: `parent[]`, `key[]`, and `mstSet[]`, each of size `V`.
   - Therefore, the space complexity is `O(V)`.

---

### **Conclusion**
This code implements **Prim's Algorithm** to find the Minimum Spanning Tree (MST) of a weighted undirected graph. The time complexity of the algorithm is `O(V^2)`, where `V` is the number of vertices in the graph, due to the repeated scanning of all vertices

 to find the minimum key value. The space complexity is `O(V)` due to the storage required for the key, parent, and MST set arrays. The program takes an adjacency matrix as input and prints the edges of the MST.