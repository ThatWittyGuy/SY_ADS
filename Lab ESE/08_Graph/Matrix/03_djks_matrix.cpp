#include <iostream>
#include <climits>
using namespace std;

void dijkstra(int graph[][10], int V, int start, int end) {
    int dist[10];
    bool visited[10] = {false};

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    if (dist[end] == INT_MAX) {
        cout << "No path exists between " << start << " and " << end << endl;
    } else {
        cout << "Shortest distance from " << start << " to " << end << " is " << dist[end] << endl;
    }
}

int main() {
    int graph[10][10] = {0};
    int V, E, start, end;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter the edges (u v weight): " << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "Enter destination vertex: ";
    cin >> end;

    dijkstra(graph, V, start, end);

    return 0;
}
