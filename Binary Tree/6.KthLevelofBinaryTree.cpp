/*   To retrieve the nodes at the ( k )-th level of a binary tree, we can perform a level-order traversal (BFS).
 At each level, we can determine if we have reached the desired level ( k ) and then collect the nodes 
 at that level.

Here’s how you can implement the function to print the nodes at the ( k )-th level of a binary tree in C++ 
using the std namespace:
*/
// without Queue

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to print the nodes at the k-th level
void printKLevel(TreeNode* root, int k) {
    if (root == nullptr) return; // Base case: if the node is null, do nothing
    
    if (k == 1) {
        // If we reach the k-th level, print the node value
        cout << root->val << " ";
    } else {
        // Recur for the left and right children, decreasing k
        printKLevel(root->left, k - 1);
        printKLevel(root->right, k - 1);
    }
}

// Helper function to create a sample tree
void createSampleTree(TreeNode*& root) {
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
}

int main() {
    TreeNode* root = nullptr;
    createSampleTree(root);
    
    int k = 3; // Change this value to get different levels
    cout << "Nodes at level " << k << ": ";
    printKLevel(root, k); // Call the function to print the k-th level
    cout << endl;

    // Cleanup (deleting nodes) would be necessary here in real code to avoid memory leaks

    return 0;
}

// Using Queue of k^th Level
/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to print the k-th level of the binary tree
void printKthLevel(TreeNode* root, int k) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);
    
    int currentLevel = 1;

    while (!q.empty()) {
        int levelSize = q.size();
        
        // If we reach the k-th level, print the nodes
        if (currentLevel == k) {
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                cout << node->val << " ";
                q.pop();
            }
            cout << endl; // New line after printing the k-th level
            return; // Exit after printing, since we only want the k-th level
        }

        // Process nodes of the current level
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            // Add left and right children to the queue
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }

        // Move to the next level
        currentLevel++;
    }

    // If we get here, it means k was greater than the height of the tree
    cout << "Level " << k << " does not exist in the tree." << endl;
}

// Helper function to create a sample tree
void createSampleTree(TreeNode*& root) {
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
}

int main() {
    TreeNode* root = nullptr;
    createSampleTree(root);

    int k;
    cout << "Enter level to print: ";
    cin >> k; // input level to print
    cout << "Nodes at level " << k << ": ";
    printKthLevel(root, k); // Function call to print the k-th level

    return 0;
}


*/