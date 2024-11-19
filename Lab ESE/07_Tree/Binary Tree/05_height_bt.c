#include <stdio.h>
#include <stdlib.h>

// Definition of a Binary Tree Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to calculate the height of the binary tree
int height(struct Node *root)
{
    if (root == NULL)
    {
        return 0; // Height of an empty tree is 0
    }

    // Recursively calculate the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // The height of the current node is 1 + the maximum height of its left and right subtrees
    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}

// Main function
int main()
{
    struct Node *root = NULL;

    // Creating the binary tree
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Printing the height of the tree
    printf("Height of the tree: %d\n", height(root));

    return 0;
}
