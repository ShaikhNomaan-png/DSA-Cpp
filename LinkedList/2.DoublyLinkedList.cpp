#include <iostream>

using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Insertion Methods
    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << value << " at the start." << endl;
        traverseForward();
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Inserted " << value << " at the end." << endl;
        traverseForward();
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
        if (!temp) {
            cout << "Position is out of bounds. Position not inserted." << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << position << "." << endl;
        traverseForward();
    }

    // Deletion Methods
    void deleteAtStart() {
        if (!head) {
            cout << "List is empty. No deletion can be performed." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete temp;
        cout << "Deleted node at the start." << endl;
        traverseForward();
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty. No deletion can be performed." << endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            cout << "Deleted node at the end." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
        cout << "Deleted node at the end." << endl;
        traverseForward();
    }

    void deleteAtPosition(int position) {
        if (position < 0 || !head) {
            cout << "Invalid position or list is empty. No deletion can be performed." << endl;
            return;
        }
        if (position == 0) {
            deleteAtStart();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position is out of bounds. No deletion performed." << endl;
            return;
        }
        if (temp->prev) {
            temp->prev->next = temp->next;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        delete temp;
        cout << "Deleted node at position " << position << "." << endl;
        traverseForward();
    }

    // Traversing the list
    void traverseForward() {
        Node* temp = head;
        cout << "Current list (forward): ";
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

    // Destructor to clean up the linked list
    ~DoublyLinkedList() {
        while (head) {
            deleteAtStart();
        }
    }
};

// Main function to demonstrate the doubly linked list operations
int main() {
    DoublyLinkedList list;

    // Inserting at the end
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    cout << "List after insertion at end: ";
    list.traverseForward();

    // Inserting at the start
    list.insertAtStart(5);
    cout << "List after insertion at start: ";
    list.traverseForward();

    // Inserting at a specific position
    list.insertAtPosition(15, 2);
    cout << "List after insertion at position 2: ";
    list.traverseForward();

    // Deleting from the start
    list.deleteAtStart();
    cout << "List after deletion at start: ";
    list.traverseForward();

    // Deleting from the end
    list.deleteAtEnd();
    cout << "List after deletion at end: ";
    list.traverseForward();

    // Deleting from a specific position
    list.deleteAtPosition(1);
    cout << "List after deletion at position 1: ";
    list.traverseForward();

    // Searching for a value
    int valueToSearch = 20;
    if (list.search(valueToSearch)) {
        cout << valueToSearch << " is found in the list." << endl;
    } else {
        cout << valueToSearch << " is not found in the list." << endl;
    }

    return 0;
}

/*  Doubly Linked List:

Each node contains data and two pointers: one to the next node and another to the previous node.
Supports bidirectional traversal (both forward and backward).
More complex than singly linked lists but allows easier deletion of nodes.
Structure:

plaintext

NULL <- [Prev | Data | Next] <-> [Prev | Data | Next]  <-> [Prev | Data | Next] -> NULL 
*/