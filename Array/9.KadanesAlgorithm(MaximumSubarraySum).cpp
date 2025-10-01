#include <iostream>
#include <vector>
using namespace std;

int kadane(vector<int>& arr) {
    int currSum = 0, maxSum = arr[0];
    for (int x : arr) {
        currSum += x;
        maxSum = max(maxSum, currSum);
        if (currSum < 0) currSum = 0;
    }
    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 3, 4, 2, 7, 9,  1, 5, 4}; // it show sum of all array
    cout << "Maximum Subarray Sum: " << kadane(arr) << endl;
    return 0;
}
