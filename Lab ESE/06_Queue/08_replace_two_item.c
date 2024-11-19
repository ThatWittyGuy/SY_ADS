#include <stdio.h>

#define MAX_QUEUE_SIZE 100

struct Queue
{
    int items[MAX_QUEUE_SIZE];
    int front, rear;
};

void initQueue(struct Queue *q)
{
    q->front = q->rear = -1;
}

int isQueueEmpty(struct Queue *q)
{
    return q->front == -1;
}

int isQueueFull(struct Queue *q)
{
    return q->rear == MAX_QUEUE_SIZE - 1;
}

void enqueue(struct Queue *q, int item)
{
    if (isQueueFull(q))
    {
        printf("Queue is full.\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->items[++(q->rear)] = item;
}

int dequeue(struct Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return item;
}

void replace(struct Queue *q, int oldItem, int newItem)
{
    int size = q->rear - q->front + 1;
    for (int i = 0; i < size; i++)
    {
        int item = dequeue(q);
        if (item == oldItem)
            item = newItem;
        enqueue(q, item);
    }
}

void displayQueue(struct Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    initQueue(&q);
    int n, item, oldItem, newItem;

    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter elements of the queue:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item);
        enqueue(&q, item);
    }

    printf("Enter the item to replace: ");
    scanf("%d", &oldItem);

    printf("Enter the new item: ");
    scanf("%d", &newItem);

    replace(&q, oldItem, newItem);

    printf("Queue after replacement: ");
    displayQueue(&q);

    return 0;
}
