/*  The "Flatten Binary Tree to Linked List" problem involves transforming a given binary tree into a linked list 
following a specific order. The linked list should represent a preorder traversal of the binary tree.

*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to flatten the binary tree to a linked list
void flatten(Node* root, Node** prev) {
    if (!root) return;

    // Flatten the right subtree first
    flatten(root->right, prev);

    // Flatten the left subtree
    flatten(root->left, prev);

    // Set the current node's left to nullptr and right to the previous node
    root->right = *prev;
    root->left = nullptr;

    // Move the previous pointer to the current node
    *prev = root;
}

// Helper function to start flattening
void flattenBinaryTree(Node* root) {
    Node* prev = nullptr;
    flatten(root, &prev);
}

// Function to create a sample binary tree
void createSampleTree(Node*& root) {
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
}

// Function to print the flattened linked list
void printFlattenedList(Node* root) {
    while (root) {
        cout << root->data << " ";
        root = root->right; // Move to the next right node
    }
}

int main() {
    Node* root = nullptr;

    // Create a sample binary tree
    createSampleTree(root);

    // Flatten the binary tree to a linked list
    flattenBinaryTree(root);

    // Print the flattened linked list
    cout << "Flattened Binary Tree to Linked List: ";
    printFlattenedList(root);
    cout << endl;

    return 0;
}
