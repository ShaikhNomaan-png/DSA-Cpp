#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to remove the Nth node from the end of the linked list
Node* removeNthFromEnd(Node* head, int n) {
    Node dummy(0); // Create a dummy node to handle edge cases (e.g., removing the head)
    dummy.next = head;
    Node* first = &dummy;
    Node* second = &dummy;

    // Move first pointer n + 1 steps ahead
    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }

    // Move both pointers until first pointer reaches the end
    while (first) {
        first = first->next;
        second = second->next;
    }

    // Remove the Nth node from the end
    second->next = second->next->next;

    return dummy.next; // Return the modified list
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

    int n = 2; // Remove the 2nd node from the end
    head = removeNthFromEnd(head, n);

    cout << "Modified List: ";
    printList(head);

    return 0;
}


// it will delete at backsize mean n=5 then 1 delete,, 
//n=4 then 2 delete