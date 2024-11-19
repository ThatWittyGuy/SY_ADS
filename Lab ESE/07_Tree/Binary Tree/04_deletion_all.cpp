#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
};

Node* insert(Node* root, int val) {
    if (!root) return new Node{val};
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (!root) return root;
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    
    // Predefined Binary Search Tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Original Tree (Inorder Traversal): ";
    inorder(root);
    cout << endl;

    int choice, value;

    do {
        cout << "\nChoose the type of deletion:\n";
        cout << "1. Delete a leaf node\n";
        cout << "2. Delete a node with one child\n";
        cout << "3. Delete a node with two children\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to delete (leaf node): ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Tree after deletion (Inorder Traversal): ";
                inorder(root);
                cout << endl;
                break;
            case 2:
                cout << "Enter value to delete (node with one child): ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Tree after deletion (Inorder Traversal): ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Enter value to delete (node with two children): ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Tree after deletion (Inorder Traversal): ";
                inorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
