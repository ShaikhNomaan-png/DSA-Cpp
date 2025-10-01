#include <iostream>

using namespace std;

int main() {
    int x = 5; // First number
    int y = 10; // Second number

    cout << "Before Swapping: x = " << x << ", y = " << y << endl;

    // Step 1
    x = x ^ y; // x now holds the XOR of both
    // Step 2
    y = x ^ y; // y becomes the original x
    // Step 3
    x = x ^ y; // x becomes the original y

    cout << "After Swapping: x = " << x << ", y = " << y << endl;

    return 0;
}
