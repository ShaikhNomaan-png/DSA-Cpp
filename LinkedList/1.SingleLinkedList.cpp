#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

// Singly Linked List class
class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() : head(nullptr) {}

    // Insertion Methods
    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            insertAtStart(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position is out of bounds." << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Deletion Methods
    void deleteAtStart() {
        if (!head) {
            cout << "List is empty. No deletion can be performed." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty. No deletion can be performed." << endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int position) {
        if (position < 0 || !head) {
            cout << "Invalid position or list is empty." << endl;
            return;
        }
        if (position == 0) {
            deleteAtStart();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (!temp || !temp->next) {
            cout << "Position is out of bounds." << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    // Traversing the list
    void traverse() {
        Node* temp = head;
        if (!temp) {
            cout << "The list is empty." << endl;
            return;
        }
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Searching in the list
    bool search(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    ~LinkedList() {
        while (head) {
            deleteAtStart();
        }
    }
};

// Main function to demonstrate the linked list operations
int main() {
    LinkedList list;

    // Inserting at the end
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "List after insertion at end: ";
    list.traverse();

    // Inserting at the start
    list.insertAtStart(5);
    cout << "List after insertion at start: ";
    list.traverse();

    // Inserting at a specific position
    list.insertAtPosition(15, 2);
    cout << "List after insertion at position 2: ";
    list.traverse();

    // Deleting from the start
    list.deleteAtStart();
    cout << "List after deletion at start: ";
    list.traverse();

    // Deleting from the end
    list.deleteAtEnd();
    cout << "List after deletion at end: ";
    list.traverse();

    // Deleting from a specific position
    list.deleteAtPosition(1);
    cout << "List after deletion at position 1: ";
    list.traverse();

    // Searching for a value
    int valueToSearch = 20;
    if (list.search(valueToSearch)) {
        cout << valueToSearch << " is found in the list." << endl;
    } else {
        cout << valueToSearch << " is not found in the list." << endl;
    }

    return 0;
}
/*  A linked list is a linear data structure where each element, called a node, contains a value and a reference (link) to the next node in the sequence. Unlike arrays, linked lists do not have a fixed size and can easily grow and shrink as needed. They are commonly used for their dynamic memory allocation properties and are efficient for certain operations, such as insertions and deletions.

Types of Linked Lists
Singly Linked List:

Each node contains data and a pointer to the next node.
Traversal is unidirectional (forward).
Operations such as insertion and deletion can be efficient, especially at the beginning.
Structure:

plaintext

[Data | Next] -> [Data | Next] -> [Data | Next] -> NULL
Doubly Linked List:

Each node contains data and two pointers: one to the next node and another to the previous node.
Supports bidirectional traversal (both forward and backward).
More complex than singly linked lists but allows easier deletion of nodes.
Structure:

plaintext

NULL <- [Prev | Data | Next] <-> [Prev | Data | Next] <-> [Prev | Data | Next] -> NULL
Circular Linked List:

The last node points back to the first node, creating a loop.
Can be singly or doubly linked.
Useful for applications where the list needs to be traversable repeatedly without restarting from the head.
Structure (Singly Circular):

plaintext

[Data | Next] -> [Data | Next] -> [Data | Next] -+
  ^                                                |
  +------------------------------------------------+
Structure (Doubly Circular):

plaintext

<-> [Prev | Data | Next] <-> [Prev | Data | Next] <-> [Prev | Data | Next] <-> 
Circular Doubly Linked List:

Each node has two pointers, allowing traversal in both directions, with both the last and the first node linking back to each other.
Useful for applications where both forward and backward traversal is needed, and repeated traversal is desired.
Basic Operations on Linked Lists
Insertion:

At the Beginning: Add a new node before the head.
At the End: Add a new node after the last node.
At a Specific Position: Insert a new node at a specific index.
Deletion:

From the Beginning: Remove the head node.
From the End: Remove the last node.
From a Specific Position: Remove a node at a specific index.
Traversal:

Forward Traversal: Visit nodes starting from the head to the end.
Backward Traversal: For doubly linked lists, starting from the last node back to the head.
Searching:

Find a node containing a specific value. This is typically done through linear traversal.
Reversal:

Reverse the linked list, changing the direction of the pointers.
Updating:

Change the value of an existing node.
Advantages of Linked Lists
Dynamic Size: Unlike arrays, linked lists can easily grow and shrink in size during runtime.
Efficient Insertion/Deletion: Inserting or deleting nodes can be done without the need to shift elements (as is required with arrays).
Disadvantages of Linked Lists
No Direct Access: Unlike arrays, linked lists do not allow random access to elements; traversal is required to reach a specific element.
Overhead: Each node requires extra memory for storing pointers/references.
Cache Locality: Arrays benefit from improved cache performance due to contiguous memory allocation.
*/

/*  How the Code Works
Node Structure: The Node struct has an integer data field and a pointer to the next node.
Linked List Class: The LinkedList class encapsulates operations on the list, maintaining a pointer to the head of the list.
Insertion:
insertAtStart: Adds a node at the beginning of the list.
insertAtEnd: Adds a node at the end of the list.
insertAtPosition: Inserts a node at a specific position in the list.
Deletion:
deleteAtStart: Removes the node at the beginning.
deleteAtEnd: Removes the node at the end.
deleteAtPosition: Deletes the node at a specific position.
Traversal: The traverse method prints the values of the nodes in the list.
Searching: The search method checks if a specific value exists in the list.
Destructor: The destructor cleans up the linked list when it goes out of scope.
Usage
In the main function, various operations are demonstrated to show how the linked list operates.

Conclusion
This implementation provides a basic structure for a singly linked list along with essential operations, making it suitable for understanding linked list manipulation in C++. You can use this as a foundation and expand upon it as needed.
*/