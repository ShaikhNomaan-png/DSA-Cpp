#include <iostream>

using namespace std;

// Function to count the number of set bits (1's) in an integer
int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1; // Add the least significant bit
        num >>= 1;        // Right shift to process the next bit
    }
    return count;
}

// Function to calculate minimum bit flips to convert a to b
int minBitFlips(int a, int b) {
    int xorValue = a ^ b; // XOR to find differing bits
    return countSetBits(xorValue); // Count the set bits in the XOR result
}

int main() {
    int a = 29; // Example number 1 (binary: 11101)
    int b = 15; // Example number 2 (binary: 01111)

    cout << "Minimum bit flips to convert " << a << " to " << b << " is: " << minBitFlips(a, b) << endl;

    return 0;
}

/*  ### L3. Minimum Bit Flips to Convert Number | Bit Manipulation

In the context of bit manipulation, one interesting problem is determining the minimum number of bit flips required to convert one binary number into another. This can be particularly useful in various applications, such as networking (to calculate differences in routing tables) or error detection in data transmission.

### Problem Statement

Given two integers, `a` and `b`, the task is to find the minimum number of bit flips required to convert `a` into `b`. A bit flip changes a binary bit from `0` to `1` or from `1` to `0`.

### Approach

1. **XOR Operation**: The first step is to use the XOR operation to find the bits that differ between `a` and `b`. The XOR of two bits is `1` when the bits are different and `0` when they are the same.

2. **Counting Set Bits**: Once we have the XOR result, we need to count the number of `1`s in the result. Each `1` indicates a position where the bits in `a` and `b` differ, which corresponds to an individual bit flip needed.

### Steps

1. Calculate `a ^ b` to find the bits that differ.
2. Count the number of `1`s in the result of the XOR operation, as each `1` represents a bit that needs to be flipped.

### Complete Code Example

Here’s a sample C++ implementation to demonstrate this logic:

```cpp
#include <iostream>

using namespace std;

// Function to count the number of set bits (1's) in an integer
int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1; // Add the least significant bit
        num >>= 1;        // Right shift to process the next bit
    }
    return count;
}

// Function to calculate minimum bit flips to convert a to b
int minBitFlips(int a, int b) {
    int xorValue = a ^ b; // XOR to find differing bits
    return countSetBits(xorValue); // Count the set bits in the XOR result
}

int main() {
    int a = 29; // Example number 1 (binary: 11101)
    int b = 15; // Example number 2 (binary: 01111)

    cout << "Minimum bit flips to convert " << a << " to " << b << " is: " << minBitFlips(a, b) << endl;

    return 0;
}
```

### Output Explanation

When you run the program with `a = 29` (binary `11101`) and `b = 15` (binary `01111`):

1. **XOR Calculation**:
   - `29 ^ 15` results in `11101 ^ 01111 = 10010` (binary).
   - The binary result `10010` has two `1`s.

2. **Counting Set Bits**:
   - The `countSetBits` function processes `10010` and counts the `1`s, resulting in `2`.

3. **Final Output**:
   ```
   Minimum bit flips to convert 29 to 15 is: 2
   ```

### Summary

The minimum bit flips required to convert one number to another can be efficiently calculated using bit manipulation techniques. By leveraging the XOR operation and counting the resulting set bits, you can determine the necessary changes succinctly.

This approach is efficient, operating in \( O(\log n) \) time complexity due to the bit counting step, and is straightforward to implement in various programming languages. Understanding this technique is essential for anyone working with low-level data processing or network protocols involving binary data.
*/