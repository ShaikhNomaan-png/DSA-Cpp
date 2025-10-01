/*1. Search Operation
Algorithm to Search:
Start from the root.
If the node's value is equal to the search value, return the node.
If the search value is less than the node's value, search in the left subtree.
If the search value is greater, search in the right subtree.
2. Delete Operation
Algorithm to Delete:
Finding the Node:
Perform a search to find the node to be deleted.
Three Cases:
Node to be deleted is a leaf (no children): Simply remove it.
Node to be deleted has one child: Replace it with its child.
Node to be deleted has two children: Find its in-order predecessor (max value in the left subtree) or 
in-order successor (min value in the right subtree), copy its value to the node, and then delete the predecessor/successor.

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
        root->left = insert(root->left, value); // Insert in the left subtree
    } else {
        root->right = insert(root->right, value); // Insert in the right subtree
    }
    return root;
}

// Function to search a value in the BST
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false; // Value not found
    }
    if (root->data == value) {
        return true; // Value found
    } else if (value < root->data) {
        return search(root->left, value); // Search in left subtree
    } else {
        return search(root->right, value); // Search in right subtree
    }
}

// Function to find the minimum value node in the BST
Node* findMin(Node* root) {
    while (root && root->left) {
        root = root->left; // Go to the leftmost node
    }
    return root;
}

// Function to delete a value from the BST
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return nullptr; // Value not found
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value); // Delete in left subtree
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value); // Delete in right subtree
    } else {
        // Node to be deleted found
        if (root->left == nullptr) {
            Node* temp = root->right; // One child (right)
            delete root; // Free the memory
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left; // One child (left)
            delete root; // Free the memory
            return temp;
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(root->right);
            root->data = temp->data; // Copy the inorder successor's value to this node
            root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
        }
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
    Node* root = nullptr; // Start with an empty tree

    // Insert initial values into BST
    vector<int> initialValues = {7, 2, 9, 1, 5, 8, 3};
    for (int value : initialValues) {
        root = insert(root, value);
    }

    int option, value;
    do {
        cout << "\nBST Operations:\n";
        cout << "1. Search\n";
        cout << "2. Delete\n";
        cout << "3. Display (Inorder Traversal)\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1: // Search
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value)) {
                    cout << value << " is found in the BST.\n";
                } else {
                    cout << value << " is not found in the BST.\n";
                }
                break;
            case 2: // Delete
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                cout << value << " has been deleted from the BST if it existed.\n";
                break;
            case 3: // Display
                cout << "Inorder Traversal of the BST: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 4: // Exit
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option! Try again.\n";
        }
    } while (option != 4);

    return 0;
}


/*
BST Operations:
1. Search
2. Delete
3. Display (Inorder Traversal)
4. Exit
Choose an option: 3
Inorder Traversal of the BST: 1 2 3 5 7 8 9 

BST Operations:
1. Search
2. Delete
3. Display (Inorder Traversal)
4. Exit
Choose an option: 1
Enter value to search: 5
5 is found in the BST.

BST Operations:
1. Search
2. Delete
3. Display (Inorder Traversal)
4. Exit
Choose an option: 2
Enter value to delete: 7
7 has been deleted from the BST if it existed.

BST Operations:
1. Search
2. Delete
3. Display (Inorder Traversal)
4. Exit
Choose an option: 3
Inorder Traversal of the BST: 1 2 3 5 8 9 

BST Operations:
1. Search
2. Delete
3. Display (Inorder Traversal)
4. Exit
Choose an option:            */
