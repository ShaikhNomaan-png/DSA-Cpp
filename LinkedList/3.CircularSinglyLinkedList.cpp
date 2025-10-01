#include <iostream>

using namespace std;

// Node structure for circular singly linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Circular Singly Linked List class
class CircularSinglyLinkedList {
private:
    Node* head;

public:
    CircularSinglyLinkedList() : head(nullptr) {}

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "Inserted " << value << " at the beginning." << endl;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted " << value << " at the end." << endl;
    }

    // Insert at a given position
    void insertAtPosition(int value, int position) {
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
            if (temp == head) {
                cout << "Position is out of bounds. No insertion performed." << endl;
                delete newNode;
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << position << "." << endl;
    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty. No deletion can be performed." << endl;
            return;
        }
        if (head->next == head) { // Only one node
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next; // Find the last node
            }
            temp->next = head->next;
            delete head;
            head = temp->next; // Move head to the next node
        }
        cout << "Deleted node from the beginning." << endl;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty. No deletion can be performed." << endl;
            return;
        }
        if (head->next == head) { // Only one node
            delete head;
            head = nullptr;
            cout << "Deleted node from the end." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next; // Find the second last node
        }
        delete temp->next; // Delete the last node
        temp->next = head; // Point the second last node to head
        cout << "Deleted node from the end." << endl;
    }

    // Delete from a given position
    void deleteFromPosition(int position) {
        if (position == 0) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
            if (temp == head) {
                cout << "Position is out of bounds. No deletion performed." << endl;
                return;
            }
        }
        if (temp->next == head) {
            cout << "Position is out of bounds. No deletion performed." << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next; // Bypass the node to delete
        delete nodeToDelete;
        cout << "Deleted node from position " << position << "." << endl;
    }

    // Traverse the list
    void traverse() {
        if (!head) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Current list: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Search for a value
    bool search(int value) {
        if (!head) {
            return false; // List is empty
        }
        Node* temp = head;
        do {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false; // Not found
    }

    // Destructor to free memory
    ~CircularSinglyLinkedList() {
        while (head) {
            deleteFromBeginning(); // Clean up the list
        }
    }
};

// Testing the circular singly linked list
int main() {
    CircularSinglyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.traverse();

    list.insertAtBeginning(5);
    list.traverse();

    list.insertAtPosition(15, 2);
    list.traverse();

    list.deleteFromBeginning();
    list.traverse();

    list.deleteFromEnd();
    list.traverse();

    list.deleteFromPosition(1);
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

/*  Code Explanation
Node Structure: Each node (Node) contains data and a pointer to the next node.
CircularSinglyLinkedList Class:
Insertions: Functions for inserting nodes at the start, end, and a specific position.
Deletions: Functions for deleting nodes from the start, end, and a specific position.
Traversal: The traverse function displays the elements of the list.
Search: The search function checks if a given value exists in the list.
Destructor: Cleans up allocated memory to prevent leaks.
Example Output
When you run this code, you may see output similar to this:

text

Inserted 10 at the end.
Inserted 20 at the end.
Inserted 30 at the end.
Current list: 10 20 30 
Inserted 5 at the beginning.
Current list: 5 10 20 30 
Inserted 15 at position 2.
Current list: 5 10 15 20 30 
Deleted node from the beginning.
Current list: 10 15 20 30 
Deleted node from the end.
Current list: 10 15 20 
Deleted node from position 1.
Current list: 10 20 
20 is found in the list.
This code performs all the required operations of a Circular Singly Linked List effectively. Let me know if you have any questions or need further modifications!
 */