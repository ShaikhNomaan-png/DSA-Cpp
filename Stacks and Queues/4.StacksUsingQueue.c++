#include <iostream>
#include <queue>
using namespace std;

// Function to push an element onto the stack
void push(queue<int>& q, int x) {
    // Step 1: Add the new element to the queue
    q.push(x);
    int size = q.size();

    // Step 2: Rotate the queue so that the new element is at the front
    for (int i = 0; i < size - 1; i++) {
        q.push(q.front());
        q.pop();
    }
}

// Function to pop the top element from the stack
int pop(queue<int>& q) {
    if (q.empty()) {
        cout << "Stack is empty." << endl;
        return -1; // Underflow case
    }
    int topValue = q.front();
    q.pop();
    return topValue;
}

// Function to get the top element of the stack
int top(queue<int>& q) {
    if (q.empty()) {
        cout << "Stack is empty." << endl;
        return -1; // Underflow case
    }
    return q.front();
}

// Function to check if the stack is empty
bool isEmpty(queue<int>& q) {
    return q.empty();
}

// Function to get the size of the stack
int size(queue<int>& q) {
    return q.size();
}

// Main function
int main() {
    queue<int> q;
    int choice, value;

    do {
        cout << "\nStack Operations using Single Queue:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Get Top\n";
        cout << "4. Check if Empty\n";
        cout << "5. Get Size\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(q, value);
                break;
            case 2:
                value = pop(q);
                if (value != -1) {
                    cout << "Popped element: " << value << endl;
                }
                break;
            case 3:
                value = top(q);
                if (value != -1) {
                    cout << "Top element is: " << value << endl;
                }
                break;
            case 4:
                if (isEmpty(q)) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 5:
                cout << "Current stack size: " << size(q) << endl;
                break;
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}



/*
Stack Operations using Single Queue:
1. Push
2. Pop
3. Get Top
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 1
Enter value to push: 12

Stack Operations using Single Queue:
1. Push
2. Pop
3. Get Top
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 5
Current stack size: 1

Stack Operations using Single Queue:
1. Push
2. Pop
3. Get Top
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 1
Enter value to push: 23

Stack Operations using Single Queue:
1. Push
2. Pop
3. Get Top
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 1
Enter value to push: 55

Stack Operations using Single Queue:
1. Push
2. Pop
3. Get Top
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 5
Current stack size: 3

Stack Operations using Single Queue:
1. Push
2. Pop
3. Get Top
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 3
Top element is: 55

Stack Operations using Single Queue:
1. Push
2. Pop
3. Get Top
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 2
Popped element: 55

Stack Operations using Single Queue:
1. Push
2. Pop
3. Get Top
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: */