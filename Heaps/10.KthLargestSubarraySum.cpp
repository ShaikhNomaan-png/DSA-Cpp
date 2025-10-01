#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthLargestSubarraySum(const vector<int>& nums, int K) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap

    int n = nums.size();

    // Step 1: Calculate all subarray sums
    for (int start = 0; start < n; ++start) {
        int sum = 0; // Sum for the current subarray starting at 'start'
        for (int end = start; end < n; ++end) {
            sum += nums[end]; // Calculate the sum of the current subarray
            
            // Step 2: Maintain a min-heap of size K for K largest sums
            if (minHeap.size() < K) {
                minHeap.push(sum);
            } else if (sum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(sum);
            }
        }
    }

    // The Kth largest sum will be at the root of the min-heap
    return minHeap.top();
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int K = 2; // Find the 2nd largest subarray sum

    int result = kthLargestSubarraySum(nums, K);
    cout << "The " << K << "th largest subarray sum is: " << result << endl;

    return 0;
}

/*  Explanation of the Code
Min-Heap: A min-heap is utilized to maintain the top K largest subarray sums. It allows for efficient retrieval and management of these sums.

Nested Loops for Subarrays: Two loops (start and end) iterate through the array, calculating the sum of subarrays that start at index start and end at index end.

Heap Operations:

If the heap size is less than K, the current subarray sum is added.
If the heap size has reached K, we compare the current sum with the smallest sum in the heap. If the current sum is larger, we replace the smallest sum.
Final Result: The top of the min-heap (minHeap.top()) will give the Kth largest subarray sum after processing all possible sums.

Complexity
Time Complexity: The approach requires (O(n^2)) for generating all subarray sums, where (n) is the size of the input array. Each sum operation and heap operation is relatively constant due to the fixed size of K.
Space Complexity: The space complexity is (O(K)) for storing the K largest sums in the min-heap.
Example
For the input array {1, 2, 3, 4, 5} and (K = 2):

Possible subarray sums include:
text

1, 3 (1+2), 6 (1+2+3), 10 (1+2+3+4), 15 (1+2+3+4+5)
, etc.
The Kth largest sums would eventually lead to identifying the 2nd largest subarray sum, which is 14 (subarray = [4, 5]).
This algorithm efficiently computes the desired Kth largest sum by maintaining a fixed-size heap of sums encountered during the calculations.
*/