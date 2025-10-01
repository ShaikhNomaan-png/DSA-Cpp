/* To construct a Binary Search Tree (BST) from its preorder traversal, you can follow the property that in a preorder traversal, the first element is always the root. All subsequent elements can be categorized as belonging to the left or right subtree based on their values compared to the root.
Steps to Construct BST from Preorder Traversal
1.Create the Root: The first element of the preorder list is the root of the BST.
2.Divide the Array: The remaining elements can be divided into two parts:
Elements less than the root belong to the left subtree.
Elements greater than the root belong to the right subtree.
3.Recursively Construct Subtrees: Recursively apply the above logic to the left and right subarrays.   */
//Leetcode 1008
#include <iostream>
#include <vector>
#include <climits>  // Include this header for INT_MIN and INT_MAX
using namespace std;

// Definition of a Node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new value into the BST, used for construction
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to construct a BST from preorder traversal
Node* constructBST(const vector<int>& preorder, int& index, int size, int min, int max) {
    // Base case for recursion
    if (index >= size) return nullptr;

    int key = preorder[index];

    // If key is out of the allowed range, return nullptr
    if (key < min || key > max) return nullptr;

    // Create a new node if key is within the range
    Node* root = new Node(key);
    index++; // Move to the next index in preorder

    // Construct the left and right subtrees recursively
    root->left = constructBST(preorder, index, size, min, key);
    root->right = constructBST(preorder, index, size, key, max);

    return root;
}

// Function to initiate BST construction
Node* constructBST(const vector<int>& preorder) {
    int index = 0;
    return constructBST(preorder, index, preorder.size(), INT_MIN, INT_MAX);
}

// Function to print the BST in-order (used for testing)
void printInOrder(Node* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

// Main function
int main() {
    vector<int> preorder = {10, 5, 1, 7, 40, 50};

    Node* root = constructBST(preorder);

    cout << "In-order traversal of the constructed BST: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
