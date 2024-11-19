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
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node *find(struct Node *root, int data)
{
    while (root != NULL)
    {
        if (data == root->data)
        {
            return root;
        }
        if (data < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

void mirrorImage(struct Node *root)
{
    if (root == NULL)
        return;
    struct Node *temp;
    mirrorImage(root->left);
    mirrorImage(root->right);
    temp = root->left;
    root->left = root->right;
    root->right = temp;
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

void menu()
{
    printf("1. Insert\n");
    printf("2. Mirror Image\n");
    printf("3. Find\n");
    printf("4. Postorder Traversal (Non-recursive)\n");
    printf("5. Exit\n");
}

int main()
{
    struct Node *root = NULL;
    int choice, data;
    struct Node *foundNode;
    while (1)
    {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            mirrorImage(root);
            printf("Mirror image: ");
            levelOrderTraversal(root);
            printf("\n");
            break;
        case 3:
            printf("Enter value to find: ");
            scanf("%d", &data);
            foundNode = find(root, data);
            if (foundNode != NULL)
            {
                printf("Found node with value %d\n", foundNode->data);
            }
            else
            {
                printf("Node with value %d not found.\n", data);
            }
            break;
        case 4:
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
