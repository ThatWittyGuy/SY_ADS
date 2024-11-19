#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the tree
struct Node
{
    int data;
    struct Node *left, *right;
};

// Create a new node with given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into the binary search tree
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);
    struct Node *curr = root;
    while (curr != NULL)
    {
        if (data < curr->data)
        {
            if (curr->left == NULL)
            {
                curr->left = createNode(data);
                return root;
            }
            curr = curr->left;
        }
        else if (data > curr->data)
        {
            if (curr->right == NULL)
            {
                curr->right = createNode(data);
                return root;
            }
            curr = curr->right;
        }
        else
            return root;
    }
    return root;
}

// Find the minimum value node in a tree
struct Node *findMin(struct Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

// Delete a node from the binary search tree
struct Node *deleteNode(struct Node *root, int data)
{
    struct Node *parent = NULL, *curr = root;

    // Find the node to delete
    while (curr != NULL && curr->data != data)
    {
        parent = curr;
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL)
        return root; // Node not found

    // Case 1: Node has no children (leaf node)
    if (curr->left == NULL && curr->right == NULL)
    {
        if (curr == root)
            root = NULL;
        else if (parent->left == curr)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(curr);
    }
    // Case 2: Node has one child (left or right)
    else if (curr->left == NULL || curr->right == NULL)
    {
        struct Node *child = (curr->left != NULL) ? curr->left : curr->right;
        if (curr == root)
            root = child;
        else if (parent->left == curr)
            parent->left = child;
        else
            parent->right = child;
        free(curr);
    }
    // Case 3: Node has two children
    else
    {
        struct Node *minNode = findMin(curr->right);
        int minData = minNode->data;
        root = deleteNode(root, minData);
        curr->data = minData;
    }

    return root;
}

// Postorder Traversal (Left, Right, Root) - Non-recursive
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

// Preorder Traversal (Root, Left, Right) - Non-recursive
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

        if (node->right)
            stack[++top] = node->right;
        if (node->left)
            stack[++top] = node->left;
    }
}

// Inorder Traversal (Left, Root, Right) - Non-recursive
void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *stack[100];
    int top = -1;
    struct Node *curr = root;

    while (curr != NULL || top >= 0)
    {
        while (curr != NULL)
        {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        printf("%d ", curr->data);

        curr = curr->right;
    }
}

// Level-order Traversal (BFS) - Non-recursive
void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *queue[100];
    int front = 0, rear = -1;
    queue[++rear] = root;

    while (front <= rear)
    {
        struct Node *node = queue[front++];
        printf("%d ", node->data);

        if (node->left)
            queue[++rear] = node->left;
        if (node->right)
            queue[++rear] = node->right;
    }
}

// Display the menu options for the user
void menu()
{
    printf("\nBinary Search Tree Operations\n");
    printf("1. Insert Node\n");
    printf("2. Delete Node\n");
    printf("3. Postorder Traversal\n");
    printf("4. Preorder Traversal\n");
    printf("5. Inorder Traversal\n");
    printf("6. Level-order Traversal\n");
    printf("7. Exit\n");
}

// Main function that controls the program flow
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
            printf("Preorder Traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
        case 6:
            printf("Level-order Traversal: ");
            levelOrderTraversal(root);
            printf("\n");
            break;
        case 7:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
