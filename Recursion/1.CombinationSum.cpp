#include <iostream>
#include <vector>

using namespace std;

// Helper function for recursion
void backtrack(int start, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current); // Found a valid combination
        return;
    }
    if (target < 0) {
        return; // Exceeded the target
    }

    for (int i = start; i < candidates.size(); ++i) {
        current.push_back(candidates[i]); // Choose the number
        backtrack(i, target - candidates[i], candidates, current, result); // Recur with the updated target
        current.pop_back(); // Backtrack
    }
}

// Main function to find all combinations
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result; // To store all valid combinations
    vector<int> current; // To store the current combination
    backtrack(0, target, candidates, current, result); // Start the backtracking process
    return result;
}

// Main driver function for testing
int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> combinations = combinationSum(candidates, target);
    
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

/*   It seems that you're referring to a video or resource on recursion, specifically focusing on topics such as recursion trees and stack space, likely from Striver's A2Z DSA Course. Here's a general breakdown based on the context provided:

### Introduction to Recursion

Recursion is a programming technique where a function calls itself to solve smaller instances of the same problem. It involves the following key components:

1. **Base Case**: A condition where the function stops calling itself. It's essential to prevent infinite loops and stack overflow.
   
2. **Recursive Case**: The part of the function where the recursive call happens, breaking down the problem into smaller subproblems.

### Recursion Tree

A recursion tree is a visual representation of the recursive calls made during execution. It helps in understanding the flow of function calls and the overall structure of the recursion. 

- **Illustration**: Each node represents a function call, with child nodes representing calls made from that function. The height of the tree indicates the maximum depth of the recursion.

- **Analysis**: By analyzing the tree, you can determine the time complexity and space complexity of the recursive algorithm.

### Stack Space

When a function is called, the current state of the program, including local variables and the return address, is stored in the call stack. Here's how it works:

- **Stack Growth**: Each recursive call adds a new layer to the stack. When a function returns, this layer is popped off the stack.

- **Space Complexity**: The maximum depth of the recursion tree denotes the maximum space used in the call stack, typically O(n) for a straightforward recursion (where n is the height of the recursion tree).

### Example: Factorial Function

Here's a simple recursive function to calculate the factorial of a number:

```cpp
int factorial(int n) {
    // Base Case
    if (n <= 1) {
        return 1;
    }
    // Recursive Case
    return n * factorial(n - 1);
}
```

#### Recursion Tree for `factorial(3)`

```
                factorial(3)
                   /     
              3 * factorial(2)
                     /     
               2 * factorial(1)
                     \
                    1
```

- **Base Case**: When \( n \leq 1 \).
- **Max Depth**: In this case, for \( n = 3 \), the height of the tree would be 3.

### Conclusion

Understanding recursion, recursion trees, and stack space is crucial for mastering algorithms and data structures. This knowledge directly applies to solving problems in programming interviews and competitive programming.

If you're following along with Striver's course, it might be helpful to practice writing different recursive functions and visualizing their recursion trees to solidify your understanding. If you have specific questions or need further details about a particular topic, feel free to ask!
*/