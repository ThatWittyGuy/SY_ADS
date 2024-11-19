#include <iostream>

using namespace std;

void BFS(int graph[][10], int V, int start) {
    bool visited[10] = {false};
    int queue[10], front = 0, rear = 0;
    
    visited[start] = true;
    queue[rear++] = start;
    
    while (front < rear) {
        int node = queue[front++];
        cout << node << " ";
        
        for (int i = 0; i < V; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    cout << endl;
}

void DFSUtil(int graph[][10], int V, int node, bool visited[]) {
    visited[node] = true;
    cout << node << " ";
    
    for (int i = 0; i < V; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFSUtil(graph, V, i, visited);
        }
    }
}

void DFS(int graph[][10], int V, int start) {
    bool visited[10] = {false};
    DFSUtil(graph, V, start, visited);
    cout << endl;
}

int main() {
    int graph[10][10] = {0}, V, E, choice, start;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter the edges (u v) where u and v are the vertices: " << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. BFS Traversal\n";
        cout << "2. DFS Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter starting vertex for BFS: ";
                cin >> start;
                BFS(graph, V, start);
                break;
            case 2:
                cout << "Enter starting vertex for DFS: ";
                cin >> start;
                DFS(graph, V, start);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
