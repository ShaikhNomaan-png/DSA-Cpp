#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool graphColouring(vector<vector<int>>& graph, int m) {
        int V = graph.size();
        vector<int> color(V, -1); // Initialize all vertices with no color
        return solve(graph, V, m, color, 0); // Start with the first vertex
    }
    
private:
    bool solve(vector<vector<int>>& graph, int V, int m, vector<int>& color, int vertex) {
        if (vertex == V) { // If all vertices are processed
            return true;
        }
        
        // Try coloring vertex with all colors from 1 to m
        for (int c = 1; c <= m; c++) {
            if (isSafe(graph, color, vertex, c)) { // Check if color can be assigned
                color[vertex] = c; // Assign color

                // Recur to color the next vertex
                if (solve(graph, V, m, color, vertex + 1)) {
                    return true;
                }

                // If assigning color c doesn't lead to a solution, remove it (backtrack)
                color[vertex] = -1;
            }
        }
        return false; // No color can be assigned
    }

    // Check if it's safe to color vertex with color c
    bool isSafe(vector<vector<int>>& graph, vector<int>& color, int vertex, int c) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[vertex][i] == 1 && color[i] == c) { // Check adjacent vertices
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 0}
    };
    
    int m = 3; // Number of colors
    if (solution.graphColouring(graph, m)) {
        cout << "Solution exists." << endl;
    } else {
        cout << "No solution exists." << endl;
    }
    
    return 0;
}

/*  The M-Coloring Problem is a classic problem in graph theory where the goal is to color the vertices of a graph such that no two adjacent vertices share the same color. The problem is NP-complete and is often tackled using backtracking.

### Problem Statement

Given a graph with `V` vertices and `E` edges, and a number `M`, your task is to determine if the graph can be colored using at most `M` colors such that no adjacent vertices have the same color.

### Approach

1. **Graph Representation**:
   - Represent the graph using an adjacency matrix or an adjacency list.
   
2. **Backtracking**:
   - Try to assign colors to each vertex one by one.
   - For each vertex, check if it can be colored with a certain color without violating the coloring rules (i.e., no two adjacent vertices share the same color).
   - If it’s possible to assign a color, recursively move on to the next vertex.
   - If all vertices are colored successfully, return true.
   - If not, backtrack and try the next color.

3. **Validity Check**:
   - When attempting to color a vertex, check all adjacent vertices to ensure they do not share the same color.

### C++ Implementation

Here’s a C++ solution for the M-Coloring problem using backtracking:

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool graphColouring(vector<vector<int>>& graph, int m) {
        int V = graph.size();
        vector<int> color(V, -1); // Initialize all vertices with no color
        return solve(graph, V, m, color, 0); // Start with the first vertex
    }
    
private:
    bool solve(vector<vector<int>>& graph, int V, int m, vector<int>& color, int vertex) {
        if (vertex == V) { // If all vertices are processed
            return true;
        }
        
        // Try coloring vertex with all colors from 1 to m
        for (int c = 1; c <= m; c++) {
            if (isSafe(graph, color, vertex, c)) { // Check if color can be assigned
                color[vertex] = c; // Assign color

                // Recur to color the next vertex
                if (solve(graph, V, m, color, vertex + 1)) {
                    return true;
                }

                // If assigning color c doesn't lead to a solution, remove it (backtrack)
                color[vertex] = -1;
            }
        }
        return false; // No color can be assigned
    }

    // Check if it's safe to color vertex with color c
    bool isSafe(vector<vector<int>>& graph, vector<int>& color, int vertex, int c) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[vertex][i] == 1 && color[i] == c) { // Check adjacent vertices
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 0}
    };
    
    int m = 3; // Number of colors
    if (solution.graphColouring(graph, m)) {
        cout << "Solution exists." << endl;
    } else {
        cout << "No solution exists." << endl;
    }
    
    return 0;
}
```

### Explanation of the Code

1. **Class Definition**: The `Solution` class contains the method `graphColouring()` that checks if the graph can be colored with the given number of colors.

2. **Graph Representation**: The graph is represented using an adjacency matrix where `graph[i][j]` indicates if there is an edge between vertex `i` and vertex `j`.

3. **Backtracking Method**:
   - The `solve()` function is the core of the backtracking.
   - It iteratively tries to assign a color to each vertex using a loop from `1` to `M`.
   - It checks if the color can be safely assigned using the `isSafe()` function.

4. **Safety Check**:
   - The `isSafe()` function checks all adjacent vertices of the current vertex to ensure no adjacent vertex has the same color.

5. **Main Function**: Initializes a sample graph and calls the `graphColouring()` method, printing whether a solution exists.

### Complexity

- **Time Complexity**: O(M^V), where `V` is the number of vertices in the graph. In the worst case, we may need to try all `M` colors for every vertex.
- **Space Complexity**: O(V), for the color array used in backtracking.

### Output

Given the example, if the problem can be solved with the specified number of colors, the output will be:

```
Solution exists.
```

If it cannot be colored with the given number of colors, it will display:

```
No solution exists.
```

If you have further questions or need additional explanations, feel free to ask!
*/