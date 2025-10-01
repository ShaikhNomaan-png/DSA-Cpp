/*Definition: Morris Inorder Traversal is a way to perform an inorder traversal of a binary tree without
 using a stack or recursion, hence achieving O(1) space complexity (not counting the output space).

Characteristics:
It temporarily modifies the tree structure by creating a temporary link (threading) to the previous node.
After the traversal, the original tree structure remains intact.
The traversal uses O(n) time and O(1) space.

*//*   Morris Inorder Traversal is an efficient algorithm for traversing a binary tree that eliminates the need
 for a stack or recursion. It achieves this by utilizing the tree's structure to temporarily store links to 
 the parent nodes.

*/
// Leetcode 94
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Morris Inorder Traversal function
void morrisInorderTraversal(Node* root) {
    Node* current = root;

    while (current) {
        if (current->left == nullptr) {
            // Visit the current node
            cout << current->data << " ";
            // Move to the right child
            current = current->right;
        } else {
            // Find the inorder predecessor of current
            Node* predecessor = current->left;
            while (predecessor->right && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                // Make a temporary connection to current
                predecessor->right = current;
                current = current->left;
            } else {
                // Restore the tree structure
                predecessor->right = nullptr;
                // Visit the current node
                cout << current->data << " ";
                // Move to the right child
                current = current->right;
            }
        }
    }
}

// Function to create a sample binary tree
void createSampleTree(Node*& root) {
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
}

// Main function
int main() {
    Node* root = nullptr;

    // Create a sample binary tree
    createSampleTree(root);

    // Perform Morris Inorder Traversal
    cout << "Morris Inorder Traversal: ";
    morrisInorderTraversal(root);
    cout << endl;

    return 0;
}
