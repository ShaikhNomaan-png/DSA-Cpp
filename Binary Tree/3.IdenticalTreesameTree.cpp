/* To determine if two binary trees are identical (i.e., they have the same structure and node values), 
you can use a simple recursive function. Below is a full but concise C++ implementation that 
defines a binary tree and includes the function to check for tree identity.

 */

#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Returns true if trees are identical
bool isIdentical(TreeNode* p, TreeNode* q) {
    // Both empty
    if (p == nullptr && q == nullptr) return true;
    // One empty or values differ
    if (p == nullptr || q == nullptr) return false;
    if (p->val != q->val) return false;

    // Recurse on left and right
    return isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
}

// Helper function to delete the tree
void deleteTree(TreeNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    // Example: build two identical trees P and Q
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    q->left->left = new TreeNode(4);

    std::cout << (isIdentical(p, q) ? "Identical" : "Not identical") << std::endl;

    // Cleanup to avoid memory leaks
    deleteTree(p);
    deleteTree(q);

    return 0;
}
