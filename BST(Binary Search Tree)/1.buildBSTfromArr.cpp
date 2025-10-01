/*What is a Binary Search Tree (BST)?
A Binary Search Tree (BST) is a specialized tree data structure that maintains the following properties:

Node Structure: Each node has up to two children (left and right).
Ordering:
1.The left child's key is less than the parent's key.
2.The right child's key is greater than the parent's key.
3.No Duplicates: Generally, BSTs do not contain duplicate values

*/
#include <iostream>
#include <vector>

using namespace std;

// Definition of a Node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value); // Create a new node if the root is null
    }
    if (value < root->data) {
        root->left = insert(root->left, value); // Insert a value in the left subtree
    } else {
        root->right = insert(root->right, value); // Insert a value in the right subtree
    }
    return root;
}

// Function to create a BST from an array
Node* buildBSTFromArray(const vector<int>& arr) {
    Node* root = nullptr; // Start with an empty tree
    for (int value : arr) {
        root = insert(root, value); // Insert each value from the array
    }
    return root;
}

// Function to print inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left); // Visit left subtree
    cout << root->data << " "; // Visit node
    inorderTraversal(root->right); // Visit right subtree
}

// Main function
int main() {
    // Random array of integers
    vector<int> arr = {7, 2, 9, 1, 5, 8, 3, 66};

    // Build BST from the array
    Node* root = buildBSTFromArray(arr);

    // Print the inorder traversal of the BST
    cout << "Inorder Traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
