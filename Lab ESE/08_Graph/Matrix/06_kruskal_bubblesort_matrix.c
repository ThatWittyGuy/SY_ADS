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

    bubbleSort(edges, edgeCount);

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
