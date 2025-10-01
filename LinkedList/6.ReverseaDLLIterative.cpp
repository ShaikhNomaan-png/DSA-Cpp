#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to reverse a doubly linked list iteratively
Node* reverseIterative(Node* head) {
    if (!head) return nullptr;
    Node* temp = nullptr;
    Node* current = head;

    // Swap next and prev for all nodes in DLL
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node (which is previous after swap)
    }

    // Return the new head which is the last processed node
    return temp ? temp->prev : head;
}

// Function to create and return a new node
Node* insert(Node* head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        return newNode;
    }
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
    return head;
}

// Function to print the list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);

    cout << "Original list: ";
    printList(head);

    head = reverseIterative(head);
    cout << "Reversed list (Iterative): ";
    printList(head);

    return 0;
}
