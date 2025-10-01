#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> previousSmallerElements(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); // Initialize result with -1
    stack<int> s; // Stack to hold indices of the elements

    // Iterate over the elements in the array
    for (int i = 0; i < n; ++i) {
        // While the stack is not empty and the current element is less than or equal to 
        // the element at the index at the top of the stack
        while (!s.empty() && nums[i] <= nums[s.top()]) {
            s.pop(); // Pop the larger element from the stack
        }
        
        // If there's any element left in the stack, it's the previous smaller element
        if (!s.empty()) {
            result[i] = nums[s.top()]; // Assign the previous smaller element
        }

        s.push(i); // Push the current index onto the stack
    }

    return result; // Return the final result
}

// Main function to demonstrate the Previous Smaller Element
int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = previousSmallerElements(nums);
    
    // Output the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl; // Expected output: -1 4 -1 2 2

    return 0;
}


/*  The Previous Smaller Element problem requires finding the previous smaller element for each element in an array. If no smaller element exists, the output should be -1 for that position. This problem can be efficiently solved using a stack, similar to how we handle the Next Greater and Previous Greater problems.
Approach Using a Stack
The strategy involves iterating through the array and maintaining a stack that helps track the indices of elements in a way that we can easily find the previous smaller element.
Steps
1.  Initialize:
Create a result array initialized to -1 (indicating no previous smaller element).
Use a stack to hold the indices of the elements.
2. Iterate Over the Array:
For each element:
While the stack is not empty and the current element is less than or equal to the element at the index stored at the top of the stack, pop the stack.
If the stack is not empty after this, the top of the stack will be the index of the previous smaller element; assign this element to the result array.
Push the current index onto the stack.
3.  Return the Result: After completing the iterations, return the result array  */