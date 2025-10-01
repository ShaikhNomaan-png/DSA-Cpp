#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElementsII(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); // Initialize result with -1
    stack<int> s; // Stack to hold indices of the elements

    // Iterate through the array twice
    for (int i = 0; i < 2 * n; ++i) {
        int currentIndex = i % n; // Get the effective index (circular)

        // While stack is not empty and the current element is greater than the element at the index at the top of the stack
        while (!s.empty() && nums[currentIndex] > nums[s.top()]) {
            result[s.top()] = nums[currentIndex]; // Assign current element as the next greater
            s.pop(); // Remove the index from the stack
        }

        // Only push indices during the first pass to avoid stacking during the repeat pass
        if (i < n) {
            s.push(currentIndex);
        }
    }

    return result;
}

// Main function to demonstrate the Next Greater Element II
int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> result = nextGreaterElementsII(nums);
    
    // Output the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl; // Output will be 2 -1 2

    return 0;
}

/*  The Next Greater Element III (Next Greater Element II - II) problem continues the theme of finding the next greater elements in a circular array. In this variant, let's clarify a few things to ensure we focus properly on identifying the elements based on the requirements.
Problem Definition
Given an integer array nums, your task is to find the next greater element for each element in a circular manner. The next greater element for an element x is the first greater element on the right side of x in the array. If no such element exists, return -1 for that element.
Approach Using a Stack
This problem can be solved using a stack in a similar manner as with the previous Next Greater Element II problem. Here's how we can do it step by step:
1. Initialize:
Create a stack to keep track of indices of numbers for which we are yet to find the next greater number.
Create a results array (initialized to -1) to store the results.
2. Iterate:
Loop through the array twice (to simulate the circular nature).
For each element, compare it with the elements indexed in the stack:
While the stack is not empty and the current element is greater than the element in the array at the index on the top of the stack, pop the index from the stack and update the result for that index to the current element.
Push the current index onto the stack.
3.Final Step:
Return the result array after processing all elements.
*/