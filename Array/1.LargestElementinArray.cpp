#include <iostream>
#include <vector>

using namespace std;

// Function to find the largest element in the array
int findLargestElement(const vector<int>& arr) {
    if (arr.empty()) {
        throw invalid_argument("Array is empty.");
    }

    int largest = arr[0]; // Assume the first element is the largest

    // Iterate through the array to find the largest element
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > largest) {
            largest = arr[i]; // Update largest if current element is greater
        }
    }

    return largest; // Return the largest element found
}

int main() {
    vector<int> arr = {3, 5, 1, 8, 2, 7, 9, 17};

    try {
        int largestElement = findLargestElement(arr);
        cout << "The largest element in the array is: " << largestElement << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl; // Handle empty array case
    }

    return 0;
}
