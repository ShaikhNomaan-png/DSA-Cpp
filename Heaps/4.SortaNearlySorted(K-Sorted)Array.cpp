#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> sortKSorted(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        minHeap.push(arr[i]);
        if (minHeap.size() > k) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}

int main() {
    vector<int> arr = {6,5,3,2,8,10,9};
    int k = 3;
    vector<int> sortedArr = sortKSorted(arr, k);
    cout << "Sorted Array: ";
    for (int num : sortedArr) cout << num << " ";
    cout << endl;
    return 0;
}
