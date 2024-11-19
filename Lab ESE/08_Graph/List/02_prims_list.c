#include <stdio.h>
#include <stdlib.h>

#define INF 999999
#define MAX_VERTICES 100

struct Node
{
    int vertex, weight;
    struct Node *next;
};

struct Graph
{
    struct Node *adjList[MAX_VERTICES];
    int numVertices;
};

void initGraph(struct Graph *graph, int vertices)
{
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        graph->adjList[i] = NULL;
    }
}

void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->weight = weight;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

int minKey(int key[], int mstSet[], int vertices)
{
    int min = INF, minIndex;
    for (int v = 0; v < vertices; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(struct Graph *graph)
{
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mstSet[MAX_VERTICES];
    int vertices = graph->numVertices;

    for (int i = 0; i < vertices; i++)
    {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++)
    {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = 1;

        struct Node *temp = graph->adjList[u];
        while (temp)
        {
            int v = temp->vertex;
            if (mstSet[v] == 0 && temp->weight < key[v])
            {
                parent[v] = u;
                key[v] = temp->weight;
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i < vertices; i++)
    {
        printf("%d - %d\n", parent[i], i);
    }
}

int main()
{
    struct Graph graph;
    int vertices, edges, src, dest, weight;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (src dest weight): ");
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&graph, src, dest, weight);
    }

    primMST(&graph);

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
