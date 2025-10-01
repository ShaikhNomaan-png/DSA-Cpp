#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;  // Main stack to store all elements
    stack<int> minStack;   // Stack to keep track of the minimum elements

public:
    // Push a new value onto the stack
    void push(int val) {
        mainStack.push(val); // Push the value onto the main stack
        // If minStack is empty or the new value is less than or equal to the current minimum, push it onto minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    // Remove the top element from the stack
    void pop() {
        // If the top element of mainStack is the same as the top of minStack, pop from minStack as well
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop(); // Always pop from the main stack
    }

    // Get the top element of the stack
    int top() {
        return mainStack.top(); // Return the top of the main stack
    }

    // Get the minimum element in the stack
    int getMin() {
        return minStack.top(); // Return the top of the min stack
    }
};

// Main function to demonstrate the Min Stack
int main() {
    MinStack minStack;

    // Push elements onto the Min Stack
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    //minStack.push(-6);
    //minStack.push(-9);

    cout << "Minimum: " << minStack.getMin() << endl; // Returns -3
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;       // Returns 0
    cout << "Minimum: " << minStack.getMin() << endl; // Returns -2

    return 0;
}

/* ### Concept of Min Stack
A Min Stack is a data structure that supports standard stack operations (push, pop, and top) but also allows you to retrieve the minimum element in constant time \(O(1)\). We achieve this by using an additional stack to keep track of the minimum values.
### Data Structures Used
1. **Main Stack** (`mainStack`):
   - This stack holds all the elements pushed onto the Min Stack.
2. **Minimum Stack** (`minStack`):
   - This auxiliary stack holds the minimum values. Each time an element is pushed onto the `mainStack`, if it is the new minimum (less than or equal to the current minimum), it is also pushed onto `minStack`.
### Detailed Steps of the Algorithm
#### **1. Push Operation (`push(val)`)**
- **Purpose**: To add a new value to the stack.
- **Steps**:
  - Push the value onto `mainStack`.
  - Check if `minStack` is empty or if the new value is less than or equal to the current top of `minStack`.
    - If true, push the new value onto `minStack`.
**Example**: 
- Push -2 → `mainStack` = [-2], `minStack` = [-2]
- Push 0 → `mainStack` = [-2, 0], `minStack` = [-2]
- Push -3 → `mainStack` = [-2, 0, -3], `minStack` = [-2, -3]
#### **2. Pop Operation (`pop()`)**

- **Purpose**: To remove the top value from the stack.
- **Steps**:
  - Check if the top of `mainStack` is the same as the top of `minStack`.
    - If true, pop the top of `minStack` as well because the minimum value is being removed.
  - Pop the top element from `mainStack`.

**Example**:
- Before pop: `mainStack` = [-2, 0, -3], `minStack` = [-2, -3]
- Top of `mainStack` is -3 (same as the top of `minStack`), so:
  - Pop -3 from both stacks.
- After pop: `mainStack` = [-2, 0], `minStack` = [-2]

#### **3. Top Operation (`top()`)**

- **Purpose**: To retrieve the top value of the stack without removing it.
- **Steps**:
  - Return the top value from `mainStack`.

**Example**:
- If `mainStack` = [-2, 0], `top()` returns 0.

#### **4. Get Minimum Operation (`getMin()`)**

- **Purpose**: To retrieve the minimum value in the stack.
- **Steps**:
  - Return the top value from `minStack`.

**Example**:
- If `minStack` = [-2], `getMin()` returns -2.

### Summary of Algorithm's Efficiency

- **Time Complexity**:
  - All operations (push, pop, top, getMin) run in \(O(1)\) time, which means they execute in constant time regardless of the number of elements in the stack. This is one of the main advantages of using a Min Stack.

- **Space Complexity**:
  - The auxiliary stack `minStack` may, in the worst case, hold all the elements of `mainStack`. Thus, the space complexity is \(O(n)\), where \(n\) is the number of elements in the `mainStack`.

### Conclusion

The use of an auxiliary stack allows us to keep track of minimum values efficiently while maintaining the overall behavior of the stack. This approach makes it a powerful way to manage data where both stack and minimum retrieval operations are frequently required. If you have more specific questions about any part of the algorithm, feel free to ask!
*/