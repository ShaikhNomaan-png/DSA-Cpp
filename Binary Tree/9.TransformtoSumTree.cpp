#include <iostream>

using namespace std;

// Structure for a TreeNode
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to transform the binary tree into a Sum Tree
int transformToSumTree(TreeNode* node) {
    // Base case
    if (node == nullptr) {
        return 0;  // Return 0 for null nodes
    }

    // Store the original value
    int oldValue = node->data;

    // Recursively call for the left and right subtrees
    int leftSum = transformToSumTree(node->left);
    int rightSum = transformToSumTree(node->right);

    // Update the current node's value to the sum of the left and right subtree
    node->data = leftSum + rightSum;

    // Return the sum of the subtree including the original node value
    return node->data + oldValue;
}

// Function to print the tree in inorder (for verification)
void printInorder(TreeNode* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

// Helper function to create a sample binary tree
TreeNode* createSampleTree() {
    // Constructing the following binary tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

// Main function
int main() {
    // Create a sample binary tree
    TreeNode* root = createSampleTree();

    // Print the original inorder traversal of the tree
    cout << "Inorder traversal of the original tree: ";
    printInorder(root);
    cout << endl;

    // Transform the tree to Sum Tree
    transformToSumTree(root);

    // Print the inorder traversal of the converted Sum Tree
    cout << "Inorder traversal of the Sum Tree: ";
    printInorder(root);
    cout << endl;

    // Clean-up memory (not shown here; ensure to free memory in practice)

    return 0;
}
