#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Pair to store the element and its origin
typedef pair<int, pair<int, int>> Element; // (value, (array index, element index))

vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    vector<int> mergedArray;

    // Insert the first element of each array into the minHeap
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], {i, 0}}); // (element, (array index, element index))
        }
    }

    // While the min-heap is not empty, extract the minimum element
    while (!minHeap.empty()) {
        // Get the smallest element
        Element minElement = minHeap.top();
        minHeap.pop();

        int value = minElement.first;
        int arrayIndex = minElement.second.first;
        int elementIndex = minElement.second.second;

        // Add the smallest element to the merged array
        mergedArray.push_back(value);

        // If there are more elements in the same array, add the next one to the heap
        if (elementIndex + 1 < arrays[arrayIndex].size()) {
            minHeap.push({arrays[arrayIndex][elementIndex + 1], {arrayIndex, elementIndex + 1}});
        }
    }

    return mergedArray;
}

int main() {
    // Example input
    vector<vector<int>> arrays = {
        {1, 4, 7},
        {3, 10, 11},
        {2, 5, 8},
        {0, 6, 9},
    };

    vector<int> mergedArray = mergeKSortedArrays(arrays);

    // Print merged array
    cout << "Merged array: ";
    for (int val : mergedArray) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


/* Mging K sorted arrays can be efficiently accomplished using a min-heap (or priority queue). The idea is to push the first element of each array into the heap, and then repeatedly extract the smallest element from the heap, inserting the next element from the array that was extracted.
Algorithm Steps
Initialize a Min-Heap: Use a priority queue to keep track of the smallest elements.
Insert Elements: Insert the first element of each of the K arrays into the heap along with the array index and the element's index inside the array.
Pop the Smallest Element: Continuously extract the smallest element from the heap, add it to the result array, and insert the next element from the respective array into the heap.
Repeat: Continue this process until all elements from all arrays are processed.
Explanation of the Code:
Data Structure: We use a priority queue to implement the min-heap. Each element stored in the heap is a pair consisting of:
The value of the element.
A pair containing the index of the array from which the element was taken and the index of the element within that array.
Initialization: We push the first elements of each array into the min-heap.
Merging Process:
While the heap is not empty, we repeatedly extract the smallest element.
We then push the next element from the same array (if available) back into the heap.
Result Construction: We keep track of the merged elements in mergedArray.
Output
For the given arrays {{1, 4, 7}, {2, 5, 8}, {0, 6, 9}}, the output will be:
text
Merged array: 0 1 2 4 5 6 7 8 9
This implementation effectively combines K sorted arrays into a single sorted array with a time complexity of O(N log K), where N is the total number of elements across all K arrays and K is the number of arrays.
*/