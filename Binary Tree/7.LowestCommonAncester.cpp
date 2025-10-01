#include <iostream>
// Leetcode 236 problem
// Structure for TreeNode
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

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

// Function to find the LCA of two nodes
TreeNode* findLCA(TreeNode* node, int a, int b) {
    // Base case: if the node is nullptr, return nullptr
    if (node == nullptr) return nullptr;

    // If the current node's data matches either a or b, return this node
    if (node->data == a || node->data == b) return node;

    // Recur to find LCA in the left and right subtrees
    TreeNode* leftLCA = findLCA(node->left, a, b);
    TreeNode* rightLCA = findLCA(node->right, a, b);

    // If both left and right call returned non-null, this is the LCA
    if (leftLCA && rightLCA) return node;

    // Otherwise, return the non-null child (if any)
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int main() {
    TreeNode* root = nullptr;

    // Create a sample binary tree
    createSampleTree(root);

    // Example nodes for which we want to find the LCA
    int node1 = 4, node2 = 5;
    TreeNode* lca = findLCA(root, node1, node2);

    if (lca) {
        std::cout << "LCA of " << node1 << " and " << node2 << " is: " << lca->data << std::endl;
    } else {
        std::cout << "LCA not found." << std::endl;
    }

    return 0;
}
