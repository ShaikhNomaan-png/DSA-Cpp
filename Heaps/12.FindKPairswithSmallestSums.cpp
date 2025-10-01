#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pair {
    int sum; // Sum of the pair
    int index1; // Index in nums1
    int index2; // Index in nums2

    // Constructor
    Pair(int s, int i1, int i2) : sum(s), index1(i1), index2(i2) {}
};

// Comparator for the min-heap
struct Compare {
    bool operator()(const Pair& a, const Pair& b) {
        return a.sum > b.sum; // We want a min-heap
    }
};

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> result;
    if (nums1.empty() || nums2.empty() || k <= 0) {
        return result;
    }

    priority_queue<Pair, vector<Pair>, Compare> minHeap;

    // Initially populate the heap with the first element of nums1 with every element of nums2
    for (int i = 0; i < min(k, (int)nums1.size()); i++) {
        minHeap.push(Pair(nums1[i] + nums2[0], i, 0));
    }

    while (k-- > 0 && !minHeap.empty()) {
        Pair current = minHeap.top();
        minHeap.pop();
        
        // Add the pair to the result
        result.push_back({nums1[current.index1], nums2[current.index2]});

        // If there is a next index in nums2, push the new pair with the next element
        if (current.index2 + 1 < nums2.size()) {
            minHeap.push(Pair(nums1[current.index1] + nums2[current.index2 + 1], current.index1, current.index2 + 1));
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 7;

    vector<vector<int>> result = kSmallestPairs(nums1, nums2, k);
    
    cout << "K pairs with smallest sums:\n";
    for (const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "]\n";
    }

    return 0;
}
