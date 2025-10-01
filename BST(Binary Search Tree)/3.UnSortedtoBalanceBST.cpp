/*Converting an unsorted array into a balanced Binary Search Tree (BST) is an important task in computer science,
 especially for applications that require efficient search, insertion, and deletion operations. A balanced BST
  maintains its height to be logarithmic relative to the number of nodes, allowing efficient operations.
Complexity Analysis
Time Complexity:
Sorting the array takes (O(n \log n)).
Building the BST takes (O(n)).
Space Complexity: The space complexity is (O(n)) because of the recursion stack.

*/

#include <iostream>
#include <vector>
#include <algorithm> // for std::sort

using namespace std;

// Definition of a Node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to build a balanced BST from a sorted array
Node* sortedArrayToBST(const vector<int>& arr, int start, int end) {
    if (start > end) return nullptr;

    // Find the middle element and make it the root
    int mid = start + (end - start) / 2;
    Node* root = new Node(arr[mid]);

    // Recursively build the left and right subtrees
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Function to print inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Main function
int main() {
    // Unsorted array
    vector<int> arr = {10, 5, 1, 7, 40, 50};

    // Sort the array
    sort(arr.begin(), arr.end());

    // Build BST from the sorted array
    Node* root = sortedArrayToBST(arr, 0, arr.size() - 1);

    // Print the inorder traversal of the balanced BST
    cout << "Inorder Traversal of the Balanced BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
