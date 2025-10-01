/*Algorithm
1.   Initialization: Create an empty stack.
2.   Iterate through each character in the input string:
If the character is an opening parenthesis ((, {, or [), push it onto the stack.
If the character is a closing parenthesis (), }, or ]):
Check if the stack is empty. If it is, return false (unbalanced).
If not empty, check if the top of the stack is the corresponding opening parenthesis. If it is, pop the stack; 
otherwise, return false (unbalanced).
3.  Final Check: After processing all characters, if the stack is empty, it means the parentheses are balanced; 
otherwise, they are not.
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string& s) {
    stack<char> parenthesesStack;

    // Iterate through each character in the string
    for (char ch : s) {
        // If it's an opening parenthesis, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            parenthesesStack.push(ch);
        } 
        // If it's a closing parenthesis
        else if (ch == ')' || ch == '}' || ch == ']') {
            // Check if the stack is empty or if the top does not match
            if (parenthesesStack.empty()) {
                return false; // Unbalanced
            }

            // Check for matching pairs
            char top = parenthesesStack.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // Unbalanced
            }
            parenthesesStack.pop(); // If matched, pop from stack
        }
    }

    // If stack is empty, all parentheses were balanced
    return parenthesesStack.empty();
}

// Main function to test the isBalanced function
int main() {
    string input;
    cout << "Enter a string of parentheses: ";
    cin >> input;

    if (isBalanced(input)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are NOT balanced." << endl;
    }

    return 0;
}


/* Example Inputs and Outputs
Input: ()

Output: The parentheses are balanced.
Input: ({[]})

Output: The parentheses are balanced.
Input: ([{}])

Output: The parentheses are balanced.
Input: ((()))

Output: The parentheses are balanced.
Input: ((()

Output: The parentheses are NOT balanced.
Input: ({[})

Output: The parentheses are NOT balanced.
Input: [{()}]

Output: The parentheses are balanced.
Input: )()

Output: The parentheses are NOT balanced.
Input: [(])

Output: The parentheses are NOT balanced.
Input: {}[]()

Output: The parentheses are balanced. */