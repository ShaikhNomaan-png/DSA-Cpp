/*   The diameter of a binary tree is defined as the length of the longest path between any two nodes in the tree.
 This path may or may not pass through the root. The diameter can be computed as the maximum value of 
 the sum of the heights of the left and right subtrees for every node in the binary tree.

Here's how you can implement the function to compute the diameter of a binary tree in C++.

*/
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to calculate the height of the tree
int height(TreeNode* node, int &diameter) {
    if (node == nullptr) return 0;

    // Recursively find the height of left and right subtrees
    int leftHeight = height(node->left, diameter);
    int rightHeight = height(node->right, diameter);

    // Update the diameter if the current path is larger
    diameter = std::max(diameter, leftHeight + rightHeight);

    // Return the height of the tree rooted at this node
    return 1 + std::max(leftHeight, rightHeight);
}

// Function to calculate the diameter of the binary tree
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0; // Initialize the diameter variable
    height(root, diameter); // Calculate height and update diameter
    return diameter; // Return the diameter
}

// Helper to create a sample tree
void createSampleTree(TreeNode* &root) {
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
}

int main() {
    TreeNode* root = nullptr;
    createSampleTree(root);

    int diameter = diameterOfBinaryTree(root);
    std::cout << "Diameter of the binary tree: " << diameter << std::endl;

    // Cleanup (delete nodes) in real code to avoid memory leaks
    // (Left as an exercise or use smart pointers)

    return 0;
}
