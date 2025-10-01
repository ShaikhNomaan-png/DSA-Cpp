#include <iostream>

using namespace std;

// Function to compute 1's complement
unsigned int onesComplement(unsigned int n) {
    return ~n; // Invert all bits
}

// Function to compute 2's complement
unsigned int twosComplement(unsigned int n) {
    return onesComplement(n) + 1; // 1's complement + 1
}

// Function to perform and display basic bitwise operations
void bitwiseOperations(unsigned int a, unsigned int b) {
    cout << "Bitwise AND: " << a << " & " << b << " = " << (a & b) << endl;
    cout << "Bitwise OR: " << a << " | " << b << " = " << (a | b) << endl;
    cout << "Bitwise XOR: " << a << " ^ " << b << " = " << (a ^ b) << endl;
    cout << "Bitwise NOT: ~" << a << " = " << (~a) << " (using 32 bits)" << endl;
    cout << "Left Shift: " << a << " << 1 = " << (a << 1) << " (shifting left by 1 bit)" << endl;
    cout << "Right Shift: " << a << " >> 1 = " << (a >> 1) << " (shifting right by 1 bit)" << endl;
}

// Main function to test the functionality
int main() {
    unsigned int n = 10; // Example number
    cout << "Original number: " << n << endl;
    cout << "1's Complement of " << n << " = " << onesComplement(n) << endl;
    cout << "2's Complement of " << n << " = " << twosComplement(n) << endl;

    // Example of bitwise operations
    unsigned int a = 12; // Binary: 1100
    unsigned int b = 5;  // Binary: 0101
    cout << "\nPerforming Bitwise Operations:" << endl;
    bitwiseOperations(a, b);

    return 0;
}

/*   
*/

/*Certainly! Let's break down the concepts around **Bit Manipulation**, specifically focusing on **1's Complement**, **2's Complement**, and **Bit Operators**.

### 1. Introduction to Bit Manipulation

**Bit Manipulation** involves direct manipulation of bits in binary representations of numbers. This technique is commonly used in low-level programming and systems programming because it can lead to optimized performance and memory usage.

### 2. 1's Complement

- **Definition**: The 1's complement of a binary number is obtained by flipping all the bits. That means every `0` becomes `1` and every `1` becomes `0`.
- **Example**: 
  - Original: `1010`
  - 1's Complement: `0101`
  
- **Properties**:
  - It can be used to represent negative numbers in the binary system, but it has some drawbacks, such as having two representations for zero (`0000` and `1111` for 4 bits).

### 3. 2's Complement

- **Definition**: The 2's complement of a binary number is found by taking the 1's complement and adding `1` to the least significant bit (LSB).
- **Example**: 
  - To find the 2's complement of `1010`:
    1. 1's Complement: `0101`
    2. Add `1`: 
       ```
         0101
       + 0001
       --------
         0110
       ```
    - So, the 2's Complement of `1010` is `0110`.

- **Properties**:
  - 2's complement allows for simpler arithmetic and representation of negative integers because it has a unique representation for zero.
  - It effectively allows for the addition and subtraction of negative and positive integers without needing special rules.

### 4. Bit Operators

Bit Operators are special operators in programming languages that perform bit-level operations. The commonly used bit operators include:

1. **AND (`&`)**:
   - **Operation**: Returns `1` if both bits are `1`, otherwise it returns `0`.
   - **Example**:
     - `1010 & 1100 = 1000`

2. **OR (`|`)**:
   - **Operation**: Returns `1` if at least one of the bits is `1`.
   - **Example**:
     - `1010 | 1100 = 1110`

3. **XOR (`^`)**:
   - **Operation**: Returns `1` if the bits are different (`0` and `1`), otherwise returns `0`.
   - **Example**:
     - `1010 ^ 1100 = 0110`

4. **NOT (`~`)**:
   - **Operation**: Inverts all the bits.
   - **Example**:
     - `~1010 = 0101` (only the 4 bits are shown, actual representation may depend on the number of bits used)

5. **Left Shift (`<<`)**:
   - **Operation**: Shifts bits to the left, filling with `0` from the right. This operation effectively multiplies the number by `2` for each shift.
   - **Example**:
     - `0001 << 2 = 0100` (1 becomes 4)

6. **Right Shift (`>>`)**:
   - **Operation**: Shifts bits to the right. For unsigned numbers, this fills with `0`, while signed numbers generally fill with the sign bit.
   - **Example**:
     - `0100 >> 2 = 0001` (4 becomes 1)

### Use Cases of Bit Manipulation

- **Performance Optimization**: Bit manipulation can make certain calculations faster and more efficient, especially in low-level programming.
- **Graphics Processing**: Used heavily in graphics, where pixel information can be tightly packed.
- **Networking**: Manipulate IP addresses and perform subnetting.

### Conclusion

Understanding bit manipulation, including 1's and 2's complement representations and bit operators, is crucial for tasks involving low-level programming, performance optimization, and efficient data manipulation. Mastery of these concepts allows you to write more efficient algorithms and better comprehend how computers process data at the most fundamental level.

If you have specific questions or want to delve deeper into any of these topics, feel free to ask!
*/

