#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev; // New head of the reversed list
}

// Function to check if a linked list is a palindrome
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true; // Empty or single node list

    // Find the middle using slow and fast pointers
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    Node* secondHalf = reverseList(slow);
    Node* firstHalf = head;

    // Compare both halves
    bool result = true;
    while (secondHalf) {
        if (firstHalf->data != secondHalf->data) {
            result = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Restore the original list (optional)
    reverseList(slow); // Restore the second half back

    return result;
}

// Function to insert a new node at the end
Node* insert(Node* head, int value) {
    Node* newNode = new Node(value);
    if (!head) return newNode;
    
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
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);

    cout << "Linked List: ";
    printList(head);
    
    bool result = isPalindrome(head);
    cout << "Is Palindrome: " << (result ? "Yes" : "No") << endl;

    return 0;
}
/*  Checking if a linked list is a palindrome is a common problem that can be approached in different ways. Below are multiple methods to solve this problem, along with their implementations.

Problem Statement
A linked list is considered a palindrome if it reads the same forwards and backwards. For example, the list 1 -> 2 -> 3 -> 2 -> 1 is a palindrome, while 1 -> 2 -> 3 is not.

Multiple Approaches
Approach 1: Reversing the Second Half
Methodology:

Use the slow and fast pointer technique to find the middle of the linked list.
Reverse the second half of the list.
Compare the first half of the list with the reversed second half.
Restore the original list (if needed).
*/