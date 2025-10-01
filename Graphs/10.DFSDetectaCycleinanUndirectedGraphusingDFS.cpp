#include <iostream>
#include <vector>
using namespace std;

bool hasCycleDFS(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    
    // Explore all neighbors of the current node
    for (int neighbor : adj[node]) {
        // If the neighbor has not been visited, visit it
        if (!visited[neighbor]) {
            if (hasCycleDFS(neighbor, node, adj, visited)) {
                return true; // Cycle detected in the DFS path
            }
        }
        // If the neighbor is visited and it's not the parent of the current node, a cycle is found
        else if (neighbor != parent) {
            return true; // Cycle detected
        }
    }
    return false; // No cycle found
}

bool isCyclic(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);

    // Check for cycles in disconnected components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) { // Only start a DFS from unvisited nodes
            if (hasCycleDFS(i, -1, adj, visited)) {
                return true; // Cycle found
            }
        }
    }
    return false; // No cycles in any components
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V); // Graph representation as an adjacency list

    // Example graph with a cycle
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(1); // Back edge creates cycle
    adj[1].push_back(4); // Add this line for undirected graph completeness

    if (isCyclic(V, adj))
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph does not contain a cycle" << endl;

    return 0;
}

/*  Certainly! Let's go through the output of the provided code that detects cycles in an undirected graph using Depth-First Search (DFS).

### Code Walkthrough

Here's the relevant part of the code for reference:

```cpp
if (isCyclic(V, adj))
    cout << "Graph contains a cycle" << endl;
else
    cout << "Graph does not contain a cycle" << endl;
```

### Given Graph Representation

In our example, the graph is represented as:

```
0 -- 1
|    |
4 -- 3 -- 2
```

Here's how the adjacency list looks based on the edges we defined:

- `0` connects to `1`
- `1` connects to `0` and `2` and `4`
- `2` connects to `1` and `3`
- `3` connects to `2` and `4`
- `4` connects to `3` and `1`

The adjacency list in code:

```cpp
vector<vector<int>> adj(V);

adj[0].push_back(1); // 0 is connected to 1
adj[1].push_back(0); // 1 is connected to 0 (undirected)
adj[1].push_back(2); // 1 is connected to 2
adj[2].push_back(1); // 2 is connected to 1 (undirected)
adj[2].push_back(3); // 2 is connected to 3
adj[3].push_back(2); // 3 is connected to 2 (undirected)
adj[3].push_back(4); // 3 is connected to 4
adj[4].push_back(3); // 4 is connected to 3 (undirected)
adj[4].push_back(1); // 4 is connected to 1
adj[1].push_back(4); // 1 is connected to 4 (undirected, completes the cycle)
```

### Cycle Detection Logic Explained

1. **DFS Traversal**: The DFS starts from an unvisited node (for example, node `0`).
2. **Marking Nodes**: As it visits nodes, it marks them as visited to prevent revisiting.
3. **Parent Tracking**: For every node visited, it checks its neighbors. If a neighbor is already visited and is not the parent of the current node, that indicates a cycle.

### In This Case

1. Start at node `0`:
   - Visit `0`, mark it visited.
   - Move to neighbor `1`, mark it visited.
   
2. From `1`, the neighbors are `0`, `2`, and `4`:
   - Visit `2`, mark it visited.
   
3. From `2`, the neighbors are `1` and `3`:
   - Visit `3`, mark it visited.
   
4. From `3`, the neighbors are `2` and `4`:
   - Visit `4`, mark it visited.
   - From `4`, you can reach back to `1` (which is not the parent of `4`). This indicates a cycle:
   
   - Cycle found between `4`, `1`, and `2`.

### Expected Output

Given that a cycle was detected during the DFS traversal, the program outputs:

```
Graph contains a cycle
```

### Summary of the Output Explanation

- The program successfully identifies the presence of a cycle in the undirected graph due to the connections made between the nodes.
- The way neighbors are explored and the extra condition of checking against the parent prevents falsely identifying valid paths as cycles.
- This demonstrates a practical application of DFS in cycle detection within undirected graphs. 

If you would like to examine a graph without a cycle or have further questions about graph theory concepts, feel free to ask!
*/