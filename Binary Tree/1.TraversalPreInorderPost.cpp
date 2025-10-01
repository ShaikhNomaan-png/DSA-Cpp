/*A Binary Tree is a tree data structure in which each node has at most two children, 
referred to as the left child and the right child.

A. Traversal
Traversal methods allow visiting all nodes in the tree:

Preorder: Visit the root, then the left subtree, then the right subtree.
Inorder: Visit the left subtree, then the root, then the right subtree.
Postorder: Visit the left subtree, then the right subtree, then the root.
Level-order: Visit nodes level by level from top to bottom.

*/

#include <iostream>
#include <queue>

using namespace std;

// Definition for a TreeNode
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Insert a new node into the binary tree
void insert(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }

    // Use a queue for level-order insertion
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current->left != nullptr) {
            q.push(current->left);
        } else {
            current->left = new TreeNode(value);
            return;
        }

        if (current->right != nullptr) {
            q.push(current->right);
        } else {
            current->right = new TreeNode(value);
            return;
        }
    }
}

// Delete the binary tree
void deleteTree(TreeNode*& node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
        node = nullptr;
    }
}

// Preorder traversal
void preorder(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// Inorder traversal
void inorder(TreeNode* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

// Postorder traversal
void postorder(TreeNode* node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

// Level order traversal
void levelOrder(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

// Function to create a sample binary tree
void createSampleTree(TreeNode*& root) {
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
}

int main() {
    TreeNode* root = nullptr;

    // Create a sample tree
    createSampleTree(root);

    // Display different traversals
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;

    // Clean up the tree
    deleteTree(root);

    return 0;
}
