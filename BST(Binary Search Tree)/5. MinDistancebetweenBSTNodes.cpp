/*To find the minimum distance (or minimum difference) between any two nodes in a Binary Search Tree (BST),
 we can utilize the properties of the BST, particularly the in-order traversal, which visits the nodes in sorted order..   */
// leetcode 783
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Definition of a Node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Helper function to perform in-order traversal and store values in a vector
void inOrderTraversal(Node* root, vector<int>& values) {
    if (root == nullptr) return;

    inOrderTraversal(root->left, values);   // Visit left subtree
    values.push_back(root->data);            // Visit node
    inOrderTraversal(root->right, values);  // Visit right subtree
}

// Function to find the minimum distance between BST nodes
int minDistance(Node* root) {
    if (root == nullptr) return -1;  // Return -1 for an empty tree

    vector<int> values;
    inOrderTraversal(root, values);

    int minDiff = INT_MAX;
    
    // Calculate differences between consecutive elements
    for (size_t i = 1; i < values.size(); ++i) {
        minDiff = min(minDiff, values[i] - values[i - 1]);
    }

    return minDiff;
}

// Main function
int main() {
    // Creating a sample BST
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Finding the minimum distance between nodes
    int result = minDistance(root);
    
    cout << "The minimum distance between BST nodes is: " << result << endl;

    return 0;
}

    