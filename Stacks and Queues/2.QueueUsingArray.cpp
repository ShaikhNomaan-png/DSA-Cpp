/*Queue                                  //// if not run ctrl + C + enter
Definition:
A queue is a linear data structure that follows the First In First Out (FIFO) principle. 
This means the first element added to the queue is the first one to be removed.
Characteristics:
Enqueue: Add an element to the end of the queue.
Dequeue: Remove the front element from the queue.
Peek (Front): Return the front element without removing it.
Like the stack, a queue can dynamically change in size; however, in an array implementation, its size is fixed.
Implementation Using Array:
In an array-based implementation, a queue uses an array to store elements along with two integer variables (front and rear) that indicate the positions of the front and rear elements in the queue.

cpp/c++ 
#define MAX 100 // Maximum size of the queue
int queue[MAX]; // Array to hold queue elements
int front = 0; // Index of the front element
int rear = -1; // Index of the last element
int size = 0; // Current size of the queue
 
*/
#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of the queue

// Queue implementation using array
struct Queue {
    int arr[MAX];
    int front, rear, size;

    Queue() {
        front = 0; 
        rear = -1; 
        size = 0; // Initialize queue size
    }

    bool isFull() {
        return size == MAX; // Check if the queue is full
    }

    bool isEmpty() {
        return size == 0; // Check if the queue is empty
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rear = (rear + 1) % MAX; // Circular increment of rear
        arr[rear] = value; 
        size++; // Increase size
        cout << value << " enqueued to queue" << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1; // Return -1 in case of underflow
        }
        int value = arr[front]; 
        front = (front + 1) % MAX; // Circular increment of front
        size--; // Decrease size
        return value; // Return the dequeued value
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Return -1 if the queue is empty
        }
        return arr[front]; // Return the value at the front
    }
};

int main() {
    Queue queue;
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Enqueue operation
                cout << "Enter the value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;

            case 2: // Dequeue operation
                value = queue.dequeue();
                if (value != -1) {
                    cout << "Dequeued: " << value << endl;
                }
                break;

            case 3: // Peek operation
                cout << "Front element: " << queue.peek() << endl;
                break;

            case 4: // Exit
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}



/*   1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter your choice: 1
Enter the value to enqueue: 22
22 enqueued to queue

1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter your choice: 1
Enter the value to enqueue: 34
34 enqueued to queue

1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter your choice: 1
Enter the value to enqueue: 44
44 enqueued to queue

1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter your choice: 2
Dequeued: 22

1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter your choice: 3
Front element: 34

1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter your choice:                     */

