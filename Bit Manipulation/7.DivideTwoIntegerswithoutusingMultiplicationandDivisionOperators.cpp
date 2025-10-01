#include <iostream>
#include <climits> // For INT_MIN and INT_MAX

using namespace std;

int divide(int dividend, int divisor) {
    // Handle edge case
    if (divisor == 0) {
        throw runtime_error("Division by zero not allowed.");
    }

    // Handle overflow case
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX; // Clamp to INT_MAX to avoid overflow
    }

    // Determine the sign of the result
    long long a = abs(static_cast<long long>(dividend));
    long long b = abs(static_cast<long long>(divisor));
    long long quotient = 0;

    // Count how many times the divisor can be subtracted
    for (int bit = 31; bit >= 0; --bit) {
        // Check if the shifted divisor fits into the remaining dividend
        if ((a >> bit) >= b) {
            a -= (b << bit); // Subtract the shifted divisor
            quotient |= (1LL << bit); // Set the bit in the quotient
        }
    }

    // Determine the sign of the quotient
    return (dividend < 0) ^ (divisor < 0) ? -quotient : quotient;
}

int main() {
    int dividend = 10; // Example dividend
    int divisor = 3;   // Example divisor
    try {
        cout << "Result of dividing " << dividend << " by " << divisor << " is: " << divide(dividend, divisor) << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}


/*  ### L9. Divide Two Integers without Using Multiplication and Division Operators | Bit Manipulation

The task is to divide two integers \( dividend \) and \( divisor \) without using the multiplication (`*`) or division (`/`) operators. Instead, we will rely on bit manipulation techniques and subtraction to achieve the division.

### Problem Statement

You are given two integers, `dividend` and `divisor`. Your goal is to compute the quotient (the result of the division) while adhering to the constraints:

1. Use bit manipulation and subtraction.
2. Handle edge cases, such as division by zero.
3. Return the quotient truncated towards zero (i.e., without rounding).

### Approach

1. **Handle Edge Cases**: 
   - If the divisor is `0`, return an error or handle appropriately (typically, we throw an exception in real implementations).
   - Handle potential overflow situations when dividing `INT_MIN` by `-1`.

2. **Use Bit Manipulation and Subtraction**:
   - Use bit shifting (i.e., left shifting) to find powers of two that make the division faster. 
   - Keep subtracting the divisor from the dividend while increasing a quotient variable for every successful subtraction.

3. **Iterate with Bit Shifting**:
   - Start with an initial quotient of `0`.
   - Use a loop to shift the divisor left until it exceeds the dividend; this allows us to approximate how many times the divisor fits into the dividend by utilizing powers of two.
   - For each successful fit, we update the quotient and the dividend.

### Implementation

Here’s a C++ implementation using the above approach:

```cpp
#include <iostream>
#include <climits> // For INT_MIN and INT_MAX

using namespace std;

int divide(int dividend, int divisor) {
    // Handle edge case
    if (divisor == 0) {
        throw runtime_error("Division by zero not allowed.");
    }

    // Handle overflow case
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX; // Clamp to INT_MAX to avoid overflow
    }

    // Determine the sign of the result
    long long a = abs(static_cast<long long>(dividend));
    long long b = abs(static_cast<long long>(divisor));
    long long quotient = 0;

    // Count how many times the divisor can be subtracted
    for (int bit = 31; bit >= 0; --bit) {
        // Check if the shifted divisor fits into the remaining dividend
        if ((a >> bit) >= b) {
            a -= (b << bit); // Subtract the shifted divisor
            quotient |= (1LL << bit); // Set the bit in the quotient
        }
    }

    // Determine the sign of the quotient
    return (dividend < 0) ^ (divisor < 0) ? -quotient : quotient;
}

int main() {
    int dividend = 10; // Example dividend
    int divisor = 3;   // Example divisor
    try {
        cout << "Result of dividing " << dividend << " by " << divisor << " is: " << divide(dividend, divisor) << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}
```

### Explanation of the Code

1. **Edge Cases**: The function checks if the divisor is `0` and also safeguards against overflow when dividing `INT_MIN` by `-1`.
2. **Initialization**:
   - Use `long long` to accommodate potential overflow when working with absolute values of `dividend` and `divisor`.
3. **Bit Shifting**:
   - The for-loop iterates from bit 31 to bit 0.
   - It checks if the `dividend` can accommodate the `divisor` shifted by the `bit` position.
   - If it can, it subtracts the shifted divisor from the dividend and updates the quotient.
4. **Sign Handling**: Finally, the sign of the result is adjusted based on the original signs of the `dividend` and `divisor`.

### Complexity Analysis

- **Time Complexity**: \(O(\log(\text{dividend}))\) due to the iteration over bits.
- **Space Complexity**: \(O(1)\) since only a constant amount of space is used.

### Conclusion

This approach demonstrates how bit manipulation techniques can be employed to solve a division problem without using the standard multiplication or division operations. It highlights the power of bitwise operations in efficiently performing arithmetic calculations under constraints.
*/