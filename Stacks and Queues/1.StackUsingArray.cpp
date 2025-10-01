/*   Stack
Definition:
A stack is a linear data structure that follows the Last In First Out (LIFO) principle.
 This means the last element added to the stack is the first one to be removed.
Characteristics:
Push: Add an element to the top of the stack.
Pop: Remove the top element from the stack.
Peek (Top): Return the top element without removing it.
A stack can grow and shrink as elements are added and removed, but in a static array implementation, the maximum size is predefined.
Implementation Using Array:
In an array-based implementation, a stack uses an array to store elements along with an integer variable (usually called top) that indicates the index of the topmost element in the stack.

cpp/c++
#define MAX 100 // Maximum size of the stack
int stack[MAX]; // Array to hold stack elements
int top = -1; // Indicates that the stack is empty
*/

#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of the stack

// Stack implementation using array
struct Stack {
    int arr[MAX];
    int top;

    Stack() {
        top = -1; // Initialize top to -1
    }

    bool isFull() {
        return top == MAX - 1; // Check if the stack is full
    }

    bool isEmpty() {
        return top == -1; // Check if the stack is empty
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value; // Push the value onto the stack
        cout << value << " pushed to stack" << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1; // Return -1 in case of underflow
        }
        return arr[top--]; // Pop the top value from the stack
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; // Return -1 if the stack is empty
        }
        return arr[top]; // Return the top value
    }
};

int main() {
    Stack stack;
    int choice, value, numToPop;

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Push operation
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2: // Pop operation
                cout << "How many values to pop? ";
                cin >> numToPop;
                for (int i = 0; i < numToPop; i++) {
                    int poppedValue = stack.pop();
                    if (poppedValue != -1) {
                        cout << "Popped: " << poppedValue << endl;
                    } else {
                        break; // If underflow occurs
                    }
                }
                break;

            case 3: // Peek operation
                cout << "Top element: " << stack.peek() << endl;
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
