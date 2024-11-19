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

int countTotalNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    int count = 0;
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        struct Node *node = queue[front++];
        count++;
        if (node->left != NULL)
            queue[rear++] = node->left;
        if (node->right != NULL)
            queue[rear++] = node->right;
    }
    return count;
}

int countLeafNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    int leafCount = 0;
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        struct Node *node = queue[front++];
        if (node->left == NULL && node->right == NULL)
            leafCount++;
        if (node->left != NULL)
            queue[rear++] = node->left;
        if (node->right != NULL)
            queue[rear++] = node->right;
    }
    return leafCount;
}

void displayLeafNodes(struct Node *root)
{
    if (root == NULL)
        return;
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        struct Node *node = queue[front++];
        if (node->left == NULL && node->right == NULL)
            printf("%d ", node->data);
        if (node->left != NULL)
            queue[rear++] = node->left;
        if (node->right != NULL)
            queue[rear++] = node->right;
    }
}

int heightOfTree(struct Node *root)
{
    if (root == NULL)
        return 0;
    int height = 0;
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    queue[rear] = NULL; // Level marker

    while (front < rear)
    {
        struct Node *node = queue[front++];
        if (node != NULL)
        {
            if (node->left != NULL)
                queue[rear++] = node->left;
            if (node->right != NULL)
                queue[rear++] = node->right;
        }
        if (queue[front] == NULL) // Level complete
        {
            height++;
            if (queue[front + 1] != NULL)
                queue[rear++] = NULL; // Add marker for next level
            front++;
        }
    }
    return height;
}

void menu()
{
    printf("1. Insert\n");
    printf("2. Mirror Image\n");
    printf("3. Find\n");
    printf("4. Preorder Traversal (Non-recursive)\n");
    printf("5. Inorder Traversal (Non-recursive)\n");
    printf("6. Postorder Traversal (Non-recursive)\n");
    printf("7. Level Order Traversal\n");
    printf("8. Total Number of Nodes\n");
    printf("9. Number of Leaf Nodes\n");
    printf("10. Display Leaf Nodes\n");
    printf("11. Height of Tree\n");
    printf("12. Exit\n");
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
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;
        case 7:
            printf("Level Order Traversal: ");
            levelOrderTraversal(root);
            printf("\n");
            break;
        case 8:
            printf("Total Number of Nodes: %d\n", countTotalNodes(root));
            break;
        case 9:
            printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));
            break;
        case 10:
            printf("Leaf Nodes: ");
            displayLeafNodes(root);
            printf("\n");
            break;
        case 11:
            printf("Height of Tree: %d\n", heightOfTree(root));
            break;
        case 12:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;
// };

// struct Node *createNode(int data)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// struct Node *insert(struct Node *root, int data)
// {
//     if (root == NULL)
//     {
//         return createNode(data);
//     }
//     if (data < root->data)
//     {
//         root->left = insert(root->left, data);
//     }
//     else
//     {
//         root->right = insert(root->right, data);
//     }
//     return root;
// }

// struct Node *find(struct Node *root, int data)
// {
//     while (root != NULL)
//     {
//         if (data == root->data)
//         {
//             return root;
//         }
//         if (data < root->data)
//         {
//             root = root->left;
//         }
//         else
//         {
//             root = root->right;
//         }
//     }
//     return NULL;
// }

// void mirrorImage(struct Node *root)
// {
//     if (root == NULL)
//         return;
//     struct Node *temp;
//     mirrorImage(root->left);
//     mirrorImage(root->right);
//     temp = root->left;
//     root->left = root->right;
//     root->right = temp;
// }

// void postorderTraversal(struct Node *root)
// {
//     if (root == NULL)
//         return;
//     struct Node *stack1[100], *stack2[100];
//     int top1 = -1, top2 = -1;
//     stack1[++top1] = root;
//     while (top1 >= 0)
//     {
//         struct Node *node = stack1[top1--];
//         stack2[++top2] = node;
//         if (node->left != NULL)
//             stack1[++top1] = node->left;
//         if (node->right != NULL)
//             stack1[++top1] = node->right;
//     }
//     while (top2 >= 0)
//     {
//         struct Node *node = stack2[top2--];
//         printf("%d ", node->data);
//     }
// }

// void preorderTraversal(struct Node *root)
// {
//     if (root == NULL)
//         return;
//     struct Node *stack[100];
//     int top = -1;
//     stack[++top] = root;
//     while (top >= 0)
//     {
//         struct Node *node = stack[top--];
//         printf("%d ", node->data);
//         if (node->right != NULL)
//             stack[++top] = node->right;
//         if (node->left != NULL)
//             stack[++top] = node->left;
//     }
// }

