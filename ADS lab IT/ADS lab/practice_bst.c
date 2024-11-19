#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// Create a new node with a given value
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->val = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert a node with a given key in the BST
struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->val)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

// Inorder traversal of the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);  // Add a space after %d
        inorder(root->right);
    }
}

//  del key in the BST
struct Node* deleteKey(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->val) {
        root->left = deleteKey(root->left, key);
    } else if (key > root->val) {
        root->right = deleteKey(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
    return root;
}
}

int main() {
    struct Node* root = NULL;
    int key;

    // Insert nodes into the BST
    root = insert(root, 25);
    insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 35);
    insert(root, 40);
    insert(root, 56);
    insert(root, 15);
    insert(root, 13);

    printf("original:\n");
    inorder(root);

    printf("\nEnter key to delete: ");
    scanf("%d", &key);
    deleteKey(root, key);

    printf("Inorder traversal:\n");
    inorder(root);

    return 0;
}

//bst


