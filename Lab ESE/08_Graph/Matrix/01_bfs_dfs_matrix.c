#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Queue
{
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int value)
{
    if (q->rear == MAX_VERTICES - 1)
        printf("Queue is full\n");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
            q->front = q->rear = -1;
        return item;
    }
}

void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int start, int n)
{
    bool visited[MAX_VERTICES] = {false};
    Queue q;
    initQueue(&q);

    visited[start] = true;
    enqueue(&q, start);

    printf("BFS Traversal starting from node %d: ", start);

    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        printf("%d ", node);

        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && !visited[i])
            {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

void dfsUtil(int graph[MAX_VERTICES][MAX_VERTICES], int node, bool visited[MAX_VERTICES], int n)
{
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            dfsUtil(graph, i, visited, n);
        }
    }
}

void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int start, int n)
{
    bool visited[MAX_VERTICES] = {false};
    printf("DFS Traversal starting from node %d: ", start);
    dfsUtil(graph, start, visited, n);
    printf("\n");
}

int main()
{
    int n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting node for BFS: ");
    scanf("%d", &start);
    bfs(graph, start, n);

    printf("Enter the starting node for DFS: ");
    scanf("%d", &start);
    dfs(graph, start, n);

    return 0;
}

// Enter the number of vertices: 5
// Enter the number of edges: 4
// Enter edge (src dest): 0 1
// Enter edge (src dest): 0 2
// Enter edge (src dest): 1 3
// Enter edge (src dest): 1 4
// Enter the starting vertex for BFS and DFS: 0
// BFS starting from vertex 0: 0 1 2 3 4
// DFS starting from vertex 0: 0 1 3 4 2

// #include <iostream>

// using namespace std;

// void BFS(int graph[][10], int V, int start) {
//     bool visited[10] = {false};
//     int queue[10], front = 0, rear = 0;

//     visited[start] = true;
//     queue[rear++] = start;

//     while (front < rear) {
//         int node = queue[front++];
//         cout << node << " ";

//         for (int i = 0; i < V; i++) {
//             if (graph[node][i] == 1 && !visited[i]) {
//                 visited[i] = true;
//                 queue[rear++] = i;
//             }
//         }
//     }
//     cout << endl;
// }

// void DFSUtil(int graph[][10], int V, int node, bool visited[]) {
//     visited[node] = true;
//     cout << node << " ";

//     for (int i = 0; i < V; i++) {
//         if (graph[node][i] == 1 && !visited[i]) {
//             DFSUtil(graph, V, i, visited);
//         }
//     }
// }

// void DFS(int graph[][10], int V, int start) {
//     bool visited[10] = {false};
//     DFSUtil(graph, V, start, visited);
//     cout << endl;
// }

// int main() {
//     int graph[10][10] = {0}, V, E, choice, start;

//     cout << "Enter number of vertices: ";
//     cin >> V;

//     cout << "Enter number of edges: ";
//     cin >> E;

//     cout << "Enter the edges (u v) where u and v are the vertices: " << endl;
//     for (int i = 0; i < E; i++) {
//         int u, v;
//         cin >> u >> v;
//         graph[u][v] = 1;
//         graph[v][u] = 1;
//     }

//     do {
//         cout << "\nMenu:\n";
//         cout << "1. BFS Traversal\n";
//         cout << "2. DFS Traversal\n";
//         cout << "3. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter starting vertex for BFS: ";
//                 cin >> start;
//                 BFS(graph, V, start);
//                 break;
//             case 2:
//                 cout << "Enter starting vertex for DFS: ";
//                 cin >> start;
//                 DFS(graph, V, start);
//                 break;
//             case 3:
//                 cout << "Exiting...\n";
//                 break;
//             default:
//                 cout << "Invalid choice!\n";
//         }
//     } while (choice != 3);

//     return 0;
// }