// void inorderTraversal(struct Node *root)
// {
//     if (root == NULL)
//         return;
//     struct Node *stack[100];
//     int top = -1;
//     struct Node *current = root;
//     while (top >= 0 || current != NULL)
//     {
//         while (current != NULL)
//         {
//             stack[++top] = current;
//             current = current->left;
//         }
//         current = stack[top--];
//         printf("%d ", current->data);
//         current = current->right;
//     }
// }

// void levelOrderTraversal(struct Node *root)
// {
//     if (root == NULL)
//         return;
//     struct Node *queue[100];
//     int front = 0, rear = 0;
//     queue[rear++] = root;
//     while (front < rear)
//     {
//         struct Node *node = queue[front++];
//         printf("%d ", node->data);
//         if (node->left != NULL)
//             queue[rear++] = node->left;
//         if (node->right != NULL)
//             queue[rear++] = node->right;
//     }
// }

// int countTotalNodes(struct Node *root)
// {
//     if (root == NULL)
//         return 0;
//     int count = 0;
//     struct Node *queue[100];
//     int front = 0, rear = 0;
//     queue[rear++] = root;
//     while (front < rear)
//     {
//         struct Node *node = queue[front++];
//         count++;
//         if (node->left != NULL)
//             queue[rear++] = node->left;
//         if (node->right != NULL)
//             queue[rear++] = node->right;
//     }
//     return count;
// }

// int countLeafNodes(struct Node *root)
// {
//     if (root == NULL)
//         return 0;
//     int leafCount = 0;
//     struct Node *queue[100];
//     int front = 0, rear = 0;
//     queue[rear++] = root;
//     while (front < rear)
//     {
//         struct Node *node = queue[front++];
//         if (node->left == NULL && node->right == NULL)
//             leafCount++;
//         if (node->left != NULL)
//             queue[rear++] = node->left;
//         if (node->right != NULL)
//             queue[rear++] = node->right;
//     }
//     return leafCount;
// }

// void displayLeafNodes(struct Node *root)
// {
//     if (root == NULL)
//         return;
//     struct Node *queue[100];
//     int front = 0, rear = 0;
//     queue[rear++] = root;
//     while (front < rear)
//     {
//         struct Node *node = queue[front++];
//         if (node->left == NULL && node->right == NULL)
//             printf("%d ", node->data);
//         if (node->left != NULL)
//             queue[rear++] = node->left;
//         if (node->right != NULL)
//             queue[rear++] = node->right;
//     }
// }

// void menu()
// {
//     printf("1. Insert\n");
//     printf("2. Mirror Image\n");
//     printf("3. Find\n");
//     printf("4. Preorder Traversal (Non-recursive)\n");
//     printf("5. Inorder Traversal (Non-recursive)\n");
//     printf("6. Postorder Traversal (Non-recursive)\n");
//     printf("7. Level Order Traversal\n");
//     printf("8. Total Number of Nodes\n");
//     printf("9. Number of Leaf Nodes\n");
//     printf("10. Display Leaf Nodes\n");
//     printf("11. Exit\n");
// }

// int main()
// {
//     struct Node *root = NULL;
//     int choice, data;
//     struct Node *foundNode;
//     while (1)
//     {
//         menu();
//         printf("Enter choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("Enter value to insert: ");
//             scanf("%d", &data);
//             root = insert(root, data);
//             break;
//         case 2:
//             mirrorImage(root);
//             printf("Mirror image: ");
//             levelOrderTraversal(root);
//             printf("\n");
//             break;
//         case 3:
//             printf("Enter value to find: ");
//             scanf("%d", &data);
//             foundNode = find(root, data);
//             if (foundNode != NULL)
//             {
//                 printf("Found node with value %d\n", foundNode->data);
//             }
//             else
//             {
//                 printf("Node with value %d not found.\n", data);
//             }
//             break;
//         case 4:
//             printf("Preorder Traversal: ");
//             preorderTraversal(root);
//             printf("\n");
//             break;
//         case 5:
//             printf("Inorder Traversal: ");
//             inorderTraversal(root);
//             printf("\n");
//             break;
//         case 6:
//             printf("Postorder Traversal: ");
//             postorderTraversal(root);
//             printf("\n");
//             break;
//         case 7:
//             printf("Level Order Traversal: ");
//             levelOrderTraversal(root);
//             printf("\n");
//             break;
//         case 8:
//             printf("Total Number of Nodes: %d\n", countTotalNodes(root));
//             break;
//         case 9:
//             printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));
//             break;
//         case 10:
//             printf("Leaf Nodes: ");
//             displayLeafNodes(root);
//             printf("\n");
//             break;
//         case 11:
//             printf("Exiting...\n");
//             return 0;
//         default:
//             printf("Invalid choice! Please try again.\n");
//         }
//     }
//     return 0;
// }
