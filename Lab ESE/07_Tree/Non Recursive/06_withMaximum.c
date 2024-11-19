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

void preorder(struct Node *root)
{
    if (!root)
        return;
    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0)
    {
        struct Node *node = stack[top--];
        printf("%d ", node->data);

        if (node->right)
            stack[++top] = node->right;
        if (node->left)
            stack[++top] = node->left;
    }
}

void postorder(struct Node *root)
{
    if (!root)
        return;
    struct Node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;

    while (top1 >= 0)
    {
        struct Node *node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left)
            stack1[++top1] = node->left;
        if (node->right)
            stack1[++top1] = node->right;
    }

    while (top2 >= 0)
    {
        printf("%d ", stack2[top2--]->data);
    }
}

void inorder(struct Node *root)
{
    if (!root)
        return;
    struct Node *stack[100];
    int top = -1;
    struct Node *curr = root;

    while (curr || top >= 0)
    {
        while (curr)
        {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void levelOrder(struct Node *root)
{
    if (!root)
        return;
    struct Node *queue[100];
    int front = -1, rear = -1;

    queue[++rear] = root;

    while (front != rear)
    {
        struct Node *node = queue[++front];
        printf("%d ", node->data);

        if (node->left)
            queue[++rear] = node->left;
        if (node->right)
            queue[++rear] = node->right;
    }
}

void mirror(struct Node *root)
{
    if (!root)
        return;

    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0)
    {
        struct Node *node = stack[top--];

        struct Node *temp = node->left;
        node->left = node->right;
        node->right = temp;

        if (node->left)
            stack[++top] = node->left;
        if (node->right)
            stack[++top] = node->right;
    }
}

int countNodes(struct Node *root)
{
    if (!root)
        return 0;
    struct Node *stack[100];
    int top = -1, count = 0;
    stack[++top] = root;

    while (top >= 0)
    {
        struct Node *node = stack[top--];
        count++;

        if (node->right)
            stack[++top] = node->right;
        if (node->left)
            stack[++top] = node->left;
    }

    return count;
}

int countLeafNodes(struct Node *root)
{
    if (!root)
        return 0;

    struct Node *stack[100];
    int top = -1, leafCount = 0;
    stack[++top] = root;

    while (top >= 0)
    {
        struct Node *node = stack[top--];

        if (!node->left && !node->right)
        {
            leafCount++;
        }

        if (node->right)
            stack[++top] = node->right;
        if (node->left)
            stack[++top] = node->left;
    }

    return leafCount;
}

int height(struct Node *root)
{
    if (!root)
        return 0;
    struct Node *stack[100];
    int height[100], top = -1, maxHeight = 0;
    stack[++top] = root;
    height[top] = 1;

    while (top >= 0)
    {
        struct Node *node = stack[top];
        int currentHeight = height[top--];

        if (node->left)
        {
            stack[++top] = node->left;
            height[top] = currentHeight + 1;
        }
        if (node->right)
        {
            stack[++top] = node->right;
            height[top] = currentHeight + 1;
        }

        if (currentHeight > maxHeight)
            maxHeight = currentHeight;
    }

    return maxHeight;
}

int findMaximum(struct Node *root)
{
    if (!root)
        return -1;

    struct Node *stack[100];
    int top = -1;
    int max = root->data;
    stack[++top] = root;

    while (top >= 0)
    {
        struct Node *node = stack[top--];

        if (node->data > max)
            max = node->data;

        if (node->right)
            stack[++top] = node->right;

        if (node->left)
            stack[++top] = node->left;
    }

    return max;
}

int main()
{
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Original Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Original Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Original Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("Original Level Order Traversal: ");
    levelOrder(root);
    printf("\n");

    mirror(root);

    printf("Mirror Image Traversal: ");
    levelOrder(root);
    printf("\n");

    printf("Total Nodes: %d\n", countNodes(root));
    printf("Height of Tree: %d\n", height(root));
    printf("Total Leaf Nodes: %d\n", countLeafNodes(root));
    printf("Maximum Value in the Tree: %d\n", findMaximum(root));

    return 0;
}
