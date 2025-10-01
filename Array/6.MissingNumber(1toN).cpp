#include <iostream>
#include <vector>

using namespace std;

// Function to find the missing number
int findMissingNumber(const vector<int>& nums, int N) {
    // Calculate expected sum of numbers from 1 to N
    int expectedSum = N * (N + 1) / 2;
    
    // Calculate the actual sum of the array
    int actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }
    
    // The missing number is the difference between expected sum and actual sum
    return expectedSum - actualSum;
}

int main() {
    vector<int> nums = {3, 7, 1, 2, 8, 4}; // Example array
    int N = 8; // The value of N (1 to N)

    int missingNumber = findMissingNumber(nums, N);

    cout << "Missing Number: " << missingNumber << endl;

    return 0;
}
