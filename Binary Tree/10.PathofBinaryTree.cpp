/*   The "Binary Tree Paths" topic generally deals with the problem of finding all root-to-leaf paths in 
a binary tree. For each node in the binary tree, if it is a leaf (i.e., it has no left or right children),
 the path from the root to that node is recorded. The paths are usually represented as strings or
  lists of node values.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to find all paths from root to leaves
void findPaths(Node* node, string currentPath, vector<string>& paths) {
    if (node == nullptr) return;

    // Append the current node's data to the current path
    currentPath += to_string(node->data);

    // Check if it's a leaf node
    if (node->left == nullptr && node->right == nullptr) {
        paths.push_back(currentPath); // Store the path
    } else {
        currentPath += "->"; // Add arrow for further nodes
        findPaths(node->left, currentPath, paths);
        findPaths(node->right, currentPath, paths);
    }
}

// Wrapper function to initiate path finding
vector<string> binaryTreePaths(Node* root) {
    vector<string> paths;
    findPaths(root, "", paths);
    return paths;
}

// Function to create a sample binary tree
void createSampleTree(Node*& root) {
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root ->right->left = new Node(7);
    root ->right->right = new Node(9);
    root ->right->left->left = new Node(8);

}

// Main function
int main() {
    Node* root = nullptr;
    
    // Create a sample binary tree
    createSampleTree(root);

    // Find all binary tree paths
    vector<string> paths = binaryTreePaths(root);

    // Display the paths
    cout << "Binary Tree Paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}
