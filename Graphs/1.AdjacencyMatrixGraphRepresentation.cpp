#include <iostream>
#include <vector>

const int MAX_VERTICES = 100; // Adjust as needed

void addEdge(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    adjMatrix[u][v] = 1; // For directed graph
    adjMatrix[v][u] = 1; // For undirected graph
}

void displayMatrix(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int vertices = 5;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize to 0

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 4);

    std::cout << "Adjacency Matrix:\n";
    displayMatrix(adjMatrix, vertices);

    return 0;
}

/*  1. Adjacency Matrix Output
When using the adjacency matrix representation, the following edges are added to the graph:

Edge between vertex 0 and vertex 1
Edge between vertex 0 and vertex 4
Edge between vertex 1 and vertex 2
Edge between vertex 1 and vertex 3
Edge between vertex 1 and vertex 4
Edge between vertex 2 and vertex 3
Edge between vertex 3 and vertex 4
Given that there are 5 vertices (0 to 4), the adjacency matrix initialized to zeros and then updated based on the edges gives us the following output:

text

Adjacency Matrix:
0 1 0 0 1 
1 0 1 1 1 
0 1 0 1 0 
0 1 1 0 1 
1 1 0 1 0 
Breakdown of the Output:
Each row and column corresponds to a vertex.
For example:
Row 0: The first row (0) shows that vertex 0 is connected to vertex 1 (1) and vertex 4 (1). Hence, 0 1 0 0 1.
Row 1: The second row (1) shows that vertex 1 is connected to vertex 0 (1), vertex 2 (1), vertex 3 (1), and vertex 4 (1). Hence, 1 0 1 1 1.
Row 2: The third row (2) shows that vertex 2 is connected to vertex 1 (1) and vertex 3 (1). Hence, 0 1 0 1 0.
Row 3: The fourth row (3) shows that vertex 3 is connected to vertex 1 (1), vertex 2 (1), and vertex 4 (1). Hence, 0 1 1 0 1.
Row 4: The fifth row (4) shows that vertex 4 is connected to vertex 0 (1), vertex 1 (1), and vertex 3 (1). Hence, 1 1 0 1 0.
*/