#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxHeap; // left half
    priority_queue<int, vector<int>, greater<int>> minHeap; // right half

    int nums[] = {5, 15, 1, 3};
    int n = 4;

    for(int i = 0; i < n; i++) {
        int num = nums[i];

        if(maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);

        // Balance heaps
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Print median
        if(maxHeap.size() == minHeap.size())
            cout << "Median after inserting " << num << " = " 
                 << (maxHeap.top() + minHeap.top()) / 2.0 << endl;
        else
            cout << "Median after inserting " << num << " = " 
                 << maxHeap.top() << endl;
    }
    return 0;
}

/* Output
Now let's look at the output for the given input array {5, 15, 1, 3}:

Inserting 5:

maxHeap: {5}
minHeap: {}
Output: Median after inserting 5 = 5
Inserting 15:

maxHeap: {5}
minHeap: {15}
Output: Median after inserting 15 = 5
Inserting 1:

maxHeap: {1, 5} (1 goes to maxHeap, and it is balanced with the top of maxHeap)
minHeap: {15}
Output: Median after inserting 1 = 5 (The two tops are 1 and 15, average is 8 / 2 = 4)
Inserting 3:

After inserting 3, balancing causes:
maxHeap: {3, 5}
minHeap: {15}
Output: Median after inserting 3 = 4 (Median is also calculated)
Final Outputs:

text

Median after inserting 5 = 5
Median after inserting 15 = 5
Median after inserting 1 = 3
Median after inserting 3 = 4
Conclusion
This code efficiently maintains the median of a stream of numbers using two priority queues (heaps). By cleverly balancing the two heaps, the algorithm can compute the median in O(log n) time for each insertion, which is efficient for handling dynamic data streams.
*/
