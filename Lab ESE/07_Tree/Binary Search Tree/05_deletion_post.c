#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
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
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

struct Node *findMin(struct Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
        return root;

    // Case 1: Node to be deleted is smaller than the root's data
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    // Case 2: Node to be deleted is greater than the root's data
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    // Case 3: Node to be deleted is the root (data == root->data)
    else
    {
        // Case 3a: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL; // The node is deleted, return NULL to its parent
        }
        // Case 3b: Node has one child (either left or right)
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp; // The node is replaced by its right child
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp; // The node is replaced by its left child
        }
        // Case 3c: Node has two children
        else
        {
            // Find the in-order successor (smallest node in the right subtree)
            struct Node *temp = findMin(root->right);

            // Copy the in-order successor's data to the current node
            root->data = temp->data;

            // Delete the in-order successor (which will be a leaf or have one child)
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
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
        if (node->left)
            stack1[++top1] = node->left;
        if (node->right)
            stack1[++top1] = node->right;
    }
    while (top2 >= 0)
    {
        struct Node *node = stack2[top2--];
        printf("%d ", node->data);
    }
}

void menu()
{
    printf("\nBinary Search Tree Operations\n");
    printf("1. Insert Node\n");
    printf("2. Delete Node\n");
    printf("3. Postorder Traversal\n");
    printf("4. Exit\n");
}

int main()
{
    struct Node *root = NULL;
    int choice, data;

    while (1)
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;
        case 3:
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
