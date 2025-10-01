#include <iostream>
// Leetcode 105
using namespace std;

// Structure for TreeNode
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to build the binary tree from preorder and inorder traversals
TreeNode* buildTreeHelper(int preorder[], int inorder[], int inStart, int inEnd, int& preIndex) {
    // Base case: if there are no elements to construct the tree
    if (inStart > inEnd) return nullptr;

    // The next element in the preorder array is the root
    int rootValue = preorder[preIndex++];
    TreeNode* root = new TreeNode(rootValue);

    // Find the index of this root in the inorder array
    int inIndex;
    for (inIndex = inStart; inIndex <= inEnd; ++inIndex) {
        if (inorder[inIndex] == rootValue) break;
    }

    // Recursively construct the left and right subtrees
    root->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

// Function to build the binary tree
TreeNode* buildTree(int preorder[], int inorder[], int size) {
    int preIndex = 0; // Initialize index for preorder
    return buildTreeHelper(preorder, inorder, 0, size - 1, preIndex);
}

// Function to print the tree in inorder (for verification)
void printInorder(TreeNode* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

// Sample usage
int main() {
    // Preorder and inorder arrays
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    // Build the tree
    TreeNode* root = buildTree(preorder, inorder, size);

    // Print the inorder traversal of the constructed tree
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    // Clean-up memory (not shown here; ensure to free memory in practice)

    return 0;
}
