#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 10

int minKey(int key[], int mstSet[], int numVertices) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numVertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int parent[numVertices];
    int key[numVertices];
    int mstSet[numVertices];

    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minKey(key, mstSet, numVertices);
        mstSet[u] = 1;

        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] != 0 && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edges in the Minimum Spanning Tree (MST):\n");
    int totalWeight = 0;
    for (int i = 1; i < numVertices; i++) {
        printf("Edge (%d, %d) with weight %d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }

    printf("Total weight of MST: %d\n", totalWeight);
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the adjacency matrix (use 0 for no edge, and the weight for edges):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    primMST(graph, numVertices);
    return 0;
}
