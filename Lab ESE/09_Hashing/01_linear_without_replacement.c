#include <stdio.h>

#define TABLE_SIZE 10

struct HashNode
{
    int data;
    struct HashNode *next;
};

struct HashTable
{
    struct HashNode *table[TABLE_SIZE];
};

int hash(int key)
{
    return key % TABLE_SIZE;
}

void initializeHashTable(struct HashTable *hashTable)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable->table[i] = NULL;
    }
}

void insert(struct HashTable *hashTable, int key, int *collisions)
{
    int index = hash(key);
    struct HashNode *newNode = (struct HashNode *)malloc(sizeof(struct HashNode));
    newNode->data = key;
    newNode->next = NULL;

    if (hashTable->table[index] == NULL)
    {
        hashTable->table[index] = newNode;
    }
    else
    {
        (*collisions)++;
        struct HashNode *current = hashTable->table[index];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display(struct HashTable *hashTable)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct HashNode *current = hashTable->table[i];
        if (current == NULL)
        {
            printf("Index %d: Empty\n", i);
        }
        else
        {
            printf("Index %d:", i);
            while (current != NULL)
            {
                printf(" %d", current->data);
                current = current->next;
            }
            printf("\n");
        }
    }
}

int main()
{
    struct HashTable hashTable;
    int collisions = 0;
    int n, data;

    initializeHashTable(&hashTable);

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insert(&hashTable, data, &collisions);
    }

    printf("\nHash Table:\n");
    display(&hashTable);

    printf("\nTotal Collisions: %d\n", collisions);
    return 0;
}
