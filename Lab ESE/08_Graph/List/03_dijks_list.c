#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode *next;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int V;
    struct AdjList *array;
};

struct AdjListNode *newAdjListNode(int dest, int weight)
{
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    struct AdjListNode *newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

int minDistance(int dist[], int sptSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == 0 && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void dijkstra(struct Graph *graph, int src, int dest)
{
    int V = graph->V;
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
        struct AdjListNode *pCrawl = graph->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;
            if (sptSet[v] == 0 && dist[u] != INT_MAX && dist[u] + pCrawl->weight < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;
            }
            pCrawl = pCrawl->next;
        }
    }
    if (dist[dest] != INT_MAX)
    {
        printf("Shortest distance from node %d to node %d is %d\n", src, dest, dist[dest]);
    }
    else
    {
        printf("No path exists from node %d to node %d\n", src, dest);
    }
}

int main()
{
    int V, E, src, dest, weight;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    struct Graph *graph = createGraph(V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter the edges (src, dest, weight):\n");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }
    printf("Enter the source node: ");
    scanf("%d", &src);
    printf("Enter the destination node: ");
    scanf("%d", &dest);
    dijkstra(graph, src, dest);
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
