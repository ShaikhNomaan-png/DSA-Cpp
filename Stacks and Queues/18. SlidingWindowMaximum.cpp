#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> slidingWindowMaximum(const vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq; // Deque to store indices of elements

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices that are out of the current window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        // Remove elements from back that are less than the current element
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        // Add current index to the deque
        dq.push_back(i);
        
        // Record the maximum of the current window
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> maxInWindows = slidingWindowMaximum(nums, k);
    
    cout << "Sliding window maximums are: ";
    for (int max : maxInWindows) {
        cout << max << " "; // Expected output: 3 3 5 5 6 7
    }
    cout << endl;
    return 0;
}
