#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> slidingWindowMaximum(const vector<int>& nums, int k) {
    vector<int> result;
    priority_queue<pair<int, int>> maxHeap; // Max-heap: stores pairs of (value, index)
    unordered_map<int, int> indexMap; // Track the count of elements in the heap

    for (int i = 0; i < nums.size(); i++) {
        // Step 1: Add current element to the max heap
        maxHeap.push({nums[i], i});
        indexMap[i] = nums[i]; // Keep track of indices
        
        // Step 2: Remove elements that are out of the current window
        if (i >= k - 1) {
            // Remove outdated elements from the heap
            while (!maxHeap.empty() && (maxHeap.top().second <= i - k)) {
                maxHeap.pop();
            }
            // The max element for the current window is at the top of the heap
            result.push_back(maxHeap.top().first);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3; // Window size

    vector<int> result = slidingWindowMaximum(nums, k);
    cout << "Sliding window maximums: ";
    for (int max : result) {
        cout << max << " ";
    }
    cout << endl;

    return 0;
}
/*  Example
For the input array {1, 3, -1, -3, 5, 3, 6, 7} with (k = 3):

The sliding windows (of size 3) are:
[1, 3, -1] → Max = 3
[3, -1, -3] → Max = 3
[-1, -3, 5] → Max = 5
[-3, 5, 3] → Max = 5
[5, 3, 6] → Max = 6
[3, 6, 7] → Max = 7
Result will be: 3, 3, 5, 5, 6, 7.

This demonstrates how to use a max-heap (priority queue) effectively for the sliding window maximum problem!
*/