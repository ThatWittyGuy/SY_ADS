#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define NUM_STACKS 3

int stack[NUM_STACKS][MAX];
int top[NUM_STACKS] = {-1, -1, -1};

int isFull(int stackIndex)
{
    return top[stackIndex] == MAX - 1;
}

int isEmpty(int stackIndex)
{
    return top[stackIndex] == -1;
}

void push(int stackIndex, int value)
{
    if (isFull(stackIndex))
    {
        printf("Stack %d is full.\n", stackIndex + 1);
    }
    else
    {
        stack[stackIndex][++top[stackIndex]] = value;
        printf("Pushed %d to stack %d\n", value, stackIndex + 1);
    }
}

int pop(int stackIndex)
{
    if (isEmpty(stackIndex))
    {
        printf("Stack %d is empty.\n", stackIndex + 1);
        return -1;
    }
    else
    {
        return stack[stackIndex][top[stackIndex]--];
    }
}

void display(int stackIndex)
{
    if (isEmpty(stackIndex))
    {
        printf("Stack %d is empty.\n", stackIndex + 1);
    }
    else
    {
        printf("Stack %d: ", stackIndex + 1);
        for (int i = 0; i <= top[stackIndex]; i++)
        {
            printf("%d ", stack[stackIndex][i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value, stackIndex;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. PUSH\n2. POP\n3. StackFull\n4. StackEmpty\n5. Display Stack\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter stack index (1, 2, or 3): ");
            scanf("%d", &stackIndex);
            stackIndex--;
            if (stackIndex >= 0 && stackIndex < NUM_STACKS)
            {
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stackIndex, value);
            }
            else
            {
                printf("Invalid stack index.\n");
            }
            break;
        case 2:
            printf("Enter stack index (1, 2, or 3): ");
            scanf("%d", &stackIndex);
            stackIndex--;
            if (stackIndex >= 0 && stackIndex < NUM_STACKS)
            {
                value = pop(stackIndex);
                if (value != -1)
                    printf("Popped %d from stack %d\n", value, stackIndex + 1);
            }
            else
            {
                printf("Invalid stack index.\n");
            }
            break;
        case 3:
            printf("Enter stack index (1, 2, or 3): ");
            scanf("%d", &stackIndex);
            stackIndex--;
            if (stackIndex >= 0 && stackIndex < NUM_STACKS)
            {
                if (isFull(stackIndex))
                {
                    printf("Stack %d is full.\n", stackIndex + 1);
                }
                else
                {
                    printf("Stack %d is not full.\n", stackIndex + 1);
                }
            }
            else
            {
                printf("Invalid stack index.\n");
            }
            break;
        case 4:
            printf("Enter stack index (1, 2, or 3): ");
            scanf("%d", &stackIndex);
            stackIndex--;
            if (stackIndex >= 0 && stackIndex < NUM_STACKS)
            {
                if (isEmpty(stackIndex))
                {
                    printf("Stack %d is empty.\n", stackIndex + 1);
                }
                else
                {
                    printf("Stack %d is not empty.\n", stackIndex + 1);
                }
            }
            else
            {
                printf("Invalid stack index.\n");
            }
            break;
        case 5:
            printf("Enter stack index (1, 2, or 3): ");
            scanf("%d", &stackIndex);
            stackIndex--;
            if (stackIndex >= 0 && stackIndex < NUM_STACKS)
            {
                display(stackIndex);
            }
            else
            {
                printf("Invalid stack index.\n");
            }
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
