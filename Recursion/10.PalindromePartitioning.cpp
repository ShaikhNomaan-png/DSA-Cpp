#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        vector<string> currentPartition;
        backtrack(results, currentPartition, s, 0);
        return results;
    }
    
private:
    void backtrack(vector<vector<string>>& results, vector<string>& currentPartition, 
                   string& s, int start) {
        if (start >= s.length()) { // If we have reached the end of the string
            results.push_back(currentPartition);
            return;
        }
        
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) { // Check if s[start:end] is a palindrome
                currentPartition.push_back(s.substr(start, end - start + 1)); // Add substring to current partition
                backtrack(results, currentPartition, s, end + 1); // Recur for the remaining substring
                currentPartition.pop_back(); // Backtrack
            }
        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false; // Not a palindrome
            }
            start++;
            end--;
        }
        return true; // Is a palindrome
    }
};

int main() {
    Solution solution;
    string s = "aabbb"; // Example input
    vector<vector<string>> results = solution.partition(s);
    
    for (const auto& partition : results) {
        for (const auto& str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*   The Palindrome Partitioning problem is a classic backtracking and recursion problem where the goal is to partition a string into all possible substrings that are palindromes.

### Problem Statement

Given a string `s`, return all possible palindrome partitioning of `s`. A palindrome is a string that reads the same backward as forward. For example, "aba" is a palindrome.

### Approach

1. **Backtracking**:
   - Use a backtracking approach to explore different partitions of the string.
   - Start from the beginning of the string and try to extend the substring to various lengths, checking if each substring is a palindrome.
   - If it is a palindrome, recursively call the backtracking function for the remaining substring.
   - If the end of the string is reached, add the current partition to the results.

2. **Palindrome Check**:
   - Implement a helper function to check if a substring is a palindrome by comparing the characters from both ends until they meet in the middle.

### C++ Implementation

Here's a C++ implementation of the Palindrome Partitioning problem using recursion and backtracking:

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        vector<string> currentPartition;
        backtrack(results, currentPartition, s, 0);
        return results;
    }
    
private:
    void backtrack(vector<vector<string>>& results, vector<string>& currentPartition, 
                   string& s, int start) {
        if (start >= s.length()) { // If we have reached the end of the string
            results.push_back(currentPartition);
            return;
        }
        
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) { // Check if s[start:end] is a palindrome
                currentPartition.push_back(s.substr(start, end - start + 1)); // Add substring to current partition
                backtrack(results, currentPartition, s, end + 1); // Recur for the remaining substring
                currentPartition.pop_back(); // Backtrack
            }
        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false; // Not a palindrome
            }
            start++;
            end--;
        }
        return true; // Is a palindrome
    }
};

int main() {
    Solution solution;
    string s = "aab"; // Example input
    vector<vector<string>> results = solution.partition(s);
    
    for (const auto& partition : results) {
        for (const auto& str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

### Explanation of the Code

1. **Class Definition**: The `Solution` class contains the method `partition()` that initializes the backtracking process.

2. **Backtracking Method**: 
   - The `backtrack()` function generates partitions by exploring substrings starting from a given index.
   - If a valid partition is found (a palindrome), it is added to the current partition list, and the function recurses for the remaining substring.
   - After returning from the recursion, it removes the last added substring to explore other possibilities (backtracking).

3. **Palindrome Check**: 
   - The `isPalindrome()` function checks if the substring is a palindrome by comparing characters from the start and the end moving towards the center.

4. **Main Function**: 
   - Initializes a sample string and calls the `partition()` method and prints the results.

### Complexity

- **Time Complexity**: O(2^N), where N is the length of the string. Each character can either be included in a palindrome partition or not, leading to an exponential number of combinations.
- **Space Complexity**: O(N), for maintaining the current partition and the recursion stack.

### Example Output

For the input string "aab", the output partitions would be:
```
a a b 
aa b 
```

Indicating that the string can be partitioned into the substrings "a", "a", "b" and "aa", "b".

If you have further questions or require more detailed explanations, feel free to ask!
*/