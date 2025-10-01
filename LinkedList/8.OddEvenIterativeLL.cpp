#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to rearrange the odd and even nodes
Node* oddEvenList(Node* head) {
    if (!head) return nullptr;  // Handle empty list

    Node* odd = head;        // Pointer for odd nodes
    Node* even = head->next; // Pointer for even nodes
    Node* evenHead = even;   // To connect at the end

    while (even && even->next) {
        odd->next = even->next; // Link odd nodes
        odd = odd->next;         // Move odd pointer
        even->next = odd->next;  // Link even nodes
        even = even->next;       // Move even pointer
    }

    odd->next = evenHead; // Connect odd list to even list
    return head;          // Return the head of the modified list
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
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);
    head = insert(head, 7);
    head = insert(head, 9);
    head = insert(head, 11);
    head = insert(head, 12);



    cout << "Original list: ";
    printList(head);
    
    head = oddEvenList(head);
    cout << "Rearranged list (Odd-Even): ";
    printList(head);

    return 0;
}
