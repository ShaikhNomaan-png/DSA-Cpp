#include <iostream>
#include <vector>

using namespace std;

// Function to find the single number using XOR
int singleNumber(const vector<int>& nums) {
    int result = 0;

    for (int num : nums) {
        result ^= num; // XOR each number with result
    }

    return result; // The single number remaining
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2}; // Example input

    cout << "The single number is: " << singleNumber(nums) << endl;

    return 0;
}

/*   ### L5. Single Number-I | Bit Manipulation

The problem of finding the "single number" in an array where every element appears twice except for one unique element is a classic interview question. The goal is to identify that unique element efficiently using bit manipulation.

### Problem Statement

Given an array of integers, where every element appears exactly twice except for one element that appears only once, find that single element.

#### Example:

**Input**: `[4, 1, 2, 1, 2]`  
**Output**: `4`  
**Explanation**: The number `4` appears only once, while all other numbers appear twice.

### Approach

The most efficient way to solve this problem is to use the **XOR** operation. The properties of XOR that we can leverage are:

1. \(x \oplus x = 0\) (any number XORed with itself is 0)
2. \(x \oplus 0 = x\) (any number XORed with 0 remains unchanged)
3. XOR is both commutative and associative.

Using these properties, when you XOR all the elements in the array, the paired elements will cancel each other out (because \(a \oplus a = 0\)), and only the unique element will remain.

### Implementation

Below is a C++ implementation of this approach:

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Function to find the single number using XOR
int singleNumber(const vector<int>& nums) {
    int result = 0;

    for (int num : nums) {
        result ^= num; // XOR each number with result
    }

    return result; // The single number remaining
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2}; // Example input

    cout << "The single number is: " << singleNumber(nums) << endl;

    return 0;
}
```

### Execution Steps

1. Begin with `result = 0`.
2. Iterate through each number in the input array.
3. Apply the XOR operation between `result` and each number:
   - After processing: 
     - For `4`: `result = 0 ^ 4 = 4`
     - For `1`: `result = 4 ^ 1 = 5` 
     - For `2`: `result = 5 ^ 2 = 7`
     - For `1`: `result = 7 ^ 1 = 6`
     - For `2`: `result = 6 ^ 2 = 4`
4. After processing all elements, the only number that remains in `result` is `4`, which is the unique number.

### Output

When executed, the program will output:
```
The single number is: 4
```

### Complexity Analysis

- **Time Complexity**: \(O(n)\), where \(n\) is the number of elements in the input array since we only traverse the list once.
- **Space Complexity**: \(O(1)\) since we use a constant amount of extra space for the `result` variable.

### Conclusion

The XOR operation is a powerful and efficient way to solve the "Single Number-I" problem using minimal space and time. This approach demonstrates how bit manipulation can simplify problems that might seem complex at first glance. Understanding this technique is valuable for anyone studying algorithms and data structures.
*/