#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int num : nums) freq[num]++;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    for (auto& it : freq) {
        minHeap.push({it.second, it.first});
        if (minHeap.size() > k) minHeap.pop();
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

int main() {
    vector<int> arr = {1,1,1,2,2,2,2,3};
    int k = 1; // means which no. is more repeated 
    vector<int> ans = topKFrequent(arr, k);
    cout << "Top " << k << " Frequent Elements: ";
    for (int num : ans) cout << num << " ";
    cout << endl;
    return 0;
}
