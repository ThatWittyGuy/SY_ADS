#include <stdio.h>

#define MAX_SIZE 100

struct MultiQueue
{
    int queue[MAX_SIZE];
    int front1, rear1, front2, rear2;
};

void initQueues(struct MultiQueue *mq)
{
    mq->front1 = mq->rear1 = -1;
    mq->front2 = mq->rear2 = MAX_SIZE;
}

int isQueue1Empty(struct MultiQueue *mq)
{
    return mq->front1 == -1;
}

int isQueue2Empty(struct MultiQueue *mq)
{
    return mq->front2 == MAX_SIZE;
}

int isQueue1Full(struct MultiQueue *mq)
{
    return mq->rear1 + 1 == mq->front2;
}

int isQueue2Full(struct MultiQueue *mq)
{
    return mq->rear2 - 1 == mq->front1;
}

void addq1(struct MultiQueue *mq, int item)
{
    if (isQueue1Full(mq))
    {
        printf("Queue 1 is full.\n");
        return;
    }
    if (mq->front1 == -1)
        mq->front1 = 0;
    mq->queue[++(mq->rear1)] = item;
}

void addq2(struct MultiQueue *mq, int item)
{
    if (isQueue2Full(mq))
    {
        printf("Queue 2 is full.\n");
        return;
    }
    if (mq->front2 == MAX_SIZE)
        mq->front2 = MAX_SIZE - 1;
    mq->queue[--(mq->rear2)] = item;
}

int delq1(struct MultiQueue *mq)
{
    if (isQueue1Empty(mq))
    {
        printf("Queue 1 is empty.\n");
        return -1;
    }
    int item = mq->queue[mq->front1];
    if (mq->front1 == mq->rear1)
    {
        mq->front1 = mq->rear1 = -1;
    }
    else
    {
        mq->front1++;
    }
    return item;
}

int delq2(struct MultiQueue *mq)
{
    if (isQueue2Empty(mq))
    {
        printf("Queue 2 is empty.\n");
        return -1;
    }
    int item = mq->queue[mq->front2];
    if (mq->front2 == mq->rear2)
    {
        mq->front2 = mq->rear2 = MAX_SIZE;
    }
    else
    {
        mq->front2--;
    }
    return item;
}

void displayQueue1(struct MultiQueue *mq)
{
    if (isQueue1Empty(mq))
    {
        printf("Queue 1 is empty.\n");
        return;
    }
    printf("Queue 1: ");
    for (int i = mq->front1; i <= mq->rear1; i++)
    {
        printf("%d ", mq->queue[i]);
    }
    printf("\n");
}

void displayQueue2(struct MultiQueue *mq)
{
    if (isQueue2Empty(mq))
    {
        printf("Queue 2 is empty.\n");
        return;
    }
    printf("Queue 2: ");
    for (int i = mq->front2; i >= mq->rear2; i--)
    {
        printf("%d ", mq->queue[i]);
    }
    printf("\n");
}

int main()
{
    struct MultiQueue mq;
    initQueues(&mq);
    int choice, item;

    while (1)
    {
        printf("\n1. Add to Queue 1\n2. Add to Queue 2\n3. Delete from Queue 1\n4. Delete from Queue 2\n5. Display Queue 1\n6. Display Queue 2\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter item to add to Queue 1: ");
            scanf("%d", &item);
            addq1(&mq, item);
            break;
        case 2:
            printf("Enter item to add to Queue 2: ");
            scanf("%d", &item);
            addq2(&mq, item);
            break;
        case 3:
            item = delq1(&mq);
            if (item != -1)
                printf("Deleted from Queue 1: %d\n", item);
            break;
        case 4:
            item = delq2(&mq);
            if (item != -1)
                printf("Deleted from Queue 2: %d\n", item);
            break;
        case 5:
            displayQueue1(&mq);
            break;
        case 6:
            displayQueue2(&mq);
            break;
        case 7:
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
