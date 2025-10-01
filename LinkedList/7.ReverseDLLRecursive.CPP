#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to reverse the linked list recursively
Node* reverseRecursive(Node* head) {
    // Base case: if the list is empty or has only one node
    if (!head || !head->next) {
        return head; // Return new head
    }

    // Recursive call to reverse the rest of the list
    Node* newHead = reverseRecursive(head->next);

    // Adjust the pointers
    head->next->next = head; // Make the next node point to the current head
    head->next = nullptr;     // Set current node's next to null (it will be the new tail)
    
    return newHead; // Return the new head of the reversed list
}

// Function to insert a new node at the end
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
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements into the linked list
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);


    cout << "Original list: ";
    printList(head);
    
    // Reverse the linked list
    head = reverseRecursive(head);
    cout << "Reversed list (Recursive): ";
    printList(head);

    return 0;
}
