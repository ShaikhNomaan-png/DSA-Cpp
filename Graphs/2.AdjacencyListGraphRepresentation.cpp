#include <iostream>
#include <vector>
#include <list>

const int MAX_VERTICES = 100; // Adjust as needed

void addEdge(std::vector<std::list<int>>& adjList, int u, int v) {
    adjList[u].push_back(v); // For directed graph
    adjList[v].push_back(u); // For undirected graph
}

void displayList(const std::vector<std::list<int>>& adjList, int vertices) {
    for (int i = 0; i < vertices; ++i) {
        std::cout << "Vertex " << i << "->";
        for (int v : adjList[i]) {
            std::cout << " " << v;
        }
        std::cout << "\n";
    }
}

int main() {
    int vertices = 5;
    std::vector<std::list<int>> adjList(MAX_VERTICES); // Initialize with a fixed size

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);

    std::cout << "Adjacency List:\n";
    displayList(adjList, vertices);

    return 0;
}

/*        0
         / \
        1   2
       / \
      3   4
2. Adjacency List Output
In the adjacency list representation, the same edges are added. When we run the code that utilizes an adjacency list, we get the output:

text

Adjacency List:
Vertex 0-> 1 4
Vertex 1-> 0 2 3 4
Vertex 2-> 1 3
Vertex 3-> 1 2 4
Vertex 4-> 0 1 3
Breakdown of the Output:
Each line corresponds to a vertex followed by the list of connected vertices.
For example:
Vertex 0: This shows that vertex 0 is directly connected to vertices 1 and 4: 0-> 1 4.
Vertex 1: This shows that vertex 1 is connected to vertices 0, 2, 3, and 4: 1-> 0 2 3 4.
Vertex 2: This shows that vertex 2 is connected to vertices 1 and 3: 2-> 1 3.
Vertex 3: This shows that vertex 3 is connected to vertices 1, 2, and 4: 3-> 1 2 4.
Vertex 4: This shows that vertex 4 is connected to vertices 0, 1, and 3: 4-> 0 1 3.
Conclusion
Both representations provide a clear way to visualize the relationships (edges) between vertices in a graph. The adjacency matrix provides a compact representation, especially useful in dense graphs, while the adjacency list is generally more memory-efficient, particularly for sparse graphs. Each format allows you to see the connections quickly, but the specific output format caters to different use cases in graph algorithms and operations.
*/