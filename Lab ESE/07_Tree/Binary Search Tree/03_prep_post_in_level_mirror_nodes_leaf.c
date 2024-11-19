#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data)
{
    struct Node *newNode = createNode(data);
    if (root == NULL)
        return newNode;
    struct Node *parent = NULL;
    struct Node *current = root;
    while (current != NULL)
    {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    return root;
}

void preorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0)
    {
        struct Node *node = stack[top--];
        printf("%d ", node->data);
        if (node->right != NULL)
            stack[++top] = node->right;
        if (node->left != NULL)
            stack[++top] = node->left;
    }
}

void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    struct Node *stack[100];
    int top = -1;
    struct Node *current = root;
    while (top >= 0 || current != NULL)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void postorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    struct Node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 >= 0)
    {
        struct Node *node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left != NULL)
            stack1[++top1] = node->left;
        if (node->right != NULL)
            stack1[++top1] = node->right;
    }
    while (top2 >= 0)
    {
        struct Node *node = stack2[top2--];
        printf("%d ", node->data);
    }
}

int countTotalNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    struct Node *stack[100];
    int top = -1, nodeCount = 0;
    stack[++top] = root;
    while (top >= 0)
    {
        struct Node *node = stack[top--];
        nodeCount++;
        if (node->right != NULL)
            stack[++top] = node->right;
        if (node->left != NULL)
            stack[++top] = node->left;
    }
    return nodeCount;
}

int countLeafNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    struct Node *stack[100];
    int top = -1, leafCount = 0;
    stack[++top] = root;
    while (top >= 0)
    {
        struct Node *node = stack[top--];
        if (node->left == NULL && node->right == NULL)
            leafCount++;
        if (node->right != NULL)
            stack[++top] = node->right;
        if (node->left != NULL)
            stack[++top] = node->left;
    }
    return leafCount;
}

void displayLeafNodes(struct Node *root)
{
    if (root == NULL)
        return;
    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0)
    {
        struct Node *node = stack[top--];
        if (node->left == NULL && node->right == NULL)
            printf("%d ", node->data);
        if (node->right != NULL)
            stack[++top] = node->right;
        if (node->left != NULL)
            stack[++top] = node->left;
    }
    printf("\n");
}

void mirrorImage(struct Node *root)
{
    if (root == NULL)
        return;
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        struct Node *node = queue[front++];
        struct Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
        if (node->left != NULL)
            queue[rear++] = node->left;
        if (node->right != NULL)
            queue[rear++] = node->right;
    }
}

void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        struct Node *node = queue[front++];
        printf("%d ", node->data);
        if (node->left != NULL)
            queue[rear++] = node->left;
        if (node->right != NULL)
            queue[rear++] = node->right;
    }
}

void levelOrderByLevel(struct Node *root)
{
    if (root == NULL)
        return;
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        int nodeCount = rear - front;
        while (nodeCount > 0)
        {
            struct Node *node = queue[front++];
            printf("%d ", node->data);
            if (node->left != NULL)
                queue[rear++] = node->left;
            if (node->right != NULL)
                queue[rear++] = node->right;
            nodeCount--;
        }
        printf("\n");
    }
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    printf("Total Number of Nodes: %d\n", countTotalNodes(root));

    printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));

    printf("Leaf Nodes: ");
    displayLeafNodes(root);

    mirrorImage(root);
    printf("Mirror Image: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
