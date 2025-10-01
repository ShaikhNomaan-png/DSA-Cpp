/*  The "Maximum Width of Binary Tree" problem involves finding the maximum width of a binary tree at any level.
 The width of a level is defined as the number of nodes present at that level, including gaps between nodes.

*/
// Leetcode 662
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to calculate the maximum width of the binary tree
int maxWidth(Node* root) {
    if (root == nullptr) return 0;

    int maxWidth = 0;
    queue<pair<Node*, int>> q; // Pair of Node and its position
    q.push({root, 0}); // Start with the root at position 0

    while (!q.empty()) {
        int size = q.size();
        int firstIndex, lastIndex;

        for (int i = 0; i < size; i++) {
            auto [node, index] = q.front();
            q.pop();

            // Save the first and last index for the current level
            if (i == 0) firstIndex = index;
            if (i == size - 1) lastIndex = index;

            // Push left and right children with their respective indices
            if (node->left) q.push({node->left, 2 * index}); // Left child index
            if (node->right) q.push({node->right, 2 * index + 1}); // Right child index
        }

        // Update maxWidth for the current level
        maxWidth = max(maxWidth, lastIndex - firstIndex + 1);
    }

    return maxWidth;
}

// Function to create a sample binary tree
void createSampleTree(Node*& root) {
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
}

// Main function
int main() {
    Node* root = nullptr;
    
    // Create a sample binary tree
    createSampleTree(root);

    // Calculate and display the maximum width of the binary tree
    int width = maxWidth(root);
    cout << "Maximum Width of the Binary Tree: " << width << endl;

    return 0;
}
