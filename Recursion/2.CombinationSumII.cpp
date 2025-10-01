#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function for recursion
void backtrack(int start, int target, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current); // Found a valid combination
        return;
    }
    if (target < 0) {
        return; // Exceeded the target
    }

    for (int i = start; i < nums.size(); ++i) {
        // Skip duplicates
        if (i > start && nums[i] == nums[i - 1]) {
            continue; 
        }
        current.push_back(nums[i]); // Choose the number
        backtrack(i + 1, target - nums[i], nums, current, result); // Recur with the updated target
        current.pop_back(); // Backtrack
    }
}

// Main function to find all combinations
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
    vector<vector<int>> result; // To store all valid combinations
    vector<int> current; // To store the current combination
    backtrack(0, target, candidates, current, result); // Start the backtracking process
    return result;
}

// Main driver function for testing
int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> combinations = combinationSum2(candidates, target);
    
    cout << "Combinations that sum to " << target << ":\n";
    for (const auto& combination : combinations) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}

/*The Combination Sum II problem is similar to Combination Sum, but with the added constraint that each number in the candidates can only be used once. Additionally, the candidates may include duplicates, so we need to ensure that we do not count the same combination more than once.

Problem Statement
Given a collection of candidate numbers (candidates) and a target sum, you want to find all unique combinations in the candidates where the chosen numbers sum to the target. Each number can be used once and should handle duplicates correctly.

Example:
Input: candidates = [10, 1, 2, 7, 6, 1, 5], target = 8
Output: [[1, 1, 6], [1, 2, 5], [2, 6], [7]]

Explanation of the C++ Code
Backtracking Function:

Similar to the previous problem, but there's an added check to skip duplicates.
If the current number is the same as the previous (and it's not the starting point of the loop), it is skipped to avoid duplicate combinations.
Main Function:

The candidates are sorted to facilitate skipping duplicates, and the combination search starts.*/