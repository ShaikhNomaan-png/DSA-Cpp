#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to rotate the linked list
Node* rotate(Node* head, int k) {
    if (!head || !head->next || k == 0) return head; // Edge cases

    // Step 1: Find the length of the list
    int length = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Step 2: Normalize k
    k = k % length;
    if (k == 0) return head; // If k is a multiple of length, no rotation needed

    // Step 3: Find the new tail: (length - k - 1)th node
    Node* newTail = head;
    for (int i = 0; i < length - k - 1; i++) {
        newTail = newTail->next;
    }

    // Step 4: Set the new head and tail
    Node* newHead = newTail->next;
    newTail->next = nullptr; // Break the link
    tail->next = head; // Connect the end of the list to the old head

    return newHead; // Return the new head of the list
}

// Function to insert a new node at the end
Node* insert(Node* head, int value) {
    Node* newNode = new Node(value);
    if (!head) return newNode; // Empty list

    Node* tail = head;
    while (tail->next) {
        tail = tail->next; // Find the last node
    }
    tail->next = newNode; // Attach the new node
    return head; // Return head of the list
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
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);

    cout << "Original List: ";
    printList(head);

    int k = 3; // Rotate the list by 2
    head = rotate(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}
