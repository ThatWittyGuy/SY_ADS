#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    struct Node *adjList[MAX_VERTICES];
    int numVertices;
};

struct Queue
{
    int items[MAX_VERTICES];
    int front, rear;
};

void initGraph(struct Graph *graph, int vertices)
{
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        graph->adjList[i] = NULL;
    }
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = NULL;

    if (graph->adjList[src] == NULL)
    {
        graph->adjList[src] = newNode;
    }
    else
    {
        struct Node *temp = graph->adjList[src];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = NULL;

    if (graph->adjList[dest] == NULL)
    {
        graph->adjList[dest] = newNode;
    }
    else
    {
        struct Node *temp = graph->adjList[dest];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void initQueue(struct Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

int isQueueEmpty(struct Queue *q)
{
    return q->rear < q->front;
}

void enqueue(struct Queue *q, int value)
{
    q->items[++q->rear] = value;
}

int dequeue(struct Queue *q)
{
    return q->items[q->front++];
}

void bfs(struct Graph *graph, int startVertex)
{
    int visited[MAX_VERTICES] = {0};
    struct Queue q;
    initQueue(&q);
    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isQueueEmpty(&q))
    {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        struct Node *temp = graph->adjList[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = 1;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

void dfsUtil(struct Graph *graph, int vertex, int visited[MAX_VERTICES])
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node *temp = graph->adjList[vertex];
    while (temp)
    {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex])
        {
            dfsUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void dfs(struct Graph *graph, int startVertex)
{
    int visited[MAX_VERTICES] = {0};
    dfsUtil(graph, startVertex, visited);
}

int main()
{
    struct Graph graph;
    int vertices, edges, src, dest, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    printf("Enter the starting vertex for BFS and DFS: ");
    scanf("%d", &startVertex);

    printf("BFS starting from vertex %d: ", startVertex);
    bfs(&graph, startVertex);
    printf("\n");

    printf("DFS starting from vertex %d: ", startVertex);
    dfs(&graph, startVertex);
    printf("\n");

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
