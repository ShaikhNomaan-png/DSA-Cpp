#include <iostream>

using namespace std;

// Node structure for circular doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Circular Doubly Linked List class
class CircularDoublyLinkedList {
private:
    Node* head;

public:
    CircularDoublyLinkedList() : head(nullptr) {}

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
        cout << "Inserted " << value << " at the beginning." << endl;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
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
        if (!temp) {
            cout << "Position is out of bounds. No insertion performed." << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
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
            Node* tail = head->prev;
            Node* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
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
        Node* tail = head->prev;
        tail->prev->next = head;
        head->prev = tail->prev;
        delete tail;
        cout << "Deleted node from the end." << endl;
    }

    // Delete from a given position
    void deleteFromPosition(int position) {
        if (position == 0) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position && temp != nullptr; i++) {
            temp = temp->next;
            if (temp == head) {
                cout << "Position is out of bounds. No deletion performed." << endl;
                return;
            }
        }
        if (!temp) {
            cout << "Position is out of bounds. No deletion performed." << endl;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
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
                return true; // Found
            }
            temp = temp->next;
        } while (temp != head);
        return false; // Not found
    }

    // Destructor to free memory
    ~CircularDoublyLinkedList() {
        while (head) {
            deleteFromBeginning(); // Clean up the list
        }
    }
};

// Testing the circular doubly linked list
int main() {
    CircularDoublyLinkedList list;

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
Node Structure: Each node (Node) contains data, a pointer to the next node, and a pointer to the previous node.
CircularDoublyLinkedList Class:
Insertion Methods: Includes functions for inserting nodes at the start, end, and a specified position.
Deletion Methods: Includes functions for deleting nodes from the start, end, and a specified position.
Traversal: The traverse function outputs the elements of the list.
Search Function: The search function checks if a given value exists in the list.
Destructor: Cleans up the allocated memory to prevent memory leaks.
*/