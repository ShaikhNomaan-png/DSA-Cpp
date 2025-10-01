#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // num -> index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 17;
    vector<int> ans = twoSum(nums, target);
    cout << "Indices: " << ans[0] << ", " << ans[1] << endl; // index show of sum of no. 
    return 0;
}



/* Sure! Let's break down the output of the Two Sum problem step by step using the provided example.

### Example Input
The input array and target value from the example are:
```cpp
std::vector<int> nums = {2, 7, 11, 15}; // Example input
int target = 9;
```

### Goal
The objective is to find two distinct indices in the array such that the numbers at those indices add up to the `target` value of **9**.

### Detailed Steps
1. **Initialization**:
   - We have an empty unordered map called `numMap` that will be used to keep track of the elements we have seen so far and their corresponding indices.

2. **First Iteration (i = 0)**:
   - Current number: `2`
   - Calculate the complement: `target - nums[0] = 9 - 2 = 7`
   - Check if `7` is in `numMap`: It is not.
   - Add `2` and its index `0` to `numMap`:
     ```
     numMap = {2: 0}
     ```

3. **Second Iteration (i = 1)**:
   - Current number: `7`
   - Calculate the complement: `target - nums[1] = 9 - 7 = 2`
   - Check if `2` is in `numMap`: It is! The index for `2` is `0`.
   - Since we found the complement (2) in the map, we return the indices:
     ```cpp
     return {0, 1};
     ```
   - Here, `0` is the index of `2`, and `1` is the index of `7`.

4. **Output**:
   - The indices returned are `0` and `1`. This means that:
     - The number at index `0` is `2`
     - The number at index `1` is `7`
   - When you add them together: 
     ```
     2 + 7 = 9
     ```

### Print Statement
In the `main` function, we display the result with the following line:
```cpp
std::cout << "Indices of the numbers that add up to " << target << ": "
          << result[0] << " and " << result[1] << std::endl;
```

### Final Output
The output displayed will be:
```
Indices of the numbers that add up to 9: 0 and 1
```

### Interpretation
This output indicates that:
- The two numbers in the array that add up to **9** are:
  - The number at index **0** (`2`)
  - The number at index **1** (`7`)
- Therefore, the correct indices are **0** and **1**.

This exemplifies how the Two Sum algorithm efficiently finds the solution using a hash map, allowing it to operate in linear time, \(O(n)\), by checking for complements while iterating through the array. The key advantage is the speed gained from using a hash map for lookups instead of a nested loop structure, which would be less efficient.
*/