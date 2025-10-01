#include <iostream>
#include <vector>

using namespace std;

// Recursive function to check if a subset with given sum exists
bool subsetSumRec(const vector<int>& arr, int n, int target) {
    // Base cases
    if (target == 0) {
        return true; // A subset with sum zero is always possible (empty subset)
    }
    if (n == 0) {
        return false; // No elements left, and target is not zero
    }

    // If the last element is greater than the sum, ignore it
    if (arr[n - 1] > target) {
        return subsetSumRec(arr, n - 1, target);
    }

    // Otherwise, check if the target can be obtained by:
    // 1. including the last element
    // 2. excluding the last element
    return subsetSumRec(arr, n - 1, target) || 
           subsetSumRec(arr, n - 1, target - arr[n - 1]);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9; // Example target sum
    int n = arr.size();

    if (subsetSumRec(arr, n, target)) {
        cout << "Subset with the given sum is possible." << endl;
    } else {
        cout << "Subset with the given sum is not possible." << endl;
    }

    return 0;
}
