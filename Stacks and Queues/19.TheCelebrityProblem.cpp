#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int findCelebrity(const vector<vector<int>>& M) {
    int n = M.size();
    stack<int> s;

    // Step 1: Push all people onto the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Find the potential celebrity
    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        
        if (M[a][b] == 1) {
            // a knows b, a cannot be a celebrity
            s.push(b);
        } else {
            // a does not know b, b cannot be a celebrity
            s.push(a);
        }
    }

    // Step 3: Verify the candidate
    int candidate = s.top();
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (M[candidate][i] == 1 || M[i][candidate] == 0) {
                return -1; // No celebrity found
            }
        }
    }

    return candidate; // Now we have found the celebrity
}

int main() {
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int celebrity = findCelebrity(M);
    if (celebrity != -1) {
        cout << "Celebrity is person " << celebrity << endl; // Expected output: Celebrity is person 1
    } else {
        cout << "There is no celebrity." << endl;
    }

    return 0;
}

/*  ### L17. The Celebrity Problem | Stack and Queue Playlist

The "Celebrity Problem" is a well-known problem in graph theory and algorithms. The goal is to identify a "celebrity" in a group of people based on their knowledge of one another.

### Problem Statement

A celebrity is defined as a person who:
- Is known by everyone else.
- Knows no one.

You are given a matrix `M` where `M[i][j]` is 1 if person `i` knows person `j`, and 0 if they do not. You need to identify the celebrity if one exists.

### Example

Given the matrix:

```
M = [
    [0, 1, 0],
    [0, 0, 0],
    [0, 1, 0]
]
```

In this example:
- Person 0 knows person 1.
- Person 1 knows no one (celebrity criteria).
- Person 2 knows person 1 but is also known by person 0.

Here, person 1 is a celebrity.

### Approach

1. **Candidate Selection**: We can use a stack to figure out the potential celebrity. The key idea is to push all individuals onto a stack, then iteratively compare pairs to eliminate non-celebrities.
2. **Verification**: After identifying a candidate, verify that this candidate meets the celebrity criteria:
   - They must be known by everyone else.
   - They must not know anyone.

### Implementation

Here’s a sample implementation in C++:

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int findCelebrity(const vector<vector<int>>& M) {
    int n = M.size();
    stack<int> s;

    // Step 1: Push all people onto the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Find the potential celebrity
    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        
        if (M[a][b] == 1) {
            // a knows b, a cannot be a celebrity
            s.push(b);
        } else {
            // a does not know b, b cannot be a celebrity
            s.push(a);
        }
    }

    // Step 3: Verify the candidate
    int candidate = s.top();
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (M[candidate][i] == 1 || M[i][candidate] == 0) {
                return -1; // No celebrity found
            }
        }
    }

    return candidate; // Now we have found the celebrity
}

int main() {
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int celebrity = findCelebrity(M);
    if (celebrity != -1) {
        cout << "Celebrity is person " << celebrity << endl; // Expected output: Celebrity is person 1
    } else {
        cout << "There is no celebrity." << endl;
    }

    return 0;
}
```

### Explanation of the Code

1. **Candidate Selection**:
   - All individuals are initially pushed onto the stack.
   - We then pair and compare individuals to eliminate non-celebrities based on whether they know each other.

2. **Verification**:
   - Once a candidate is identified, we verify whether the candidate is indeed a celebrity by checking if the candidate knows anyone and whether all others know the candidate.

### Complexity Analysis

- **Time Complexity**: O(n), where `n` is the number of people. We make a linear pass to find and verify the celebrity.
- **Space Complexity**: O(n), required for the stack in the worst case if no celebrities are eliminated early.

### Conclusion

The "Celebrity Problem" is a classic algorithmic challenge that leverages stack data structures to efficiently identify a celebrity through elimination and verification processes. If you have any questions or need further explanations on specific parts, feel free to ask!  */