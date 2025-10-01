#include <iostream>
#include <vector>
#include <algorithm> // For max
using namespace std;

// Merge function that counts inversions
long long mergeCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;   // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;   // Starting index for to be sorted subarray
    long long invCount = 0;

    // Conditions are checked to ensure that i doesn't exceed mid and j doesn't exceed right
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // There are mid - i inversions, because all elements left to i in the left subarray
            // are greater than arr[j]
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy the remaining elements of right subarray, if any
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy the sorted subarray back into the original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    
    return invCount;
}

// Recursive function to sort the array and count inversions
long long mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid + 1, right);
        invCount += mergeCount(arr, temp, left, mid, right);
    }
    return invCount;
}

// Function to count inversions in the array
long long countInversions(vector<int>& arr) {
    vector<int> temp(arr.size());
    return mergeSort(arr, temp, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {1, 20, 6, 4, 5};
    cout << "Number of inversions: " << countInversions(arr) << endl;
    return 0;
}

/*  Sure! Let’s break down the output of the code provided for counting inversions, especially for the specific test case where the input array is `{1, 20, 6, 4, 5}`.

### Input and Definition of Inversions

**Input Array**: 
```cpp
vector<int> arr = {1, 20, 6, 4, 5};
```

**Inversion Definition**: 
An inversion in an array is defined as a pair of indices \( (i, j) \) such that:
- \( i < j \)
- \( arr[i] > arr[j] \)

### Counting Inversions Manually

For the provided array `{1, 20, 6, 4, 5}`, let's identify the inversions:

1. For \( 1 \) at index \( 0 \):
   - \( 1 \) is not greater than any subsequent numbers, so there are **0 inversions** here.

2. For \( 20 \) at index \( 1 \):
   - \( 20 > 6 \) (inversion: (1, 2))
   - \( 20 > 4 \) (inversion: (1, 3))
   - \( 20 > 5 \) (inversion: (1, 4))
   - Total for index \( 1 \): **3 inversions**

3. For \( 6 \) at index \( 2 \):
   - \( 6 > 4 \) (inversion: (2, 3))
   - \( 6 > 5 \) (inversion: (2, 4))
   - Total for index \( 2 \): **2 inversions**

4. For \( 4 \) at index \( 3 \):
   - \( 4 \) is not greater than \( 5 \), so there are **0 inversions** here.

5. For \( 5 \) at index \( 4 \):
   - There are no indices after this one, so there are **0 inversions** here.

### Total Inversions Count

Adding all the inversions together:
- From index 1: 3 inversions
- From index 2: 2 inversions
- From indices 0, 3, and 4: 0 inversions each

Total inversions = **3 + 2 + 0 + 0 + 0 = 5**

### Output Explanation

When you run the program, it computes the number of inversions using the modified merge sort algorithm. As it processes the array, it counts the inversions during the merge phase of the sort. 

The final output of the program is:

```
Number of inversions: 5
```

This means that there are 5 pairs of indices in the array where the elements are out of order.

### Verification of the Output

You can verify the inversions listed:
- \( (1, 2) \): 20 and 6
- \( (1, 3) \): 20 and 4
- \( (1, 4) \): 20 and 5
- \( (2, 3) \): 6 and 4
- \( (2, 4) \): 6 and 5

This gives us exactly 5 inversions in total, confirming that the implementation correctly counts the inversions in the input array. 

### Summary
The output indicates the total number of inversions calculated is `5`, providing insight into how far the array is from being sorted. Each inversion reflects a pair of numbers that are incorrectly ordered according to the definition of a sorted array.
*/