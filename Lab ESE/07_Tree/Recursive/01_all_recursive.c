#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive Preorder Traversal
void preorder(struct Node *root) {
    if (root) {
        printf("%d ", root->data);  // Visit root
        preorder(root->left);       // Traverse left subtree
        preorder(root->right);      // Traverse right subtree
    }
}

// Recursive Inorder Traversal
void inorder(struct Node *root) {
    if (root) {
        inorder(root->left);       // Traverse left subtree
        printf("%d ", root->data);  // Visit root
        inorder(root->right);      // Traverse right subtree
    }
}

// Recursive Postorder Traversal
void postorder(struct Node *root) {
    if (root) {
        postorder(root->left);     // Traverse left subtree
        postorder(root->right);    // Traverse right subtree
        printf("%d ", root->data); // Visit root
    }
}

// Recursive Level Order Traversal (using a helper function)
void levelOrder(struct Node *root) {
    if (!root) return;
    int height = findHeight(root);
    for (int i = 1; i <= height; i++) {
        printGivenLevel(root, i);
    }
}

// Helper function to print nodes at a specific level
void printGivenLevel(struct Node *root, int level) {
    if (!root) return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

// Recursive function to find the height of the tree
int findHeight(struct Node *root) {
    if (!root)
        return 0;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Recursive function to mirror the binary tree
void mirror(struct Node *root) {
    if (!root)
        return;
    // Swap the left and right subtrees
    struct Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    // Recursively mirror the left and right subtrees
    mirror(root->left);
    mirror(root->right);
}

// Recursive function to count total number of nodes in the tree
int countNodes(struct Node *root) {
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Recursive function to count the number of leaf nodes
int countLeafNodes(struct Node *root) {
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Recursive function to find the maximum value in the tree
int findMaximum(struct Node *root) {
    if (!root)
        return -1;
    int leftMax = findMaximum(root->left);
    int rightMax = findMaximum(root->right);
    int max = root->data;
    if (leftMax > max)
        max = leftMax;
    if (rightMax > max)
        max = rightMax;
    return max;
}

int main() {
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

    printf("Mirror Image Level Order Traversal: ");
    levelOrder(root);
    printf("\n");

    printf("Total Nodes: %d\n", countNodes(root));
    printf("Height of Tree: %d\n", findHeight(root));
    printf("Total Leaf Nodes: %d\n", countLeafNodes(root));
    printf("Maximum Value in the Tree: %d\n", findMaximum(root));

    return 0;
}

// Original Preorder Traversal: 1 2 4 5 3 6 7        
// Original Inorder Traversal: 4 2 5 1 6 3 7         
// Original Postorder Traversal: 4 5 2 6 7 3 1       
// Original Level Order Traversal: 1 2 3 4 5 6 7     
// Mirror Image Level Order Traversal: 1 3 2 7 6 5 4 
// Total Nodes: 7
// Height of Tree: 3
// Total Leaf Nodes: 4
// Maximum Value in the Tree: 7