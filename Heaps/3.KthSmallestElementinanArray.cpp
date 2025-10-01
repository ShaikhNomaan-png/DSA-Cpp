#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;
    for (int num : nums) {
        maxHeap.push(num);
        if (maxHeap.size() > k) maxHeap.pop();
    }
    return maxHeap.top();
}

int main() {
    vector<int> arr = {7,10,4,2,3,20,15};
    int k = 2;
    cout << "Kth Smallest Element = " << findKthSmallest(arr, k) << endl;
    return 0;
}
