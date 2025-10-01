#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

using namespace std;

// Function to find the second largest element in the array
int findSecondLargest(const vector<int>& arr) {
    if (arr.size() < 2) {
        throw invalid_argument("Array must contain at least two elements.");
    }

    int largest = INT_MIN;       // Initialize to the lowest possible integer
    int secondLargest = INT_MIN; // Initialize second largest

    for (int num : arr) {
        if (num > largest) {
            secondLargest = largest; // Update second largest
            largest = num;           // Update largest
        } else if (num > secondLargest && num < largest) {
            secondLargest = num;     // Update second largest
        }
    }

    if (secondLargest == INT_MIN) {
        throw invalid_argument("There is no second largest element (check for duplicates).");
    }

    return secondLargest; // Return the second largest element
}

// Function to find the second smallest element in the array
int findSecondSmallest(const vector<int>& arr) {
    if (arr.size() < 2) {
        throw invalid_argument("Array must contain at least two elements.");
    }

    int smallest = INT_MAX;      // Initialize to the highest possible integer
    int secondSmallest = INT_MAX; // Initialize second smallest

    for (int num : arr) {
        if (num < smallest) {
            secondSmallest = smallest; // Update second smallest
            smallest = num;             // Update smallest
        } else if (num < secondSmallest && num > smallest) {
            secondSmallest = num;       // Update second smallest
        }
    }

    if (secondSmallest == INT_MAX) {
        throw invalid_argument("There is no second smallest element (check for duplicates).");
    }

    return secondSmallest; // Return the second smallest element
}

int main() {
    vector<int> arr = {3, 5, 1, 8, 2, 7, 19,-1,-12, -14, 22};

    try {
        int secondLargest = findSecondLargest(arr);
        cout << "The second largest element in the array is: " << secondLargest << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl; // Handle exceptions for second largest
    }

    try {
        int secondSmallest = findSecondSmallest(arr);
        cout << "The second smallest element in the array is: " << secondSmallest << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl; // Handle exceptions for second smallest
    }

    return 0;
}
