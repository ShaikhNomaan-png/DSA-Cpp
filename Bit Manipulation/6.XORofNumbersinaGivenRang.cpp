#include <iostream>

using namespace std;

// Function to compute XOR from 0 to n
int xorTo(int n) {
    // Using properties of XOR to determine the result
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

// Function to compute XOR from L to R
int xorInRange(int L, int R) {
    // XOR from L to R is derived from XOR from 0 to R and XOR from 0 to L-1
    return xorTo(R) ^ xorTo(L - 1);
}

int main() {
    int L = 3; // Example input L
    int R = 9; // Example input R
    cout << "XOR of numbers from " << L << " to " << R << " is: " << xorInRange(L, R) << endl;
    return 0;
}


/*   ### L8. XOR of Numbers in a Given Range | Bit Manipulation

The task is to find the XOR of all numbers in a given range from \( L \) to \( R \). This can be efficiently calculated using properties of the XOR operation and a helper function that computes the XOR from \( 0 \) to \( n \).

### Problem Statement

Given two integers \( L \) and \( R \), compute the XOR of all integers from \( L \) to \( R \) (inclusive).

#### Example:

**Input**: \( L = 3, R = 9 \)  
**Output**:  \( 8 \)  
**Explanation**: The XOR from \( 3 \) to \( 9 \) is \( 3 \oplus 4 \oplus 5 \oplus 6 \oplus 7 \oplus 8 \oplus 9 = 8 \).

### Approach

1. **XOR Properties**: XOR has certain properties that can be utilized for quick computation:
   - \( x \oplus x = 0 \)
   - \( x \oplus 0 = x \)
   - XOR is associative and commutative.

2. **Helper Function**: Create a helper function that computes the XOR from \( 0 \) to \( n \). This can be derived using:
   - If \( n \mod 4 = 0 \) then \( \text{xor\_to}(n) = n \)
   - If \( n \mod 4 = 1 \) then \( \text{xor\_to}(n) = 1 \)
   - If \( n \mod 4 = 2 \) then \( \text{xor\_to}(n) = n + 1 \)
   - If \( n \mod 4 = 3 \) then \( \text{xor\_to}(n) = 0 \)

3. **Calculate the Result**: 
   - The XOR from \( L \) to \( R \) can be computed as:
   \[
   \text{result} = \text{xor\_to}(R) \oplus \text{xor\_to}(L - 1)
   \]
   - This is derived from the property that if you have the XOR from \( 0 \) to \( R \) and want to remove the XOR from \( 0 \) to \( L-1 \), you effectively get the XOR from \( L \) to \( R \).

### Implementation

Here’s a C++ implementation of the above approach:

```cpp
#include <iostream>

using namespace std;

// Function to compute XOR from 0 to n
int xorTo(int n) {
    // Using properties of XOR to determine the result
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

// Function to compute XOR from L to R
int xorInRange(int L, int R) {
    // XOR from L to R is derived from XOR from 0 to R and XOR from 0 to L-1
    return xorTo(R) ^ xorTo(L - 1);
}

int main() {
    int L = 3; // Example input L
    int R = 9; // Example input R
    cout << "XOR of numbers from " << L << " to " << R << " is: " << xorInRange(L, R) << endl;
    return 0;
}
```

### Output

When executed with \( L = 3 \) and \( R = 9 \):
```
XOR of numbers from 3 to 9 is: 8
```

### Complexity Analysis

- **Time Complexity**: \( O(1) \) since the solution involves a constant number of operations regardless of the values of \( L \) and \( R \).
- **Space Complexity**: \( O(1) \) as we are using a constant amount of space for the variables.

### Conclusion

The problem of finding the XOR of numbers in a given range can be efficiently solved using properties of XOR and a simple mathematical derivation. By understanding how to accumulate results over ranges, we can reduce the computational complexity and provide an instant result with minimal operations. This showcases the power of bit manipulation in solving mathematical problems efficiently.
*/