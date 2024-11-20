#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10

int minDistance(int dist[], int sptSet[], int V)
{
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == 0 && dist[v] < min)
        {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

int dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int V, int src, int dest)
{
    int dist[V];
    int sptSet[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && sptSet[v] == 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return dist[dest];
}

int main()
{
    int V, src, dest;

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

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    printf("Enter the destination vertex: ");
    scanf("%d", &dest);

    int shortestDist = dijkstra(graph, V, src, dest);
    printf("Shortest distance from %d to %d is: %d\n", src, dest, shortestDist);

    return 0;
}

// Enter number of vertices: 5
// Enter number of edges: 7
// Enter the edges (src, dest, weight):
// 0 1 10
// 0 2 5
// 1 2 2
// 1 3 1
// 2 3 9
// 2 4 3
// 3 4 4
// Enter the source node: 0
// Enter the destination node: 4

// Shortest distance from node 0 to node 4 is 8


// Vertex to Source
// #include <stdio.h>
// #include <limits.h>

// #define MAX_VERTICES 10

// int minDistance(int dist[], int sptSet[], int V) {
//     int min = INT_MAX, minIndex;
//     for (int v = 0; v < V; v++) {
//         if (sptSet[v] == 0 && dist[v] < min) {
//             min = dist[v];
//             minIndex = v;
//         }
//     }
//     return minIndex;
// }

// void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int V, int src) {
//     int dist[V];
//     int sptSet[V];

//     for (int i = 0; i < V; i++) {
//         dist[i] = INT_MAX;
//         sptSet[i] = 0;
//     }

//     dist[src] = 0;

//     for (int count = 0; count < V - 1; count++) {
//         int u = minDistance(dist, sptSet, V);
//         sptSet[u] = 1;

//         for (int v = 0; v < V; v++) {
//             if (graph[u][v] && sptSet[v] == 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
//                 dist[v] = dist[u] + graph[u][v];
//             }
//         }
//     }

//     printf("Vertex \t Distance from Source\n");
//     for (int i = 0; i < V; i++) {
//         printf("%d \t %d\n", i, dist[i]);
//     }
// }

// int main() {
//     int V, src;

//     printf("Enter number of vertices: ");
//     scanf("%d", &V);

//     int graph[MAX_VERTICES][MAX_VERTICES];

//     printf("Enter the adjacency matrix (use 0 for no edge, non-zero for weight of edge):\n");
//     for (int i = 0; i < V; i++) {
//         for (int j = 0; j < V; j++) {
//             scanf("%d", &graph[i][j]);
//         }
//     }

//     printf("Enter the source vertex: ");
//     scanf("%d", &src);

//     dijkstra(graph, V, src);

//     return 0;
// }

// #include <iostream>
// #include <climits>
// using namespace std;

// void dijkstra(int graph[][10], int V, int start, int end) {
//     int dist[10];
//     bool visited[10] = {false};

//     for (int i = 0; i < V; i++) {
//         dist[i] = INT_MAX;
//     }
//     dist[start] = 0;

//     for (int count = 0; count < V - 1; count++) {
//         int u = -1;
//         for (int i = 0; i < V; i++) {
//             if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
//                 u = i;
//             }
//         }

//         visited[u] = true;

//         for (int v = 0; v < V; v++) {
//             if (graph[u][v] != 0 && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
//                 dist[v] = dist[u] + graph[u][v];
//             }
//         }
//     }

//     if (dist[end] == INT_MAX) {
//         cout << "No path exists between " << start << " and " << end << endl;
//     } else {
//         cout << "Shortest distance from " << start << " to " << end << " is " << dist[end] << endl;
//     }
// }

// int main() {
//     int graph[10][10] = {0};
//     int V, E, start, end;

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

//     cout << "Enter starting vertex: ";
//     cin >> start;

//     cout << "Enter destination vertex: ";
//     cin >> end;

//     dijkstra(graph, V, start, end);

//     return 0;
// }
