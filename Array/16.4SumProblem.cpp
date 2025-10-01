#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    
    for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // Skip duplicate for i
        
        for (int j = i + 1; j < n; ++j) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue; // Skip duplicate for j
            
            long long need = (long long)target - nums[i] - nums[j]; // Required sum for two additional numbers
            int l = j + 1, r = n - 1;
            
            while (l < r) {
                long long sum = (long long)nums[l] + nums[r];
                
                if (sum == need) {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) ++l; // Skip duplicates for l
                    while (l < r && nums[r] == nums[r - 1]) --r; // Skip duplicates for r
                    ++l; --r; // Move to next possible pair
                } else if (sum < need) {
                    ++l; // Increase sum
                } else {
                    --r; // Decrease sum
                }
            }
        }
    }
    
    return res;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2, 0, 1, 2, -1, -4, 2, 3, 0, 1, 2, 3, 6};
    int target = 9;
    auto ans = fourSum(nums, target);
    
    cout << "Quadruplets that sum to " << target << ":\n";
    for (auto &q : ans) {
        cout << "[";
        for (int i = 0; i < (int)q.size(); ++i) {
            cout << q[i] << (i + 1 == (int)q.size() ? "" : ", ");
        }
        cout << "]\n";
    }

    return 0;
}
