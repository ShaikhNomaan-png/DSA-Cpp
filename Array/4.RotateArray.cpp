#include <iostream>
#include <vector>

using namespace std;

// Function to reverse a portion of the array
void reverse(vector<int>& nums, int left, int right) {
    while (left < right) {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

// Function to rotate the array to the right by k steps
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return;

    // Normalize k to avoid unnecessary rotations
    k = k % n;

    // Reverse the whole array
    reverse(nums, 0, n - 1);
    // Reverse the first k elements
    reverse(nums, 0, k - 1);
    // Reverse the remaining n - k elements
    reverse(nums, k, n - 1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Example array
    int k = 7; // Number of rotations

    rotate(nums, k);

    cout << "Rotated Array: ";
    for (const int& num : nums) {
        cout << num << " "; // Print the rotated array
    }
    cout << endl;

    return 0;
}
