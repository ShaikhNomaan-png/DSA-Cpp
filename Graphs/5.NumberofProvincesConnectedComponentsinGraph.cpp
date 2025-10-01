#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// DFS function to explore the graph
void DFS(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
    visited[node] = true; // Mark the current node as visited

    // Recursively visit all connected nodes
    for (int i = 0; i < isConnected[node].size(); i++) {
        if (isConnected[node][i] == 1 && !visited[i]) {
            DFS(i, isConnected, visited);
        }
    }
}

// Function to count the number of provinces (connected components)
int findProvinces(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) { // If the node is not visited, it is a new province
            count++;
            DFS(i, isConnected, visited);
        }
    }
    return count;
}

int main() {
    // Example adjacency matrix for the graph
    vector<vector<int>> isConnected = {
        {1, 1, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };

    int provinces = findProvinces(isConnected);
    cout << "Number of Provinces: " << provinces << endl;

    return 0;
}

/*  Let's walk through the provided C++ code step by step and explain the output based on the given adjacency matrix.

### Code Overview

1. **Graph Representation**: The graph is represented as an adjacency matrix called `isConnected`, 
where a `1` indicates a direct connection between nodes, and a `0` indicates no connection.

```cpp
vector<vector<int>> isConnected = {
    {1, 1, 1, 0, 0}, // Node 0 is connected to Nodes 1, 2
    {1, 1, 1, 0, 0}, // Node 1 is connected to Nodes 0, 2
    {1, 1, 1, 0, 0}, // Node 2 is connected to Nodes 0, 1
    {0, 0, 0, 1, 1}, // Node 3 is connected to Nodes 4
    {0, 0, 0, 1, 1}  // Node 4 is connected to Nodes 3
};
```

### Details of the Graph

The adjacency matrix defines the following connections:

- **Component 1** (Province 1): Nodes 0, 1, and 2 are all connected to each other.
- **Component 2** (Province 2): Nodes 3 and 4 are connected to each other but have no connection to Nodes 0, 1, or 2.

### Execution Flow

1. **Visited Array**: A Boolean vector `visited` of the same size as the number of nodes (`n`) is initialized to `false`.

2. **Counting Provinces**:
   - The `findProvinces` function iterates through each node.
   - For each unvisited node, it increments the province count and performs a DFS to mark all reachable nodes as visited.

### Detailed Execution Steps

- For `i = 0` (Node 0):
  - Not visited, increment count to 1.
  - Perform DFS starting from Node 0:
    - Mark Node 0 as visited.
    - Check connections:
      - Visit Node 1 (mark as visited, then check connection to 0 and 2).
        - Visit Node 2 (mark as visited, then check connection to 0 and 1).
  - After this DFS, Nodes 0, 1, and 2 are all marked as visited.

- For `i = 1` (Node 1):
  - Already visited, skip.

- For `i = 2` (Node 2):
  - Already visited, skip.

- For `i = 3` (Node 3):
  - Not visited, increment count to 2.
  - Perform DFS starting from Node 3:
    - Mark Node 3 as visited.
    - Check connections:
      - Visit Node 4 (mark as visited, then check connection to 3).
  - After this DFS, Nodes 3 and 4 are marked as visited.

- For `i = 4` (Node 4):
  - Already visited, skip.

### Final Count of Provinces

After checking all nodes, the function determines that there are **2 provinces** in total:

1. Province 1: Nodes (0, 1, 2)
2. Province 2: Nodes (3, 4)

### Output

The final output corresponds to the count of provinces:

```bash
Number of Provinces: 2
```

### Summary

The program effectively counts the separate connected components (provinces) in the graph based on the provided 
adjacency matrix. It identifies that there are 2 connected components, and that is the output displayed by the program.
*/