/* Sure! Let’s break down the output of the provided C++ code in detail, including the computations and binary representations involved.

### Code Breakdown

1. **Header Files and Namespace**:
   - The code includes `<iostream>` for input/output operations and `<bitset>` (though it's not used in the code).
   - `using namespace std;` allows us to use standard namespace components without the `std::` prefix.

2. **Function Definitions**:
   - `onesComplement`: Computes the 1's complement of a number by inverting all bits using the bitwise NOT operator (`~`).
   - `twosComplement`: Computes the 2's complement by calculating the 1's complement and adding 1.

3. **Bitwise Operations**: This function demonstrates various bitwise operations that can be performed on two unsigned integers `a` and `b`.

4. **Main Function**: 
   - Initializes `n` with the value of `10`.
   - Calls the 1's and 2's complement functions.
   - Initializes `a` with `12` and `b` with `5` for bitwise operations and calls the respective function.

### Output Explanation

Let's look at the output in detail, assuming typical results from the execution:

#### Original Number:
```
Original number: 10
```
- This simply prints the original number `n`, which is `10`.

#### 1's Complement:
```
1's Complement of 10 = 4294967295
```
- **Calculation of 1's Complement**:
  - **Binary Representation of 10**: `00000000 00000000 00000000 00001010` (32 bits).
  - **1's Complement**: Invert all bits: `11111111 11111111 11111111 11110101` (this is `-11` in two's complement).
  - Given that `n` is an unsigned integer, the result is displayed in the unsigned format, which results in `4294967285`.

#### 2's Complement:
```
2's Complement of 10 = 4294967305
```
- **Calculation of 2's Complement**:
  - Start with the 1's complement: `11111111 11111111 11111111 11110101`.
  - Add `1` to get the 2's complement: 
    ```
    11111111 11111111 11111111 11110101
    +                                   1
    ----------------------------------------
    11111111 11111111 11111111 11110110
    ```
  - This results in `-10` in signed integer representation, which translates to `4294967306` in unsigned representation.

#### Bitwise Operations:

Next are the results for the bitwise operations on `a` and `b`, where `a = 12` and `b = 5`.

Binary representations for `12` and `5`:
- **12**: `00000000 00000000 00000000 00001100`
- **5**:  `00000000 00000000 00000000 00000101`

1. **Bitwise AND**:
```
Bitwise AND: 12 & 5 = 4
```
- Calculation:
  ```
  00000000 00000000 00000000 00001100
  & 00000000 00000000 00000000 00000101
  ----------------------------------------
  00000000 00000000 00000000 00000100
  ```
- Result: `4` (which is `00000100` in binary).

2. **Bitwise OR**:
```
Bitwise OR: 12 | 5 = 13
```
- Calculation:
  ```
  00000000 00000000 00000000 00001100
  | 00000000 00000000 00000000 00000101
  ----------------------------------------
  00000000 00000000 00000000 00001101
  ```
- Result: `13` (which is `00001101` in binary).

3. **Bitwise XOR**:
```
Bitwise XOR: 12 ^ 5 = 9
```
- Calculation:
  ```
  00000000 00000000 00000000 00001100
  ^ 00000000 00000000 00000000 00000101
  ----------------------------------------
  00000000 00000000 00000000 00001001
  ```
- Result: `9` (which is `00001001` in binary).

4. **Bitwise NOT**:
```
Bitwise NOT: ~12 = -13 (using 32 bits)
```
- Calculation:
  ```
  ~12 = ~00000000 00000000 00000000 00001100 = 11111111 11111111 11111111 11110101
  ```
- Result: `-13` in a signed interpretation of the bits, which can be calculated as `4294967283` in unsigned representation.

5. **Left Shift**:
```
Left Shift: 12 << 1 = 24 (shifting left by 1 bit)
```
- Calculation:
  - Shifting `12` (binary `00000000 00000000 00000000 00001100`) left by 1 bit results in `00000000 00000000 00000000 00011000`, which is `24`.

6. **Right Shift**:
```
Right Shift: 12 >> 1 = 6 (shifting right by 1 bit)
```
- Calculation:
  - Shifting `12` (binary `00000000 00000000 00000000 00001100`) right by 1 bit results in `00000000 00000000 00000000 00000110`, which is `6`.

### Summary of Execution

- The program computes the 1's and 2's complements of the number `10`, demonstrating how bitwise operations can manipulate binary representations.
- It performs basic bitwise operations on the integers `12` and `5`, producing results backed by direct binary arithmetic.

If you have any more questions or need further clarification, feel free to ask! */