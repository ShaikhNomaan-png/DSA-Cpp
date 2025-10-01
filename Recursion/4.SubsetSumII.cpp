#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function for backtracking
void findSubsets(int index, int target, const vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    // If we reach the target
    if (target == 0) {
        result.push_back(current);
        return;
    }

    // If we reach the end of the array
    if (index >= nums.size()) {
        return;
    }

    // Choose the current element
    current.push_back(nums[index]);
    findSubsets(index + 1, target - nums[index], nums, current, result);
    current.pop_back(); // Backtrack

    // Skip duplicates
    while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
        index++;
    }

    // Don't choose the current element
    findSubsets(index + 1, target, nums, current, result);
}

vector<vector<int>> subsetSumII(vector<int>& nums, int target) {
    vector<vector<int>> result;
    vector<int> current;

    // Sort the input to handle duplicates
    sort(nums.begin(), nums.end());

    findSubsets(0, target, nums, current, result);
    return result;
}

int main() {
    vector<int> nums = {10, 7, 2, 5, 3, 3};
    int target = 15; // Example target sum

    vector<vector<int>> result = subsetSumII(nums, target);

    cout << "Subsets with the given sum are:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}

/*  The Subset Sum II problem is a variation of the Subset Sum problem which allows for duplicate elements in the input set, meaning you need to ensure that you account for all unique subsets that sum to the target without counting duplicates.

Problem Statement
Given a set of integers that may contain duplicates and a target sum, determine all unique subsets that sum to the target.

Recursive Approach with Backtracking
The recursive approach involves exploring each number in the list and deciding whether to include it in the current subset. To handle duplicates, we need to ensure that we don't consider the same number at the same recursive level more than once.

*/