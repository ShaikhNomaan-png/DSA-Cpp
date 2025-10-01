/* To find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree (BST), we can leverage the properties of the BST. The LCA of two nodes (P) and (Q) is the deepest node that is an ancestor of both (P) and (Q).
Approach
BST Properties:
If both (P) and (Q) are smaller than the current node, then the LCA lies in the left subtree.
If both (P) and (Q) are larger than the current node, then the LCA lies in the right subtree.
If one of them is smaller and the other is larger, the current node is the LCA. */
// leetcode 235
#include <iostream>
using namespace std;

// Definition of a Node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to find the Lowest Common Ancestor in the BST
Node* lowestCommonAncestor(Node* root, int P, int Q) {
    // Base case: if root is null, return null
    if (root == nullptr) {
        return nullptr;
    }

    // If both P and Q are smaller than root, LCA is in left subtree
    if (P < root->data && Q < root->data) {
        return lowestCommonAncestor(root->left, P, Q);
    }

    // If both P and Q are greater than root, LCA is in right subtree
    if (P > root->data && Q > root->data) {
        return lowestCommonAncestor(root->right, P, Q);
    }

    // If one is on one side and the other is on the other side, root is LCA
    return root;
}

// Main function
int main() {
    // Creating a sample BST
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    // Input values for P and Q
    int P, Q;
    cout << "Enter the values of P and Q: ";
    cin >> P >> Q;

    // Finding the Lowest Common Ancestor
    Node* ancestor = lowestCommonAncestor(root, P, Q);
    
    if (ancestor != nullptr) {
        cout << "The Lowest Common Ancestor of " << P << " and " << Q << " is: " << ancestor->data << endl;
    } else {
        cout << "One or both of the nodes are not in the BST." << endl;
    }

    return 0;
}

// output: Enter the values of P and Q: 7 8
//The Lowest Common Ancestor of 7 and 8 is: 8