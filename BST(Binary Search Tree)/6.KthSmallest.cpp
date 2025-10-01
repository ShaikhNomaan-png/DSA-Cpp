/* To find the Kth smallest element in a Binary Search Tree (BST), we can utilize the properties of
 in-order traversal. In a BST, an in-order traversal visits the nodes in sorted order,
  meaning that the Kth node visited in this traversal is the Kth smallest element.  */
// leetcode 230
#include <iostream>
using namespace std;

// Definition of a Node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Helper function for in-order traversal to find Kth smallest
void inOrderHelper(Node* root, int& count, int K, int& result) {
    if (root == nullptr) return;

    // Traverse left subtree
    inOrderHelper(root->left, count, K, result);

    // Increment count when visiting a node
    count++;
    // Check if the current node is the Kth smallest
    if (count == K) {
        result = root->data;  // Assign the Kth smallest value
        return;               // Exit once we found it
    }

    // Traverse right subtree
    inOrderHelper(root->right, count, K, result);
}

// Function to find the Kth smallest element in the BST
int kthSmallest(Node* root, int K) {
    int count = 0;
    int result = -1;  // Default value if K is out of bounds
    inOrderHelper(root, count, K, result);
    return result;
}

// Main function
int main() {
    // Creating a sample BST
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    int K = 3; // Example: find the 3rd smallest element

    // Finding the Kth smallest element
    int result = kthSmallest(root, K);
    if (result != -1) {
        cout << "The " << K << "th smallest element in the BST is: " << result << endl;
    } else {
        cout << "The value of K is out of bounds." << endl;
    }

    return 0;
}
