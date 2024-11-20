#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10

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

void printMST(int parent[], int V) {
    for (int i = 1; i < V; i++) {
        printf("%d - %d\n", parent[i], i);
    }
}

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


// Enter number of vertices: 5
// Enter number of edges: 7
// Enter the edges (src, dest, weight):
// 0 1 2
// 0 3 6
// 1 3 8
// 1 2 3
// 2 3 7
// 2 4 5
// 3 4 9

// 0 - 1: 2
// 1 - 2: 3
// 0 - 3: 6
// 2 - 4: 5


// #include <iostream>
// using namespace std;

// void primMST(int graph[][10], int V) {
//     int parent[10], key[10];
//     bool mstSet[10] = {false};

//     for (int i = 0; i < V; i++) {
//         key[i] = 9999;
//     }
//     key[0] = 0;
//     parent[0] = -1;

//     for (int count = 0; count < V - 1; count++) {
//         int u = -1;
//         for (int i = 0; i < V; i++) {
//             if (!mstSet[i] && (u == -1 || key[i] < key[u])) {
//                 u = i;
//             }
//         }
//         mstSet[u] = true;

//         for (int v = 0; v < V; v++) {
//             if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
//                 parent[v] = u;
//                 key[v] = graph[u][v];
//             }
//         }
//     }

//     for (int i = 1; i < V; i++) {
//         cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
//     }
// }

// int main() {
//     int graph[10][10], V, E;

//     cout << "Enter number of vertices: ";
//     cin >> V;

//     cout << "Enter number of edges: ";
//     cin >> E;

//     cout << "Enter the edges (u v weight): " << endl;
//     for (int i = 0; i < E; i++) {
//         int u, v, weight;
//         cin >> u >> v >> weight;
//         graph[u][v] = weight;
//         graph[v][u] = weight;
//     }

//     primMST(graph, V);

//     return 0;
// }
