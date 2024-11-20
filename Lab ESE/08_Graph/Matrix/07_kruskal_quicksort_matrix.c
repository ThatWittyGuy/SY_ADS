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

// Function to partition the array for quick sort
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

// Quick Sort function to sort edges by their weights
void quickSort(Edge edges[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(edges, low, high);
        quickSort(edges, low, pi - 1);  // Sort the left part
        quickSort(edges, pi + 1, high); // Sort the right part
    }
}

void kruskalMST(int graph[MAX_VERTICES][MAX_VERTICES], int V)
{
    Edge edges[V * (V - 1) / 2];
    int edgeCount = 0;

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

    // Sort edges based on their weights using quick sort
    quickSort(edges, 0, edgeCount - 1);

    // Union-Find data structure to track connected components
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
    }

    printf("Edges in the Minimum Spanning Tree (MST):\n");
    int mstWeight = 0;

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


// SELECTION
// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_VERTICES 10

// typedef struct
// {
//     int u, v, weight;
// } Edge;

// int find(int parent[], int i)
// {
//     if (parent[i] == -1)
//         return i;
//     return find(parent, parent[i]);
// }

// void unionSet(int parent[], int x, int y)
// {
//     int xroot = find(parent, x);
//     int yroot = find(parent, y);
//     parent[xroot] = yroot;
// }

// // Selection Sort for sorting edges by their weights
// void selectionSort(Edge edges[], int edgeCount)
// {
//     for (int i = 0; i < edgeCount - 1; i++)
//     {
//         // Find the minimum edge in the unsorted part of the array
//         int minIndex = i;
//         for (int j = i + 1; j < edgeCount; j++)
//         {
//             if (edges[j].weight < edges[minIndex].weight)
//             {
//                 minIndex = j;
//             }
//         }
//         // Swap the found minimum element with the first element of the unsorted part
//         if (minIndex != i)
//         {
//             Edge temp = edges[i];
//             edges[i] = edges[minIndex];
//             edges[minIndex] = temp;
//         }
//     }
// }

// void kruskalMST(int graph[MAX_VERTICES][MAX_VERTICES], int V)
// {
//     Edge edges[V * (V - 1) / 2];
//     int edgeCount = 0;

//     // Convert the adjacency matrix to an edge list
//     for (int i = 0; i < V; i++)
//     {
//         for (int j = i + 1; j < V; j++)
//         {
//             if (graph[i][j] != 0)
//             {
//                 edges[edgeCount].u = i;
//                 edges[edgeCount].v = j;
//                 edges[edgeCount].weight = graph[i][j];
//                 edgeCount++;
//             }
//         }
//     }

//     // Sort edges based on their weights using selection sort
//     selectionSort(edges, edgeCount);

//     // Union-Find data structure to track connected components
//     int parent[V];
//     for (int i = 0; i < V; i++)
//     {
//         parent[i] = -1;
//     }

//     printf("Edges in the Minimum Spanning Tree (MST):\n");
//     int mstWeight = 0;

//     // Process edges and add them to the MST if they do not form a cycle
//     for (int i = 0; i < edgeCount; i++)
//     {
//         int u = edges[i].u;
//         int v = edges[i].v;
//         int weight = edges[i].weight;

//         int setU = find(parent, u);
//         int setV = find(parent, v);

//         // If u and v are not in the same set, add the edge to the MST
//         if (setU != setV)
//         {
//             printf("%d - %d : %d\n", u, v, weight);
//             mstWeight += weight;
//             unionSet(parent, setU, setV);
//         }
//     }

//     printf("Total weight of MST: %d\n", mstWeight);
// }

// int main()
// {
//     int V;

//     printf("Enter number of vertices: ");
//     scanf("%d", &V);

//     int graph[MAX_VERTICES][MAX_VERTICES];

//     printf("Enter the adjacency matrix (use 0 for no edge, non-zero for weight of edge):\n");
//     for (int i = 0; i < V; i++)
//     {
//         for (int j = 0; j < V; j++)
//         {
//             scanf("%d", &graph[i][j]);
//         }
//     }

//     kruskalMST(graph, V);

//     return 0;
// }

// // Enter number of vertices: 4
// // Enter number of edges: 5
// // Enter the edges (src, dest, weight):
// // 0 1 10
// // 0 2 6
// // 0 3 5
// // 1 3 15
// // 2 3 4

// // Edges in the MST:
// // 2 - 3: 4
// // 0 - 3: 5
// // 0 - 1: 10