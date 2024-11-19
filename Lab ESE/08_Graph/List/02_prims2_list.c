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

int minKey(int key[], int mstSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

void primMST(struct Graph *graph)
{
    int V = graph->V;
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;

        struct AdjListNode *pCrawl = graph->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;
            if (mstSet[v] == 0 && pCrawl->weight < key[v])
            {
                key[v] = pCrawl->weight;
                parent[v] = u;
            }
            pCrawl = pCrawl->next;
        }
    }

    for (int i = 1; i < V; i++)
    {
        printf("%d - %d: %d\n", parent[i], i, key[i]);
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
    primMST(graph);
    return 0;
}
