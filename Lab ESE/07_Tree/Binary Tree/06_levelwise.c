#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to print nodes level by level
void printLevelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        struct Node *current = queue[front++];
        printf("%d ", current->data);

        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
}

// Main function to test the program
int main()
{
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Level order traversal of binary tree:\n");
    printLevelOrder(root);
    return 0;
}
