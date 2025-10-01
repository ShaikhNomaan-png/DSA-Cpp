#include <iostream>
#include <stack>
using namespace std;

// Global stacks for queue functionality
stack<int> stack1;
stack<int> stack2;

// Function to transfer elements from stack1 to stack2
void transfer() {
    while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
    }
}

// Function to enqueue an element
void enqueue(int x) {
    stack1.push(x);
    cout << x << " has been added to the queue." << endl;
}

// Function to dequeue an element
int dequeue() {
    if (stack2.empty()) {
        if (stack1.empty()) {
            cout << "Queue is empty." << endl;
            return -1; // Underflow case
        }
        transfer(); // Move elements from stack1 to stack2
    }
    int frontValue = stack2.top();
    stack2.pop();
    return frontValue;
}

// Function to get the front element of the queue
int front() {
    if (stack2.empty()) {
        if (stack1.empty()) {
            cout << "Queue is empty." << endl;
            return -1; // Underflow case
        }
        transfer(); // Move elements if stack2 is empty
    }
    return stack2.top();
}

// Function to check if the queue is empty
bool isEmpty() {
    return stack1.empty() && stack2.empty();
}

// Function to get the size of the queue
int size() {
    return stack1.size() + stack2.size();
}

// Main function
int main() {
    int choice, value;

    do {
        cout << "\nQueue Operations using Stacks:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Get Front\n";
        cout << "4. Check if Empty\n";
        cout << "5. Get Size\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    cout << "Dequeued element: " << value << endl;
                }
                break;
            case 3:
                value = front();
                if (value != -1) {
                    cout << "Front element is: " << value << endl;
                }
                break;
            case 4:
                if (isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 5:
                cout << "Current queue size: " << size() << endl;
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

/*output:---------
Queue Operations using Stacks:
1. Enqueue
2. Dequeue
3. Get Front
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 1
Enter value to enqueue: 10
10 has been added to the queue.

Queue Operations using Stacks:
1. Enqueue
2. Dequeue
3. Get Front
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 1
Enter value to enqueue: 20
20 has been added to the queue.

Queue Operations using Stacks:
1. Enqueue
2. Dequeue
3. Get Front
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 3
Front element is: 10

Queue Operations using Stacks:
1. Enqueue
2. Dequeue
3. Get Front
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 4
Queue is not empty.

Queue Operations using Stacks:
1. Enqueue
2. Dequeue
3. Get Front
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 5
Current queue size: 2

Queue Operations using Stacks:
1. Enqueue
2. Dequeue
3. Get Front
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 1
Enter value to enqueue: 33
33 has been added to the queue.

Queue Operations using Stacks:
1. Enqueue
2. Dequeue
3. Get Front
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 5
Current queue size: 3

Queue Operations using Stacks:
1. Enqueue
2. Dequeue
3. Get Front
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 2
Dequeued element: 10

Queue Operations using Stacks:
1. Enqueue
2. Dequeue
3. Get Front
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 5
Current queue size: 2

Queue Operations using Stacks:
1. Enqueue
2. Dequeue
3. Get Front
4. Check if Empty
5. Get Size
0. Exit
Enter your choice: 
*/