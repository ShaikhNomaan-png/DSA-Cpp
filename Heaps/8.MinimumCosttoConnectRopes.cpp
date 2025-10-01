#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minimumCostToConnectRopes(const vector<int>& ropes) {
    // Create a min-heap to store the rope lengths
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Push all ropes into the min-heap
    for (int length : ropes) {
        minHeap.push(length);
    }

    int totalCost = 0;

    // While there's more than one rope to connect
    while (minHeap.size() > 1) {
        // Extract the two shortest ropes
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        // Calculate the cost to connect them
        int cost = first + second;
        totalCost += cost;

        // Add the new rope back to the min-heap
        minHeap.push(cost);
    }

    return totalCost;
}

int main() {
    // Example input
    vector<int> ropes = {4, 3, 2, 6};

    int totalCost = minimumCostToConnectRopes(ropes);
    cout << "Minimum cost to connect ropes: " << totalCost << endl;

    return 0;
}

/*  Let's walk through the explanation of the output for the provided code that computes the minimum cost to connect the ropes, using the example `ropes = {4, 3, 2, 6}`.

### Initial Input

You have ropes of lengths:
- Rope 1: 4
- Rope 2: 3
- Rope 3: 2
- Rope 4: 6

### Steps to Connect Ropes

To understand the output, let’s look at the step-by-step process in the algorithm, detailing how the minimum cost is calculated.

#### 1. Initialize the Min-Heap
All rope lengths are added to the min-heap (priority queue):
- Min-Heap after inserting ropes: `{2, 3, 4, 6}`

### Connection Process

**Iteration 1:**
- Extract the two shortest ropes:
  - First: `2`
  - Second: `3`
- Connect them:
  - Cost = `2 + 3 = 5`
- Add the new rope back to the min-heap:
- Updated heap: `{4, 5, 6}`

**Total Cost after Iteration 1**: `5`

**Iteration 2:**
- Extract the two shortest ropes again:
  - First: `4`
  - Second: `5`
- Connect them:
  - Cost = `4 + 5 = 9`
- Add the new rope back to the min-heap:
- Updated heap: `{6, 9}`

**Total Cost after Iteration 2**: `5 + 9 = 14`

**Iteration 3:**
- Extract the last two ropes:
  - First: `6`
  - Second: `9`
- Connect them:
  - Cost = `6 + 9 = 15`
- Add the new rope back to the min-heap, but at this point, there’s no need since we will have only one rope left.
  
**Total Cost after Iteration 3**: `14 + 15 = 29`
### Final Output
After all iterations, the total cost incurred to connect all the ropes is **29**.
### Summary of Connection Costs
To summarize:
- First connection `2 + 3` costs **5**
- Second connection `4 + 5` costs **9**
- Last connection `6 + 9` costs **15**
### Overall Total Cost
Thus, the output "Minimum cost to connect ropes: 29" indicates that the minimum total cost to connect all ropes into a single rope is **29**. 
This greedy approach ensures that at every step, we are making the optimal choice by connecting the shortest ropes first, which minimizes the overall expense of connecting them into a single rope.
*/