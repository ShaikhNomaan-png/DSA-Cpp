#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long sumOfSubarrayMinimums(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prev(n), next(n);
    stack<int> s;

    // Calculate the previous smaller element indices
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        prev[i] = (s.empty()) ? -1 : s.top();
        s.push(i);
    }

    // Clear the stack to reuse for next smaller elements
    while (!s.empty()) s.pop();

    // Calculate the next smaller element indices
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            s.pop();
        }
        next[i] = (s.empty()) ? n : s.top();
        s.push(i);
    }

    // Calculate the sum of subarray minimums
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long count = (i - prev[i]) * (next[i] - i);
        sum += arr[i] * count;
    }

    return sum;
}

// Main function to demonstrate the implementation
int main() {
    vector<int> arr = {3, 1, 2, 4};
    long long result = sumOfSubarrayMinimums(arr);
    
    cout << "Sum of Subarray Minimums: " << result << endl; // Expected output: 17

    return 0;
}

/*Explanation of the Code
Initialization:

The prev and next vectors hold the indices of the previous and next smaller elements, respectively.
Previous Smaller Element Calculation:

The first loop finds the index of the nearest smaller element to the left of each element.
Next Smaller Element Calculation:

The second loop finds the index of the nearest smaller element to the right of each element.
Calculating Total Sum:

For each element, compute how many subarrays have that element as the minimum using the counts derived from the indices of the previous and next smaller elements.
Multiply each element by its count and accumulate the result.
Output:

The result is printed, giving you the total sum of the minimums of all subarrays.
Complexity Analysis
Time Complexity: (O(n)) for both finding previous and next smaller elements and calculating the result, resulting in an overall time complexity of (O(n)).
Space Complexity: (O(n)) for storing the indices of the previous and next smaller elements.
Example
For the array {3, 1, 2, 4}, the expected output will be 17:

Subarrays and their minimums:
[3] → 3
[3, 1] → 1
[3, 1, 2] → 1
[3, 1, 2, 4] → 1
[1] → 1
[1, 2] → 1
[1, 2, 4] → 1
[2] → 2
[2, 4] → 2
[4] → 4
The sum of all minimums: 3 + 1 + 1 + 1 + 1 + 1 + 1 + 2 + 2 + 4 = 17.
*//*The Sum of Subarray Minimum problem involves calculating the sum of the minimums of all possible subarrays in a given array. This problem can be efficiently solved using a stack to maintain the indices of elements in a way that allows us to find the minimums of all subarrays quickly.

Problem Explanation
Given an array, we want to compute the following:

For each element in the array, determine how many subarrays exist where that element is the minimum value.
Calculate the contribution of that element (the minimum) to the total sum based on the number of such subarrays.
Approach Using a Stack
To efficiently find how many subarrays have each element as the minimum, we can use a stack to determine:

Next Smaller Element to the right.
Previous Smaller Element to the left.
Steps
Initialize:

Use a stack to keep track of indices of array elements.
Create two arrays (or vectors) to store the indices for the next and previous smaller elements.
Find Previous Smaller Element:

Traverse the array from left to right.
For each element, pop elements from the stack until you find a smaller element or the stack is empty. The top of the stack (if it's not empty) will be the index of the previous smaller element.
Find Next Smaller Element:

Traverse the array from right to left.
Use a similar process to keep track of the next smaller element for each element in the array.
Calculate Contributions:

For each element in the array, calculate how many subarrays it can be a minimum by using the indices of the previous and next smaller elements:
Let i be the current index of the element.
Let p be the previous smaller element index (or -1 if none exists).
Let n be the next smaller element index (or length of array if none exists).
The count of subarrays where element at i is the minimum is given by (i - p) * (n - i).
Multiply the element by its count and add to the total sum.
*/
