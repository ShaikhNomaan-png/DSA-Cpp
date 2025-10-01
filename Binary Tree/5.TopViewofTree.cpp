/*    The "top view" of a binary tree refers to the nodes visible when the tree is viewed from the top.
 This means that for each vertical line, we only see the first node encountered when moving from 
 the top of the tree to the bottom.

To implement the top view of a binary tree in C++, we can use a level-order traversal (BFS) along with
 a map to track the first node encountered in each vertical level.


*/
#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to get the top view of the binary tree
void topView(TreeNode* root) {
    if (root == nullptr) return;

    // Map to store the first node at each horizontal distance
    map<int, int> topNodeMap; // key: horizontal distance, value: node value
    queue<pair<TreeNode*, int>> q; // queue to perform level order traversal
    q.push({root, 0}); // start with root at horizontal distance 0

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        
        TreeNode* node = front.first;
        int hd = front.second; // horizontal distance

        // If there's no entry for this horizontal distance, add the node
        if (topNodeMap.find(hd) == topNodeMap.end()) {
            topNodeMap[hd] = node->val; // storing the first node at this distance
        }

        // Move to the left and right children
        if (node->left) {
            q.push({node->left, hd - 1}); // left child at hd - 1
        }
        if (node->right) {
            q.push({node->right, hd + 1}); // right child at hd + 1
        }
    }

    // Print the top view
    for (const auto& it : topNodeMap) {
        cout << it.second << " ";
    }
    cout << endl;
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
    cout << "Top view of the binary tree: ";
    topView(root); // Function call to print the top view
    return 0;
}
