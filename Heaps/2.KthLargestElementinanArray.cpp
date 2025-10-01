#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

int main() {
    vector<int> arr = {3,2,1,5,6,4};
    int k = 2;
    cout << "Kth Largest Element = " << findKthLargest(arr, k) << endl;
    return 0;
}
