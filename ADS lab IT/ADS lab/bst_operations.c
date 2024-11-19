//BST

/*#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// creating new node
struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// insertion
struct node* insert(struct node* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// finding smallest value in right subtree
struct node* findMin(struct node* root) {
    struct node* current = root;
    if (root == NULL)
    return NULL;
  else if (root -> left != NULL); // Traverse left until the leftmost node (which will be the smallest node)
    return findMin(root -> left); // no child in left , left most element will be minimum
  return root;
}

// deletion
struct node* deleteNode(struct node* root, int val) {
    if (root == NULL) return NULL;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {

//no child node or 1 child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        //2 child node
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// inorder traversal
void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// preorder traversal
void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// postorder traversal
void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node* root = NULL;
    int c, val;

while (1) {
        printf("\nBST Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

    switch (c) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            root = insert(root, val);
            printf("Node inserted.\n");
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            root = deleteNode(root, val);
            printf("Node deleted\n");
            break;

        case 3:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 4:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 5:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 6:
            printf("Exit\n");
            exit(0);

        default:
        printf("Enter valid option.\n");
        }
    }

return 0;
}*/

#include<stdio.h>

int main(){
  int arr[]={23,43,5,50,11,34};
  int n=sizeof(arr)/sizeof(arr[0]);
  int key;

  for(int i=0; i<n; i++){
    printf("%d\t",arr[i]);
  }
  printf("enter key: ");
  scanf("%d",&key);
int res = search(arr,0,n-1,key);
  printf("found at pos %d",res);
  if (res==-1){
    printf("not found");
  }

return 0;
}

int search(int arr[],int p, int r, int key){
  int q = p+(r-p)/2;
  if (key==arr[q]){
    return q;

  if (key<arr[q])
    r = q-1;
  else
    p=q+1;

}
return -1;
}





