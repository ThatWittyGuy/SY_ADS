#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct
{
    int u, v, weight;
} Edge;

int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y)
{
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}

int compareEdges(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

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

    qsort(edges, edgeCount, sizeof(Edge), compareEdges);

    int parent[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
    }

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

    printf("Total weight of MST: %d\n", mstWeight);
}

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

// Enter number of vertices: 4
// Enter number of edges: 5
// Enter the edges (src, dest, weight):
// 0 1 10
// 0 2 6
// 0 3 5
// 1 3 15
// 2 3 4

// Edges in the MST:
// 2 - 3: 4
// 0 - 3: 5
// 0 - 1: 10

// OLD but correct

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_VERTICES 10

// typedef struct {
//     int u, v, weight;
// } Edge;

// int compareEdges(const void* a, const void* b) {
//     return ((Edge*)a)->weight - ((Edge*)b)->weight;
// }

// int find(int parent[], int i) {
//     if (parent[i] == -1) {
//         return i;
//     }
//     return parent[i] = find(parent, parent[i]);
// }

// void unionSets(int parent[], int rank[], int x, int y) {
//     int rootX = find(parent, x);
//     int rootY = find(parent, y);

//     if (rank[rootX] > rank[rootY]) {
//         parent[rootY] = rootX;
//     } else if (rank[rootX] < rank[rootY]) {
//         parent[rootX] = rootY;
//     } else {
//         parent[rootY] = rootX;
//         rank[rootX]++;
//     }
// }

// void kruskal(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
//     Edge edges[MAX_VERTICES * (MAX_VERTICES - 1) / 2];
//     int edgeCount = 0;

//     for (int i = 0; i < numVertices; i++) {
//         for (int j = i + 1; j < numVertices; j++) {
//             if (graph[i][j] != 0) {
//                 edges[edgeCount].u = i;
//                 edges[edgeCount].v = j;
//                 edges[edgeCount].weight = graph[i][j];
//                 edgeCount++;
//             }
//         }
//     }

//     qsort(edges, edgeCount, sizeof(Edge), compareEdges);

//     int parent[numVertices], rank[numVertices];
//     for (int i = 0; i < numVertices; i++) {
//         parent[i] = -1;
//         rank[i] = 0;
//     }

//     printf("Edges in the Minimum Spanning Tree (MST):\n");
//     int mstWeight = 0;
//     for (int i = 0; i < edgeCount; i++) {
//         int u = edges[i].u;
//         int v = edges[i].v;
//         int weight = edges[i].weight;

//         int rootU = find(parent, u);
//         int rootV = find(parent, v);

//         if (rootU != rootV) {
//             printf("Edge (%d, %d) with weight %d\n", u, v, weight);
//             mstWeight += weight;
//             unionSets(parent, rank, rootU, rootV);
//         }
//     }

//     printf("Total weight of MST: %d\n", mstWeight);
// }

// int main() {
//     int graph[MAX_VERTICES][MAX_VERTICES];
//     int numVertices;

//     printf("Enter the number of vertices: ");
//     scanf("%d", &numVertices);

//     printf("Enter the adjacency matrix (use 0 for no edge, and the weight for edges):\n");
//     for (int i = 0; i < numVertices; i++) {
//         for (int j = 0; j < numVertices; j++) {
//             scanf("%d", &graph[i][j]);
//         }
//     }

//     kruskal(graph, numVertices);

//     return 0;
// }
