#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to merge two sorted linked lists
Node* mergeTwoLists(Node* l1, Node* l2) {
    Node dummy(0); // Create a dummy node to ease merging
    Node* tail = &dummy; // Pointer to form the new list

    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1; // Attach l1 node
            l1 = l1->next;   // Advance l1
        } else {
            tail->next = l2; // Attach l2 node
            l2 = l2->next;   // Advance l2
        }
        tail = tail->next; // Advance the tail of the merged list
    }

    // If there are remaining nodes in either list, attach them
    if (l1) tail->next = l1;
    if (l2) tail->next = l2;

    return dummy.next; // Return head of the merged list
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
    Node* l1 = nullptr;
    l1 = insert(l1, 1);
    l1 = insert(l1, 3);
    l1 = insert(l1, 5);

    Node* l2 = nullptr;
    l2 = insert(l2, 2);
    l2 = insert(l2, 4);
    l2 = insert(l2, 6);

    cout << "List 1: ";
    printList(l1);
    
    cout << "List 2: ";
    printList(l2);

    Node* mergedList = mergeTwoLists(l1, l2);
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
