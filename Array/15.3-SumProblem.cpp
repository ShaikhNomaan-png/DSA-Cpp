#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end()); // Sort the array
    vector<vector<int>> result;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate elements for the first number
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == k) {
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                // Skip duplicate elements for the second number
                while (left < right && nums[left] == nums[left - 1]) left++;
                // Skip duplicate elements for the third number
                while (left < right && nums[right] == nums[right + 1]) right--;
            } 
            else if (sum < k) {
                left++; // need a larger sum
            } 
            else {
                right--; // need a smaller sum
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4, 2,3,0,1,2,3,6};
    int k = 9; // You can change this to any integer value to find triplets that sum to k
    vector<vector<int>> triplets = threeSum(nums, k);
    
    cout << "Triplets that sum to " << k << " are: " << endl;
    for (const auto& triplet : triplets) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    return 0;
}

/*  Let's break down how the provided C++ code works step-by-step, focusing on the input given in the `main` function, `nums = {-1, 0, 1, 2, -1, -4, 2, 3, 0, 1, 2, 3, 6}` and `k = 11`.

### Code Execution Breakdown

1. **Input Initialization**:
   - The program initializes the vector `nums` containing thirteen integers and sets `k` to `11`.
   
2. **Sorting the Array**:
   - The line `sort(nums.begin(), nums.end());` sorts the array in ascending order:
   ```
   Sorted nums: [-4, -1, -1, 0, 0, 1, 1, 2, 2, 3, 3, 6]
   ```

3. **Finding Triples**:
   - A loop iterates through each element of the sorted array using index `i` for the first element of the triplet.
   - For every triplet, two pointers (`left` and `right`) are initialized to find potential pairs that sum with `nums[i]` to equal `k`.

### Key Points in the Logic

- **Outer Loop**: This runs from `0` to `n - 2`, ensuring there's always room to find two additional numbers to form a triplet.
- **Skipping Duplicates**: Prior to using an indexed element in the triplet, duplicate values are skipped to avoid repetition in the output.
- **Two-Pointer Technique**:
  - For each selected `nums[i]`, the `left` pointer starts just after `i`, while the `right` pointer points to the last element of the array.
  - The program checks the sum of the three numbers: `nums[i] + nums[left] + nums[right]`.
  
### Detailed Behavior with the Example Input

1. **When `i = 0` (nums[0] = -4)**:
   - The pointers are set at `left = 1` (nums[1] = -1) and `right = 12` (nums[12] = 6).
   - The sum will be `-4 + (-1) + 6 = 1`, which is less than `11`. Increment `left`.
   - This process continues until all combinations involving `-4` are checked.

2. **When `i = 1` (nums[1] = -1)**:
   - `left` starts at `2` and `right` at `12`.
   - The sums are calculated:
     - `-1 + (-1) + 6 = 4 < 11` → increment `left`.
     - `-1 + 0 + 6 = 5 < 11` → increment `left`.
     - `-1 + 1 + 6 = 6 < 11` → increment `left`.
     - `-1 + 2 + 6 = 7 < 11` → increment `left`.
     - `-1 + 2 + 3 = 4 < 11` → increment `left`.
     - `-1 + 3 + 3 = 5 < 11` → increment `left`.

3. **As the process continues**:
   - The loop iterates with increasing `i` values (until `i = 10`), with each iteration recalculating the sum of `nums[i]`, `nums[left]`, and `nums[right]`.
   - At no point is a triplet found such that `nums[i] + nums[left] + nums[right] = k` (11).

### Final Output

After all iterations and combinations are checked, and because no valid triplets were found, the result is an empty list. 

### Output Explanation

The final output will be:
```
Triplets that sum to 11 are: 
```
meaning no triplet combinations of three numbers from the array sum up to `11`.

### Complexity
- **Time Complexity**: The algorithm runs in \( O(n^2) \) due to the nested nature of the loop with the two-pointer strategy.
- **Space Complexity**: The space complexity is \( O(1) \) for storing indices and the result vector is \( O(t) \) where \( t \) is the number of unique triplets found.

Since no valid triplet was found summing to 11, the output correctly reflects that outcome.
*/