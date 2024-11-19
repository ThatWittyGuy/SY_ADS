#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

//creating a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//new node insertion
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

//height of BT
int height(struct node* n) {
    if (n == NULL) {
        return 0;
    }

    int lH = height(n->left);
    int rH = height(n->right);

    return 1 + (lH > rH ? lH : rH);
}
//to print leaf nodes
void printLeaf(struct node* n) {
    if (n == NULL) {
        return;
    }

    if (n->left == NULL && n->right == NULL) {
        printf("%d ", n->data);
    }

    printLeaf(n->left);
    printLeaf(n->right);
}
//calculate level of BT
void printLevel(struct node* root, int level) {
    if (root == NULL) {
        return;
    }

    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void display(struct node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
        printf("\n");
    }
}

void mirror(struct node* n) {
    if (n == NULL) {
        return;
    }

    mirror(n->left);
    mirror(n->right);

    struct node* temp = n->left;
    n->left = n->right;
    n->right = temp;
}

int main() {
    struct node* root = NULL;
    int ch, val, n;

    while (1) {
        printf("\nBinary Tree operations are:\n");
        printf("1. Insert node\n");
        printf("2. Display tree traversal\n");
        printf("3. Display height of tree\n");
        printf("4. Display leaf nodes of tree\n");
        printf("5. Display mirror image of tree\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter number of nodes to insert: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter node data: ");
                    scanf("%d", &val);
                    root = insert(root, val);
                }
                break;

            case 2:
                printf("Binary Tree is:\n");
                display(root);
                break;

            case 3:
                printf("Height of the tree is: %d\n", height(root));
                break;

            case 4:
                printf("Leaf Nodes are: ");
                printLeaf(root);
                printf("\n");
                break;

            case 5:
                printf("Mirror image of the Binary Tree is:\n");
                mirror(root);
                display(root);
                break;

            case 6:
                printf("Exit\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
