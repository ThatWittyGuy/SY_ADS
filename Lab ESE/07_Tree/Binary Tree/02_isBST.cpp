#include <iostream>
using namespace std;

# define INT_MIN 0
# define INT_MAX 9999

struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
};

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = new Node{10};
    root->left = new Node{5};
    root->right = new Node{15};
    root->left->left = new Node{2};
    root->left->right = new Node{7};
    root->right->left = new Node{12};
    root->right->right = new Node{20};
    cout << (isBST(root) ? "BST" : "Not BST") << endl;
    return 0;
}
