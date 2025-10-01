#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long sumOfSubarrayRanges(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prevGreater(n), nextGreater(n), prevSmaller(n), nextSmaller(n);
    stack<int> s;

    // Find previous greater elements
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        prevGreater[i] = (s.empty()) ? -1 : s.top();
        s.push(i);
    }

    // Clear stack for next calculations
    while (!s.empty()) s.pop();

    // Find next greater elements
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            s.pop();
        }
        nextGreater[i] = (s.empty()) ? n : s.top();
        s.push(i);
    }

    // Clear stack for smaller calculations
    while (!s.empty()) s.pop();

    // Find previous smaller elements
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        prevSmaller[i] = (s.empty()) ? -1 : s.top();
        s.push(i);
    }

    // Clear stack for next smaller calculations
    while (!s.empty()) s.pop();

    // Find next smaller elements
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            s.pop();
        }
        nextSmaller[i] = (s.empty()) ? n : s.top();
        s.push(i);
    }

    long long totalRangeSum = 0;

    // Calculate total sum of ranges
    for (int i = 0; i < n; ++i) {
        long long maxContribution = (long long)(i - prevGreater[i]) * (nextGreater[i] - i) * arr[i];
        long long minContribution = (long long)(i - prevSmaller[i]) * (nextSmaller[i] - i) * arr[i];
        totalRangeSum += (maxContribution - minContribution);
    }

    return totalRangeSum;
}

// Main function to test the implementation
int main() {
    vector<int> arr = {1, 2, 3};
    long long result = sumOfSubarrayRanges(arr);

    cout << "Sum of Subarray Ranges: " << result << endl; // Expected output: 4

    return 0;
}

/* Efficient Approach
Utilization of Stacks:

Use two stacks to find the previous and next greater/smaller elements for each element in the array.
This enables quick determination of how many subarrays an element serves as the maximum or minimum.
Defining Contribution:

For each element, calculate:
How many subarrays it serves as the maximum.
How many times it serves as the minimum.
The contribution to the overall range sum can then be computed.
Steps to Solution
Calculate Next and Previous Elements:

For each element in the array:
Previous Greater Element (PGE): The last index where the element exceeds the current element.
Next Greater Element (NGE): The next index where the element exceeds the current element.
Previous Smaller Element (PSE): The last index where the element is less than the current element.
Next Smaller Element (NSE): The next index where the element is less than the current element.
Formula for Contributions:

For each element (arr[i]):
Maximum Contribution: [ \text{maxContribution} = arr[i] \times (i - \text{PGE}[i]) \times (\text{NGE}[i] - i) ]
Minimum Contribution: [ \text{minContribution} = arr[i] \times (i - \text{PSE}[i]) \times (\text{NSE}[i] - i) ]
The overall contribution for (arr[i]) to the total range sum is: [ \text{Total Contribution} = \text{maxContribution} - \text{minContribution} ]
Summing Contributions:

Iterate through the array and sum the contributions for each element.
*/