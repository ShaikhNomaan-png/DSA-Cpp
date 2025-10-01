#include <iostream>
#include <string>
#include <stack>

using namespace std;

string removeKdigits(string num, int k) {
    stack<char> s;

    for (char digit : num) {
        // While we can remove digits and the top of the stack is larger than the current digit
        while (k > 0 && !s.empty() && s.top() > digit) {
            s.pop();
            k--;
        }
        
        s.push(digit);
    }

    // If there's still remaining digits to remove
    while (k > 0 && !s.empty()) {
        s.pop();
        k--;
    }

    // Build the result from the stack
    string result = "";
    while (!s.empty()) {
        result = s.top() + result; // Build the string in reverse
        s.pop();
    }

    // Remove leading zeros
    while (result.size() > 1 && result.front() == '0') {
        result.erase(result.begin());
    }

    return result.empty() ? "0" : result;
}

int main() {
    string num = "1432219";
    int k = 3;
    string result = removeKdigits(num, k);
    cout << "The smallest number after removing " << k << " digits is: " << result << endl; // Expected output: "1219"
    return 0;
}

/* L14. Remove K Digits | Stack and Queue Playlist
The "Remove K Digits" problem is a popular coding challenge that involves manipulating numbers represented as strings. The goal is to remove k digits from a given non-negative integer represented as a string to form the smallest possible number.

Problem Statement
Given a string num representing a non-negative integer, and an integer k, remove k digits from num. The result should be the smallest possible number formed, and if the result is an empty string, return "0".

Approach
Use a Stack: The idea is to use a stack to build the resulting number. We will iterate through each digit of the number.
Maintain Monotonicity: To ensure we create the smallest number, we want to keep the current number in a non-decreasing order (from left to right). Whenever we encounter a digit that is smaller than the digit at the top of the stack, and we still have k digits to remove, we'll pop the top of the stack.
Push Current Digit: After handling removals, we can push the current digit onto the stack.
Final Adjustments: After processing all digits, if there are still digits to be removed (k > 0), we pop from the end of the stack. Finally, we convert the stack to a string, remove leading zeros, and check if it’s empty. If so, return "0".  *//*
Explanation of Code
Stack Usage:

As we traverse the input number, we use a stack to keep track of the digits of the resulting number. The stack ensures that we can maintain the desired order.
Popping Logic:

The while loop inside the main loop removes digits from the stack if the current digit is smaller than the one at the top of the stack (and we still have digits to remove).
Final Adjustments:

If there are still digits to remove after processing all input digits, we pop from the top of the stack.
We build the final number from the stack, ensuring to handle leading zeros.
Result Handling:

The result string is checked for leading zeros. If it becomes empty after processing, we return "0".
Complexity Analysis
Time Complexity: O(n), where n is the length of the number string. Each digit is processed once.
Space Complexity: O(n) for the stack used to store the digits.
Conclusion
The "Remove K Digits" problem efficiently utilizes a stack to construct the smallest possible number by maintaining the order of digits. This approach ensures that we can make optimal choices for digit removal while processing the number sequentially. If you have any further questions or need assistance with any specific part, feel free to ask! */