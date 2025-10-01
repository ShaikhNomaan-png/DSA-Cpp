#include <iostream>
#include <vector>

using namespace std;

// Function to remove duplicates from a sorted array
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0; // Return 0 if the array is empty
    }

    int j = 0; // Pointer to place the next unique element

    // Iterate through the array with the second pointer
    for (int i = 1; i < nums.size(); i++) {
        // If the current element is different from the last unique element
        if (nums[i] != nums[j]) {
            j++; // Move to the next unique position
            nums[j] = nums[i]; // Update the array
        }
    }

    // Return the new length of the array with unique elements
    return j + 1; // Length is j + 1
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5}; // Example sorted array

    int newLength = removeDuplicates(nums);

    cout << "The number of unique elements is: " << newLength << endl;
    cout << "The array after removing duplicates is: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " "; // Print the unique elements
    }
    cout << endl;

    return 0;
}
