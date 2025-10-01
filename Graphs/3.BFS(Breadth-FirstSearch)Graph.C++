/*  What is BFS?
Breadth-First Search (BFS) is an algorithm for traversing or searching tree or
 graph data structures. It starts at a selected node (the "source" or "root") and
  explores all of its neighbors at the present depth prior to moving on to nodes at the next
   depth level. BFS uses a queue to keep track of the nodes to be explored.

BFS Algorithm Steps
Start from the source node and mark it as visited.
Use a queue to explore each vertex.
Dequeue a vertex and check its adjacent vertices.
If an adjacent vertex hasn't been visited, mark it as visited and enqueue it.
Repeat steps 3 and 4 until the queue is empty.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS function
void BFS(int start, vector<vector<int>> &adj, int n) {
    vector<bool> visited(n, false); // track visited nodes
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS traversal starting from node " << start << ": ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // visit all neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int n = 5; // number of vertices
    vector<vector<int>> adj(n); // adjacency list

    // edges (undirected)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);
    adj[3].push_back(7);

    
    BFS(0, adj, n);

    return 0;
}


/*  Let's break down the provided C++ code for a graph and its Breadth-First Search (BFS) algorithm, and represent the graph visually as a tree structure based on the edges defined in the `main()` function.

### Code Explanation

1. **Graph Class**:
   - This class encapsulates the graph's properties and methods. It includes:
     - A constructor to initialize the number of vertices and the adjacency list.
     - An `addEdge` method to create undirected edges between vertices.
     - A `BFS` method to perform the breadth-first search starting from a specified vertex.

2. **Vertices and Edges**:
   - The graph is initialized with **5 vertices** (numbered 0 to 4).
   - The following edges are added:
     - 0 <-> 1
     - 0 <-> 4
     - 1 <-> 2
     - 1 <-> 3
     - 1 <-> 4
     - 2 <-> 3
     - 3 <-> 4
     
   This means:
   - Vertex 0 is connected to Vertex 1 and Vertex 4.
   - Vertex 1 is connected to Vertex 0, 2, 3, and 4.
   - Vertex 2 is connected to Vertex 1 and Vertex 3.
   - Vertex 3 is connected to Vertex 1, 2, and 4.
   - Vertex 4 is connected to Vertex 0, 1, and 3.

3. **BFS Method**:
   - The BFS algorithm starts at vertex 0, marking it as visited and enqueuing it.
   - It explores each vertex’s neighbors in a level-wise manner, ensuring that all reachable vertices are visited.

### Visual Tree Representation of the Graph

Given the edges, we can represent this undirected graph as a visual tree-like structure.

```
      0
     / \
    1   4
   /|\  |\
  2 | 3 | 
     | /
     3  (connected to 2 and 4)
```

### Output Explanation

When the `g.BFS(0);` is called, the output represents the visiting order of the vertices starting from vertex 0.

#### BFS Traversal Steps Starting from Vertex 0

1. Start at **vertex 0**: 
   - Mark it as visited.
   - Output: `0`
   - Neighbors of 0: 1, 4 — Enqueue: **1, 4**

2. Dequeue and process **vertex 1**:
   - Mark it as visited.
   - Output: `1`
   - Neighbors of 1: 0 (visited), 2, 3, 4 (visited) — Enqueue: **2, 3**

3. Dequeue and process **vertex 4**:
   - Mark it as visited.
   - Output: `4`
   - Neighbors of 4: 0 (visited), 1 (visited), 3 (already queued) — Nothing new to enqueue.

4. Dequeue and process **vertex 2**:
   - Mark it as visited.
   - Output: `2`
   - Neighbors of 2: 1 (visited), 3 (already queued) — Nothing new to enqueue.

5. Dequeue and process **vertex 3**:
   - Mark it as visited.
   - Output: `3`
   - Neighbors of 3: 1 (visited), 2 (visited), 4 (visited) — Nothing new to enqueue.

### Final Output from the Code

When you run the code, the complete output from the BFS starting at vertex 0 will be:

```
Breadth-First Search starting from vertex 0:
0 1 4 2 3 
```

### Summary

- The program initializes a graph with 5 vertices and constructs edges between them.
- The BFS algorithm is executed starting from vertex 0, resulting in the traversal order of the graph’s nodes.
- The output demonstrates the order of nodes as they are visited by the BFS algorithm.
*/