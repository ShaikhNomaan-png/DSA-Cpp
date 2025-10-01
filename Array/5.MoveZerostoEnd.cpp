#include <iostream>
#include <vector>

using namespace std;

// Function to move all zeros to the end of the array
void moveZerosToEnd(vector<int>& nums) {
    int n = nums.size();
    int j = 0; // Pointer for the next position to place a non-zero element
    
    // Move non-zero elements to the front
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i]; // Place non-zero elements at the `j`th position
            j++; // Move the `j` pointer
        }
    }
    
    // Fill the remaining positions with zeros
    while (j < n) {
        nums[j] = 0;
        j++;
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 4, 0, 9, 0, 3, 12}; // Example array

    moveZerosToEnd(nums);

    cout << "Array after moving zeros to the end: ";
    for (const int& num : nums) {
        cout << num << " "; // Print the modified array
    }
    cout << endl;

    return 0;
}
