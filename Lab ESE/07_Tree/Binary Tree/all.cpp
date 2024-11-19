#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void printLevelOrder(Node* root, int level) {
    if (root == nullptr) return;
    if (level == 1) {
        cout << root->data << " ";
    } else if (level > 1) {
        printLevelOrder(root->left, level - 1);
        printLevelOrder(root->right, level - 1);
    }
}

int height(Node* root) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

void levelOrderTraversal(Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevelOrder(root, i);
        cout << endl;
    }
}

void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int countLeafNodes(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countNodes(Node* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void mirror(Node* root) {
    if (root == nullptr) return;
    // Swap the left and right children
    swap(root->left, root->right);
    mirror(root->left);   // Recurse on the left subtree
    mirror(root->right);  // Recurse on the right subtree
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int choice;
    while (true) {
        cout << "1. Level-order Traversal\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Count Leaf Nodes\n";
        cout << "6. Count Total Nodes\n";
        cout << "7. Display Height of Tree\n";
        cout << "8. Mirror Image of Tree\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                levelOrderTraversal(root);
                break;
            case 2:
                preorderTraversal(root);
                cout << endl;
                break;
            case 3:
                postorderTraversal(root);
                cout << endl;
                break;
            case 4:
                inorderTraversal(root);
                cout << endl;
                break;
            case 5:
                cout << "Leaf Nodes: " << countLeafNodes(root) << endl;
                break;
            case 6:
                cout << "Total Nodes: " << countNodes(root) << endl;
                break;
            case 7:
                cout << "Height of Tree: " << height(root) << endl;
                break;
            case 8:
                mirror(root);
                cout << "Mirror Image of Tree: ";
                levelOrderTraversal(root);
                cout << endl;
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
