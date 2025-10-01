#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    // Expected sum of numbers from 1 to n
    int totalSum = n * (n + 1) / 2;

    // Actual sum of array elements
    int arrSum = 0;
    for (int i = 0; i < n - 1; i++) {
        arrSum += arr[i];
    }

    return totalSum - arrSum;  // Missing number
}

int main() {
    int n = 5;
    int arr[] = {1, 2, 4, 5};  // Missing number is 3

    cout << "Missing Number is: " << findMissingNumber(arr, n) << endl;
    return 0;
}
