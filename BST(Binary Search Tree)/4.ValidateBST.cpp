/*Validating a Binary Search Tree (BST) involves checking whether the values of the nodes follow 
the BST properties. Specifically, for any given node, the values in its left subtree must be less than 
the node's value, and the values in its right subtree must be greater than the node's value.   */
// leetcode 98
#include <iostream>
#include <climits> // Include this for LONG_MIN and LONG_MAX
using namespace std;

// Definition of a Node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Helper function to validate the BST using recursion
bool isValidBST(Node* root, long minValue, long maxValue) {
    // An empty tree is a valid BST
    if (root == nullptr) {
        return true;
    }

    // Check the current node's value against the allowed range
    if (root->data <= minValue || root->data >= maxValue) {
        return false;
    }

    // Recursively validate the left and right subtree
    return isValidBST(root->left, minValue, root->data) &&
           isValidBST(root->right, root->data, maxValue);
}

// Function to start the validation from the root
bool validateBST(Node* root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
}

// Main function
int main() {
    // Create a binary search tree
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // Validate the BST
    if (validateBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    return 0;
}
